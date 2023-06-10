
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

template<> StandardModuleComplexity const StandardModule<float, 4>::Complexity = { 0, 0 };
template<> StandardModuleComplexity const StandardModule<double, 4>::Complexity = { 0, 0 };

template<typename valueT>
static void ComputeCore(Phasors<valueT> const &phasors, valueT *pReal, valueT *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement)
{
	valueT r4, i4, r6, i6, r8, i8, r5, i5;

	phasors.Multiply(r4, i4, pReal[3 * stride], pImag[3 * stride], twiddleStart + 3 * twiddleIncrement);
	{
		valueT s1r, s1i;
		phasors.Multiply(s1r, s1i, pReal[1 * stride], pImag[1 * stride], twiddleStart + 1 * twiddleIncrement);
		r6 = s1r - r4;
		i6 = s1i - i4;
		r8 = r4 + s1r;
		i8 = i4 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i;
		phasors.Multiply(s1r, s1i, pReal[0 * stride], pImag[0 * stride], twiddleStart + 0 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[2 * stride], pImag[2 * stride], twiddleStart + 2 * twiddleIncrement);
		r5 = s1r - s2r;
		i5 = s1i - s2i;
		s3r = s1r + s2r;
		s3i = s1i + s2i;
		pReal[2 * stride] = s3r - r8;
		pImag[2 * stride] = s3i - i8;
		pReal[0 * stride] = r8 + s3r;
		pImag[0 * stride] = i8 + s3i;
	}
	pReal[3 * stride] = i6 + r5;
	pImag[3 * stride] = i5 - r6;
	pReal[1 * stride] = r5 - i6;
	pImag[1 * stride] = r6 + i5;
}

template<> void StandardModule<float, 4>::Compute(float *pReal, float *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

template<> void StandardModule<double, 4>::Compute(double *pReal, double *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

}
}
