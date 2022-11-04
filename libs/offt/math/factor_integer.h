
//          Copyright Christian Volmer 2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <cstddef>
#include <functional>

namespace offt {
namespace math {

// Decomposes 'n' into its prime factors. 'factorCallback' is called
// for every prime factor of 'n' with the factor given as the parameter.
void FactorInteger(std::ptrdiff_t n, std::function<void(std::ptrdiff_t)> factorCallback);

}
}
