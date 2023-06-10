
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

template<> StandardModuleComplexity const StandardModule<float, 17>::Complexity = { 0, 0 };
template<> StandardModuleComplexity const StandardModule<double, 17>::Complexity = { 0, 0 };

template<typename valueT>
static void ComputeCore(Phasors<valueT> const &phasors, valueT *pReal, valueT *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement)
{
	valueT r17, i17, r19, i19, r34, i34, r22, i22, r48, i48;
	valueT r51, i51, r26, i26, r20, i20, r44, i44, r71, i71;
	valueT r72, i72, r25, i25, r24, i24, r23, i23, r21, i21;
	valueT r45, i45, r47, i47, r67, i67, r99, i99, r101, i101;
	valueT r127, i127, r185, i185, r227, i227, r267, i267, r269, i269;
	valueT r264, i264, r297, i297, r298, i298, r179, i179, r208, i208;
	valueT r265, i265, r280, i280, r291, i291, r316, i316, r319, i319;
	valueT r176, i176, r175, i175, r84, i84, r174, i174, r121, i121;
	valueT r171, i171, r210, i210, r189, i189, r209, i209, r207, i207;
	valueT r206, i206, r256, i256, r277, i277, r278, i278, r272, i272;
	valueT r290, i290, r279, i279, r300, i300, r307, i307, r259, i259;
	valueT r305, i305, r311, i311, r318, i318, r287, i287, r288, i288;
	valueT r301, i301, r309, i309, r310, i310, r294, i294, r296, i296;
	valueT r314, i314, r315, i315, r317, i317, r306, i306;

	phasors.Multiply(r17, i17, pReal[16 * stride], pImag[16 * stride], twiddleStart + 16 * twiddleIncrement);
	{
		valueT s1r, s1i;
		phasors.Multiply(s1r, s1i, pReal[1 * stride], pImag[1 * stride], twiddleStart + 1 * twiddleIncrement);
		r19 = s1r - r17;
		i19 = s1i - i17;
		r34 = r17 + s1r;
		i34 = i17 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i;
		phasors.Multiply(s1r, s1i, pReal[4 * stride], pImag[4 * stride], twiddleStart + 4 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[13 * stride], pImag[13 * stride], twiddleStart + 13 * twiddleIncrement);
		r22 = s1r - s2r;
		i22 = s1i - s2i;
		s3r = s1r + s2r;
		s3i = s1i + s2i;
		r48 = s3r - r34;
		i48 = s3i - i34;
		r51 = r34 + s3r;
		i51 = i34 + s3i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i;
		phasors.Multiply(s1r, s1i, pReal[2 * stride], pImag[2 * stride], twiddleStart + 2 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[8 * stride], pImag[8 * stride], twiddleStart + 8 * twiddleIncrement);
		phasors.Multiply(s3r, s3i, pReal[9 * stride], pImag[9 * stride], twiddleStart + 9 * twiddleIncrement);
		phasors.Multiply(s4r, s4i, pReal[15 * stride], pImag[15 * stride], twiddleStart + 15 * twiddleIncrement);
		r26 = s2r - s3r;
		i26 = s2i - s3i;
		s5r = s2r + s3r;
		s5i = s2i + s3i;
		r20 = s1r - s4r;
		i20 = s1i - s4i;
		s6r = s1r + s4r;
		s6i = s1i + s4i;
		r44 = s5r - s6r;
		i44 = s5i - s6i;
		s7r = s5r + s6r;
		s7i = s5i + s6i;
		r71 = s7r - r51;
		i71 = s7i - i51;
		r72 = r51 + s7r;
		i72 = i51 + s7i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		valueT s11r, s11i, s12r, s12i, s13r, s13i, s14r, s14i, s15r, s15i;
		phasors.Multiply(s1r, s1i, pReal[3 * stride], pImag[3 * stride], twiddleStart + 3 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[5 * stride], pImag[5 * stride], twiddleStart + 5 * twiddleIncrement);
		phasors.Multiply(s3r, s3i, pReal[6 * stride], pImag[6 * stride], twiddleStart + 6 * twiddleIncrement);
		phasors.Multiply(s4r, s4i, pReal[7 * stride], pImag[7 * stride], twiddleStart + 7 * twiddleIncrement);
		phasors.Multiply(s5r, s5i, pReal[10 * stride], pImag[10 * stride], twiddleStart + 10 * twiddleIncrement);
		phasors.Multiply(s6r, s6i, pReal[11 * stride], pImag[11 * stride], twiddleStart + 11 * twiddleIncrement);
		phasors.Multiply(s7r, s7i, pReal[12 * stride], pImag[12 * stride], twiddleStart + 12 * twiddleIncrement);
		phasors.Multiply(s8r, s8i, pReal[14 * stride], pImag[14 * stride], twiddleStart + 14 * twiddleIncrement);
		r25 = s4r - s5r;
		i25 = s4i - s5i;
		s9r = s4r + s5r;
		s9i = s4i + s5i;
		r24 = s3r - s6r;
		i24 = s3i - s6i;
		s10r = s3r + s6r;
		s10i = s3i + s6i;
		r23 = s2r - s7r;
		i23 = s2i - s7i;
		s11r = s2r + s7r;
		s11i = s2i + s7i;
		r21 = s1r - s8r;
		i21 = s1i - s8i;
		s12r = s1r + s8r;
		s12i = s1i + s8i;
		r45 = s9r - s10r;
		i45 = s9i - s10i;
		s13r = s9r + s10r;
		s13i = s9i + s10i;
		r47 = s11r - s12r;
		i47 = s11i - s12i;
		s14r = s11r + s12r;
		s14i = s11i + s12i;
		r67 = s13r - s14r;
		i67 = s13i - s14i;
		s15r = s13r + s14r;
		s15i = s13i + s14i;
		r99 = s15r - r72;
		i99 = s15i - i72;
		r101 = r72 + s15r;
		i101 = i72 + s15i;
	}
	{
		valueT s1r, s1i;
		phasors.Multiply(s1r, s1i, pReal[0 * stride], pImag[0 * stride], twiddleStart + 0 * twiddleIncrement);
		r127 = r101 + s1r;
		i127 = i101 + s1i;
		r185 = valueT(-1.0625) * r101;
		i185 = valueT(-1.0625) * i101;
	}
	pReal[0 * stride] = r127;
	pImag[0 * stride] = i127;
	r227 = r127 + r185;
	i227 = i127 + i185;
	{
		valueT s1r, s1i;
		s1r = valueT(-0.25769410160110378436) * r99;
		s1i = valueT(-0.25769410160110378436) * i99;
		r267 = s1r - r227;
		i267 = s1i - i227;
		r269 = r227 + s1r;
		i269 = i227 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		s1r = valueT(-0.08905559162060637075) * r67;
		s1i = valueT(-0.08905559162060637075) * i67;
		s2r = r71 - r67;
		s2i = i71 - i67;
		s3r = valueT(-0.72340797728605660184) * r71;
		s3i = valueT(-0.72340797728605660184) * i71;
		s4r = valueT(0.40623178445333148629) * s2r;
		s4i = valueT(0.40623178445333148629) * s2i;
		r264 = s1r - s4r;
		i264 = s1i - s4i;
		s5r = s3r + s4r;
		s5i = s3i + s4i;
		r297 = s5r - r269;
		i297 = s5i - i269;
		r298 = r269 + s5r;
		i298 = i269 + s5i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		valueT s11r, s11i, s12r, s12i, s13r, s13i, s14r, s14i, s15r, s15i;
		valueT s16r, s16i;
		r179 = valueT(-0.042602849117735904509) * r45;
		i179 = valueT(-0.042602849117735904509) * i45;
		s1r = r45 + r47;
		s1i = i45 + i47;
		s2r = valueT(1.0451835201736756678) * r47;
		s2i = valueT(1.0451835201736756678) * i47;
		s3r = r44 - r45;
		s3i = i44 - i45;
		s4r = valueT(-1.7645848660222967987) * r44;
		s4i = valueT(-1.7645848660222967987) * i44;
		s5r = r48 - r47;
		s5i = i48 - i47;
		s6r = r48 + r44;
		s6i = i48 + i44;
		s7r = valueT(0.20497965023262185845) * r48;
		s7i = valueT(0.20497965023262185845) * i48;
		s8r = valueT(0.54389318464570578614) * s1r;
		s8i = valueT(0.54389318464570578614) * s1i;
		r208 = valueT(0.48349192259948944695) * s3r;
		i208 = valueT(0.48349192259948944695) * s3i;
		s9r = valueT(0.23590942324913168399) * s5r;
		s9i = valueT(0.23590942324913168399) * s5i;
		s10r = s6r - s1r;
		s10i = s6i - s1i;
		s11r = valueT(0.98478225812745932858) * s6r;
		s11i = valueT(0.98478225812745932858) * s6i;
		s12r = s4r + r208;
		s12i = s4i + i208;
		r265 = s2r - s9r;
		i265 = s2i - s9i;
		s13r = s7r + s9r;
		s13i = s7i + s9i;
		s14r = valueT(-0.12379124967517888148) * s10r;
		s14i = valueT(-0.12379124967517888148) * s10i;
		r280 = s8r - s14r;
		i280 = s8i - s14i;
		s15r = s11r + s14r;
		s15i = s11i + s14i;
		r291 = s12r + s15r;
		i291 = s12i + s15i;
		s16r = s13r - s15r;
		s16i = s13i - s15i;
		r316 = s16r - r298;
		i316 = s16i - i298;
		r319 = r298 + s16r;
		i319 = i298 + s16i;
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
		valueT s41r, s41i, s42r, s42i, s43r, s43i, s44r, s44i;
		s1r = valueT(-3.4722080422851535691) * i26;
		s1i = valueT(3.4722080422851535691) * r26;
		s2r = r25 - r26;
		s2i = i25 - i26;
		r176 = valueT(-3.104709006652012906) * i25;
		i176 = valueT(3.104709006652012906) * r25;
		s3r = r24 - r25;
		s3i = i24 - i25;
		r175 = valueT(-0.63663632735975597915) * i24;
		i175 = valueT(0.63663632735975597915) * r24;
		r84 = r24 + r23;
		i84 = i24 + i23;
		r174 = valueT(0.060376328307232261758) * i23;
		i174 = valueT(-0.060376328307232261758) * r23;
		s4r = r22 + r23;
		s4i = i22 + i23;
		s5r = valueT(-2.0518446808973013055) * i22;
		s5i = valueT(2.0518446808973013055) * r22;
		s6r = r25 + r21;
		s6i = i25 + i21;
		s7r = r21 - r23;
		s7i = i21 - i23;
		s8r = valueT(1.681881459575028925) * i21;
		s8i = valueT(-1.681881459575028925) * r21;
		s9r = r20 - r26;
		s9i = i20 - i26;
		r121 = r20 - r24;
		i121 = i20 - i24;
		s10r = r20 - r22;
		s10i = i20 - i22;
		r171 = valueT(-1.9840276146528704026) * i20;
		i171 = valueT(1.9840276146528704026) * r20;
		s11r = r19 + r26;
		s11i = i19 + i26;
		s12r = r19 + r22;
		s12i = i19 + i22;
		s13r = r19 - r21;
		s13i = i19 - i21;
		s14r = valueT(0.95939812720072302752) * i19;
		s14i = valueT(-0.95939812720072302752) * r19;
		r210 = valueT(-1.2577870383398385552) * s2i;
		i210 = valueT(1.2577870383398385552) * s2r;
		r189 = valueT(1.8706726670058844426) * s3i;
		i189 = valueT(-1.8706726670058844426) * s3r;
		r209 = valueT(0.20492271258512695475) * s4i;
		i209 = valueT(-0.20492271258512695475) * s4r;
		s15r = valueT(2.6814252326397827742) * s6i;
		s15i = valueT(-2.6814252326397827742) * s6r;
		s16r = s3r - s7r;
		s16i = s3i - s7i;
		s17r = valueT(0.87112889394113059338) * s7i;
		s17i = valueT(-0.87112889394113059338) * s7r;
		s18r = s9r - s3r;
		s18i = s9i - s3i;
		s19r = valueT(2.7281178284690119859) * s9i;
		s19i = valueT(-2.7281178284690119859) * s9r;
		s20r = s10r - r84;
		s20i = s10i - i84;
		s21r = valueT(0.76153119023287058323) * s10i;
		s21i = valueT(-0.76153119023287058323) * s10r;
		s22r = s6r - s11r;
		s22i = s6i - s11i;
		s23r = valueT(2.1818945516207228469) * s11i;
		s23i = valueT(-2.1818945516207228469) * s11r;
		s24r = s7r - s12r;
		s24i = s7i - s12i;
		s25r = s9r - s12r;
		s25i = s9i - s12i;
		s26r = valueT(1.5056214040490121665) * s12i;
		s26i = valueT(-1.5056214040490121665) * s12r;
		s27r = valueT(0.5325395443702860889) * s13i;
		s27i = valueT(-0.5325395443702860889) * s13r;
		s28r = s1r + r210;
		s28i = s1i + i210;
		s29r = s5r + r209;
		s29i = s5i + i209;
		s30r = valueT(1.1592588934673924521) * s16i;
		s30i = valueT(-1.1592588934673924521) * s16r;
		r207 = valueT(-1.6931805186353018254) * s18i;
		i207 = valueT(1.6931805186353018254) * s18r;
		r206 = valueT(-0.27158506440288370309) * s20i;
		i206 = valueT(0.27158506440288370309) * s20r;
		s31r = valueT(1.3244493901575953036) * s22i;
		s31i = valueT(-1.3244493901575953036) * s22r;
		s32r = valueT(-0.16380841589257956708) * s24i;
		s32i = valueT(0.16380841589257956708) * s24r;
		s33r = s25r - s16r;
		s33i = s25i - s16i;
		s34r = valueT(1.471712870926796715) * s25i;
		s34i = valueT(-1.471712870926796715) * s25r;
		r256 = s8r - s27r;
		i256 = s8i - s27i;
		s35r = s14r + s27r;
		s35i = s14i + s27i;
		s36r = s19r + r207;
		s36i = s19i + i207;
		r277 = s21r + r206;
		i277 = s21i + i206;
		r278 = s15r - s31r;
		i278 = s15i - s31i;
		s37r = s23r + s31r;
		s37i = s23i + s31i;
		r272 = s17r - s32r;
		i272 = s17i - s32i;
		s38r = s26r + s32r;
		s38i = s26i + s32i;
		s39r = valueT(-0.79801722728023950333) * s33i;
		s39i = valueT(0.79801722728023950333) * s33r;
		s40r = s29r - r277;
		s40i = s29i - i277;
		r290 = s28r + s37r;
		i290 = s28i + s37i;
		s41r = s35r - s37r;
		s41i = s35i - s37i;
		r279 = s30r - s39r;
		i279 = s30i - s39i;
		s42r = s34r + s39r;
		s42i = s34i + s39i;
		r300 = s36r - s42r;
		i300 = s36i - s42i;
		s43r = s38r + s42r;
		s43i = s38i + s42i;
		r307 = s40r + s43r;
		i307 = s40i + s43i;
		s44r = s41r - s43r;
		s44i = s41i - s43i;
		pReal[16 * stride] = r319 - s44r;
		pImag[16 * stride] = i319 - s44i;
		pReal[1 * stride] = r319 + s44r;
		pImag[1 * stride] = i319 + s44i;
	}
	pReal[4 * stride] = -r316 - r307;
	pImag[4 * stride] = -i316 - i307;
	pReal[13 * stride] = r307 - r316;
	pImag[13 * stride] = i307 - i316;
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i;
		s1r = valueT(2.1285739989307650956) * i121;
		s1i = valueT(-2.1285739989307650956) * r121;
		r259 = r175 - s1r;
		i259 = i175 - s1i;
		s2r = r171 + s1r;
		s2i = i171 + s1i;
		s3r = r277 + s2r;
		s3i = i277 + s2i;
		r305 = r300 + s3r;
		i305 = i300 + s3i;
		r311 = r290 - r300;
		i311 = i290 - i300;
	}
	{
		valueT s1r, s1i;
		s1r = r291 - r297;
		s1i = i291 - i297;
		r318 = r297 + r291;
		i318 = i297 + i291;
		pReal[8 * stride] = s1r - r311;
		pImag[8 * stride] = s1i - i311;
		pReal[9 * stride] = r311 + s1r;
		pImag[9 * stride] = i311 + s1i;
	}
	pReal[2 * stride] = -r305 - r318;
	pImag[2 * stride] = -i305 - i318;
	pReal[15 * stride] = r305 - r318;
	pImag[15 * stride] = i305 - i318;
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i;
		s1r = valueT(-0.36290744570499787004) * i84;
		s1i = valueT(0.36290744570499787004) * r84;
		s2r = r174 - r209;
		s2i = i174 - i209;
		s3r = s1r - r206;
		s3i = s1i - i206;
		r287 = s2r - s3r;
		i287 = s2i - s3i;
		r288 = r259 + s3r;
		i288 = i259 + s3i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i;
		s1r = r176 - r210;
		s1i = i176 - i210;
		s2r = r189 - r207;
		s2i = i189 - i207;
		s3r = r278 + s1r;
		s3i = i278 + s1i;
		s4r = s2r - r279;
		s4i = s2i - i279;
		r301 = r272 + r279;
		i301 = i272 + i279;
		r309 = r288 + s4r;
		i309 = i288 + s4i;
		r310 = s3r - s4r;
		i310 = s3i - s4i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i;
		s1r = r179 - r208;
		s1i = i179 - i208;
		s2r = r280 + s1r;
		s2i = i280 + s1i;
		r294 = r265 - r280;
		i294 = i265 - i280;
		r296 = r267 - r264;
		i296 = i267 - i264;
		s3r = r267 + r264;
		s3i = i267 + i264;
		s4r = s2r - s3r;
		s4i = s2i - s3i;
		r314 = s2r + s3r;
		i314 = s2i + s3i;
		pReal[7 * stride] = s4r - r310;
		pImag[7 * stride] = s4i - i310;
		pReal[10 * stride] = r310 + s4r;
		pImag[10 * stride] = i310 + s4i;
	}
	pReal[6 * stride] = -r309 - r314;
	pImag[6 * stride] = -i309 - i314;
	pReal[11 * stride] = r309 - r314;
	pImag[11 * stride] = i309 - i314;
	r315 = r294 - r296;
	i315 = i294 - i296;
	r317 = r294 + r296;
	i317 = i294 + i296;
	{
		valueT s1r, s1i, s2r, s2i;
		s1r = r256 - r278;
		s1i = i256 - i278;
		s2r = r287 + r301;
		s2i = i287 + i301;
		r306 = s1r - r301;
		i306 = s1i - i301;
		pReal[12 * stride] = -r317 - s2r;
		pImag[12 * stride] = -i317 - s2i;
		pReal[5 * stride] = s2r - r317;
		pImag[5 * stride] = s2i - i317;
	}
	pReal[14 * stride] = r315 - r306;
	pImag[14 * stride] = i315 - i306;
	pReal[3 * stride] = r315 + r306;
	pImag[3 * stride] = i315 + i306;
}

template<> void StandardModule<float, 17>::Compute(float *pReal, float *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

template<> void StandardModule<double, 17>::Compute(double *pReal, double *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

}
}
