
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

	static size_t const SPLIT_LENGTH = 2048;

	using realT = valueT;
	using complexT = std::complex<valueT>;
	
	std::size_t mLength;

	std::vector<complexT> mLargePhasors;
	std::vector<complexT> mSmallPhasors;

	size_t GetSplitLength() const
	{
		return SPLIT_LENGTH;
	}

public:

	Phasors(std::size_t length);

	std::size_t GetLength() const;

	void Multiply(realT &destR, realT &destI, realT const &srcR, realT const &srcI, std::size_t index) const
	{
		complexT phasor = mSmallPhasors[index % SPLIT_LENGTH];
		if (!mLargePhasors.empty() && index >= SPLIT_LENGTH)
			phasor *= mLargePhasors[index / SPLIT_LENGTH];

		realT cos = phasor.real();
		realT sin = phasor.imag();

		destR = srcR * cos - srcI * sin;
		destI = srcR * sin + srcI * cos;
	}

	void Twiddle(realT *t, realT const *real, realT const *imag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement, size_t length) const;
};

}
}
