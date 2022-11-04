
//          Copyright Christian Volmer 2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include "factor_integer.h"
#include "times_plus_mod.h"
#include "prime_q.h"
#include "gcd.h"

#include <cmath>

namespace offt {
namespace math {

using std::ptrdiff_t;

static ptrdiff_t PollardRhoFactorize(ptrdiff_t n, ptrdiff_t c)
{
	// Implementation of Brent's variant of Pollard's Rho factorisation algorithm
	// as described in: Brent80 - An Improved Monte Carlo Factorization Algorithm

	// Starting value (y = 1 seems to cause endless loop sometimes. Is y = 2 safe?)
	ptrdiff_t y = 2;

	// TODO: explain the variables

	ptrdiff_t r = 1;
	ptrdiff_t q = 1;

	// How many steps to move forward before doing the GCD
	ptrdiff_t m = 1 + (ptrdiff_t)std::floor(0.5 * std::pow(n, 0.25)); // TODO: call dedicated IntegerSurd function

	ptrdiff_t g, ys, k, x;

	do {

		x = y;

		for (ptrdiff_t i = 0; i < r; ++i)
			y = TimesPlusMod(y, y, c, n);

		k = 0;

		do {

			ys = y;

			for (ptrdiff_t i = 0; i < m && i < r - k; ++i) {

				y = TimesPlusMod(y, y, c, n);
				if (x > y)
					q = TimesPlusMod(q, x - y, 0, n);
				else
					q = TimesPlusMod(q, y - x, 0, n);
			}

			g = GCD(q, n);
			k = k + m;

		} while (k < r && g <= 1);

		r = 2 * r;

	} while (g <= 1);

	if (g == n) {

		// We were not able to extract a non-trivial factor. Sometimes the reason
		// is that we were taking too many steps at a time before doing the GCD. 
		// Go back to the last time when g was 1 and go one step at a time.
		do {

			ys = TimesPlusMod(ys, ys, c, n);
			g = GCD(x - ys, n);

		} while (g <= 1);
	}

	if (g == n)
		return 0; // The function was not able to extract a (non-trivial) factor.
	else
		return g;
}

static void RecursivePollardRhoFactorize(ptrdiff_t n, std::function<void(ptrdiff_t)> factorCallback)
{
	// 'rest' is what remains to be factored
	ptrdiff_t rest = n;

	while (!PrimeQ(rest)) {

		ptrdiff_t c = 1;
		ptrdiff_t factor = PollardRhoFactorize(rest, c);

		while (factor == 0) {

			// PollardRhoFactorize() was not able to factorise the number.
			// Try again with a different value for 'c'.
			++c;
			factor = PollardRhoFactorize(rest, c);
		}

		// If 'factor' is not prime, we need to call PollardRho again 
		// for further factorisation.
		if (PrimeQ(factor))
			factorCallback(factor);
		else
			RecursivePollardRhoFactorize(factor, factorCallback);

		rest /= factor;
	}

	factorCallback(rest);
}

static ptrdiff_t TrialFactorize(ptrdiff_t n, std::function<void(ptrdiff_t)> factorCallback)
{
	// Try factors up to 61 using modulo-6 wheel factorisation.

	while (n % 2 == 0) { factorCallback(2); n /= 2; }
	while (n % 3 == 0) { factorCallback(3); n /= 3; }

	for (ptrdiff_t k = 5; k <= 59 && k*k <= n; k += 6) {
		while (n % k == 0) { factorCallback(k); n /= k; }
		while (n % (k + 2) == 0) { factorCallback(k + 2); n /= (k + 2); }
	}

	return n;
}

void FactorInteger(ptrdiff_t n, std::function<void(ptrdiff_t)> factorCallback)
{
	if (n >= -1 && n <= 1) {

		factorCallback(n);
		return;
	}
	else if (n < 0) {

		factorCallback(-1);
		n = -n;
	}

	// Remove small factors...
	n = TrialFactorize(n, factorCallback);

	// ... before using more elaborate techniques.
	if (n > 1)
		RecursivePollardRhoFactorize(n, factorCallback);
}

}
}
