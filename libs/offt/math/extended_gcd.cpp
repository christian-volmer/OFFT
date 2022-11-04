
//          Copyright Christian Volmer 2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include "extended_gcd.h"

#include <limits>
#include <stdexcept>

namespace offt {
namespace math {

using std::size_t;
using std::ptrdiff_t;

ptrdiff_t ExtendedGCD(ptrdiff_t a, ptrdiff_t b, ptrdiff_t *x, ptrdiff_t *y)
{
	// Computes ax + by = GCD(a, b) using the extended Euclidean algorithm.
	// See https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Pseudocode

	if (a < -std::numeric_limits<ptrdiff_t>::max())
		throw std::invalid_argument("ExtendedGCD(): parameter 'a' is out of range.");

	if (b < -std::numeric_limits<ptrdiff_t>::max())
		throw std::invalid_argument("ExtendedGCD(): parameter 'b' is out of range.");

	ptrdiff_t r0 = a, r1 = b;
	ptrdiff_t s0 = 1, s1 = 0;
	ptrdiff_t t0 = 0, t1 = 1;

	if (r0 < 0)
		r0 = -r0;

	if (r1 < 0)
		r1 = -r1;

	while (r1 != 0) {

		ptrdiff_t quotient = r0 / r1;

		ptrdiff_t temp;

		temp = r0; 
		r0 = r1; 
		r1 = temp - quotient * r1;

		if (x != nullptr) { 
			
			temp = s0; 
			s0 = s1; 
			s1 = temp - quotient * s1; 
		}

		if (y != nullptr) {

			temp = t0;
			t0 = t1;
			t1 = temp - quotient * t1;
		}
	}

	if (x != nullptr)
		*x = a >= 0 ? s0 : -s0;

	if (y != nullptr)
		*y = b >= 0 ? t0 : -t0;

	return r0;
}

}
}
