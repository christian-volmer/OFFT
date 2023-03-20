
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
	valueT t11, t12, t13, t14, t15, t16, t17, t18;

	phasors.Multiply(t1, t2, pReal[0 * stride], pImag[0 * stride], twiddleStart + 0 * twiddleIncrement);
	phasors.Multiply(t3, t4, pReal[1 * stride], pImag[1 * stride], twiddleStart + 1 * twiddleIncrement);
	phasors.Multiply(t5, t6, pReal[2 * stride], pImag[2 * stride], twiddleStart + 2 * twiddleIncrement);
	phasors.Multiply(t7, t8, pReal[3 * stride], pImag[3 * stride], twiddleStart + 3 * twiddleIncrement);
	phasors.Multiply(t9, t10, pReal[4 * stride], pImag[4 * stride], twiddleStart + 4 * twiddleIncrement);
	phasors.Multiply(t11, t12, pReal[5 * stride], pImag[5 * stride], twiddleStart + 5 * twiddleIncrement);
	phasors.Multiply(t13, t14, pReal[6 * stride], pImag[6 * stride], twiddleStart + 6 * twiddleIncrement);
	phasors.Multiply(t15, t16, pReal[7 * stride], pImag[7 * stride], twiddleStart + 7 * twiddleIncrement);

	t17 = t1 - t9;
	t18 = t2 - t10;
	t1 += t9;
	t2 += t10;
	t9 = t5 - t13;
	t10 = t6 - t14;
	t5 += t13;
	t6 += t14;
	t13 = t17 + t10;
	t14 = t18 - t9;
	t17 -= t10;
	t18 += t9;
	t9 = t1 - t5;
	t10 = t2 - t6;
	t1 += t5;
	t2 += t6;
	t5 = t3 - t11;
	t6 = t4 - t12;
	t3 += t11;
	t4 += t12;
	t11 = t7 - t15;
	t12 = t8 - t16;
	t7 += t15;
	t8 += t16;
	t15 = valueT(0.7071067811865475244) * (t5 - t6);
	t5 = valueT(0.7071067811865475244) * (t5 + t6);
	t6 = valueT(0.7071067811865475244) * (t11 + t12);
	t11 = valueT(0.7071067811865475244) * (t11 - t12);
	t12 = t15 + t6;
	t16 = t5 - t11;
	t15 -= t6;
	t5 += t11;
	t6 = t3 - t7;
	t11 = t4 - t8;
	t3 += t7;
	t4 += t8;
	pReal[0 * stride] = t1 + t3;
	pImag[0 * stride] = t2 + t4;
	pReal[1 * stride] = t17 + t15;
	pImag[1 * stride] = t18 + t5;
	pReal[2 * stride] = t9 - t11;
	pImag[2 * stride] = t10 + t6;
	pReal[3 * stride] = t13 - t16;
	pImag[3 * stride] = t14 + t12;
	pReal[4 * stride] = t1 - t3;
	pImag[4 * stride] = t2 - t4;
	pReal[5 * stride] = t17 - t15;
	pImag[5 * stride] = t18 - t5;
	pReal[6 * stride] = t9 + t11;
	pImag[6 * stride] = t10 - t6;
	pReal[7 * stride] = t13 + t16;
	pImag[7 * stride] = t14 - t12;
}

template<> void StandardModule<float, 8>::Compute(float *pReal, float *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

template<> void StandardModule<double, 8>::Compute(double *pReal, double *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

}
}
