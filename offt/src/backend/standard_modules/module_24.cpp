
//          Copyright Christian Volmer 2022, 2023.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include "../standard_module.h"

namespace offt {
namespace backend {

/*
	Number of additions       : 252
	Number of multiplications : 36
*/

template<> StandardModuleComplexity const StandardModule<float, 24>::Complexity = { 252, 36 };
template<> StandardModuleComplexity const StandardModule<double, 24>::Complexity = { 252, 36 };

template<typename valueT>
static void ComputeCore(valueT *pReal, valueT *pImag, ptrdiff_t stride, valueT const *twiddles)
{
	valueT t0, t1, t2, t3, t4, t5, t6, t7, t8, t9;
	valueT t10, t11, t12, t13, t14, t15, t16, t17, t18, t19;
	valueT t20, t21, t22, t23, t24, t25, t26, t27, t28, t29;
	valueT t30, t31, t32, t33, t34, t35, t36, t37, t38, t39;
	valueT t40, t41, t42, t43, t44, t45, t46, t47, t48, t49;

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
	ModuleBase<valueT>::ComplexMultiply(t32, t33, pReal[16 * stride], pImag[16 * stride], twiddles[32], twiddles[33]);
	ModuleBase<valueT>::ComplexMultiply(t34, t35, pReal[17 * stride], pImag[17 * stride], twiddles[34], twiddles[35]);
	ModuleBase<valueT>::ComplexMultiply(t36, t37, pReal[18 * stride], pImag[18 * stride], twiddles[36], twiddles[37]);
	ModuleBase<valueT>::ComplexMultiply(t38, t39, pReal[19 * stride], pImag[19 * stride], twiddles[38], twiddles[39]);
	ModuleBase<valueT>::ComplexMultiply(t40, t41, pReal[20 * stride], pImag[20 * stride], twiddles[40], twiddles[41]);
	ModuleBase<valueT>::ComplexMultiply(t42, t43, pReal[21 * stride], pImag[21 * stride], twiddles[42], twiddles[43]);
	ModuleBase<valueT>::ComplexMultiply(t44, t45, pReal[22 * stride], pImag[22 * stride], twiddles[44], twiddles[45]);
	ModuleBase<valueT>::ComplexMultiply(t46, t47, pReal[23 * stride], pImag[23 * stride], twiddles[46], twiddles[47]);

	t48 = t2 - t34;
	t49 = t3 - t35;
	t2 += t34;
	t3 += t35;
	t34 = t4 - t20;
	t35 = t5 - t21;
	t4 += t20;
	t5 += t21;
	t20 = t8 - t40;
	t21 = t9 - t41;
	t8 += t40;
	t9 += t41;
	t40 = t10 - t26;
	t41 = t11 - t27;
	t10 += t26;
	t11 += t27;
	t26 = t14 - t46;
	t27 = t15 - t47;
	t14 += t46;
	t15 += t47;
	t46 = t16 - t32;
	t47 = t17 - t33;
	t16 += t32;
	t17 += t33;
	t32 = t22 - t38;
	t33 = t23 - t39;
	t22 += t38;
	t23 += t39;
	t38 = t28 - t44;
	t39 = t29 - t45;
	t28 += t44;
	t29 += t45;
	t0 += t16;
	t1 += t17;
	t18 = t2 + t18;
	t19 = t3 + t19;
	t36 = t4 + t36;
	t37 = t5 + t37;
	t6 += t22;
	t7 += t23;
	t24 = t8 + t24;
	t25 = t9 + t25;
	t42 = t10 + t42;
	t43 = t11 + t43;
	t12 += t28;
	t13 += t29;
	t30 = t14 + t30;
	t31 = t15 + t31;
	t44 = t0 - t24;
	t45 = t1 - t25;
	t0 += t24;
	t1 += t25;
	t24 = t34 - t38;
	t25 = t35 - t39;
	t34 += t38;
	t35 += t39;
	t38 = t4 - t28;
	t39 = t5 - t29;
	t4 += t28;
	t5 += t29;
	t28 = t36 - t12;
	t29 = t37 - t13;
	t36 += t12;
	t37 += t13;
	t12 = t20 - t46;
	t13 = t21 - t47;
	t20 += t46;
	t21 += t47;
	t46 = t8 - t16;
	t47 = t9 - t17;
	t8 += t16;
	t9 += t17;
	t16 = t44 - t29;
	t17 = t45 + t28;
	t44 += t29;
	t45 -= t28;
	t28 = t0 - t36;
	t29 = t1 - t37;
	t0 += t36;
	t1 += t37;
	t36 = t48 + t40;
	t37 = t49 + t41;
	t48 -= t40;
	t49 -= t41;
	t40 = t2 - t10;
	t41 = t3 - t11;
	t2 += t10;
	t3 += t11;
	t10 = t18 - t42;
	t11 = t19 - t43;
	t18 += t42;
	t19 += t43;
	t42 = t25 - t20;
	t43 = t24 + t21;
	t25 += t20;
	t24 -= t21;
	t20 = t34 + t12;
	t21 = t35 + t13;
	t34 -= t12;
	t35 -= t13;
	t12 = t39 + t46;
	t13 = t38 - t47;
	t39 -= t46;
	t38 += t47;
	t46 = t4 - t8;
	t47 = t5 - t9;
	t4 += t8;
	t5 += t9;
	t8 = t6 - t30;
	t9 = t7 - t31;
	t6 += t30;
	t7 += t31;
	t30 = t26 + t32;
	t31 = t27 + t33;
	t26 -= t32;
	t27 -= t33;
	t32 = t14 - t22;
	t33 = t15 - t23;
	t14 += t22;
	t15 += t23;
	t22 = valueT(0.61237243569579452455) * (t36 - t37);
	t36 = valueT(0.61237243569579452455) * (t36 + t37);
	t49 *= valueT(0.86602540378443864676);
	t48 *= valueT(0.86602540378443864676);
	t23 = valueT(1.0606601717798212866) * (t40 + t41);
	t40 = valueT(1.0606601717798212866) * (t40 - t41);
	t2 *= valueT(1.5);
	t3 *= valueT(1.5);
	t37 = valueT(0.7071067811865475244) * (t10 + t11);
	t10 = valueT(0.7071067811865475244) * (t10 - t11);
	t43 *= valueT(0.86602540378443864676);
	t42 *= valueT(0.86602540378443864676);
	t24 *= valueT(0.86602540378443864676);
	t25 *= valueT(0.86602540378443864676);
	t21 *= valueT(0.86602540378443864676);
	t20 *= valueT(0.86602540378443864676);
	t35 *= valueT(0.86602540378443864676);
	t34 *= valueT(0.86602540378443864676);
	t12 *= valueT(1.5);
	t13 *= valueT(1.5);
	t39 *= valueT(1.5);
	t38 *= valueT(1.5);
	t46 *= valueT(1.5);
	t47 *= valueT(1.5);
	t4 *= valueT(1.5);
	t5 *= valueT(1.5);
	t11 = valueT(0.7071067811865475244) * (t8 - t9);
	t8 = valueT(0.7071067811865475244) * (t8 + t9);
	t9 = valueT(0.61237243569579452455) * (t30 + t31);
	t30 = valueT(0.61237243569579452455) * (t30 - t31);
	t27 *= valueT(0.86602540378443864676);
	t26 *= valueT(0.86602540378443864676);
	t31 = valueT(1.0606601717798212866) * (t32 - t33);
	t32 = valueT(1.0606601717798212866) * (t32 + t33);
	t14 *= valueT(1.5);
	t15 *= valueT(1.5);
	t12 = t16 + t12;
	t13 = t17 - t13;
	t39 = t44 - t39;
	t38 = t45 + t38;
	t46 = t28 + t46;
	t47 = t29 + t47;
	t4 = t0 - t4;
	t5 = t1 - t5;
	t23 -= t37;
	t40 -= t10;
	t2 -= t18;
	t3 -= t19;
	t31 = t11 + t31;
	t32 = t8 + t32;
	t14 = t6 - t14;
	t15 = t7 - t15;
	t33 = t12 + t43;
	t41 = t13 + t42;
	t12 -= t43;
	t13 -= t42;
	t42 = t39 - t24;
	t43 = t38 - t25;
	t39 += t24;
	t38 += t25;
	t24 = t46 - t21;
	t25 = t47 + t20;
	t46 += t21;
	t47 -= t20;
	t20 = t4 + t35;
	t21 = t5 - t34;
	t4 -= t35;
	t5 += t34;
	t34 = t22 - t23;
	t35 = t36 + t40;
	t22 += t23;
	t36 -= t40;
	t23 = t49 + t2;
	t40 = t48 - t3;
	t49 -= t2;
	t48 += t3;
	t2 = t31 + t9;
	t3 = t32 - t30;
	t31 -= t9;
	t32 += t30;
	t9 = t14 - t27;
	t30 = t15 + t26;
	t14 += t27;
	t15 -= t26;
	t26 = t34 + t2;
	t27 = t35 + t3;
	t34 -= t2;
	t35 -= t3;
	t2 = t22 - t31;
	t3 = t36 - t32;
	t22 += t31;
	t36 += t32;
	t31 = t23 + t9;
	t32 = t40 - t30;
	t23 -= t9;
	t40 += t30;
	t9 = t49 - t14;
	t30 = t48 + t15;
	t49 += t14;
	t48 -= t15;
	t14 = t37 + t11;
	t15 = t10 - t8;
	t37 -= t11;
	t10 += t8;
	t8 = t18 - t6;
	t11 = t19 - t7;
	t18 += t6;
	t19 += t7;
	pReal[0 * stride] = t0 + t18;
	pImag[0 * stride] = t1 + t19;
	pReal[1 * stride] = t39 + t22;
	pImag[1 * stride] = t38 + t36;
	pReal[2 * stride] = t24 + t32;
	pImag[2 * stride] = t25 + t31;
	pReal[3 * stride] = t16 + t15;
	pImag[3 * stride] = t17 + t14;
	pReal[4 * stride] = t4 - t49;
	pImag[4 * stride] = t5 + t48;
	pReal[5 * stride] = t42 + t34;
	pImag[5 * stride] = t43 + t35;
	pReal[6 * stride] = t28 - t11;
	pImag[6 * stride] = t29 + t8;
	pReal[7 * stride] = t12 - t3;
	pImag[7 * stride] = t13 + t2;
	pReal[8 * stride] = t20 - t23;
	pImag[8 * stride] = t21 + t40;
	pReal[9 * stride] = t44 - t37;
	pImag[9 * stride] = t45 + t10;
	pReal[10 * stride] = t46 - t30;
	pImag[10 * stride] = t47 - t9;
	pReal[11 * stride] = t33 - t27;
	pImag[11 * stride] = t41 + t26;
	pReal[12 * stride] = t0 - t18;
	pImag[12 * stride] = t1 - t19;
	pReal[13 * stride] = t39 - t22;
	pImag[13 * stride] = t38 - t36;
	pReal[14 * stride] = t24 - t32;
	pImag[14 * stride] = t25 - t31;
	pReal[15 * stride] = t16 - t15;
	pImag[15 * stride] = t17 - t14;
	pReal[16 * stride] = t4 + t49;
	pImag[16 * stride] = t5 - t48;
	pReal[17 * stride] = t42 - t34;
	pImag[17 * stride] = t43 - t35;
	pReal[18 * stride] = t28 + t11;
	pImag[18 * stride] = t29 - t8;
	pReal[19 * stride] = t12 + t3;
	pImag[19 * stride] = t13 - t2;
	pReal[20 * stride] = t20 + t23;
	pImag[20 * stride] = t21 - t40;
	pReal[21 * stride] = t44 + t37;
	pImag[21 * stride] = t45 - t10;
	pReal[22 * stride] = t46 + t30;
	pImag[22 * stride] = t47 + t9;
	pReal[23 * stride] = t33 + t27;
	pImag[23 * stride] = t41 - t26;
}

template<> void StandardModule<float, 24>::Compute(float *pReal, float *pImag, ptrdiff_t stride, float const *twiddles) const
{
	ComputeCore(pReal, pImag, stride, twiddles);
}

template<> void StandardModule<double, 24>::Compute(double *pReal, double *pImag, ptrdiff_t stride, double const *twiddles) const
{
	ComputeCore(pReal, pImag, stride, twiddles);
}

}
}
