
//          Copyright Christian Volmer 2022, 2023.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include "../standard_module.h"

namespace offt {
namespace backend {

/*
	Number of additions       : 52
	Number of multiplications : 4
*/

template<> StandardModuleComplexity const StandardModule<float, 8>::Complexity = { 52, 4 };
template<> StandardModuleComplexity const StandardModule<double, 8>::Complexity = { 52, 4 };

template<typename valueT>
static void ComputeCore(Phasors<valueT> const &phasors, valueT *pReal, valueT *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement)
{
	valueT t0, t1, t2, t3, t4, t5, t6, t7, t8, t9;
	valueT t10, t11, t12, t13, t14, t15, t16, t17;

	phasors.Multiply(t0, t1, pReal[0 * stride], pImag[0 * stride], twiddleStart + 0 * twiddleIncrement);
	phasors.Multiply(t2, t3, pReal[1 * stride], pImag[1 * stride], twiddleStart + 1 * twiddleIncrement);
	phasors.Multiply(t4, t5, pReal[2 * stride], pImag[2 * stride], twiddleStart + 2 * twiddleIncrement);
	phasors.Multiply(t6, t7, pReal[3 * stride], pImag[3 * stride], twiddleStart + 3 * twiddleIncrement);
	phasors.Multiply(t8, t9, pReal[4 * stride], pImag[4 * stride], twiddleStart + 4 * twiddleIncrement);
	phasors.Multiply(t10, t11, pReal[5 * stride], pImag[5 * stride], twiddleStart + 5 * twiddleIncrement);
	phasors.Multiply(t12, t13, pReal[6 * stride], pImag[6 * stride], twiddleStart + 6 * twiddleIncrement);
	phasors.Multiply(t14, t15, pReal[7 * stride], pImag[7 * stride], twiddleStart + 7 * twiddleIncrement);

	t16 = t0 - t8;
	t17 = t1 - t9;
	t0 += t8;
	t1 += t9;
	t8 = t4 - t12;
	t9 = t5 - t13;
	t4 += t12;
	t5 += t13;
	t12 = t16 + t9;
	t13 = t17 - t8;
	t16 -= t9;
	t17 += t8;
	t8 = t0 - t4;
	t9 = t1 - t5;
	t0 += t4;
	t1 += t5;
	t4 = t2 - t10;
	t5 = t3 - t11;
	t2 += t10;
	t3 += t11;
	t10 = t6 - t14;
	t11 = t7 - t15;
	t6 += t14;
	t7 += t15;
	t14 = valueT(0.7071067811865475244) * (t4 - t5);
	t4 = valueT(0.7071067811865475244) * (t4 + t5);
	t5 = valueT(0.7071067811865475244) * (t10 + t11);
	t10 = valueT(0.7071067811865475244) * (t10 - t11);
	t11 = t14 + t5;
	t15 = t4 - t10;
	t14 -= t5;
	t4 += t10;
	t5 = t2 - t6;
	t10 = t3 - t7;
	t2 += t6;
	t3 += t7;
	pReal[0 * stride] = t0 + t2;
	pImag[0 * stride] = t1 + t3;
	pReal[1 * stride] = t16 + t14;
	pImag[1 * stride] = t17 + t4;
	pReal[2 * stride] = t8 - t10;
	pImag[2 * stride] = t9 + t5;
	pReal[3 * stride] = t12 - t15;
	pImag[3 * stride] = t13 + t11;
	pReal[4 * stride] = t0 - t2;
	pImag[4 * stride] = t1 - t3;
	pReal[5 * stride] = t16 - t14;
	pImag[5 * stride] = t17 - t4;
	pReal[6 * stride] = t8 + t10;
	pImag[6 * stride] = t9 - t5;
	pReal[7 * stride] = t12 + t15;
	pImag[7 * stride] = t13 - t11;
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
