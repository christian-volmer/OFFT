
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
	Number of additions       : 216
	Number of multiplications : 40
*/

template<> StandardModuleComplexity const StandardModule<float, 20>::Complexity = { 216, 40 };
template<> StandardModuleComplexity const StandardModule<double, 20>::Complexity = { 216, 40 };

template<typename valueT>
static void ComputeCore(Phasors<valueT> const &phasors, valueT *pReal, valueT *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement)
{
	valueT t0, t1, t2, t3, t4, t5, t6, t7, t8, t9;
	valueT t10, t11, t12, t13, t14, t15, t16, t17, t18, t19;
	valueT t20, t21, t22, t23, t24, t25, t26, t27, t28, t29;
	valueT t30, t31, t32, t33, t34, t35, t36, t37, t38, t39;
	valueT t40, t41, t42, t43, t44, t45, t46, t47, t48, t49;

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
	phasors.Multiply(t24, t25, pReal[12 * stride], pImag[12 * stride], twiddleStart + 12 * twiddleIncrement);
	phasors.Multiply(t26, t27, pReal[13 * stride], pImag[13 * stride], twiddleStart + 13 * twiddleIncrement);
	phasors.Multiply(t28, t29, pReal[14 * stride], pImag[14 * stride], twiddleStart + 14 * twiddleIncrement);
	phasors.Multiply(t30, t31, pReal[15 * stride], pImag[15 * stride], twiddleStart + 15 * twiddleIncrement);
	phasors.Multiply(t32, t33, pReal[16 * stride], pImag[16 * stride], twiddleStart + 16 * twiddleIncrement);
	phasors.Multiply(t34, t35, pReal[17 * stride], pImag[17 * stride], twiddleStart + 17 * twiddleIncrement);
	phasors.Multiply(t36, t37, pReal[18 * stride], pImag[18 * stride], twiddleStart + 18 * twiddleIncrement);
	phasors.Multiply(t38, t39, pReal[19 * stride], pImag[19 * stride], twiddleStart + 19 * twiddleIncrement);

	t40 = t0 - t20;
	t41 = t1 - t21;
	t0 += t20;
	t1 += t21;
	t20 = t2 - t22;
	t21 = t3 - t23;
	t2 += t22;
	t3 += t23;
	t22 = t4 - t24;
	t23 = t5 - t25;
	t4 += t24;
	t5 += t25;
	t24 = t6 - t26;
	t25 = t7 - t27;
	t6 += t26;
	t7 += t27;
	t26 = t8 - t28;
	t27 = t9 - t29;
	t8 += t28;
	t9 += t29;
	t28 = t10 - t30;
	t29 = t11 - t31;
	t10 += t30;
	t11 += t31;
	t30 = t12 - t32;
	t31 = t13 - t33;
	t12 += t32;
	t13 += t33;
	t32 = t14 - t34;
	t33 = t15 - t35;
	t14 += t34;
	t15 += t35;
	t34 = t16 - t36;
	t35 = t17 - t37;
	t16 += t36;
	t17 += t37;
	t36 = t18 - t38;
	t37 = t19 - t39;
	t18 += t38;
	t19 += t39;
	t38 = t20 - t36;
	t39 = t21 - t37;
	t20 += t36;
	t21 += t37;
	t36 = t2 - t18;
	t37 = t3 - t19;
	t2 += t18;
	t3 += t19;
	t18 = t22 - t34;
	t19 = t23 - t35;
	t22 += t34;
	t23 += t35;
	t34 = t4 - t16;
	t35 = t5 - t17;
	t4 += t16;
	t5 += t17;
	t16 = t24 - t32;
	t17 = t25 - t33;
	t24 += t32;
	t25 += t33;
	t32 = t6 - t14;
	t33 = t7 - t15;
	t6 += t14;
	t7 += t15;
	t14 = t26 - t30;
	t15 = t27 - t31;
	t26 += t30;
	t27 += t31;
	t30 = t8 - t12;
	t31 = t9 - t13;
	t8 += t12;
	t9 += t13;
	t12 = t38 - t16;
	t13 = t39 - t17;
	t42 = t20 - t24;
	t43 = t21 - t25;
	t20 += t24;
	t21 += t25;
	t24 = t36 + t32;
	t25 = t37 + t33;
	t44 = t2 - t6;
	t45 = t3 - t7;
	t2 += t6;
	t3 += t7;
	t6 = t18 - t14;
	t7 = t19 - t15;
	t18 += t14;
	t19 += t15;
	t14 = t22 - t26;
	t15 = t23 - t27;
	t46 = t34 + t30;
	t47 = t35 + t31;
	t48 = t4 - t8;
	t49 = t5 - t9;
	t4 += t8;
	t5 += t9;
	t40 -= t6;
	t41 -= t7;
	t0 += t4;
	t1 += t5;
	t28 = t42 + t28;
	t29 = t43 + t29;
	t10 = t2 + t10;
	t11 = t3 + t11;
	t38 *= valueT(1.5388417685876267013);
	t39 *= valueT(1.5388417685876267013);
	t12 *= valueT(0.58778525229247312917);
	t13 *= valueT(0.58778525229247312917);
	t43 *= valueT(1.25);
	t42 *= valueT(1.25);
	t21 *= valueT(0.5590169943749474241);
	t20 *= valueT(0.5590169943749474241);
	t37 *= valueT(1.5388417685876267013);
	t36 *= valueT(1.5388417685876267013);
	t25 *= valueT(0.58778525229247312917);
	t24 *= valueT(0.58778525229247312917);
	t44 *= valueT(0.5590169943749474241);
	t45 *= valueT(0.5590169943749474241);
	t2 *= valueT(1.25);
	t3 *= valueT(1.25);
	t6 *= valueT(1.25);
	t7 *= valueT(1.25);
	t18 *= valueT(0.5590169943749474241);
	t19 *= valueT(0.5590169943749474241);
	t23 *= valueT(0.36327126400268044295);
	t22 *= valueT(0.36327126400268044295);
	t15 *= valueT(0.58778525229247312917);
	t14 *= valueT(0.58778525229247312917);
	t35 *= valueT(0.36327126400268044295);
	t34 *= valueT(0.36327126400268044295);
	t47 *= valueT(0.58778525229247312917);
	t46 *= valueT(0.58778525229247312917);
	t48 *= valueT(0.5590169943749474241);
	t49 *= valueT(0.5590169943749474241);
	t4 *= valueT(1.25);
	t5 *= valueT(1.25);
	t16 *= valueT(0.36327126400268044295);
	t17 *= valueT(0.36327126400268044295);
	t33 *= valueT(0.36327126400268044295);
	t32 *= valueT(0.36327126400268044295);
	t27 *= valueT(1.5388417685876267013);
	t26 *= valueT(1.5388417685876267013);
	t31 *= valueT(1.5388417685876267013);
	t30 *= valueT(1.5388417685876267013);
	t6 = t40 + t6;
	t7 = t41 + t7;
	t4 = t0 - t4;
	t5 = t1 - t5;
	t43 -= t29;
	t42 -= t28;
	t2 -= t10;
	t3 -= t11;
	t8 = t6 - t18;
	t9 = t7 - t19;
	t6 += t18;
	t7 += t19;
	t18 = t4 + t48;
	t19 = t5 + t49;
	t4 -= t48;
	t5 -= t49;
	t38 -= t12;
	t39 -= t13;
	t12 -= t16;
	t13 -= t17;
	t16 = t43 + t21;
	t17 = t42 + t20;
	t43 -= t21;
	t42 -= t20;
	t37 -= t25;
	t36 -= t24;
	t25 += t33;
	t24 += t32;
	t20 = t44 + t2;
	t21 = t45 + t3;
	t44 -= t2;
	t45 -= t3;
	t23 += t15;
	t22 += t14;
	t15 += t27;
	t14 += t26;
	t35 += t47;
	t34 += t46;
	t47 -= t31;
	t46 -= t30;
	t2 = t8 - t23;
	t3 = t9 + t22;
	t8 += t23;
	t9 -= t22;
	t22 = t6 + t15;
	t23 = t7 - t14;
	t6 -= t15;
	t7 += t14;
	t14 = t18 + t35;
	t15 = t19 - t34;
	t18 -= t35;
	t19 += t34;
	t26 = t4 - t47;
	t27 = t5 + t46;
	t4 += t47;
	t5 -= t46;
	t30 = t38 - t43;
	t31 = t39 + t42;
	t38 += t43;
	t39 -= t42;
	t32 = t12 - t16;
	t33 = t13 + t17;
	t12 += t16;
	t13 -= t17;
	t16 = t37 - t44;
	t17 = t36 + t45;
	t37 += t44;
	t36 -= t45;
	t34 = t25 + t20;
	t35 = t24 - t21;
	t25 -= t20;
	t24 += t21;
	pReal[0 * stride] = t0 + t10;
	pImag[0 * stride] = t1 + t11;
	pReal[1 * stride] = t6 + t38;
	pImag[1 * stride] = t7 + t39;
	pReal[2 * stride] = t18 - t25;
	pImag[2 * stride] = t19 + t24;
	pReal[3 * stride] = t2 + t32;
	pImag[3 * stride] = t3 + t33;
	pReal[4 * stride] = t26 - t16;
	pImag[4 * stride] = t27 + t17;
	pReal[5 * stride] = t40 - t29;
	pImag[5 * stride] = t41 + t28;
	pReal[6 * stride] = t4 - t37;
	pImag[6 * stride] = t5 + t36;
	pReal[7 * stride] = t8 - t12;
	pImag[7 * stride] = t9 - t13;
	pReal[8 * stride] = t14 - t34;
	pImag[8 * stride] = t15 + t35;
	pReal[9 * stride] = t22 - t30;
	pImag[9 * stride] = t23 - t31;
	pReal[10 * stride] = t0 - t10;
	pImag[10 * stride] = t1 - t11;
	pReal[11 * stride] = t6 - t38;
	pImag[11 * stride] = t7 - t39;
	pReal[12 * stride] = t18 + t25;
	pImag[12 * stride] = t19 - t24;
	pReal[13 * stride] = t2 - t32;
	pImag[13 * stride] = t3 - t33;
	pReal[14 * stride] = t26 + t16;
	pImag[14 * stride] = t27 - t17;
	pReal[15 * stride] = t40 + t29;
	pImag[15 * stride] = t41 - t28;
	pReal[16 * stride] = t4 + t37;
	pImag[16 * stride] = t5 - t36;
	pReal[17 * stride] = t8 + t12;
	pImag[17 * stride] = t9 + t13;
	pReal[18 * stride] = t14 + t34;
	pImag[18 * stride] = t15 - t35;
	pReal[19 * stride] = t22 + t30;
	pImag[19 * stride] = t23 + t31;
}

template<> void StandardModule<float, 20>::Compute(float *pReal, float *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

template<> void StandardModule<double, 20>::Compute(double *pReal, double *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

}
}
