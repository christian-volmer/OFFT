
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
	valueT t21, t22, t23, t24, t25, t26, t27, t28, t29, t30;
	valueT t31, t32, t33, t34;

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
	phasors.Multiply(t27, t28, pReal[13 * stride], pImag[13 * stride], twiddleStart + 13 * twiddleIncrement);
	phasors.Multiply(t29, t30, pReal[14 * stride], pImag[14 * stride], twiddleStart + 14 * twiddleIncrement);
	phasors.Multiply(t31, t32, pReal[15 * stride], pImag[15 * stride], twiddleStart + 15 * twiddleIncrement);

	t33 = t1 - t17;
	t34 = t2 - t18;
	t1 += t17;
	t2 += t18;
	t17 = t9 - t25;
	t18 = t10 - t26;
	t9 += t25;
	t10 += t26;
	t25 = t33 + t18;
	t26 = t34 - t17;
	t33 -= t18;
	t34 += t17;
	t17 = t1 - t9;
	t18 = t2 - t10;
	t1 += t9;
	t2 += t10;
	t9 = t3 - t19;
	t10 = t4 - t20;
	t3 += t19;
	t4 += t20;
	t19 = t5 - t21;
	t20 = t6 - t22;
	t5 += t21;
	t6 += t22;
	t21 = t7 - t23;
	t22 = t8 - t24;
	t7 += t23;
	t8 += t24;
	t23 = t11 - t27;
	t24 = t12 - t28;
	t11 += t27;
	t12 += t28;
	t27 = t13 - t29;
	t28 = t14 - t30;
	t13 += t29;
	t14 += t30;
	t29 = t15 - t31;
	t30 = t16 - t32;
	t15 += t31;
	t16 += t32;
	t31 = valueT(0.7071067811865475244) * (t19 - t20);
	t19 = valueT(0.7071067811865475244) * (t19 + t20);
	t20 = valueT(0.7071067811865475244) * (t27 + t28);
	t27 = valueT(0.7071067811865475244) * (t27 - t28);
	t28 = t9 + t24;
	t32 = t10 - t23;
	t9 -= t24;
	t10 += t23;
	t23 = t3 - t11;
	t24 = t4 - t12;
	t3 += t11;
	t4 += t12;
	t11 = t31 + t20;
	t12 = t19 - t27;
	t31 -= t20;
	t19 += t27;
	t20 = t5 - t13;
	t27 = t6 - t14;
	t5 += t13;
	t6 += t14;
	t13 = t21 + t30;
	t14 = t22 - t29;
	t21 -= t30;
	t22 += t29;
	t29 = t7 - t15;
	t30 = t8 - t16;
	t7 += t15;
	t8 += t16;
	t15 = t25 + t12;
	t16 = t26 - t11;
	t25 -= t12;
	t26 += t11;
	t11 = t33 - t31;
	t12 = t34 - t19;
	t33 += t31;
	t34 += t19;
	t19 = t17 + t27;
	t31 = t18 - t20;
	t17 -= t27;
	t18 += t20;
	t20 = t1 - t5;
	t27 = t2 - t6;
	t1 += t5;
	t2 += t6;
	t5 = valueT(0.38268343236508977173) * t28 - valueT(0.92387953251128675613) * t32;
	t28 = valueT(0.92387953251128675613) * t28 + valueT(0.38268343236508977173) * t32;
	t6 = valueT(0.92387953251128675613) * t9 - valueT(0.38268343236508977173) * t10;
	t9 = valueT(0.38268343236508977173) * t9 + valueT(0.92387953251128675613) * t10;
	t10 = valueT(0.7071067811865475244) * (t23 - t24);
	t23 = valueT(0.7071067811865475244) * (t23 + t24);
	t24 = valueT(0.92387953251128675613) * t13 - valueT(0.38268343236508977173) * t14;
	t13 = valueT(0.38268343236508977173) * t13 + valueT(0.92387953251128675613) * t14;
	t14 = valueT(0.38268343236508977173) * t21 - valueT(0.92387953251128675613) * t22;
	t21 = valueT(0.92387953251128675613) * t21 + valueT(0.38268343236508977173) * t22;
	t22 = valueT(0.7071067811865475244) * (t29 + t30);
	t29 = valueT(0.7071067811865475244) * (t29 - t30);
	t30 = t5 + t24;
	t32 = t28 + t13;
	t5 -= t24;
	t28 -= t13;
	t13 = t6 - t14;
	t24 = t9 - t21;
	t6 += t14;
	t9 += t21;
	t14 = t10 + t22;
	t21 = t23 - t29;
	t10 -= t22;
	t23 += t29;
	t22 = t3 - t7;
	t29 = t4 - t8;
	t3 += t7;
	t4 += t8;
	pReal[0 * stride] = t1 + t3;
	pImag[0 * stride] = t2 + t4;
	pReal[1 * stride] = t33 + t6;
	pImag[1 * stride] = t34 + t9;
	pReal[2 * stride] = t17 + t10;
	pImag[2 * stride] = t18 + t23;
	pReal[3 * stride] = t25 + t5;
	pImag[3 * stride] = t26 + t28;
	pReal[4 * stride] = t20 - t29;
	pImag[4 * stride] = t27 + t22;
	pReal[5 * stride] = t11 - t24;
	pImag[5 * stride] = t12 + t13;
	pReal[6 * stride] = t19 - t21;
	pImag[6 * stride] = t31 + t14;
	pReal[7 * stride] = t15 - t32;
	pImag[7 * stride] = t16 + t30;
	pReal[8 * stride] = t1 - t3;
	pImag[8 * stride] = t2 - t4;
	pReal[9 * stride] = t33 - t6;
	pImag[9 * stride] = t34 - t9;
	pReal[10 * stride] = t17 - t10;
	pImag[10 * stride] = t18 - t23;
	pReal[11 * stride] = t25 - t5;
	pImag[11 * stride] = t26 - t28;
	pReal[12 * stride] = t20 + t29;
	pImag[12 * stride] = t27 - t22;
	pReal[13 * stride] = t11 + t24;
	pImag[13 * stride] = t12 - t13;
	pReal[14 * stride] = t19 + t21;
	pImag[14 * stride] = t31 - t14;
	pReal[15 * stride] = t15 + t32;
	pImag[15 * stride] = t16 - t30;
}

template<> void StandardModule<float, 16>::Compute(float *pReal, float *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

template<> void StandardModule<double, 16>::Compute(double *pReal, double *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

}
}
