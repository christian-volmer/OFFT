
//          Copyright Christian Volmer 2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <cstddef>

namespace offt {
namespace math {

// Computes the greatest common divisor (GCD) of 'a' and 'b'
std::ptrdiff_t GCD(std::ptrdiff_t a, std::ptrdiff_t b);

}
}
