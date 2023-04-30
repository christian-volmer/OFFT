
//          Copyright Christian Volmer 2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include "../standard_module.h"

namespace offt {
namespace backend {

using std::size_t;
using std::ptrdiff_t;

/*
	Number of additions       : 96
	Number of multiplications : 16
*/

template<> StandardModuleComplexity const StandardModule<float, 12>::Complexity = { 96, 16 };
template<> StandardModuleComplexity const StandardModule<double, 12>::Complexity = { 96, 16 };

template<typename valueT>
static void ComputeCore(Phasors<valueT> const &phasors, valueT *pReal, valueT *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement)
{
	valueT t0, t1, t2, t3, t4, t5, t6, t7, t8, t9;
	valueT t10, t11, t12, t13, t14, t15, t16, t17, t18, t19;
	valueT t20, t21, t22, t23, t24, t25;

	phasors.Multiply(t0, t1, pReal[0 * stride], pImag[0 * stride], twiddleStart + 0 * twiddleIncrement);
	phasors.Multiply(t2, t3, pReal[1 * stride], pImag[1 * stride], twiddleStart + 1 * twiddleIncrement);
	phasors.Multiply(t4, t5, pReal[2 * stride], pImag[2 * stride], twiddleStart + 2 * twiddleIncrement);
	phasors.Multiply(t6, t7, pReal[3 * stride], pImag[3 * stride], twiddleStart + 3 * twiddleIncrement);
	phasors.Multiply(t8, t9, pReal[4 * stride], pImag[4 * stride], twiddleStart + 4 * twiddleIncrement);
	phasors.Multiply(t10, t11, pReal[5 * stride], pImag[5 * stride], twiddleStart + 5 * twiddleIncrement);
	phasors.Multiply(t12, t13, pReal[6 * stride], pImag[6 * stride], twiddleStart + 6 * twiddleIncrement);
	phasors.Multiply(t14, t15, pReal[7 * stride], pImag[7 * stride], twiddleStart + 7 * twiddleIncrement);
	phasors.Multiply(t16, t17, pReal[8 * stride], pImag[8 * stride], twiddleStart + 8 * twiddleIncrement);
	phasors.Multiply(t18, t19, pReal[9 * stride], pImag[9 * stride], twiddleStart + 9 * twiddleIncrement);
	phasors.Multiply(t20, t21, pReal[10 * stride], pImag[10 * stride], twiddleStart + 10 * twiddleIncrement);
	phasors.Multiply(t22, t23, pReal[11 * stride], pImag[11 * stride], twiddleStart + 11 * twiddleIncrement);

	t24 = t2 - t10;
	t25 = t3 - t11;
	t2 += t10;
	t3 += t11;
	t10 = t4 - t20;
	t11 = t5 - t21;
	t4 += t20;
	t5 += t21;
	t20 = t8 - t16;
	t21 = t9 - t17;
	t8 += t16;
	t9 += t17;
	t16 = t14 - t22;
	t17 = t15 - t23;
	t14 += t22;
	t15 += t23;
	t0 += t8;
	t1 += t9;
	t18 = t2 + t18;
	t19 = t3 + t19;
	t12 = t4 + t12;
	t13 = t5 + t13;
	t6 += t14;
	t7 += t15;
	t22 = t0 - t12;
	t23 = t1 - t13;
	t0 += t12;
	t1 += t13;
	t12 = t24 - t16;
	t13 = t25 - t17;
	t24 += t16;
	t25 += t17;
	t16 = t2 - t14;
	t17 = t3 - t15;
	t2 += t14;
	t3 += t15;
	t14 = t18 - t6;
	t15 = t19 - t7;
	t18 += t6;
	t19 += t7;
	t6 = t10 - t20;
	t7 = t11 - t21;
	t10 += t20;
	t11 += t21;
	t20 = t4 - t8;
	t21 = t5 - t9;
	t4 += t8;
	t5 += t9;
	t12 *= valueT(0.86602540378443864676);
	t13 *= valueT(0.86602540378443864676);
	t25 *= valueT(0.86602540378443864676);
	t24 *= valueT(0.86602540378443864676);
	t17 *= valueT(1.5);
	t16 *= valueT(1.5);
	t2 *= valueT(1.5);
	t3 *= valueT(1.5);
	t7 *= valueT(0.86602540378443864676);
	t6 *= valueT(0.86602540378443864676);
	t11 *= valueT(0.86602540378443864676);
	t10 *= valueT(0.86602540378443864676);
	t20 *= valueT(1.5);
	t21 *= valueT(1.5);
	t4 *= valueT(1.5);
	t5 *= valueT(1.5);
	t20 = t22 + t20;
	t21 = t23 + t21;
	t4 = t0 - t4;
	t5 = t1 - t5;
	t17 -= t15;
	t16 -= t14;
	t2 -= t18;
	t3 -= t19;
	t8 = t20 + t11;
	t9 = t21 - t10;
	t20 -= t11;
	t21 += t10;
	t10 = t4 - t7;
	t11 = t5 + t6;
	t4 += t7;
	t5 -= t6;
	t6 = t12 + t17;
	t7 = t13 - t16;
	t12 -= t17;
	t13 += t16;
	t16 = t25 - t2;
	t17 = t24 + t3;
	t25 += t2;
	t24 -= t3;
	pReal[0 * stride] = t0 + t18;
	pImag[0 * stride] = t1 + t19;
	pReal[1 * stride] = t20 + t12;
	pImag[1 * stride] = t21 + t13;
	pReal[2 * stride] = t10 - t16;
	pImag[2 * stride] = t11 + t17;
	pReal[3 * stride] = t22 - t15;
	pImag[3 * stride] = t23 + t14;
	pReal[4 * stride] = t4 - t25;
	pImag[4 * stride] = t5 + t24;
	pReal[5 * stride] = t8 - t6;
	pImag[5 * stride] = t9 - t7;
	pReal[6 * stride] = t0 - t18;
	pImag[6 * stride] = t1 - t19;
	pReal[7 * stride] = t20 - t12;
	pImag[7 * stride] = t21 - t13;
	pReal[8 * stride] = t10 + t16;
	pImag[8 * stride] = t11 - t17;
	pReal[9 * stride] = t22 + t15;
	pImag[9 * stride] = t23 - t14;
	pReal[10 * stride] = t4 + t25;
	pImag[10 * stride] = t5 - t24;
	pReal[11 * stride] = t8 + t6;
	pImag[11 * stride] = t9 + t7;
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
