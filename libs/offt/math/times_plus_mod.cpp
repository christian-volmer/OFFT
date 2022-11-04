
//          Copyright Christian Volmer 2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include "times_plus_mod.h"
#include "mod.h"

#include <cstdint>
#include <stdexcept>

namespace offt {
namespace math {

using std::ptrdiff_t;

ptrdiff_t TimesPlusMod(ptrdiff_t a, ptrdiff_t b, ptrdiff_t c, ptrdiff_t modulus)
{
	if (a < 0)
		throw std::invalid_argument("TimesPlusMod(): 'a' must be non-negative.");

	if (b < 0)
		throw std::invalid_argument("TimesPlusMod(): 'b' must be non-negative.");

	if (c < 0)
		throw std::invalid_argument("TimesPlusMod(): 'c' must be non-negative.");

	if (modulus <= 0)
		throw std::invalid_argument("TimesPlusMod(): 'm' must be positive.");

	std::uintmax_t working_a = static_cast<std::uintmax_t>(a);
	std::uintmax_t working_b = static_cast<std::uintmax_t>(b);
	std::uintmax_t working_c = static_cast<std::uintmax_t>(c);
	std::uintmax_t working_m = static_cast<std::uintmax_t>(modulus);

	std::uintmax_t result;
	std::uintmax_t temp;

	if (working_a != 0) {

		temp = working_a * working_b;
		if (temp / working_a != working_b)
			std::overflow_error("TimesPlusMod(): overflow during modular multiplication.");

		temp = temp % working_m;
	}
	else
		temp = 0;

	if (working_c == 0)
		return static_cast<ptrdiff_t>(temp);

	result = temp + working_c;
	if (result < temp || result < working_c)
		std::overflow_error("TimesPlusMod(): overflow during modular addition.");

	return static_cast<ptrdiff_t>(result % working_m);
}

}
}
