
//          Copyright Christian Volmer 2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <cstddef>

namespace offt {
namespace math {

// Computes the remainder of integer division for positive 'divisor'.
// The result is always in the range '0 .. divisor - 1'.
std::ptrdiff_t Mod(std::ptrdiff_t dividend, std::ptrdiff_t divisor);

}
}
