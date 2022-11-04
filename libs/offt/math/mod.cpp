
//          Copyright Christian Volmer 2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include "mod.h"

#include <limits>
#include <stdexcept>

namespace offt {
namespace math {

using std::ptrdiff_t;

ptrdiff_t Mod(ptrdiff_t dividend, ptrdiff_t divisor)
{
	if (dividend < -std::numeric_limits<ptrdiff_t>::max())
		throw std::invalid_argument("Mod(): parameter 'dividend' is out of range.");

	if (divisor <= 0)
		throw std::invalid_argument("Mod(): parameter 'divisor' must be positive.");

	if (dividend >= 0)
		return dividend % divisor;
	else {

		ptrdiff_t temp = (-dividend) % divisor;

		if (temp == 0)
			return 0;

		return divisor - temp;
	}
}

}
}
