
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

template<> StandardModuleComplexity const StandardModule<float, 10>::Complexity = { 0, 0 };
template<> StandardModuleComplexity const StandardModule<double, 10>::Complexity = { 0, 0 };

template<typename valueT>
static void ComputeCore(Phasors<valueT> const &phasors, valueT *pReal, valueT *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement)
{
	valueT r10, i10, r12, i12, r20, i20, r14, i14, r28, i28;
	valueT r30, i30, r38, i38, r54, i54, r3, i3, r5, i5;
	valueT r7, i7, r9, i9, r17, i17, r19, i19, r29, i29;
	valueT r33, i33, r66, i66, r76, i76, r78, i78, r70, i70;
	valueT r82, i82, r88, i88, r73, i73, r75, i75, r81, i81;
	valueT r85, i85, r83, i83, r80, i80;

	phasors.Multiply(r10, i10, pReal[9 * stride], pImag[9 * stride], twiddleStart + 9 * twiddleIncrement);
	{
		valueT s1r, s1i;
		phasors.Multiply(s1r, s1i, pReal[1 * stride], pImag[1 * stride], twiddleStart + 1 * twiddleIncrement);
		r12 = s1r - r10;
		i12 = s1i - i10;
		r20 = r10 + s1r;
		i20 = i10 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i;
		phasors.Multiply(s1r, s1i, pReal[3 * stride], pImag[3 * stride], twiddleStart + 3 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[7 * stride], pImag[7 * stride], twiddleStart + 7 * twiddleIncrement);
		r14 = s1r - s2r;
		i14 = s1i - s2i;
		s3r = s1r + s2r;
		s3i = s1i + s2i;
		r28 = s3r - r20;
		i28 = s3i - i20;
		r30 = r20 + s3r;
		i30 = i20 + s3i;
	}
	{
		valueT s1r, s1i;
		phasors.Multiply(s1r, s1i, pReal[5 * stride], pImag[5 * stride], twiddleStart + 5 * twiddleIncrement);
		r38 = r30 + s1r;
		i38 = i30 + s1i;
		r54 = valueT(-1.25) * r30;
		i54 = valueT(-1.25) * i30;
	}
	{
		valueT s1r, s1i;
		phasors.Multiply(s1r, s1i, pReal[0 * stride], pImag[0 * stride], twiddleStart + 0 * twiddleIncrement);
		phasors.Multiply(r3, i3, pReal[2 * stride], pImag[2 * stride], twiddleStart + 2 * twiddleIncrement);
		phasors.Multiply(r5, i5, pReal[4 * stride], pImag[4 * stride], twiddleStart + 4 * twiddleIncrement);
		phasors.Multiply(r7, i7, pReal[6 * stride], pImag[6 * stride], twiddleStart + 6 * twiddleIncrement);
		phasors.Multiply(r9, i9, pReal[8 * stride], pImag[8 * stride], twiddleStart + 8 * twiddleIncrement);
		r17 = r5 + r7;
		i17 = i5 + i7;
		r19 = r3 + r9;
		i19 = i3 + i9;
		r29 = r17 + r19;
		i29 = i17 + i19;
		r33 = s1r + r29;
		i33 = s1i + i29;
		pReal[5 * stride] = r33 - r38;
		pImag[5 * stride] = i33 - i38;
		pReal[0 * stride] = r38 + r33;
		pImag[0 * stride] = i38 + i33;
		r66 = r38 + r54;
		i66 = i38 + i54;
	}
	{
		valueT s1r, s1i;
		s1r = valueT(0.5590169943749474241) * r28;
		s1i = valueT(0.5590169943749474241) * i28;
		r76 = s1r - r66;
		i76 = s1i - i66;
		r78 = r66 + s1r;
		i78 = i66 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		s1r = valueT(1.5388417685876267013) * i14;
		s1i = valueT(-1.5388417685876267013) * r14;
		s2r = r12 - r14;
		s2i = i12 - i14;
		s3r = valueT(-0.36327126400268044295) * i12;
		s3i = valueT(0.36327126400268044295) * r12;
		s4r = valueT(0.58778525229247312917) * s2i;
		s4i = valueT(-0.58778525229247312917) * s2r;
		s5r = s1r + s4r;
		s5i = s1i + s4i;
		r70 = s3r - s4r;
		i70 = s3i - s4i;
		r82 = s5r - r78;
		i82 = s5i - i78;
		r88 = r78 + s5r;
		i88 = i78 + s5i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		valueT s11r, s11i, s12r, s12i, s13r, s13i;
		s1r = r5 - r7;
		s1i = i5 - i7;
		s2r = r3 - r9;
		s2i = i3 - i9;
		s3r = valueT(0.36327126400268044295) * s1i;
		s3i = valueT(-0.36327126400268044295) * s1r;
		s4r = s2r - s1r;
		s4i = s2i - s1i;
		s5r = valueT(-1.5388417685876267013) * s2i;
		s5i = valueT(1.5388417685876267013) * s2r;
		s6r = r17 - r19;
		s6i = i17 - i19;
		s7r = valueT(0.58778525229247312917) * s4i;
		s7i = valueT(-0.58778525229247312917) * s4r;
		s8r = valueT(-0.5590169943749474241) * s6r;
		s8i = valueT(-0.5590169943749474241) * s6i;
		s9r = valueT(-1.25) * r29;
		s9i = valueT(-1.25) * i29;
		r73 = s3r - s7r;
		i73 = s3i - s7i;
		s10r = s5r + s7r;
		s10i = s5i + s7i;
		s11r = r33 + s9r;
		s11i = i33 + s9i;
		r75 = s8r - s11r;
		i75 = s8i - s11i;
		s12r = s8r + s11r;
		s12i = s8i + s11i;
		r81 = s10r - s12r;
		i81 = s10i - s12i;
		s13r = s10r + s12r;
		s13i = s10i + s12i;
		pReal[1 * stride] = s13r - r88;
		pImag[1 * stride] = s13i - i88;
		pReal[6 * stride] = r88 + s13r;
		pImag[6 * stride] = i88 + s13i;
	}
	pReal[4 * stride] = -r82 - r81;
	pImag[4 * stride] = -i82 - i81;
	pReal[9 * stride] = r82 - r81;
	pImag[9 * stride] = i82 - i81;
	r85 = r75 - r73;
	i85 = i75 - i73;
	r83 = r73 + r75;
	i83 = i73 + i75;
	{
		valueT s1r, s1i;
		r80 = r70 - r76;
		i80 = i70 - i76;
		s1r = r76 + r70;
		s1i = i76 + i70;
		pReal[8 * stride] = -r83 - s1r;
		pImag[8 * stride] = -i83 - s1i;
		pReal[3 * stride] = s1r - r83;
		pImag[3 * stride] = s1i - i83;
	}
	pReal[7 * stride] = -r85 - r80;
	pImag[7 * stride] = -i85 - i80;
	pReal[2 * stride] = r80 - r85;
	pImag[2 * stride] = i80 - i85;
}

template<> void StandardModule<float, 10>::Compute(float *pReal, float *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

template<> void StandardModule<double, 10>::Compute(double *pReal, double *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

}
}
