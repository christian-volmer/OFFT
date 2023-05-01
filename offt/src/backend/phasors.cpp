
//          Copyright Christian Volmer 2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include "phasors.h"

#include <algorithm>

namespace offt {
namespace backend {

template class Phasors<float>;
template class Phasors<double>;

template<typename valueT>
Phasors<valueT>::Phasors(size_t length) :
	mLength(length),
	mLargePhasors(),
	mSmallPhasors()
{
	static realT const TWO_PI = realT(6.28318530717958647692528676656);

	size_t splitLength = GetSplitLength();

	size_t smallLength = std::min(splitLength, mLength);
	mSmallPhasors.resize(smallLength);

	for (size_t i = 0; i < smallLength; ++i)
		mSmallPhasors[i] = std::exp(complexT(0, TWO_PI * i / mLength));

	size_t largeLength = (mLength + splitLength - 1) / splitLength;

	if (largeLength > 1) {

		mLargePhasors.resize(largeLength);

		for (size_t i = 0; i < largeLength; ++i)
			mLargePhasors[i] = std::exp(complexT(0, TWO_PI * i * splitLength / mLength));
	}
}

template<typename valueT>
size_t Phasors<valueT>::GetLength() const
{
	return mLength;
}

/*

template<typename valueT>
void Phasors<valueT>::Twiddle(realT *t, realT const *real, realT const *imag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement, size_t length) const
{
	for (size_t i = 0; i < length; ++i) {

		Multiply(t[2 * i], t[2 * i + 1], real[i * stride], imag[i * stride], twiddleStart + i * twiddleIncrement);
	}
}

template<typename valueT>
void Phasors<valueT>::TwiddleInplace(realT *real, realT *imag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement, size_t length) const
{
	realT const *sa = reinterpret_cast<realT const *>(mSmallPhasors.data());
	realT const *la = reinterpret_cast<realT const *>(mLargePhasors.data());

	size_t index = twiddleStart;

	for (size_t k = 0; k < length; ++k) {

		size_t sx = index % SPLIT_LENGTH;
		size_t lx = index / SPLIT_LENGTH;

		realT sr = sa[2*sx+0];
		realT si = sa[2*sx+1];
		realT lr = la[2*lx+0];
		realT li = la[2*lx+1];

		realT r = *real;
		realT i = *imag;

		*real = -(i*lr*si) - li*r*si - i*li*sr + lr*r*sr;
		*imag = -(i*li*si) + lr*r*si + i*lr*sr + li*r*sr;

		real += stride;
		imag += stride;
		index += twiddleIncrement;
	}
}

*/

}
}
