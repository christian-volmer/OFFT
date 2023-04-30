
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
	valueT t0, t1, t2, t3, t4, t5, t6, t7, t8, t9;
	valueT t10, t11, t12, t13, t14, t15, t16, t17, t18, t19;
	valueT t20, t21, t22, t23, t24, t25, t26, t27, t28, t29;
	valueT t30, t31, t32, t33, t34, t35, t36, t37, t38, t39;
	valueT t40, t41;

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

	t22 = t2 - t20;
	t23 = t3 - t21;
	t2 += t20;
	t3 += t21;
	t20 = t4 - t18;
	t21 = t5 - t19;
	t4 += t18;
	t5 += t19;
	t18 = t6 - t16;
	t19 = t7 - t17;
	t6 += t16;
	t7 += t17;
	t16 = t8 - t14;
	t17 = t9 - t15;
	t8 += t14;
	t9 += t15;
	t14 = t10 - t12;
	t15 = t11 - t13;
	t10 += t12;
	t11 += t13;
	t12 = t22 - t20 + t18 + t16 + t14;
	t13 = t23 - t21 + t19 + t17 + t15;
	t24 = t22 - t16;
	t25 = t23 - t17;
	t22 -= t14;
	t23 -= t15;
	t26 = t2 + t4 + t6 + t8 + t10;
	t27 = t3 + t5 + t7 + t9 + t11;
	t28 = t2 - t8;
	t29 = t3 - t9;
	t2 -= t10;
	t3 -= t11;
	t30 = t20 + t18;
	t31 = t21 + t19;
	t20 += t14;
	t21 += t15;
	t32 = t4 - t6;
	t33 = t5 - t7;
	t4 -= t10;
	t5 -= t11;
	t18 -= t14;
	t19 -= t15;
	t6 -= t10;
	t7 -= t11;
	t16 -= t14;
	t17 -= t15;
	t8 -= t10;
	t9 -= t11;
	t0 += t26;
	t1 += t27;
	t10 = t24 - t30;
	t11 = t25 - t31;
	t14 = t22 - t20;
	t15 = t23 - t21;
	t34 = t28 - t32;
	t35 = t29 - t33;
	t36 = t2 - t4;
	t37 = t3 - t5;
	t38 = t18 + t16;
	t39 = t19 + t17;
	t40 = t6 - t8;
	t41 = t7 - t9;
	t13 *= valueT(0.33166247903553998491);
	t12 *= valueT(0.33166247903553998491);
	t25 *= valueT(0.2340718675266744486);
	t24 *= valueT(0.2340718675266744486);
	t11 *= valueT(0.65815896284539274746);
	t10 *= valueT(0.65815896284539274746);
	t23 *= valueT(1.2162009452834415049);
	t22 *= valueT(1.2162009452834415049);
	t15 *= valueT(0.58313551154466560886);
	t14 *= valueT(0.58313551154466560886);
	t26 *= valueT(1.1);
	t27 *= valueT(1.1);
	t28 *= valueT(0.5971755722185702045);
	t29 *= valueT(0.5971755722185702045);
	t34 *= valueT(0.042314838273285140444);
	t35 *= valueT(0.042314838273285140444);
	t2 *= valueT(0.85949297361449738989);
	t3 *= valueT(0.85949297361449738989);
	t36 *= valueT(0.47310017472860128509);
	t37 *= valueT(0.47310017472860128509);
	t31 *= valueT(0.70808888503950303466);
	t30 *= valueT(0.70808888503950303466);
	t21 *= valueT(0.95729268466927362052);
	t20 *= valueT(0.95729268466927362052);
	t32 *= valueT(0.90180781188778253033);
	t33 *= valueT(0.90180781188778253033);
	t4 *= valueT(0.94125353283118116886);
	t5 *= valueT(0.94125353283118116886);
	t19 *= valueT(2.1583616978496189882);
	t18 *= valueT(2.1583616978496189882);
	t39 *= valueT(0.86713730126545034466);
	t38 *= valueT(0.86713730126545034466);
	t6 *= valueT(0.55486073394528506406);
	t7 *= valueT(0.55486073394528506406);
	t40 *= valueT(0.89893869455789602842);
	t41 *= valueT(0.89893869455789602842);
	t17 *= valueT(0.492980128140842333);
	t16 *= valueT(0.492980128140842333);
	t8 *= valueT(0.51541501300188642553);
	t9 *= valueT(0.51541501300188642553);
	t26 = t0 - t26;
	t27 = t1 - t27;
	t25 -= t11;
	t24 -= t10;
	t11 += t31;
	t10 += t30;
	t23 -= t15;
	t22 -= t14;
	t15 += t21;
	t14 += t20;
	t28 -= t34;
	t29 -= t35;
	t34 += t32;
	t35 += t33;
	t2 -= t36;
	t3 -= t37;
	t36 -= t4;
	t37 -= t5;
	t19 -= t39;
	t18 -= t38;
	t39 -= t17;
	t38 -= t16;
	t6 -= t40;
	t7 -= t41;
	t40 -= t8;
	t41 -= t9;
	t4 = t26 + t28 + t2;
	t5 = t27 + t29 + t3;
	t28 = t26 - t28 + t40;
	t29 = t27 - t29 + t41;
	t8 = t26 + t34 + t36;
	t9 = t27 + t35 + t37;
	t34 = t26 - t34 + t6;
	t35 = t27 - t35 + t7;
	t26 -= t2 + t36 + t6 + t40;
	t27 -= t3 + t37 + t7 + t41;
	t2 = t13 + t25 + t23;
	t3 = t12 + t24 + t22;
	t25 = t13 - t25 + t39;
	t24 = t12 - t24 + t38;
	t6 = t13 - t11 - t15;
	t7 = t12 - t10 - t14;
	t11 = t13 + t11 - t19;
	t10 = t12 + t10 - t18;
	t13 -= t23 - t15 - t19 + t39;
	t12 -= t22 - t14 - t18 + t38;
	pReal[0 * stride] = t0;
	pImag[0 * stride] = t1;
	pReal[1 * stride] = t4 - t2;
	pImag[1 * stride] = t5 + t3;
	pReal[2 * stride] = t8 + t6;
	pImag[2 * stride] = t9 - t7;
	pReal[3 * stride] = t34 - t11;
	pImag[3 * stride] = t35 + t10;
	pReal[4 * stride] = t28 - t25;
	pImag[4 * stride] = t29 + t24;
	pReal[5 * stride] = t26 - t13;
	pImag[5 * stride] = t27 + t12;
	pReal[6 * stride] = t26 + t13;
	pImag[6 * stride] = t27 - t12;
	pReal[7 * stride] = t28 + t25;
	pImag[7 * stride] = t29 - t24;
	pReal[8 * stride] = t34 + t11;
	pImag[8 * stride] = t35 - t10;
	pReal[9 * stride] = t8 - t6;
	pImag[9 * stride] = t9 + t7;
	pReal[10 * stride] = t4 + t2;
	pImag[10 * stride] = t5 - t3;
}

template<> void StandardModule<float, 11>::Compute(float *pReal, float *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

template<> void StandardModule<double, 11>::Compute(double *pReal, double *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

}
}
