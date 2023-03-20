
//          Copyright Christian Volmer 2023.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <cstddef>

/// @brief Runs tests on random transform in an infinite loop and prints result statistics to cout.
/// @param MaximumDepth specifies the maximum depth of the transform to test.
/// @param MaximumElementCount is the maximum number of elements in the, possibly multi-dimensional, transform 
/// @param MinimumTestTime is the minimum time, in seconds, to run the test for on a specific transform size
void RandomisedTest(size_t MaximumDepth, size_t MaximumElementCount, double MinimumTestTime);
