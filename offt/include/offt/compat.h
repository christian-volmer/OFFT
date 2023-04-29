
//          Copyright Christian Volmer 2023.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#pragma once

/*

Make constexpr optional. 

This allows us to compile on Visual Studio 2013, which has partial 
support for C++11 but doesn't support 'constexpr'

*/

#ifdef __cpp_constexpr

#define OFFT_OPTIONAL_CONSTEXPR constexpr

#else

#define OFFT_OPTIONAL_CONSTEXPR

#endif


/*

Disable checked iterators on Visual Studio 2013

*/

#define _SCL_SECURE_NO_WARNINGS
