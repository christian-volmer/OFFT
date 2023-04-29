
//          Copyright Christian Volmer 2023.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <offt.h>
#include <offt/math.h>

#include <chrono>
#include <vector>

template<typename T>
class TransformTest {

private:

	using value_t = T;
	using cpx_t = std::complex<value_t>;

	offt::backend::FourierBase<value_t> mFourierBase;

	size_t mDepth;
	size_t mElementCount;

	std::vector<size_t> mDimensions;
	std::vector<ptrdiff_t> mStrides;
	std::vector<ptrdiff_t> mBins;
	std::vector<value_t> mPhases;

	std::vector<cpx_t> mData, mFreq, mData2;

	ptrdiff_t mTargetBin;
	cpx_t mTargetValue;

public:

	struct BenchmarkSummary {

		size_t IterationCount;
		double TotalRuntime;
		double FrequencyDomainError;
		double RoundTripError;
	};

	TransformTest(size_t const *pDimensions, size_t depth, ptrdiff_t const *pBins, value_t const *pPhases) :
		mFourierBase(pDimensions, depth, offt::FourierParameters::WolframLanguage),
		mDepth(depth),
		mElementCount(),
		mDimensions(pDimensions, pDimensions + depth),
		mStrides(depth),
		mBins(pBins, pBins + depth),
		mPhases(pPhases, pPhases + depth),
		mData(),
		mFreq(),
		mData2(),
		mTargetBin(),
		mTargetValue()
	{
		static value_t const Pi = value_t(3.1415926535897932385);

		// Compute the total element count and the strides of the
		// multidimensional array.

		mElementCount = 1;
		for (ptrdiff_t i = depth - 1; i >= 0; --i) {

			mStrides[i] = mElementCount;
			mElementCount *= mDimensions[i];
		}

		mData.resize(mElementCount, 1.0);
		mFreq.resize(mElementCount);
		mData2.resize(mElementCount);

		// Create the n-dimensional time-domain samples. This
		// consists of appropriately multiplied complex exponentials
		// so that the frequency-domain data has a non-zero component
		// only at the position specified by parameter 'pBins'.

		for (size_t level = 0; level < mDepth; ++level) {

			size_t dimension = mDimensions[level];
			ptrdiff_t stride = mStrides[level];
			ptrdiff_t subStride = mElementCount / stride / dimension;
			ptrdiff_t bin = mBins[level];
			value_t phase = mPhases[level];

			for (size_t i = 0; i < dimension; ++i) {

				cpx_t exp = std::exp(cpx_t(0, -2 * Pi * bin * i / dimension - phase));

				for (ptrdiff_t k = 0; k < subStride; ++k)
					for (ptrdiff_t j = 0; j < stride; ++j)
						mData[(i + k * dimension) * stride + j] *= exp;
			}
		}

		// Compute the offset of target bin in the flattened
		// array.

		mTargetBin = 0;
		for (size_t i = 0; i < mDepth; ++i)
			mTargetBin += offt::math::Mod(mBins[i], mDimensions[i]) * mStrides[i];

		// Compute the expected phase of the target bin.
		value_t totalPhase = mPhases[0];
		for (size_t i = 1; i < mDepth; ++i)
			totalPhase += mPhases[i];

		// Compute the expected value of the target bin. Note this depends on
		// the value of the parameter 'fourierParameters' passed to the
		// constructor of 'mFourierBase' in the initialiser list above.
		mTargetValue = std::sqrt(value_t(mElementCount)) * std::exp(cpx_t(0, -totalPhase));
	}

	BenchmarkSummary Benchmark(double testTime)
	{
		// Run a forward and an inverse transform in a loop for
		// at least the amount of time specified by 'testTime'.
		// Count the number of iterations.
		auto startTime = std::chrono::steady_clock::now();

		size_t iterationCount = 0;
		double duration;

		do {

			mFourierBase.Transform(mFreq.data(), mStrides.data(), mData.data(), mStrides.data());
			mFourierBase.InverseTransform(mData2.data(), mStrides.data(), mFreq.data(), mStrides.data());

			duration = std::chrono::duration<double>(std::chrono::steady_clock::now() - startTime).count();
			iterationCount += 2;

		} while (duration < testTime);

		// Ideally, the frequency domain data is expected to be zero except
		// for the position of the target bin, where it should have the
		// value 'mTargetValue'. Calculate the root-mean-square (rms) error
		// from the ideal solution.

		double frequencyTotalSquaredError = 0;
		for (size_t i = 0; i < mElementCount; ++i) {

			cpx_t error = i == (size_t)mTargetBin ? mFreq[i] - mTargetValue : mFreq[i];
			frequencyTotalSquaredError += std::pow(std::abs(error), 2);
		}

		double frequencyRmsError = std::sqrt(frequencyTotalSquaredError / mElementCount);

		// Ideally, the result of the inverse transform should be identical to
		// the original time-domain values. Calculate the root-mean-square (rms)
		// error from the ideal solution.

		double roundTripTotalSquaredError = 0;
		for (size_t i = 0; i < mElementCount; ++i)
			roundTripTotalSquaredError += std::pow(std::abs(mData2[i] - mData[i]), 2);

		double roundTripRmsError = std::sqrt(roundTripTotalSquaredError / mElementCount);

		return { iterationCount, duration, frequencyRmsError, roundTripRmsError };
	}
};
