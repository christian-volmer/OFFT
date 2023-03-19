
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
#include <limits>

#include <offt.h>

template <typename value_t>
bool TestLength(int length)
{
	double const MAX_ERROR = 1.5;

	using cpx_t = std::complex<value_t>;
	value_t const Pi = value_t(3.1415926535897932385);
	offt::Fourier<value_t> fourier(length);

	std::vector<cpx_t> samples(length);

	int targetBin = std::min(length / 3 + 1, length - 1);

	for (int i = 0; i < length; ++i)
		samples[i] = std::exp(cpx_t(0, -targetBin * 2 * Pi * i / length));

	std::vector<cpx_t> fft(length);
	fourier.Transform(fft.data(), 1, samples.data(), 1);

	double epsilon = std::numeric_limits<value_t>::epsilon();
	double error = 0;

	for (int i = 0; i < length; ++i)
		if (i != targetBin)
			error += std::abs(fft[i]);

	error += std::abs(fft[targetBin] - cpx_t(length, 0));

	double ratio = std::sqrt(error / epsilon) / length / std::log((double)length);

	if (ratio > MAX_ERROR) {

		std::cout << "Length " << length << " FAILED test.\n";
		return true;
	}

	return false;
}

int main()
{
	bool failure = false;

	for (int length = 1; length <= 1024; ++length)
		failure = TestLength<float>(length) || failure;

	for (int length = 1; length <= 1024; ++length)
		failure = TestLength<double>(length) || failure;

	return failure;
}
