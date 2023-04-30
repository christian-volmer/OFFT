
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
	valueT t0, t1, t2, t3, t4, t5, t6, t7, t8, t9;

	phasors.Multiply(t0, t1, pReal[0 * stride], pImag[0 * stride], twiddleStart + 0 * twiddleIncrement);
	phasors.Multiply(t2, t3, pReal[1 * stride], pImag[1 * stride], twiddleStart + 1 * twiddleIncrement);
	phasors.Multiply(t4, t5, pReal[2 * stride], pImag[2 * stride], twiddleStart + 2 * twiddleIncrement);
	phasors.Multiply(t6, t7, pReal[3 * stride], pImag[3 * stride], twiddleStart + 3 * twiddleIncrement);

	t8 = t0 - t4;
	t9 = t1 - t5;
	t0 += t4;
	t1 += t5;
	t4 = t2 - t6;
	t5 = t3 - t7;
	t2 += t6;
	t3 += t7;
	t6 = t8 + t5;
	t7 = t9 - t4;
	t8 -= t5;
	t9 += t4;
	t4 = t0 - t2;
	t5 = t1 - t3;
	t0 += t2;
	t1 += t3;
	pReal[0 * stride] = t0;
	pImag[0 * stride] = t1;
	pReal[1 * stride] = t8;
	pImag[1 * stride] = t9;
	pReal[2 * stride] = t4;
	pImag[2 * stride] = t5;
	pReal[3 * stride] = t6;
	pImag[3 * stride] = t7;
}

template<> void StandardModule<float, 4>::Compute(float *pReal, float *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

template<> void StandardModule<double, 4>::Compute(double *pReal, double *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

}
}
