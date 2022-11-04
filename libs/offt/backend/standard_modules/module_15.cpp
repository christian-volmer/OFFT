
//          Copyright Christian Volmer 2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include "../standard_module.h"

namespace offt {
namespace backend {

using std::size_t;
using std::ptrdiff_t;

template<typename valueT>
static void ComputeCore(Phasors<valueT> const &phasors, valueT *pReal, valueT *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement)
{
	valueT t1, t2, t3, t4, t5, t6, t7, t8, t9, t10;
	valueT t11, t12, t13, t14, t15, t16, t17, t18, t19, t20;
	valueT t21, t22, t23, t24, t25, t26, t27, t28, t29, t30;
	valueT t33, t34, t35, t36, t37, t38, t39, t40;

	phasors.Multiply(t1, t2, pReal[0 * stride], pImag[0 * stride], twiddleStart + 0 * twiddleIncrement);
	phasors.Multiply(t3, t4, pReal[1 * stride], pImag[1 * stride], twiddleStart + 1 * twiddleIncrement);
	phasors.Multiply(t5, t6, pReal[2 * stride], pImag[2 * stride], twiddleStart + 2 * twiddleIncrement);
	phasors.Multiply(t7, t8, pReal[3 * stride], pImag[3 * stride], twiddleStart + 3 * twiddleIncrement);
	phasors.Multiply(t9, t10, pReal[4 * stride], pImag[4 * stride], twiddleStart + 4 * twiddleIncrement);
	phasors.Multiply(t11, t12, pReal[5 * stride], pImag[5 * stride], twiddleStart + 5 * twiddleIncrement);
	phasors.Multiply(t13, t14, pReal[6 * stride], pImag[6 * stride], twiddleStart + 6 * twiddleIncrement);
	phasors.Multiply(t15, t16, pReal[7 * stride], pImag[7 * stride], twiddleStart + 7 * twiddleIncrement);
	phasors.Multiply(t17, t18, pReal[8 * stride], pImag[8 * stride], twiddleStart + 8 * twiddleIncrement);
	phasors.Multiply(t19, t20, pReal[9 * stride], pImag[9 * stride], twiddleStart + 9 * twiddleIncrement);
	phasors.Multiply(t21, t22, pReal[10 * stride], pImag[10 * stride], twiddleStart + 10 * twiddleIncrement);
	phasors.Multiply(t23, t24, pReal[11 * stride], pImag[11 * stride], twiddleStart + 11 * twiddleIncrement);
	phasors.Multiply(t25, t26, pReal[12 * stride], pImag[12 * stride], twiddleStart + 12 * twiddleIncrement);
	phasors.Multiply(t27, t28, pReal[13 * stride], pImag[13 * stride], twiddleStart + 13 * twiddleIncrement);
	phasors.Multiply(t29, t30, pReal[14 * stride], pImag[14 * stride], twiddleStart + 14 * twiddleIncrement);

	t33 = t3 - t23;
	t34 = t4 - t24;
	t3 += t23;
	t4 += t24;
	t23 = t5 - t15;
	t24 = t6 - t16;
	t5 += t15;
	t6 += t16;
	t15 = t9 - t29;
	t16 = t10 - t30;
	t9 += t29;
	t10 += t30;
	t29 = t11 - t21;
	t30 = t12 - t22;
	t11 += t21;
	t12 += t22;
	t21 = t17 - t27;
	t22 = t18 - t28;
	t17 += t27;
	t18 += t28;
	t1 += t11;
	t2 += t12;
	t13 = t3 + t13;
	t14 = t4 + t14;
	t25 = t5 + t25;
	t26 = t6 + t26;
	t7 += t17;
	t8 += t18;
	t19 = t9 + t19;
	t20 = t10 + t20;
	t27 = t33 - t15;
	t28 = t34 - t16;
	t33 += t15;
	t34 += t16;
	t15 = t3 - t9;
	t16 = t4 - t10;
	t3 += t9;
	t4 += t10;
	t9 = t13 - t19;
	t10 = t14 - t20;
	t13 += t19;
	t14 += t20;
	t19 = t23 - t21;
	t20 = t24 - t22;
	t23 += t21;
	t24 += t22;
	t21 = t5 - t17;
	t22 = t6 - t18;
	t5 += t17;
	t6 += t18;
	t17 = t25 - t7;
	t18 = t26 - t8;
	t25 += t7;
	t26 += t8;
	t7 = t27 - t19;
	t8 = t28 - t20;
	t35 = t33 - t23;
	t36 = t34 - t24;
	t33 += t23;
	t34 += t24;
	t23 = t15 + t21;
	t24 = t16 + t22;
	t37 = t3 - t5;
	t38 = t4 - t6;
	t3 += t5;
	t4 += t6;
	t5 = t9 + t17;
	t6 = t10 + t18;
	t39 = t13 - t25;
	t40 = t14 - t26;
	t13 += t25;
	t14 += t26;
	t1 += t13;
	t2 += t14;
	t29 = t35 - t29;
	t30 = t36 - t30;
	t11 = t3 + t11;
	t12 = t4 + t12;
	t27 *= valueT(0.31460214309120474243);
	t28 *= valueT(0.31460214309120474243);
	t7 *= valueT(0.50903696045512718345);
	t8 *= valueT(0.50903696045512718345);
	t36 *= valueT(1.0825317547305483085);
	t35 *= valueT(1.0825317547305483085);
	t30 *= valueT(0.86602540378443864676);
	t29 *= valueT(0.86602540378443864676);
	t34 *= valueT(0.48412291827592711065);
	t33 *= valueT(0.48412291827592711065);
	t16 *= valueT(0.54490689600402066442);
	t15 *= valueT(0.54490689600402066442);
	t24 *= valueT(0.88167787843870969375);
	t23 *= valueT(0.88167787843870969375);
	t37 *= valueT(0.83852549156242113615);
	t38 *= valueT(0.83852549156242113615);
	t3 *= valueT(1.875);
	t4 *= valueT(1.875);
	t11 *= valueT(1.5);
	t12 *= valueT(1.5);
	t10 *= valueT(0.36327126400268044295);
	t9 *= valueT(0.36327126400268044295);
	t6 *= valueT(0.58778525229247312917);
	t5 *= valueT(0.58778525229247312917);
	t39 *= valueT(0.5590169943749474241);
	t40 *= valueT(0.5590169943749474241);
	t13 *= valueT(1.25);
	t14 *= valueT(1.25);
	t19 *= valueT(1.3326760640014591093);
	t20 *= valueT(1.3326760640014591093);
	t22 *= valueT(2.3082626528814400519);
	t21 *= valueT(2.3082626528814400519);
	t18 *= valueT(1.5388417685876267013);
	t17 *= valueT(1.5388417685876267013);
	t13 = t1 - t13;
	t14 = t2 - t14;
	t36 -= t30;
	t35 -= t29;
	t3 -= t11;
	t4 -= t12;
	t25 = t13 + t39;
	t26 = t14 + t40;
	t13 -= t39;
	t14 -= t40;
	t27 += t7;
	t28 += t8;
	t7 += t19;
	t8 += t20;
	t19 = t36 - t34;
	t20 = t35 - t33;
	t36 += t34;
	t35 += t33;
	t16 += t24;
	t15 += t23;
	t24 -= t22;
	t23 -= t21;
	t21 = t37 - t3;
	t22 = t38 - t4;
	t37 += t3;
	t38 += t4;
	t10 += t6;
	t9 += t5;
	t6 -= t18;
	t5 -= t17;
	t3 = t25 - t10;
	t4 = t26 + t9;
	t25 += t10;
	t26 -= t9;
	t9 = t13 + t6;
	t10 = t14 - t5;
	t13 -= t6;
	t14 += t5;
	t5 = t27 - t19;
	t6 = t28 + t20;
	t27 += t19;
	t28 -= t20;
	t17 = t7 + t36;
	t18 = t8 - t35;
	t7 -= t36;
	t8 += t35;
	t19 = t16 - t21;
	t20 = t15 + t22;
	t16 += t21;
	t15 -= t22;
	t21 = t24 - t37;
	t22 = t23 + t38;
	t24 += t37;
	t23 -= t38;
	t11 = t1 - t11;
	t12 = t2 - t12;
	t19 = t3 + t19;
	t20 = t4 - t20;
	t16 = t25 - t16;
	t15 = t26 + t15;
	t21 = t9 - t21;
	t22 = t10 + t22;
	t24 = t13 + t24;
	t23 = t14 - t23;
	pReal[0 * stride] = t1;
	pImag[0 * stride] = t2;
	pReal[1 * stride] = t24 + t7;
	pImag[1 * stride] = t23 + t8;
	pReal[2 * stride] = t16 + t27;
	pImag[2 * stride] = t15 + t28;
	pReal[3 * stride] = t3;
	pImag[3 * stride] = t4;
	pReal[4 * stride] = t21 - t17;
	pImag[4 * stride] = t22 - t18;
	pReal[5 * stride] = t11 - t30;
	pImag[5 * stride] = t12 + t29;
	pReal[6 * stride] = t13;
	pImag[6 * stride] = t14;
	pReal[7 * stride] = t16 - t27;
	pImag[7 * stride] = t15 - t28;
	pReal[8 * stride] = t19 - t5;
	pImag[8 * stride] = t20 - t6;
	pReal[9 * stride] = t9;
	pImag[9 * stride] = t10;
	pReal[10 * stride] = t11 + t30;
	pImag[10 * stride] = t12 - t29;
	pReal[11 * stride] = t24 - t7;
	pImag[11 * stride] = t23 - t8;
	pReal[12 * stride] = t25;
	pImag[12 * stride] = t26;
	pReal[13 * stride] = t19 + t5;
	pImag[13 * stride] = t20 + t6;
	pReal[14 * stride] = t21 + t17;
	pImag[14 * stride] = t22 + t18;
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
