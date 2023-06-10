
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

template<> StandardModuleComplexity const StandardModule<float, 20>::Complexity = { 0, 0 };
template<> StandardModuleComplexity const StandardModule<double, 20>::Complexity = { 0, 0 };

template<typename valueT>
static void ComputeCore(Phasors<valueT> const &phasors, valueT *pReal, valueT *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement)
{
	valueT r20, i20, r30, i30, r40, i40, r22, i22, r52, i52;
	valueT r60, i60, r24, i24, r28, i28, r54, i54, r78, i78;
	valueT r80, i80, r26, i26, r100, i100, r128, i128, r1, i1;
	valueT r3, i3, r5, i5, r7, i7, r9, i9, r11, i11;
	valueT r13, i13, r15, i15, r17, i17, r19, i19, r33, i33;
	valueT r35, i35, r37, i37, r39, i39, r57, i57, r59, i59;
	valueT r79, i79, r95, i95, r152, i152, r174, i174, r176, i176;
	valueT r170, i170, r188, i188, r196, i196, r169, i169, r173, i173;
	valueT r191, i191, r189, i189, r193, i193, r194, i194, r29, i29;
	valueT r43, i43, r49, i49, r45, i45, r115, i115, r83, i83;
	valueT r117, i117, r163, i163, r165, i165, r48, i48, r50, i50;
	valueT r68, i68, r90, i90, r161, i161, r179, i179, r185, i185;
	valueT r158, i158, r166, i166, r184, i184, r178, i178, r186, i186;
	valueT r181, i181;

	phasors.Multiply(r20, i20, pReal[19 * stride], pImag[19 * stride], twiddleStart + 19 * twiddleIncrement);
	{
		valueT s1r, s1i;
		phasors.Multiply(s1r, s1i, pReal[9 * stride], pImag[9 * stride], twiddleStart + 9 * twiddleIncrement);
		r30 = s1r - r20;
		i30 = s1i - i20;
		r40 = r20 + s1r;
		i40 = i20 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i;
		phasors.Multiply(s1r, s1i, pReal[1 * stride], pImag[1 * stride], twiddleStart + 1 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[11 * stride], pImag[11 * stride], twiddleStart + 11 * twiddleIncrement);
		r22 = s1r - s2r;
		i22 = s1i - s2i;
		s3r = s1r + s2r;
		s3i = s1i + s2i;
		r52 = s3r - r40;
		i52 = s3i - i40;
		r60 = r40 + s3r;
		i60 = i40 + s3i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i;
		phasors.Multiply(s1r, s1i, pReal[3 * stride], pImag[3 * stride], twiddleStart + 3 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[7 * stride], pImag[7 * stride], twiddleStart + 7 * twiddleIncrement);
		phasors.Multiply(s3r, s3i, pReal[13 * stride], pImag[13 * stride], twiddleStart + 13 * twiddleIncrement);
		phasors.Multiply(s4r, s4i, pReal[17 * stride], pImag[17 * stride], twiddleStart + 17 * twiddleIncrement);
		r24 = s1r - s3r;
		i24 = s1i - s3i;
		s5r = s1r + s3r;
		s5i = s1i + s3i;
		r28 = s2r - s4r;
		i28 = s2i - s4i;
		s6r = s2r + s4r;
		s6i = s2i + s4i;
		r54 = s5r - s6r;
		i54 = s5i - s6i;
		s7r = s5r + s6r;
		s7i = s5i + s6i;
		r78 = s7r - r60;
		i78 = s7i - i60;
		r80 = r60 + s7r;
		i80 = i60 + s7i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i;
		phasors.Multiply(s1r, s1i, pReal[5 * stride], pImag[5 * stride], twiddleStart + 5 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[15 * stride], pImag[15 * stride], twiddleStart + 15 * twiddleIncrement);
		r26 = s1r - s2r;
		i26 = s1i - s2i;
		s3r = s1r + s2r;
		s3i = s1i + s2i;
		r100 = r80 + s3r;
		i100 = i80 + s3i;
		r128 = valueT(-1.25) * r80;
		i128 = valueT(-1.25) * i80;
	}
	{
		valueT s1r, s1i;
		phasors.Multiply(r1, i1, pReal[0 * stride], pImag[0 * stride], twiddleStart + 0 * twiddleIncrement);
		phasors.Multiply(r3, i3, pReal[2 * stride], pImag[2 * stride], twiddleStart + 2 * twiddleIncrement);
		phasors.Multiply(r5, i5, pReal[4 * stride], pImag[4 * stride], twiddleStart + 4 * twiddleIncrement);
		phasors.Multiply(r7, i7, pReal[6 * stride], pImag[6 * stride], twiddleStart + 6 * twiddleIncrement);
		phasors.Multiply(r9, i9, pReal[8 * stride], pImag[8 * stride], twiddleStart + 8 * twiddleIncrement);
		phasors.Multiply(r11, i11, pReal[10 * stride], pImag[10 * stride], twiddleStart + 10 * twiddleIncrement);
		phasors.Multiply(r13, i13, pReal[12 * stride], pImag[12 * stride], twiddleStart + 12 * twiddleIncrement);
		phasors.Multiply(r15, i15, pReal[14 * stride], pImag[14 * stride], twiddleStart + 14 * twiddleIncrement);
		phasors.Multiply(r17, i17, pReal[16 * stride], pImag[16 * stride], twiddleStart + 16 * twiddleIncrement);
		phasors.Multiply(r19, i19, pReal[18 * stride], pImag[18 * stride], twiddleStart + 18 * twiddleIncrement);
		s1r = r1 + r11;
		s1i = i1 + i11;
		r33 = r3 + r13;
		i33 = i3 + i13;
		r35 = r5 + r15;
		i35 = i5 + i15;
		r37 = r7 + r17;
		i37 = i7 + i17;
		r39 = r9 + r19;
		i39 = i9 + i19;
		r57 = r35 + r37;
		i57 = i35 + i37;
		r59 = r33 + r39;
		i59 = i33 + i39;
		r79 = r57 + r59;
		i79 = i57 + i59;
		r95 = s1r + r79;
		i95 = s1i + i79;
		pReal[10 * stride] = r95 - r100;
		pImag[10 * stride] = i95 - i100;
		pReal[0 * stride] = r100 + r95;
		pImag[0 * stride] = i100 + i95;
		r152 = r100 + r128;
		i152 = i100 + i128;
	}
	{
		valueT s1r, s1i;
		s1r = valueT(-0.5590169943749474241) * r78;
		s1i = valueT(-0.5590169943749474241) * i78;
		r174 = s1r - r152;
		i174 = s1i - i152;
		r176 = r152 + s1r;
		i176 = i152 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		s1r = valueT(0.36327126400268044295) * i54;
		s1i = valueT(-0.36327126400268044295) * r54;
		s2r = r52 + r54;
		s2i = i52 + i54;
		s3r = valueT(1.5388417685876267013) * i52;
		s3i = valueT(-1.5388417685876267013) * r52;
		s4r = valueT(-0.58778525229247312917) * s2i;
		s4i = valueT(0.58778525229247312917) * s2r;
		r170 = s1r - s4r;
		i170 = s1i - s4i;
		s5r = s3r + s4r;
		s5i = s3i + s4i;
		r188 = s5r - r176;
		i188 = s5i - i176;
		r196 = r176 + s5r;
		i196 = i176 + s5i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		valueT s11r, s11i, s12r, s12i, s13r, s13i;
		s1r = r35 - r37;
		s1i = i35 - i37;
		s2r = r33 - r39;
		s2i = i33 - i39;
		s3r = valueT(-1.5388417685876267013) * s1i;
		s3i = valueT(1.5388417685876267013) * s1r;
		s4r = s1r + s2r;
		s4i = s1i + s2i;
		s5r = valueT(-0.36327126400268044295) * s2i;
		s5i = valueT(0.36327126400268044295) * s2r;
		s6r = r57 - r59;
		s6i = i57 - i59;
		s7r = valueT(0.58778525229247312917) * s4i;
		s7i = valueT(-0.58778525229247312917) * s4r;
		s8r = valueT(0.5590169943749474241) * s6r;
		s8i = valueT(0.5590169943749474241) * s6i;
		s9r = valueT(-1.25) * r79;
		s9i = valueT(-1.25) * i79;
		s10r = s3r + s7r;
		s10i = s3i + s7i;
		r169 = s5r - s7r;
		i169 = s5i - s7i;
		s11r = r95 + s9r;
		s11i = i95 + s9i;
		r173 = s8r - s11r;
		i173 = s8i - s11i;
		s12r = s8r + s11r;
		s12i = s8i + s11i;
		r191 = s10r - s12r;
		i191 = s10i - s12i;
		s13r = s10r + s12r;
		s13i = s10i + s12i;
		pReal[6 * stride] = s13r - r196;
		pImag[6 * stride] = s13i - i196;
		pReal[16 * stride] = r196 + s13r;
		pImag[16 * stride] = i196 + s13i;
	}
	pReal[4 * stride] = -r188 - r191;
	pImag[4 * stride] = -i188 - i191;
	pReal[14 * stride] = r188 - r191;
	pImag[14 * stride] = i188 - i191;
	r189 = r169 - r173;
	i189 = i169 - i173;
	r193 = r169 + r173;
	i193 = i169 + i173;
	{
		valueT s1r, s1i;
		r194 = r174 - r170;
		i194 = i174 - i170;
		s1r = r174 + r170;
		s1i = i174 + i170;
		pReal[8 * stride] = -r193 - s1r;
		pImag[8 * stride] = -i193 - s1i;
		pReal[18 * stride] = s1r - r193;
		pImag[18 * stride] = s1i - i193;
	}
	pReal[12 * stride] = r189 - r194;
	pImag[12 * stride] = i189 - i194;
	pReal[2 * stride] = r189 + r194;
	pImag[2 * stride] = i189 + i194;
	r29 = r9 - r19;
	i29 = i9 - i19;
	{
		valueT s1r, s1i;
		s1r = r3 - r13;
		s1i = i3 - i13;
		r43 = s1r - r29;
		i43 = s1i - i29;
		r49 = r29 + s1r;
		i49 = i29 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i;
		s1r = r5 - r15;
		s1i = i5 - i15;
		s2r = r7 - r17;
		s2i = i7 - i17;
		r45 = s1r - s2r;
		i45 = s1i - s2i;
		s3r = s1r + s2r;
		s3i = s1i + s2i;
		r115 = valueT(-1.5388417685876267013) * s3i;
		i115 = valueT(1.5388417685876267013) * s3r;
		r83 = s3r - r49;
		i83 = s3i - i49;
		r117 = valueT(0.36327126400268044295) * i49;
		i117 = valueT(-0.36327126400268044295) * r49;
	}
	{
		valueT s1r, s1i;
		s1r = valueT(0.58778525229247312917) * i83;
		s1i = valueT(-0.58778525229247312917) * r83;
		r163 = r115 + s1r;
		i163 = i115 + s1i;
		r165 = r117 - s1r;
		i165 = i117 - s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i;
		s1r = r1 - r11;
		s1i = i1 - i11;
		r48 = r24 + r28;
		i48 = i24 + i28;
		r50 = r30 + r22;
		i50 = i30 + i22;
		s2r = r43 - r45;
		s2i = i43 - i45;
		s3r = r43 + r45;
		s3i = i43 + i45;
		r68 = r48 - r50;
		i68 = i48 - i50;
		s4r = s1r - s2r;
		s4i = s1i - s2i;
		s5r = valueT(1.25) * s2r;
		s5i = valueT(1.25) * s2i;
		s6r = valueT(0.5590169943749474241) * s3r;
		s6i = valueT(0.5590169943749474241) * s3i;
		r90 = r26 - r68;
		i90 = i26 - i68;
		s7r = s4r + s5r;
		s7i = s4i + s5i;
		pReal[15 * stride] = s4r + i90;
		pImag[15 * stride] = s4i - r90;
		pReal[5 * stride] = s4r - i90;
		pImag[5 * stride] = s4i + r90;
		s8r = s7r - s6r;
		s8i = s7i - s6i;
		r161 = s6r + s7r;
		i161 = s6i + s7i;
		r179 = s8r - r165;
		i179 = s8i - i165;
		r185 = r165 + s8r;
		i185 = i165 + s8i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		valueT s11r, s11i, s12r, s12i, s13r, s13i;
		s1r = r24 - r28;
		s1i = i24 - i28;
		s2r = r22 - r30;
		s2i = i22 - i30;
		s3r = valueT(-0.36327126400268044295) * s1r;
		s3i = valueT(-0.36327126400268044295) * s1i;
		s4r = s1r - s2r;
		s4i = s1i - s2i;
		s5r = valueT(1.5388417685876267013) * s2r;
		s5i = valueT(1.5388417685876267013) * s2i;
		s6r = r48 + r50;
		s6i = i48 + i50;
		s7r = valueT(0.58778525229247312917) * s4r;
		s7i = valueT(0.58778525229247312917) * s4i;
		s8r = valueT(-1.25) * i68;
		s8i = valueT(1.25) * r68;
		s9r = valueT(-0.5590169943749474241) * s6i;
		s9i = valueT(0.5590169943749474241) * s6r;
		s10r = s3r - s7r;
		s10i = s3i - s7i;
		r158 = s5r + s7r;
		i158 = s5i + s7i;
		s11r = s8r - i90;
		s11i = r90 + s8i;
		s12r = s11r - s9r;
		s12i = s11i - s9i;
		r166 = s9r + s11r;
		i166 = s9i + s11i;
		r184 = s12r - s10r;
		i184 = s12i - s10i;
		s13r = s10r + s12r;
		s13i = s10i + s12i;
		pReal[7 * stride] = r185 - s13r;
		pImag[7 * stride] = i185 - s13i;
		pReal[17 * stride] = r185 + s13r;
		pImag[17 * stride] = i185 + s13i;
	}
	pReal[3 * stride] = r179 - r184;
	pImag[3 * stride] = i179 - i184;
	pReal[13 * stride] = r179 + r184;
	pImag[13 * stride] = i179 + i184;
	r178 = r158 - r166;
	i178 = i158 - i166;
	r186 = r158 + r166;
	i186 = i158 + i166;
	{
		valueT s1r, s1i;
		r181 = r161 - r163;
		i181 = i161 - i163;
		s1r = r163 + r161;
		s1i = i163 + i161;
		pReal[11 * stride] = s1r - r186;
		pImag[11 * stride] = s1i - i186;
		pReal[1 * stride] = r186 + s1r;
		pImag[1 * stride] = i186 + s1i;
	}
	pReal[9 * stride] = r181 - r178;
	pImag[9 * stride] = i181 - i178;
	pReal[19 * stride] = r178 + r181;
	pImag[19 * stride] = i178 + i181;
}

template<> void StandardModule<float, 20>::Compute(float *pReal, float *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

template<> void StandardModule<double, 20>::Compute(double *pReal, double *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

}
}
