
//          Copyright Christian Volmer 2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include <offt/math/list_product.h>

#include <cstdint>
#include <stdexcept>

namespace offt {
namespace math {

using std::size_t;

size_t ListProduct(size_t const *factors, size_t factorCount)
{
	if (factorCount == 0)
		return 1;
	else {

		size_t product = factors[0];

		for (size_t i = 1; i < factorCount; ++i) {

			if (factors[i] == 0)
				return 0;

			size_t temp = product * factors[i];
			if (temp / factors[i] != product)
				std::overflow_error("ListProduct(): overflow during multiplication.");

			product = temp;
		}

		return product;
	}
}

}
}
