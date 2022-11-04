
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
	valueT t11, t12, t13, t14, t15, t16, t17, t18, t25, t26;

	phasors.Multiply(t1, t2, pReal[0 * stride], pImag[0 * stride], twiddleStart + 0 * twiddleIncrement);
	phasors.Multiply(t3, t4, pReal[1 * stride], pImag[1 * stride], twiddleStart + 1 * twiddleIncrement);
	phasors.Multiply(t5, t6, pReal[2 * stride], pImag[2 * stride], twiddleStart + 2 * twiddleIncrement);
	phasors.Multiply(t7, t8, pReal[3 * stride], pImag[3 * stride], twiddleStart + 3 * twiddleIncrement);
	phasors.Multiply(t9, t10, pReal[4 * stride], pImag[4 * stride], twiddleStart + 4 * twiddleIncrement);
	phasors.Multiply(t11, t12, pReal[5 * stride], pImag[5 * stride], twiddleStart + 5 * twiddleIncrement);
	phasors.Multiply(t13, t14, pReal[6 * stride], pImag[6 * stride], twiddleStart + 6 * twiddleIncrement);
	phasors.Multiply(t15, t16, pReal[7 * stride], pImag[7 * stride], twiddleStart + 7 * twiddleIncrement);
	phasors.Multiply(t17, t18, pReal[8 * stride], pImag[8 * stride], twiddleStart + 8 * twiddleIncrement);

	t25 = t7 - t13;
	t26 = t8 - t14;
	t7 += t13;
	t8 += t14;
	t13 = t9 - t15;
	t14 = t10 - t16;
	t9 += t15;
	t10 += t16;
	t15 = t11 - t17;
	t16 = t12 - t18;
	t11 += t17;
	t12 += t18;
	t1 += t7;
	t2 += t8;
	t3 += t9;
	t4 += t10;
	t5 += t11;
	t6 += t12;
	t26 *= valueT(0.86602540378443864676);
	t25 *= valueT(0.86602540378443864676);
	t7 *= valueT(1.5);
	t8 *= valueT(1.5);
	t14 *= valueT(0.86602540378443864676);
	t13 *= valueT(0.86602540378443864676);
	t9 *= valueT(1.5);
	t10 *= valueT(1.5);
	t16 *= valueT(0.86602540378443864676);
	t15 *= valueT(0.86602540378443864676);
	t11 *= valueT(1.5);
	t12 *= valueT(1.5);
	t7 = t1 - t7;
	t8 = t2 - t8;
	t9 = t3 - t9;
	t10 = t4 - t10;
	t11 = t5 - t11;
	t12 = t6 - t12;
	t17 = t7 + t26;
	t18 = t8 - t25;
	t7 -= t26;
	t8 += t25;
	t25 = t9 + t14;
	t26 = t10 - t13;
	t9 -= t14;
	t10 += t13;
	t13 = t11 + t16;
	t14 = t12 - t15;
	t11 -= t16;
	t12 += t15;
	t15 = valueT(0.17364817766693034885) * t25 - valueT(0.98480775301220805937) * t26;
	t25 = valueT(0.98480775301220805937) * t25 + valueT(0.17364817766693034885) * t26;
	t16 = valueT(0.7660444431189780352) * t9 - valueT(0.64278760968653932632) * t10;
	t9 = valueT(0.64278760968653932632) * t9 + valueT(0.7660444431189780352) * t10;
	t10 = valueT(0.93969262078590838405) * t13 + valueT(0.34202014332566873304) * t14;
	t13 = valueT(0.34202014332566873304) * t13 - valueT(0.93969262078590838405) * t14;
	t14 = valueT(0.17364817766693034885) * t11 - valueT(0.98480775301220805937) * t12;
	t11 = valueT(0.98480775301220805937) * t11 + valueT(0.17364817766693034885) * t12;
	t12 = t3 - t5;
	t26 = t4 - t6;
	t3 += t5;
	t4 += t6;
	t5 = t15 + t10;
	t6 = t25 - t13;
	t15 -= t10;
	t25 += t13;
	t10 = t16 - t14;
	t13 = t9 - t11;
	t16 += t14;
	t9 += t11;
	t1 += t3;
	t2 += t4;
	t17 += t15;
	t18 += t25;
	t7 += t16;
	t8 += t9;
	t26 *= valueT(0.86602540378443864676);
	t12 *= valueT(0.86602540378443864676);
	t3 *= valueT(1.5);
	t4 *= valueT(1.5);
	t6 *= valueT(0.86602540378443864676);
	t5 *= valueT(0.86602540378443864676);
	t15 *= valueT(1.5);
	t25 *= valueT(1.5);
	t13 *= valueT(0.86602540378443864676);
	t10 *= valueT(0.86602540378443864676);
	t16 *= valueT(1.5);
	t9 *= valueT(1.5);
	t3 = t1 - t3;
	t4 = t2 - t4;
	t15 = t17 - t15;
	t25 = t18 - t25;
	t16 = t7 - t16;
	t9 = t8 - t9;
	t11 = t3 + t26;
	t14 = t4 - t12;
	t3 -= t26;
	t4 += t12;
	t12 = t15 + t6;
	t26 = t25 - t5;
	t15 -= t6;
	t25 += t5;
	t5 = t16 + t13;
	t6 = t9 - t10;
	t16 -= t13;
	t9 += t10;
	pReal[0 * stride] = t1;
	pImag[0 * stride] = t2;
	pReal[1 * stride] = t7;
	pImag[1 * stride] = t8;
	pReal[2 * stride] = t17;
	pImag[2 * stride] = t18;
	pReal[3 * stride] = t3;
	pImag[3 * stride] = t4;
	pReal[4 * stride] = t16;
	pImag[4 * stride] = t9;
	pReal[5 * stride] = t15;
	pImag[5 * stride] = t25;
	pReal[6 * stride] = t11;
	pImag[6 * stride] = t14;
	pReal[7 * stride] = t5;
	pImag[7 * stride] = t6;
	pReal[8 * stride] = t12;
	pImag[8 * stride] = t26;
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
