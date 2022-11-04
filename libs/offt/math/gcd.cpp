
//          Copyright Christian Volmer 2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include "gcd.h"

#include <limits>
#include <stdexcept>

namespace offt {
namespace math {

using std::ptrdiff_t;

ptrdiff_t GCD(ptrdiff_t a, ptrdiff_t b)
{
	// This is the implementation of Euclid's algorithm.

	if (a < -std::numeric_limits<ptrdiff_t>::max())
		throw std::invalid_argument("GCD(): parameter 'a' is out of range.");

	if (b < -std::numeric_limits<ptrdiff_t>::max())
		throw std::invalid_argument("GCD(): parameter 'b' is out of range.");

	if (a < 0) a = -a;
	if (b < 0) b = -b;

	while (b != 0) {

		ptrdiff_t mod = a % b;
		a = b;
		b = mod;
	}

	return a;
}

}
}
