
//          Copyright Christian Volmer 2022, 2023.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include "../standard_module.h"

namespace offt {
namespace backend {

/*
	Number of additions       : 196
	Number of multiplications : 80
*/

template<> StandardModuleComplexity const StandardModule<float, 18>::Complexity = { 196, 80 };
template<> StandardModuleComplexity const StandardModule<double, 18>::Complexity = { 196, 80 };

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
	phasors.Multiply(t30, t31, pReal[15 * stride], pImag[15 * stride], twiddleStart + 15 * twiddleIncrement);
	phasors.Multiply(t32, t33, pReal[16 * stride], pImag[16 * stride], twiddleStart + 16 * twiddleIncrement);
	phasors.Multiply(t34, t35, pReal[17 * stride], pImag[17 * stride], twiddleStart + 17 * twiddleIncrement);

	t36 = t2 - t14;
	t37 = t3 - t15;
	t2 += t14;
	t3 += t15;
	t14 = t6 - t30;
	t15 = t7 - t31;
	t6 += t30;
	t7 += t31;
	t30 = t10 - t34;
	t31 = t11 - t35;
	t10 += t34;
	t11 += t35;
	t34 = t12 - t24;
	t35 = t13 - t25;
	t12 += t24;
	t13 += t25;
	t24 = t16 - t28;
	t25 = t17 - t29;
	t16 += t28;
	t17 += t29;
	t28 = t20 - t32;
	t29 = t21 - t33;
	t20 += t32;
	t21 += t33;
	t0 += t12;
	t1 += t13;
	t26 = t2 + t26;
	t27 = t3 + t27;
	t4 += t16;
	t5 += t17;
	t18 = t6 + t18;
	t19 = t7 + t19;
	t8 += t20;
	t9 += t21;
	t22 = t10 + t22;
	t23 = t11 + t23;
	t37 *= valueT(0.86602540378443864676);
	t36 *= valueT(0.86602540378443864676);
	t2 *= valueT(1.5);
	t3 *= valueT(1.5);
	t15 *= valueT(0.86602540378443864676);
	t14 *= valueT(0.86602540378443864676);
	t6 *= valueT(1.5);
	t7 *= valueT(1.5);
	t31 *= valueT(0.86602540378443864676);
	t30 *= valueT(0.86602540378443864676);
	t10 *= valueT(1.5);
	t11 *= valueT(1.5);
	t35 *= valueT(0.86602540378443864676);
	t34 *= valueT(0.86602540378443864676);
	t12 *= valueT(1.5);
	t13 *= valueT(1.5);
	t25 *= valueT(0.86602540378443864676);
	t24 *= valueT(0.86602540378443864676);
	t16 *= valueT(1.5);
	t17 *= valueT(1.5);
	t29 *= valueT(0.86602540378443864676);
	t28 *= valueT(0.86602540378443864676);
	t20 *= valueT(1.5);
	t21 *= valueT(1.5);
	t12 = t0 - t12;
	t13 = t1 - t13;
	t2 -= t26;
	t3 -= t27;
	t16 = t4 - t16;
	t17 = t5 - t17;
	t6 -= t18;
	t7 -= t19;
	t20 = t8 - t20;
	t21 = t9 - t21;
	t10 -= t22;
	t11 -= t23;
	t32 = t12 + t35;
	t33 = t13 - t34;
	t12 -= t35;
	t13 += t34;
	t34 = t37 - t2;
	t35 = t36 + t3;
	t37 += t2;
	t36 -= t3;
	t2 = t16 + t25;
	t3 = t17 - t24;
	t16 -= t25;
	t17 += t24;
	t24 = t15 + t6;
	t25 = t14 - t7;
	t15 -= t6;
	t14 += t7;
	t6 = t20 + t29;
	t7 = t21 - t28;
	t20 -= t29;
	t21 += t28;
	t28 = t31 + t10;
	t29 = t30 - t11;
	t31 -= t10;
	t30 += t11;
	t10 = valueT(0.93969262078590838405) * t34 - valueT(0.34202014332566873304) * t35;
	t34 = valueT(0.34202014332566873304) * t34 + valueT(0.93969262078590838405) * t35;
	t11 = valueT(0.17364817766693034885) * t37 + valueT(0.98480775301220805937) * t36;
	t37 = valueT(0.98480775301220805937) * t37 - valueT(0.17364817766693034885) * t36;
	t35 = valueT(0.17364817766693034885) * t2 - valueT(0.98480775301220805937) * t3;
	t2 = valueT(0.98480775301220805937) * t2 + valueT(0.17364817766693034885) * t3;
	t3 = valueT(0.7660444431189780352) * t16 - valueT(0.64278760968653932632) * t17;
	t16 = valueT(0.64278760968653932632) * t16 + valueT(0.7660444431189780352) * t17;
	t17 = valueT(0.93969262078590838405) * t6 + valueT(0.34202014332566873304) * t7;
	t6 = valueT(0.34202014332566873304) * t6 - valueT(0.93969262078590838405) * t7;
	t7 = valueT(0.17364817766693034885) * t20 - valueT(0.98480775301220805937) * t21;
	t20 = valueT(0.98480775301220805937) * t20 + valueT(0.17364817766693034885) * t21;
	t21 = valueT(0.17364817766693034885) * t28 + valueT(0.98480775301220805937) * t29;
	t28 = valueT(0.98480775301220805937) * t28 - valueT(0.17364817766693034885) * t29;
	t29 = valueT(0.7660444431189780352) * t31 + valueT(0.64278760968653932632) * t30;
	t31 = valueT(0.64278760968653932632) * t31 - valueT(0.7660444431189780352) * t30;
	t30 = t10 - t21;
	t36 = t34 + t28;
	t10 += t21;
	t34 -= t28;
	t21 = t11 + t29;
	t28 = t37 + t31;
	t11 -= t29;
	t37 -= t31;
	t29 = t26 - t22;
	t31 = t27 - t23;
	t26 += t22;
	t27 += t23;
	t22 = t4 - t8;
	t23 = t5 - t9;
	t4 += t8;
	t5 += t9;
	t8 = t35 + t17;
	t9 = t2 - t6;
	t35 -= t17;
	t2 += t6;
	t6 = t3 - t7;
	t17 = t16 - t20;
	t3 += t7;
	t16 += t20;
	t0 += t4;
	t1 += t5;
	t32 += t35;
	t33 += t2;
	t12 += t3;
	t13 += t16;
	t24 = t10 + t24;
	t25 = t34 + t25;
	t15 = t11 - t15;
	t14 = t37 + t14;
	t18 = t26 + t18;
	t19 = t27 + t19;
	t36 *= valueT(0.86602540378443864676);
	t30 *= valueT(0.86602540378443864676);
	t10 *= valueT(1.5);
	t34 *= valueT(1.5);
	t28 *= valueT(0.86602540378443864676);
	t21 *= valueT(0.86602540378443864676);
	t11 *= valueT(1.5);
	t37 *= valueT(1.5);
	t31 *= valueT(0.86602540378443864676);
	t29 *= valueT(0.86602540378443864676);
	t26 *= valueT(1.5);
	t27 *= valueT(1.5);
	t23 *= valueT(0.86602540378443864676);
	t22 *= valueT(0.86602540378443864676);
	t4 *= valueT(1.5);
	t5 *= valueT(1.5);
	t9 *= valueT(0.86602540378443864676);
	t8 *= valueT(0.86602540378443864676);
	t35 *= valueT(1.5);
	t2 *= valueT(1.5);
	t17 *= valueT(0.86602540378443864676);
	t6 *= valueT(0.86602540378443864676);
	t3 *= valueT(1.5);
	t16 *= valueT(1.5);
	t7 = t0 - t18;
	t20 = t1 - t19;
	t0 += t18;
	t1 += t19;
	t18 = t32 + t24;
	t19 = t33 - t25;
	t32 -= t24;
	t33 += t25;
	t24 = t12 + t15;
	t25 = t13 + t14;
	t12 -= t15;
	t13 -= t14;
	t14 = t36 + t9;
	t15 = t30 - t8;
	t36 -= t9;
	t30 += t8;
	t8 = t10 + t35;
	t9 = t34 - t2;
	t10 -= t35;
	t34 += t2;
	t2 = t28 - t17;
	t35 = t21 - t6;
	t28 += t17;
	t21 += t6;
	t6 = t11 + t3;
	t17 = t37 + t16;
	t11 -= t3;
	t37 -= t16;
	t3 = t31 + t23;
	t16 = t29 + t22;
	t31 -= t23;
	t29 -= t22;
	t22 = t26 - t4;
	t23 = t27 - t5;
	t26 += t4;
	t27 += t5;
	t22 = t7 + t22;
	t23 = t20 + t23;
	t26 = t0 - t26;
	t27 = t1 - t27;
	t8 = t18 - t8;
	t9 = t19 + t9;
	t10 = t32 + t10;
	t34 = t33 - t34;
	t6 = t24 - t6;
	t17 = t25 - t17;
	t11 = t12 + t11;
	t37 = t13 + t37;
	pReal[0 * stride] = t0;
	pImag[0 * stride] = t1;
	pReal[1 * stride] = t24;
	pImag[1 * stride] = t25;
	pReal[2 * stride] = t32;
	pImag[2 * stride] = t33;
	pReal[3 * stride] = t22 - t3;
	pImag[3 * stride] = t23 + t16;
	pReal[4 * stride] = t11 - t28;
	pImag[4 * stride] = t37 + t21;
	pReal[5 * stride] = t8 - t14;
	pImag[5 * stride] = t9 - t15;
	pReal[6 * stride] = t26 - t31;
	pImag[6 * stride] = t27 + t29;
	pReal[7 * stride] = t6 - t2;
	pImag[7 * stride] = t17 + t35;
	pReal[8 * stride] = t10 - t36;
	pImag[8 * stride] = t34 - t30;
	pReal[9 * stride] = t7;
	pImag[9 * stride] = t20;
	pReal[10 * stride] = t12;
	pImag[10 * stride] = t13;
	pReal[11 * stride] = t18;
	pImag[11 * stride] = t19;
	pReal[12 * stride] = t26 + t31;
	pImag[12 * stride] = t27 - t29;
	pReal[13 * stride] = t6 + t2;
	pImag[13 * stride] = t17 - t35;
	pReal[14 * stride] = t10 + t36;
	pImag[14 * stride] = t34 + t30;
	pReal[15 * stride] = t22 + t3;
	pImag[15 * stride] = t23 - t16;
	pReal[16 * stride] = t11 + t28;
	pImag[16 * stride] = t37 - t21;
	pReal[17 * stride] = t8 + t14;
	pImag[17 * stride] = t9 + t15;
}

template<> void StandardModule<float, 18>::Compute(float *pReal, float *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

template<> void StandardModule<double, 18>::Compute(double *pReal, double *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

}
}
