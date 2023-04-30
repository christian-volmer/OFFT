
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
	Number of additions       : 188
	Number of multiplications : 40
*/

template<> StandardModuleComplexity const StandardModule<float, 13>::Complexity = { 188, 40 };
template<> StandardModuleComplexity const StandardModule<double, 13>::Complexity = { 188, 40 };

template<typename valueT>
static void ComputeCore(Phasors<valueT> const &phasors, valueT *pReal, valueT *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement)
{
	valueT t0, t1, t2, t3, t4, t5, t6, t7, t8, t9;
	valueT t10, t11, t12, t13, t14, t15, t16, t17, t18, t19;
	valueT t20, t21, t22, t23, t24, t25, t26, t27, t28, t29;
	valueT t30, t31, t32, t33, t34, t35, t36, t37, t38, t39;
	valueT t40, t41;

	phasors.Multiply(t0, t1, pReal[0 * stride], pImag[0 * stride], twiddleStart + 0 * twiddleIncrement);
	phasors.Multiply(t2, t3, pReal[1 * stride], pImag[1 * stride], twiddleStart + 1 * twiddleIncrement);
	phasors.Multiply(t4, t5, pReal[2 * stride], pImag[2 * stride], twiddleStart + 2 * twiddleIncrement);
	phasors.Multiply(t6, t7, pReal[3 * stride], pImag[3 * stride], twiddleStart + 3 * twiddleIncrement);
	phasors.Multiply(t8, t9, pReal[4 * stride], pImag[4 * stride], twiddleStart + 4 * twiddleIncrement);
	phasors.Multiply(t10, t11, pReal[5 * stride], pImag[5 * stride], twiddleStart + 5 * twiddleIncrement);
	phasors.Multiply(t12, t13, pReal[6 * stride], pImag[6 * stride], twiddleStart + 6 * twiddleIncrement);
	phasors.Multiply(t14, t15, pReal[7 * stride], pImag[7 * stride], twiddleStart + 7 * twiddleIncrement);
	phasors.Multiply(t16, t17, pReal[8 * stride], pImag[8 * stride], twiddleStart + 8 * twiddleIncrement);
	phasors.Multiply(t18, t19, pReal[9 * stride], pImag[9 * stride], twiddleStart + 9 * twiddleIncrement);
	phasors.Multiply(t20, t21, pReal[10 * stride], pImag[10 * stride], twiddleStart + 10 * twiddleIncrement);
	phasors.Multiply(t22, t23, pReal[11 * stride], pImag[11 * stride], twiddleStart + 11 * twiddleIncrement);
	phasors.Multiply(t24, t25, pReal[12 * stride], pImag[12 * stride], twiddleStart + 12 * twiddleIncrement);

	t26 = t2 - t24;
	t27 = t3 - t25;
	t2 += t24;
	t3 += t25;
	t24 = t4 - t22;
	t25 = t5 - t23;
	t4 += t22;
	t5 += t23;
	t22 = t6 - t20;
	t23 = t7 - t21;
	t6 += t20;
	t7 += t21;
	t20 = t8 - t18;
	t21 = t9 - t19;
	t8 += t18;
	t9 += t19;
	t18 = t10 - t16;
	t19 = t11 - t17;
	t10 += t16;
	t11 += t17;
	t16 = t12 - t14;
	t17 = t13 - t15;
	t12 += t14;
	t13 += t15;
	t14 = t26 - t22;
	t15 = t27 - t23;
	t26 += t22 - t20;
	t27 += t23 - t21;
	t28 = t2 - t10;
	t29 = t3 - t11;
	t2 += t10;
	t3 += t11;
	t10 = t24 + t18 + t16;
	t11 = t25 + t19 + t17;
	t24 -= t16;
	t25 -= t17;
	t30 = t4 - t6;
	t31 = t5 - t7;
	t4 += t6;
	t5 += t7;
	t22 += t20;
	t23 += t21;
	t6 = t8 - t12;
	t7 = t9 - t13;
	t8 += t12;
	t9 += t13;
	t18 -= t16;
	t19 -= t17;
	t12 = t14 - t22;
	t13 = t15 - t23;
	t16 = t26 - t10;
	t17 = t27 - t11;
	t20 = t28 - t30 + t6;
	t21 = t29 - t31 + t7;
	t28 -= t6;
	t29 -= t7;
	t32 = t2 - t4;
	t33 = t3 - t5;
	t34 = t2 + t4 + t8;
	t35 = t3 + t5 + t9;
	t2 -= t8;
	t3 -= t9;
	t36 = t24 + t18;
	t37 = t25 + t19;
	t30 += t6;
	t31 += t7;
	t4 -= t8;
	t5 -= t9;
	t0 += t34;
	t1 += t35;
	t6 = t14 - t24;
	t7 = t15 - t25;
	t8 = t12 - t36;
	t9 = t13 - t37;
	t38 = t28 - t30;
	t39 = t29 - t31;
	t40 = t22 + t18;
	t41 = t23 + t19;
	t15 *= valueT(1.5596006223820445613);
	t14 *= valueT(1.5596006223820445613);
	t7 *= valueT(0.1598612076528611922);
	t6 *= valueT(0.1598612076528611922);
	t13 *= valueT(1.0211729150707586474);
	t12 *= valueT(1.0211729150707586474);
	t9 *= valueT(0.087981928766792081008);
	t8 *= valueT(0.087981928766792081008);
	t27 *= valueT(0.74927933062613902637);
	t26 *= valueT(0.74927933062613902637);
	t17 *= valueT(0.57514072947400312137);
	t16 *= valueT(0.57514072947400312137);
	t20 *= valueT(0.30046260628866577443);
	t21 *= valueT(0.30046260628866577443);
	t28 *= valueT(1.0407474201500718718);
	t29 *= valueT(1.0407474201500718718);
	t38 *= valueT(0.52422663952658214901);
	t39 *= valueT(0.52422663952658214901);
	t32 *= valueT(0.42763404682657276126);
	t33 *= valueT(0.42763404682657276126);
	t34 *= valueT(1.0833333333333333333);
	t35 *= valueT(1.0833333333333333333);
	t2 *= valueT(0.57944001890096049323);
	t3 *= valueT(0.57944001890096049323);
	t11 *= valueT(0.40100212832186721636);
	t10 *= valueT(0.40100212832186721636);
	t25 *= valueT(2.0875863244363300084);
	t24 *= valueT(2.0875863244363300084);
	t37 *= valueT(0.73058834417912600679);
	t36 *= valueT(0.73058834417912600679);
	t30 *= valueT(0.53193249842967457518);
	t31 *= valueT(0.53193249842967457518);
	t4 *= valueT(0.15180597207438773197);
	t5 *= valueT(0.15180597207438773197);
	t23 *= valueT(1.503918122830231381);
	t22 *= valueT(1.503918122830231381);
	t41 *= valueT(0.42380699395323743523);
	t40 *= valueT(0.42380699395323743523);
	t19 *= valueT(0.10417870810104801192);
	t18 *= valueT(0.10417870810104801192);
	t34 = t0 - t34;
	t35 = t1 - t35;
	t15 -= t7;
	t14 -= t6;
	t7 += t25;
	t6 += t24;
	t13 += t9;
	t12 += t8;
	t9 -= t37;
	t8 -= t36;
	t28 -= t38;
	t29 -= t39;
	t38 += t30;
	t39 += t31;
	t23 += t41;
	t22 += t40;
	t41 += t19;
	t40 += t18;
	t18 = t34 - t32 + t2;
	t19 = t35 - t33 + t3;
	t32 = t34 + t32 - t4;
	t33 = t35 + t33 - t5;
	t34 -= t2 - t4;
	t35 -= t3 - t5;
	t15 -= t13;
	t14 -= t12;
	t7 += t9;
	t6 += t8;
	t13 += t23;
	t12 += t22;
	t9 += t41;
	t8 += t40;
	t27 -= t17;
	t26 -= t16;
	t17 += t11;
	t16 += t10;
	t2 = t20 + t28;
	t3 = t21 + t29;
	t28 = t20 - t28 + t38;
	t29 = t21 - t29 + t39;
	t20 -= t38;
	t21 -= t39;
	t4 = t18 - t2;
	t5 = t19 - t3;
	t18 += t2;
	t19 += t3;
	t2 = t32 - t20;
	t3 = t33 - t21;
	t32 += t20;
	t33 += t21;
	t10 = t34 - t28;
	t11 = t35 - t29;
	t34 += t28;
	t35 += t29;
	t20 = t15 - t13 - t27;
	t21 = t14 - t12 - t26;
	t15 += t27;
	t14 += t26;
	t22 = t7 + t9 - t17;
	t23 = t6 + t8 - t16;
	t7 += t17;
	t6 += t16;
	t13 -= t27;
	t12 -= t26;
	t9 += t17;
	t8 += t16;
	pReal[0 * stride] = t0;
	pImag[0 * stride] = t1;
	pReal[1 * stride] = t18 - t15;
	pImag[1 * stride] = t19 + t14;
	pReal[2 * stride] = t2 - t7;
	pImag[2 * stride] = t3 + t6;
	pReal[3 * stride] = t32 + t20;
	pImag[3 * stride] = t33 - t21;
	pReal[4 * stride] = t34 - t13;
	pImag[4 * stride] = t35 + t12;
	pReal[5 * stride] = t4 - t9;
	pImag[5 * stride] = t5 + t8;
	pReal[6 * stride] = t10 + t22;
	pImag[6 * stride] = t11 - t23;
	pReal[7 * stride] = t10 - t22;
	pImag[7 * stride] = t11 + t23;
	pReal[8 * stride] = t4 + t9;
	pImag[8 * stride] = t5 - t8;
	pReal[9 * stride] = t34 + t13;
	pImag[9 * stride] = t35 - t12;
	pReal[10 * stride] = t32 - t20;
	pImag[10 * stride] = t33 + t21;
	pReal[11 * stride] = t2 + t7;
	pImag[11 * stride] = t3 - t6;
	pReal[12 * stride] = t18 + t15;
	pImag[12 * stride] = t19 - t14;
}

template<> void StandardModule<float, 13>::Compute(float *pReal, float *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

template<> void StandardModule<double, 13>::Compute(double *pReal, double *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

}
}
