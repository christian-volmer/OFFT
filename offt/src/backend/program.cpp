
//          Copyright Christian Volmer 2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include "program.h"
#include "module_manager.h"

namespace offt {
namespace backend {

using std::size_t;
using std::ptrdiff_t;

template class Program<float>;
template class Program<double>;

template<typename valueT>
class Program<valueT>::Impl {

public:

	size_t mLength;
	size_t mTempRequirement;

	using ItemListType = std::vector<std::unique_ptr<ModuleBase<valueT>>>;

	ItemListType mItems;

	static void RecursiveExecuteInPlaceOutOfOrderTime(valueT *pReal, valueT *pImag, ptrdiff_t stride, typename ItemListType::const_iterator const &item)
	{
		if ((*item)->mRemainingLength > 1) {

			for (size_t i = 0; i < (*item)->mLength; ++i)
				RecursiveExecuteInPlaceOutOfOrderTime(
					pReal + i * (*item)->mRemainingLength * stride,
					pImag + i * (*item)->mRemainingLength * stride,
					stride, std::next(item));
		}

		for (size_t i = 0; i < (*item)->mRemainingLength; ++i)
			(*item)->Compute(
				pReal + i * stride,
				pImag + i * stride,
				(*item)->mRemainingLength * stride, 0, i * (*item)->mTwiddleStep);
	}

	static void RecursiveExecuteInPlaceOutOfOrderFrequency(valueT *pReal, valueT *pImag, ptrdiff_t stride, typename ItemListType::const_iterator const &item, size_t twiddleStep)
	{
		size_t twiddleIncrement = (*item)->mRemainingLength * twiddleStep;

		for (size_t i = 0; i < (*item)->mRemainingLength; ++i)
			(*item)->Compute(
				pReal + i * stride,
				pImag + i * stride,
				(*item)->mRemainingLength * stride, i * twiddleStep, twiddleIncrement);

		if ((*item)->mRemainingLength > 1) {

			for (size_t i = 0; i < (*item)->mLength; ++i)
				RecursiveExecuteInPlaceOutOfOrderFrequency(
					pReal + i * (*item)->mRemainingLength * stride,
					pImag + i * (*item)->mRemainingLength * stride,
					stride, std::next(item), i * (*item)->mTwiddleStep);
		}
	}

	static void RecursiveExecuteOutOfPlaceInOrder(valueT *pDestReal, valueT *pDestImag, ptrdiff_t destStride, valueT const *pSrcReal, valueT const *pSrcImag, ptrdiff_t srcStride, typename ItemListType::const_iterator const &item)
	{
		if ((*item)->mRemainingLength > 1) {

			for (size_t i = 0; i < (*item)->mLength; ++i)
				RecursiveExecuteOutOfPlaceInOrder(
					pDestReal + i * (*item)->mRemainingLength * destStride,
					pDestImag + i * (*item)->mRemainingLength * destStride,
					destStride,
					pSrcReal + i * srcStride,
					pSrcImag + i * srcStride,
					(*item)->mLength * srcStride,
					std::next(item));
		}
		else {

			for (size_t i = 0; i < (*item)->mLength; ++i) {

				pDestReal[i * destStride] = pSrcReal[i * srcStride];
				pDestImag[i * destStride] = pSrcImag[i * srcStride];
			}
		}

		for (size_t i = 0; i < (*item)->mRemainingLength; ++i)
			(*item)->Compute(
				pDestReal + i * destStride,
				pDestImag + i * destStride,
				(*item)->mRemainingLength * destStride, 0, i * (*item)->mTwiddleStep);
	}
};


template<typename valueT>
Program<valueT>::Program() :
	mpImpl(new Impl())
{
}

template<typename valueT>
Program<valueT>::~Program()
{
}

template<typename valueT>
size_t Program<valueT>::GetLength() const
{
	return mpImpl->mLength;
}

template<typename valueT>
size_t Program<valueT>::GetTempRequirement() const
{
	return mpImpl->mTempRequirement;
}

template<typename valueT>
void Program<valueT>::SetTemp(valueT *pTemp)
{
	for (auto &item : mpImpl->mItems)
		item->SetTemp(pTemp);
}

template<typename valueT>
void Program<valueT>::Prepare(Storage<valueT> &storage, size_t length)
{
	static ModuleManager<valueT> moduleManager;

	SetTemp(nullptr);
	mpImpl->mItems.clear();

	mpImpl->mLength = length;

	if (length > 1) {

		auto factors = moduleManager.Factorise(length);
		size_t currentLength = length;

		Phasors<valueT> const &phasors = storage.GetPhasors(length);

		for (auto const &factor : factors) {

			size_t itemLength = factor;
			size_t remainingLength = currentLength / itemLength;
			size_t twiddleStep = phasors.GetLength() / currentLength;

			mpImpl->mItems.push_back(moduleManager.ConstructModule(phasors, itemLength, remainingLength, twiddleStep));

			currentLength = remainingLength;
		}

		for (auto &item : mpImpl->mItems) {

			size_t tempRequirement = item->Prepare(storage);

			if (tempRequirement > mpImpl->mTempRequirement)
				mpImpl->mTempRequirement = tempRequirement;
		}
	}
}

template<typename valueT>
void Program<valueT>::ExecuteInPlaceOutOfOrderTime(valueT *pReal, valueT *pImag, ptrdiff_t stride) const
{
	Impl::RecursiveExecuteInPlaceOutOfOrderTime(pReal, pImag, stride, mpImpl->mItems.begin());
}

template<typename valueT>
void Program<valueT>::ExecuteInPlaceOutOfOrderFrequency(valueT *pReal, valueT *pImag, ptrdiff_t stride) const
{
	Impl::RecursiveExecuteInPlaceOutOfOrderFrequency(pReal, pImag, stride, mpImpl->mItems.begin(), 0);
}

template<typename valueT>
void Program<valueT>::ExecuteOutOfPlaceInOrder(valueT *pDestReal, valueT *pDestImag, ptrdiff_t destStride, valueT const *pSrcReal, valueT const *pSrcImag, ptrdiff_t srcStride) const
{
	Impl::RecursiveExecuteOutOfPlaceInOrder(pDestReal, pDestImag, destStride, pSrcReal, pSrcImag, srcStride, mpImpl->mItems.begin());
}

}
}
