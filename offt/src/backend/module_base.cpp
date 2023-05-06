
//          Copyright Christian Volmer 2023.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include "module_base.h"

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

		Compute(
			pReal, pImag,
			stride,
			twiddleStart,
			twiddleIncrement);

		pReal += step;
		pImag += step;
		twiddleStart += twiddleStartStep;
		twiddleIncrement += twiddleIncrementStep;
	}
}

}
}
