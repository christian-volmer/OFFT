
//          Copyright Christian Volmer 2022, 2023.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include "../standard_module.h"

namespace offt {
namespace backend {

/*
	Number of additions       : 12
	Number of multiplications : 4
*/

template<> StandardModuleComplexity const StandardModule<float, 3>::Complexity = { 12, 4 };
template<> StandardModuleComplexity const StandardModule<double, 3>::Complexity = { 12, 4 };

template<typename valueT>
static void ComputeCore(valueT *pReal, valueT *pImag, ptrdiff_t stride, valueT const *twiddles)
{
	valueT t0, t1, t2, t3, t4, t5, t6, t7;

	ModuleBase<valueT>::ComplexMultiply(t0, t1, pReal[0 * stride], pImag[0 * stride], twiddles[0], twiddles[1]);
	ModuleBase<valueT>::ComplexMultiply(t2, t3, pReal[1 * stride], pImag[1 * stride], twiddles[2], twiddles[3]);
	ModuleBase<valueT>::ComplexMultiply(t4, t5, pReal[2 * stride], pImag[2 * stride], twiddles[4], twiddles[5]);

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

template<> void StandardModule<float, 3>::Compute(float *pReal, float *pImag, ptrdiff_t stride, float const *twiddles) const
{
	ComputeCore(pReal, pImag, stride, twiddles);
}

template<> void StandardModule<double, 3>::Compute(double *pReal, double *pImag, ptrdiff_t stride, double const *twiddles) const
{
	ComputeCore(pReal, pImag, stride, twiddles);
}

}
}
