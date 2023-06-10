
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

template<> StandardModuleComplexity const StandardModule<float, 5>::Complexity = { 0, 0 };
template<> StandardModuleComplexity const StandardModule<double, 5>::Complexity = { 0, 0 };

template<typename valueT>
static void ComputeCore(Phasors<valueT> const &phasors, valueT *pReal, valueT *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement)
{
	valueT r5, i5, r7, i7, r10, i10, r8, i8, r14, i14;
	valueT r15, i15, r17, i17, r27, i27, r33, i33, r38, i38;
	valueT r39, i39, r37, i37;

	phasors.Multiply(r5, i5, pReal[4 * stride], pImag[4 * stride], twiddleStart + 4 * twiddleIncrement);
	{
		valueT s1r, s1i;
		phasors.Multiply(s1r, s1i, pReal[1 * stride], pImag[1 * stride], twiddleStart + 1 * twiddleIncrement);
		r7 = s1r - r5;
		i7 = s1i - i5;
		r10 = r5 + s1r;
		i10 = i5 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i;
		phasors.Multiply(s1r, s1i, pReal[2 * stride], pImag[2 * stride], twiddleStart + 2 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[3 * stride], pImag[3 * stride], twiddleStart + 3 * twiddleIncrement);
		r8 = s1r - s2r;
		i8 = s1i - s2i;
		s3r = s1r + s2r;
		s3i = s1i + s2i;
		r14 = s3r - r10;
		i14 = s3i - i10;
		r15 = r10 + s3r;
		i15 = i10 + s3i;
	}
	{
		valueT s1r, s1i;
		phasors.Multiply(s1r, s1i, pReal[0 * stride], pImag[0 * stride], twiddleStart + 0 * twiddleIncrement);
		r17 = r15 + s1r;
		i17 = i15 + s1i;
		r27 = valueT(-1.25) * r15;
		i27 = valueT(-1.25) * i15;
	}
	pReal[0 * stride] = r17;
	pImag[0 * stride] = i17;
	r33 = r17 + r27;
	i33 = i17 + i27;
	{
		valueT s1r, s1i;
		s1r = valueT(-0.5590169943749474241) * r14;
		s1i = valueT(-0.5590169943749474241) * i14;
		r38 = s1r - r33;
		i38 = s1i - i33;
		r39 = r33 + s1r;
		i39 = i33 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		s1r = valueT(0.36327126400268044295) * i8;
		s1i = valueT(-0.36327126400268044295) * r8;
		s2r = r7 - r8;
		s2i = i7 - i8;
		s3r = valueT(-1.5388417685876267013) * i7;
		s3i = valueT(1.5388417685876267013) * r7;
		s4r = valueT(0.58778525229247312917) * s2i;
		s4i = valueT(-0.58778525229247312917) * s2r;
		r37 = s1r - s4r;
		i37 = s1i - s4i;
		s5r = s3r + s4r;
		s5i = s3i + s4i;
		pReal[4 * stride] = r39 - s5r;
		pImag[4 * stride] = i39 - s5i;
		pReal[1 * stride] = r39 + s5r;
		pImag[1 * stride] = i39 + s5i;
	}
	pReal[3 * stride] = -r38 - r37;
	pImag[3 * stride] = -i38 - i37;
	pReal[2 * stride] = r37 - r38;
	pImag[2 * stride] = i37 - i38;
}

template<> void StandardModule<float, 5>::Compute(float *pReal, float *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

template<> void StandardModule<double, 5>::Compute(double *pReal, double *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

}
}
