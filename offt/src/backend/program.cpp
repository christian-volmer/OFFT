
//          Copyright Christian Volmer 2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include "program.h"
#include "module_manager.h"

namespace offt {
namespace backend {

using std::ptrdiff_t;
using std::size_t;

template class Program<float>;
template class Program<double>;

template<typename valueT>
class Program<valueT>::Impl {

public:

	using ItemListType = std::vector<std::unique_ptr<ModuleBase<valueT>>>;

	size_t mLength;
	size_t mTempRequirement;

	ItemListType mItems;

	Impl() :
		mLength(0),
		mTempRequirement(0),
		mItems()
	{
	}

	static void RecursiveExecuteInPlaceOutOfOrderTime(valueT *pReal, valueT *pImag, ptrdiff_t const stride, typename ItemListType::const_iterator const &item)
	{
		if ((*item)->mRemainingLength > 1) {

			for (size_t i = 0; i < (*item)->mLength; ++i)
				RecursiveExecuteInPlaceOutOfOrderTime(
					pReal + i * (*item)->mRemainingLength * stride,
					pImag + i * (*item)->mRemainingLength * stride,
					stride, std::next(item));
		}

		(*item)->ComputeLoop(
			pReal, pImag, stride,
			0, 0, (*item)->mTwiddleStep);
	}

	static void RecursiveExecuteInPlaceOutOfOrderFrequency(valueT *pReal, valueT *pImag, ptrdiff_t const stride, typename ItemListType::const_iterator const &item, size_t const twiddleStep)
	{
		size_t const twiddleIncrement = (*item)->mRemainingLength * twiddleStep;

		(*item)->ComputeLoop(
			pReal, pImag, stride,
			twiddleStep, twiddleIncrement, 0);

		if ((*item)->mRemainingLength > 1) {

			for (size_t i = 0; i < (*item)->mLength; ++i)
				RecursiveExecuteInPlaceOutOfOrderFrequency(
					pReal + i * (*item)->mRemainingLength * stride,
					pImag + i * (*item)->mRemainingLength * stride,
					stride, std::next(item), i * (*item)->mTwiddleStep);
		}
	}

	static void RecursiveExecuteOutOfPlaceInOrder(valueT *pDestReal, valueT *pDestImag, ptrdiff_t const destStride, valueT const *pSrcReal, valueT const *pSrcImag, ptrdiff_t const srcStride, typename ItemListType::const_iterator const &item)
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

		(*item)->ComputeLoop(
			pDestReal, pDestImag, destStride,
			0, 0, (*item)->mTwiddleStep);
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
