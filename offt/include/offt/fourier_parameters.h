
//          Copyright Christian Volmer 2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#pragma once

namespace offt {

// 'FourierParameters' defines the scaling and the sign of the imaginary 
// part used in the computation of the Fast Fourier Transform.
struct FourierParameters {

	int a, b;

	// Default values used in this implementation: { 1, 1 }
	static const FourierParameters Default;

	// Default values used in the Wolfram Language: { 0, 1 }
	static const FourierParameters WolframLanguage;

	// Default values used in Mathematica: { 0, 1 }
	static const FourierParameters Mathematica;

	// Default values used by the FFTW library: { 1, -1 }
	static const FourierParameters FFTW;

	FourierParameters(int a, int b) :
		a(a),
		b(b)
	{
	}
};

}
