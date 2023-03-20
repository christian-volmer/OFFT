
//          Copyright Christian Volmer 2023.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include <random>
#include <iomanip>
#include <iostream>

#include "transform_test.h"

void RandomisedTest(size_t MaximumDepth, size_t MaximumElementCount, double MinimumTestTime)
{
	std::random_device rd;
	std::mt19937_64 gen(rd());

	std::cout << std::setw(16) << "IterationCount";
	std::cout << ", " << std::setw(16) << "TotalRuntime";
	std::cout << ", " << std::setw(16) << "FreqDomainError";
	std::cout << ", " << std::setw(16) << "RoundTripError";
	std::cout << ", "
			  << "Dimensions"
			  << "\n";

	do {

		using value_t = double;
		value_t const Pi = value_t(3.1415926535897932385);

		// Get a random depth.

		size_t depth = std::uniform_int_distribution<size_t>(1, MaximumDepth)(gen);
		depth = std::uniform_int_distribution<size_t>(1, depth)(gen); // called twice to give preference to smaller depths.

		std::vector<size_t> dimensions(depth);
		std::vector<ptrdiff_t> bins(depth);
		std::vector<value_t> phases(depth);

		// Compute random and reasonable dimensions for the transform.

		size_t elementCount = 0;

		do {

			size_t const maxDimension = std::min((size_t)std::pow(10 * MaximumElementCount, 1.0 / depth), MaximumElementCount);

			for (size_t &dimension : dimensions)
				dimension = size_t(std::ceil(std::exp(std::uniform_real_distribution<double>(0.0, std::log(maxDimension))(gen))));

			try {

				elementCount = offt::math::ListProduct(dimensions.data(), dimensions.size());
			} catch (...) {

				// 'ListProduct()' throws on arithmetic overflow, which means 'elementCount' will be too large.
				continue;
			}

		} while (elementCount > MaximumElementCount);

		// Random bin and phases
		for (size_t i = 0; i < depth; ++i) {

			bins[i] = std::uniform_int_distribution<size_t>(0, dimensions[i] - 1)(gen);
			phases[i] = std::uniform_real_distribution<value_t>(-Pi, Pi)(gen);
		}

		// Run the benchmark
		TransformTest<value_t> test(dimensions.data(), depth, bins.data(), phases.data());

		auto summary = test.Benchmark(MinimumTestTime);

		// Print the results
		std::cout << std::setw(16) << summary.IterationCount;
		std::cout << ", " << std::setw(16) << summary.TotalRuntime;
		std::cout << ", " << std::setw(16) << summary.FrequencyDomainError;
		std::cout << ", " << std::setw(16) << summary.RoundTripError;

		for (size_t dimension : dimensions)
			std::cout << ", " << dimension;
		std::cout << "\n";

	} while (true);
}
