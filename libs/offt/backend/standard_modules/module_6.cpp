
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
	valueT t11, t12, t15, t16;

	phasors.Multiply(t1, t2, pReal[0 * stride], pImag[0 * stride], twiddleStart + 0 * twiddleIncrement);
	phasors.Multiply(t3, t4, pReal[1 * stride], pImag[1 * stride], twiddleStart + 1 * twiddleIncrement);
	phasors.Multiply(t5, t6, pReal[2 * stride], pImag[2 * stride], twiddleStart + 2 * twiddleIncrement);
	phasors.Multiply(t7, t8, pReal[3 * stride], pImag[3 * stride], twiddleStart + 3 * twiddleIncrement);
	phasors.Multiply(t9, t10, pReal[4 * stride], pImag[4 * stride], twiddleStart + 4 * twiddleIncrement);
	phasors.Multiply(t11, t12, pReal[5 * stride], pImag[5 * stride], twiddleStart + 5 * twiddleIncrement);

	t15 = t3 - t11;
	t16 = t4 - t12;
	t3 += t11;
	t4 += t12;
	t11 = t5 - t9;
	t12 = t6 - t10;
	t5 += t9;
	t6 += t10;
	t1 += t5;
	t2 += t6;
	t7 = t3 + t7;
	t8 = t4 + t8;
	t16 *= valueT(0.86602540378443864676);
	t15 *= valueT(0.86602540378443864676);
	t3 *= valueT(1.5);
	t4 *= valueT(1.5);
	t12 *= valueT(0.86602540378443864676);
	t11 *= valueT(0.86602540378443864676);
	t5 *= valueT(1.5);
	t6 *= valueT(1.5);
	t9 = t1 - t7;
	t10 = t2 - t8;
	t1 += t7;
	t2 += t8;
	t7 = t16 + t12;
	t8 = t15 + t11;
	t16 -= t12;
	t15 -= t11;
	t11 = t3 - t5;
	t12 = t4 - t6;
	t3 += t5;
	t4 += t6;
	t11 = t9 + t11;
	t12 = t10 + t12;
	t3 = t1 - t3;
	t4 = t2 - t4;
	pReal[0 * stride] = t1;
	pImag[0 * stride] = t2;
	pReal[1 * stride] = t11 - t7;
	pImag[1 * stride] = t12 + t8;
	pReal[2 * stride] = t3 - t16;
	pImag[2 * stride] = t4 + t15;
	pReal[3 * stride] = t9;
	pImag[3 * stride] = t10;
	pReal[4 * stride] = t3 + t16;
	pImag[4 * stride] = t4 - t15;
	pReal[5 * stride] = t11 + t7;
	pImag[5 * stride] = t12 - t8;
}

template<> void StandardModule<float, 6>::Compute(float *pReal, float *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

template<> void StandardModule<double, 6>::Compute(double *pReal, double *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

}
}
