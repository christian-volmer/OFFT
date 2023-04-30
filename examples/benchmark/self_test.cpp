
//          Copyright Christian Volmer 2023.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include "self_test.h"
#include "transform_test.h"

#include <algorithm>
#include <iostream>

template<typename value_t>
bool TestLength(size_t length)
{
	double const MAX_ERROR = 1.0;

	ptrdiff_t targetBin = std::min(length / 3 + 1, length - 1);

	value_t zeroPhase = 0;
	TransformTest<value_t> test(&length, 1, &targetBin, &zeroPhase);

	double error = test.Benchmark(0.0).FrequencyDomainError;

	double epsilon = std::numeric_limits<value_t>::epsilon();
	double ratio = error / epsilon / (double)length;

	if (ratio > MAX_ERROR) {

		std::cout << "    Length " << length << " FAILED test. (normalised error = " << ratio << ")\n";
		return true;
	}

	return false;
}

template<typename T>
bool SelfTestForType()
{
	bool failure = false;

	std::cout << "  All lengths up to 1000...\n";
    for (int length = 1; length < 1000; ++length)
		failure = TestLength<T>(length) || failure;

	std::cout << "  Some prime lengths...\n";
    for (int length = 10001; length < 10500; length += 2) {

		if (offt::math::PrimeQ(length))
			failure = TestLength<T>(length) || failure;
	}

	std::cout << "  Powers of 2...\n";
    for (int length = 128; length <= 1024*1024; length *= 2)
		failure = TestLength<T>(length) || failure;

	std::cout << "  Powers of 10...\n";
    for (int length = 100; length <= 1000000; length *= 10)
		failure = TestLength<T>(length) || failure;

	return failure;
}

int SelfTest()
{
	bool failure = false;

	std::cout << "--- Testing type float ---\n";
    failure = SelfTestForType<float>() || failure;

	std::cout << "--- Testing type double ---\n";
	failure = SelfTestForType<double>() || failure;

	return failure;
}