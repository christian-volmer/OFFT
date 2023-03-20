
//          Copyright Christian Volmer 2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "phasors.h"

#include <map>
#include <vector>

namespace offt {
namespace backend {

template<typename valueT>
class RaderData {

public:

	std::vector<std::size_t> mPermutation;
	std::vector<valueT> mCoefficients;

	RaderData() :
		mPermutation(),
		mCoefficients()
	{
	}
};

template<typename valueT>
class Storage {

private:

	std::map<std::size_t, Phasors<valueT>> mPhasors;
	std::map<std::size_t, RaderData<valueT>> mRaderData; 

public:

	Storage();

	Phasors<valueT> const &GetPhasors(std::size_t length);
	RaderData<valueT> &GetRaderData(std::size_t length);
};

}
}
