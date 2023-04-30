
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
	Number of additions       : 36
	Number of multiplications : 8
*/

template<> StandardModuleComplexity const StandardModule<float, 6>::Complexity = { 36, 8 };
template<> StandardModuleComplexity const StandardModule<double, 6>::Complexity = { 36, 8 };

template<typename valueT>
static void ComputeCore(Phasors<valueT> const &phasors, valueT *pReal, valueT *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement)
{
	valueT t0, t1, t2, t3, t4, t5, t6, t7, t8, t9;
	valueT t10, t11, t12, t13;

	phasors.Multiply(t0, t1, pReal[0 * stride], pImag[0 * stride], twiddleStart + 0 * twiddleIncrement);
	phasors.Multiply(t2, t3, pReal[1 * stride], pImag[1 * stride], twiddleStart + 1 * twiddleIncrement);
	phasors.Multiply(t4, t5, pReal[2 * stride], pImag[2 * stride], twiddleStart + 2 * twiddleIncrement);
	phasors.Multiply(t6, t7, pReal[3 * stride], pImag[3 * stride], twiddleStart + 3 * twiddleIncrement);
	phasors.Multiply(t8, t9, pReal[4 * stride], pImag[4 * stride], twiddleStart + 4 * twiddleIncrement);
	phasors.Multiply(t10, t11, pReal[5 * stride], pImag[5 * stride], twiddleStart + 5 * twiddleIncrement);

	t12 = t2 - t10;
	t13 = t3 - t11;
	t2 += t10;
	t3 += t11;
	t10 = t4 - t8;
	t11 = t5 - t9;
	t4 += t8;
	t5 += t9;
	t0 += t4;
	t1 += t5;
	t6 = t2 + t6;
	t7 = t3 + t7;
	t13 *= valueT(0.86602540378443864676);
	t12 *= valueT(0.86602540378443864676);
	t2 *= valueT(1.5);
	t3 *= valueT(1.5);
	t11 *= valueT(0.86602540378443864676);
	t10 *= valueT(0.86602540378443864676);
	t4 *= valueT(1.5);
	t5 *= valueT(1.5);
	t8 = t0 - t6;
	t9 = t1 - t7;
	t0 += t6;
	t1 += t7;
	t6 = t13 + t11;
	t7 = t12 + t10;
	t13 -= t11;
	t12 -= t10;
	t10 = t2 - t4;
	t11 = t3 - t5;
	t2 += t4;
	t3 += t5;
	t10 = t8 + t10;
	t11 = t9 + t11;
	t2 = t0 - t2;
	t3 = t1 - t3;
	pReal[0 * stride] = t0;
	pImag[0 * stride] = t1;
	pReal[1 * stride] = t10 - t6;
	pImag[1 * stride] = t11 + t7;
	pReal[2 * stride] = t2 - t13;
	pImag[2 * stride] = t3 + t12;
	pReal[3 * stride] = t8;
	pImag[3 * stride] = t9;
	pReal[4 * stride] = t2 + t13;
	pImag[4 * stride] = t3 - t12;
	pReal[5 * stride] = t10 + t6;
	pImag[5 * stride] = t11 - t7;
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
