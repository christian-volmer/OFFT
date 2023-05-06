
//          Copyright Christian Volmer 2022, 2023.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include "../standard_module.h"

namespace offt {
namespace backend {

/*
	Number of additions       : 144
	Number of multiplications : 24
*/

template<> StandardModuleComplexity const StandardModule<float, 16>::Complexity = { 144, 24 };
template<> StandardModuleComplexity const StandardModule<double, 16>::Complexity = { 144, 24 };

template<typename valueT>
static void ComputeCore(valueT *pReal, valueT *pImag, ptrdiff_t stride, valueT const *twiddles)
{
	valueT t0, t1, t2, t3, t4, t5, t6, t7, t8, t9;
	valueT t10, t11, t12, t13, t14, t15, t16, t17, t18, t19;
	valueT t20, t21, t22, t23, t24, t25, t26, t27, t28, t29;
	valueT t30, t31, t32, t33;

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
	ModuleBase<valueT>::ComplexMultiply(t28, t29, pReal[14 * stride], pImag[14 * stride], twiddles[28], twiddles[29]);
	ModuleBase<valueT>::ComplexMultiply(t30, t31, pReal[15 * stride], pImag[15 * stride], twiddles[30], twiddles[31]);

	t32 = t0 - t16;
	t33 = t1 - t17;
	t0 += t16;
	t1 += t17;
	t16 = t8 - t24;
	t17 = t9 - t25;
	t8 += t24;
	t9 += t25;
	t24 = t32 + t17;
	t25 = t33 - t16;
	t32 -= t17;
	t33 += t16;
	t16 = t0 - t8;
	t17 = t1 - t9;
	t0 += t8;
	t1 += t9;
	t8 = t2 - t18;
	t9 = t3 - t19;
	t2 += t18;
	t3 += t19;
	t18 = t4 - t20;
	t19 = t5 - t21;
	t4 += t20;
	t5 += t21;
	t20 = t6 - t22;
	t21 = t7 - t23;
	t6 += t22;
	t7 += t23;
	t22 = t10 - t26;
	t23 = t11 - t27;
	t10 += t26;
	t11 += t27;
	t26 = t12 - t28;
	t27 = t13 - t29;
	t12 += t28;
	t13 += t29;
	t28 = t14 - t30;
	t29 = t15 - t31;
	t14 += t30;
	t15 += t31;
	t30 = valueT(0.7071067811865475244) * (t18 - t19);
	t18 = valueT(0.7071067811865475244) * (t18 + t19);
	t19 = valueT(0.7071067811865475244) * (t26 + t27);
	t26 = valueT(0.7071067811865475244) * (t26 - t27);
	t27 = t8 + t23;
	t31 = t9 - t22;
	t8 -= t23;
	t9 += t22;
	t22 = t2 - t10;
	t23 = t3 - t11;
	t2 += t10;
	t3 += t11;
	t10 = t30 + t19;
	t11 = t18 - t26;
	t30 -= t19;
	t18 += t26;
	t19 = t4 - t12;
	t26 = t5 - t13;
	t4 += t12;
	t5 += t13;
	t12 = t20 + t29;
	t13 = t21 - t28;
	t20 -= t29;
	t21 += t28;
	t28 = t6 - t14;
	t29 = t7 - t15;
	t6 += t14;
	t7 += t15;
	t14 = t24 + t11;
	t15 = t25 - t10;
	t24 -= t11;
	t25 += t10;
	t10 = t32 - t30;
	t11 = t33 - t18;
	t32 += t30;
	t33 += t18;
	t18 = t16 + t26;
	t30 = t17 - t19;
	t16 -= t26;
	t17 += t19;
	t19 = t0 - t4;
	t26 = t1 - t5;
	t0 += t4;
	t1 += t5;
	t4 = valueT(0.38268343236508977173) * t27 - valueT(0.92387953251128675613) * t31;
	t27 = valueT(0.92387953251128675613) * t27 + valueT(0.38268343236508977173) * t31;
	t5 = valueT(0.92387953251128675613) * t8 - valueT(0.38268343236508977173) * t9;
	t8 = valueT(0.38268343236508977173) * t8 + valueT(0.92387953251128675613) * t9;
	t9 = valueT(0.7071067811865475244) * (t22 - t23);
	t22 = valueT(0.7071067811865475244) * (t22 + t23);
	t23 = valueT(0.92387953251128675613) * t12 - valueT(0.38268343236508977173) * t13;
	t12 = valueT(0.38268343236508977173) * t12 + valueT(0.92387953251128675613) * t13;
	t13 = valueT(0.38268343236508977173) * t20 - valueT(0.92387953251128675613) * t21;
	t20 = valueT(0.92387953251128675613) * t20 + valueT(0.38268343236508977173) * t21;
	t21 = valueT(0.7071067811865475244) * (t28 + t29);
	t28 = valueT(0.7071067811865475244) * (t28 - t29);
	t29 = t4 + t23;
	t31 = t27 + t12;
	t4 -= t23;
	t27 -= t12;
	t12 = t5 - t13;
	t23 = t8 - t20;
	t5 += t13;
	t8 += t20;
	t13 = t9 + t21;
	t20 = t22 - t28;
	t9 -= t21;
	t22 += t28;
	t21 = t2 - t6;
	t28 = t3 - t7;
	t2 += t6;
	t3 += t7;
	pReal[0 * stride] = t0 + t2;
	pImag[0 * stride] = t1 + t3;
	pReal[1 * stride] = t32 + t5;
	pImag[1 * stride] = t33 + t8;
	pReal[2 * stride] = t16 + t9;
	pImag[2 * stride] = t17 + t22;
	pReal[3 * stride] = t24 + t4;
	pImag[3 * stride] = t25 + t27;
	pReal[4 * stride] = t19 - t28;
	pImag[4 * stride] = t26 + t21;
	pReal[5 * stride] = t10 - t23;
	pImag[5 * stride] = t11 + t12;
	pReal[6 * stride] = t18 - t20;
	pImag[6 * stride] = t30 + t13;
	pReal[7 * stride] = t14 - t31;
	pImag[7 * stride] = t15 + t29;
	pReal[8 * stride] = t0 - t2;
	pImag[8 * stride] = t1 - t3;
	pReal[9 * stride] = t32 - t5;
	pImag[9 * stride] = t33 - t8;
	pReal[10 * stride] = t16 - t9;
	pImag[10 * stride] = t17 - t22;
	pReal[11 * stride] = t24 - t4;
	pImag[11 * stride] = t25 - t27;
	pReal[12 * stride] = t19 + t28;
	pImag[12 * stride] = t26 - t21;
	pReal[13 * stride] = t10 + t23;
	pImag[13 * stride] = t11 - t12;
	pReal[14 * stride] = t18 + t20;
	pImag[14 * stride] = t30 - t13;
	pReal[15 * stride] = t14 + t31;
	pImag[15 * stride] = t15 - t29;
}

template<> void StandardModule<float, 16>::Compute(float *pReal, float *pImag, ptrdiff_t stride, float const *twiddles) const
{
	ComputeCore(pReal, pImag, stride, twiddles);
}

template<> void StandardModule<double, 16>::Compute(double *pReal, double *pImag, ptrdiff_t stride, double const *twiddles) const
{
	ComputeCore(pReal, pImag, stride, twiddles);
}

}
}
