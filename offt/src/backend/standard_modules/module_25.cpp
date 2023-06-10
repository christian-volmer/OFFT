
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

template<> StandardModuleComplexity const StandardModule<float, 25>::Complexity = { 0, 0 };
template<> StandardModuleComplexity const StandardModule<double, 25>::Complexity = { 0, 0 };

template<typename valueT>
static void ComputeCore(Phasors<valueT> const &phasors, valueT *pReal, valueT *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement)
{
	valueT r25, i25, r35, i35, r50, i50, r40, i40, r70, i70;
	valueT r75, i75, r85, i85, r135, i135, r7, i7, r12, i12;
	valueT r17, i17, r22, i22, r42, i42, r47, i47, r72, i72;
	valueT r82, i82, r247, i247, r250, i250, r165, i165, r190, i190;
	valueT r195, i195, r185, i185, r205, i205, r220, i220, r245, i245;
	valueT r182, i182, r187, i187, r202, i202, r267, i267, r270, i270;
	valueT r183, i183, r184, i184, r248, i248, r249, i249, r188, i188;
	valueT r189, i189, r203, i203, r204, i204, r268, i268, r294, i294;
	valueT r295, i295, r181, i181, r186, i186, r275, i275, r201, i201;
	valueT r301, i301, r321, i321, r355, i355, r385, i385, r414, i414;
	valueT r415, i415, r413, i413, r365, i365, r394, i394, r395, i395;
	valueT r393, i393, r253, i253, r252, i252, r279, i279, r306, i306;
	valueT r340, i340, r370, i370, r399, i399, r400, i400, r398, i398;
	valueT r206, i206, r211, i211, r207, i207, r208, i208, r209, i209;
	valueT r210, i210, r263, i263, r262, i262, r289, i289, r316, i316;
	valueT r350, i350, r380, i380, r409, i409, r410, i410, r408, i408;
	valueT r235, i235, r257, i257, r260, i260, r258, i258, r284, i284;
	valueT r285, i285, r311, i311, r345, i345, r375, i375, r404, i404;
	valueT r405, i405, r403, i403;

	phasors.Multiply(r25, i25, pReal[24 * stride], pImag[24 * stride], twiddleStart + 24 * twiddleIncrement);
	{
		valueT s1r, s1i;
		phasors.Multiply(s1r, s1i, pReal[9 * stride], pImag[9 * stride], twiddleStart + 9 * twiddleIncrement);
		r35 = s1r - r25;
		i35 = s1i - i25;
		r50 = r25 + s1r;
		i50 = i25 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i;
		phasors.Multiply(s1r, s1i, pReal[14 * stride], pImag[14 * stride], twiddleStart + 14 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[19 * stride], pImag[19 * stride], twiddleStart + 19 * twiddleIncrement);
		r40 = s1r - s2r;
		i40 = s1i - s2i;
		s3r = s1r + s2r;
		s3i = s1i + s2i;
		r70 = s3r - r50;
		i70 = s3i - i50;
		r75 = r50 + s3r;
		i75 = i50 + s3i;
	}
	{
		valueT s1r, s1i;
		phasors.Multiply(s1r, s1i, pReal[4 * stride], pImag[4 * stride], twiddleStart + 4 * twiddleIncrement);
		r85 = r75 + s1r;
		i85 = i75 + s1i;
		r135 = valueT(-1.25) * r75;
		i135 = valueT(-1.25) * i75;
	}
	{
		valueT s1r, s1i;
		phasors.Multiply(s1r, s1i, pReal[1 * stride], pImag[1 * stride], twiddleStart + 1 * twiddleIncrement);
		phasors.Multiply(r7, i7, pReal[6 * stride], pImag[6 * stride], twiddleStart + 6 * twiddleIncrement);
		phasors.Multiply(r12, i12, pReal[11 * stride], pImag[11 * stride], twiddleStart + 11 * twiddleIncrement);
		phasors.Multiply(r17, i17, pReal[16 * stride], pImag[16 * stride], twiddleStart + 16 * twiddleIncrement);
		phasors.Multiply(r22, i22, pReal[21 * stride], pImag[21 * stride], twiddleStart + 21 * twiddleIncrement);
		r42 = r12 + r17;
		i42 = i12 + i17;
		r47 = r7 + r22;
		i47 = i7 + i22;
		r72 = r42 + r47;
		i72 = i42 + i47;
		r82 = s1r + r72;
		i82 = s1i + i72;
		r247 = r82 - r85;
		i247 = i82 - i85;
		r250 = r85 + r82;
		i250 = i85 + i82;
		r165 = r85 + r135;
		i165 = i85 + i135;
	}
	{
		valueT s1r, s1i;
		s1r = valueT(-0.5590169943749474241) * r70;
		s1i = valueT(-0.5590169943749474241) * i70;
		r190 = s1r - r165;
		i190 = s1i - i165;
		r195 = r165 + s1r;
		i195 = i165 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		s1r = valueT(0.36327126400268044295) * i40;
		s1i = valueT(-0.36327126400268044295) * r40;
		s2r = r35 - r40;
		s2i = i35 - i40;
		s3r = valueT(-1.5388417685876267013) * i35;
		s3i = valueT(1.5388417685876267013) * r35;
		s4r = valueT(0.58778525229247312917) * s2i;
		s4i = valueT(-0.58778525229247312917) * s2r;
		r185 = s1r - s4r;
		i185 = s1i - s4i;
		s5r = s3r + s4r;
		s5i = s3i + s4i;
		r205 = s5r - r195;
		i205 = s5i - i195;
		r220 = r195 + s5r;
		i220 = i195 + s5i;
	}
	r245 = valueT(0.53582679497899661827) * r220 - valueT(0.84432792550201507855) * i220;
	i245 = valueT(0.84432792550201507855) * r220 + valueT(0.53582679497899661827) * i220;
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		valueT s11r, s11i, s12r, s12i, s13r, s13i, s14r, s14i;
		s1r = r12 - r17;
		s1i = i12 - i17;
		s2r = r7 - r22;
		s2i = i7 - i22;
		s3r = valueT(0.36327126400268044295) * s1i;
		s3i = valueT(-0.36327126400268044295) * s1r;
		s4r = s2r - s1r;
		s4i = s2i - s1i;
		s5r = valueT(-1.5388417685876267013) * s2i;
		s5i = valueT(1.5388417685876267013) * s2r;
		s6r = r42 - r47;
		s6i = i42 - i47;
		s7r = valueT(0.58778525229247312917) * s4i;
		s7i = valueT(-0.58778525229247312917) * s4r;
		s8r = valueT(-0.5590169943749474241) * s6r;
		s8i = valueT(-0.5590169943749474241) * s6i;
		s9r = valueT(-1.25) * r72;
		s9i = valueT(-1.25) * i72;
		r182 = s3r - s7r;
		i182 = s3i - s7i;
		s10r = s5r + s7r;
		s10i = s5i + s7i;
		s11r = r82 + s9r;
		s11i = i82 + s9i;
		r187 = s8r - s11r;
		i187 = s8i - s11i;
		s12r = s8r + s11r;
		s12i = s8i + s11i;
		r202 = s10r - s12r;
		i202 = s10i - s12i;
		s13r = s10r + s12r;
		s13i = s10i + s12i;
		s14r = valueT(0.96858316112863111949) * s13r - valueT(0.24868988716485478824) * s13i;
		s14i = valueT(0.24868988716485478824) * s13r + valueT(0.96858316112863111949) * s13i;
		r267 = s14r - r245;
		i267 = s14i - i245;
		r270 = r245 + s14r;
		i270 = i245 + s14i;
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
		valueT s46r, s46i, s47r, s47i;
		phasors.Multiply(s1r, s1i, pReal[2 * stride], pImag[2 * stride], twiddleStart + 2 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[3 * stride], pImag[3 * stride], twiddleStart + 3 * twiddleIncrement);
		phasors.Multiply(s3r, s3i, pReal[7 * stride], pImag[7 * stride], twiddleStart + 7 * twiddleIncrement);
		phasors.Multiply(s4r, s4i, pReal[8 * stride], pImag[8 * stride], twiddleStart + 8 * twiddleIncrement);
		phasors.Multiply(s5r, s5i, pReal[12 * stride], pImag[12 * stride], twiddleStart + 12 * twiddleIncrement);
		phasors.Multiply(s6r, s6i, pReal[13 * stride], pImag[13 * stride], twiddleStart + 13 * twiddleIncrement);
		phasors.Multiply(s7r, s7i, pReal[17 * stride], pImag[17 * stride], twiddleStart + 17 * twiddleIncrement);
		phasors.Multiply(s8r, s8i, pReal[18 * stride], pImag[18 * stride], twiddleStart + 18 * twiddleIncrement);
		phasors.Multiply(s9r, s9i, pReal[22 * stride], pImag[22 * stride], twiddleStart + 22 * twiddleIncrement);
		phasors.Multiply(s10r, s10i, pReal[23 * stride], pImag[23 * stride], twiddleStart + 23 * twiddleIncrement);
		s11r = s5r - s7r;
		s11i = s5i - s7i;
		s12r = s5r + s7r;
		s12i = s5i + s7i;
		s13r = s6r - s8r;
		s13i = s6i - s8i;
		s14r = s6r + s8r;
		s14i = s6i + s8i;
		s15r = s3r - s9r;
		s15i = s3i - s9i;
		s16r = s3r + s9r;
		s16i = s3i + s9i;
		s17r = s4r - s10r;
		s17i = s4i - s10i;
		s18r = s4r + s10r;
		s18i = s4i + s10i;
		s19r = valueT(0.36327126400268044295) * s11i;
		s19i = valueT(-0.36327126400268044295) * s11r;
		s20r = valueT(0.36327126400268044295) * s13i;
		s20i = valueT(-0.36327126400268044295) * s13r;
		s21r = s15r - s11r;
		s21i = s15i - s11i;
		s22r = valueT(-1.5388417685876267013) * s15i;
		s22i = valueT(1.5388417685876267013) * s15r;
		s23r = s12r - s16r;
		s23i = s12i - s16i;
		s24r = s12r + s16r;
		s24i = s12i + s16i;
		s25r = s17r - s13r;
		s25i = s17i - s13i;
		s26r = valueT(-1.5388417685876267013) * s17i;
		s26i = valueT(1.5388417685876267013) * s17r;
		s27r = s14r - s18r;
		s27i = s14i - s18i;
		s28r = s14r + s18r;
		s28i = s14i + s18i;
		s29r = valueT(0.58778525229247312917) * s21i;
		s29i = valueT(-0.58778525229247312917) * s21r;
		s30r = valueT(-0.5590169943749474241) * s23r;
		s30i = valueT(-0.5590169943749474241) * s23i;
		s31r = s1r + s24r;
		s31i = s1i + s24i;
		s32r = valueT(-1.25) * s24r;
		s32i = valueT(-1.25) * s24i;
		s33r = valueT(0.58778525229247312917) * s25i;
		s33i = valueT(-0.58778525229247312917) * s25r;
		s34r = valueT(-0.5590169943749474241) * s27r;
		s34i = valueT(-0.5590169943749474241) * s27i;
		s35r = s2r + s28r;
		s35i = s2i + s28i;
		s36r = valueT(-1.25) * s28r;
		s36i = valueT(-1.25) * s28i;
		r183 = s19r - s29r;
		i183 = s19i - s29i;
		s37r = s22r + s29r;
		s37i = s22i + s29i;
		s38r = s31r + s32r;
		s38i = s31i + s32i;
		r184 = s20r - s33r;
		i184 = s20i - s33i;
		s39r = s26r + s33r;
		s39i = s26i + s33i;
		r248 = s31r - s35r;
		i248 = s31i - s35i;
		r249 = s31r + s35r;
		i249 = s31i + s35i;
		s40r = s35r + s36r;
		s40i = s35i + s36i;
		r188 = s30r - s38r;
		i188 = s30i - s38i;
		s41r = s30r + s38r;
		s41i = s30i + s38i;
		r189 = s34r - s40r;
		i189 = s34i - s40i;
		s42r = s34r + s40r;
		s42i = s34i + s40i;
		r203 = s37r - s41r;
		i203 = s37i - s41i;
		s43r = s37r + s41r;
		s43i = s37i + s41i;
		r204 = s39r - s42r;
		i204 = s39i - s42i;
		s44r = s39r + s42r;
		s44i = s39i + s42i;
		s45r = valueT(0.87630668004386358731) * s43r - valueT(0.48175367410171527499) * s43i;
		s45i = valueT(0.48175367410171527499) * s43r + valueT(0.87630668004386358731) * s43i;
		s46r = valueT(0.72896862742141152315) * s44r - valueT(0.68454710592868867373) * s44i;
		s46i = valueT(0.68454710592868867373) * s44r + valueT(0.72896862742141152315) * s44i;
		r268 = s45r - s46r;
		i268 = s45i - s46i;
		s47r = s45r + s46r;
		s47i = s45i + s46i;
		r294 = s47r - r270;
		i294 = s47i - i270;
		r295 = r270 + s47r;
		i295 = i270 + s47i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		valueT s11r, s11i, s12r, s12i, s13r, s13i, s14r, s14i, s15r, s15i;
		valueT s16r, s16i, s17r, s17i, s18r, s18i, s19r, s19i, s20r, s20i;
		valueT s21r, s21i, s22r, s22i;
		phasors.Multiply(s1r, s1i, pReal[0 * stride], pImag[0 * stride], twiddleStart + 0 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[5 * stride], pImag[5 * stride], twiddleStart + 5 * twiddleIncrement);
		phasors.Multiply(s3r, s3i, pReal[10 * stride], pImag[10 * stride], twiddleStart + 10 * twiddleIncrement);
		phasors.Multiply(s4r, s4i, pReal[15 * stride], pImag[15 * stride], twiddleStart + 15 * twiddleIncrement);
		phasors.Multiply(s5r, s5i, pReal[20 * stride], pImag[20 * stride], twiddleStart + 20 * twiddleIncrement);
		s6r = s3r - s4r;
		s6i = s3i - s4i;
		s7r = s3r + s4r;
		s7i = s3i + s4i;
		s8r = s2r - s5r;
		s8i = s2i - s5i;
		s9r = s2r + s5r;
		s9i = s2i + s5i;
		s10r = valueT(0.36327126400268044295) * s6i;
		s10i = valueT(-0.36327126400268044295) * s6r;
		s11r = s8r - s6r;
		s11i = s8i - s6i;
		s12r = valueT(-1.5388417685876267013) * s8i;
		s12i = valueT(1.5388417685876267013) * s8r;
		s13r = s7r - s9r;
		s13i = s7i - s9i;
		s14r = s7r + s9r;
		s14i = s7i + s9i;
		s15r = valueT(0.58778525229247312917) * s11i;
		s15i = valueT(-0.58778525229247312917) * s11r;
		s16r = valueT(-0.5590169943749474241) * s13r;
		s16i = valueT(-0.5590169943749474241) * s13i;
		s17r = s1r + s14r;
		s17i = s1i + s14i;
		s18r = valueT(-1.25) * s14r;
		s18i = valueT(-1.25) * s14i;
		r181 = s10r - s15r;
		i181 = s10i - s15i;
		s19r = s12r + s15r;
		s19i = s12i + s15i;
		s20r = s17r + s18r;
		s20i = s17i + s18i;
		r186 = s16r - s20r;
		i186 = s16i - s20i;
		s21r = s16r + s20r;
		s21i = s16i + s20i;
		r275 = r250 + r249;
		i275 = i250 + i249;
		r201 = s19r - s21r;
		i201 = s19i - s21i;
		s22r = s19r + s21r;
		s22i = s19i + s21i;
		r301 = s17r + r275;
		i301 = s17i + i275;
		r321 = r295 + s22r;
		i321 = i295 + s22i;
		r355 = valueT(-1.25) * r295;
		i355 = valueT(-1.25) * i295;
	}
	pReal[1 * stride] = r321;
	pImag[1 * stride] = i321;
	r385 = r321 + r355;
	i385 = i321 + i355;
	{
		valueT s1r, s1i;
		s1r = valueT(-0.5590169943749474241) * r294;
		s1i = valueT(-0.5590169943749474241) * i294;
		r414 = s1r - r385;
		i414 = s1i - i385;
		r415 = r385 + s1r;
		i415 = i385 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		s1r = valueT(0.36327126400268044295) * i268;
		s1i = valueT(-0.36327126400268044295) * r268;
		s2r = r267 - r268;
		s2i = i267 - i268;
		s3r = valueT(-1.5388417685876267013) * i267;
		s3i = valueT(1.5388417685876267013) * r267;
		s4r = valueT(0.58778525229247312917) * s2i;
		s4i = valueT(-0.58778525229247312917) * s2r;
		r413 = s1r - s4r;
		i413 = s1i - s4i;
		s5r = s3r + s4r;
		s5i = s3i + s4i;
		pReal[21 * stride] = r415 - s5r;
		pImag[21 * stride] = i415 - s5i;
		pReal[6 * stride] = r415 + s5r;
		pImag[6 * stride] = i415 + s5i;
	}
	pReal[16 * stride] = -r414 - r413;
	pImag[16 * stride] = -i414 - i413;
	pReal[11 * stride] = r413 - r414;
	pImag[11 * stride] = i413 - i414;
	{
		valueT s1r, s1i;
		s1r = valueT(-1.25) * r275;
		s1i = valueT(-1.25) * i275;
		pReal[0 * stride] = r301;
		pImag[0 * stride] = i301;
		r365 = r301 + s1r;
		i365 = i301 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i;
		s1r = r249 - r250;
		s1i = i249 - i250;
		s2r = valueT(-0.5590169943749474241) * s1r;
		s2i = valueT(-0.5590169943749474241) * s1i;
		r394 = s2r - r365;
		i394 = s2i - i365;
		r395 = r365 + s2r;
		i395 = i365 + s2i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		s1r = valueT(0.36327126400268044295) * i248;
		s1i = valueT(-0.36327126400268044295) * r248;
		s2r = r247 - r248;
		s2i = i247 - i248;
		s3r = valueT(-1.5388417685876267013) * i247;
		s3i = valueT(1.5388417685876267013) * r247;
		s4r = valueT(0.58778525229247312917) * s2i;
		s4i = valueT(-0.58778525229247312917) * s2r;
		r393 = s1r - s4r;
		i393 = s1i - s4i;
		s5r = s3r + s4r;
		s5i = s3i + s4i;
		pReal[20 * stride] = r395 - s5r;
		pImag[20 * stride] = i395 - s5i;
		pReal[5 * stride] = r395 + s5r;
		pImag[5 * stride] = i395 + s5i;
	}
	pReal[15 * stride] = -r394 - r393;
	pImag[15 * stride] = -i394 - i393;
	pReal[10 * stride] = r393 - r394;
	pImag[10 * stride] = i393 - i394;
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i;
		s1r = valueT(0.84432792550201507855) * i202 - valueT(0.53582679497899661827) * r202;
		s1i = valueT(-0.84432792550201507855) * r202 - valueT(0.53582679497899661827) * i202;
		s2r = valueT(0.42577929156507264886) * r203 + valueT(0.90482705246601952771) * i203;
		s2i = valueT(0.42577929156507264886) * i203 - valueT(0.90482705246601952771) * r203;
		s3r = valueT(0.99211470131447783105) * r204 + valueT(0.12533323356430424537) * i204;
		s3i = valueT(0.99211470131447783105) * i204 - valueT(0.12533323356430424537) * r204;
		s4r = valueT(0.63742398974868971018) * r205 - valueT(0.7705132427757892308) * i205;
		s4i = valueT(0.7705132427757892308) * r205 + valueT(0.63742398974868971018) * i205;
		r253 = s2r - s3r;
		i253 = s2i - s3i;
		s5r = s2r + s3r;
		s5i = s2i + s3i;
		r252 = s1r - s4r;
		i252 = s1i - s4i;
		s6r = s1r + s4r;
		s6i = s1i + s4i;
		r279 = s5r - s6r;
		i279 = s5i - s6i;
		s7r = s5r + s6r;
		s7i = s5i + s6i;
		r306 = r201 - s7r;
		i306 = i201 - s7i;
		r340 = valueT(-1.25) * s7r;
		i340 = valueT(-1.25) * s7i;
	}
	pReal[4 * stride] = -r306;
	pImag[4 * stride] = -i306;
	r370 = r340 - r306;
	i370 = i340 - i306;
	{
		valueT s1r, s1i;
		s1r = valueT(-0.5590169943749474241) * r279;
		s1i = valueT(-0.5590169943749474241) * i279;
		r399 = s1r - r370;
		i399 = s1i - i370;
		r400 = r370 + s1r;
		i400 = i370 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		s1r = valueT(0.36327126400268044295) * i253;
		s1i = valueT(-0.36327126400268044295) * r253;
		s2r = r252 - r253;
		s2i = i252 - i253;
		s3r = valueT(-1.5388417685876267013) * i252;
		s3i = valueT(1.5388417685876267013) * r252;
		s4r = valueT(0.58778525229247312917) * s2i;
		s4i = valueT(-0.58778525229247312917) * s2r;
		r398 = s1r - s4r;
		i398 = s1i - s4i;
		s5r = s3r + s4r;
		s5i = s3i + s4i;
		pReal[24 * stride] = r400 - s5r;
		pImag[24 * stride] = i400 - s5i;
		pReal[9 * stride] = r400 + s5r;
		pImag[9 * stride] = i400 + s5i;
	}
	pReal[19 * stride] = -r399 - r398;
	pImag[19 * stride] = -i399 - i398;
	pReal[14 * stride] = r398 - r399;
	pImag[14 * stride] = i398 - i399;
	r206 = r181 - r186;
	i206 = i181 - i186;
	r211 = r181 + r186;
	i211 = i181 + i186;
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		valueT s11r, s11i;
		r207 = r182 - r187;
		i207 = i182 - i187;
		s1r = r182 + r187;
		s1i = i182 + i187;
		r208 = r183 - r188;
		i208 = i183 - i188;
		s2r = r183 + r188;
		s2i = i183 + i188;
		r209 = r184 - r189;
		i209 = i184 - i189;
		s3r = r184 + r189;
		s3i = i184 + i189;
		r210 = r185 - r190;
		i210 = i185 - i190;
		s4r = r190 + r185;
		s4i = i190 + i185;
		s5r = valueT(0.68454710592868867373) * s1i - valueT(0.72896862742141152315) * s1r;
		s5i = valueT(-0.68454710592868867373) * s1r - valueT(0.72896862742141152315) * s1i;
		s6r = valueT(0.99802672842827156195) * s2i - valueT(0.062790519529313376076) * s2r;
		s6i = valueT(-0.99802672842827156195) * s2r - valueT(0.062790519529313376076) * s2i;
		s7r = valueT(0.63742398974868971018) * s3r + valueT(0.7705132427757892308) * s3i;
		s7i = valueT(0.63742398974868971018) * s3i - valueT(0.7705132427757892308) * s3r;
		s8r = valueT(0.99211470131447783105) * s4r + valueT(0.12533323356430424537) * s4i;
		s8i = valueT(0.99211470131447783105) * s4i - valueT(0.12533323356430424537) * s4r;
		r263 = s6r - s7r;
		i263 = s6i - s7i;
		s9r = s6r + s7r;
		s9i = s6i + s7i;
		r262 = s5r - s8r;
		i262 = s5i - s8i;
		s10r = s5r + s8r;
		s10i = s5i + s8i;
		r289 = s9r - s10r;
		i289 = s9i - s10i;
		s11r = s9r + s10r;
		s11i = s9i + s10i;
		r316 = r211 - s11r;
		i316 = i211 - s11i;
		r350 = valueT(-1.25) * s11r;
		i350 = valueT(-1.25) * s11i;
	}
	pReal[3 * stride] = -r316;
	pImag[3 * stride] = -i316;
	r380 = r350 - r316;
	i380 = i350 - i316;
	{
		valueT s1r, s1i;
		s1r = valueT(-0.5590169943749474241) * r289;
		s1i = valueT(-0.5590169943749474241) * i289;
		r409 = s1r - r380;
		i409 = s1i - i380;
		r410 = r380 + s1r;
		i410 = i380 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		s1r = valueT(0.36327126400268044295) * i263;
		s1i = valueT(-0.36327126400268044295) * r263;
		s2r = r262 - r263;
		s2i = i262 - i263;
		s3r = valueT(-1.5388417685876267013) * i262;
		s3i = valueT(1.5388417685876267013) * r262;
		s4r = valueT(0.58778525229247312917) * s2i;
		s4i = valueT(-0.58778525229247312917) * s2r;
		r408 = s1r - s4r;
		i408 = s1i - s4i;
		s5r = s3r + s4r;
		s5i = s3i + s4i;
		pReal[23 * stride] = r410 - s5r;
		pImag[23 * stride] = i410 - s5i;
		pReal[8 * stride] = r410 + s5r;
		pImag[8 * stride] = i410 + s5i;
	}
	pReal[18 * stride] = -r409 - r408;
	pImag[18 * stride] = -i409 - i408;
	pReal[13 * stride] = r408 - r409;
	pImag[13 * stride] = i408 - i409;
	r235 = valueT(-0.42577929156507264886) * r210 - valueT(0.90482705246601952771) * i210;
	i235 = valueT(0.90482705246601952771) * r210 - valueT(0.42577929156507264886) * i210;
	{
		valueT s1r, s1i;
		s1r = valueT(0.87630668004386358731) * r207 - valueT(0.48175367410171527499) * i207;
		s1i = valueT(0.48175367410171527499) * r207 + valueT(0.87630668004386358731) * i207;
		r257 = s1r - r235;
		i257 = s1i - i235;
		r260 = r235 + s1r;
		i260 = i235 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i;
		s1r = valueT(0.53582679497899661827) * r208 - valueT(0.84432792550201507855) * i208;
		s1i = valueT(0.84432792550201507855) * r208 + valueT(0.53582679497899661827) * i208;
		s2r = valueT(0.062790519529313376076) * r209 - valueT(0.99802672842827156195) * i209;
		s2i = valueT(0.99802672842827156195) * r209 + valueT(0.062790519529313376076) * i209;
		r258 = s1r - s2r;
		i258 = s1i - s2i;
		s3r = s1r + s2r;
		s3i = s1i + s2i;
		r284 = s3r - r260;
		i284 = s3i - i260;
		r285 = r260 + s3r;
		i285 = i260 + s3i;
	}
	r311 = r206 + r285;
	i311 = i206 + i285;
	r345 = valueT(-1.25) * r285;
	i345 = valueT(-1.25) * i285;
	pReal[2 * stride] = r311;
	pImag[2 * stride] = i311;
	r375 = r311 + r345;
	i375 = i311 + i345;
	{
		valueT s1r, s1i;
		s1r = valueT(-0.5590169943749474241) * r284;
		s1i = valueT(-0.5590169943749474241) * i284;
		r404 = s1r - r375;
		i404 = s1i - i375;
		r405 = r375 + s1r;
		i405 = i375 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		s1r = valueT(0.36327126400268044295) * i258;
		s1i = valueT(-0.36327126400268044295) * r258;
		s2r = r257 - r258;
		s2i = i257 - i258;
		s3r = valueT(-1.5388417685876267013) * i257;
		s3i = valueT(1.5388417685876267013) * r257;
		s4r = valueT(0.58778525229247312917) * s2i;
		s4i = valueT(-0.58778525229247312917) * s2r;
		r403 = s1r - s4r;
		i403 = s1i - s4i;
		s5r = s3r + s4r;
		s5i = s3i + s4i;
		pReal[22 * stride] = r405 - s5r;
		pImag[22 * stride] = i405 - s5i;
		pReal[7 * stride] = r405 + s5r;
		pImag[7 * stride] = i405 + s5i;
	}
	pReal[17 * stride] = -r404 - r403;
	pImag[17 * stride] = -i404 - i403;
	pReal[12 * stride] = r403 - r404;
	pImag[12 * stride] = i403 - i404;
}

template<> void StandardModule<float, 25>::Compute(float *pReal, float *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

template<> void StandardModule<double, 25>::Compute(double *pReal, double *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

}
}
