
//          Copyright Christian Volmer 2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <cstddef>

namespace offt {
namespace math {

// Computes 'a' times 'b' plus 'c' modulo 'modulus'. 
std::ptrdiff_t TimesPlusMod(std::ptrdiff_t a, std::ptrdiff_t b, std::ptrdiff_t c, std::ptrdiff_t modulus);

}
}
