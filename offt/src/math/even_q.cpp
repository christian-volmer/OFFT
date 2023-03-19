
//          Copyright Christian Volmer 2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include <offt/math/even_q.h>

namespace offt {
namespace math {

using std::ptrdiff_t;

bool EvenQ(ptrdiff_t value)
{
	return value % 2 == 0;
}

}
}
