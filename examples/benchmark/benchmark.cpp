
//          Copyright Christian Volmer 2023.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include <string>

#include "randomised_testing.h"
#include "self_test.h"

int main(int argc, char *argv[])
{
	if (argc == 2 && std::string("--self-test") == argv[1]) {

		return SelfTest();
	}
	else
		RandomisedTest(2, 1000000, 0.1);

	return 0;
}
