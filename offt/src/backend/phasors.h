
//          Copyright Christian Volmer 2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <cassert>
#include <complex>
#include <cstddef>
#include <vector>

namespace offt {
namespace backend {

using std::ptrdiff_t;
using std::size_t;

template<typename valueT>
class Phasors {

private:

	static size_t const SPLIT_LENGTH = 2048;

	using realT = valueT;
	using complexT = std::complex<valueT>;

	size_t const mLength;

	std::vector<complexT> mLargePhasors;
	std::vector<complexT> mSmallPhasors;

	size_t GetSplitLength() const
	{
		return SPLIT_LENGTH;
	}

public:

	Phasors(size_t length);

	size_t GetLength() const;

	void Load(realT &twiddleR, realT &twiddleI, size_t index) const
	{
		complexT small = mSmallPhasors[index % SPLIT_LENGTH];
		realT sr = small.real();
		realT si = small.imag();

		if (index < SPLIT_LENGTH) {

			twiddleR = sr;
			twiddleI = si;
		}
		else {

			complexT large = mLargePhasors[index / SPLIT_LENGTH];
			realT lr = large.real();
			realT li = large.imag();

			twiddleR = sr * lr - si * li;
			twiddleI = sr * li + si * lr;
		}
	}

	void Multiply(realT &destR, realT &destI, realT const &srcR, realT const &srcI, size_t index) const
	{
		if (index == 0) {

			destR = srcR;
			destI = srcI;
		}
		else {
			complexT small = mSmallPhasors[index % SPLIT_LENGTH];
			realT sr = small.real();
			realT si = small.imag();

			if (index < SPLIT_LENGTH) {

				destR = sr * srcR - si * srcI;
				destI = sr * srcI + si * srcR;
			}
			else {

				complexT large = mLargePhasors[index / SPLIT_LENGTH];
				realT lr = large.real();
				realT li = large.imag();

				realT t1 = lr * sr - li * si;
				realT t2 = lr * si + li * sr;

				destR = t1 * srcR - t2 * srcI;
				destI = t1 * srcI + t2 * srcR;
			}
		}
	}

	/*

	void Twiddle(realT *t, realT const *real, realT const *imag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement, size_t length) const;
	void TwiddleInplace(realT *real, realT *imag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement, size_t length) const;

	*/
};

}
}
