
//          Copyright Christian Volmer 2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include <offt/compat.h>
#include <offt/backend/fourier_base.h>
#include <offt/math/list_product.h>
#include "program.h"

#include <cassert>
#include <algorithm>

namespace offt {
namespace backend {

using std::size_t;
using std::ptrdiff_t;

template class FourierBase<float>;
template class FourierBase<double>;

template<typename valueT>
class FourierBase<valueT>::Impl {

private:

	using realT = valueT;
	using complexT = std::complex<valueT>;

	// The depth, i.e., the number of dimenions of this transform.
	size_t const mDepth;

	// Number of dimensions that are greater than 1.
	size_t mNonTrivialDepth;

	// The dimensions, i.e., the lengths of the one-dimensional transforms at each 
	// level of a multi-dimensional transform
	std::unique_ptr<size_t[]> mDimensions;

	// FourierParameters used for this transform
	FourierParameters const mFourierParameters;

	// Common storage for the elements of 'mPrograms'.
	std::shared_ptr<backend::Storage<valueT>> mStorage;

	// List of FFT programs, one for each dimension.
	std::unique_ptr<backend::Program<valueT>[]> const mPrograms;

	// Index of the largest element of 'mDimensions'. Used to optimise the storage requirements
	// of multi-dimensional transforms.
	size_t mLargestDimensionLevel;

	// Total amount of temporary storage required by the elements of 'mPrograms', plus storage
	// required for multi-dimensional transforms.
	size_t mTempRequirement;

	// Pointer to the temporary storage
	mutable std::unique_ptr<realT[]> mTemp;

	size_t mElementCount;
	realT mForwardScale, mInverseScale;
	bool mConjugate;

	size_t AdditionalTempRequirementForLevel(size_t dimensionIndex) const
	{
		if (dimensionIndex == mLargestDimensionLevel)
			return 0;

		return 2 * mPrograms[dimensionIndex].GetLength();
	}

	void ComputeTempRequirement()
	{
		if (mElementCount <= 1) {

			mTempRequirement = 0;
			return;
		}

		// First, we need to know the index of the largest dimension 
		// of a multi-dimensional transform. This is required by the
		// later call to 'AdditionalTempRequirementForLevel()'.
		size_t largestDimension = 0;
		for (size_t i = 0; i < mDepth; ++i) {

			if (mDimensions[i] > largestDimension) {

				largestDimension = mDimensions[i];
				mLargestDimensionLevel = i;
			}
		}

		// Each level may require temporary working memory for the
		// FFT program execution. More memory may be required for 
		// multi-dimensional transforms.
		for (size_t level = 0; level < mDepth; ++level) {

			size_t programTempRequirement = mPrograms[level].GetTempRequirement();
			size_t dimensionTempRequirement = programTempRequirement + AdditionalTempRequirementForLevel(level);

			if (dimensionTempRequirement > mTempRequirement)
				mTempRequirement = dimensionTempRequirement;
		}
	}

	void RecursiveApplyTransform(
		realT *pDestReal, realT *pDestImag, ptrdiff_t const *pDestStrides,
		realT const *pSrcReal, realT const *pSrcImag, ptrdiff_t const *pSrcStrides,
		size_t currentLevel, size_t applyLevel, realT scale, int strideMultiplier) const
	{
		if (currentLevel == applyLevel) {

			RecursiveApplyTransform(
				pDestReal, pDestImag, pDestStrides,
				pSrcReal, pSrcImag, pSrcStrides,
				currentLevel + 1, applyLevel, scale, strideMultiplier);
		}
		else if (currentLevel < mDepth) {

			ptrdiff_t destStride = pDestStrides[currentLevel] * strideMultiplier;
			ptrdiff_t srcStride = pSrcStrides[currentLevel] * strideMultiplier;

			for (size_t i = 0; i < mDimensions[currentLevel]; ++i) {

				RecursiveApplyTransform(
					pDestReal + i * destStride, pDestImag + i * destStride, pDestStrides,
					pSrcReal + i * srcStride, pSrcImag + i * srcStride, pSrcStrides,
					currentLevel + 1, applyLevel, scale, strideMultiplier);
			}
		}
		else {

			ptrdiff_t destStride = pDestStrides[applyLevel] * strideMultiplier;
			size_t length = mPrograms[applyLevel].GetLength();
			assert(length > 1);

			if (pSrcReal == pDestReal) {

				mPrograms[applyLevel].ExecuteOutOfPlaceInOrder(&mTemp[0], &mTemp[1], 2,
					pDestReal, pDestImag, destStride);


				if (scale != 1) {

					for (size_t i = 0; i < length; ++i) {

						pDestReal[destStride * i] = scale * mTemp[2 * i + 0];
						pDestImag[destStride * i] = scale * mTemp[2 * i + 1];
					}
				}
				else {

					for (size_t i = 0; i < length; ++i) {

						pDestReal[destStride * i] = mTemp[2 * i + 0];
						pDestImag[destStride * i] = mTemp[2 * i + 1];
					}
				}
			}
			else {

				mPrograms[applyLevel].ExecuteOutOfPlaceInOrder(pDestReal, pDestImag, destStride,
					pSrcReal, pSrcImag, pSrcStrides[applyLevel] * strideMultiplier);

				if (scale != 1) {

					for (size_t i = 0; i < length; ++i) {

						pDestReal[destStride * i] *= scale;
						pDestImag[destStride * i] *= scale;
					}
				}
			}
		}
	}

