
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

template<> StandardModuleComplexity const StandardModule<float, 26>::Complexity = { 0, 0 };
template<> StandardModuleComplexity const StandardModule<double, 26>::Complexity = { 0, 0 };

template<typename valueT>
static void ComputeCore(Phasors<valueT> const &phasors, valueT *pReal, valueT *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement)
{
	valueT r26, i26, r28, i28, r52, i52, r32, i32, r74, i74;
	valueT r78, i78, r38, i38, r36, i36, r34, i34, r30, i30;
	valueT r70, i70, r68, i68, r102, i102, r107, i107, r98, i98;
	valueT r104, i104, r180, i180, r3, i3, r5, i5, r7, i7;
	valueT r9, i9, r11, i11, r13, i13, r15, i15, r17, i17;
	valueT r19, i19, r21, i21, r23, i23, r25, i25, r41, i41;
	valueT r43, i43, r45, i45, r47, i47, r49, i49, r51, i51;
	valueT r71, i71, r75, i75, r77, i77, r97, i97, r113, i113;
	valueT r256, i256, r254, i254, r250, i250, r252, i252, r248, i248;
	valueT r276, i276, r272, i272, r164, i164, r191, i191, r234, i234;
	valueT r198, i198, r223, i223, r268, i268, r262, i262, r298, i298;
	valueT r290, i290, r167, i167, r193, i193, r207, i207, r235, i235;
	valueT r229, i229, r253, i253, r249, i249, r251, i251, r245, i245;
	valueT r263, i263, r259, i259, r273, i273, r291, i291, r267, i267;
	valueT r269, i269, r287, i287, r299, i299, r266, i266, r260, i260;
	valueT r284, i284, r274, i274, r306, i306, r286, i286, r275, i275;
	valueT r297, i297, r289, i289, r301, i301, r294, i294, r282, i282;
	valueT r292, i292, r304, i304, r277, i277, r295, i295, r285, i285;
	valueT r303, i303, r288, i288;

	phasors.Multiply(r26, i26, pReal[25 * stride], pImag[25 * stride], twiddleStart + 25 * twiddleIncrement);
	{
		valueT s1r, s1i;
		phasors.Multiply(s1r, s1i, pReal[1 * stride], pImag[1 * stride], twiddleStart + 1 * twiddleIncrement);
		r28 = s1r - r26;
		i28 = s1i - i26;
		r52 = r26 + s1r;
		i52 = i26 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i;
		phasors.Multiply(s1r, s1i, pReal[5 * stride], pImag[5 * stride], twiddleStart + 5 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[21 * stride], pImag[21 * stride], twiddleStart + 21 * twiddleIncrement);
		r32 = s1r - s2r;
		i32 = s1i - s2i;
		s3r = s1r + s2r;
		s3i = s1i + s2i;
		r74 = s3r - r52;
		i74 = s3i - i52;
		r78 = r52 + s3r;
		i78 = i52 + s3i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		valueT s11r, s11i, s12r, s12i, s13r, s13i, s14r, s14i;
		phasors.Multiply(s1r, s1i, pReal[3 * stride], pImag[3 * stride], twiddleStart + 3 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[7 * stride], pImag[7 * stride], twiddleStart + 7 * twiddleIncrement);
		phasors.Multiply(s3r, s3i, pReal[9 * stride], pImag[9 * stride], twiddleStart + 9 * twiddleIncrement);
		phasors.Multiply(s4r, s4i, pReal[11 * stride], pImag[11 * stride], twiddleStart + 11 * twiddleIncrement);
		phasors.Multiply(s5r, s5i, pReal[15 * stride], pImag[15 * stride], twiddleStart + 15 * twiddleIncrement);
		phasors.Multiply(s6r, s6i, pReal[17 * stride], pImag[17 * stride], twiddleStart + 17 * twiddleIncrement);
		phasors.Multiply(s7r, s7i, pReal[19 * stride], pImag[19 * stride], twiddleStart + 19 * twiddleIncrement);
		phasors.Multiply(s8r, s8i, pReal[23 * stride], pImag[23 * stride], twiddleStart + 23 * twiddleIncrement);
		r38 = s4r - s5r;
		i38 = s4i - s5i;
		s9r = s4r + s5r;
		s9i = s4i + s5i;
		r36 = s3r - s6r;
		i36 = s3i - s6i;
		s10r = s3r + s6r;
		s10i = s3i + s6i;
		r34 = s2r - s7r;
		i34 = s2i - s7i;
		s11r = s2r + s7r;
		s11i = s2i + s7i;
		r30 = s1r - s8r;
		i30 = s1i - s8i;
		s12r = s1r + s8r;
		s12i = s1i + s8i;
		r70 = s10r - s11r;
		i70 = s10i - s11i;
		s13r = s10r + s11r;
		s13i = s10i + s11i;
		r68 = s9r - s12r;
		i68 = s9i - s12i;
		s14r = s9r + s12r;
		s14i = s9i + s12i;
		r102 = s14r - s13r;
		i102 = s14i - s13i;
		r107 = s13r - r78;
		i107 = s13i - i78;
		r98 = r78 + s13r + s14r;
		i98 = i78 + s13i + s14i;
		r104 = r78 - s14r;
		i104 = i78 - s14i;
	}
	r180 = valueT(-0.57944001890096049323) * r104;
	i180 = valueT(-0.57944001890096049323) * i104;
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i;
		phasors.Multiply(s1r, s1i, pReal[0 * stride], pImag[0 * stride], twiddleStart + 0 * twiddleIncrement);
		phasors.Multiply(r3, i3, pReal[2 * stride], pImag[2 * stride], twiddleStart + 2 * twiddleIncrement);
		phasors.Multiply(r5, i5, pReal[4 * stride], pImag[4 * stride], twiddleStart + 4 * twiddleIncrement);
		phasors.Multiply(r7, i7, pReal[6 * stride], pImag[6 * stride], twiddleStart + 6 * twiddleIncrement);
		phasors.Multiply(r9, i9, pReal[8 * stride], pImag[8 * stride], twiddleStart + 8 * twiddleIncrement);
		phasors.Multiply(r11, i11, pReal[10 * stride], pImag[10 * stride], twiddleStart + 10 * twiddleIncrement);
		phasors.Multiply(r13, i13, pReal[12 * stride], pImag[12 * stride], twiddleStart + 12 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[13 * stride], pImag[13 * stride], twiddleStart + 13 * twiddleIncrement);
		phasors.Multiply(r15, i15, pReal[14 * stride], pImag[14 * stride], twiddleStart + 14 * twiddleIncrement);
		phasors.Multiply(r17, i17, pReal[16 * stride], pImag[16 * stride], twiddleStart + 16 * twiddleIncrement);
		phasors.Multiply(r19, i19, pReal[18 * stride], pImag[18 * stride], twiddleStart + 18 * twiddleIncrement);
		phasors.Multiply(r21, i21, pReal[20 * stride], pImag[20 * stride], twiddleStart + 20 * twiddleIncrement);
		phasors.Multiply(r23, i23, pReal[22 * stride], pImag[22 * stride], twiddleStart + 22 * twiddleIncrement);
		phasors.Multiply(r25, i25, pReal[24 * stride], pImag[24 * stride], twiddleStart + 24 * twiddleIncrement);
		r41 = r13 + r15;
		i41 = i13 + i15;
		r43 = r11 + r17;
		i43 = i11 + i17;
		r45 = r9 + r19;
		i45 = i9 + i19;
		r47 = r7 + r21;
		i47 = i7 + i21;
		r49 = r5 + r23;
		i49 = i5 + i23;
		r51 = r3 + r25;
		i51 = i3 + i25;
		r71 = r41 + r45;
		i71 = i41 + i45;
		r75 = r47 + r49;
		i75 = i47 + i49;
		r77 = r43 + r51;
		i77 = i43 + i51;
		r97 = r71 + r75 + r77;
		i97 = i71 + i75 + i77;
		s3r = valueT(-0.42763404682657276126) * r102;
		s3i = valueT(-0.42763404682657276126) * i102;
		r113 = s1r + r97;
		i113 = s1i + i97;
		s4r = valueT(-0.15180597207438773197) * r107;
		s4i = valueT(-0.15180597207438773197) * i107;
		s5r = r98 + s2r;
		s5i = i98 + s2i;
		s6r = valueT(-1.0833333333333333333) * r98;
		s6i = valueT(-1.0833333333333333333) * i98;
		pReal[13 * stride] = r113 - s5r;
		pImag[13 * stride] = i113 - s5i;
		pReal[0 * stride] = r113 + s5r;
		pImag[0 * stride] = i113 + s5i;
		s7r = s5r + s6r;
		s7i = s5i + s6i;
		r256 = s4r + s7r - s3r;
		i256 = s4i + s7i - s3i;
		r254 = r180 + s3r + s7r;
		i254 = i180 + s3i + s7i;
		r250 = s7r - r180 - s4r;
		i250 = s7i - i180 - s4i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		valueT s11r, s11i;
		s1r = r70 - r74 - r68;
		s1i = i70 - i74 - i68;
		s2r = r74 + r70;
		s2i = i74 + i70;
		s3r = r68 - r74;
		s3i = i68 - i74;
		s4r = valueT(-0.30046260628866577443) * s1r;
		s4i = valueT(-0.30046260628866577443) * s1i;
		s5r = valueT(0.53193249842967457518) * s2r;
		s5i = valueT(0.53193249842967457518) * s2i;
		s6r = s2r - s3r;
		s6i = s2i - s3i;
		s7r = valueT(-1.0407474201500718718) * s3r;
		s7i = valueT(-1.0407474201500718718) * s3i;
		s8r = valueT(-0.52422663952658214901) * s6r;
		s8i = valueT(-0.52422663952658214901) * s6i;
		s9r = s5r + s8r;
		s9i = s5i + s8i;
		s10r = s7r + s8r;
		s10i = s7i + s8i;
		r252 = s9r - s4r;
		i252 = s9i - s4i;
		r248 = s4r - s10r;
		i248 = s4i - s10i;
		s11r = s4r + s9r + s10r;
		s11i = s4i + s9i + s10i;
		r276 = r250 - s11r;
		i276 = i250 - s11i;
		r272 = r250 + s11r;
		i272 = i250 + s11i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		valueT s11r, s11i, s12r, s12i, s13r, s13i, s14r, s14i, s15r, s15i;
		valueT s16r, s16i, s17r, s17i, s18r, s18i, s19r, s19i, s20r, s20i;
		valueT s21r, s21i, s22r, s22i, s23r, s23i, s24r, s24i, s25r, s25i;
		valueT s26r, s26i, s27r, s27i, s28r, s28i, s29r, s29i;
		s1r = r38 - r34;
		s1i = i38 - i34;
		s2r = r38 + r34 - r32;
		s2i = i38 + i34 - i32;
		s3r = r32 + r34;
		s3i = i32 + i34;
		s4r = r36 - r28;
		s4i = i36 - i28;
		s5r = r28 + r36 + r30;
		s5i = i28 + i36 + i30;
		s6r = r28 - r30;
		s6i = i28 - i30;
		s7r = valueT(-1.5596006223820445613) * s1i;
		s7i = valueT(1.5596006223820445613) * s1r;
		s8r = valueT(0.74927933062613902637) * s2i;
		s8i = valueT(-0.74927933062613902637) * s2r;
		s9r = s3r - s1r;
		s9i = s3i - s1i;
		s10r = valueT(1.503918122830231381) * s3i;
		s10i = valueT(-1.503918122830231381) * s3r;
		s11r = s1r - s4r;
		s11i = s1i - s4i;
		r164 = valueT(-2.0875863244363300084) * s4i;
		i164 = valueT(2.0875863244363300084) * s4r;
		s12r = s5r - s2r;
		s12i = s5i - s2i;
		s13r = valueT(0.40100212832186721636) * s5i;
		s13i = valueT(-0.40100212832186721636) * s5r;
		s14r = s6r - s3r;
		s14i = s6i - s3i;
		s15r = s6r - s4r;
		s15i = s6i - s4i;
		s16r = valueT(0.10417870810104801192) * s6i;
		s16i = valueT(-0.10417870810104801192) * s6r;
		s17r = valueT(-1.0211729150707586474) * s9i;
		s17i = valueT(1.0211729150707586474) * s9r;
		r191 = valueT(0.1598612076528611922) * s11i;
		i191 = valueT(-0.1598612076528611922) * s11r;
		s18r = valueT(-0.57514072947400312137) * s12i;
		s18i = valueT(0.57514072947400312137) * s12r;
		s19r = valueT(-0.42380699395323743523) * s14i;
		s19i = valueT(0.42380699395323743523) * s14r;
		s20r = s15r - s9r;
		s20i = s15i - s9i;
		s21r = valueT(-0.73058834417912600679) * s15i;
		s21i = valueT(0.73058834417912600679) * s15r;
		s22r = s7r + r191;
		s22i = s7i + i191;
		s23r = s8r - s18r;
		s23i = s8i - s18i;
		r234 = s13r + s18r;
		i234 = s13i + s18i;
		s24r = s10r + s19r;
		s24i = s10i + s19i;
		r198 = s16r - s19r;
		i198 = s16i - s19i;
		s25r = valueT(0.087981928766792081008) * s20i;
		s25i = valueT(-0.087981928766792081008) * s20r;
		s26r = s17r + s25r;
		s26i = s17i + s25i;
		r223 = s21r - s25r;
		i223 = s21i - s25i;
		s27r = s22r + s26r;
		s27i = s22i + s26i;
		s28r = s24r + s26r;
		s28i = s24i + s26i;
		r268 = s27r - s23r;
		i268 = s27i - s23i;
		s29r = s23r - s28r;
		s29i = s23i - s28i;
		r262 = s23r + s27r + s28r;
		i262 = s23i + s27i + s28i;
		r298 = r272 - s29r;
		i298 = i272 - s29i;
		r290 = r272 + s29r;
		i290 = i272 + s29i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		valueT s11r, s11i, s12r, s12i, s13r, s13i, s14r, s14i, s15r, s15i;
		valueT s16r, s16i, s17r, s17i, s18r, s18i, s19r, s19i, s20r, s20i;
		valueT s21r, s21i, s22r, s22i, s23r, s23i, s24r, s24i, s25r, s25i;
		valueT s26r, s26i, s27r, s27i, s28r, s28i, s29r, s29i, s30r, s30i;
		valueT s31r, s31i, s32r, s32i, s33r, s33i, s34r, s34i, s35r, s35i;
		valueT s36r, s36i, s37r, s37i, s38r, s38i, s39r, s39i, s40r, s40i;
		valueT s41r, s41i, s42r, s42i, s43r, s43i, s44r, s44i, s45r, s45i;
		valueT s46r, s46i, s47r, s47i, s48r, s48i, s49r, s49i, s50r, s50i;
		valueT s51r, s51i, s52r, s52i, s53r, s53i, s54r, s54i, s55r, s55i;
		valueT s56r, s56i, s57r, s57i, s58r, s58i, s59r, s59i, s60r, s60i;
		s1r = r13 - r15;
		s1i = i13 - i15;
		s2r = r11 - r17;
		s2i = i11 - i17;
		s3r = r9 - r19;
		s3i = i9 - i19;
		s4r = r7 - r21;
		s4i = i7 - i21;
		s5r = r5 - r23;
		s5i = i5 - i23;
		s6r = r3 - r25;
		s6i = i3 - i25;
		s7r = s2r - s1r;
		s7i = s2i - s1i;
		s8r = r41 - r45;
		s8i = i41 - i45;
		s9r = s3r + s4r;
		s9i = s3i + s4i;
		s10r = s1r - s5r;
		s10i = s1i - s5i;
		s11r = s1r + s2r + s5r;
		s11i = s1i + s2i + s5i;
		s12r = r47 - r49;
		s12i = i47 - i49;
		s13r = s4r + s6r - s3r;
		s13i = s4i + s6i - s3i;
		s14r = s6r - s4r;
		s14i = s6i - s4i;
		s15r = r43 - r51;
		s15i = i43 - i51;
		s16r = valueT(0.10417870810104801192) * s7i;
		s16i = valueT(-0.10417870810104801192) * s7r;
		s17r = s7r + s9r;
		s17i = s7i + s9i;
		s18r = valueT(-1.503918122830231381) * s9i;
		s18i = valueT(1.503918122830231381) * s9r;
		s19r = s7r - s10r;
		s19i = s7i - s10i;
		r167 = valueT(-2.0875863244363300084) * s10i;
		i167 = valueT(2.0875863244363300084) * s10r;
		s20r = valueT(-0.40100212832186721636) * s11i;
		s20i = valueT(0.40100212832186721636) * s11r;
		s21r = s8r + s12r;
		s21i = s8i + s12i;
		s22r = r75 - r71;
		s22i = i75 - i71;
		s23r = s13r - s11r;
		s23i = s13i - s11i;
		s24r = valueT(-0.74927933062613902637) * s13i;
		s24i = valueT(0.74927933062613902637) * s13r;
		s25r = s14r - s9r;
		s25i = s14i - s9i;
		s26r = -s10r - s14r;
		s26i = -s10i - s14i;
		s27r = valueT(1.5596006223820445613) * s14i;
		s27i = valueT(-1.5596006223820445613) * s14r;
		s28r = s15r - s8r;
		s28i = s15i - s8i;
		s29r = s8r + s15r - s12r;
		s29i = s8i + s15i - s12i;
		s30r = r71 - r77;
		s30i = i71 - i77;
		s31r = r77 - r75;
		s31i = i77 - i75;
		s32r = valueT(-0.42380699395323743523) * s17i;
		s32i = valueT(0.42380699395323743523) * s17r;
		s33r = valueT(-0.73058834417912600679) * s19i;
		s33i = valueT(0.73058834417912600679) * s19r;
		s34r = valueT(-0.53193249842967457518) * s21r;
		s34i = valueT(-0.53193249842967457518) * s21i;
		s35r = valueT(-0.15180597207438773197) * s22r;
		s35i = valueT(-0.15180597207438773197) * s22i;
		s36r = valueT(-0.57514072947400312137) * s23i;
		s36i = valueT(0.57514072947400312137) * s23r;
		s37r = s19r - s25r;
		s37i = s19i - s25i;
		s38r = valueT(-1.0211729150707586474) * s25i;
		s38i = valueT(1.0211729150707586474) * s25r;
		r193 = valueT(0.1598612076528611922) * s26i;
		i193 = valueT(-0.1598612076528611922) * s26r;
		s39r = s28r - s21r;
		s39i = s28i - s21i;
		s40r = valueT(1.0407474201500718718) * s28r;
		s40i = valueT(1.0407474201500718718) * s28i;
		s41r = valueT(-0.30046260628866577443) * s29r;
		s41i = valueT(-0.30046260628866577443) * s29i;
		s42r = valueT(-0.57944001890096049323) * s30r;
		s42i = valueT(-0.57944001890096049323) * s30i;
		s43r = valueT(-1.0833333333333333333) * r97;
		s43i = valueT(-1.0833333333333333333) * i97;
		s44r = valueT(-0.42763404682657276126) * s31r;
		s44i = valueT(-0.42763404682657276126) * s31i;
		r207 = s16r - s32r;
		i207 = s16i - s32i;
		s45r = s18r + s32r;
		s45i = s18i + s32i;
		r235 = s20r + s36r;
		i235 = s20i + s36i;
		s46r = s24r - s36r;
		s46i = s24i - s36i;
		s47r = valueT(0.087981928766792081008) * s37i;
		s47i = valueT(-0.087981928766792081008) * s37r;
		s48r = s27r + r193;
		s48i = s27i + i193;
		s49r = valueT(-0.52422663952658214901) * s39r;
		s49i = valueT(-0.52422663952658214901) * s39i;
		s50r = r113 + s43r;
		s50i = i113 + s43i;
		r229 = s33r - s47r;
		i229 = s33i - s47i;
		s51r = s38r + s47r;
		s51i = s38i + s47i;
		s52r = s34r + s49r;
		s52i = s34i + s49i;
		s53r = s40r + s49r;
		s53i = s40i + s49i;
		s54r = s50r - s35r - s42r;
		s54i = s50i - s35i - s42i;
		r253 = s35r + s50r - s44r;
		i253 = s35i + s50i - s44i;
		r249 = s42r + s44r + s50r;
		i249 = s42i + s44i + s50i;
		s55r = s45r + s51r;
		s55i = s45i + s51i;
		s56r = s48r + s51r;
		s56i = s48i + s51i;
		r251 = s52r - s41r;
		i251 = s52i - s41i;
		r245 = s41r - s53r;
		i245 = s41i - s53i;
		s57r = s41r + s52r + s53r;
		s57i = s41i + s52i + s53i;
		s58r = s55r - s46r;
		s58i = s55i - s46i;
		r263 = s46r - s56r;
		i263 = s46i - s56i;
		r259 = s46r + s55r + s56r;
		i259 = s46i + s55i + s56i;
		r273 = s57r - s54r;
		i273 = s57i - s54i;
		s59r = s54r + s57r;
		s59i = s54i + s57i;
		s60r = s59r - s58r;
		s60i = s59i - s58i;
		r291 = s58r + s59r;
		i291 = s58i + s59i;
		pReal[9 * stride] = s60r - r290;
		pImag[9 * stride] = s60i - i290;
		pReal[22 * stride] = r290 + s60r;
		pImag[22 * stride] = i290 + s60i;
	}
	pReal[17 * stride] = r291 - r298;
	pImag[17 * stride] = i291 - i298;
	pReal[4 * stride] = r298 + r291;
	pImag[4 * stride] = i298 + i291;
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i;
		s1r = r167 - r193;
		s1i = i167 - i193;
		s2r = r207 + r229;
		s2i = i207 + i229;
		s3r = r229 + s1r;
		s3i = i229 + s1i;
		r267 = s2r - r235;
		i267 = s2i - i235;
		r269 = s3r - r235;
		i269 = s3i - i235;
		s4r = r235 + s2r + s3r;
		s4i = i235 + s2i + s3i;
		r287 = s4r - r273;
		i287 = s4i - i273;
		r299 = r273 + s4r;
		i299 = i273 + s4i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		s1r = r164 - r191;
		s1i = i164 - i191;
		s2r = r223 + s1r;
		s2i = i223 + s1i;
		s3r = r198 + r223;
		s3i = i198 + i223;
		r266 = s2r - r234;
		i266 = s2i - i234;
		r260 = r234 - s3r;
		i260 = i234 - s3i;
		s4r = r234 + s2r + s3r;
		s4i = i234 + s2i + s3i;
		s5r = r276 - s4r;
		s5i = i276 - s4i;
		r284 = r276 + s4r;
		i284 = i276 + s4i;
		pReal[7 * stride] = -r299 - s5r;
		pImag[7 * stride] = -i299 - s5i;
		pReal[20 * stride] = s5r - r299;
		pImag[20 * stride] = s5i - i299;
	}
	pReal[19 * stride] = r287 - r284;
	pImag[19 * stride] = i287 - i284;
	pReal[6 * stride] = r287 + r284;
	pImag[6 * stride] = i287 + i284;
	{
		valueT s1r, s1i;
		s1r = r254 - r248;
		s1i = i254 - i248;
		r274 = r254 + r248;
		i274 = i254 + i248;
		r306 = s1r - r260;
		i306 = s1i - i260;
		r286 = r260 + s1r;
		i286 = i260 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i;
		s1r = r245 - r249;
		s1i = i245 - i249;
		r275 = r249 + r245;
		i275 = i249 + i245;
		r297 = s1r - r267;
		i297 = s1i - i267;
		s2r = r267 + s1r;
		s2i = i267 + s1i;
		pReal[5 * stride] = -r286 - s2r;
		pImag[5 * stride] = -i286 - s2i;
		pReal[18 * stride] = r286 - s2r;
		pImag[18 * stride] = i286 - s2i;
	}
	pReal[21 * stride] = -r306 - r297;
	pImag[21 * stride] = -i306 - i297;
	pReal[8 * stride] = r306 - r297;
	pImag[8 * stride] = i306 - i297;
	r289 = r263 - r275;
	i289 = i263 - i275;
	r301 = r263 + r275;
	i301 = i263 + i275;
	{
		valueT s1r, s1i;
		s1r = r274 - r268;
		s1i = i274 - i268;
		r294 = r268 + r274;
		i294 = i268 + i274;
		pReal[1 * stride] = r301 - s1r;
		pImag[1 * stride] = i301 - s1i;
		pReal[14 * stride] = r301 + s1r;
		pImag[14 * stride] = i301 + s1i;
	}
	pReal[25 * stride] = -r289 - r294;
	pImag[25 * stride] = -i289 - i294;
	pReal[12 * stride] = r294 - r289;
	pImag[12 * stride] = i294 - i289;
	{
		valueT s1r, s1i;
		r282 = r256 - r252;
		i282 = i256 - i252;
		s1r = r256 + r252;
		s1i = i256 + i252;
		r292 = r266 - s1r;
		i292 = i266 - s1i;
		r304 = r266 + s1r;
		i304 = i266 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i;
		r277 = r251 - r253;
		i277 = i251 - i253;
		s1r = r253 + r251;
		s1i = i253 + i251;
		r295 = r269 - s1r;
		i295 = i269 - s1i;
		s2r = r269 + s1r;
		s2i = i269 + s1i;
		pReal[11 * stride] = s2r - r304;
		pImag[11 * stride] = s2i - i304;
		pReal[24 * stride] = r304 + s2r;
		pImag[24 * stride] = i304 + s2i;
	}
	pReal[2 * stride] = -r292 - r295;
	pImag[2 * stride] = -i292 - i295;
	pReal[15 * stride] = r292 - r295;
	pImag[15 * stride] = i292 - i295;
	r285 = r259 - r277;
	i285 = i259 - i277;
	r303 = r259 + r277;
	i303 = i259 + i277;
	{
		valueT s1r, s1i;
		s1r = r282 - r262;
		s1i = i282 - i262;
		r288 = r262 + r282;
		i288 = i262 + i282;
		pReal[23 * stride] = -r303 - s1r;
		pImag[23 * stride] = -i303 - s1i;
		pReal[10 * stride] = s1r - r303;
		pImag[10 * stride] = s1i - i303;
	}
	pReal[3 * stride] = r285 - r288;
	pImag[3 * stride] = i285 - i288;
	pReal[16 * stride] = r285 + r288;
	pImag[16 * stride] = i285 + i288;
}

template<> void StandardModule<float, 26>::Compute(float *pReal, float *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

template<> void StandardModule<double, 26>::Compute(double *pReal, double *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

}
}
