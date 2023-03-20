
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
	valueT t11, t12, t13, t14, t15, t16, t17, t18, t19, t20;
	valueT t21, t22, t23, t24, t25, t26, t29, t30, t31, t32;
	valueT t33, t34, t35, t36, t37, t38, t39, t40, t41, t42;
	valueT t43, t44;

	phasors.Multiply(t1, t2, pReal[0 * stride], pImag[0 * stride], twiddleStart + 0 * twiddleIncrement);
	phasors.Multiply(t3, t4, pReal[1 * stride], pImag[1 * stride], twiddleStart + 1 * twiddleIncrement);
	phasors.Multiply(t5, t6, pReal[2 * stride], pImag[2 * stride], twiddleStart + 2 * twiddleIncrement);
	phasors.Multiply(t7, t8, pReal[3 * stride], pImag[3 * stride], twiddleStart + 3 * twiddleIncrement);
	phasors.Multiply(t9, t10, pReal[4 * stride], pImag[4 * stride], twiddleStart + 4 * twiddleIncrement);
	phasors.Multiply(t11, t12, pReal[5 * stride], pImag[5 * stride], twiddleStart + 5 * twiddleIncrement);
	phasors.Multiply(t13, t14, pReal[6 * stride], pImag[6 * stride], twiddleStart + 6 * twiddleIncrement);
	phasors.Multiply(t15, t16, pReal[7 * stride], pImag[7 * stride], twiddleStart + 7 * twiddleIncrement);
	phasors.Multiply(t17, t18, pReal[8 * stride], pImag[8 * stride], twiddleStart + 8 * twiddleIncrement);
	phasors.Multiply(t19, t20, pReal[9 * stride], pImag[9 * stride], twiddleStart + 9 * twiddleIncrement);
	phasors.Multiply(t21, t22, pReal[10 * stride], pImag[10 * stride], twiddleStart + 10 * twiddleIncrement);
	phasors.Multiply(t23, t24, pReal[11 * stride], pImag[11 * stride], twiddleStart + 11 * twiddleIncrement);
	phasors.Multiply(t25, t26, pReal[12 * stride], pImag[12 * stride], twiddleStart + 12 * twiddleIncrement);

	t29 = t3 - t25;
	t30 = t4 - t26;
	t3 += t25;
	t4 += t26;
	t25 = t5 - t23;
	t26 = t6 - t24;
	t5 += t23;
	t6 += t24;
	t23 = t7 - t21;
	t24 = t8 - t22;
	t7 += t21;
	t8 += t22;
	t21 = t9 - t19;
	t22 = t10 - t20;
	t9 += t19;
	t10 += t20;
	t19 = t11 - t17;
	t20 = t12 - t18;
	t11 += t17;
	t12 += t18;
	t17 = t13 - t15;
	t18 = t14 - t16;
	t13 += t15;
	t14 += t16;
	t15 = t29 - t23;
	t16 = t30 - t24;
	t29 += t23 - t21;
	t30 += t24 - t22;
	t31 = t3 - t11;
	t32 = t4 - t12;
	t3 += t11;
	t4 += t12;
	t11 = t25 + t19 + t17;
	t12 = t26 + t20 + t18;
	t25 -= t17;
	t26 -= t18;
	t33 = t5 - t7;
	t34 = t6 - t8;
	t5 += t7;
	t6 += t8;
	t23 += t21;
	t24 += t22;
	t7 = t9 - t13;
	t8 = t10 - t14;
	t9 += t13;
	t10 += t14;
	t19 -= t17;
	t20 -= t18;
	t13 = t15 - t23;
	t14 = t16 - t24;
	t17 = t29 - t11;
	t18 = t30 - t12;
	t21 = t31 - t33 + t7;
	t22 = t32 - t34 + t8;
	t31 -= t7;
	t32 -= t8;
	t35 = t3 - t5;
	t36 = t4 - t6;
	t37 = t3 + t5 + t9;
	t38 = t4 + t6 + t10;
	t3 -= t9;
	t4 -= t10;
	t39 = t25 + t19;
	t40 = t26 + t20;
	t33 += t7;
	t34 += t8;
	t5 -= t9;
	t6 -= t10;
	t1 += t37;
	t2 += t38;
	t7 = t15 - t25;
	t8 = t16 - t26;
	t9 = t13 - t39;
	t10 = t14 - t40;
	t41 = t31 - t33;
	t42 = t32 - t34;
	t43 = t23 + t19;
	t44 = t24 + t20;
	t16 *= valueT(1.5596006223820445613);
	t15 *= valueT(1.5596006223820445613);
	t8 *= valueT(0.1598612076528611922);
	t7 *= valueT(0.1598612076528611922);
	t14 *= valueT(1.0211729150707586474);
	t13 *= valueT(1.0211729150707586474);
	t10 *= valueT(0.087981928766792081008);
	t9 *= valueT(0.087981928766792081008);
	t30 *= valueT(0.74927933062613902637);
	t29 *= valueT(0.74927933062613902637);
	t18 *= valueT(0.57514072947400312137);
	t17 *= valueT(0.57514072947400312137);
	t21 *= valueT(0.30046260628866577443);
	t22 *= valueT(0.30046260628866577443);
	t31 *= valueT(1.0407474201500718718);
	t32 *= valueT(1.0407474201500718718);
	t41 *= valueT(0.52422663952658214901);
	t42 *= valueT(0.52422663952658214901);
	t35 *= valueT(0.42763404682657276126);
	t36 *= valueT(0.42763404682657276126);
	t37 *= valueT(1.0833333333333333333);
	t38 *= valueT(1.0833333333333333333);
	t3 *= valueT(0.57944001890096049323);
	t4 *= valueT(0.57944001890096049323);
	t12 *= valueT(0.40100212832186721636);
	t11 *= valueT(0.40100212832186721636);
	t26 *= valueT(2.0875863244363300084);
	t25 *= valueT(2.0875863244363300084);
	t40 *= valueT(0.73058834417912600679);
	t39 *= valueT(0.73058834417912600679);
	t33 *= valueT(0.53193249842967457518);
	t34 *= valueT(0.53193249842967457518);
	t5 *= valueT(0.15180597207438773197);
	t6 *= valueT(0.15180597207438773197);
	t24 *= valueT(1.503918122830231381);
	t23 *= valueT(1.503918122830231381);
	t44 *= valueT(0.42380699395323743523);
	t43 *= valueT(0.42380699395323743523);
	t20 *= valueT(0.10417870810104801192);
	t19 *= valueT(0.10417870810104801192);
	t37 = t1 - t37;
	t38 = t2 - t38;
	t16 -= t8;
	t15 -= t7;
	t8 += t26;
	t7 += t25;
	t14 += t10;
	t13 += t9;
	t10 -= t40;
	t9 -= t39;
	t31 -= t41;
	t32 -= t42;
	t41 += t33;
	t42 += t34;
	t24 += t44;
	t23 += t43;
	t44 += t20;
	t43 += t19;
	t19 = t37 - t35 + t3;
	t20 = t38 - t36 + t4;
	t35 = t37 + t35 - t5;
	t36 = t38 + t36 - t6;
	t37 -= t3 - t5;
	t38 -= t4 - t6;
	t16 -= t14;
	t15 -= t13;
	t8 += t10;
	t7 += t9;
	t14 += t24;
	t13 += t23;
	t10 += t44;
	t9 += t43;
	t30 -= t18;
	t29 -= t17;
	t18 += t12;
	t17 += t11;
	t3 = t21 + t31;
	t4 = t22 + t32;
	t31 = t21 - t31 + t41;
	t32 = t22 - t32 + t42;
	t21 -= t41;
	t22 -= t42;
	t5 = t19 - t3;
	t6 = t20 - t4;
	t19 += t3;
	t20 += t4;
	t3 = t35 - t21;
	t4 = t36 - t22;
	t35 += t21;
	t36 += t22;
	t11 = t37 - t31;
	t12 = t38 - t32;
	t37 += t31;
	t38 += t32;
	t21 = t16 - t14 - t30;
	t22 = t15 - t13 - t29;
	t16 += t30;
	t15 += t29;
	t23 = t8 + t10 - t18;
	t24 = t7 + t9 - t17;
	t8 += t18;
	t7 += t17;
	t14 -= t30;
	t13 -= t29;
	t10 += t18;
	t9 += t17;
	pReal[0 * stride] = t1;
	pImag[0 * stride] = t2;
	pReal[1 * stride] = t19 - t16;
	pImag[1 * stride] = t20 + t15;
	pReal[2 * stride] = t3 - t8;
	pImag[2 * stride] = t4 + t7;
	pReal[3 * stride] = t35 + t21;
	pImag[3 * stride] = t36 - t22;
	pReal[4 * stride] = t37 - t14;
	pImag[4 * stride] = t38 + t13;
	pReal[5 * stride] = t5 - t10;
	pImag[5 * stride] = t6 + t9;
	pReal[6 * stride] = t11 + t23;
	pImag[6 * stride] = t12 - t24;
	pReal[7 * stride] = t11 - t23;
	pImag[7 * stride] = t12 + t24;
	pReal[8 * stride] = t5 + t10;
	pImag[8 * stride] = t6 - t9;
	pReal[9 * stride] = t37 + t14;
	pImag[9 * stride] = t38 - t13;
	pReal[10 * stride] = t35 - t21;
	pImag[10 * stride] = t36 + t22;
	pReal[11 * stride] = t3 + t8;
	pImag[11 * stride] = t4 - t7;
	pReal[12 * stride] = t19 + t16;
	pImag[12 * stride] = t20 - t15;
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
