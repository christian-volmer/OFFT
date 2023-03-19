
//          Copyright Christian Volmer 2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <cstddef>

namespace offt {
namespace math {

// Computes ax + by = GCD(a, b) using the extended Euclidean algorithm. 'x' and 'y' can 
// be 'nullptr' if their value is not required by the caller. Return value is the 
// GCD of 'a' and 'b'.
std::ptrdiff_t ExtendedGCD(std::ptrdiff_t a, std::ptrdiff_t b, std::ptrdiff_t *x, std::ptrdiff_t *y);

}
}
