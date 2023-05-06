
//          Copyright Christian Volmer 2022, 2023.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include "../standard_module.h"

namespace offt {
namespace backend {

/*
	Number of additions       : 172
	Number of multiplications : 32
*/

template<> StandardModuleComplexity const StandardModule<float, 14>::Complexity = { 172, 32 };
template<> StandardModuleComplexity const StandardModule<double, 14>::Complexity = { 172, 32 };

template<typename valueT>
static void ComputeCore(valueT *pReal, valueT *pImag, ptrdiff_t stride, valueT const *twiddles)
{
	valueT t0, t1, t2, t3, t4, t5, t6, t7, t8, t9;
	valueT t10, t11, t12, t13, t14, t15, t16, t17, t18, t19;
	valueT t20, t21, t22, t23, t24, t25, t26, t27, t28, t29;
	valueT t30, t31, t32, t33, t34, t35, t36, t37, t38, t39;

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
	ModuleBase<valueT>::ComplexMultiply(t20, t21, pReal[10 * stride], pImag[10 * stride], twiddles[20], twiddles[21]);
	ModuleBase<valueT>::ComplexMultiply(t22, t23, pReal[11 * stride], pImag[11 * stride], twiddles[22], twiddles[23]);
	ModuleBase<valueT>::ComplexMultiply(t24, t25, pReal[12 * stride], pImag[12 * stride], twiddles[24], twiddles[25]);
	ModuleBase<valueT>::ComplexMultiply(t26, t27, pReal[13 * stride], pImag[13 * stride], twiddles[26], twiddles[27]);

	t28 = t2 - t26;
	t29 = t3 - t27;
	t2 += t26;
	t3 += t27;
	t26 = t4 - t24;
	t27 = t5 - t25;
	t4 += t24;
	t5 += t25;
	t24 = t6 - t22;
	t25 = t7 - t23;
	t6 += t22;
	t7 += t23;
	t22 = t8 - t20;
	t23 = t9 - t21;
	t8 += t20;
	t9 += t21;
	t20 = t10 - t18;
	t21 = t11 - t19;
	t10 += t18;
	t11 += t19;
	t18 = t12 - t16;
	t19 = t13 - t17;
	t12 += t16;
	t13 += t17;
	t16 = t28 + t24;
	t17 = t29 + t25;
	t28 -= t24 + t20;
	t29 -= t25 + t21;
	t30 = t2 - t6;
	t31 = t3 - t7;
	t32 = t2 + t6 + t10;
	t33 = t3 + t7 + t11;
	t2 -= t10;
	t3 -= t11;
	t34 = t26 - t22;
	t35 = t27 - t23;
	t26 += t22 - t18;
	t27 += t23 - t19;
	t36 = t4 - t8;
	t37 = t5 - t9;
	t38 = t4 + t8 + t12;
	t39 = t5 + t9 + t13;
	t4 -= t12;
	t5 -= t13;
	t24 -= t20;
	t25 -= t21;
	t6 -= t10;
	t7 -= t11;
	t22 += t18;
	t23 += t19;
	t8 -= t12;
	t9 -= t13;
	t0 += t38;
	t1 += t39;
	t10 = t16 + t24;
	t11 = t17 + t25;
	t14 = t32 + t14;
	t15 = t33 + t15;
	t12 = t34 - t22;
	t13 = t35 - t23;
	t17 *= valueT(1.4088116512993817275);
	t16 *= valueT(1.4088116512993817275);
	t11 *= valueT(0.87484229096165655223);
	t10 *= valueT(0.87484229096165655223);
	t29 *= valueT(0.44095855184409843175);
	t28 *= valueT(0.44095855184409843175);
	t30 *= valueT(0.79015646852540019719);
	t31 *= valueT(0.79015646852540019719);
	t32 *= valueT(1.1666666666666666667);
	t33 *= valueT(1.1666666666666666667);
	t2 *= valueT(0.73430220123575245957);
	t3 *= valueT(0.73430220123575245957);
	t35 *= valueT(1.2157152215855879292);
	t34 *= valueT(1.2157152215855879292);
	t13 *= valueT(0.87484229096165655223);
	t12 *= valueT(0.87484229096165655223);
	t27 *= valueT(0.44095855184409843175);
	t26 *= valueT(0.44095855184409843175);
	t36 *= valueT(0.055854267289647737622);
	t37 *= valueT(0.055854267289647737622);
	t38 *= valueT(1.1666666666666666667);
	t39 *= valueT(1.1666666666666666667);
	t4 *= valueT(0.73430220123575245957);
	t5 *= valueT(0.73430220123575245957);
	t25 *= valueT(1.2157152215855879292);
	t24 *= valueT(1.2157152215855879292);
	t6 *= valueT(0.055854267289647737622);
	t7 *= valueT(0.055854267289647737622);
	t23 *= valueT(1.4088116512993817275);
	t22 *= valueT(1.4088116512993817275);
	t8 *= valueT(0.79015646852540019719);
	t9 *= valueT(0.79015646852540019719);
	t38 = t0 - t38;
	t39 = t1 - t39;
	t17 -= t11;
	t16 -= t10;
	t11 -= t25;
	t10 -= t24;
	t32 -= t14;
	t33 -= t15;
	t35 -= t13;
	t34 -= t12;
	t13 += t23;
	t12 += t22;
	t18 = t38 + t36 + t4;
	t19 = t39 + t37 + t5;
	t36 = t38 - t36 - t8;
	t37 = t39 - t37 - t9;
	t38 -= t4 - t8;
	t39 -= t5 - t9;
	t4 = t17 - t11 - t29;
	t5 = t16 - t10 - t28;
	t17 += t29;
	t16 += t28;
	t11 -= t29;
	t10 -= t28;
	t8 = t30 + t32 - t2;
	t9 = t31 + t33 - t3;
	t30 -= t32 - t6;
	t31 -= t33 - t7;
	t32 += t2 + t6;
	t33 += t3 + t7;
	t2 = t35 - t13 - t27;
	t3 = t34 - t12 - t26;
	t35 += t27;
	t34 += t26;
	t13 -= t27;
	t12 -= t26;
	t6 = t18 - t35;
	t7 = t19 + t34;
	t18 += t35;
	t19 -= t34;
	t20 = t36 + t2;
	t21 = t37 - t3;
	t36 -= t2;
	t37 += t3;
	t2 = t38 - t13;
	t3 = t39 + t12;
	t38 += t13;
	t39 -= t12;
	t12 = t4 + t30;
	t13 = t5 - t31;
	t4 -= t30;
	t5 += t31;
	t22 = t17 - t8;
	t23 = t16 + t9;
	t17 += t8;
	t16 -= t9;
	t8 = t11 - t32;
	t9 = t10 + t33;
	t11 += t32;
	t10 -= t33;
	pReal[0 * stride] = t0 + t14;
	pImag[0 * stride] = t1 + t15;
	pReal[1 * stride] = t6 - t8;
	pImag[1 * stride] = t7 + t9;
	pReal[2 * stride] = t20 + t12;
	pImag[2 * stride] = t21 - t13;
	pReal[3 * stride] = t2 - t22;
	pImag[3 * stride] = t3 + t23;
	pReal[4 * stride] = t38 - t17;
	pImag[4 * stride] = t39 + t16;
	pReal[5 * stride] = t36 + t4;
	pImag[5 * stride] = t37 - t5;
	pReal[6 * stride] = t18 - t11;
	pImag[6 * stride] = t19 + t10;
	pReal[7 * stride] = t0 - t14;
	pImag[7 * stride] = t1 - t15;
	pReal[8 * stride] = t6 + t8;
	pImag[8 * stride] = t7 - t9;
	pReal[9 * stride] = t20 - t12;
	pImag[9 * stride] = t21 + t13;
	pReal[10 * stride] = t2 + t22;
	pImag[10 * stride] = t3 - t23;
	pReal[11 * stride] = t38 + t17;
	pImag[11 * stride] = t39 - t16;
	pReal[12 * stride] = t36 - t4;
	pImag[12 * stride] = t37 + t5;
	pReal[13 * stride] = t18 + t11;
	pImag[13 * stride] = t19 - t10;
}

template<> void StandardModule<float, 14>::Compute(float *pReal, float *pImag, ptrdiff_t stride, float const *twiddles) const
{
	ComputeCore(pReal, pImag, stride, twiddles);
}

template<> void StandardModule<double, 14>::Compute(double *pReal, double *pImag, ptrdiff_t stride, double const *twiddles) const
{
	ComputeCore(pReal, pImag, stride, twiddles);
}

}
}
