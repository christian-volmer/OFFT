
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

template<> StandardModuleComplexity const StandardModule<float, 30>::Complexity = { 0, 0 };
template<> StandardModuleComplexity const StandardModule<double, 30>::Complexity = { 0, 0 };

template<typename valueT>
static void ComputeCore(Phasors<valueT> const &phasors, valueT *pReal, valueT *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement)
{
	valueT r30, i30, r50, i50, r60, i60, r32, i32, r82, i82;
	valueT r70, i70, r102, i102, r120, i120, r38, i38, r44, i44;
	valueT r88, i88, r64, i64, r108, i108, r144, i144, r150, i150;
	valueT r36, i36, r76, i76, r182, i182, r222, i222, r3, i3;
	valueT r5, i5, r9, i9, r11, i11, r15, i15, r17, i17;
	valueT r21, i21, r23, i23, r27, i27, r29, i29, r45, i45;
	valueT r51, i51, r53, i53, r57, i57, r59, i59, r117, i117;
	valueT r119, i119, r149, i149, r213, i213, r258, i258, r345, i345;
	valueT r350, i350, r105, i105, r113, i113, r94, i94, r97, i97;
	valueT r103, i103, r100, i100, r139, i139, r142, i142, r253, i253;
	valueT r325, i325, r256, i256, r380, i380, r98, i98, r95, i95;
	valueT r93, i93, r92, i92, r137, i137, r134, i134, r237, i237;
	valueT r248, i248, r330, i330, r278, i278, r284, i284, r272, i272;
	valueT r296, i296, r314, i314, r267, i267, r273, i273, r299, i299;
	valueT r341, i341, r344, i344, r287, i287, r282, i282, r277, i277;
	valueT r268, i268, r283, i283, r291, i291, r286, i286, r288, i288;
	valueT r301, i301, r309, i309, r304, i304, r306, i306, r349, i349;
	valueT r353, i353, r383, i383, r339, i339, r336, i336, r334, i334;
	valueT r366, i366, r329, i329, r318, i318, r312, i312, r317, i317;
	valueT r351, i351, r342, i342, r307, i307, r316, i316, r343, i343;
	valueT r372, i372, r303, i303, r308, i308, r327, i327, r333, i333;
	valueT r338, i338, r346, i346, r348, i348, r378, i378;

	phasors.Multiply(r30, i30, pReal[29 * stride], pImag[29 * stride], twiddleStart + 29 * twiddleIncrement);
	{
		valueT s1r, s1i;
		phasors.Multiply(s1r, s1i, pReal[19 * stride], pImag[19 * stride], twiddleStart + 19 * twiddleIncrement);
		r50 = s1r - r30;
		i50 = s1i - i30;
		r60 = r30 + s1r;
		i60 = i30 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		phasors.Multiply(s1r, s1i, pReal[1 * stride], pImag[1 * stride], twiddleStart + 1 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[9 * stride], pImag[9 * stride], twiddleStart + 9 * twiddleIncrement);
		phasors.Multiply(s3r, s3i, pReal[11 * stride], pImag[11 * stride], twiddleStart + 11 * twiddleIncrement);
		phasors.Multiply(s4r, s4i, pReal[21 * stride], pImag[21 * stride], twiddleStart + 21 * twiddleIncrement);
		r32 = s1r - s3r;
		i32 = s1i - s3i;
		s5r = s1r + s3r;
		s5i = s1i + s3i;
		r82 = s4r + s5r;
		i82 = s4i + s5i;
		r70 = r60 + s2r;
		i70 = i60 + s2i;
		r102 = s5r - r60;
		i102 = s5i - i60;
		r120 = r60 + s5r;
		i120 = i60 + s5i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i;
		phasors.Multiply(s1r, s1i, pReal[3 * stride], pImag[3 * stride], twiddleStart + 3 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[7 * stride], pImag[7 * stride], twiddleStart + 7 * twiddleIncrement);
		phasors.Multiply(s3r, s3i, pReal[13 * stride], pImag[13 * stride], twiddleStart + 13 * twiddleIncrement);
		phasors.Multiply(s4r, s4i, pReal[17 * stride], pImag[17 * stride], twiddleStart + 17 * twiddleIncrement);
		phasors.Multiply(s5r, s5i, pReal[23 * stride], pImag[23 * stride], twiddleStart + 23 * twiddleIncrement);
		phasors.Multiply(s6r, s6i, pReal[27 * stride], pImag[27 * stride], twiddleStart + 27 * twiddleIncrement);
		r38 = s2r - s4r;
		i38 = s2i - s4i;
		s7r = s2r + s4r;
		s7i = s2i + s4i;
		r44 = s3r - s5r;
		i44 = s3i - s5i;
		s8r = s3r + s5r;
		s8i = s3i + s5i;
		r88 = s6r + s7r;
		i88 = s6i + s7i;
		r64 = s1r + s8r;
		i64 = s1i + s8i;
		r108 = s7r - s8r;
		i108 = s7i - s8i;
		s9r = s7r + s8r;
		s9i = s7i + s8i;
		r144 = s9r - r120;
		i144 = s9i - i120;
		r150 = r120 + s9r;
		i150 = i120 + s9i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i;
		phasors.Multiply(s1r, s1i, pReal[5 * stride], pImag[5 * stride], twiddleStart + 5 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[15 * stride], pImag[15 * stride], twiddleStart + 15 * twiddleIncrement);
		phasors.Multiply(s3r, s3i, pReal[25 * stride], pImag[25 * stride], twiddleStart + 25 * twiddleIncrement);
		r36 = s1r - s3r;
		i36 = s1i - s3i;
		s4r = s1r + s3r;
		s4i = s1i + s3i;
		r76 = s2r + s4r;
		i76 = s2i + s4i;
		r182 = r150 + s4r;
		i182 = i150 + s4i;
		r222 = valueT(1.875) * r150;
		i222 = valueT(1.875) * i150;
	}
	{
		valueT s1r, s1i, s2r, s2i;
		phasors.Multiply(r3, i3, pReal[2 * stride], pImag[2 * stride], twiddleStart + 2 * twiddleIncrement);
		phasors.Multiply(r5, i5, pReal[4 * stride], pImag[4 * stride], twiddleStart + 4 * twiddleIncrement);
		phasors.Multiply(r9, i9, pReal[8 * stride], pImag[8 * stride], twiddleStart + 8 * twiddleIncrement);
		phasors.Multiply(r11, i11, pReal[10 * stride], pImag[10 * stride], twiddleStart + 10 * twiddleIncrement);
		phasors.Multiply(r15, i15, pReal[14 * stride], pImag[14 * stride], twiddleStart + 14 * twiddleIncrement);
		phasors.Multiply(r17, i17, pReal[16 * stride], pImag[16 * stride], twiddleStart + 16 * twiddleIncrement);
		phasors.Multiply(r21, i21, pReal[20 * stride], pImag[20 * stride], twiddleStart + 20 * twiddleIncrement);
		phasors.Multiply(r23, i23, pReal[22 * stride], pImag[22 * stride], twiddleStart + 22 * twiddleIncrement);
		phasors.Multiply(r27, i27, pReal[26 * stride], pImag[26 * stride], twiddleStart + 26 * twiddleIncrement);
		phasors.Multiply(r29, i29, pReal[28 * stride], pImag[28 * stride], twiddleStart + 28 * twiddleIncrement);
		r45 = r5 + r15;
		i45 = i5 + i15;
		r51 = r11 + r21;
		i51 = i11 + i21;
		r53 = r3 + r23;
		i53 = i3 + i23;
		r57 = r17 + r27;
		i57 = i17 + i27;
		r59 = r9 + r29;
		i59 = i9 + i29;
		r117 = r45 + r57;
		i117 = i45 + i57;
		r119 = r53 + r59;
		i119 = i53 + i59;
		r149 = r117 + r119;
		i149 = i117 + i119;
		s1r = r51 + r149;
		s1i = i51 + i149;
		r213 = valueT(-1.5) * s1r;
		i213 = valueT(-1.5) * s1i;
		s2r = valueT(-1.5) * r182;
		s2i = valueT(-1.5) * i182;
		r258 = r222 + s2r;
		i258 = i222 + s2i;
		r345 = r213 - s2r;
		i345 = i213 - s2i;
		r350 = r213 + s2r;
		i350 = i213 + s2i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		valueT s11r, s11i, s12r, s12i, s13r, s13i, s14r, s14i, s15r, s15i;
		valueT s16r, s16i, s17r, s17i, s18r, s18i, s19r, s19i, s20r, s20i;
		valueT s21r, s21i;
		phasors.Multiply(s1r, s1i, pReal[0 * stride], pImag[0 * stride], twiddleStart + 0 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[6 * stride], pImag[6 * stride], twiddleStart + 6 * twiddleIncrement);
		phasors.Multiply(s3r, s3i, pReal[12 * stride], pImag[12 * stride], twiddleStart + 12 * twiddleIncrement);
		phasors.Multiply(s4r, s4i, pReal[18 * stride], pImag[18 * stride], twiddleStart + 18 * twiddleIncrement);
		phasors.Multiply(s5r, s5i, pReal[24 * stride], pImag[24 * stride], twiddleStart + 24 * twiddleIncrement);
		s6r = r45 + s5r;
		s6i = i45 + s5i;
		s7r = r51 + s1r;
		s7i = i51 + s1i;
		s8r = r53 + s3r;
		s8i = i53 + s3i;
		s9r = r57 + s2r;
		s9i = i57 + s2i;
		r105 = r45 - r57;
		i105 = i45 - i57;
		s10r = r59 + s4r;
		s10i = i59 + s4i;
		r113 = r53 - r59;
		i113 = i53 - i59;
		r94 = r64 - r88;
		i94 = i64 - i88;
		s11r = r88 + r64;
		s11i = i88 + i64;
		r97 = s9r - s6r;
		i97 = s9i - s6i;
		s12r = s6r + s9r;
		s12i = s6i + s9i;
		r103 = s8r - s10r;
		i103 = s8i - s10i;
		s13r = s8r + s10r;
		s13i = s8i + s10i;
		r100 = r70 - r82;
		i100 = i70 - i82;
		s14r = r82 + r70;
		s14i = i82 + i70;
		r139 = s13r - s12r;
		i139 = s13i - s12i;
		s15r = s12r + s13r;
		s15i = s12i + s13i;
		r142 = s14r - s11r;
		i142 = s14i - s11i;
		s16r = s11r + s14r;
		s16i = s11i + s14i;
		s17r = s7r + s15r;
		s17i = s7i + s15i;
		s18r = valueT(-1.25) * s15r;
		s18i = valueT(-1.25) * s15i;
		s19r = r76 + s16r;
		s19i = i76 + s16i;
		s20r = valueT(-1.25) * s16r;
		s20i = valueT(-1.25) * s16i;
		r253 = s17r + s18r;
		i253 = s17i + s18i;
		r325 = s17r - s19r;
		i325 = s17i - s19i;
		s21r = s17r + s19r;
		s21i = s17i + s19i;
		r256 = s19r + s20r;
		i256 = s19i + s20i;
		pReal[0 * stride] = s21r;
		pImag[0 * stride] = s21i;
		r380 = r350 + s21r;
		i380 = i350 + s21i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		valueT s11r, s11i, s12r, s12i, s13r, s13i, s14r, s14i, s15r, s15i;
		valueT s16r, s16i, s17r, s17i, s18r, s18i;
		s1r = r5 - r15;
		s1i = i5 - i15;
		s2r = r11 - r21;
		s2i = i11 - i21;
		s3r = r3 - r23;
		s3i = i3 - i23;
		s4r = r17 - r27;
		s4i = i17 - i27;
		s5r = r9 - r29;
		s5i = i9 - i29;
		r98 = r38 - r44;
		i98 = i38 - i44;
		s6r = r38 + r44;
		s6i = i38 + i44;
		r95 = s1r - s4r;
		i95 = s1i - s4i;
		s7r = s1r + s4r;
		s7i = s1i + s4i;
		r93 = s3r - s5r;
		i93 = s3i - s5i;
		s8r = s3r + s5r;
		s8i = s3i + s5i;
		r92 = r32 - r50;
		i92 = i32 - i50;
		s9r = r50 + r32;
		s9i = i50 + i32;
		s10r = s8r - s7r;
		s10i = s8i - s7i;
		r137 = s7r + s8r;
		i137 = s7i + s8i;
		r134 = s6r - s9r;
		i134 = s6i - s9i;
		s11r = s6r + s9r;
		s11i = s6i + s9i;
		s12r = s2r - s10r;
		s12i = s2i - s10i;
		s13r = valueT(-1.0825317547305483085) * s10i;
		s13i = valueT(1.0825317547305483085) * s10r;
		s14r = r36 - s11r;
		s14i = i36 - s11i;
		s15r = valueT(1.0825317547305483085) * s11i;
		s15i = valueT(-1.0825317547305483085) * s11r;
		s16r = valueT(-0.86602540378443864676) * s12i;
		s16i = valueT(0.86602540378443864676) * s12r;
		s17r = valueT(0.86602540378443864676) * s14i;
		s17i = valueT(-0.86602540378443864676) * s14r;
		r237 = s13r + s16r;
		i237 = s13i + s16i;
		r248 = s15r + s17r;
		i248 = s15i + s17i;
		r330 = s17r - s16r;
		i330 = s17i - s16i;
		s18r = s16r + s17r;
		s18i = s16i + s17i;
		pReal[20 * stride] = r380 - s18r;
		pImag[20 * stride] = i380 - s18i;
		pReal[10 * stride] = r380 + s18r;
		pImag[10 * stride] = i380 + s18i;
	}
	{
		valueT s1r, s1i;
		pReal[15 * stride] = r325;
		pImag[15 * stride] = i325;
		s1r = r345 + r325;
		s1i = i345 + i325;
		pReal[25 * stride] = s1r - r330;
		pImag[25 * stride] = s1i - i330;
		pReal[5 * stride] = r330 + s1r;
		pImag[5 * stride] = i330 + s1i;
	}
	{
		valueT s1r, s1i;
		s1r = valueT(0.48412291827592711065) * i134;
		s1i = valueT(-0.48412291827592711065) * r134;
		r278 = s1r - r248;
		i278 = s1i - i248;
		r284 = r248 + s1r;
		i284 = i248 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		s1r = valueT(0.31460214309120474243) * r98;
		s1i = valueT(0.31460214309120474243) * i98;
		s2r = r98 - r92;
		s2i = i98 - i92;
		s3r = valueT(-1.3326760640014591093) * r92;
		s3i = valueT(-1.3326760640014591093) * i92;
		s4r = valueT(-0.50903696045512718345) * s2r;
		s4i = valueT(-0.50903696045512718345) * s2i;
		r272 = s1r - s4r;
		i272 = s1i - s4i;
		s5r = s3r + s4r;
		s5i = s3i + s4i;
		r296 = s5r - r284;
		i296 = s5i - i284;
		r314 = r284 + s5r;
		i314 = i284 + s5i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i;
		s1r = valueT(1.3326760640014591093) * r95;
		s1i = valueT(1.3326760640014591093) * i95;
		s2r = r93 - r95;
		s2i = i93 - i95;
		s3r = valueT(-0.31460214309120474243) * r93;
		s3i = valueT(-0.31460214309120474243) * i93;
		s4r = valueT(0.50903696045512718345) * s2r;
		s4i = valueT(0.50903696045512718345) * s2i;
		s5r = valueT(-0.48412291827592711065) * i137;
		s5i = valueT(0.48412291827592711065) * r137;
		s6r = s1r + s4r;
		s6i = s1i + s4i;
		r267 = s3r - s4r;
		i267 = s3i - s4i;
		r273 = r237 - s5r;
		i273 = i237 - s5i;
		s7r = r237 + s5r;
		s7i = i237 + s5i;
		r299 = s6r - s7r;
		i299 = s6i - s7i;
		s8r = s6r + s7r;
		s8i = s6i + s7i;
		r341 = s8r - r314;
		i341 = s8i - i314;
		r344 = r314 + s8r;
		i344 = i314 + s8i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		valueT s11r, s11i, s12r, s12i, s13r, s13i, s14r, s14i, s15r, s15i;
		valueT s16r, s16i, s17r, s17i, s18r, s18i, s19r, s19i, s20r, s20i;
		valueT s21r, s21i, s22r, s22i, s23r, s23i, s24r, s24i, s25r, s25i;
		valueT s26r, s26i, s27r, s27i, s28r, s28i, s29r, s29i, s30r, s30i;
		valueT s31r, s31i, s32r, s32i, s33r, s33i, s34r, s34i, s35r, s35i;
		valueT s36r, s36i, s37r, s37i, s38r, s38i;
		s1r = valueT(-0.54490689600402066442) * i108;
		s1i = valueT(0.54490689600402066442) * r108;
		s2r = valueT(-2.3082626528814400519) * i105;
		s2i = valueT(2.3082626528814400519) * r105;
		s3r = r105 + r113;
		s3i = i105 + i113;
		s4r = valueT(-0.54490689600402066442) * i113;
		s4i = valueT(0.54490689600402066442) * r113;
		s5r = r117 - r119;
		s5i = i117 - i119;
		s6r = r102 - r108;
		s6i = i102 - i108;
		s7r = valueT(2.3082626528814400519) * i102;
		s7i = valueT(-2.3082626528814400519) * r102;
		s8r = valueT(-0.36327126400268044295) * i94;
		s8i = valueT(0.36327126400268044295) * r94;
		s9r = valueT(-1.5388417685876267013) * i97;
		s9i = valueT(1.5388417685876267013) * r97;
		s10r = r103 - r97;
		s10i = i103 - i97;
		s11r = valueT(0.36327126400268044295) * i103;
		s11i = valueT(-0.36327126400268044295) * r103;
		s12r = valueT(0.88167787843870969375) * s3i;
		s12i = valueT(-0.88167787843870969375) * s3r;
		s13r = valueT(-0.83852549156242113615) * s5r;
		s13i = valueT(-0.83852549156242113615) * s5i;
		s14r = valueT(1.875) * r149;
		s14i = valueT(1.875) * i149;
		s15r = r94 - r100;
		s15i = i94 - i100;
		s16r = valueT(1.5388417685876267013) * i100;
		s16i = valueT(-1.5388417685876267013) * r100;
		s17r = valueT(-0.88167787843870969375) * s6i;
		s17i = valueT(0.88167787843870969375) * s6r;
		s18r = valueT(0.83852549156242113615) * r144;
		s18i = valueT(0.83852549156242113615) * i144;
		s19r = valueT(-0.58778525229247312917) * s10i;
		s19i = valueT(0.58778525229247312917) * s10r;
		s20r = valueT(-0.5590169943749474241) * r139;
		s20i = valueT(-0.5590169943749474241) * i139;
		s21r = s2r + s12r;
		s21i = s2i + s12i;
		r287 = s4r - s12r;
		i287 = s4i - s12i;
		s22r = valueT(0.58778525229247312917) * s15i;
		s22i = valueT(-0.58778525229247312917) * s15r;
		s23r = valueT(0.5590169943749474241) * r142;
		s23i = valueT(0.5590169943749474241) * i142;
		r282 = s1r - s17r;
		i282 = s1i - s17i;
		s24r = s7r + s17r;
		s24i = s7i + s17i;
		s25r = s9r + s19r;
		s25i = s9i + s19i;
		r277 = s11r - s19r;
		i277 = s11i - s19i;
		s26r = r213 + s14r;
		s26i = i213 + s14i;
		r268 = s8r - s22r;
		i268 = s8i - s22i;
		s27r = s16r + s22r;
		s27i = s16i + s22i;
		r283 = s20r - r253;
		i283 = s20i - i253;
		s28r = r253 + s20r;
		s28i = i253 + s20i;
		r291 = s13r - s26r;
		i291 = s13i - s26i;
		s29r = s13r + s26r;
		s29i = s13i + s26i;
		r286 = s23r - r256;
		i286 = s23i - i256;
		s30r = r256 + s23r;
		s30i = i256 + s23i;
		r288 = s18r - r258;
		i288 = s18i - i258;
		s31r = r258 + s18r;
		s31i = i258 + s18i;
		r301 = s25r - s28r;
		i301 = s25i - s28i;
		s32r = s25r + s28r;
		s32i = s25i + s28i;
		r309 = s21r - s29r;
		i309 = s21i - s29i;
		s33r = s21r + s29r;
		s33i = s21i + s29i;
		r304 = s27r - s30r;
		i304 = s27i - s30i;
		s34r = s27r + s30r;
		s34i = s27i + s30i;
		r306 = s24r - s31r;
		i306 = s24i - s31i;
		s35r = s24r + s31r;
		s35i = s24i + s31i;
		r349 = s32r - s34r;
		i349 = s32i - s34i;
		s36r = s32r + s34r;
		s36i = s32i + s34i;
		r353 = s33r - s35r;
		i353 = s33i - s35i;
		s37r = s33r + s35r;
		s37i = s33i + s35i;
		pReal[6 * stride] = s36r;
		pImag[6 * stride] = s36i;
		s38r = s36r + s37r;
		s38i = s36i + s37i;
		pReal[26 * stride] = s38r - r344;
		pImag[26 * stride] = s38i - i344;
		pReal[16 * stride] = r344 + s38r;
		pImag[16 * stride] = i344 + s38i;
	}
	pReal[21 * stride] = r349;
	pImag[21 * stride] = i349;
	r383 = r349 + r353;
	i383 = i349 + i353;
	pReal[11 * stride] = r383 - r341;
	pImag[11 * stride] = i383 - i341;
	pReal[1 * stride] = r341 + r383;
	pImag[1 * stride] = i341 + i383;
	r339 = r309 - r306;
	i339 = i309 - i306;
	r336 = r309 + r306;
	i336 = i309 + i306;
	{
		valueT s1r, s1i;
		r334 = r304 - r301;
		i334 = i304 - i301;
		s1r = r301 + r304;
		s1i = i301 + i304;
		pReal[24 * stride] = -s1r;
		pImag[24 * stride] = -s1i;
		r366 = r336 + s1r;
		i366 = i336 + s1i;
	}
	{
		valueT s1r, s1i;
		r329 = r299 - r296;
		i329 = i299 - i296;
		s1r = r296 + r299;
		s1i = i296 + i299;
		pReal[4 * stride] = -r366 - s1r;
		pImag[4 * stride] = -i366 - s1i;
		pReal[14 * stride] = s1r - r366;
		pImag[14 * stride] = s1i - i366;
	}
	{
		valueT s1r, s1i;
		pReal[9 * stride] = r334;
		pImag[9 * stride] = i334;
		s1r = r339 - r334;
		s1i = i339 - i334;
		pReal[19 * stride] = -r329 - s1r;
		pImag[19 * stride] = -i329 - s1i;
		pReal[29 * stride] = r329 - s1r;
		pImag[29 * stride] = i329 - s1i;
	}
	r318 = r288 - r282;
	i318 = i288 - i282;
	r312 = r282 + r288;
	i312 = i282 + i288;
	{
		valueT s1r, s1i;
		r317 = r287 - r291;
		i317 = i287 - i291;
		s1r = r287 + r291;
		s1i = i287 + i291;
		r351 = s1r - r312;
		i351 = s1i - i312;
		r342 = r312 + s1r;
		i342 = i312 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i;
		r307 = r277 - r283;
		i307 = i277 - i283;
		s1r = r277 + r283;
		s1i = i277 + i283;
		r316 = r286 - r268;
		i316 = i286 - i268;
		s2r = r268 + r286;
		s2i = i268 + i286;
		r343 = s1r - s2r;
		i343 = s1i - s2i;
		s3r = s1r + s2r;
		s3i = s1i + s2i;
		pReal[18 * stride] = -s3r;
		pImag[18 * stride] = -s3i;
		r372 = r342 + s3r;
		i372 = i342 + s3i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i;
		s1r = r267 - r273;
		s1i = i267 - i273;
		r303 = r267 + r273;
		i303 = i267 + i273;
		r308 = r278 - r272;
		i308 = i278 - i272;
		s2r = r278 + r272;
		s2i = i278 + i272;
		r327 = s1r - s2r;
		i327 = s1i - s2i;
		s3r = s1r + s2r;
		s3i = s1i + s2i;
		pReal[28 * stride] = -r372 - s3r;
		pImag[28 * stride] = -i372 - s3i;
		pReal[8 * stride] = s3r - r372;
		pImag[8 * stride] = s3i - i372;
	}
	{
		valueT s1r, s1i;
		pReal[3 * stride] = -r343;
		pImag[3 * stride] = -i343;
		s1r = r351 + r343;
		s1i = i351 + i343;
		pReal[13 * stride] = -r327 - s1r;
		pImag[13 * stride] = -i327 - s1i;
		pReal[23 * stride] = r327 - s1r;
		pImag[23 * stride] = i327 - s1i;
	}
	r333 = r303 - r308;
	i333 = i303 - i308;
	r338 = r303 + r308;
	i338 = i303 + i308;
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i;
		r346 = r316 - r307;
		i346 = i316 - i307;
		s1r = r307 + r316;
		s1i = i307 + i316;
		r348 = r318 - r317;
		i348 = i318 - i317;
		s2r = r318 + r317;
		s2i = i318 + i317;
		pReal[27 * stride] = s1r;
		pImag[27 * stride] = s1i;
		s3r = s1r + s2r;
		s3i = s1i + s2i;
		pReal[17 * stride] = s3r - r338;
		pImag[17 * stride] = s3i - i338;
		pReal[7 * stride] = r338 + s3r;
		pImag[7 * stride] = i338 + s3i;
	}
	pReal[12 * stride] = -r346;
	pImag[12 * stride] = -i346;
	r378 = r346 + r348;
	i378 = i346 + i348;
	pReal[2 * stride] = -r333 - r378;
	pImag[2 * stride] = -i333 - i378;
	pReal[22 * stride] = r333 - r378;
	pImag[22 * stride] = i333 - i378;
}

template<> void StandardModule<float, 30>::Compute(float *pReal, float *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

template<> void StandardModule<double, 30>::Compute(double *pReal, double *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

}
}
