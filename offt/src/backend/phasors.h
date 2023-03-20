
//          Copyright Christian Volmer 2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <cstddef>
#include <complex>
#include <vector>

namespace offt {
namespace backend {

template<typename valueT>
class Phasors {

private:

	using realT = valueT;
	using complexT = std::complex<valueT>;
	
	std::size_t mLength;

	std::vector<complexT> mLargePhasors;
	std::vector<complexT> mSmallPhasors;

public:

	Phasors(std::size_t length);

	std::size_t GetLength() const;

	void Multiply(realT &destR, realT &destI, realT const &srcR, realT const &srcI, std::size_t index) const;
};

}
}
