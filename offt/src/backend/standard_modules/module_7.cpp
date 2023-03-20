
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
	valueT t11, t12, t13, t14, t17, t18, t19, t20, t21, t22;

	phasors.Multiply(t1, t2, pReal[0 * stride], pImag[0 * stride], twiddleStart + 0 * twiddleIncrement);
	phasors.Multiply(t3, t4, pReal[1 * stride], pImag[1 * stride], twiddleStart + 1 * twiddleIncrement);
	phasors.Multiply(t5, t6, pReal[2 * stride], pImag[2 * stride], twiddleStart + 2 * twiddleIncrement);
	phasors.Multiply(t7, t8, pReal[3 * stride], pImag[3 * stride], twiddleStart + 3 * twiddleIncrement);
	phasors.Multiply(t9, t10, pReal[4 * stride], pImag[4 * stride], twiddleStart + 4 * twiddleIncrement);
	phasors.Multiply(t11, t12, pReal[5 * stride], pImag[5 * stride], twiddleStart + 5 * twiddleIncrement);
	phasors.Multiply(t13, t14, pReal[6 * stride], pImag[6 * stride], twiddleStart + 6 * twiddleIncrement);

	t17 = t3 - t13;
	t18 = t4 - t14;
	t3 += t13;
	t4 += t14;
	t13 = t5 - t11;
	t14 = t6 - t12;
	t5 += t11;
	t6 += t12;
	t11 = t7 - t9;
	t12 = t8 - t10;
	t7 += t9;
	t8 += t10;
	t9 = t17 - t13;
	t10 = t18 - t14;
	t17 += t13 - t11;
	t18 += t14 - t12;
	t19 = t3 - t5;
	t20 = t4 - t6;
	t21 = t3 + t5 + t7;
	t22 = t4 + t6 + t8;
	t3 -= t7;
	t4 -= t8;
	t13 += t11;
	t14 += t12;
	t5 -= t7;
	t6 -= t8;
	t1 += t21;
	t2 += t22;
	t7 = t9 - t13;
	t8 = t10 - t14;
	t10 *= valueT(1.2157152215855879292);
	t9 *= valueT(1.2157152215855879292);
	t8 *= valueT(0.87484229096165655223);
	t7 *= valueT(0.87484229096165655223);
	t18 *= valueT(0.44095855184409843175);
	t17 *= valueT(0.44095855184409843175);
	t19 *= valueT(0.055854267289647737622);
	t20 *= valueT(0.055854267289647737622);
	t21 *= valueT(1.1666666666666666667);
	t22 *= valueT(1.1666666666666666667);
	t3 *= valueT(0.73430220123575245957);
	t4 *= valueT(0.73430220123575245957);
	t14 *= valueT(1.4088116512993817275);
	t13 *= valueT(1.4088116512993817275);
	t5 *= valueT(0.79015646852540019719);
	t6 *= valueT(0.79015646852540019719);
	t21 = t1 - t21;
	t22 = t2 - t22;
	t10 -= t8;
	t9 -= t7;
	t8 += t14;
	t7 += t13;
	t11 = t21 + t19 + t3;
	t12 = t22 + t20 + t4;
	t19 = t21 - t19 - t5;
	t20 = t22 - t20 - t6;
	t21 -= t3 - t5;
	t22 -= t4 - t6;
	t3 = t10 - t8 - t18;
	t4 = t9 - t7 - t17;
	t10 += t18;
	t9 += t17;
	t8 -= t18;
	t7 -= t17;
	pReal[0 * stride] = t1;
	pImag[0 * stride] = t2;
	pReal[1 * stride] = t11 - t10;
	pImag[1 * stride] = t12 + t9;
	pReal[2 * stride] = t19 + t3;
	pImag[2 * stride] = t20 - t4;
	pReal[3 * stride] = t21 - t8;
	pImag[3 * stride] = t22 + t7;
	pReal[4 * stride] = t21 + t8;
	pImag[4 * stride] = t22 - t7;
	pReal[5 * stride] = t19 - t3;
	pImag[5 * stride] = t20 + t4;
	pReal[6 * stride] = t11 + t10;
	pImag[6 * stride] = t12 - t9;
}

template<> void StandardModule<float, 7>::Compute(float *pReal, float *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

template<> void StandardModule<double, 7>::Compute(double *pReal, double *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

}
}
