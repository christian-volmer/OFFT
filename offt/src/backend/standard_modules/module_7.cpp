
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

template<> StandardModuleComplexity const StandardModule<float, 7>::Complexity = { 0, 0 };
template<> StandardModuleComplexity const StandardModule<double, 7>::Complexity = { 0, 0 };

template<typename valueT>
static void ComputeCore(Phasors<valueT> const &phasors, valueT *pReal, valueT *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement)
{
	valueT r7, i7, r9, i9, r14, i14, r11, i11, r10, i10;
	valueT r20, i20, r22, i22, r19, i19, r21, i21, r38, i38;
	valueT r55, i55, r54, i54, r53, i53, r52, i52, r50, i50;

	phasors.Multiply(r7, i7, pReal[6 * stride], pImag[6 * stride], twiddleStart + 6 * twiddleIncrement);
	{
		valueT s1r, s1i;
		phasors.Multiply(s1r, s1i, pReal[1 * stride], pImag[1 * stride], twiddleStart + 1 * twiddleIncrement);
		r9 = s1r - r7;
		i9 = s1i - i7;
		r14 = r7 + s1r;
		i14 = i7 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i;
		phasors.Multiply(s1r, s1i, pReal[2 * stride], pImag[2 * stride], twiddleStart + 2 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[3 * stride], pImag[3 * stride], twiddleStart + 3 * twiddleIncrement);
		phasors.Multiply(s3r, s3i, pReal[4 * stride], pImag[4 * stride], twiddleStart + 4 * twiddleIncrement);
		phasors.Multiply(s4r, s4i, pReal[5 * stride], pImag[5 * stride], twiddleStart + 5 * twiddleIncrement);
		r11 = s2r - s3r;
		i11 = s2i - s3i;
		s5r = s2r + s3r;
		s5i = s2i + s3i;
		r10 = s1r - s4r;
		i10 = s1i - s4i;
		s6r = s1r + s4r;
		s6i = s1i + s4i;
		r20 = s6r - s5r;
		i20 = s6i - s5i;
		r22 = s5r - r14;
		i22 = s5i - i14;
		r19 = r14 + s5r + s6r;
		i19 = i14 + s5i + s6i;
		r21 = r14 - s6r;
		i21 = i14 - s6i;
	}
	r38 = valueT(0.055854267289647737622) * r21;
	i38 = valueT(0.055854267289647737622) * i21;
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i;
		phasors.Multiply(s1r, s1i, pReal[0 * stride], pImag[0 * stride], twiddleStart + 0 * twiddleIncrement);
		s2r = valueT(0.79015646852540019719) * r20;
		s2i = valueT(0.79015646852540019719) * i20;
		s3r = valueT(-0.73430220123575245957) * r22;
		s3i = valueT(-0.73430220123575245957) * i22;
		s4r = r19 + s1r;
		s4i = i19 + s1i;
		s5r = valueT(-1.1666666666666666667) * r19;
		s5i = valueT(-1.1666666666666666667) * i19;
		pReal[0 * stride] = s4r;
		pImag[0 * stride] = s4i;
		s6r = s4r + s5r;
		s6i = s4i + s5i;
		r55 = s2r + s6r - s3r;
		i55 = s2i + s6i - s3i;
		r54 = r38 + s2r - s6r;
		i54 = i38 + s2i - s6i;
		r53 = r38 + s3r + s6r;
		i53 = i38 + s3i + s6i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		valueT s11r, s11i;
		s1r = r11 + r10;
		s1i = i11 + i10;
		s2r = r9 + r10 - r11;
		s2i = i9 + i10 - i11;
		s3r = r9 - r10;
		s3i = i9 - i10;
		s4r = valueT(-1.4088116512993817275) * s1i;
		s4i = valueT(1.4088116512993817275) * s1r;
		s5r = valueT(-0.44095855184409843175) * s2i;
		s5i = valueT(0.44095855184409843175) * s2r;
		s6r = s1r - s3r;
		s6i = s1i - s3i;
		s7r = valueT(1.2157152215855879292) * s3i;
		s7i = valueT(-1.2157152215855879292) * s3r;
		s8r = valueT(0.87484229096165655223) * s6i;
		s8i = valueT(-0.87484229096165655223) * s6r;
		s9r = s4r + s8r;
		s9i = s4i + s8i;
		s10r = s7r + s8r;
		s10i = s7i + s8i;
		r52 = s9r - s5r;
		i52 = s9i - s5i;
		s11r = s5r - s10r;
		s11i = s5i - s10i;
		r50 = s5r + s9r + s10r;
		i50 = s5i + s9i + s10i;
		pReal[6 * stride] = r53 - s11r;
		pImag[6 * stride] = i53 - s11i;
		pReal[1 * stride] = r53 + s11r;
		pImag[1 * stride] = i53 + s11i;
	}
	pReal[5 * stride] = -r54 - r50;
	pImag[5 * stride] = -i54 - i50;
	pReal[2 * stride] = r50 - r54;
	pImag[2 * stride] = i50 - i54;
	pReal[4 * stride] = r55 - r52;
	pImag[4 * stride] = i55 - i52;
	pReal[3 * stride] = r55 + r52;
	pImag[3 * stride] = i55 + i52;
}

template<> void StandardModule<float, 7>::Compute(float *pReal, float *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

template<> void StandardModule<double, 7>::Compute(double *pReal, double *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

}
}
