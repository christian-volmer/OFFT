
//          Copyright Christian Volmer 2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <cstddef>

namespace offt {
namespace math {

// Returns a primitive root of the given prime number 'n'.
std::ptrdiff_t PrimitiveRoot(std::ptrdiff_t n);

}
}
