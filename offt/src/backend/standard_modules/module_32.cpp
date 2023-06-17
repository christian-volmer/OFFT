
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

template<> StandardModuleComplexity const StandardModule<float, 32>::Complexity = { 0, 0 };
template<> StandardModuleComplexity const StandardModule<double, 32>::Complexity = { 0, 0 };

template<typename valueT>
static void ComputeCore(Phasors<valueT> const &phasors, valueT *pReal, valueT *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement)
{
	valueT r32, i32, r176, i176, r192, i192, r168, i168, r248, i248;
	valueT r256, i256, r100, i100, r108, i108, r180, i180, r284, i284;
	valueT r288, i288, r98, i98, r166, i166, r106, i106, r174, i174;
	valueT r178, i178, r246, i246, r282, i282, r350, i350, r352, i352;
	valueT r33, i33, r67, i67, r69, i69, r71, i71, r41, i41;
	valueT r75, i75, r77, i77, r79, i79, r81, i81, r147, i147;
	valueT r149, i149, r151, i151, r185, i185, r251, i251, r285, i285;
	valueT r283, i283, r281, i281, r348, i348, r215, i215, r243, i243;
	valueT r247, i247, r177, i177, r279, i279, r277, i277, r274, i274;
	valueT r276, i276, r344, i344, r308, i308, r338, i338, r340, i340;
	valueT r273, i273, r143, i143, r135, i135, r199, i199, r139, i139;
	valueT r227, i227, r231, i231, r65, i65, r133, i133, r169, i169;
	valueT r263, i263, r269, i269, r162, i162, r164, i164, r230, i230;
	valueT r232, i232, r266, i266, r268, i268, r334, i334, r300, i300;
	valueT r330, i330, r332, i332, r259, i259, r264, i264, r260, i260;
	valueT r292, i292, r262, i262, r322, i322, r324, i324, r161, i161;
	valueT r239, i239, r261, i261, r257, i257, r271, i271, r326, i326;

	phasors.Multiply(r32, i32, pReal[31 * stride], pImag[31 * stride], twiddleStart + 31 * twiddleIncrement);
	{
		valueT s1r, s1i;
		phasors.Multiply(s1r, s1i, pReal[15 * stride], pImag[15 * stride], twiddleStart + 15 * twiddleIncrement);
		r176 = s1r - r32;
		i176 = s1i - i32;
		r192 = r32 + s1r;
		i192 = i32 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i;
		phasors.Multiply(s1r, s1i, pReal[7 * stride], pImag[7 * stride], twiddleStart + 7 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[23 * stride], pImag[23 * stride], twiddleStart + 23 * twiddleIncrement);
		r168 = s1r - s2r;
		i168 = s1i - s2i;
		s3r = s1r + s2r;
		s3i = s1i + s2i;
		r248 = s3r - r192;
		i248 = s3i - i192;
		r256 = r192 + s3r;
		i256 = i192 + s3i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i;
		phasors.Multiply(s1r, s1i, pReal[3 * stride], pImag[3 * stride], twiddleStart + 3 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[11 * stride], pImag[11 * stride], twiddleStart + 11 * twiddleIncrement);
		phasors.Multiply(s3r, s3i, pReal[19 * stride], pImag[19 * stride], twiddleStart + 19 * twiddleIncrement);
		phasors.Multiply(s4r, s4i, pReal[27 * stride], pImag[27 * stride], twiddleStart + 27 * twiddleIncrement);
		r100 = s1r - s3r;
		i100 = s1i - s3i;
		s5r = s1r + s3r;
		s5i = s1i + s3i;
		r108 = s2r - s4r;
		i108 = s2i - s4i;
		s6r = s2r + s4r;
		s6i = s2i + s4i;
		r180 = s5r - s6r;
		i180 = s5i - s6i;
		s7r = s5r + s6r;
		s7i = s5i + s6i;
		r284 = s7r - r256;
		i284 = s7i - i256;
		r288 = r256 + s7r;
		i288 = i256 + s7i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		valueT s11r, s11i, s12r, s12i, s13r, s13i, s14r, s14i, s15r, s15i;
		phasors.Multiply(s1r, s1i, pReal[1 * stride], pImag[1 * stride], twiddleStart + 1 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[5 * stride], pImag[5 * stride], twiddleStart + 5 * twiddleIncrement);
		phasors.Multiply(s3r, s3i, pReal[9 * stride], pImag[9 * stride], twiddleStart + 9 * twiddleIncrement);
		phasors.Multiply(s4r, s4i, pReal[13 * stride], pImag[13 * stride], twiddleStart + 13 * twiddleIncrement);
		phasors.Multiply(s5r, s5i, pReal[17 * stride], pImag[17 * stride], twiddleStart + 17 * twiddleIncrement);
		phasors.Multiply(s6r, s6i, pReal[21 * stride], pImag[21 * stride], twiddleStart + 21 * twiddleIncrement);
		phasors.Multiply(s7r, s7i, pReal[25 * stride], pImag[25 * stride], twiddleStart + 25 * twiddleIncrement);
		phasors.Multiply(s8r, s8i, pReal[29 * stride], pImag[29 * stride], twiddleStart + 29 * twiddleIncrement);
		r98 = s1r - s5r;
		i98 = s1i - s5i;
		s9r = s1r + s5r;
		s9i = s1i + s5i;
		r166 = s2r - s6r;
		i166 = s2i - s6i;
		s10r = s2r + s6r;
		s10i = s2i + s6i;
		r106 = s3r - s7r;
		i106 = s3i - s7i;
		s11r = s3r + s7r;
		s11i = s3i + s7i;
		r174 = s4r - s8r;
		i174 = s4i - s8i;
		s12r = s4r + s8r;
		s12i = s4i + s8i;
		r178 = s9r - s11r;
		i178 = s9i - s11i;
		s13r = s9r + s11r;
		s13i = s9i + s11i;
		r246 = s10r - s12r;
		i246 = s10i - s12i;
		s14r = s10r + s12r;
		s14i = s10i + s12i;
		r282 = s13r - s14r;
		i282 = s13i - s14i;
		s15r = s13r + s14r;
		s15i = s13i + s14i;
		r350 = s15r - r288;
		i350 = s15i - i288;
		r352 = r288 + s15r;
		i352 = i288 + s15i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		valueT s11r, s11i, s12r, s12i, s13r, s13i, s14r, s14i, s15r, s15i;
		valueT s16r, s16i, s17r, s17i, s18r, s18i, s19r, s19i, s20r, s20i;
		valueT s21r, s21i, s22r, s22i, s23r, s23i, s24r, s24i, s25r, s25i;
		valueT s26r, s26i, s27r, s27i, s28r, s28i, s29r, s29i, s30r, s30i;
		valueT s31r, s31i;
		phasors.Multiply(s1r, s1i, pReal[0 * stride], pImag[0 * stride], twiddleStart + 0 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[2 * stride], pImag[2 * stride], twiddleStart + 2 * twiddleIncrement);
		phasors.Multiply(s3r, s3i, pReal[4 * stride], pImag[4 * stride], twiddleStart + 4 * twiddleIncrement);
		phasors.Multiply(s4r, s4i, pReal[6 * stride], pImag[6 * stride], twiddleStart + 6 * twiddleIncrement);
		phasors.Multiply(s5r, s5i, pReal[8 * stride], pImag[8 * stride], twiddleStart + 8 * twiddleIncrement);
		phasors.Multiply(s6r, s6i, pReal[10 * stride], pImag[10 * stride], twiddleStart + 10 * twiddleIncrement);
		phasors.Multiply(s7r, s7i, pReal[12 * stride], pImag[12 * stride], twiddleStart + 12 * twiddleIncrement);
		phasors.Multiply(s8r, s8i, pReal[14 * stride], pImag[14 * stride], twiddleStart + 14 * twiddleIncrement);
		phasors.Multiply(s9r, s9i, pReal[16 * stride], pImag[16 * stride], twiddleStart + 16 * twiddleIncrement);
		phasors.Multiply(s10r, s10i, pReal[18 * stride], pImag[18 * stride], twiddleStart + 18 * twiddleIncrement);
		phasors.Multiply(s11r, s11i, pReal[20 * stride], pImag[20 * stride], twiddleStart + 20 * twiddleIncrement);
		phasors.Multiply(s12r, s12i, pReal[22 * stride], pImag[22 * stride], twiddleStart + 22 * twiddleIncrement);
		phasors.Multiply(s13r, s13i, pReal[24 * stride], pImag[24 * stride], twiddleStart + 24 * twiddleIncrement);
		phasors.Multiply(s14r, s14i, pReal[26 * stride], pImag[26 * stride], twiddleStart + 26 * twiddleIncrement);
		phasors.Multiply(s15r, s15i, pReal[28 * stride], pImag[28 * stride], twiddleStart + 28 * twiddleIncrement);
		phasors.Multiply(s16r, s16i, pReal[30 * stride], pImag[30 * stride], twiddleStart + 30 * twiddleIncrement);
		r33 = s1r - s9r;
		i33 = s1i - s9i;
		s17r = s1r + s9r;
		s17i = s1i + s9i;
		r67 = s2r - s10r;
		i67 = s2i - s10i;
		s18r = s2r + s10r;
		s18i = s2i + s10i;
		r69 = s3r - s11r;
		i69 = s3i - s11i;
		s19r = s3r + s11r;
		s19i = s3i + s11i;
		r71 = s4r - s12r;
		i71 = s4i - s12i;
		s20r = s4r + s12r;
		s20i = s4i + s12i;
		r41 = s5r - s13r;
		i41 = s5i - s13i;
		s21r = s5r + s13r;
		s21i = s5i + s13i;
		r75 = s6r - s14r;
		i75 = s6i - s14i;
		s22r = s6r + s14r;
		s22i = s6i + s14i;
		r77 = s7r - s15r;
		i77 = s7i - s15i;
		s23r = s7r + s15r;
		s23i = s7i + s15i;
		r79 = s8r - s16r;
		i79 = s8i - s16i;
		s24r = s8r + s16r;
		s24i = s8i + s16i;
		r81 = s17r - s21r;
		i81 = s17i - s21i;
		s25r = s17r + s21r;
		s25i = s17i + s21i;
		r147 = s18r - s22r;
		i147 = s18i - s22i;
		s26r = s18r + s22r;
		s26i = s18i + s22i;
		r149 = s19r - s23r;
		i149 = s19i - s23i;
		s27r = s19r + s23r;
		s27i = s19i + s23i;
		r151 = s20r - s24r;
		i151 = s20i - s24i;
		s28r = s20r + s24r;
		s28i = s20i + s24i;
		r185 = s25r - s27r;
		i185 = s25i - s27i;
		s29r = s25r + s27r;
		s29i = s25i + s27i;
		r251 = s26r - s28r;
		i251 = s26i - s28i;
		s30r = s26r + s28r;
		s30i = s26i + s28i;
		r285 = s29r - s30r;
		i285 = s29i - s30i;
		s31r = s29r + s30r;
		s31i = s29i + s30i;
		pReal[16 * stride] = s31r - r352;
		pImag[16 * stride] = s31i - i352;
		pReal[0 * stride] = r352 + s31r;
		pImag[0 * stride] = i352 + s31i;
	}
	pReal[24 * stride] = i350 + r285;
	pImag[24 * stride] = i285 - r350;
	pReal[8 * stride] = r285 - i350;
	pImag[8 * stride] = r350 + i285;
	r283 = i185 + r251;
	i283 = i251 - r185;
	r281 = r185 + i251;
	i281 = i185 - r251;
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i;
		s1r = valueT(0.7071067811865475244) * r282 - valueT(0.7071067811865475244) * i282;
		s1i = valueT(0.7071067811865475244) * r282 + valueT(0.7071067811865475244) * i282;
		s2r = valueT(-0.7071067811865475244) * r284 - valueT(0.7071067811865475244) * i284;
		s2i = valueT(0.7071067811865475244) * r284 - valueT(0.7071067811865475244) * i284;
		s3r = s1r - s2r;
		s3i = s1i - s2i;
		r348 = s1r + s2r;
		i348 = s1i + s2i;
		pReal[28 * stride] = r281 + s3i;
		pImag[28 * stride] = i281 - s3r;
		pReal[12 * stride] = r281 - s3i;
		pImag[12 * stride] = i281 + s3r;
	}
	pReal[20 * stride] = -i283 - r348;
	pImag[20 * stride] = r283 - i348;
	pReal[4 * stride] = r348 - i283;
	pImag[4 * stride] = r283 + i348;
	r215 = valueT(-0.7071067811865475244) * r151 - valueT(0.7071067811865475244) * i151;
	i215 = valueT(0.7071067811865475244) * r151 - valueT(0.7071067811865475244) * i151;
	{
		valueT s1r, s1i;
		s1r = valueT(0.7071067811865475244) * r147 - valueT(0.7071067811865475244) * i147;
		s1i = valueT(0.7071067811865475244) * r147 + valueT(0.7071067811865475244) * i147;
		r243 = s1r - r215;
		i243 = s1i - i215;
		r247 = r215 + s1r;
		i247 = i215 + s1i;
	}
	{
		valueT s1r, s1i;
		s1r = i81 + r149;
		s1i = i149 - r81;
		r177 = r81 + i149;
		i177 = i81 - r149;
		r279 = r247 - s1i;
		i279 = i247 + s1r;
		r277 = s1r - i247;
		i277 = r247 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		s1r = i178 + r246;
		s1i = i246 - r178;
		r274 = r178 + i246;
		i274 = i178 - r246;
		s2r = r248 + i180;
		s2i = i248 - r180;
		r276 = i248 + r180;
		i276 = i180 - r248;
		s3r = valueT(-0.38268343236508977173) * s1r - valueT(0.92387953251128675613) * s1i;
		s3i = valueT(0.92387953251128675613) * s1r - valueT(0.38268343236508977173) * s1i;
		s4r = valueT(-0.92387953251128675613) * s2r - valueT(0.38268343236508977173) * s2i;
		s4i = valueT(0.38268343236508977173) * s2r - valueT(0.92387953251128675613) * s2i;
		s5r = s3r - s4r;
		s5i = s3i - s4i;
		r344 = s3r + s4r;
		i344 = s3i + s4i;
		pReal[26 * stride] = s5i - i277;
		pImag[26 * stride] = r277 - s5r;
		pReal[10 * stride] = -i277 - s5i;
		pImag[10 * stride] = r277 + s5r;
	}
	pReal[18 * stride] = r279 - r344;
	pImag[18 * stride] = i279 - i344;
	pReal[2 * stride] = r279 + r344;
	pImag[2 * stride] = i279 + i344;
	r308 = valueT(0.38268343236508977173) * i276 - valueT(0.92387953251128675613) * r276;
	i308 = valueT(-0.38268343236508977173) * r276 - valueT(0.92387953251128675613) * i276;
	{
		valueT s1r, s1i;
		s1r = valueT(0.38268343236508977173) * r274 - valueT(0.92387953251128675613) * i274;
		s1i = valueT(0.92387953251128675613) * r274 + valueT(0.38268343236508977173) * i274;
		r338 = s1r - r308;
		i338 = s1i - i308;
		r340 = r308 + s1r;
		i340 = i308 + s1i;
	}
	{
		valueT s1r, s1i;
		s1r = r243 + i177;
		s1i = i243 - r177;
		r273 = i243 + r177;
		i273 = i177 - r243;
		pReal[22 * stride] = -r340 - s1i;
		pImag[22 * stride] = s1r - i340;
		pReal[6 * stride] = r340 - s1i;
		pImag[6 * stride] = i340 + s1r;
	}
	pReal[30 * stride] = i338 + r273;
	pImag[30 * stride] = i273 - r338;
	pReal[14 * stride] = r273 - i338;
	pImag[14 * stride] = r338 + i273;
	r143 = r79 - i71;
	i143 = r71 + i79;
	r135 = r71 - i79;
	i135 = i71 + r79;
	r199 = valueT(0.38268343236508977173) * r135 - valueT(0.92387953251128675613) * i135;
	i199 = valueT(0.92387953251128675613) * r135 + valueT(0.38268343236508977173) * i135;
	{
		valueT s1r, s1i, s2r, s2i;
		r139 = r75 - i67;
		i139 = r67 + i75;
		s1r = r67 - i75;
		s1i = i67 + r75;
		s2r = valueT(0.92387953251128675613) * s1r - valueT(0.38268343236508977173) * s1i;
		s2i = valueT(0.38268343236508977173) * s1r + valueT(0.92387953251128675613) * s1i;
		r227 = s2r - r199;
		i227 = s2i - i199;
		r231 = r199 + s2r;
		i231 = i199 + s2i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		s1r = valueT(0.7071067811865475244) * r69 - valueT(0.7071067811865475244) * i69;
		s1i = valueT(0.7071067811865475244) * r69 + valueT(0.7071067811865475244) * i69;
		s2r = i33 + r41;
		s2i = i41 - r33;
		r65 = r33 + i41;
		i65 = i33 - r41;
		s3r = valueT(-0.7071067811865475244) * r77 - valueT(0.7071067811865475244) * i77;
		s3i = valueT(0.7071067811865475244) * r77 - valueT(0.7071067811865475244) * i77;
		r133 = s1r - s3r;
		i133 = s1i - s3i;
		s4r = s1r + s3r;
		s4i = s1i + s3i;
		s5r = s4r - s2i;
		s5i = s2r + s4i;
		r169 = s2r - s4i;
		i169 = s2i + s4r;
		r263 = r231 - s5r;
		i263 = i231 - s5i;
		r269 = r231 + s5r;
		i269 = i231 + s5i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		valueT s11r, s11i, s12r, s12i, s13r, s13i;
		s1r = valueT(0.7071067811865475244) * r166 - valueT(0.7071067811865475244) * i166;
		s1i = valueT(0.7071067811865475244) * r166 + valueT(0.7071067811865475244) * i166;
		s2r = valueT(0.7071067811865475244) * r168 - valueT(0.7071067811865475244) * i168;
		s2i = valueT(0.7071067811865475244) * r168 + valueT(0.7071067811865475244) * i168;
		s3r = i98 + r106;
		s3i = i106 - r98;
		r162 = r98 + i106;
		i162 = i98 - r106;
		s4r = i100 + r108;
		s4i = i108 - r100;
		r164 = r100 + i108;
		i164 = i100 - r108;
		s5r = valueT(-0.7071067811865475244) * r174 - valueT(0.7071067811865475244) * i174;
		s5i = valueT(0.7071067811865475244) * r174 - valueT(0.7071067811865475244) * i174;
		s6r = valueT(-0.7071067811865475244) * r176 - valueT(0.7071067811865475244) * i176;
		s6i = valueT(0.7071067811865475244) * r176 - valueT(0.7071067811865475244) * i176;
		r230 = s1r - s5r;
		i230 = s1i - s5i;
		s7r = s1r + s5r;
		s7i = s1i + s5i;
		r232 = s2r - s6r;
		i232 = s2i - s6i;
		s8r = s2r + s6r;
		s8i = s2i + s6i;
		s9r = s7r - s3i;
		s9i = s3r + s7i;
		r266 = s3r - s7i;
		i266 = s3i + s7r;
		s10r = s8r - s4i;
		s10i = s4r + s8i;
		r268 = s4r - s8i;
		i268 = s4i + s8r;
		s11r = valueT(0.98078528040323044913) * s9r - valueT(0.19509032201612826785) * s9i;
		s11i = valueT(0.19509032201612826785) * s9r + valueT(0.98078528040323044913) * s9i;
		s12r = valueT(0.83146961230254523708) * s10r - valueT(0.55557023301960222474) * s10i;
		s12i = valueT(0.55557023301960222474) * s10r + valueT(0.83146961230254523708) * s10i;
		r334 = s11r - s12r;
		i334 = s11i - s12i;
		s13r = s11r + s12r;
		s13i = s11i + s12i;
		pReal[17 * stride] = r269 - s13r;
		pImag[17 * stride] = i269 - s13i;
		pReal[1 * stride] = r269 + s13r;
		pImag[1 * stride] = i269 + s13i;
	}
	pReal[25 * stride] = i334 - r263;
	pImag[25 * stride] = -i263 - r334;
	pReal[9 * stride] = -r263 - i334;
	pImag[9 * stride] = r334 - i263;
	r300 = valueT(0.98078528040323044913) * i268 - valueT(0.19509032201612826785) * r268;
	i300 = valueT(-0.98078528040323044913) * r268 - valueT(0.19509032201612826785) * i268;
	{
		valueT s1r, s1i;
		s1r = valueT(-0.83146961230254523708) * r266 - valueT(0.55557023301960222474) * i266;
		s1i = valueT(0.55557023301960222474) * r266 - valueT(0.83146961230254523708) * i266;
		r330 = s1r - r300;
		i330 = s1i - i300;
		r332 = r300 + s1r;
		i332 = i300 + s1i;
	}
	{
		valueT s1r, s1i;
		r259 = r227 - r169;
		i259 = i227 - i169;
		s1r = r227 + r169;
		s1i = i227 + i169;
		pReal[21 * stride] = -r332 - s1i;
		pImag[21 * stride] = s1r - i332;
		pReal[5 * stride] = r332 - s1i;
		pImag[5 * stride] = i332 + s1r;
	}
	pReal[29 * stride] = i330 + i259;
	pImag[29 * stride] = -r330 - r259;
	pReal[13 * stride] = i259 - i330;
	pImag[13 * stride] = r330 - r259;
	r264 = i164 + r232;
	i264 = i232 - r164;
	r260 = r164 + i232;
	i260 = i164 - r232;
	r292 = valueT(0.83146961230254523708) * i260 - valueT(0.55557023301960222474) * r260;
	i292 = valueT(-0.83146961230254523708) * r260 - valueT(0.55557023301960222474) * i260;
	{
		valueT s1r, s1i, s2r, s2i;
		r262 = i162 + r230;
		i262 = i230 - r162;
		s1r = r162 + i230;
		s1i = i162 - r230;
		s2r = valueT(0.19509032201612826785) * s1r - valueT(0.98078528040323044913) * s1i;
		s2i = valueT(0.98078528040323044913) * s1r + valueT(0.19509032201612826785) * s1i;
		r322 = s2r - r292;
		i322 = s2i - i292;
		r324 = r292 + s2r;
		i324 = i292 + s2i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		s1r = valueT(0.92387953251128675613) * r139 + valueT(0.38268343236508977173) * i139;
		s1i = valueT(0.92387953251128675613) * i139 - valueT(0.38268343236508977173) * r139;
		s2r = valueT(-0.38268343236508977173) * r143 - valueT(0.92387953251128675613) * i143;
		s2i = valueT(0.92387953251128675613) * r143 - valueT(0.38268343236508977173) * i143;
		s3r = r133 - i65;
		s3i = r65 + i133;
		r161 = r65 - i133;
		i161 = i65 + r133;
		s4r = s1r - s2r;
		s4i = s1i - s2i;
		r239 = s1r + s2r;
		i239 = s1i + s2i;
		s5r = s4r - s3r;
		s5i = s4i - s3i;
		r261 = s3r + s4r;
		i261 = s3i + s4i;
		pReal[23 * stride] = -r324 - s5i;
		pImag[23 * stride] = s5r - i324;
		pReal[7 * stride] = r324 - s5i;
		pImag[7 * stride] = i324 + s5r;
	}
	pReal[31 * stride] = i322 + i261;
	pImag[31 * stride] = -r322 - r261;
	pReal[15 * stride] = i261 - i322;
	pImag[15 * stride] = r322 - r261;
	r257 = r161 - r239;
	i257 = i161 - i239;
	r271 = r161 + r239;
	i271 = i161 + i239;
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i;
		s1r = valueT(-0.55557023301960222474) * r262 - valueT(0.83146961230254523708) * i262;
		s1i = valueT(0.83146961230254523708) * r262 - valueT(0.55557023301960222474) * i262;
		s2r = valueT(0.19509032201612826785) * i264 - valueT(0.98078528040323044913) * r264;
		s2i = valueT(-0.19509032201612826785) * r264 - valueT(0.98078528040323044913) * i264;
		r326 = s1r - s2r;
		i326 = s1i - s2i;
		s3r = s1r + s2r;
		s3i = s1i + s2i;
		pReal[19 * stride] = r271 - s3r;
		pImag[19 * stride] = i271 - s3i;
		pReal[3 * stride] = r271 + s3r;
		pImag[3 * stride] = i271 + s3i;
	}
	pReal[27 * stride] = r257 + i326;
	pImag[27 * stride] = i257 - r326;
	pReal[11 * stride] = r257 - i326;
	pImag[11 * stride] = i257 + r326;
}

template<> void StandardModule<float, 32>::Compute(float *pReal, float *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

template<> void StandardModule<double, 32>::Compute(double *pReal, double *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

}
}
