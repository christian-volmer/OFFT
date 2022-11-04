
//          Copyright Christian Volmer 2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include "miller_rabin_probable_prime_q.h"
#include "even_q.h"
#include "odd_q.h"
#include "power_mod.h"

#include <stdexcept>

namespace offt {
namespace math {

using std::ptrdiff_t;

bool MillerRabinProbablePrimeQ(ptrdiff_t base, ptrdiff_t n)
{
	// The following is an implementation of the Miller-Rabin test for given 'base' accurding to
	// https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test#Miller%E2%80%93Rabin_test

	if (n < 3 || !OddQ(n))
		throw std::invalid_argument("MillerRabinProbablePrimeQ(): 'n' must be an odd integer greater than 2.");

	if (base <= 0 || base >= n)
		throw std::invalid_argument("MillerRabinProbablePrimeQ(): 'base' must be a positive integer less than 'n'.");

	ptrdiff_t r = 0;
	ptrdiff_t d = n - 1;

	while (EvenQ(d)) {

		d /= 2;
		++r;
	}

	ptrdiff_t x = PowerMod(base, d, n);

	if (x == 1 || x == n - 1)
		return true;

	for (ptrdiff_t i = 0; i < r - 1; ++i) {

		x = PowerMod(x, 2, n);
		if (x == n - 1)
			return true;
	}

	return false;
}

}
}
