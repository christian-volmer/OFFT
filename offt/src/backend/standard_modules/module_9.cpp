
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
	Number of additions       : 80
	Number of multiplications : 40
*/

template<> StandardModuleComplexity const StandardModule<float, 9>::Complexity = { 80, 40 };
template<> StandardModuleComplexity const StandardModule<double, 9>::Complexity = { 80, 40 };

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
	phasors.Multiply(t14, t15, pReal[7 * stride], pImag[7 * stride], twiddleStart + 7 * twiddleIncrement);
	phasors.Multiply(t16, t17, pReal[8 * stride], pImag[8 * stride], twiddleStart + 8 * twiddleIncrement);

	t18 = t6 - t12;
	t19 = t7 - t13;
	t6 += t12;
	t7 += t13;
	t12 = t8 - t14;
	t13 = t9 - t15;
	t8 += t14;
	t9 += t15;
	t14 = t10 - t16;
	t15 = t11 - t17;
	t10 += t16;
	t11 += t17;
	t0 += t6;
	t1 += t7;
	t2 += t8;
	t3 += t9;
	t4 += t10;
	t5 += t11;
	t19 *= valueT(0.86602540378443864676);
	t18 *= valueT(0.86602540378443864676);
	t6 *= valueT(1.5);
	t7 *= valueT(1.5);
	t13 *= valueT(0.86602540378443864676);
	t12 *= valueT(0.86602540378443864676);
	t8 *= valueT(1.5);
	t9 *= valueT(1.5);
	t15 *= valueT(0.86602540378443864676);
	t14 *= valueT(0.86602540378443864676);
	t10 *= valueT(1.5);
	t11 *= valueT(1.5);
	t6 = t0 - t6;
	t7 = t1 - t7;
	t8 = t2 - t8;
	t9 = t3 - t9;
	t10 = t4 - t10;
	t11 = t5 - t11;
	t16 = t6 + t19;
	t17 = t7 - t18;
	t6 -= t19;
	t7 += t18;
	t18 = t8 + t13;
	t19 = t9 - t12;
	t8 -= t13;
	t9 += t12;
	t12 = t10 + t15;
	t13 = t11 - t14;
	t10 -= t15;
	t11 += t14;
	t14 = valueT(0.17364817766693034885) * t18 - valueT(0.98480775301220805937) * t19;
	t18 = valueT(0.98480775301220805937) * t18 + valueT(0.17364817766693034885) * t19;
	t15 = valueT(0.7660444431189780352) * t8 - valueT(0.64278760968653932632) * t9;
	t8 = valueT(0.64278760968653932632) * t8 + valueT(0.7660444431189780352) * t9;
	t9 = valueT(0.93969262078590838405) * t12 + valueT(0.34202014332566873304) * t13;
	t12 = valueT(0.34202014332566873304) * t12 - valueT(0.93969262078590838405) * t13;
	t13 = valueT(0.17364817766693034885) * t10 - valueT(0.98480775301220805937) * t11;
	t10 = valueT(0.98480775301220805937) * t10 + valueT(0.17364817766693034885) * t11;
	t11 = t2 - t4;
	t19 = t3 - t5;
	t2 += t4;
	t3 += t5;
	t4 = t14 + t9;
	t5 = t18 - t12;
	t14 -= t9;
	t18 += t12;
	t9 = t15 - t13;
	t12 = t8 - t10;
	t15 += t13;
	t8 += t10;
	t0 += t2;
	t1 += t3;
	t16 += t14;
	t17 += t18;
	t6 += t15;
	t7 += t8;
	t19 *= valueT(0.86602540378443864676);
	t11 *= valueT(0.86602540378443864676);
	t2 *= valueT(1.5);
	t3 *= valueT(1.5);
	t5 *= valueT(0.86602540378443864676);
	t4 *= valueT(0.86602540378443864676);
	t14 *= valueT(1.5);
	t18 *= valueT(1.5);
	t12 *= valueT(0.86602540378443864676);
	t9 *= valueT(0.86602540378443864676);
	t15 *= valueT(1.5);
	t8 *= valueT(1.5);
	t2 = t0 - t2;
	t3 = t1 - t3;
	t14 = t16 - t14;
	t18 = t17 - t18;
	t15 = t6 - t15;
	t8 = t7 - t8;
	t10 = t2 + t19;
	t13 = t3 - t11;
	t2 -= t19;
	t3 += t11;
	t11 = t14 + t5;
	t19 = t18 - t4;
	t14 -= t5;
	t18 += t4;
	t4 = t15 + t12;
	t5 = t8 - t9;
	t15 -= t12;
	t8 += t9;
	pReal[0 * stride] = t0;
	pImag[0 * stride] = t1;
	pReal[1 * stride] = t6;
	pImag[1 * stride] = t7;
	pReal[2 * stride] = t16;
	pImag[2 * stride] = t17;
	pReal[3 * stride] = t2;
	pImag[3 * stride] = t3;
	pReal[4 * stride] = t15;
	pImag[4 * stride] = t8;
	pReal[5 * stride] = t14;
	pImag[5 * stride] = t18;
	pReal[6 * stride] = t10;
	pImag[6 * stride] = t13;
	pReal[7 * stride] = t4;
	pImag[7 * stride] = t5;
	pReal[8 * stride] = t11;
	pImag[8 * stride] = t19;
}

template<> void StandardModule<float, 9>::Compute(float *pReal, float *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

template<> void StandardModule<double, 9>::Compute(double *pReal, double *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

}
}
