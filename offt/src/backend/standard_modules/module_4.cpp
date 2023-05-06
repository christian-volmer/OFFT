
//          Copyright Christian Volmer 2022, 2023.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include "../standard_module.h"

namespace offt {
namespace backend {

/*
	Number of additions       : 16
	Number of multiplications : 0
*/

template<> StandardModuleComplexity const StandardModule<float, 4>::Complexity = { 16, 0 };
template<> StandardModuleComplexity const StandardModule<double, 4>::Complexity = { 16, 0 };

template<typename valueT>
static void ComputeCore(valueT *pReal, valueT *pImag, ptrdiff_t stride, valueT const *twiddles)
{
	valueT t0, t1, t2, t3, t4, t5, t6, t7, t8, t9;

	ModuleBase<valueT>::ComplexMultiply(t0, t1, pReal[0 * stride], pImag[0 * stride], twiddles[0], twiddles[1]);
	ModuleBase<valueT>::ComplexMultiply(t2, t3, pReal[1 * stride], pImag[1 * stride], twiddles[2], twiddles[3]);
	ModuleBase<valueT>::ComplexMultiply(t4, t5, pReal[2 * stride], pImag[2 * stride], twiddles[4], twiddles[5]);
	ModuleBase<valueT>::ComplexMultiply(t6, t7, pReal[3 * stride], pImag[3 * stride], twiddles[6], twiddles[7]);

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

template<> void StandardModule<float, 4>::Compute(float *pReal, float *pImag, ptrdiff_t stride, float const *twiddles) const
{
	ComputeCore(pReal, pImag, stride, twiddles);
}

template<> void StandardModule<double, 4>::Compute(double *pReal, double *pImag, ptrdiff_t stride, double const *twiddles) const
{
	ComputeCore(pReal, pImag, stride, twiddles);
}

}
}
