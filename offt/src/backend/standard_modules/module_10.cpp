
//          Copyright Christian Volmer 2022, 2023.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include "../standard_module.h"

namespace offt {
namespace backend {

/*
	Number of additions       : 88
	Number of multiplications : 20
*/

template<> StandardModuleComplexity const StandardModule<float, 10>::Complexity = { 88, 20 };
template<> StandardModuleComplexity const StandardModule<double, 10>::Complexity = { 88, 20 };

template<typename valueT>
static void ComputeCore(valueT *pReal, valueT *pImag, ptrdiff_t stride, valueT const *twiddles)
{
	valueT t0, t1, t2, t3, t4, t5, t6, t7, t8, t9;
	valueT t10, t11, t12, t13, t14, t15, t16, t17, t18, t19;
	valueT t20, t21, t22, t23, t24, t25;

	ModuleBase<valueT>::ComplexMultiply(t0, t1, pReal[0 * stride], pImag[0 * stride], twiddles[0], twiddles[1]);
	ModuleBase<valueT>::ComplexMultiply(t2, t3, pReal[1 * stride], pImag[1 * stride], twiddles[2], twiddles[3]);
	ModuleBase<valueT>::ComplexMultiply(t4, t5, pReal[2 * stride], pImag[2 * stride], twiddles[4], twiddles[5]);
	ModuleBase<valueT>::ComplexMultiply(t6, t7, pReal[3 * stride], pImag[3 * stride], twiddles[6], twiddles[7]);
	ModuleBase<valueT>::ComplexMultiply(t8, t9, pReal[4 * stride], pImag[4 * stride], twiddles[8], twiddles[9]);
	ModuleBase<valueT>::ComplexMultiply(t10, t11, pReal[5 * stride], pImag[5 * stride], twiddles[10], twiddles[11]);
	ModuleBase<valueT>::ComplexMultiply(t12, t13, pReal[6 * stride], pImag[6 * stride], twiddles[12], twiddles[13]);
	ModuleBase<valueT>::ComplexMultiply(t14, t15, pReal[7 * stride], pImag[7 * stride], twiddles[14], twiddles[15]);
	ModuleBase<valueT>::ComplexMultiply(t16, t17, pReal[8 * stride], pImag[8 * stride], twiddles[16], twiddles[17]);
	ModuleBase<valueT>::ComplexMultiply(t18, t19, pReal[9 * stride], pImag[9 * stride], twiddles[18], twiddles[19]);

	t20 = t2 - t18;
	t21 = t3 - t19;
	t2 += t18;
	t3 += t19;
	t18 = t4 - t16;
	t19 = t5 - t17;
	t4 += t16;
	t5 += t17;
	t16 = t6 - t14;
	t17 = t7 - t15;
	t6 += t14;
	t7 += t15;
	t14 = t8 - t12;
	t15 = t9 - t13;
	t8 += t12;
	t9 += t13;
	t12 = t20 - t16;
	t13 = t21 - t17;
	t22 = t2 - t6;
	t23 = t3 - t7;
	t2 += t6;
	t3 += t7;
	t6 = t18 - t14;
	t7 = t19 - t15;
	t24 = t4 - t8;
	t25 = t5 - t9;
	t4 += t8;
	t5 += t9;
	t0 += t4;
	t1 += t5;
	t10 = t2 + t10;
	t11 = t3 + t11;
	t21 *= valueT(0.36327126400268044295);
	t20 *= valueT(0.36327126400268044295);
	t13 *= valueT(0.58778525229247312917);
	t12 *= valueT(0.58778525229247312917);
	t22 *= valueT(0.5590169943749474241);
	t23 *= valueT(0.5590169943749474241);
	t2 *= valueT(1.25);
	t3 *= valueT(1.25);
	t19 *= valueT(1.5388417685876267013);
	t18 *= valueT(1.5388417685876267013);
	t7 *= valueT(0.58778525229247312917);
	t6 *= valueT(0.58778525229247312917);
	t24 *= valueT(0.5590169943749474241);
	t25 *= valueT(0.5590169943749474241);
	t4 *= valueT(1.25);
	t5 *= valueT(1.25);
	t17 *= valueT(1.5388417685876267013);
	t16 *= valueT(1.5388417685876267013);
	t15 *= valueT(0.36327126400268044295);
	t14 *= valueT(0.36327126400268044295);
	t4 = t0 - t4;
	t5 = t1 - t5;
	t2 -= t10;
	t3 -= t11;
	t8 = t4 - t24;
	t9 = t5 - t25;
	t4 += t24;
	t5 += t25;
	t21 += t13;
	t20 += t12;
	t13 += t17;
	t12 += t16;
	t16 = t22 - t2;
	t17 = t23 - t3;
	t22 += t2;
	t23 += t3;
	t19 -= t7;
	t18 -= t6;
	t7 -= t15;
	t6 -= t14;
	t2 = t8 + t7;
	t3 = t9 - t6;
	t8 -= t7;
	t9 += t6;
	t6 = t4 + t19;
	t7 = t5 - t18;
	t4 -= t19;
	t5 += t18;
	t14 = t21 + t16;
	t15 = t20 - t17;
	t21 -= t16;
	t20 += t17;
	t16 = t13 + t22;
	t17 = t12 - t23;
	t13 -= t22;
	t12 += t23;
	pReal[0 * stride] = t0 + t10;
	pImag[0 * stride] = t1 + t11;
	pReal[1 * stride] = t4 - t13;
	pImag[1 * stride] = t5 + t12;
	pReal[2 * stride] = t8 - t21;
	pImag[2 * stride] = t9 + t20;
	pReal[3 * stride] = t2 - t14;
	pImag[3 * stride] = t3 + t15;
	pReal[4 * stride] = t6 - t16;
	pImag[4 * stride] = t7 + t17;
	pReal[5 * stride] = t0 - t10;
	pImag[5 * stride] = t1 - t11;
	pReal[6 * stride] = t4 + t13;
	pImag[6 * stride] = t5 - t12;
	pReal[7 * stride] = t8 + t21;
	pImag[7 * stride] = t9 - t20;
	pReal[8 * stride] = t2 + t14;
	pImag[8 * stride] = t3 - t15;
	pReal[9 * stride] = t6 + t16;
	pImag[9 * stride] = t7 - t17;
}

template<> void StandardModule<float, 10>::Compute(float *pReal, float *pImag, ptrdiff_t stride, float const *twiddles) const
{
	ComputeCore(pReal, pImag, stride, twiddles);
}

template<> void StandardModule<double, 10>::Compute(double *pReal, double *pImag, ptrdiff_t stride, double const *twiddles) const
{
	ComputeCore(pReal, pImag, stride, twiddles);
}

}
}
