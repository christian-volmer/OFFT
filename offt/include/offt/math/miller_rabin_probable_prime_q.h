
//          Copyright Christian Volmer 2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <cstddef>

namespace offt {
namespace math {

// Returns 'true' if the number 'n' is a Miller-Rabin probable prime to given 'base' and 'false' otherwise.
bool MillerRabinProbablePrimeQ(std::ptrdiff_t base, std::ptrdiff_t n);

}
}
