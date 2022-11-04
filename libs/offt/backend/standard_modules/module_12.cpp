
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
	valueT t21, t22, t23, t24, t27, t28;

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

	t27 = t3 - t11;
	t28 = t4 - t12;
	t3 += t11;
	t4 += t12;
	t11 = t5 - t21;
	t12 = t6 - t22;
	t5 += t21;
	t6 += t22;
	t21 = t9 - t17;
	t22 = t10 - t18;
	t9 += t17;
	t10 += t18;
	t17 = t15 - t23;
	t18 = t16 - t24;
	t15 += t23;
	t16 += t24;
	t1 += t9;
	t2 += t10;
	t19 = t3 + t19;
	t20 = t4 + t20;
	t13 = t5 + t13;
	t14 = t6 + t14;
	t7 += t15;
	t8 += t16;
	t23 = t1 - t13;
	t24 = t2 - t14;
	t1 += t13;
	t2 += t14;
	t13 = t27 - t17;
	t14 = t28 - t18;
	t27 += t17;
	t28 += t18;
	t17 = t3 - t15;
	t18 = t4 - t16;
	t3 += t15;
	t4 += t16;
	t15 = t19 - t7;
	t16 = t20 - t8;
	t19 += t7;
	t20 += t8;
	t7 = t11 - t21;
	t8 = t12 - t22;
	t11 += t21;
	t12 += t22;
	t21 = t5 - t9;
	t22 = t6 - t10;
	t5 += t9;
	t6 += t10;
	t13 *= valueT(0.86602540378443864676);
	t14 *= valueT(0.86602540378443864676);
	t28 *= valueT(0.86602540378443864676);
	t27 *= valueT(0.86602540378443864676);
	t18 *= valueT(1.5);
	t17 *= valueT(1.5);
	t3 *= valueT(1.5);
	t4 *= valueT(1.5);
	t8 *= valueT(0.86602540378443864676);
	t7 *= valueT(0.86602540378443864676);
	t12 *= valueT(0.86602540378443864676);
	t11 *= valueT(0.86602540378443864676);
	t21 *= valueT(1.5);
	t22 *= valueT(1.5);
	t5 *= valueT(1.5);
	t6 *= valueT(1.5);
	t21 = t23 + t21;
	t22 = t24 + t22;
	t5 = t1 - t5;
	t6 = t2 - t6;
	t18 -= t16;
	t17 -= t15;
	t3 -= t19;
	t4 -= t20;
	t9 = t21 + t12;
	t10 = t22 - t11;
	t21 -= t12;
	t22 += t11;
	t11 = t5 - t8;
	t12 = t6 + t7;
	t5 += t8;
	t6 -= t7;
	t7 = t13 + t18;
	t8 = t14 - t17;
	t13 -= t18;
	t14 += t17;
	t17 = t28 - t3;
	t18 = t27 + t4;
	t28 += t3;
	t27 -= t4;
	pReal[0 * stride] = t1 + t19;
	pImag[0 * stride] = t2 + t20;
	pReal[1 * stride] = t21 + t13;
	pImag[1 * stride] = t22 + t14;
	pReal[2 * stride] = t11 - t17;
	pImag[2 * stride] = t12 + t18;
	pReal[3 * stride] = t23 - t16;
	pImag[3 * stride] = t24 + t15;
	pReal[4 * stride] = t5 - t28;
	pImag[4 * stride] = t6 + t27;
	pReal[5 * stride] = t9 - t7;
	pImag[5 * stride] = t10 - t8;
	pReal[6 * stride] = t1 - t19;
	pImag[6 * stride] = t2 - t20;
	pReal[7 * stride] = t21 - t13;
	pImag[7 * stride] = t22 - t14;
	pReal[8 * stride] = t11 + t17;
	pImag[8 * stride] = t12 - t18;
	pReal[9 * stride] = t23 + t16;
	pImag[9 * stride] = t24 - t15;
	pReal[10 * stride] = t5 + t28;
	pImag[10 * stride] = t6 - t27;
	pReal[11 * stride] = t9 + t7;
	pImag[11 * stride] = t10 + t8;
}

template<> void StandardModule<float, 12>::Compute(float *pReal, float *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

template<> void StandardModule<double, 12>::Compute(double *pReal, double *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

}
}
