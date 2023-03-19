
//          Copyright Christian Volmer 2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <cstddef>

namespace offt {
namespace math {

// Computes the product of all 'factors'. Throws on arithmetic overflow.
std::size_t ListProduct(std::size_t const *factors, std::size_t factorCount);

}
}
