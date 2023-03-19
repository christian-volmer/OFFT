
//          Copyright Christian Volmer 2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include "phasors.h"

#include <algorithm>

namespace offt {
namespace backend {

using std::size_t;
using std::ptrdiff_t;

template class Phasors<float>;
template class Phasors<double>;

static size_t constexpr SPLIT_LENGTH = 2048;

template<typename valueT>
Phasors<valueT>::Phasors(size_t length) :
	mLength(length),
	mLargePhasors(),
	mSmallPhasors()
{
	static realT constexpr TWO_PI = realT(6.28318530717958647692528676656);

	size_t smallLength = std::min(SPLIT_LENGTH, mLength);
	mSmallPhasors.resize(smallLength);

	for (size_t i = 0; i < smallLength; ++i)
		mSmallPhasors[i] = std::exp(complexT(0, TWO_PI * i / mLength));

	size_t largeLength = (mLength + SPLIT_LENGTH - 1) / SPLIT_LENGTH;

	if (largeLength > 1) {

		mLargePhasors.resize(largeLength);

		for (size_t i = 0; i < largeLength; ++i)
			mLargePhasors[i] = std::exp(complexT(0, TWO_PI * i * SPLIT_LENGTH / mLength));
	}
}

template<typename valueT>
size_t Phasors<valueT>::GetLength() const
{
	return mLength;
}

template<typename valueT>
void Phasors<valueT>::Multiply(realT &destR, realT &destI, realT const &srcR, realT const &srcI, size_t index) const
{
	complexT phasor = mSmallPhasors[index % SPLIT_LENGTH];
	if (!mLargePhasors.empty() && index >= SPLIT_LENGTH)
		phasor *= mLargePhasors[index / SPLIT_LENGTH];

	realT cos = phasor.real();
	realT sin = phasor.imag();

	destR = srcR * cos - srcI * sin;
	destI = srcR * sin + srcI * cos;
}

}
}
