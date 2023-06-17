
//          Copyright Christian Volmer 2022, 2023.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include "../standard_module.h"

namespace offt {
namespace backend {

/*
	Number of additions       : 0
	Number of multiplications : 0
*/

template<> StandardModuleComplexity const StandardModule<float, 3>::Complexity = { 0, 0 };
template<> StandardModuleComplexity const StandardModule<double, 3>::Complexity = { 0, 0 };

template<typename valueT>
static void ComputeCore(Phasors<valueT> const &phasors, valueT *pReal, valueT *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement)
{
	valueT r3, i3, r5, i5, r6, i6, r7, i7, r12, i12;
	valueT r15, i15;

	phasors.Multiply(r3, i3, pReal[2 * stride], pImag[2 * stride], twiddleStart + 2 * twiddleIncrement);
	{
		valueT s1r, s1i;
		phasors.Multiply(s1r, s1i, pReal[1 * stride], pImag[1 * stride], twiddleStart + 1 * twiddleIncrement);
		r5 = s1r - r3;
		i5 = s1i - i3;
		r6 = r3 + s1r;
		i6 = i3 + s1i;
	}
	{
		valueT s1r, s1i;
		phasors.Multiply(s1r, s1i, pReal[0 * stride], pImag[0 * stride], twiddleStart + 0 * twiddleIncrement);
		r7 = r6 + s1r;
		i7 = i6 + s1i;
		r12 = valueT(-1.5) * r6;
		i12 = valueT(-1.5) * i6;
	}
	pReal[0 * stride] = r7;
	pImag[0 * stride] = i7;
	r15 = r7 + r12;
	i15 = i7 + i12;
	{
		valueT s1r, s1i;
		s1r = valueT(-0.86602540378443864676) * i5;
		s1i = valueT(0.86602540378443864676) * r5;
		pReal[2 * stride] = r15 - s1r;
		pImag[2 * stride] = i15 - s1i;
		pReal[1 * stride] = r15 + s1r;
		pImag[1 * stride] = i15 + s1i;
	}
}

template<> void StandardModule<float, 3>::Compute(float *pReal, float *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

template<> void StandardModule<double, 3>::Compute(double *pReal, double *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

}
}
