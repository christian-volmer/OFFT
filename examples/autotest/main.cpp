
//          Copyright Christian Volmer 2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include <vector>
#include <complex>
#include <iomanip>
#include <memory>
#include <utility>
#include <chrono>
#include <random>

#include <offt/fourier.h>
#include <offt/math/mod.h>
#include <offt/math/list_product.h>

using std::size_t;
using std::ptrdiff_t;
using value_t = double;
using cpx_t = std::complex<value_t>;

template<typename T>
struct Pi {

	static T constexpr value = T(3.1415926535897932385);
};


int main()
{
	std::cout << Pi<float>::value << "\n";
	return 0;
}
