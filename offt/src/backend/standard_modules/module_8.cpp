
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

template<> StandardModuleComplexity const StandardModule<float, 8>::Complexity = { 0, 0 };
template<> StandardModuleComplexity const StandardModule<double, 8>::Complexity = { 0, 0 };

template<typename valueT>
static void ComputeCore(Phasors<valueT> const &phasors, valueT *pReal, valueT *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement)
{
	valueT r8, i8, r20, i20, r24, i24, r18, i18, r38, i38;
	valueT r40, i40, r9, i9, r11, i11, r21, i21, r19, i19;
	valueT r17, i17, r36, i36;

	phasors.Multiply(r8, i8, pReal[7 * stride], pImag[7 * stride], twiddleStart + 7 * twiddleIncrement);
	{
		valueT s1r, s1i;
		phasors.Multiply(s1r, s1i, pReal[3 * stride], pImag[3 * stride], twiddleStart + 3 * twiddleIncrement);
		r20 = s1r - r8;
		i20 = s1i - i8;
		r24 = r8 + s1r;
		i24 = i8 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i;
		phasors.Multiply(s1r, s1i, pReal[1 * stride], pImag[1 * stride], twiddleStart + 1 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[5 * stride], pImag[5 * stride], twiddleStart + 5 * twiddleIncrement);
		r18 = s1r - s2r;
		i18 = s1i - s2i;
		s3r = s1r + s2r;
		s3i = s1i + s2i;
		r38 = s3r - r24;
		i38 = s3i - i24;
		r40 = r24 + s3r;
		i40 = i24 + s3i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i;
		phasors.Multiply(s1r, s1i, pReal[0 * stride], pImag[0 * stride], twiddleStart + 0 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[2 * stride], pImag[2 * stride], twiddleStart + 2 * twiddleIncrement);
		phasors.Multiply(s3r, s3i, pReal[4 * stride], pImag[4 * stride], twiddleStart + 4 * twiddleIncrement);
		phasors.Multiply(s4r, s4i, pReal[6 * stride], pImag[6 * stride], twiddleStart + 6 * twiddleIncrement);
		r9 = s1r - s3r;
		i9 = s1i - s3i;
		s5r = s1r + s3r;
		s5i = s1i + s3i;
		r11 = s2r - s4r;
		i11 = s2i - s4i;
		s6r = s2r + s4r;
		s6i = s2i + s4i;
		r21 = s5r - s6r;
		i21 = s5i - s6i;
		s7r = s5r + s6r;
		s7i = s5i + s6i;
		pReal[4 * stride] = s7r - r40;
		pImag[4 * stride] = s7i - i40;
		pReal[0 * stride] = r40 + s7r;
		pImag[0 * stride] = i40 + s7i;
	}
	pReal[6 * stride] = i38 + r21;
	pImag[6 * stride] = i21 - r38;
	pReal[2 * stride] = r21 - i38;
	pImag[2 * stride] = r38 + i21;
	r19 = i9 + r11;
	i19 = i11 - r9;
	r17 = r9 + i11;
	i17 = i9 - r11;
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i;
		s1r = valueT(0.7071067811865475244) * r18 - valueT(0.7071067811865475244) * i18;
		s1i = valueT(0.7071067811865475244) * r18 + valueT(0.7071067811865475244) * i18;
		s2r = valueT(-0.7071067811865475244) * r20 - valueT(0.7071067811865475244) * i20;
		s2i = valueT(0.7071067811865475244) * r20 - valueT(0.7071067811865475244) * i20;
		s3r = s1r - s2r;
		s3i = s1i - s2i;
		r36 = s1r + s2r;
		i36 = s1i + s2i;
		pReal[7 * stride] = r17 + s3i;
		pImag[7 * stride] = i17 - s3r;
		pReal[3 * stride] = r17 - s3i;
		pImag[3 * stride] = i17 + s3r;
	}
	pReal[5 * stride] = -i19 - r36;
	pImag[5 * stride] = r19 - i36;
	pReal[1 * stride] = r36 - i19;
	pImag[1 * stride] = r19 + i36;
}

template<> void StandardModule<float, 8>::Compute(float *pReal, float *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

template<> void StandardModule<double, 8>::Compute(double *pReal, double *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

}
}
