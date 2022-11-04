
//          Copyright Christian Volmer 2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include <vector>
#include <complex>
#include <iomanip>
#include <memory>
#include <utility>
#include <chrono>
#include <random>

#include <offt/fourier.h>
#include <offt/math/mod.h>
#include <offt/math/list_product.h>

using std::size_t;
using std::ptrdiff_t;
using value_t = double;
using cpx_t = std::complex<value_t>;

static value_t constexpr Pi = value_t(3.1415926535897932385);

class MultidimensionalTransformTest {

private:


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

	MultidimensionalTransformTest(size_t const *pDimensions, size_t depth, ptrdiff_t const *pBins, value_t const *pPhases) :
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
		mElementCount = 1;
		for (ptrdiff_t i = depth - 1; i >= 0; --i) {

			mStrides[i] = mElementCount;
			mElementCount *= mDimensions[i];
		}

		mData.resize(mElementCount, 1.0);
		mFreq.resize(mElementCount);
		mData2.resize(mElementCount);

		for (size_t level = 0; level < mDepth; ++level) {

			size_t dimension = mDimensions[level];
			ptrdiff_t stride = mStrides[level];
			ptrdiff_t subStride = mElementCount / stride / dimension;
			ptrdiff_t bin = mBins[level];
			value_t phase = mPhases[level];

			for (size_t i = 0; i < dimension; ++i) {

				cpx_t exp = std::exp(cpx_t(0, -2 * Pi * bin * i / dimension) - phase);

				for (ptrdiff_t k = 0; k < subStride; ++k)
					for (ptrdiff_t j = 0; j < stride; ++j)
						mData[(i + k * dimension) * stride + j] *= exp;
			}
		}

		mTargetBin = 0;
		for (size_t i = 0; i < mDepth; ++i)
			mTargetBin += offt::math::Mod(mBins[i], mDimensions[i]) * mStrides[i];

		value_t totalPhase = mPhases[0];
		for (size_t i = 1; i < mDepth; ++i)
			totalPhase += mPhases[i];

		mTargetValue = std::sqrt(value_t(mElementCount)) * std::exp(-totalPhase);
	}

	BenchmarkSummary Benchmark(double testTime)
	{
		auto startTime = std::chrono::steady_clock::now();

		size_t iterationCount = 0;
		double duration;

		do {

			mFourierBase.Transform(mFreq.data(), mStrides.data(), mData.data(), mStrides.data());
			mFourierBase.InverseTransform(mData2.data(), mStrides.data(), mFreq.data(), mStrides.data());

			duration = std::chrono::duration<double>(std::chrono::steady_clock::now() - startTime).count();
			iterationCount += 2;

		} while (duration < testTime);

		double frequencyMse2 = 0;
		for (size_t i = 0; i < mElementCount; ++i) {

			cpx_t error = i == (size_t)mTargetBin ? mFreq[i] - mTargetValue : mFreq[i];
			frequencyMse2 += std::pow(std::abs(error), 2);
		}

		frequencyMse2 = std::sqrt(frequencyMse2 / mElementCount);

		double roundTripMse2 = 0;
		for (size_t i = 0; i < mElementCount; ++i)
			roundTripMse2 += std::pow(std::abs(mData2[i] - mData[i]), 2);

		roundTripMse2 = std::sqrt(roundTripMse2 / mElementCount);

		return { iterationCount, duration, frequencyMse2, roundTripMse2 };
	}
};


int main()
{
	size_t constexpr MaximumDepth = 1;
	size_t constexpr MaximumElementCount = 10000000;

	std::random_device rd;
	std::mt19937_64 gen(rd());

	do {

		size_t depth = std::uniform_int_distribution<size_t>(1, MaximumDepth)(gen);
		depth = std::uniform_int_distribution<size_t>(1, depth)(gen);

		std::vector<size_t> dimensions(depth);
		std::vector<ptrdiff_t> bins(depth);
		std::vector<value_t> phases(depth);

		size_t elementCount = 0;

		do {

			size_t const maxDimension = std::min((size_t)std::pow(10 * MaximumElementCount, 1.0 / depth), MaximumElementCount);

			for (size_t &dimension : dimensions)
				dimension = size_t(std::ceil(std::exp(std::uniform_real_distribution<double>(0.0, std::log(maxDimension))(gen))));

			try {

				elementCount = offt::math::ListProduct(dimensions.data(), dimensions.size());
			}
			catch (...) {

				// 'ListProduct()' throws on arithmetic overflow, which means 'elementCount' will be too large.
				continue;
			}

		} while (elementCount > MaximumElementCount);

		for (size_t i = 0; i < depth; ++i) {

			bins[i] = std::uniform_int_distribution<size_t>(0, dimensions[i] - 1)(gen);
			phases[i] = std::uniform_real_distribution<value_t>(-Pi, Pi)(gen);
		}


		MultidimensionalTransformTest test(dimensions.data(), depth, bins.data(), phases.data());

		auto summary = test.Benchmark(1.0);

		std::cout << summary.IterationCount;
		std::cout << ", " << summary.TotalRuntime;
		std::cout << ", " << summary.FrequencyDomainError;
		std::cout << ", " << summary.RoundTripError;

		for (size_t dimension : dimensions)
			std::cout << ", " << dimension;
		std::cout << "\n";

	} while (true);
}
