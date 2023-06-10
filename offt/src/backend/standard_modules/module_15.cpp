
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

template<> StandardModuleComplexity const StandardModule<float, 15>::Complexity = { 0, 0 };
template<> StandardModuleComplexity const StandardModule<double, 15>::Complexity = { 0, 0 };

template<typename valueT>
static void ComputeCore(Phasors<valueT> const &phasors, valueT *pReal, valueT *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement)
{
	valueT r15, i15, r20, i20, r30, i30, r17, i17, r37, i37;
	valueT r40, i40, r57, i57, r60, i60, r18, i18, r24, i24;
	valueT r43, i43, r34, i34, r53, i53, r74, i74, r75, i75;
	valueT r21, i21, r31, i31, r89, i89, r111, i111, r58, i58;
	valueT r55, i55, r73, i73, r79, i79, r129, i129, r173, i173;
	valueT r48, i48, r47, i47, r69, i69, r119, i119, r137, i137;
	valueT r141, i141, r134, i134, r150, i150, r156, i156, r144, i144;
	valueT r139, i139, r142, i142, r146, i146, r151, i151, r155, i155;
	valueT r170, i170, r159, i159, r161, i161, r154, i154, r176, i176;
	valueT r152, i152;

	phasors.Multiply(r15, i15, pReal[14 * stride], pImag[14 * stride], twiddleStart + 14 * twiddleIncrement);
	{
		valueT s1r, s1i;
		phasors.Multiply(s1r, s1i, pReal[4 * stride], pImag[4 * stride], twiddleStart + 4 * twiddleIncrement);
		r20 = s1r - r15;
		i20 = s1i - i15;
		r30 = r15 + s1r;
		i30 = i15 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		phasors.Multiply(s1r, s1i, pReal[1 * stride], pImag[1 * stride], twiddleStart + 1 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[6 * stride], pImag[6 * stride], twiddleStart + 6 * twiddleIncrement);
		phasors.Multiply(s3r, s3i, pReal[9 * stride], pImag[9 * stride], twiddleStart + 9 * twiddleIncrement);
		phasors.Multiply(s4r, s4i, pReal[11 * stride], pImag[11 * stride], twiddleStart + 11 * twiddleIncrement);
		r17 = s1r - s4r;
		i17 = s1i - s4i;
		s5r = s1r + s4r;
		s5i = s1i + s4i;
		r37 = s2r + s5r;
		i37 = s2i + s5i;
		r40 = r30 + s3r;
		i40 = i30 + s3i;
		r57 = s5r - r30;
		i57 = s5i - i30;
		r60 = r30 + s5r;
		i60 = i30 + s5i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i;
		phasors.Multiply(s1r, s1i, pReal[2 * stride], pImag[2 * stride], twiddleStart + 2 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[3 * stride], pImag[3 * stride], twiddleStart + 3 * twiddleIncrement);
		phasors.Multiply(s3r, s3i, pReal[7 * stride], pImag[7 * stride], twiddleStart + 7 * twiddleIncrement);
		phasors.Multiply(s4r, s4i, pReal[8 * stride], pImag[8 * stride], twiddleStart + 8 * twiddleIncrement);
		phasors.Multiply(s5r, s5i, pReal[12 * stride], pImag[12 * stride], twiddleStart + 12 * twiddleIncrement);
		phasors.Multiply(s6r, s6i, pReal[13 * stride], pImag[13 * stride], twiddleStart + 13 * twiddleIncrement);
		r18 = s1r - s3r;
		i18 = s1i - s3i;
		s7r = s1r + s3r;
		s7i = s1i + s3i;
		r24 = s4r - s6r;
		i24 = s4i - s6i;
		s8r = s4r + s6r;
		s8i = s4i + s6i;
		r43 = s5r + s7r;
		i43 = s5i + s7i;
		r34 = s2r + s8r;
		i34 = s2i + s8i;
		r53 = s7r - s8r;
		i53 = s7i - s8i;
		s9r = s7r + s8r;
		s9i = s7i + s8i;
		r74 = s9r - r60;
		i74 = s9i - i60;
		r75 = r60 + s9r;
		i75 = i60 + s9i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i;
		phasors.Multiply(s1r, s1i, pReal[0 * stride], pImag[0 * stride], twiddleStart + 0 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[5 * stride], pImag[5 * stride], twiddleStart + 5 * twiddleIncrement);
		phasors.Multiply(s3r, s3i, pReal[10 * stride], pImag[10 * stride], twiddleStart + 10 * twiddleIncrement);
		r21 = s2r - s3r;
		i21 = s2i - s3i;
		s4r = s2r + s3r;
		s4i = s2i + s3i;
		r31 = s1r + s4r;
		i31 = s1i + s4i;
		r89 = r75 + s4r;
		i89 = i75 + s4i;
		r111 = valueT(1.875) * r75;
		i111 = valueT(1.875) * i75;
	}
	{
		valueT s1r, s1i;
		r58 = r43 + r34;
		i58 = i43 + i34;
		r55 = r37 + r40;
		i55 = i37 + i40;
		r73 = r58 + r55;
		i73 = i58 + i55;
		r79 = r31 + r73;
		i79 = i31 + i73;
		s1r = valueT(-1.5) * r89;
		s1i = valueT(-1.5) * i89;
		r129 = r111 + s1r;
		i129 = i111 + s1i;
		r173 = r79 + s1r;
		i173 = i79 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i;
		r48 = r18 - r24;
		i48 = i18 - i24;
		s1r = r18 + r24;
		s1i = i18 + i24;
		r47 = r17 - r20;
		i47 = i17 - i20;
		s2r = r20 + r17;
		s2i = i20 + i17;
		s3r = s2r - s1r;
		s3i = s2i - s1i;
		r69 = s1r + s2r;
		i69 = s1i + s2i;
		s4r = r21 - s3r;
		s4i = i21 - s3i;
		s5r = valueT(-1.0825317547305483085) * s3i;
		s5i = valueT(1.0825317547305483085) * s3r;
		s6r = valueT(-0.86602540378443864676) * s4i;
		s6i = valueT(0.86602540378443864676) * s4r;
		r119 = s5r + s6r;
		i119 = s5i + s6i;
		pReal[5 * stride] = r173 - s6r;
		pImag[5 * stride] = i173 - s6i;
		pReal[10 * stride] = r173 + s6r;
		pImag[10 * stride] = i173 + s6i;
	}
	{
		valueT s1r, s1i;
		s1r = valueT(-0.48412291827592711065) * i69;
		s1i = valueT(0.48412291827592711065) * r69;
		r137 = r119 - s1r;
		i137 = i119 - s1i;
		r141 = r119 + s1r;
		i141 = i119 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		s1r = valueT(1.3326760640014591093) * r48;
		s1i = valueT(1.3326760640014591093) * i48;
		s2r = r47 - r48;
		s2i = i47 - i48;
		s3r = valueT(-0.31460214309120474243) * r47;
		s3i = valueT(-0.31460214309120474243) * i47;
		s4r = valueT(0.50903696045512718345) * s2r;
		s4i = valueT(0.50903696045512718345) * s2i;
		s5r = s1r + s4r;
		s5i = s1i + s4i;
		r134 = s3r - s4r;
		i134 = s3i - s4i;
		r150 = s5r - r141;
		i150 = s5i - i141;
		r156 = r141 + s5r;
		i156 = i141 + s5i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		valueT s11r, s11i, s12r, s12i, s13r, s13i, s14r, s14i, s15r, s15i;
		valueT s16r, s16i, s17r, s17i, s18r, s18i, s19r, s19i, s20r, s20i;
		valueT s21r, s21i, s22r, s22i;
		s1r = r34 - r43;
		s1i = i34 - i43;
		s2r = valueT(-2.3082626528814400519) * i53;
		s2i = valueT(2.3082626528814400519) * r53;
		s3r = r37 - r40;
		s3i = i37 - i40;
		s4r = r57 + r53;
		s4i = i57 + i53;
		s5r = valueT(-0.54490689600402066442) * i57;
		s5i = valueT(0.54490689600402066442) * r57;
		s6r = valueT(-1.5388417685876267013) * s1i;
		s6i = valueT(1.5388417685876267013) * s1r;
		s7r = s3r - s1r;
		s7i = s3i - s1i;
		s8r = valueT(0.36327126400268044295) * s3i;
		s8i = valueT(-0.36327126400268044295) * s3r;
		s9r = r55 - r58;
		s9i = i55 - i58;
		s10r = valueT(0.88167787843870969375) * s4i;
		s10i = valueT(-0.88167787843870969375) * s4r;
		s11r = valueT(-0.83852549156242113615) * r74;
		s11i = valueT(-0.83852549156242113615) * i74;
		s12r = valueT(-0.58778525229247312917) * s7i;
		s12i = valueT(0.58778525229247312917) * s7r;
		s13r = valueT(-0.5590169943749474241) * s9r;
		s13i = valueT(-0.5590169943749474241) * s9i;
		s14r = valueT(-1.25) * r73;
		s14i = valueT(-1.25) * i73;
		s15r = s2r + s10r;
		s15i = s2i + s10i;
		r144 = s5r - s10r;
		i144 = s5i - s10i;
		s16r = s6r + s12r;
		s16i = s6i + s12i;
		r139 = s8r - s12r;
		i139 = s8i - s12i;
		pReal[0 * stride] = r79;
		pImag[0 * stride] = i79;
		s17r = r79 + s14r;
		s17i = i79 + s14i;
		r142 = s13r - s17r;
		i142 = s13i - s17i;
		s18r = s13r + s17r;
		s18i = s13i + s17i;
		r146 = s11r - r129;
		i146 = s11i - i129;
		s19r = r129 + s11r;
		s19i = i129 + s11i;
		r151 = s16r - s18r;
		i151 = s16i - s18i;
		s20r = s16r + s18r;
		s20i = s16i + s18i;
		r155 = s15r - s19r;
		i155 = s15i - s19i;
		s21r = s15r + s19r;
		s21i = s15i + s19i;
		pReal[6 * stride] = s20r;
		pImag[6 * stride] = s20i;
		s22r = s20r + s21r;
		s22i = s20i + s21i;
		pReal[11 * stride] = s22r - r156;
		pImag[11 * stride] = s22i - i156;
		pReal[1 * stride] = r156 + s22r;
		pImag[1 * stride] = i156 + s22i;
	}
	pReal[9 * stride] = -r151;
	pImag[9 * stride] = -i151;
	r170 = r151 + r155;
	i170 = i151 + i155;
	pReal[4 * stride] = -r150 - r170;
	pImag[4 * stride] = -i150 - i170;
	pReal[14 * stride] = r150 - r170;
	pImag[14 * stride] = i150 - i170;
	r159 = r144 - r146;
	i159 = i144 - i146;
	r161 = r144 + r146;
	i161 = i144 + i146;
	{
		valueT s1r, s1i;
		r154 = r139 - r142;
		i154 = i139 - i142;
		s1r = r139 + r142;
		s1i = i139 + i142;
		pReal[3 * stride] = -s1r;
		pImag[3 * stride] = -s1i;
		r176 = r161 + s1r;
		i176 = i161 + s1i;
	}
	{
		valueT s1r, s1i;
		s1r = r134 - r137;
		s1i = i134 - i137;
		r152 = r137 + r134;
		i152 = i137 + i134;
		pReal[13 * stride] = -r176 - s1r;
		pImag[13 * stride] = -i176 - s1i;
		pReal[8 * stride] = s1r - r176;
		pImag[8 * stride] = s1i - i176;
	}
	{
		valueT s1r, s1i;
		pReal[12 * stride] = r154;
		pImag[12 * stride] = i154;
		s1r = r159 + r154;
		s1i = i159 + i154;
		pReal[2 * stride] = s1r - r152;
		pImag[2 * stride] = s1i - i152;
		pReal[7 * stride] = r152 + s1r;
		pImag[7 * stride] = i152 + s1i;
	}
}

template<> void StandardModule<float, 15>::Compute(float *pReal, float *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

template<> void StandardModule<double, 15>::Compute(double *pReal, double *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

}
}
