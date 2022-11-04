
//          Copyright Christian Volmer 2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <cstddef>

namespace offt {
namespace math {

// Returns the remainder of the division of 'base' raised to the power of 'exponent' by 'modulus' 
std::ptrdiff_t PowerMod(std::ptrdiff_t base, std::ptrdiff_t exponent, std::ptrdiff_t modulus);

}
}
