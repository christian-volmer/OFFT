
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
	valueT t21, t22, t23, t24, t25, t26, t27, t28, t31, t32;
	valueT t33, t34, t35, t36, t37, t38, t39, t40, t41, t42;

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

	t31 = t3 - t27;
	t32 = t4 - t28;
	t3 += t27;
	t4 += t28;
	t27 = t5 - t25;
	t28 = t6 - t26;
	t5 += t25;
	t6 += t26;
	t25 = t7 - t23;
	t26 = t8 - t24;
	t7 += t23;
	t8 += t24;
	t23 = t9 - t21;
	t24 = t10 - t22;
	t9 += t21;
	t10 += t22;
	t21 = t11 - t19;
	t22 = t12 - t20;
	t11 += t19;
	t12 += t20;
	t19 = t13 - t17;
	t20 = t14 - t18;
	t13 += t17;
	t14 += t18;
	t17 = t31 + t25;
	t18 = t32 + t26;
	t31 -= t25 + t21;
	t32 -= t26 + t22;
	t33 = t3 - t7;
	t34 = t4 - t8;
	t35 = t3 + t7 + t11;
	t36 = t4 + t8 + t12;
	t3 -= t11;
	t4 -= t12;
	t37 = t27 - t23;
	t38 = t28 - t24;
	t27 += t23 - t19;
	t28 += t24 - t20;
	t39 = t5 - t9;
	t40 = t6 - t10;
	t41 = t5 + t9 + t13;
	t42 = t6 + t10 + t14;
	t5 -= t13;
	t6 -= t14;
	t25 -= t21;
	t26 -= t22;
	t7 -= t11;
	t8 -= t12;
	t23 += t19;
	t24 += t20;
	t9 -= t13;
	t10 -= t14;
	t1 += t41;
	t2 += t42;
	t11 = t17 + t25;
	t12 = t18 + t26;
	t15 = t35 + t15;
	t16 = t36 + t16;
	t13 = t37 - t23;
	t14 = t38 - t24;
	t18 *= valueT(1.4088116512993817275);
	t17 *= valueT(1.4088116512993817275);
	t12 *= valueT(0.87484229096165655223);
	t11 *= valueT(0.87484229096165655223);
	t32 *= valueT(0.44095855184409843175);
	t31 *= valueT(0.44095855184409843175);
	t33 *= valueT(0.79015646852540019719);
	t34 *= valueT(0.79015646852540019719);
	t35 *= valueT(1.1666666666666666667);
	t36 *= valueT(1.1666666666666666667);
	t3 *= valueT(0.73430220123575245957);
	t4 *= valueT(0.73430220123575245957);
	t38 *= valueT(1.2157152215855879292);
	t37 *= valueT(1.2157152215855879292);
	t14 *= valueT(0.87484229096165655223);
	t13 *= valueT(0.87484229096165655223);
	t28 *= valueT(0.44095855184409843175);
	t27 *= valueT(0.44095855184409843175);
	t39 *= valueT(0.055854267289647737622);
	t40 *= valueT(0.055854267289647737622);
	t41 *= valueT(1.1666666666666666667);
	t42 *= valueT(1.1666666666666666667);
	t5 *= valueT(0.73430220123575245957);
	t6 *= valueT(0.73430220123575245957);
	t26 *= valueT(1.2157152215855879292);
	t25 *= valueT(1.2157152215855879292);
	t7 *= valueT(0.055854267289647737622);
	t8 *= valueT(0.055854267289647737622);
	t24 *= valueT(1.4088116512993817275);
	t23 *= valueT(1.4088116512993817275);
	t9 *= valueT(0.79015646852540019719);
	t10 *= valueT(0.79015646852540019719);
	t41 = t1 - t41;
	t42 = t2 - t42;
	t18 -= t12;
	t17 -= t11;
	t12 -= t26;
	t11 -= t25;
	t35 -= t15;
	t36 -= t16;
	t38 -= t14;
	t37 -= t13;
	t14 += t24;
	t13 += t23;
	t19 = t41 + t39 + t5;
	t20 = t42 + t40 + t6;
	t39 = t41 - t39 - t9;
	t40 = t42 - t40 - t10;
	t41 -= t5 - t9;
	t42 -= t6 - t10;
	t5 = t18 - t12 - t32;
	t6 = t17 - t11 - t31;
	t18 += t32;
	t17 += t31;
	t12 -= t32;
	t11 -= t31;
	t9 = t33 + t35 - t3;
	t10 = t34 + t36 - t4;
	t33 -= t35 - t7;
	t34 -= t36 - t8;
	t35 += t3 + t7;
	t36 += t4 + t8;
	t3 = t38 - t14 - t28;
	t4 = t37 - t13 - t27;
	t38 += t28;
	t37 += t27;
	t14 -= t28;
	t13 -= t27;
	t7 = t19 - t38;
	t8 = t20 + t37;
	t19 += t38;
	t20 -= t37;
	t21 = t39 + t3;
	t22 = t40 - t4;
	t39 -= t3;
	t40 += t4;
	t3 = t41 - t14;
	t4 = t42 + t13;
	t41 += t14;
	t42 -= t13;
	t13 = t5 + t33;
	t14 = t6 - t34;
	t5 -= t33;
	t6 += t34;
	t23 = t18 - t9;
	t24 = t17 + t10;
	t18 += t9;
	t17 -= t10;
	t9 = t12 - t35;
	t10 = t11 + t36;
	t12 += t35;
	t11 -= t36;
	pReal[0 * stride] = t1 + t15;
	pImag[0 * stride] = t2 + t16;
	pReal[1 * stride] = t7 - t9;
	pImag[1 * stride] = t8 + t10;
	pReal[2 * stride] = t21 + t13;
	pImag[2 * stride] = t22 - t14;
	pReal[3 * stride] = t3 - t23;
	pImag[3 * stride] = t4 + t24;
	pReal[4 * stride] = t41 - t18;
	pImag[4 * stride] = t42 + t17;
	pReal[5 * stride] = t39 + t5;
	pImag[5 * stride] = t40 - t6;
	pReal[6 * stride] = t19 - t12;
	pImag[6 * stride] = t20 + t11;
	pReal[7 * stride] = t1 - t15;
	pImag[7 * stride] = t2 - t16;
	pReal[8 * stride] = t7 + t9;
	pImag[8 * stride] = t8 - t10;
	pReal[9 * stride] = t21 - t13;
	pImag[9 * stride] = t22 + t14;
	pReal[10 * stride] = t3 + t23;
	pImag[10 * stride] = t4 - t24;
	pReal[11 * stride] = t41 + t18;
	pImag[11 * stride] = t42 - t17;
	pReal[12 * stride] = t39 - t5;
	pImag[12 * stride] = t40 + t6;
	pReal[13 * stride] = t19 + t12;
	pImag[13 * stride] = t20 - t11;
}

template<> void StandardModule<float, 14>::Compute(float *pReal, float *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

template<> void StandardModule<double, 14>::Compute(double *pReal, double *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

}
}
