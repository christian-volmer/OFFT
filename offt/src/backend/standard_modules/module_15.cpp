
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
	Number of additions       : 162
	Number of multiplications : 34
*/

template<> StandardModuleComplexity const StandardModule<float, 15>::Complexity = { 162, 34 };
template<> StandardModuleComplexity const StandardModule<double, 15>::Complexity = { 162, 34 };

template<typename valueT>
static void ComputeCore(Phasors<valueT> const &phasors, valueT *pReal, valueT *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement)
{
	valueT t0, t1, t2, t3, t4, t5, t6, t7, t8, t9;
	valueT t10, t11, t12, t13, t14, t15, t16, t17, t18, t19;
	valueT t20, t21, t22, t23, t24, t25, t26, t27, t28, t29;
	valueT t30, t31, t32, t33, t34, t35, t36, t37;

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

	t30 = t2 - t22;
	t31 = t3 - t23;
	t2 += t22;
	t3 += t23;
	t22 = t4 - t14;
	t23 = t5 - t15;
	t4 += t14;
	t5 += t15;
	t14 = t8 - t28;
	t15 = t9 - t29;
	t8 += t28;
	t9 += t29;
	t28 = t10 - t20;
	t29 = t11 - t21;
	t10 += t20;
	t11 += t21;
	t20 = t16 - t26;
	t21 = t17 - t27;
	t16 += t26;
	t17 += t27;
	t0 += t10;
	t1 += t11;
	t12 = t2 + t12;
	t13 = t3 + t13;
	t24 = t4 + t24;
	t25 = t5 + t25;
	t6 += t16;
	t7 += t17;
	t18 = t8 + t18;
	t19 = t9 + t19;
	t26 = t30 - t14;
	t27 = t31 - t15;
	t30 += t14;
	t31 += t15;
	t14 = t2 - t8;
	t15 = t3 - t9;
	t2 += t8;
	t3 += t9;
	t8 = t12 - t18;
	t9 = t13 - t19;
	t12 += t18;
	t13 += t19;
	t18 = t22 - t20;
	t19 = t23 - t21;
	t22 += t20;
	t23 += t21;
	t20 = t4 - t16;
	t21 = t5 - t17;
	t4 += t16;
	t5 += t17;
	t16 = t24 - t6;
	t17 = t25 - t7;
	t24 += t6;
	t25 += t7;
	t6 = t26 - t18;
	t7 = t27 - t19;
	t32 = t30 - t22;
	t33 = t31 - t23;
	t30 += t22;
	t31 += t23;
	t22 = t14 + t20;
	t23 = t15 + t21;
	t34 = t2 - t4;
	t35 = t3 - t5;
	t2 += t4;
	t3 += t5;
	t4 = t8 + t16;
	t5 = t9 + t17;
	t36 = t12 - t24;
	t37 = t13 - t25;
	t12 += t24;
	t13 += t25;
	t0 += t12;
	t1 += t13;
	t28 = t32 - t28;
	t29 = t33 - t29;
	t10 = t2 + t10;
	t11 = t3 + t11;
	t26 *= valueT(0.31460214309120474243);
	t27 *= valueT(0.31460214309120474243);
	t6 *= valueT(0.50903696045512718345);
	t7 *= valueT(0.50903696045512718345);
	t33 *= valueT(1.0825317547305483085);
	t32 *= valueT(1.0825317547305483085);
	t29 *= valueT(0.86602540378443864676);
	t28 *= valueT(0.86602540378443864676);
	t31 *= valueT(0.48412291827592711065);
	t30 *= valueT(0.48412291827592711065);
	t15 *= valueT(0.54490689600402066442);
	t14 *= valueT(0.54490689600402066442);
	t23 *= valueT(0.88167787843870969375);
	t22 *= valueT(0.88167787843870969375);
	t34 *= valueT(0.83852549156242113615);
	t35 *= valueT(0.83852549156242113615);
	t2 *= valueT(1.875);
	t3 *= valueT(1.875);
	t10 *= valueT(1.5);
	t11 *= valueT(1.5);
	t9 *= valueT(0.36327126400268044295);
	t8 *= valueT(0.36327126400268044295);
	t5 *= valueT(0.58778525229247312917);
	t4 *= valueT(0.58778525229247312917);
	t36 *= valueT(0.5590169943749474241);
	t37 *= valueT(0.5590169943749474241);
	t12 *= valueT(1.25);
	t13 *= valueT(1.25);
	t18 *= valueT(1.3326760640014591093);
	t19 *= valueT(1.3326760640014591093);
	t21 *= valueT(2.3082626528814400519);
	t20 *= valueT(2.3082626528814400519);
	t17 *= valueT(1.5388417685876267013);
	t16 *= valueT(1.5388417685876267013);
	t12 = t0 - t12;
	t13 = t1 - t13;
	t33 -= t29;
	t32 -= t28;
	t2 -= t10;
	t3 -= t11;
	t24 = t12 + t36;
	t25 = t13 + t37;
	t12 -= t36;
	t13 -= t37;
	t26 += t6;
	t27 += t7;
	t6 += t18;
	t7 += t19;
	t18 = t33 - t31;
	t19 = t32 - t30;
	t33 += t31;
	t32 += t30;
	t15 += t23;
	t14 += t22;
	t23 -= t21;
	t22 -= t20;
	t20 = t34 - t2;
	t21 = t35 - t3;
	t34 += t2;
	t35 += t3;
	t9 += t5;
	t8 += t4;
	t5 -= t17;
	t4 -= t16;
	t2 = t24 - t9;
	t3 = t25 + t8;
	t24 += t9;
	t25 -= t8;
	t8 = t12 + t5;
	t9 = t13 - t4;
	t12 -= t5;
	t13 += t4;
	t4 = t26 - t18;
	t5 = t27 + t19;
	t26 += t18;
	t27 -= t19;
	t16 = t6 + t33;
	t17 = t7 - t32;
	t6 -= t33;
	t7 += t32;
	t18 = t15 - t20;
	t19 = t14 + t21;
	t15 += t20;
	t14 -= t21;
	t20 = t23 - t34;
	t21 = t22 + t35;
	t23 += t34;
	t22 -= t35;
	t10 = t0 - t10;
	t11 = t1 - t11;
	t18 = t2 + t18;
	t19 = t3 - t19;
	t15 = t24 - t15;
	t14 = t25 + t14;
	t20 = t8 - t20;
	t21 = t9 + t21;
	t23 = t12 + t23;
	t22 = t13 - t22;
	pReal[0 * stride] = t0;
	pImag[0 * stride] = t1;
	pReal[1 * stride] = t23 + t6;
	pImag[1 * stride] = t22 + t7;
	pReal[2 * stride] = t15 + t26;
	pImag[2 * stride] = t14 + t27;
	pReal[3 * stride] = t2;
	pImag[3 * stride] = t3;
	pReal[4 * stride] = t20 - t16;
	pImag[4 * stride] = t21 - t17;
	pReal[5 * stride] = t10 - t29;
	pImag[5 * stride] = t11 + t28;
	pReal[6 * stride] = t12;
	pImag[6 * stride] = t13;
	pReal[7 * stride] = t15 - t26;
	pImag[7 * stride] = t14 - t27;
	pReal[8 * stride] = t18 - t4;
	pImag[8 * stride] = t19 - t5;
	pReal[9 * stride] = t8;
	pImag[9 * stride] = t9;
	pReal[10 * stride] = t10 + t29;
	pImag[10 * stride] = t11 - t28;
	pReal[11 * stride] = t23 - t6;
	pImag[11 * stride] = t22 - t7;
	pReal[12 * stride] = t24;
	pImag[12 * stride] = t25;
	pReal[13 * stride] = t18 + t4;
	pImag[13 * stride] = t19 + t5;
	pReal[14 * stride] = t20 + t16;
	pImag[14 * stride] = t21 + t17;
}

template<> void StandardModule<float, 15>::Compute(float *pReal, float *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

template<> void StandardModule<double, 15>::Compute(double *pReal, double *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

}
}
