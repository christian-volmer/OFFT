
//          Copyright Christian Volmer 2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include "power_mod.h"
#include "extended_gcd.h"
#include "mod.h"
#include "odd_q.h"

#include <limits>
#include <stdexcept>

namespace offt {
namespace math {

using std::ptrdiff_t;

ptrdiff_t PowerMod(ptrdiff_t base, ptrdiff_t exponent, ptrdiff_t modulus)
{
	if (base < 0)
		throw std::invalid_argument("PowerMod(): parameter 'base' must be non-negative");

	if (exponent < -std::numeric_limits<ptrdiff_t>::max())
		throw std::invalid_argument("PowerMod(): parameter 'exponent' is out of range.");

	if (modulus <= 0)
		throw std::invalid_argument("PowerMod(): parameter 'modulus' must be positive.");

	if (exponent == 0)
		return 1;

	if (base == 0)
		return 0;

	// If the exponent is negative, we first find the modular inverse using
	// the extended GCD and then continue exponentiation with the absolute value of the exponent.
	// See https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Computing_multiplicative_inverses_in_modular_structures
	if (exponent < 0) {

		ptrdiff_t inverse;
		if (base == 0 || ExtendedGCD(base, modulus, &inverse, nullptr) != 1)
			throw std::runtime_error("PowerMod(): modular inverse does not exist.");

		base = Mod(inverse, modulus);
		exponent = -exponent;
	}

	std::uintmax_t result = 1;
	std::uintmax_t workingModulus = static_cast<std::uintmax_t>(modulus);
	std::uintmax_t workingBase = static_cast<std::uintmax_t>(base) % workingModulus;
	std::uintmax_t temp;

	// Perform 'exponentiation by squaring'.
	// See https://en.wikipedia.org/wiki/Exponentiation_by_squaring

	while (exponent > 0) {

		if (OddQ(exponent)) {

			temp = result * workingBase;
			if (temp / workingBase != result)
				std::overflow_error("PowerMod(): overflow during modular exponentiation.");

			result = temp % workingModulus;
		}

		temp = workingBase * workingBase;
		if (temp / workingBase != workingBase)
			std::overflow_error("PowerMod(): overflow during modular exponentiation.");

		workingBase = temp % workingModulus;

		exponent /= 2;
	}

	return static_cast<ptrdiff_t>(result);
}

}
}
