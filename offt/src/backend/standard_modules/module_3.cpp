
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
	valueT t0, t1, t2, t3, t4, t5, t6, t7;

	phasors.Multiply(t0, t1, pReal[0 * stride], pImag[0 * stride], twiddleStart + 0 * twiddleIncrement);
	phasors.Multiply(t2, t3, pReal[1 * stride], pImag[1 * stride], twiddleStart + 1 * twiddleIncrement);
	phasors.Multiply(t4, t5, pReal[2 * stride], pImag[2 * stride], twiddleStart + 2 * twiddleIncrement);

	t6 = t2 - t4;
	t7 = t3 - t5;
	t2 += t4;
	t3 += t5;
	t0 += t2;
	t1 += t3;
	t7 *= valueT(0.86602540378443864676);
	t6 *= valueT(0.86602540378443864676);
	t2 *= valueT(1.5);
	t3 *= valueT(1.5);
	t2 = t0 - t2;
	t3 = t1 - t3;
	pReal[0 * stride] = t0;
	pImag[0 * stride] = t1;
	pReal[1 * stride] = t2 - t7;
	pImag[1 * stride] = t3 + t6;
	pReal[2 * stride] = t2 + t7;
	pImag[2 * stride] = t3 - t6;
}

template<> void StandardModule<float, 3>::Compute(float *pReal, float *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

template<> void StandardModule<double, 3>::Compute(double *pReal, double *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

}
}
