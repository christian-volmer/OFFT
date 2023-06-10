
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

template<> StandardModuleComplexity const StandardModule<float, 19>::Complexity = { 0, 0 };
template<> StandardModuleComplexity const StandardModule<double, 19>::Complexity = { 0, 0 };

template<typename valueT>
static void ComputeCore(Phasors<valueT> const &phasors, valueT *pReal, valueT *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement)
{
	valueT r19, i19, r21, i21, r38, i38, r28, i28, r27, i27;
	valueT r51, i51, r50, i50, r57, i57, r4, i4, r7, i7;
	valueT r14, i14, r17, i17, r29, i29, r25, i25, r24, i24;
	valueT r22, i22, r52, i52, r49, i49, r55, i55, r53, i53;
	valueT r172, i172, r81, i81, r159, i159, r175, i175, r114, i114;
	valueT r157, i157, r177, i177, r152, i152, r109, i109, r178, i178;
	valueT r110, i110, r102, i102, r176, i176, r113, i113, r183, i183;
	valueT r154, i154, r180, i180, r228, i228, r225, i225, r197, i197;
	valueT r221, i221, r237, i237, r236, i236, r256, i256, r255, i255;
	valueT r258, i258, r218, i218, r277, i277, r280, i280, r276, i276;
	valueT r273, i273, r254, i254, r275, i275, r293, i293, r299, i299;
	valueT r291, i291, r166, i166, r163, i163, r203, i203, r201, i201;
	valueT r235, i235, r266, i266, r269, i269, r227, i227, r234, i234;
	valueT r260, i260, r243, i243, r271, i271, r289, i289, r282, i282;
	valueT r288, i288, r290, i290, r287, i287, r294, i294, r292, i292;
	valueT r285, i285, r286, i286, r284, i284, r297, i297, r295, i295;

	phasors.Multiply(r19, i19, pReal[18 * stride], pImag[18 * stride], twiddleStart + 18 * twiddleIncrement);
	{
		valueT s1r, s1i;
		phasors.Multiply(s1r, s1i, pReal[1 * stride], pImag[1 * stride], twiddleStart + 1 * twiddleIncrement);
		r21 = s1r - r19;
		i21 = s1i - i19;
		r38 = r19 + s1r;
		i38 = i19 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i;
		phasors.Multiply(s1r, s1i, pReal[7 * stride], pImag[7 * stride], twiddleStart + 7 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[8 * stride], pImag[8 * stride], twiddleStart + 8 * twiddleIncrement);
		phasors.Multiply(s3r, s3i, pReal[11 * stride], pImag[11 * stride], twiddleStart + 11 * twiddleIncrement);
		phasors.Multiply(s4r, s4i, pReal[12 * stride], pImag[12 * stride], twiddleStart + 12 * twiddleIncrement);
		r28 = s2r - s3r;
		i28 = s2i - s3i;
		s5r = s2r + s3r;
		s5i = s2i + s3i;
		r27 = s1r - s4r;
		i27 = s1i - s4i;
		s6r = s1r + s4r;
		s6i = s1i + s4i;
		r51 = s6r - s5r;
		i51 = s6i - s5i;
		r50 = r38 + s5r + s6r;
		i50 = i38 + s5i + s6i;
		r57 = r38 - s6r;
		i57 = i38 - s6i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		valueT s11r, s11i, s12r, s12i, s13r, s13i, s14r, s14i, s15r, s15i;
		valueT s16r, s16i, s17r, s17i;
		phasors.Multiply(s1r, s1i, pReal[2 * stride], pImag[2 * stride], twiddleStart + 2 * twiddleIncrement);
		phasors.Multiply(r4, i4, pReal[3 * stride], pImag[3 * stride], twiddleStart + 3 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[4 * stride], pImag[4 * stride], twiddleStart + 4 * twiddleIncrement);
		phasors.Multiply(s3r, s3i, pReal[5 * stride], pImag[5 * stride], twiddleStart + 5 * twiddleIncrement);
		phasors.Multiply(r7, i7, pReal[6 * stride], pImag[6 * stride], twiddleStart + 6 * twiddleIncrement);
		phasors.Multiply(s4r, s4i, pReal[9 * stride], pImag[9 * stride], twiddleStart + 9 * twiddleIncrement);
		phasors.Multiply(s5r, s5i, pReal[10 * stride], pImag[10 * stride], twiddleStart + 10 * twiddleIncrement);
		phasors.Multiply(r14, i14, pReal[13 * stride], pImag[13 * stride], twiddleStart + 13 * twiddleIncrement);
		phasors.Multiply(s6r, s6i, pReal[14 * stride], pImag[14 * stride], twiddleStart + 14 * twiddleIncrement);
		phasors.Multiply(s7r, s7i, pReal[15 * stride], pImag[15 * stride], twiddleStart + 15 * twiddleIncrement);
		phasors.Multiply(r17, i17, pReal[16 * stride], pImag[16 * stride], twiddleStart + 16 * twiddleIncrement);
		phasors.Multiply(s8r, s8i, pReal[17 * stride], pImag[17 * stride], twiddleStart + 17 * twiddleIncrement);
		r29 = s4r - s5r;
		i29 = s4i - s5i;
		s9r = s4r + s5r;
		s9i = s4i + s5i;
		s10r = r7 + r14;
		s10i = i7 + i14;
		r25 = s3r - s6r;
		i25 = s3i - s6i;
		s11r = s3r + s6r;
		s11i = s3i + s6i;
		r24 = s2r - s7r;
		i24 = s2i - s7i;
		s12r = s2r + s7r;
		s12i = s2i + s7i;
		s13r = r4 + r17;
		s13i = i4 + i17;
		r22 = s1r - s8r;
		i22 = s1i - s8i;
		s14r = s1r + s8r;
		s14i = s1i + s8i;
		r52 = s10r - s9r;
		i52 = s10i - s9i;
		s15r = s12r - s9r;
		s15i = s12i - s9i;
		r49 = s9r + s10r + s12r;
		i49 = s9i + s10i + s12i;
		r55 = s13r - s11r;
		i55 = s13i - s11i;
		s16r = s14r - s11r;
		s16i = s14i - s11i;
		r53 = s11r + s13r + s14r;
		i53 = s11i + s13i + s14i;
		r172 = valueT(1.5702524941755912569) * r51;
		i172 = valueT(1.5702524941755912569) * i51;
		r81 = r51 - r52;
		i81 = i51 - i52;
		r159 = s15r - r52;
		i159 = s15i - i52;
		r175 = valueT(-0.97680829181198902898) * s15r;
		i175 = valueT(-0.97680829181198902898) * s15i;
		r114 = -r51 - r55;
		i114 = -i51 - i55;
		r157 = s16r - r55;
		i157 = s16i - i55;
		r177 = valueT(1.6498790548989948758) * s16r;
		i177 = valueT(1.6498790548989948758) * s16i;
		r152 = r51 + r57;
		i152 = i51 + i57;
		s17r = -r57 - s15r;
		s17i = -i57 - s15i;
		r109 = s16r - r57;
		i109 = s16i - i57;
		r178 = valueT(1.5180103763831126486) * r57;
		i178 = valueT(1.5180103763831126486) * i57;
		r110 = s17r - s16r;
		i110 = s17i - s16i;
		r102 = s16r + s17r;
		i102 = s16i + s17i;
	}
	{
		valueT s1r, s1i;
		r176 = valueT(-1.0471317928768547985) * r55;
		i176 = valueT(-1.0471317928768547985) * i55;
		r113 = r81 - r55;
		i113 = i81 - i55;
		s1r = r55 + r81;
		s1i = i55 + i81;
		r183 = valueT(-0.651085145804193646) * s1r;
		i183 = valueT(-0.651085145804193646) * s1i;
		r154 = r102 - s1r;
		i154 = i102 - s1i;
		r180 = valueT(0.87748374592112899047) * r102;
		i180 = valueT(0.87748374592112899047) * i102;
	}
	{
		valueT s1r, s1i;
		s1r = valueT(-0.22639860011693534447) * r154;
		s1i = valueT(-0.22639860011693534447) * i154;
		r228 = r183 - s1r;
		i228 = i183 - s1i;
		r225 = r180 + s1r;
		i225 = i180 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		valueT s11r, s11i, s12r, s12i, s13r, s13i;
		s1r = valueT(-1.0471317928768547985) * r114;
		s1i = valueT(-1.0471317928768547985) * i114;
		s2r = valueT(-0.60274726202214007732) * r157;
		s2i = valueT(-0.60274726202214007732) * i157;
		r197 = valueT(0.052242117792478608243) * r152;
		i197 = valueT(0.052242117792478608243) * i152;
		s3r = r114 + r109;
		s3i = i114 + i109;
		s4r = valueT(-1.6498790548989948758) * r109;
		s4i = valueT(-1.6498790548989948758) * i109;
		s5r = valueT(-0.024742578358430269679) * r113;
		s5i = valueT(-0.024742578358430269679) * i113;
		r221 = r176 - s2r;
		i221 = i176 - s2i;
		s6r = r177 + s2r;
		s6i = i177 + s2i;
		s7r = r178 + r197;
		s7i = i178 + i197;
		s8r = r113 - r110;
		s8i = i113 - i110;
		s9r = valueT(0.27197952282337084426) * r110;
		s9i = valueT(0.27197952282337084426) * i110;
		s10r = valueT(0.60274726202214007732) * s3r;
		s10i = valueT(0.60274726202214007732) * s3i;
		s11r = valueT(0.24723694446494057458) * s8r;
		s11i = valueT(0.24723694446494057458) * s8i;
		r237 = s1r - s10r;
		i237 = s1i - s10i;
		s12r = s4r + s10r;
		s12i = s4i + s10i;
		r236 = s5r - s11r;
		i236 = s5i - s11i;
		s13r = s9r + s11r;
		s13i = s9i + s11i;
		r256 = s7r - s12r;
		i256 = s7i - s12i;
		r255 = r225 + s6r + s12r + s13r;
		i255 = i225 + s6i + s12i + s13i;
		r258 = r225 - s13r;
		i258 = i225 - s13i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i;
		s1r = valueT(0.49723085000549921805) * r52;
		s1i = valueT(0.49723085000549921805) * i52;
		s2r = valueT(0.47957744180648981093) * r159;
		s2i = valueT(0.47957744180648981093) * i159;
		r218 = s1r - s2r;
		i218 = s1i - s2i;
		s3r = r175 + s2r;
		s3i = i175 + s2i;
		r277 = s3r - r258;
		i277 = s3i - i258;
		r280 = r256 - r258;
		i280 = i256 - i258;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		valueT s11r, s11i, s12r, s12i, s13r, s13i, s14r, s14i, s15r, s15i;
		valueT s16r, s16i;
		phasors.Multiply(s1r, s1i, pReal[0 * stride], pImag[0 * stride], twiddleStart + 0 * twiddleIncrement);
		s2r = r49 - r53;
		s2i = i49 - i53;
		s3r = r50 - r49;
		s3i = i50 - i49;
		s4r = r50 + r49 + r53;
		s4i = i50 + i49 + i53;
		s5r = r53 - r50;
		s5i = i53 - i50;
		s6r = valueT(-0.14809047148830960016) * s2r;
		s6i = valueT(-0.14809047148830960016) * s2i;
		s7r = valueT(0.32530152474940867184) * s3r;
		s7i = valueT(0.32530152474940867184) * s3i;
		s8r = s1r + s4r;
		s8i = s1i + s4i;
		s9r = valueT(-1.0555555555555555556) * s4r;
		s9i = valueT(-1.0555555555555555556) * s4i;
		s10r = valueT(0.473391996237718272) * s5r;
		s10i = valueT(0.473391996237718272) * s5i;
		pReal[0 * stride] = s8r;
		pImag[0 * stride] = s8i;
		s11r = s8r + s9r;
		s11i = s8i + s9i;
		s12r = r172 - r197;
		s12i = i172 - i197;
		r276 = s10r - s6r - s11r;
		i276 = s10i - s6i - s11i;
		r273 = s6r + s7r - s11r;
		i273 = s6i + s7i - s11i;
		s13r = s7r + s10r + s11r;
		s13i = s7i + s10i + s11i;
		s14r = s12r - r237;
		s14i = s12i - i237;
		r254 = r228 + r221 + r237 + r236;
		i254 = i228 + i221 + i237 + i236;
		s15r = r228 - r236;
		s15i = i228 - i236;
		r275 = r218 - s15r;
		i275 = i218 - s15i;
		s16r = s14r - s15r;
		s16i = s14i - s15i;
		r293 = s13r + s16r;
		i293 = s13i + s16i;
		r299 = r280 + s16r - s13r;
		i299 = i280 + s16i - s13i;
		r291 = r280 + s13r;
		i291 = i280 + s13i;
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
		valueT s61r, s61i, s62r, s62i, s63r, s63i;
		s1r = r7 - r14;
		s1i = i7 - i14;
		s2r = r4 - r17;
		s2i = i4 - i17;
		s3r = r28 + r27;
		s3i = i28 + i27;
		s4r = s1r - r29;
		s4i = s1i - i29;
		s5r = r29 - r24;
		s5i = i29 - i24;
		s6r = r29 + r24 + s1r;
		s6i = i29 + i24 + s1i;
		s7r = r25 + s2r;
		s7i = i25 + s2i;
		s8r = r22 + s2r - r25;
		s8i = i22 + s2i - i25;
		s9r = r25 + r22;
		s9i = i25 + i22;
		s10r = r21 + r27 - r28;
		s10i = i21 + i27 - i28;
		s11r = r21 - r27;
		s11i = i21 - i27;
		s12r = valueT(0.28192537265311784701) * s3i;
		s12i = valueT(-0.28192537265311784701) * s3r;
		s13r = s4r - s3r;
		s13i = s4i - s3i;
		r166 = valueT(-0.85961846932201412149) * s4i;
		i166 = valueT(0.85961846932201412149) * s4r;
		s14r = s5r - s4r;
		s14i = s5i - s4i;
		s15r = valueT(1.8873779105534714014) * s5i;
		s15i = valueT(-1.8873779105534714014) * s5r;
		s16r = s3r + s7r;
		s16i = s3i + s7i;
		r163 = valueT(-2.244775412737646562) * s7i;
		i163 = valueT(2.244775412737646562) * s7r;
		s17r = s6r + s8r;
		s17i = s6i + s8i;
		s18r = -s7r - s9r;
		s18i = -s7i - s9i;
		s19r = valueT(-1.4346250692830659266) * s9i;
		s19i = valueT(1.4346250692830659266) * s9r;
		s20r = s10r - s6r;
		s20i = s10i - s6i;
		s21r = s8r - s6r - s10r;
		s21i = s8i - s6i - s10i;
		s22r = s3r - s11r;
		s22i = s3i - s11i;
		s23r = s11r - s5r;
		s23i = s11i - s5i;
		s24r = s11r - s9r;
		s24i = s11i - s9i;
		s25r = valueT(-0.68760514632558187155) * s11i;
		s25i = valueT(0.68760514632558187155) * s11r;
		s26r = s13r - s7r;
		s26i = s13i - s7i;
		s27r = s7r + s13r;
		s27i = s7i + s13i;
		r203 = valueT(-0.91566545995849517431) * s14i;
		i203 = valueT(0.91566545995849517431) * s14r;
		s28r = valueT(2.244775412737646562) * s16i;
		s28i = valueT(-2.244775412737646562) * s16r;
		s29r = valueT(-0.83485429360688276441) * s17i;
		s29i = valueT(0.83485429360688276441) * s17r;
		r201 = valueT(-1.2264668273402374962) * s18i;
		i201 = valueT(1.2264668273402374962) * s18r;
		s30r = s20r - s17r;
		s30i = s20i - s17i;
		s31r = valueT(0.34642356159542270339) * s20i;
		s31i = valueT(-0.34642356159542270339) * s20r;
		s32r = valueT(0.24216105241892630846) * s21i;
		s32i = valueT(-0.24216105241892630846) * s21r;
		s33r = valueT(-0.32317683965956657285) * s22i;
		s33i = valueT(0.32317683965956657285) * s22r;
		s34r = s23r - s9r;
		s34i = s23i - s9i;
		s35r = s9r + s23r;
		s35i = s9i + s23i;
		s36r = s16r - s24r;
		s36i = s16i - s24i;
		s37r = valueT(1.4346250692830659266) * s24i;
		s37i = valueT(-1.4346250692830659266) * s24r;
		s38r = valueT(0.58110158892138584157) * s26i;
		s38i = valueT(-0.58110158892138584157) * s26r;
		s39r = valueT(-0.1700771474529377042) * s27i;
		s39i = valueT(0.1700771474529377042) * s27r;
		s40r = s15r + r203;
		s40i = s15i + i203;
		s41r = s19r + r201;
		s41i = s19i + i201;
		s42r = valueT(-0.39375928506743515593) * s30i;
		s42i = valueT(0.39375928506743515593) * s30r;
		s43r = s12r + s33r;
		s43i = s12i + s33i;
		s44r = s25r + s33r;
		s44i = s25i + s33i;
		s45r = s26r + s34r;
		s45i = s26i + s34i;
		s46r = valueT(0.57902218221296609619) * s34i;
		s46i = valueT(-0.57902218221296609619) * s34r;
		s47r = -s27r - s35r;
		s47i = -s27i - s35i;
		s48r = valueT(0.63264912149723907301) * s35i;
		s48i = valueT(-0.63264912149723907301) * s35r;
		s49r = valueT(1.2264668273402374962) * s36i;
		s49i = valueT(-1.2264668273402374962) * s36r;
		s50r = s29r + s42r;
		s50i = s29i + s42i;
		s51r = s31r + s42r;
		s51i = s31i + s42i;
		s52r = valueT(-0.38670792371145064592) * s45i;
		s52i = valueT(0.38670792371145064592) * s45r;
		s53r = valueT(0.15419065801476712294) * s47i;
		s53i = valueT(-0.15419065801476712294) * s47r;
		r235 = s28r - s49r;
		i235 = s28i - s49i;
		s54r = s37r + s49r;
		s54i = s37i + s49i;
		r266 = s50r - s32r;
		i266 = s50i - s32i;
		s55r = s32r - s51r;
		s55i = s32i - s51i;
		r269 = s32r + s50r + s51r;
		i269 = s32i + s50i + s51i;
		r227 = s38r + s52r;
		i227 = s38i + s52i;
		s56r = s46r + s52r;
		s56i = s46i + s52i;
		r234 = s39r + s53r;
		i234 = s39i + s53i;
		s57r = s48r + s53r;
		s57i = s48i + s53i;
		s58r = s43r - r235;
		s58i = s43i - i235;
		s59r = s44r + s54r;
		s59i = s44i + s54i;
		r260 = r227 - r234;
		i260 = i227 - i234;
		r243 = s41r + s56r + s57r - s54r;
		i243 = s41i + s56i + s57i - s54i;
		s60r = s56r - s57r;
		s60i = s56i - s57i;
		s61r = s58r - r260;
		s61i = s58i - i260;
		r271 = s40r - s60r;
		i271 = s40i - s60i;
		s62r = s59r - s60r;
		s62i = s59i - s60i;
		r289 = s61r - s55r;
		i289 = s61i - s55i;
		s63r = s55r - s62r;
		s63i = s55i - s62i;
		r282 = s55r + s61r + s62r;
		i282 = s55i + s61i + s62i;
		pReal[18 * stride] = r291 - s63r;
		pImag[18 * stride] = i291 - s63i;
		pReal[1 * stride] = r291 + s63r;
		pImag[1 * stride] = i291 + s63i;
	}
	pReal[12 * stride] = -r299 - r282;
	pImag[12 * stride] = -i299 - i282;
	pReal[7 * stride] = r282 - r299;
	pImag[7 * stride] = i282 - i299;
	pReal[11 * stride] = r293 - r289;
	pImag[11 * stride] = i293 - i289;
	pReal[8 * stride] = r293 + r289;
	pImag[8 * stride] = i293 + i289;
	{
		valueT s1r, s1i, s2r, s2i;
		s1r = r166 + r203;
		s1i = i166 + i203;
		s2r = s1r - r260;
		s2i = s1i - i260;
		r288 = r269 - s2r;
		i288 = i269 - s2i;
		r290 = r271 - r269;
		i290 = i271 - i269;
		r287 = r269 + r271 + s2r;
		i287 = i269 + i271 + s2i;
	}
	{
		valueT s1r, s1i;
		r294 = r275 - r273;
		i294 = i275 - i273;
		r292 = r273 - r277;
		i292 = i273 - i277;
		s1r = r277 + r273 + r275;
		s1i = i277 + i273 + i275;
		pReal[10 * stride] = -r287 - s1r;
		pImag[10 * stride] = -i287 - s1i;
		pReal[9 * stride] = r287 - s1r;
		pImag[9 * stride] = i287 - s1i;
	}
	pReal[4 * stride] = -r290 - r292;
	pImag[4 * stride] = -i290 - i292;
	pReal[15 * stride] = r290 - r292;
	pImag[15 * stride] = i290 - i292;
	pReal[13 * stride] = r294 - r288;
	pImag[13 * stride] = i294 - i288;
	pReal[6 * stride] = r288 + r294;
	pImag[6 * stride] = i288 + i294;
	{
		valueT s1r, s1i, s2r, s2i;
		s1r = r163 + r201;
		s1i = i163 + i201;
		s2r = r235 + r227 + r234 + s1r;
		s2i = i235 + i227 + i234 + s1i;
		r285 = r266 - s2r;
		i285 = i266 - s2i;
		r286 = r243 - r266;
		i286 = i243 - i266;
		r284 = r266 + r243 + s2r;
		i284 = i266 + i243 + s2i;
	}
	{
		valueT s1r, s1i;
		r297 = r254 - r276;
		i297 = i254 - i276;
		r295 = r276 - r255;
		i295 = i276 - i255;
		s1r = r255 + r276 + r254;
		s1i = i255 + i276 + i254;
		pReal[5 * stride] = -r284 - s1r;
		pImag[5 * stride] = -i284 - s1i;
		pReal[14 * stride] = r284 - s1r;
		pImag[14 * stride] = i284 - s1i;
	}
	pReal[2 * stride] = -r286 - r295;
	pImag[2 * stride] = -i286 - i295;
	pReal[17 * stride] = r286 - r295;
	pImag[17 * stride] = i286 - i295;
	pReal[16 * stride] = r297 - r285;
	pImag[16 * stride] = i297 - i285;
	pReal[3 * stride] = r285 + r297;
	pImag[3 * stride] = i285 + i297;
}

template<> void StandardModule<float, 19>::Compute(float *pReal, float *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

template<> void StandardModule<double, 19>::Compute(double *pReal, double *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

}
}
