
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

template<> StandardModuleComplexity const StandardModule<float, 6>::Complexity = { 0, 0 };
template<> StandardModuleComplexity const StandardModule<double, 6>::Complexity = { 0, 0 };

template<typename valueT>
static void ComputeCore(Phasors<valueT> const &phasors, valueT *pReal, valueT *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement)
{
	valueT r6, i6, r8, i8, r12, i12, r16, i16, r24, i24;
	valueT r9, i9, r13, i13, r29, i29, r30, i30, r25, i25;
	valueT r36, i36, r26, i26;

	phasors.Multiply(r6, i6, pReal[5 * stride], pImag[5 * stride], twiddleStart + 5 * twiddleIncrement);
	{
		valueT s1r, s1i;
		phasors.Multiply(s1r, s1i, pReal[1 * stride], pImag[1 * stride], twiddleStart + 1 * twiddleIncrement);
		r8 = s1r - r6;
		i8 = s1i - i6;
		r12 = r6 + s1r;
		i12 = i6 + s1i;
	}
	{
		valueT s1r, s1i;
		phasors.Multiply(s1r, s1i, pReal[3 * stride], pImag[3 * stride], twiddleStart + 3 * twiddleIncrement);
		r16 = r12 + s1r;
		i16 = i12 + s1i;
		r24 = valueT(-1.5) * r12;
		i24 = valueT(-1.5) * i12;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		phasors.Multiply(s1r, s1i, pReal[0 * stride], pImag[0 * stride], twiddleStart + 0 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[2 * stride], pImag[2 * stride], twiddleStart + 2 * twiddleIncrement);
		phasors.Multiply(s3r, s3i, pReal[4 * stride], pImag[4 * stride], twiddleStart + 4 * twiddleIncrement);
		r9 = s2r - s3r;
		i9 = s2i - s3i;
		s4r = s2r + s3r;
		s4i = s2i + s3i;
		r13 = s1r + s4r;
		i13 = s1i + s4i;
		s5r = valueT(-1.5) * s4r;
		s5i = valueT(-1.5) * s4i;
		r29 = s5r - r24;
		i29 = s5i - i24;
		r30 = r24 + s5r;
		i30 = i24 + s5i;
	}
	{
		valueT s1r, s1i;
		r25 = r13 - r16;
		i25 = i13 - i16;
		s1r = r16 + r13;
		s1i = i16 + i13;
		pReal[0 * stride] = s1r;
		pImag[0 * stride] = s1i;
		r36 = r30 + s1r;
		i36 = i30 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i;
		s1r = valueT(-0.86602540378443864676) * i9;
		s1i = valueT(0.86602540378443864676) * r9;
		s2r = valueT(0.86602540378443864676) * i8;
		s2i = valueT(-0.86602540378443864676) * r8;
		r26 = s2r - s1r;
		i26 = s2i - s1i;
		s3r = s1r + s2r;
		s3i = s1i + s2i;
		pReal[2 * stride] = r36 - s3r;
		pImag[2 * stride] = i36 - s3i;
		pReal[4 * stride] = r36 + s3r;
		pImag[4 * stride] = i36 + s3i;
	}
	{
		valueT s1r, s1i;
		pReal[3 * stride] = r25;
		pImag[3 * stride] = i25;
		s1r = r29 + r25;
		s1i = i29 + i25;
		pReal[1 * stride] = s1r - r26;
		pImag[1 * stride] = s1i - i26;
		pReal[5 * stride] = r26 + s1r;
		pImag[5 * stride] = i26 + s1i;
	}
}

template<> void StandardModule<float, 6>::Compute(float *pReal, float *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

template<> void StandardModule<double, 6>::Compute(double *pReal, double *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

}
}
