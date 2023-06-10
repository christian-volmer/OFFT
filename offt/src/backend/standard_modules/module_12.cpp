
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

template<> StandardModuleComplexity const StandardModule<float, 12>::Complexity = { 0, 0 };
template<> StandardModuleComplexity const StandardModule<double, 12>::Complexity = { 0, 0 };

template<typename valueT>
static void ComputeCore(Phasors<valueT> const &phasors, valueT *pReal, valueT *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement)
{
	valueT r12, i12, r20, i20, r24, i24, r14, i14, r34, i34;
	valueT r28, i28, r42, i42, r48, i48, r60, i60, r3, i3;
	valueT r5, i5, r9, i9, r11, i11, r21, i21, r23, i23;
	valueT r25, i25, r31, i31, r43, i43, r40, i40, r72, i72;
	valueT r38, i38, r80, i80, r84, i84, r41, i41, r45, i45;
	valueT r75, i75, r57, i57, r69, i69, r77, i77, r81, i81;
	valueT r74, i74;

	phasors.Multiply(r12, i12, pReal[11 * stride], pImag[11 * stride], twiddleStart + 11 * twiddleIncrement);
	{
		valueT s1r, s1i;
		phasors.Multiply(s1r, s1i, pReal[7 * stride], pImag[7 * stride], twiddleStart + 7 * twiddleIncrement);
		r20 = s1r - r12;
		i20 = s1i - i12;
		r24 = r12 + s1r;
		i24 = i12 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		phasors.Multiply(s1r, s1i, pReal[1 * stride], pImag[1 * stride], twiddleStart + 1 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[3 * stride], pImag[3 * stride], twiddleStart + 3 * twiddleIncrement);
		phasors.Multiply(s3r, s3i, pReal[5 * stride], pImag[5 * stride], twiddleStart + 5 * twiddleIncrement);
		phasors.Multiply(s4r, s4i, pReal[9 * stride], pImag[9 * stride], twiddleStart + 9 * twiddleIncrement);
		r14 = s1r - s3r;
		i14 = s1i - s3i;
		s5r = s1r + s3r;
		s5i = s1i + s3i;
		r34 = s4r + s5r;
		i34 = s4i + s5i;
		r28 = r24 + s2r;
		i28 = i24 + s2i;
		r42 = s5r - r24;
		i42 = s5i - i24;
		r48 = r24 + s5r;
		i48 = i24 + s5i;
	}
	r60 = valueT(-1.5) * r48;
	i60 = valueT(-1.5) * i48;
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i;
		phasors.Multiply(s1r, s1i, pReal[0 * stride], pImag[0 * stride], twiddleStart + 0 * twiddleIncrement);
		phasors.Multiply(r3, i3, pReal[2 * stride], pImag[2 * stride], twiddleStart + 2 * twiddleIncrement);
		phasors.Multiply(r5, i5, pReal[4 * stride], pImag[4 * stride], twiddleStart + 4 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[6 * stride], pImag[6 * stride], twiddleStart + 6 * twiddleIncrement);
		phasors.Multiply(r9, i9, pReal[8 * stride], pImag[8 * stride], twiddleStart + 8 * twiddleIncrement);
		phasors.Multiply(r11, i11, pReal[10 * stride], pImag[10 * stride], twiddleStart + 10 * twiddleIncrement);
		r21 = r5 + r9;
		i21 = i5 + i9;
		r23 = r3 + r11;
		i23 = i3 + i11;
		r25 = s1r + r21;
		i25 = s1i + i21;
		r31 = s2r + r23;
		i31 = s2i + i23;
		r43 = r25 + r31;
		i43 = i25 + i31;
		r40 = r28 - r34;
		i40 = i28 - i34;
		s3r = r34 + r28;
		s3i = i34 + i28;
		pReal[6 * stride] = r43 - s3r;
		pImag[6 * stride] = i43 - s3i;
		pReal[0 * stride] = r43 + s3r;
		pImag[0 * stride] = i43 + s3i;
		r72 = r60 + s3r;
		i72 = i60 + s3i;
	}
	{
		valueT s1r, s1i, s2r, s2i;
		r38 = r14 - r20;
		i38 = i14 - i20;
		s1r = r20 + r14;
		s1i = i20 + i14;
		s2r = valueT(-0.86602540378443864676) * s1i;
		s2i = valueT(0.86602540378443864676) * s1r;
		r80 = s2r - r72;
		i80 = s2i - i72;
		r84 = r72 + s2r;
		i84 = i72 + s2i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i;
		s1r = r5 - r9;
		s1i = i5 - i9;
		s2r = r3 - r11;
		s2i = i3 - i11;
		s3r = s2r - s1r;
		s3i = s2i - s1i;
		r41 = s1r + s2r;
		i41 = s1i + s2i;
		r45 = r21 - r23;
		i45 = i21 - i23;
		s4r = r21 + r23;
		s4i = i21 + i23;
		s5r = valueT(0.86602540378443864676) * s3i;
		s5i = valueT(-0.86602540378443864676) * s3r;
		s6r = valueT(-1.5) * s4r;
		s6i = valueT(-1.5) * s4i;
		s7r = r43 + s6r;
		s7i = i43 + s6i;
		r75 = s5r - s7r;
		i75 = s5i - s7i;
		s8r = s5r + s7r;
		s8i = s5i + s7i;
		pReal[10 * stride] = s8r - r84;
		pImag[10 * stride] = s8i - i84;
		pReal[4 * stride] = r84 + s8r;
		pImag[4 * stride] = i84 + s8i;
	}
	pReal[8 * stride] = -r80 - r75;
	pImag[8 * stride] = -i80 - i75;
	pReal[2 * stride] = r80 - r75;
	pImag[2 * stride] = i80 - i75;
	r57 = valueT(-1.5) * r45;
	i57 = valueT(-1.5) * i45;
	{
		valueT s1r, s1i;
		s1r = r25 - r31;
		s1i = i25 - i31;
		r69 = r57 + s1r;
		i69 = i57 + s1i;
		pReal[3 * stride] = i40 + s1r;
		pImag[3 * stride] = s1i - r40;
		pReal[9 * stride] = s1r - i40;
		pImag[9 * stride] = r40 + s1i;
	}
	{
		valueT s1r, s1i;
		s1r = valueT(-0.86602540378443864676) * i41;
		s1i = valueT(0.86602540378443864676) * r41;
		r77 = s1r - r69;
		i77 = s1i - i69;
		r81 = r69 + s1r;
		i81 = i69 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i;
		s1r = valueT(0.86602540378443864676) * r38;
		s1i = valueT(0.86602540378443864676) * i38;
		s2r = valueT(-1.5) * i42;
		s2i = valueT(1.5) * r42;
		s3r = s2r - i40;
		s3i = r40 + s2i;
		r74 = s1r - s3r;
		i74 = s1i - s3i;
		s4r = s1r + s3r;
		s4i = s1i + s3i;
		pReal[7 * stride] = r81 - s4r;
		pImag[7 * stride] = i81 - s4i;
		pReal[1 * stride] = r81 + s4r;
		pImag[1 * stride] = i81 + s4i;
	}
	pReal[5 * stride] = -r77 - r74;
	pImag[5 * stride] = -i77 - i74;
	pReal[11 * stride] = r74 - r77;
	pImag[11 * stride] = i74 - i77;
}

template<> void StandardModule<float, 12>::Compute(float *pReal, float *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

template<> void StandardModule<double, 12>::Compute(double *pReal, double *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

}
}
