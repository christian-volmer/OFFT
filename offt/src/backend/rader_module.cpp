
//          Copyright Christian Volmer 2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include "rader_module.h"
#include <offt/math/power_mod.h>
#include <offt/math/prime_q.h>
#include <offt/math/primitive_root.h>
#include <offt/math/times_plus_mod.h>

namespace offt {
namespace backend {

template class RaderModule<float>;
template class RaderModule<double>;

template<typename valueT>
RaderModule<valueT>::RaderModule(Phasors<valueT> const &phasors, size_t length, size_t remainingLength, size_t twiddleStep) :
	ModuleBase<valueT>(phasors, length, remainingLength, twiddleStep),
	mpTemp(),
	mConvolutionProgram(),
	mRaderData()
{
	if (length <= 2 || !math::PrimeQ(length))
		throw std::invalid_argument("RaderModule::ctor(): parameter 'length' must be a prime number greater than '2'.");
}

template<typename valueT>
size_t RaderModule<valueT>::Prepare(Storage<valueT> &storage)
{
	size_t phasorStep = mPhasors.GetLength() / mLength;

	size_t convolutionLength = mLength - 1;
	mConvolutionProgram.Prepare(storage, convolutionLength);
	size_t convolutionTempRequirement = mConvolutionProgram.GetTempRequirement();

	RaderData<valueT> *raderData = &storage.GetRaderData(mLength);

	if (raderData->mCoefficients.empty()) {

		// Primitive root and its inverse
		ptrdiff_t g = math::PrimitiveRoot(mLength);
		ptrdiff_t gi = math::PowerMod(g, -1, mLength);

		raderData->mCoefficients.resize(2 * convolutionLength, {});

		// Compute the kernel of the convolution used by the Rader method
		for (ptrdiff_t i = 0, ggi = 1; static_cast<size_t>(i) < mLength - 1; ++i) {

			mPhasors.Multiply(raderData->mCoefficients[2 * i + 0], raderData->mCoefficients[2 * i + 1], 1, 0, phasorStep * ggi);
			ggi = math::TimesPlusMod(ggi, gi, 0, mLength);
		}

		// Transform the kernel to frequency-domain, because this is what we need later in the Compute() method
		{
			std::vector<valueT> convolutionTemp(convolutionTempRequirement);
			mConvolutionProgram.SetTemp(convolutionTemp.data());

			mConvolutionProgram.ExecuteInPlaceOutOfOrderFrequency(&raderData->mCoefficients[0], &raderData->mCoefficients[1], 2);

			// The first coefficient has a simple value:
			raderData->mCoefficients[0] = -1;
			raderData->mCoefficients[1] = 0;

			// Adjust the scaling so we don't have to do it during the Compute() method
			for (size_t i = 0; i < raderData->mCoefficients.size(); ++i)
				raderData->mCoefficients[i] /= convolutionLength;

			mConvolutionProgram.SetTemp(nullptr);
		}

		// Precompute the permutation
		raderData->mPermutation.resize(mLength);
		for (ptrdiff_t i = 0, gg = 1; static_cast<size_t>(i) < mLength - 1; ++i) {

			raderData->mPermutation[gg] = i;
			gg = math::TimesPlusMod(gg, g, 0, mLength);
		}
	}

	mRaderData = raderData;

	return 2 * mLength + convolutionTempRequirement;
}

template<typename valueT>
void RaderModule<valueT>::SetTemp(valueT *pTemp)
{
	mpTemp = pTemp;

	if (pTemp != nullptr)
		mConvolutionProgram.SetTemp(pTemp + 2 * mLength);
	else
		mConvolutionProgram.SetTemp(nullptr);
}

template<typename valueT>
void RaderModule<valueT>::Compute(valueT *pReal, valueT *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	valueT twiddledReal0, twiddledImag0;

	// The first time-domain sample is processed separately.
	mPhasors.Multiply(twiddledReal0, twiddledImag0, pReal[0], pImag[0], twiddleStart);

	// The Rader permutation is applied to all but the first time-domain
	// samples -- along with the twiddling.
	for (size_t i = 1; i < mLength; ++i) {

		mPhasors.Multiply(
			mpTemp[2 * mRaderData->mPermutation[i] + 0], mpTemp[2 * mRaderData->mPermutation[i] + 1],
			pReal[i * stride], pImag[i * stride], twiddleStart + i * twiddleIncrement);
	}

	// Transform to frequency-domain
	mConvolutionProgram.ExecuteInPlaceOutOfOrderFrequency(&mpTemp[0], &mpTemp[1], 2);

	// mpTemp[0, 1] now contains the sum of all but the first time-domain samples.
	// We complete the sum by adding the first time-domain sample and store this
	// away as the 0-th frequency-domain result (the "DC-bin").
	pReal[0 * stride] = twiddledReal0 + mpTemp[0];
	pImag[0 * stride] = twiddledImag0 + mpTemp[1];

	// Do the Rader convolution in frequency-domain by multiplying with the
	// coefficients we precomputed earlier.
	for (size_t i = 0; i < mConvolutionProgram.GetLength(); ++i) {

		valueT coeffReal = mRaderData->mCoefficients[2 * i + 0];
		valueT coeffImag = mRaderData->mCoefficients[2 * i + 1];

		valueT temp = mpTemp[2 * i + 0] * coeffImag + mpTemp[2 * i + 1] * coeffReal;
		mpTemp[2 * i + 0] = mpTemp[2 * i + 0] * coeffReal - mpTemp[2 * i + 1] * coeffImag;
		mpTemp[2 * i + 1] = temp;
	}

	// Rader's algorithm involves adding the first time-domain sample to
	// the result of the convolution. This is accomplished here by adding
	// the first time-domain sample to the DC-bin of the frequency-domain
	// convolution result.
	mpTemp[0] += twiddledReal0;
	mpTemp[1] += twiddledImag0;

	// Transform back to time-domain
	mConvolutionProgram.ExecuteInPlaceOutOfOrderTime(&mpTemp[0], &mpTemp[1], 2);

	// Incidentally, the way we transformed to and from the frequency-domain
	// leaves the result of the convolution in reversed order. This allows us
	// to use the precomputed permutation during both the input and the output
	// permutation stage of Rader's algorithm.
	for (size_t i = 1; i < mLength; ++i) {

		pReal[i * stride] = mpTemp[2 * mRaderData->mPermutation[i] + 0];
		pImag[i * stride] = mpTemp[2 * mRaderData->mPermutation[i] + 1];
	}
}

}
}
