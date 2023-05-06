
//          Copyright Christian Volmer 2022, 2023.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include "../standard_module.h"

namespace offt {
namespace backend {

/*
	Number of additions       : 36
	Number of multiplications : 8
*/

template<> StandardModuleComplexity const StandardModule<float, 6>::Complexity = { 36, 8 };
template<> StandardModuleComplexity const StandardModule<double, 6>::Complexity = { 36, 8 };

template<typename valueT>
static void ComputeCore(valueT *pReal, valueT *pImag, ptrdiff_t stride, valueT const *twiddles)
{
	valueT t0, t1, t2, t3, t4, t5, t6, t7, t8, t9;
	valueT t10, t11, t12, t13;

	ModuleBase<valueT>::ComplexMultiply(t0, t1, pReal[0 * stride], pImag[0 * stride], twiddles[0], twiddles[1]);
	ModuleBase<valueT>::ComplexMultiply(t2, t3, pReal[1 * stride], pImag[1 * stride], twiddles[2], twiddles[3]);
	ModuleBase<valueT>::ComplexMultiply(t4, t5, pReal[2 * stride], pImag[2 * stride], twiddles[4], twiddles[5]);
	ModuleBase<valueT>::ComplexMultiply(t6, t7, pReal[3 * stride], pImag[3 * stride], twiddles[6], twiddles[7]);
	ModuleBase<valueT>::ComplexMultiply(t8, t9, pReal[4 * stride], pImag[4 * stride], twiddles[8], twiddles[9]);
	ModuleBase<valueT>::ComplexMultiply(t10, t11, pReal[5 * stride], pImag[5 * stride], twiddles[10], twiddles[11]);

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

template<> void StandardModule<float, 6>::Compute(float *pReal, float *pImag, ptrdiff_t stride, float const *twiddles) const
{
	ComputeCore(pReal, pImag, stride, twiddles);
}

template<> void StandardModule<double, 6>::Compute(double *pReal, double *pImag, ptrdiff_t stride, double const *twiddles) const
{
	ComputeCore(pReal, pImag, stride, twiddles);
}

}
}