	void ExecuteTransform(realT *pDestReal, realT *pDestImag, ptrdiff_t const *destinationStrides,
		realT const *pSrcReal, realT const *pSrcImag, ptrdiff_t const *sourceStrides, int strideMultiplier, bool conjugate, realT scale) const
	{
		if (mElementCount == 0)
			return;
		else if (mElementCount == 1) {

			*pDestReal = *pSrcReal;
			*pDestImag = *pSrcImag;
		}
		else {

			EnsureTemp();

			if (conjugate) {

				std::swap(pDestReal, pDestImag);
				std::swap(pSrcReal, pSrcImag);
			}

			RecursiveApplyTransform(
				pDestReal, pDestImag, destinationStrides,
				pSrcReal, pSrcImag, sourceStrides,
				0, mLargestDimensionLevel, mNonTrivialDepth == 1 ? scale : 1, strideMultiplier);

			for (size_t level = 0; level < mDepth; ++level) {

				if (level == mLargestDimensionLevel || mDimensions[level] == 1)
					continue;

				RecursiveApplyTransform(
					pDestReal, pDestImag, destinationStrides,
					pDestReal, pDestImag, destinationStrides,
					0, level, scale, strideMultiplier);

				scale = 1;
			}
		}
	}

public:

	Impl(size_t const *dimensions, size_t depth, FourierParameters const &fourierParameters) :
		mDepth(depth),
		mNonTrivialDepth(0),
		mDimensions(new size_t[depth]),
		mFourierParameters(fourierParameters),
		mStorage(new backend::Storage<valueT>()),
		mPrograms(new backend::Program<valueT>[depth]),
		mLargestDimensionLevel(0),
		mTempRequirement(0),
		mTemp(nullptr),
		mElementCount(0),
		mForwardScale(0),
		mInverseScale(0),
		mConjugate(false)
	{
		if (fourierParameters.b != 1 && fourierParameters.b != -1)
			throw std::invalid_argument("FourierBase::ctor(): field 'b' of parameter 'fourierParameters' must be either '+1' or '-1'.");

		std::copy(dimensions, dimensions + depth, mDimensions.get());

		// Count the total number of elements (throws on overflow)
		mElementCount = math::ListProduct(dimensions, depth);

		if (mElementCount > 1) {

			// Count the number of non-trivial dimensions in the array.
			mNonTrivialDepth = 0;
			for (size_t i = 0; i < depth; ++i)
				if (dimensions[i] > 1)
					++mNonTrivialDepth;

			// Prepare the programs for each dimension
			for (size_t i = 0; i < depth; ++i)
				mPrograms[i].Prepare(*mStorage, dimensions[i]);

			// Compute temp requirements
			ComputeTempRequirement();

			// Interpret 'fourierParameters'
			mForwardScale = std::pow(realT(mElementCount), realT(-0.5) * (1 - mFourierParameters.a));
			mInverseScale = 1 / (mElementCount * mForwardScale);

			mConjugate = fourierParameters.b != 1;
		}
	}

	size_t GetDepth() const
	{
		return mDepth;
	}

	size_t const *GetDimensions() const
	{
		return mDimensions.get();
	}

	void EnsureTemp() const
	{
		if (!mTemp) {

			mTemp.reset(new realT[mTempRequirement]);

			for (size_t level = 0; level < mDepth; ++level)
				mPrograms[level].SetTemp(mTemp.get() + AdditionalTempRequirementForLevel(level));
		}
	}

	void ReleaseTemp() const
	{
		mTemp.reset(nullptr);
		for (size_t i = 0; i < mDepth; ++i)
			mPrograms[i].SetTemp(nullptr);
	}

	void ComplexTransform(complexT *destination, ptrdiff_t const *destinationStrides,
		complexT const *source, ptrdiff_t const *sourceStrides, bool inverse) const
	{
		ExecuteTransform(
			reinterpret_cast<realT *>(destination) + 0,
			reinterpret_cast<realT *>(destination) + 1,
			destinationStrides,
			reinterpret_cast<realT const *>(source) + 0,
			reinterpret_cast<realT const *>(source) + 1,
			sourceStrides, 2, mConjugate != inverse, inverse ? mInverseScale : mForwardScale
		);
	}
};

template<typename valueT>
FourierBase<valueT>::FourierBase(size_t const *dimensions, size_t depth, FourierParameters const &fourierParameters /* = FourierParameters::Default */) :
	mpImpl(new Impl(dimensions, depth, fourierParameters))
{
}


template<typename valueT>
FourierBase<valueT>::~FourierBase()
{
}

template<typename valueT>
size_t const *FourierBase<valueT>::GetDimensions() const
{
	return mpImpl->GetDimensions();
}

template<typename valueT>
size_t FourierBase<valueT>::GetDepth() const
{
	return mpImpl->GetDepth();
}

template<typename valueT>
void FourierBase<valueT>::EnsureTemp() const
{
	mpImpl->EnsureTemp();
}

template<typename valueT>
void FourierBase<valueT>::ReleaseTemp() const
{
	mpImpl->ReleaseTemp();
}

template<typename valueT>
void FourierBase<valueT>::Transform(complexT *destination, ptrdiff_t const *destinationStrides,
	complexT const *source, ptrdiff_t const *sourceStrides) const
{
	mpImpl->ComplexTransform(destination, destinationStrides, source, sourceStrides, false);
}

template<typename valueT>
void FourierBase<valueT>::InverseTransform(complexT *destination, ptrdiff_t const *destinationStrides,
	complexT const *source, ptrdiff_t const *sourceStrides) const
{
	mpImpl->ComplexTransform(destination, destinationStrides, source, sourceStrides, true);
}

}
}

