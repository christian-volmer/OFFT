
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
	valueT t21, t22, t25, t26, t27, t28, t29, t30, t31, t32;
	valueT t33, t34, t35, t36, t37, t38, t39, t40, t41, t42;
	valueT t43, t44;

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

	t25 = t3 - t21;
	t26 = t4 - t22;
	t3 += t21;
	t4 += t22;
	t21 = t5 - t19;
	t22 = t6 - t20;
	t5 += t19;
	t6 += t20;
	t19 = t7 - t17;
	t20 = t8 - t18;
	t7 += t17;
	t8 += t18;
	t17 = t9 - t15;
	t18 = t10 - t16;
	t9 += t15;
	t10 += t16;
	t15 = t11 - t13;
	t16 = t12 - t14;
	t11 += t13;
	t12 += t14;
	t13 = t25 - t21 + t19 + t17 + t15;
	t14 = t26 - t22 + t20 + t18 + t16;
	t27 = t25 - t17;
	t28 = t26 - t18;
	t25 -= t15;
	t26 -= t16;
	t29 = t3 + t5 + t7 + t9 + t11;
	t30 = t4 + t6 + t8 + t10 + t12;
	t31 = t3 - t9;
	t32 = t4 - t10;
	t3 -= t11;
	t4 -= t12;
	t33 = t21 + t19;
	t34 = t22 + t20;
	t21 += t15;
	t22 += t16;
	t35 = t5 - t7;
	t36 = t6 - t8;
	t5 -= t11;
	t6 -= t12;
	t19 -= t15;
	t20 -= t16;
	t7 -= t11;
	t8 -= t12;
	t17 -= t15;
	t18 -= t16;
	t9 -= t11;
	t10 -= t12;
	t1 += t29;
	t2 += t30;
	t11 = t27 - t33;
	t12 = t28 - t34;
	t15 = t25 - t21;
	t16 = t26 - t22;
	t37 = t31 - t35;
	t38 = t32 - t36;
	t39 = t3 - t5;
	t40 = t4 - t6;
	t41 = t19 + t17;
	t42 = t20 + t18;
	t43 = t7 - t9;
	t44 = t8 - t10;
	t14 *= valueT(0.33166247903553998491);
	t13 *= valueT(0.33166247903553998491);
	t28 *= valueT(0.2340718675266744486);
	t27 *= valueT(0.2340718675266744486);
	t12 *= valueT(0.65815896284539274746);
	t11 *= valueT(0.65815896284539274746);
	t26 *= valueT(1.2162009452834415049);
	t25 *= valueT(1.2162009452834415049);
	t16 *= valueT(0.58313551154466560886);
	t15 *= valueT(0.58313551154466560886);
	t29 *= valueT(1.1);
	t30 *= valueT(1.1);
	t31 *= valueT(0.5971755722185702045);
	t32 *= valueT(0.5971755722185702045);
	t37 *= valueT(0.042314838273285140444);
	t38 *= valueT(0.042314838273285140444);
	t3 *= valueT(0.85949297361449738989);
	t4 *= valueT(0.85949297361449738989);
	t39 *= valueT(0.47310017472860128509);
	t40 *= valueT(0.47310017472860128509);
	t34 *= valueT(0.70808888503950303466);
	t33 *= valueT(0.70808888503950303466);
	t22 *= valueT(0.95729268466927362052);
	t21 *= valueT(0.95729268466927362052);
	t35 *= valueT(0.90180781188778253033);
	t36 *= valueT(0.90180781188778253033);
	t5 *= valueT(0.94125353283118116886);
	t6 *= valueT(0.94125353283118116886);
	t20 *= valueT(2.1583616978496189882);
	t19 *= valueT(2.1583616978496189882);
	t42 *= valueT(0.86713730126545034466);
	t41 *= valueT(0.86713730126545034466);
	t7 *= valueT(0.55486073394528506406);
	t8 *= valueT(0.55486073394528506406);
	t43 *= valueT(0.89893869455789602842);
	t44 *= valueT(0.89893869455789602842);
	t18 *= valueT(0.492980128140842333);
	t17 *= valueT(0.492980128140842333);
	t9 *= valueT(0.51541501300188642553);
	t10 *= valueT(0.51541501300188642553);
	t29 = t1 - t29;
	t30 = t2 - t30;
	t28 -= t12;
	t27 -= t11;
	t12 += t34;
	t11 += t33;
	t26 -= t16;
	t25 -= t15;
	t16 += t22;
	t15 += t21;
	t31 -= t37;
	t32 -= t38;
	t37 += t35;
	t38 += t36;
	t3 -= t39;
	t4 -= t40;
	t39 -= t5;
	t40 -= t6;
	t20 -= t42;
	t19 -= t41;
	t42 -= t18;
	t41 -= t17;
	t7 -= t43;
	t8 -= t44;
	t43 -= t9;
	t44 -= t10;
	t5 = t29 + t31 + t3;
	t6 = t30 + t32 + t4;
	t31 = t29 - t31 + t43;
	t32 = t30 - t32 + t44;
	t9 = t29 + t37 + t39;
	t10 = t30 + t38 + t40;
	t37 = t29 - t37 + t7;
	t38 = t30 - t38 + t8;
	t29 -= t3 + t39 + t7 + t43;
	t30 -= t4 + t40 + t8 + t44;
	t3 = t14 + t28 + t26;
	t4 = t13 + t27 + t25;
	t28 = t14 - t28 + t42;
	t27 = t13 - t27 + t41;
	t7 = t14 - t12 - t16;
	t8 = t13 - t11 - t15;
	t12 = t14 + t12 - t20;
	t11 = t13 + t11 - t19;
	t14 -= t26 - t16 - t20 + t42;
	t13 -= t25 - t15 - t19 + t41;
	pReal[0 * stride] = t1;
	pImag[0 * stride] = t2;
	pReal[1 * stride] = t5 - t3;
	pImag[1 * stride] = t6 + t4;
	pReal[2 * stride] = t9 + t7;
	pImag[2 * stride] = t10 - t8;
	pReal[3 * stride] = t37 - t12;
	pImag[3 * stride] = t38 + t11;
	pReal[4 * stride] = t31 - t28;
	pImag[4 * stride] = t32 + t27;
	pReal[5 * stride] = t29 - t14;
	pImag[5 * stride] = t30 + t13;
	pReal[6 * stride] = t29 + t14;
	pImag[6 * stride] = t30 - t13;
	pReal[7 * stride] = t31 + t28;
	pImag[7 * stride] = t32 - t27;
	pReal[8 * stride] = t37 + t12;
	pImag[8 * stride] = t38 - t11;
	pReal[9 * stride] = t9 - t7;
	pImag[9 * stride] = t10 + t8;
	pReal[10 * stride] = t5 + t3;
	pImag[10 * stride] = t6 - t4;
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
