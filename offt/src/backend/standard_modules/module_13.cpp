
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

template<> StandardModuleComplexity const StandardModule<float, 13>::Complexity = { 0, 0 };
template<> StandardModuleComplexity const StandardModule<double, 13>::Complexity = { 0, 0 };

template<typename valueT>
static void ComputeCore(Phasors<valueT> const &phasors, valueT *pReal, valueT *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement)
{
	valueT r13, i13, r15, i15, r26, i26, r19, i19, r35, i35;
	valueT r39, i39, r20, i20, r18, i18, r17, i17, r16, i16;
	valueT r34, i34, r37, i37, r51, i51, r55, i55, r49, i49;
	valueT r52, i52, r90, i90, r128, i128, r127, i127, r125, i125;
	valueT r126, i126, r124, i124, r136, i136, r138, i138, r83, i83;
	valueT r98, i98, r118, i118, r105, i105, r115, i115, r133, i133;
	valueT r130, i130, r140, i140, r134, i134, r131, i131, r141, i141;

	phasors.Multiply(r13, i13, pReal[12 * stride], pImag[12 * stride], twiddleStart + 12 * twiddleIncrement);
	{
		valueT s1r, s1i;
		phasors.Multiply(s1r, s1i, pReal[1 * stride], pImag[1 * stride], twiddleStart + 1 * twiddleIncrement);
		r15 = s1r - r13;
		i15 = s1i - i13;
		r26 = r13 + s1r;
		i26 = i13 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i;
		phasors.Multiply(s1r, s1i, pReal[5 * stride], pImag[5 * stride], twiddleStart + 5 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[8 * stride], pImag[8 * stride], twiddleStart + 8 * twiddleIncrement);
		r19 = s1r - s2r;
		i19 = s1i - s2i;
		s3r = s1r + s2r;
		s3i = s1i + s2i;
		r35 = s3r - r26;
		i35 = s3i - i26;
		r39 = r26 + s3r;
		i39 = i26 + s3i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		valueT s11r, s11i, s12r, s12i, s13r, s13i, s14r, s14i;
		phasors.Multiply(s1r, s1i, pReal[2 * stride], pImag[2 * stride], twiddleStart + 2 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[3 * stride], pImag[3 * stride], twiddleStart + 3 * twiddleIncrement);
		phasors.Multiply(s3r, s3i, pReal[4 * stride], pImag[4 * stride], twiddleStart + 4 * twiddleIncrement);
		phasors.Multiply(s4r, s4i, pReal[6 * stride], pImag[6 * stride], twiddleStart + 6 * twiddleIncrement);
		phasors.Multiply(s5r, s5i, pReal[7 * stride], pImag[7 * stride], twiddleStart + 7 * twiddleIncrement);
		phasors.Multiply(s6r, s6i, pReal[9 * stride], pImag[9 * stride], twiddleStart + 9 * twiddleIncrement);
		phasors.Multiply(s7r, s7i, pReal[10 * stride], pImag[10 * stride], twiddleStart + 10 * twiddleIncrement);
		phasors.Multiply(s8r, s8i, pReal[11 * stride], pImag[11 * stride], twiddleStart + 11 * twiddleIncrement);
		r20 = s4r - s5r;
		i20 = s4i - s5i;
		s9r = s4r + s5r;
		s9i = s4i + s5i;
		r18 = s3r - s6r;
		i18 = s3i - s6i;
		s10r = s3r + s6r;
		s10i = s3i + s6i;
		r17 = s2r - s7r;
		i17 = s2i - s7i;
		s11r = s2r + s7r;
		s11i = s2i + s7i;
		r16 = s1r - s8r;
		i16 = s1i - s8i;
		s12r = s1r + s8r;
		s12i = s1i + s8i;
		r34 = s9r - s10r;
		i34 = s9i - s10i;
		s13r = s9r + s10r;
		s13i = s9i + s10i;
		r37 = s11r - s12r;
		i37 = s11i - s12i;
		s14r = s11r + s12r;
		s14i = s11i + s12i;
		r51 = s14r - s13r;
		i51 = s14i - s13i;
		r55 = s13r - r39;
		i55 = s13i - i39;
		r49 = r39 + s13r + s14r;
		i49 = i39 + s13i + s14i;
		r52 = r39 - s14r;
		i52 = i39 - s14i;
	}
	r90 = valueT(-0.42763404682657276126) * r52;
	i90 = valueT(-0.42763404682657276126) * i52;
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i;
		phasors.Multiply(s1r, s1i, pReal[0 * stride], pImag[0 * stride], twiddleStart + 0 * twiddleIncrement);
		s2r = valueT(-0.15180597207438773197) * r51;
		s2i = valueT(-0.15180597207438773197) * i51;
		s3r = valueT(-0.57944001890096049323) * r55;
		s3i = valueT(-0.57944001890096049323) * i55;
		s4r = r49 + s1r;
		s4i = i49 + s1i;
		s5r = valueT(-1.0833333333333333333) * r49;
		s5i = valueT(-1.0833333333333333333) * i49;
		pReal[0 * stride] = s4r;
		pImag[0 * stride] = s4i;
		s6r = s4r + s5r;
		s6i = s4i + s5i;
		r128 = s6r - s2r - s3r;
		i128 = s6i - s2i - s3i;
		r127 = s2r + s6r - r90;
		i127 = s2i + s6i - i90;
		r125 = r90 + s3r + s6r;
		i125 = i90 + s3i + s6i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		valueT s11r, s11i;
		s1r = r34 + r37;
		s1i = i34 + i37;
		s2r = r35 - r34;
		s2i = i35 - i34;
		s3r = r35 + r34 - r37;
		s3i = i35 + i34 - i37;
		s4r = valueT(-0.53193249842967457518) * s1r;
		s4i = valueT(-0.53193249842967457518) * s1i;
		s5r = s2r - s1r;
		s5i = s2i - s1i;
		s6r = valueT(1.0407474201500718718) * s2r;
		s6i = valueT(1.0407474201500718718) * s2i;
		s7r = valueT(-0.30046260628866577443) * s3r;
		s7i = valueT(-0.30046260628866577443) * s3i;
		s8r = valueT(-0.52422663952658214901) * s5r;
		s8i = valueT(-0.52422663952658214901) * s5i;
		s9r = s4r + s8r;
		s9i = s4i + s8i;
		s10r = s6r + s8r;
		s10i = s6i + s8i;
		r126 = s9r - s7r;
		i126 = s9i - s7i;
		s11r = s7r - s10r;
		s11i = s7i - s10i;
		r124 = s7r + s9r + s10r;
		i124 = s7i + s9i + s10i;
		r136 = s11r - r125;
		i136 = s11i - i125;
		r138 = r125 + s11r;
		i138 = i125 + s11i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		valueT s11r, s11i, s12r, s12i, s13r, s13i, s14r, s14i, s15r, s15i;
		valueT s16r, s16i, s17r, s17i, s18r, s18i, s19r, s19i, s20r, s20i;
		valueT s21r, s21i, s22r, s22i, s23r, s23i, s24r, s24i, s25r, s25i;
		valueT s26r, s26i, s27r, s27i, s28r, s28i, s29r, s29i;
		s1r = r19 - r20;
		s1i = i19 - i20;
		s2r = r18 + r17;
		s2i = i18 + i17;
		s3r = r20 - r16;
		s3i = i20 - i16;
		s4r = r19 + r20 + r16;
		s4i = i19 + i20 + i16;
		s5r = r15 + r17 - r18;
		s5i = i15 + i17 - i18;
		s6r = r15 - r17;
		s6i = i15 - i17;
		r83 = valueT(0.10417870810104801192) * s1i;
		i83 = valueT(-0.10417870810104801192) * s1r;
		s7r = s1r + s2r;
		s7i = s1i + s2i;
		s8r = valueT(-1.503918122830231381) * s2i;
		s8i = valueT(1.503918122830231381) * s2r;
		s9r = s1r - s3r;
		s9i = s1i - s3i;
		s10r = valueT(-2.0875863244363300084) * s3i;
		s10i = valueT(2.0875863244363300084) * s3r;
		s11r = valueT(-0.40100212832186721636) * s4i;
		s11i = valueT(0.40100212832186721636) * s4r;
		s12r = s5r - s4r;
		s12i = s5i - s4i;
		s13r = valueT(-0.74927933062613902637) * s5i;
		s13i = valueT(0.74927933062613902637) * s5r;
		s14r = s6r - s2r;
		s14i = s6i - s2i;
		s15r = -s3r - s6r;
		s15i = -s3i - s6i;
		s16r = valueT(1.5596006223820445613) * s6i;
		s16i = valueT(-1.5596006223820445613) * s6r;
		r98 = valueT(-0.42380699395323743523) * s7i;
		i98 = valueT(0.42380699395323743523) * s7r;
		s17r = valueT(-0.73058834417912600679) * s9i;
		s17i = valueT(0.73058834417912600679) * s9r;
		s18r = valueT(-0.57514072947400312137) * s12i;
		s18i = valueT(0.57514072947400312137) * s12r;
		s19r = s9r - s14r;
		s19i = s9i - s14i;
		s20r = valueT(-1.0211729150707586474) * s14i;
		s20i = valueT(1.0211729150707586474) * s14r;
		s21r = valueT(0.1598612076528611922) * s15i;
		s21i = valueT(-0.1598612076528611922) * s15r;
		s22r = s8r + r98;
		s22i = s8i + i98;
		r118 = s11r + s18r;
		i118 = s11i + s18i;
		s23r = s13r - s18r;
		s23i = s13i - s18i;
		s24r = valueT(0.087981928766792081008) * s19i;
		s24i = valueT(-0.087981928766792081008) * s19r;
		r105 = s10r - s21r;
		i105 = s10i - s21i;
		s25r = s16r + s21r;
		s25i = s16i + s21i;
		r115 = s17r - s24r;
		i115 = s17i - s24i;
		s26r = s20r + s24r;
		s26i = s20i + s24i;
		s27r = s22r + s26r;
		s27i = s22i + s26i;
		s28r = s25r + s26r;
		s28i = s25i + s26i;
		r133 = s27r - s23r;
		i133 = s27i - s23i;
		s29r = s23r - s28r;
		s29i = s23i - s28i;
		r130 = s23r + s27r + s28r;
		i130 = s23i + s27i + s28i;
		pReal[12 * stride] = r138 - s29r;
		pImag[12 * stride] = i138 - s29i;
		pReal[1 * stride] = r138 + s29r;
		pImag[1 * stride] = i138 + s29i;
	}
	{
		valueT s1r, s1i;
		s1r = r126 - r127;
		s1i = i126 - i127;
		r140 = r127 + r126;
		i140 = i127 + i126;
		pReal[10 * stride] = -r130 - s1r;
		pImag[10 * stride] = -i130 - s1i;
		pReal[3 * stride] = r130 - s1r;
		pImag[3 * stride] = i130 - s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i;
		s1r = r83 - r98;
		s1i = i83 - i98;
		s2r = r115 + s1r;
		s2i = i115 + s1i;
		s3r = r105 + r115;
		s3i = i105 + i115;
		r134 = s2r - r118;
		i134 = s2i - i118;
		s4r = s3r - r118;
		s4i = s3i - i118;
		r131 = r118 + s2r + s3r;
		i131 = i118 + s2i + s3i;
		pReal[2 * stride] = r140 - s4r;
		pImag[2 * stride] = i140 - s4i;
		pReal[11 * stride] = r140 + s4r;
		pImag[11 * stride] = i140 + s4i;
	}
	{
		valueT s1r, s1i;
		s1r = r124 - r128;
		s1i = i124 - i128;
		r141 = r128 + r124;
		i141 = i128 + i124;
		pReal[7 * stride] = -r131 - s1r;
		pImag[7 * stride] = -i131 - s1i;
		pReal[6 * stride] = r131 - s1r;
		pImag[6 * stride] = i131 - s1i;
	}
	pReal[9 * stride] = r141 - r133;
	pImag[9 * stride] = i141 - i133;
	pReal[4 * stride] = r133 + r141;
	pImag[4 * stride] = i133 + i141;
	pReal[5 * stride] = -r136 - r134;
	pImag[5 * stride] = -i136 - i134;
	pReal[8 * stride] = r134 - r136;
	pImag[8 * stride] = i134 - i136;
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
