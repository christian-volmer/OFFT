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
