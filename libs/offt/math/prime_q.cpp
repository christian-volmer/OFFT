
//          Copyright Christian Volmer 2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include "prime_q.h"
#include "miller_rabin_probable_prime_q.h"

namespace offt {
namespace math {

using std::ptrdiff_t;

bool PrimeQ(ptrdiff_t n)
{
	// Negative and positive integers are treated alike
	if (n < 0)
		n = -n;

	// Test small primes before we do more elaborate testing
	if (n < 2)
		return false; // non-prime: 0, 1
	else if (n <= 3)
		return true; // prime: 2, 3
	else if (n % 2 == 0)
		return false; // non-prime: all even numbers (except 2)
	else if (n % 3 == 0)
		return false; // non-prime: all numbers divisible by 3 (except 3)
	else if (n < 1000) {

		// Perform trial division by small factors (wheel factorised modulo 6) 
		// 5, 7, 11, 13, 17, 19, 23, 25, ... (not all are prime)
		for (ptrdiff_t k = 5; k*k <= n; k += 6) {
			if (n % k == 0)
				return false;

			if (n % (k + 2) == 0)
				return false;
		}

		return true;
	}
	else {

		// Perform Miller-Rabin strong pseudo-prime tests on bases that are known to give correct results.
		// The limits can be found here: http://oeis.org/A014233.

		bool prime = MillerRabinProbablePrimeQ(2, n);

		if (prime && n >= 2047)
			prime &= MillerRabinProbablePrimeQ(3, n);

		if (prime && n >= 1373653)
			prime &= MillerRabinProbablePrimeQ(5, n);

		if (prime && n >= 25326001)
			prime &= MillerRabinProbablePrimeQ(7, n);

		if (prime && n >= 3215031751)
			prime &= MillerRabinProbablePrimeQ(11, n);

		if (prime && n >= 2152302898747)
			prime &= MillerRabinProbablePrimeQ(13, n);

		if (prime && n >= 3474749660383)
			prime &= MillerRabinProbablePrimeQ(17, n);

		if (prime && n >= 341550071728321)
			prime &= MillerRabinProbablePrimeQ(19, n);

		if (prime && n >= 341550071728321)
			prime &= MillerRabinProbablePrimeQ(23, n);

		if (prime && n >= 3825123056546413051)
			prime &= MillerRabinProbablePrimeQ(29, n);

		if (prime && n >= 3825123056546413051)
			prime &= MillerRabinProbablePrimeQ(31, n);

		if (prime && n >= 3825123056546413051)
			prime &= MillerRabinProbablePrimeQ(37, n);

		return prime;
	}
}

}
}
