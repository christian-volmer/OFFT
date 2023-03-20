
//          Copyright Christian Volmer 2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include <vector>
#include <complex>
#include <iomanip>

#include <offt.h>

int main()
{
	// The mathematical constant Pi.
	double const Pi = 3.1415926535897932385;

	// A shorthand name for std::complex<double>
	using cpx_t = std::complex<double>;

	// The length of the transform we want to compute.
	// The length is the number of complex-valued elements in our data.
	std::size_t length = 10;

	// The std::vector of our time-domain samples.
	std::vector<cpx_t> samples(length);

	// Compute the sample values.
	for (std::size_t i = 0; i < length; ++i)
		samples[i] = std::exp(cpx_t(0.0, -2*Pi * i * 3 / length));

	std::cout << std::setprecision(4);

	std::cout << "Time-domain samples\n";
	std::cout << "-------------------\n";

	for (auto const &sample : samples)
		std::cout << sample << "\n";

	// We create an instance of the offt::Fourier template class.
	// The length of our transform must be specified during construction.
	// In order to be able to perform the FFT fast, the constructor
	// does some precomputations that depend on the length.
	offt::Fourier<> fourier(length);

	// Because the transformation cannot be done in-place, we have
	// to reserve an extra array for the frequency-domain result.
	std::vector<cpx_t> frequency(length);

	// Do the transform. Because the data is stored sequencially
	// in vectors 'samples' and 'frequency', we specify the number
	// '1' as the source and destination strides.
	fourier.Transform(frequency.data(), 1, samples.data(), 1);

	std::cout << "\n\n";
	std::cout << "Frequency-domain samples\n";
	std::cout << "------------------------\n";

	for (auto const &f: frequency)
		std::cout << f << "\n";
}
