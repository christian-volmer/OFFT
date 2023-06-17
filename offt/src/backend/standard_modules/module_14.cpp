
//          Copyright Christian Volmer 2022, 2023.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include "../standard_module.h"

namespace offt {
namespace backend {

/*
	Number of additions       : 0
	Number of multiplications : 0
*/

template<> StandardModuleComplexity const StandardModule<float, 14>::Complexity = { 0, 0 };
template<> StandardModuleComplexity const StandardModule<double, 14>::Complexity = { 0, 0 };

template<typename valueT>
static void ComputeCore(Phasors<valueT> const &phasors, valueT *pReal, valueT *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement)
{
	valueT r14, i14, r16, i16, r28, i28, r20, i20, r18, i18;
	valueT r40, i40, r43, i43, r38, i38, r42, i42, r76, i76;
	valueT r3, i3, r5, i5, r7, i7, r9, i9, r11, i11;
	valueT r13, i13, r23, i23, r25, i25, r27, i27, r37, i37;
	valueT r45, i45, r108, i108, r110, i110, r106, i106, r102, i102;
	valueT r98, i98, r120, i120, r114, i114, r107, i107, r105, i105;
	valueT r101, i101, r99, i99, r117, i117, r113, i113, r121, i121;
	valueT r112, i112, r119, i119, r115, i115, r116, i116;

	phasors.Multiply(r14, i14, pReal[13 * stride], pImag[13 * stride], twiddleStart + 13 * twiddleIncrement);
	{
		valueT s1r, s1i;
		phasors.Multiply(s1r, s1i, pReal[1 * stride], pImag[1 * stride], twiddleStart + 1 * twiddleIncrement);
		r16 = s1r - r14;
		i16 = s1i - i14;
		r28 = r14 + s1r;
		i28 = i14 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i;
		phasors.Multiply(s1r, s1i, pReal[3 * stride], pImag[3 * stride], twiddleStart + 3 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[5 * stride], pImag[5 * stride], twiddleStart + 5 * twiddleIncrement);
		phasors.Multiply(s3r, s3i, pReal[9 * stride], pImag[9 * stride], twiddleStart + 9 * twiddleIncrement);
		phasors.Multiply(s4r, s4i, pReal[11 * stride], pImag[11 * stride], twiddleStart + 11 * twiddleIncrement);
		r20 = s2r - s3r;
		i20 = s2i - s3i;
		s5r = s2r + s3r;
		s5i = s2i + s3i;
		r18 = s1r - s4r;
		i18 = s1i - s4i;
		s6r = s1r + s4r;
		s6i = s1i + s4i;
		r40 = s6r - s5r;
		i40 = s6i - s5i;
		r43 = s5r - r28;
		i43 = s5i - i28;
		r38 = r28 + s5r + s6r;
		i38 = i28 + s5i + s6i;
		r42 = r28 - s6r;
		i42 = i28 - s6i;
	}
	r76 = valueT(-0.79015646852540019719) * r42;
	i76 = valueT(-0.79015646852540019719) * i42;
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i;
		phasors.Multiply(s1r, s1i, pReal[0 * stride], pImag[0 * stride], twiddleStart + 0 * twiddleIncrement);
		phasors.Multiply(r3, i3, pReal[2 * stride], pImag[2 * stride], twiddleStart + 2 * twiddleIncrement);
		phasors.Multiply(r5, i5, pReal[4 * stride], pImag[4 * stride], twiddleStart + 4 * twiddleIncrement);
		phasors.Multiply(r7, i7, pReal[6 * stride], pImag[6 * stride], twiddleStart + 6 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[7 * stride], pImag[7 * stride], twiddleStart + 7 * twiddleIncrement);
		phasors.Multiply(r9, i9, pReal[8 * stride], pImag[8 * stride], twiddleStart + 8 * twiddleIncrement);
		phasors.Multiply(r11, i11, pReal[10 * stride], pImag[10 * stride], twiddleStart + 10 * twiddleIncrement);
		phasors.Multiply(r13, i13, pReal[12 * stride], pImag[12 * stride], twiddleStart + 12 * twiddleIncrement);
		r23 = r7 + r9;
		i23 = i7 + i9;
		r25 = r5 + r11;
		i25 = i5 + i11;
		r27 = r3 + r13;
		i27 = i3 + i13;
		r37 = r23 + r25 + r27;
		i37 = i23 + i25 + i27;
		s3r = valueT(-0.055854267289647737622) * r40;
		s3i = valueT(-0.055854267289647737622) * i40;
		r45 = s1r + r37;
		i45 = s1i + i37;
		s4r = valueT(0.73430220123575245957) * r43;
		s4i = valueT(0.73430220123575245957) * i43;
		s5r = r38 + s2r;
		s5i = i38 + s2i;
		s6r = valueT(-1.1666666666666666667) * r38;
		s6i = valueT(-1.1666666666666666667) * i38;
		pReal[7 * stride] = r45 - s5r;
		pImag[7 * stride] = i45 - s5i;
		pReal[0 * stride] = r45 + s5r;
		pImag[0 * stride] = i45 + s5i;
		s7r = s5r + s6r;
		s7i = s5i + s6i;
		r108 = r76 + s3r - s7r;
		i108 = i76 + s3i - s7i;
		r110 = s3r + s4r + s7r;
		i110 = s3i + s4i + s7i;
		r106 = r76 + s7r - s4r;
		i106 = i76 + s7i - s4i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		valueT s11r, s11i;
		s1r = r20 - r18;
		s1i = i20 - i18;
		s2r = r20 + r18 - r16;
		s2i = i20 + i18 - i16;
		s3r = r16 + r18;
		s3i = i16 + i18;
		s4r = valueT(-1.2157152215855879292) * s1i;
		s4i = valueT(1.2157152215855879292) * s1r;
		s5r = valueT(0.44095855184409843175) * s2i;
		s5i = valueT(-0.44095855184409843175) * s2r;
		s6r = s1r - s3r;
		s6i = s1i - s3i;
		s7r = valueT(1.4088116512993817275) * s3i;
		s7i = valueT(-1.4088116512993817275) * s3r;
		s8r = valueT(0.87484229096165655223) * s6i;
		s8i = valueT(-0.87484229096165655223) * s6r;
		s9r = s4r + s8r;
		s9i = s4i + s8i;
		s10r = s7r + s8r;
		s10i = s7i + s8i;
		r102 = s9r - s5r;
		i102 = s9i - s5i;
		s11r = s5r - s10r;
		s11i = s5i - s10i;
		r98 = s5r + s9r + s10r;
		i98 = s5i + s9i + s10i;
		r120 = r106 - s11r;
		i120 = i106 - s11i;
		r114 = r106 + s11r;
		i114 = i106 + s11i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		valueT s11r, s11i, s12r, s12i, s13r, s13i, s14r, s14i, s15r, s15i;
		valueT s16r, s16i, s17r, s17i, s18r, s18i, s19r, s19i, s20r, s20i;
		valueT s21r, s21i, s22r, s22i, s23r, s23i, s24r, s24i;
		s1r = r7 - r9;
		s1i = i7 - i9;
		s2r = r5 - r11;
		s2i = i5 - i11;
		s3r = r3 - r13;
		s3i = i3 - i13;
		s4r = s1r + s2r;
		s4i = s1i + s2i;
		s5r = r25 - r23;
		s5i = i25 - i23;
		s6r = s2r + s3r - s1r;
		s6i = s2i + s3i - s1i;
		s7r = s3r - s2r;
		s7i = s3i - s2i;
		s8r = r23 - r27;
		s8i = i23 - i27;
		s9r = r27 - r25;
		s9i = i27 - i25;
		s10r = valueT(-1.4088116512993817275) * s4i;
		s10i = valueT(1.4088116512993817275) * s4r;
		s11r = valueT(0.79015646852540019719) * s5r;
		s11i = valueT(0.79015646852540019719) * s5i;
		s12r = valueT(-0.44095855184409843175) * s6i;
		s12i = valueT(0.44095855184409843175) * s6r;
		s13r = s4r - s7r;
		s13i = s4i - s7i;
		s14r = valueT(1.2157152215855879292) * s7i;
		s14i = valueT(-1.2157152215855879292) * s7r;
		s15r = valueT(-0.73430220123575245957) * s8r;
		s15i = valueT(-0.73430220123575245957) * s8i;
		s16r = valueT(-1.1666666666666666667) * r37;
		s16i = valueT(-1.1666666666666666667) * i37;
		s17r = valueT(0.055854267289647737622) * s9r;
		s17i = valueT(0.055854267289647737622) * s9i;
		s18r = valueT(0.87484229096165655223) * s13i;
		s18i = valueT(-0.87484229096165655223) * s13r;
		s19r = r45 + s16r;
		s19i = i45 + s16i;
		s20r = s10r + s18r;
		s20i = s10i + s18i;
		s21r = s14r + s18r;
		s21i = s14i + s18i;
		s22r = s11r + s19r - s15r;
		s22i = s11i + s19i - s15i;
		r107 = s11r + s17r - s19r;
		i107 = s11i + s17i - s19i;
		r105 = s15r + s17r + s19r;
		i105 = s15i + s17i + s19i;
		s23r = s20r - s12r;
		s23i = s20i - s12i;
		r101 = s12r - s21r;
		i101 = s12i - s21i;
		r99 = s12r + s20r + s21r;
		i99 = s12i + s20i + s21i;
		s24r = s22r - s23r;
		s24i = s22i - s23i;
		r117 = s22r + s23r;
		i117 = s22i + s23i;
		pReal[11 * stride] = s24r - r114;
		pImag[11 * stride] = s24i - i114;
		pReal[4 * stride] = r114 + s24r;
		pImag[4 * stride] = i114 + s24i;
	}
	pReal[3 * stride] = r117 - r120;
	pImag[3 * stride] = i117 - i120;
	pReal[10 * stride] = r120 + r117;
	pImag[10 * stride] = i120 + i117;
	r113 = r99 - r107;
	i113 = i99 - i107;
	r121 = r107 + r99;
	i121 = i107 + i99;
	{
		valueT s1r, s1i;
		r112 = r98 - r108;
		i112 = i98 - i108;
		s1r = r108 + r98;
		s1i = i108 + i98;
		pReal[12 * stride] = -r121 - s1r;
		pImag[12 * stride] = -i121 - s1i;
		pReal[5 * stride] = s1r - r121;
		pImag[5 * stride] = s1i - i121;
	}
	pReal[9 * stride] = r113 - r112;
	pImag[9 * stride] = i113 - i112;
	pReal[2 * stride] = r113 + r112;
	pImag[2 * stride] = i113 + i112;
	r119 = r105 - r101;
	i119 = i105 - i101;
	r115 = r105 + r101;
	i115 = i105 + i101;
	{
		valueT s1r, s1i;
		s1r = r110 - r102;
		s1i = i110 - i102;
		r116 = r110 + r102;
		i116 = i110 + i102;
		pReal[1 * stride] = r115 - s1r;
		pImag[1 * stride] = i115 - s1i;
		pReal[8 * stride] = r115 + s1r;
		pImag[8 * stride] = i115 + s1i;
	}
	pReal[13 * stride] = r119 - r116;
	pImag[13 * stride] = i119 - i116;
	pReal[6 * stride] = r119 + r116;
	pImag[6 * stride] = i119 + i116;
}

template<> void StandardModule<float, 14>::Compute(float *pReal, float *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

template<> void StandardModule<double, 14>::Compute(double *pReal, double *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

}
}
