
//          Copyright Christian Volmer 2022, 2023.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include "../standard_module.h"

namespace offt {
namespace backend {

/*
	Number of additions       : 300
	Number of multiplications : 52
*/

template<> StandardModuleComplexity const StandardModule<float, 21>::Complexity = { 300, 52 };
template<> StandardModuleComplexity const StandardModule<double, 21>::Complexity = { 300, 52 };

template<typename valueT>
static void ComputeCore(valueT *pReal, valueT *pImag, ptrdiff_t stride, valueT const *twiddles)
{
	valueT t0, t1, t2, t3, t4, t5, t6, t7, t8, t9;
	valueT t10, t11, t12, t13, t14, t15, t16, t17, t18, t19;
	valueT t20, t21, t22, t23, t24, t25, t26, t27, t28, t29;
	valueT t30, t31, t32, t33, t34, t35, t36, t37, t38, t39;
	valueT t40, t41, t42, t43, t44, t45, t46, t47, t48, t49;
	valueT t50, t51, t52, t53;

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

	t42 = t2 - t16;
	t43 = t3 - t17;
	t2 += t16;
	t3 += t17;
	t16 = t4 - t32;
	t17 = t5 - t33;
	t4 += t32;
	t5 += t33;
	t32 = t8 - t22;
	t33 = t9 - t23;
	t8 += t22;
	t9 += t23;
	t22 = t10 - t38;
	t23 = t11 - t39;
	t10 += t38;
	t11 += t39;
	t38 = t14 - t28;
	t39 = t15 - t29;
	t14 += t28;
	t15 += t29;
	t28 = t20 - t34;
	t29 = t21 - t35;
	t20 += t34;
	t21 += t35;
	t34 = t26 - t40;
	t35 = t27 - t41;
	t26 += t40;
	t27 += t41;
	t0 += t14;
	t1 += t15;
	t30 = t2 + t30;
	t31 = t3 + t31;
	t18 = t4 + t18;
	t19 = t5 + t19;
	t6 += t20;
	t7 += t21;
	t36 = t8 + t36;
	t37 = t9 + t37;
	t24 = t10 + t24;
	t25 = t11 + t25;
	t12 += t26;
	t13 += t27;
	t40 = t42 - t34;
	t41 = t43 - t35;
	t42 += t34;
	t43 += t35;
	t34 = t2 - t26;
	t35 = t3 - t27;
	t2 += t26;
	t3 += t27;
	t26 = t30 - t12;
	t27 = t31 - t13;
	t30 += t12;
	t31 += t13;
	t12 = t16 - t22;
	t13 = t17 - t23;
	t16 += t22;
	t17 += t23;
	t22 = t4 - t10;
	t23 = t5 - t11;
	t4 += t10;
	t5 += t11;
	t10 = t18 - t24;
	t11 = t19 - t25;
	t18 += t24;
	t19 += t25;
	t24 = t6 - t36;
	t25 = t7 - t37;
	t6 += t36;
	t7 += t37;
	t36 = t32 - t28;
	t37 = t33 - t29;
	t32 += t28;
	t33 += t29;
	t28 = t8 - t20;
	t29 = t9 - t21;
	t8 += t20;
	t9 += t21;
	t20 = t40 + t12;
	t21 = t41 + t13;
	t12 = t40 - t12 + t36;
	t13 = t41 - t13 + t37;
	t40 -= t36;
	t41 -= t37;
	t36 = t42 + t16;
	t37 = t43 + t17;
	t44 = t42 - t16 + t32;
	t45 = t43 - t17 + t33;
	t42 -= t32;
	t43 -= t33;
	t46 = t34 - t22;
	t47 = t35 - t23;
	t22 = t34 + t22 + t28;
	t23 = t35 + t23 + t29;
	t34 -= t28;
	t35 -= t29;
	t28 = t2 - t4;
	t29 = t3 - t5;
	t48 = t2 + t4 + t8;
	t49 = t3 + t5 + t9;
	t2 -= t8;
	t3 -= t9;
	t50 = t26 - t10;
	t51 = t27 - t11;
	t10 = t26 + t10 - t24;
	t11 = t27 + t11 - t25;
	t26 += t24;
	t27 += t25;
	t24 = t30 - t18;
	t25 = t31 - t19;
	t52 = t30 + t18 + t6;
	t53 = t31 + t19 + t7;
	t30 -= t6;
	t31 -= t7;
	t16 += t32;
	t17 += t33;
	t4 -= t8;
	t5 -= t9;
	t18 -= t6;
	t19 -= t7;
	t0 += t52;
	t1 += t53;
	t6 = t20 + t40;
	t7 = t21 + t41;
	t38 = t44 + t38;
	t39 = t45 + t39;
	t8 = t46 + t34;
	t9 = t47 + t35;
	t14 = t48 + t14;
	t15 = t49 + t15;
	t32 = t50 + t26;
	t33 = t51 + t27;
	t20 *= valueT(1.2200666791727688395);
	t21 *= valueT(1.2200666791727688395);
	t6 *= valueT(0.75763564827777197604);
	t7 *= valueT(0.75763564827777197604);
	t12 *= valueT(0.38188130791298666722);
	t13 *= valueT(0.38188130791298666722);
	t40 *= valueT(1.0528402656605470886);
	t41 *= valueT(1.0528402656605470886);
	t37 *= valueT(0.68429557470759579241);
	t36 *= valueT(0.68429557470759579241);
	t45 *= valueT(1.0103629710818450879);
	t44 *= valueT(1.0103629710818450879);
	t39 *= valueT(0.86602540378443864676);
	t38 *= valueT(0.86602540378443864676);
	t43 *= valueT(0.048371214382601145551);
	t42 *= valueT(0.048371214382601145551);
	t47 *= valueT(2.1132174769490725912);
	t46 *= valueT(2.1132174769490725912);
	t9 *= valueT(1.3122634364424848283);
	t8 *= valueT(1.3122634364424848283);
	t23 *= valueT(0.66143782776614764763);
	t22 *= valueT(0.66143782776614764763);
	t35 *= valueT(1.8235728323783818938);
	t34 *= valueT(1.8235728323783818938);
	t28 *= valueT(1.1852347027881002958);
	t29 *= valueT(1.1852347027881002958);
	t48 *= valueT(1.75);
	t49 *= valueT(1.75);
	t14 *= valueT(1.5);
	t15 *= valueT(1.5);
	t2 *= valueT(0.083781400934471606433);
	t3 *= valueT(0.083781400934471606433);
	t51 *= valueT(1.4088116512993817275);
	t50 *= valueT(1.4088116512993817275);
	t33 *= valueT(0.87484229096165655223);
	t32 *= valueT(0.87484229096165655223);
	t11 *= valueT(0.44095855184409843175);
	t10 *= valueT(0.44095855184409843175);
	t27 *= valueT(1.2157152215855879292);
	t26 *= valueT(1.2157152215855879292);
	t24 *= valueT(0.79015646852540019719);
	t25 *= valueT(0.79015646852540019719);
	t52 *= valueT(1.1666666666666666667);
	t53 *= valueT(1.1666666666666666667);
	t30 *= valueT(0.055854267289647737622);
	t31 *= valueT(0.055854267289647737622);
	t17 *= valueT(0.63592436032499464686);
	t16 *= valueT(0.63592436032499464686);
	t4 *= valueT(1.1014533018536286894);
	t5 *= valueT(1.1014533018536286894);
	t18 *= valueT(0.73430220123575245957);
	t19 *= valueT(0.73430220123575245957);
	t52 = t0 - t52;
	t53 = t1 - t53;
	t20 -= t6;
	t21 -= t7;
	t6 -= t40;
	t7 -= t41;
	t45 -= t39;
	t44 -= t38;
	t47 -= t9;
	t46 -= t8;
	t9 -= t35;
	t8 -= t34;
	t48 -= t14;
	t49 -= t15;
	t51 -= t33;
	t50 -= t32;
	t33 -= t27;
	t32 -= t26;
	t26 = t52 - t24 + t30;
	t27 = t53 - t25 + t31;
	t24 = t52 + t24 + t18;
	t25 = t53 + t25 + t19;
	t52 -= t30 + t18;
	t53 -= t31 + t19;
	t18 = t20 - t6 + t12;
	t19 = t21 - t7 + t13;
	t20 -= t12;
	t21 -= t13;
	t6 += t12;
	t7 += t13;
	t12 = t37 + t45 - t43;
	t13 = t36 + t44 - t42;
	t37 -= t45 + t17;
	t36 -= t44 + t16;
	t45 += t43 - t17;
	t44 += t42 - t16;
	t16 = t47 - t9 + t23;
	t17 = t46 - t8 + t22;
	t47 -= t23;
	t46 -= t22;
	t9 += t23;
	t8 += t22;
	t22 = t28 + t48 - t2;
	t23 = t29 + t49 - t3;
	t28 -= t48 - t4;
	t29 -= t49 - t5;
	t48 += t2 + t4;
	t49 += t3 + t5;
	t2 = t51 - t33 + t11;
	t3 = t50 - t32 + t10;
	t51 -= t11;
	t50 -= t10;
	t33 += t11;
	t32 += t10;
	t4 = t26 + t2;
	t5 = t27 - t3;
	t26 -= t2;
	t27 += t3;
	t2 = t24 + t51;
	t3 = t25 - t50;
	t24 -= t51;
	t25 += t50;
	t10 = t52 + t33;
	t11 = t53 - t32;
	t52 -= t33;
	t53 += t32;
	t30 = t18 + t12;
	t31 = t19 - t13;
	t18 -= t12;
	t19 += t13;
	t12 = t20 - t37;
	t13 = t21 + t36;
	t20 += t37;
	t21 -= t36;
	t32 = t6 + t45;
	t33 = t7 - t44;
	t6 -= t45;
	t7 += t44;
	t34 = t16 - t22;
	t35 = t17 + t23;
	t16 += t22;
	t17 -= t23;
	t22 = t47 + t28;
	t23 = t46 - t29;
	t47 -= t28;
	t46 += t29;
	t28 = t9 - t48;
	t29 = t8 + t49;
	t9 += t48;
	t8 -= t49;
	t14 = t0 - t14;
	t15 = t1 - t15;
	t34 = t4 - t34;
	t35 = t5 + t35;
	t16 = t26 + t16;
	t17 = t27 - t17;
	t22 = t2 - t22;
	t23 = t3 + t23;
	t47 = t24 + t47;
	t46 = t25 - t46;
	t28 = t10 - t28;
	t29 = t11 + t29;
	t9 = t52 + t9;
	t8 = t53 - t8;
	pReal[0 * stride] = t0;
	pImag[0 * stride] = t1;
	pReal[1 * stride] = t28 + t32;
	pImag[1 * stride] = t29 + t33;
	pReal[2 * stride] = t34 - t30;
	pImag[2 * stride] = t35 - t31;
	pReal[3 * stride] = t2;
	pImag[3 * stride] = t3;
	pReal[4 * stride] = t47 - t20;
	pImag[4 * stride] = t46 - t21;
	pReal[5 * stride] = t16 + t18;
	pImag[5 * stride] = t17 + t19;
	pReal[6 * stride] = t52;
	pImag[6 * stride] = t53;
	pReal[7 * stride] = t14 - t39;
	pImag[7 * stride] = t15 + t38;
	pReal[8 * stride] = t28 - t32;
	pImag[8 * stride] = t29 - t33;
	pReal[9 * stride] = t4;
	pImag[9 * stride] = t5;
	pReal[10 * stride] = t22 + t12;
	pImag[10 * stride] = t23 + t13;
	pReal[11 * stride] = t47 + t20;
	pImag[11 * stride] = t46 + t21;
	pReal[12 * stride] = t26;
	pImag[12 * stride] = t27;
	pReal[13 * stride] = t9 - t6;
	pImag[13 * stride] = t8 - t7;
	pReal[14 * stride] = t14 + t39;
	pImag[14 * stride] = t15 - t38;
	pReal[15 * stride] = t10;
	pImag[15 * stride] = t11;
	pReal[16 * stride] = t34 + t30;
	pImag[16 * stride] = t35 + t31;
	pReal[17 * stride] = t22 - t12;
	pImag[17 * stride] = t23 - t13;
	pReal[18 * stride] = t24;
	pImag[18 * stride] = t25;
	pReal[19 * stride] = t16 - t18;
	pImag[19 * stride] = t17 - t19;
	pReal[20 * stride] = t9 + t6;
	pImag[20 * stride] = t8 + t7;
}

template<> void StandardModule<float, 21>::Compute(float *pReal, float *pImag, ptrdiff_t stride, float const *twiddles) const
{
	ComputeCore(pReal, pImag, stride, twiddles);
}

template<> void StandardModule<double, 21>::Compute(double *pReal, double *pImag, ptrdiff_t stride, double const *twiddles) const
{
	ComputeCore(pReal, pImag, stride, twiddles);
}

}
}
