
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
	valueT t13, t14, t15, t16;

	phasors.Multiply(t1, t2, pReal[0 * stride], pImag[0 * stride], twiddleStart + 0 * twiddleIncrement);
	phasors.Multiply(t3, t4, pReal[1 * stride], pImag[1 * stride], twiddleStart + 1 * twiddleIncrement);
	phasors.Multiply(t5, t6, pReal[2 * stride], pImag[2 * stride], twiddleStart + 2 * twiddleIncrement);
	phasors.Multiply(t7, t8, pReal[3 * stride], pImag[3 * stride], twiddleStart + 3 * twiddleIncrement);
	phasors.Multiply(t9, t10, pReal[4 * stride], pImag[4 * stride], twiddleStart + 4 * twiddleIncrement);

	t13 = t3 - t9;
	t14 = t4 - t10;
	t3 += t9;
	t4 += t10;
	t9 = t5 - t7;
	t10 = t6 - t8;
	t5 += t7;
	t6 += t8;
	t7 = t13 - t9;
	t8 = t14 - t10;
	t15 = t3 - t5;
	t16 = t4 - t6;
	t3 += t5;
	t4 += t6;
	t1 += t3;
	t2 += t4;
	t14 *= valueT(1.5388417685876267013);
	t13 *= valueT(1.5388417685876267013);
	t8 *= valueT(0.58778525229247312917);
	t7 *= valueT(0.58778525229247312917);
	t15 *= valueT(0.5590169943749474241);
	t16 *= valueT(0.5590169943749474241);
	t3 *= valueT(1.25);
	t4 *= valueT(1.25);
	t10 *= valueT(0.36327126400268044295);
	t9 *= valueT(0.36327126400268044295);
	t3 = t1 - t3;
	t4 = t2 - t4;
	t5 = t3 - t15;
	t6 = t4 - t16;
	t3 += t15;
	t4 += t16;
	t14 -= t8;
	t13 -= t7;
	t8 -= t10;
	t7 -= t9;
	pReal[0 * stride] = t1;
	pImag[0 * stride] = t2;
	pReal[1 * stride] = t3 - t14;
	pImag[1 * stride] = t4 + t13;
	pReal[2 * stride] = t5 - t8;
	pImag[2 * stride] = t6 + t7;
	pReal[3 * stride] = t5 + t8;
	pImag[3 * stride] = t6 - t7;
	pReal[4 * stride] = t3 + t14;
	pImag[4 * stride] = t4 - t13;
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
