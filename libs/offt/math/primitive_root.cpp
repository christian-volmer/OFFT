
//          Copyright Christian Volmer 2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include "primitive_root.h"
#include "prime_q.h"
#include "factor_integer.h"
#include "power_mod.h"

#include <set>
#include <stdexcept>

namespace offt {
namespace math {

using std::ptrdiff_t;

ptrdiff_t PrimitiveRoot(ptrdiff_t n)
{
	if (!(n > 1))
		throw std::invalid_argument("PrimitiveRoot(): parameter 'n' must be greater than 1.");

	// Implementation of the algorithm presented by Vadim at
	// http://math.stackexchange.com/questions/124408/finding-a-primitive-root-of-a-prime-number
	// See also https://en.wikipedia.org/wiki/Primitive_root_modulo_n#Finding_primitive_roots

	if (!PrimeQ(n))
		throw std::invalid_argument("PrimitiveRoot(): parameter 'n' must be a prime number.");

	ptrdiff_t eulerPhi = n - 1;  // This assumes that 'n' is prime.

	std::set<ptrdiff_t> tests;
	FactorInteger(eulerPhi, [eulerPhi, &tests](ptrdiff_t factor) { tests.insert(eulerPhi / factor); });

	for (ptrdiff_t a = 2; a < n; ++a) {

		bool found = true;

		for (auto it = tests.begin(); it != tests.end(); ++it)
			if (PowerMod(a, *it, n) == 1) {

				found = false;
				break;
			}

		if (found)
			return a;
	}

	throw std::runtime_error("PrimitiveRoot(): internal error. Should have found a primitive root but did not.");
}


}
}
