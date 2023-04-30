
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
	valueT t10, t11, t12, t13;

	phasors.Multiply(t0, t1, pReal[0 * stride], pImag[0 * stride], twiddleStart + 0 * twiddleIncrement);
	phasors.Multiply(t2, t3, pReal[1 * stride], pImag[1 * stride], twiddleStart + 1 * twiddleIncrement);
	phasors.Multiply(t4, t5, pReal[2 * stride], pImag[2 * stride], twiddleStart + 2 * twiddleIncrement);
	phasors.Multiply(t6, t7, pReal[3 * stride], pImag[3 * stride], twiddleStart + 3 * twiddleIncrement);
	phasors.Multiply(t8, t9, pReal[4 * stride], pImag[4 * stride], twiddleStart + 4 * twiddleIncrement);

	t10 = t2 - t8;
	t11 = t3 - t9;
	t2 += t8;
	t3 += t9;
	t8 = t4 - t6;
	t9 = t5 - t7;
	t4 += t6;
	t5 += t7;
	t6 = t10 - t8;
	t7 = t11 - t9;
	t12 = t2 - t4;
	t13 = t3 - t5;
	t2 += t4;
	t3 += t5;
	t0 += t2;
	t1 += t3;
	t11 *= valueT(1.5388417685876267013);
	t10 *= valueT(1.5388417685876267013);
	t7 *= valueT(0.58778525229247312917);
	t6 *= valueT(0.58778525229247312917);
	t12 *= valueT(0.5590169943749474241);
	t13 *= valueT(0.5590169943749474241);
	t2 *= valueT(1.25);
	t3 *= valueT(1.25);
	t9 *= valueT(0.36327126400268044295);
	t8 *= valueT(0.36327126400268044295);
	t2 = t0 - t2;
	t3 = t1 - t3;
	t4 = t2 - t12;
	t5 = t3 - t13;
	t2 += t12;
	t3 += t13;
	t11 -= t7;
	t10 -= t6;
	t7 -= t9;
	t6 -= t8;
	pReal[0 * stride] = t0;
	pImag[0 * stride] = t1;
	pReal[1 * stride] = t2 - t11;
	pImag[1 * stride] = t3 + t10;
	pReal[2 * stride] = t4 - t7;
	pImag[2 * stride] = t5 + t6;
	pReal[3 * stride] = t4 + t7;
	pImag[3 * stride] = t5 - t6;
	pReal[4 * stride] = t2 + t11;
	pImag[4 * stride] = t3 - t10;
}

template<> void StandardModule<float, 5>::Compute(float *pReal, float *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

template<> void StandardModule<double, 5>::Compute(double *pReal, double *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

}
}
