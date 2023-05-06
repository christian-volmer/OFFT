
//          Copyright Christian Volmer 2023.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include "module_base.h"

#include <iostream>

/*struct TwiddleInfo {
	size_t length, start, increment;

	friend auto operator<=>(TwiddleInfo const &, TwiddleInfo const &) = default;
};

std::map<TwiddleInfo, size_t> gTwiddles;*/

namespace offt {
namespace backend {

template class ModuleBase<float>;
template class ModuleBase<double>;

template<typename valueT>
void ModuleBase<valueT>::ComputeLoop(
	valueT *pReal, valueT *pImag, ptrdiff_t step,
	size_t twiddleStartStep, size_t twiddleIncrement, size_t twiddleIncrementStep) const
{
	size_t twiddleStart = 0;
	ptrdiff_t stride = mRemainingLength * step;

	for (size_t i = 0; i < mRemainingLength; ++i) {

		/*		std::cout << "Twiddle: "
					<< "length = " << mLength << ", "
					<< "twiddleStart = " << twiddleStart << ", "
					<< "twiddleIncrement = " << twiddleIncrement << "\n";
		*/

		//		gTwiddles[{mLength, twiddleStart, twiddleIncrement}]++;

		for (size_t j = 0; j < mLength; ++j)
			mPhasors.Load(mTwiddles[2 * j], mTwiddles[2 * j + 1], twiddleStart + j * twiddleIncrement);

		Compute(
			pReal, pImag,
			stride,
			mTwiddles.data());

		pReal += step;
		pImag += step;
		twiddleStart += twiddleStartStep;
		twiddleIncrement += twiddleIncrementStep;
	}
}

}
}
