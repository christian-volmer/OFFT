
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
	Number of additions       : 72
	Number of multiplications : 16
*/

template<> StandardModuleComplexity const StandardModule<float, 7>::Complexity = { 72, 16 };
template<> StandardModuleComplexity const StandardModule<double, 7>::Complexity = { 72, 16 };

template<typename valueT>
static void ComputeCore(Phasors<valueT> const &phasors, valueT *pReal, valueT *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement)
{
	valueT t0, t1, t2, t3, t4, t5, t6, t7, t8, t9;
	valueT t10, t11, t12, t13, t14, t15, t16, t17, t18, t19;

	phasors.Multiply(t0, t1, pReal[0 * stride], pImag[0 * stride], twiddleStart + 0 * twiddleIncrement);
	phasors.Multiply(t2, t3, pReal[1 * stride], pImag[1 * stride], twiddleStart + 1 * twiddleIncrement);
	phasors.Multiply(t4, t5, pReal[2 * stride], pImag[2 * stride], twiddleStart + 2 * twiddleIncrement);
	phasors.Multiply(t6, t7, pReal[3 * stride], pImag[3 * stride], twiddleStart + 3 * twiddleIncrement);
	phasors.Multiply(t8, t9, pReal[4 * stride], pImag[4 * stride], twiddleStart + 4 * twiddleIncrement);
	phasors.Multiply(t10, t11, pReal[5 * stride], pImag[5 * stride], twiddleStart + 5 * twiddleIncrement);
	phasors.Multiply(t12, t13, pReal[6 * stride], pImag[6 * stride], twiddleStart + 6 * twiddleIncrement);

	t14 = t2 - t12;
	t15 = t3 - t13;
	t2 += t12;
	t3 += t13;
	t12 = t4 - t10;
	t13 = t5 - t11;
	t4 += t10;
	t5 += t11;
	t10 = t6 - t8;
	t11 = t7 - t9;
	t6 += t8;
	t7 += t9;
	t8 = t14 - t12;
	t9 = t15 - t13;
	t14 += t12 - t10;
	t15 += t13 - t11;
	t16 = t2 - t4;
	t17 = t3 - t5;
	t18 = t2 + t4 + t6;
	t19 = t3 + t5 + t7;
	t2 -= t6;
	t3 -= t7;
	t12 += t10;
	t13 += t11;
	t4 -= t6;
	t5 -= t7;
	t0 += t18;
	t1 += t19;
	t6 = t8 - t12;
	t7 = t9 - t13;
	t9 *= valueT(1.2157152215855879292);
	t8 *= valueT(1.2157152215855879292);
	t7 *= valueT(0.87484229096165655223);
	t6 *= valueT(0.87484229096165655223);
	t15 *= valueT(0.44095855184409843175);
	t14 *= valueT(0.44095855184409843175);
	t16 *= valueT(0.055854267289647737622);
	t17 *= valueT(0.055854267289647737622);
	t18 *= valueT(1.1666666666666666667);
	t19 *= valueT(1.1666666666666666667);
	t2 *= valueT(0.73430220123575245957);
	t3 *= valueT(0.73430220123575245957);
	t13 *= valueT(1.4088116512993817275);
	t12 *= valueT(1.4088116512993817275);
	t4 *= valueT(0.79015646852540019719);
	t5 *= valueT(0.79015646852540019719);
	t18 = t0 - t18;
	t19 = t1 - t19;
	t9 -= t7;
	t8 -= t6;
	t7 += t13;
	t6 += t12;
	t10 = t18 + t16 + t2;
	t11 = t19 + t17 + t3;
	t16 = t18 - t16 - t4;
	t17 = t19 - t17 - t5;
	t18 -= t2 - t4;
	t19 -= t3 - t5;
	t2 = t9 - t7 - t15;
	t3 = t8 - t6 - t14;
	t9 += t15;
	t8 += t14;
	t7 -= t15;
	t6 -= t14;
	pReal[0 * stride] = t0;
	pImag[0 * stride] = t1;
	pReal[1 * stride] = t10 - t9;
	pImag[1 * stride] = t11 + t8;
	pReal[2 * stride] = t16 + t2;
	pImag[2 * stride] = t17 - t3;
	pReal[3 * stride] = t18 - t7;
	pImag[3 * stride] = t19 + t6;
	pReal[4 * stride] = t18 + t7;
	pImag[4 * stride] = t19 - t6;
	pReal[5 * stride] = t16 - t2;
	pImag[5 * stride] = t17 + t3;
	pReal[6 * stride] = t10 + t9;
	pImag[6 * stride] = t11 - t8;
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
