
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
	valueT t23, t24, t25, t26, t27, t28;

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

	t23 = t3 - t19;
	t24 = t4 - t20;
	t3 += t19;
	t4 += t20;
	t19 = t5 - t17;
	t20 = t6 - t18;
	t5 += t17;
	t6 += t18;
	t17 = t7 - t15;
	t18 = t8 - t16;
	t7 += t15;
	t8 += t16;
	t15 = t9 - t13;
	t16 = t10 - t14;
	t9 += t13;
	t10 += t14;
	t13 = t23 - t17;
	t14 = t24 - t18;
	t25 = t3 - t7;
	t26 = t4 - t8;
	t3 += t7;
	t4 += t8;
	t7 = t19 - t15;
	t8 = t20 - t16;
	t27 = t5 - t9;
	t28 = t6 - t10;
	t5 += t9;
	t6 += t10;
	t1 += t5;
	t2 += t6;
	t11 = t3 + t11;
	t12 = t4 + t12;
	t24 *= valueT(0.36327126400268044295);
	t23 *= valueT(0.36327126400268044295);
	t14 *= valueT(0.58778525229247312917);
	t13 *= valueT(0.58778525229247312917);
	t25 *= valueT(0.5590169943749474241);
	t26 *= valueT(0.5590169943749474241);
	t3 *= valueT(1.25);
	t4 *= valueT(1.25);
	t20 *= valueT(1.5388417685876267013);
	t19 *= valueT(1.5388417685876267013);
	t8 *= valueT(0.58778525229247312917);
	t7 *= valueT(0.58778525229247312917);
	t27 *= valueT(0.5590169943749474241);
	t28 *= valueT(0.5590169943749474241);
	t5 *= valueT(1.25);
	t6 *= valueT(1.25);
	t18 *= valueT(1.5388417685876267013);
	t17 *= valueT(1.5388417685876267013);
	t16 *= valueT(0.36327126400268044295);
	t15 *= valueT(0.36327126400268044295);
	t5 = t1 - t5;
	t6 = t2 - t6;
	t3 -= t11;
	t4 -= t12;
	t9 = t5 - t27;
	t10 = t6 - t28;
	t5 += t27;
	t6 += t28;
	t24 += t14;
	t23 += t13;
	t14 += t18;
	t13 += t17;
	t17 = t25 - t3;
	t18 = t26 - t4;
	t25 += t3;
	t26 += t4;
	t20 -= t8;
	t19 -= t7;
	t8 -= t16;
	t7 -= t15;
	t3 = t9 + t8;
	t4 = t10 - t7;
	t9 -= t8;
	t10 += t7;
	t7 = t5 + t20;
	t8 = t6 - t19;
	t5 -= t20;
	t6 += t19;
	t15 = t24 + t17;
	t16 = t23 - t18;
	t24 -= t17;
	t23 += t18;
	t17 = t14 + t25;
	t18 = t13 - t26;
	t14 -= t25;
	t13 += t26;
	pReal[0 * stride] = t1 + t11;
	pImag[0 * stride] = t2 + t12;
	pReal[1 * stride] = t5 - t14;
	pImag[1 * stride] = t6 + t13;
	pReal[2 * stride] = t9 - t24;
	pImag[2 * stride] = t10 + t23;
	pReal[3 * stride] = t3 - t15;
	pImag[3 * stride] = t4 + t16;
	pReal[4 * stride] = t7 - t17;
	pImag[4 * stride] = t8 + t18;
	pReal[5 * stride] = t1 - t11;
	pImag[5 * stride] = t2 - t12;
	pReal[6 * stride] = t5 + t14;
	pImag[6 * stride] = t6 - t13;
	pReal[7 * stride] = t9 + t24;
	pImag[7 * stride] = t10 - t23;
	pReal[8 * stride] = t3 + t15;
	pImag[8 * stride] = t4 - t16;
	pReal[9 * stride] = t7 + t17;
	pImag[9 * stride] = t8 - t18;
}

template<> void StandardModule<float, 10>::Compute(float *pReal, float *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

template<> void StandardModule<double, 10>::Compute(double *pReal, double *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

}
}
