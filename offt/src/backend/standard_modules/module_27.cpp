
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

template<> StandardModuleComplexity const StandardModule<float, 27>::Complexity = { 0, 0 };
template<> StandardModuleComplexity const StandardModule<double, 27>::Complexity = { 0, 0 };

template<typename valueT>
static void ComputeCore(Phasors<valueT> const &phasors, valueT *pReal, valueT *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement)
{
	valueT r27, i27, r45, i45, r54, i54, r63, i63, r108, i108;
	valueT r15, i15, r24, i24, r51, i51, r60, i60, r195, i195;
	valueT r198, i198, r135, i135, r153, i153, r162, i162, r189, i189;
	valueT r150, i150, r213, i213, r216, i216, r147, i147, r219, i219;
	valueT r237, i237, r270, i270, r345, i345, r297, i297, r321, i321;
	valueT r324, i324, r351, i351, r194, i194, r197, i197, r146, i146;
	valueT r149, i149, r218, i218, r152, i152, r344, i344, r320, i320;
	valueT r377, i377, r378, i378, r193, i193, r196, i196, r145, i145;
	valueT r148, i148, r217, i217, r151, i151, r319, i319, r372, i372;
	valueT r397, i397, r403, i403, r432, i432, r459, i459, r453, i453;
	valueT r374, i374, r400, i400, r429, i429, r456, i456, r178, i178;
	valueT r202, i202, r205, i205, r226, i226, r259, i259, r176, i176;
	valueT r177, i177, r179, i179, r180, i180, r206, i206, r207, i207;
	valueT r227, i227, r228, i228, r286, i286, r335, i335, r336, i336;
	valueT r363, i363, r388, i388, r444, i444, r310, i310, r313, i313;
	valueT r311, i311, r312, i312, r368, i368, r394, i394, r423, i423;
	valueT r450, i450, r339, i339, r365, i365, r366, i366, r391, i391;
	valueT r420, i420, r447, i447, r277, i277, r278, i278, r353, i353;
	valueT r279, i279, r379, i379, r408, i408, r435, i435, r303, i303;
	valueT r306, i306, r333, i333, r302, i302, r359, i359, r360, i360;
	valueT r301, i301, r385, i385, r414, i414, r441, i441, r356, i356;
	valueT r382, i382, r411, i411, r438, i438;

	phasors.Multiply(r27, i27, pReal[26 * stride], pImag[26 * stride], twiddleStart + 26 * twiddleIncrement);
	{
		valueT s1r, s1i;
		phasors.Multiply(s1r, s1i, pReal[17 * stride], pImag[17 * stride], twiddleStart + 17 * twiddleIncrement);
		r45 = s1r - r27;
		i45 = s1i - i27;
		r54 = r27 + s1r;
		i54 = i27 + s1i;
	}
	{
		valueT s1r, s1i;
		phasors.Multiply(s1r, s1i, pReal[8 * stride], pImag[8 * stride], twiddleStart + 8 * twiddleIncrement);
		r63 = r54 + s1r;
		i63 = i54 + s1i;
		r108 = valueT(-1.5) * r54;
		i108 = valueT(-1.5) * i54;
	}
	{
		valueT s1r, s1i;
		phasors.Multiply(s1r, s1i, pReal[5 * stride], pImag[5 * stride], twiddleStart + 5 * twiddleIncrement);
		phasors.Multiply(r15, i15, pReal[14 * stride], pImag[14 * stride], twiddleStart + 14 * twiddleIncrement);
		phasors.Multiply(r24, i24, pReal[23 * stride], pImag[23 * stride], twiddleStart + 23 * twiddleIncrement);
		r51 = r15 + r24;
		i51 = i15 + i24;
		r60 = s1r + r51;
		i60 = s1i + i51;
		r195 = r60 - r63;
		i195 = i60 - i63;
		r198 = r63 + r60;
		i198 = i63 + i60;
		r135 = r63 + r108;
		i135 = i63 + i108;
	}
	{
		valueT s1r, s1i;
		s1r = valueT(-0.86602540378443864676) * i45;
		s1i = valueT(0.86602540378443864676) * r45;
		r153 = s1r - r135;
		i153 = s1i - i135;
		r162 = r135 + s1r;
		i162 = i135 + s1i;
	}
	r189 = valueT(0.17364817766693034885) * r162 - valueT(0.98480775301220805937) * i162;
	i189 = valueT(0.98480775301220805937) * r162 + valueT(0.17364817766693034885) * i162;
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i;
		s1r = r15 - r24;
		s1i = i15 - i24;
		s2r = valueT(-0.86602540378443864676) * s1i;
		s2i = valueT(0.86602540378443864676) * s1r;
		s3r = valueT(-1.5) * r51;
		s3i = valueT(-1.5) * i51;
		s4r = r60 + s3r;
		s4i = i60 + s3i;
		r150 = s2r - s4r;
		i150 = s2i - s4i;
		s5r = s2r + s4r;
		s5i = s2i + s4i;
		s6r = valueT(0.7660444431189780352) * s5r - valueT(0.64278760968653932632) * s5i;
		s6i = valueT(0.64278760968653932632) * s5r + valueT(0.7660444431189780352) * s5i;
		r213 = s6r - r189;
		i213 = s6i - i189;
		r216 = r189 + s6r;
		i216 = i189 + s6i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		phasors.Multiply(s1r, s1i, pReal[2 * stride], pImag[2 * stride], twiddleStart + 2 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[11 * stride], pImag[11 * stride], twiddleStart + 11 * twiddleIncrement);
		phasors.Multiply(s3r, s3i, pReal[20 * stride], pImag[20 * stride], twiddleStart + 20 * twiddleIncrement);
		s4r = s2r - s3r;
		s4i = s2i - s3i;
		s5r = s2r + s3r;
		s5i = s2i + s3i;
		s6r = valueT(-0.86602540378443864676) * s4i;
		s6i = valueT(0.86602540378443864676) * s4r;
		s7r = s1r + s5r;
		s7i = s1i + s5i;
		s8r = valueT(-1.5) * s5r;
		s8i = valueT(-1.5) * s5i;
		s9r = s7r + s8r;
		s9i = s7i + s8i;
		r147 = s6r - s9r;
		i147 = s6i - s9i;
		s10r = s6r + s9r;
		s10i = s6i + s9i;
		r219 = r198 + s7r;
		i219 = i198 + s7i;
		r237 = r216 + s10r;
		i237 = i216 + s10i;
		r270 = valueT(-1.5) * r216;
		i270 = valueT(-1.5) * i216;
	}
	r345 = valueT(0.89363264032341224819) * r237 - valueT(0.44879918020046217279) * i237;
	i345 = valueT(0.44879918020046217279) * r237 + valueT(0.89363264032341224819) * i237;
	r297 = r237 + r270;
	i297 = i237 + i270;
	{
		valueT s1r, s1i;
		s1r = valueT(-0.86602540378443864676) * i213;
		s1i = valueT(0.86602540378443864676) * r213;
		r321 = s1r - r297;
		i321 = s1i - i297;
		r324 = r297 + s1r;
		i324 = i297 + s1i;
	}
	r351 = valueT(-0.2868032327110902531) * r324 - valueT(0.95798951231548887444) * i324;
	i351 = valueT(0.95798951231548887444) * r324 - valueT(0.2868032327110902531) * i324;
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		valueT s11r, s11i, s12r, s12i, s13r, s13i, s14r, s14i, s15r, s15i;
		valueT s16r, s16i, s17r, s17i, s18r, s18i, s19r, s19i, s20r, s20i;
		valueT s21r, s21i, s22r, s22i, s23r, s23i, s24r, s24i, s25r, s25i;
		valueT s26r, s26i, s27r, s27i, s28r, s28i, s29r, s29i, s30r, s30i;
		valueT s31r, s31i, s32r, s32i, s33r, s33i, s34r, s34i, s35r, s35i;
		valueT s36r, s36i, s37r, s37i, s38r, s38i, s39r, s39i, s40r, s40i;
		phasors.Multiply(s1r, s1i, pReal[1 * stride], pImag[1 * stride], twiddleStart + 1 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[4 * stride], pImag[4 * stride], twiddleStart + 4 * twiddleIncrement);
		phasors.Multiply(s3r, s3i, pReal[7 * stride], pImag[7 * stride], twiddleStart + 7 * twiddleIncrement);
		phasors.Multiply(s4r, s4i, pReal[10 * stride], pImag[10 * stride], twiddleStart + 10 * twiddleIncrement);
		phasors.Multiply(s5r, s5i, pReal[13 * stride], pImag[13 * stride], twiddleStart + 13 * twiddleIncrement);
		phasors.Multiply(s6r, s6i, pReal[16 * stride], pImag[16 * stride], twiddleStart + 16 * twiddleIncrement);
		phasors.Multiply(s7r, s7i, pReal[19 * stride], pImag[19 * stride], twiddleStart + 19 * twiddleIncrement);
		phasors.Multiply(s8r, s8i, pReal[22 * stride], pImag[22 * stride], twiddleStart + 22 * twiddleIncrement);
		phasors.Multiply(s9r, s9i, pReal[25 * stride], pImag[25 * stride], twiddleStart + 25 * twiddleIncrement);
		s10r = s4r - s7r;
		s10i = s4i - s7i;
		s11r = s4r + s7r;
		s11i = s4i + s7i;
		s12r = s5r - s8r;
		s12i = s5i - s8i;
		s13r = s5r + s8r;
		s13i = s5i + s8i;
		s14r = s6r - s9r;
		s14i = s6i - s9i;
		s15r = s6r + s9r;
		s15i = s6i + s9i;
		s16r = valueT(-0.86602540378443864676) * s10i;
		s16i = valueT(0.86602540378443864676) * s10r;
		s17r = s1r + s11r;
		s17i = s1i + s11i;
		s18r = valueT(-1.5) * s11r;
		s18i = valueT(-1.5) * s11i;
		s19r = valueT(-0.86602540378443864676) * s12i;
		s19i = valueT(0.86602540378443864676) * s12r;
		s20r = s2r + s13r;
		s20i = s2i + s13i;
		s21r = valueT(-1.5) * s13r;
		s21i = valueT(-1.5) * s13i;
		s22r = valueT(-0.86602540378443864676) * s14i;
		s22i = valueT(0.86602540378443864676) * s14r;
		s23r = s3r + s15r;
		s23i = s3i + s15i;
		s24r = valueT(-1.5) * s15r;
		s24i = valueT(-1.5) * s15i;
		s25r = s17r + s18r;
		s25i = s17i + s18i;
		s26r = s20r + s21r;
		s26i = s20i + s21i;
		r194 = s20r - s23r;
		i194 = s20i - s23i;
		r197 = s20r + s23r;
		i197 = s20i + s23i;
		s27r = s23r + s24r;
		s27i = s23i + s24i;
		r146 = s16r - s25r;
		i146 = s16i - s25i;
		s28r = s16r + s25r;
		s28i = s16i + s25i;
		r149 = s19r - s26r;
		i149 = s19i - s26i;
		s29r = s19r + s26r;
		s29i = s19i + s26i;
		r218 = s17r + r197;
		i218 = s17i + i197;
		r152 = s22r - s27r;
		i152 = s22i - s27i;
		s30r = s22r + s27r;
		s30i = s22i + s27i;
		s31r = valueT(0.7660444431189780352) * s29r - valueT(0.64278760968653932632) * s29i;
		s31i = valueT(0.64278760968653932632) * s29r + valueT(0.7660444431189780352) * s29i;
		s32r = valueT(0.17364817766693034885) * s30r - valueT(0.98480775301220805937) * s30i;
		s32i = valueT(0.98480775301220805937) * s30r + valueT(0.17364817766693034885) * s30i;
		s33r = s31r - s32r;
		s33i = s31i - s32i;
		s34r = s31r + s32r;
		s34i = s31i + s32i;
		s35r = valueT(-0.86602540378443864676) * s33i;
		s35i = valueT(0.86602540378443864676) * s33r;
		s36r = s28r + s34r;
		s36i = s28i + s34i;
		s37r = valueT(-1.5) * s34r;
		s37i = valueT(-1.5) * s34i;
		r344 = valueT(0.97304487057982383883) * s36r - valueT(0.23061587074244017845) * s36i;
		i344 = valueT(0.23061587074244017845) * s36r + valueT(0.97304487057982383883) * s36i;
		s38r = s36r + s37r;
		s38i = s36i + s37i;
		r320 = s35r - s38r;
		i320 = s35i - s38i;
		s39r = s35r + s38r;
		s39i = s35i + s38i;
		s40r = valueT(0.59715859170278616485) * s39r - valueT(0.80212319275504378508) * s39i;
		s40i = valueT(0.80212319275504378508) * s39r + valueT(0.59715859170278616485) * s39i;
		r377 = s40r - r351;
		i377 = s40i - i351;
		r378 = r351 + s40r;
		i378 = i351 + s40i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		valueT s11r, s11i, s12r, s12i, s13r, s13i, s14r, s14i, s15r, s15i;
		valueT s16r, s16i, s17r, s17i, s18r, s18i, s19r, s19i, s20r, s20i;
		valueT s21r, s21i, s22r, s22i, s23r, s23i, s24r, s24i, s25r, s25i;
		valueT s26r, s26i, s27r, s27i, s28r, s28i, s29r, s29i, s30r, s30i;
		valueT s31r, s31i, s32r, s32i, s33r, s33i, s34r, s34i, s35r, s35i;
		valueT s36r, s36i, s37r, s37i, s38r, s38i, s39r, s39i;
		phasors.Multiply(s1r, s1i, pReal[0 * stride], pImag[0 * stride], twiddleStart + 0 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[3 * stride], pImag[3 * stride], twiddleStart + 3 * twiddleIncrement);
		phasors.Multiply(s3r, s3i, pReal[6 * stride], pImag[6 * stride], twiddleStart + 6 * twiddleIncrement);
		phasors.Multiply(s4r, s4i, pReal[9 * stride], pImag[9 * stride], twiddleStart + 9 * twiddleIncrement);
		phasors.Multiply(s5r, s5i, pReal[12 * stride], pImag[12 * stride], twiddleStart + 12 * twiddleIncrement);
		phasors.Multiply(s6r, s6i, pReal[15 * stride], pImag[15 * stride], twiddleStart + 15 * twiddleIncrement);
		phasors.Multiply(s7r, s7i, pReal[18 * stride], pImag[18 * stride], twiddleStart + 18 * twiddleIncrement);
		phasors.Multiply(s8r, s8i, pReal[21 * stride], pImag[21 * stride], twiddleStart + 21 * twiddleIncrement);
		phasors.Multiply(s9r, s9i, pReal[24 * stride], pImag[24 * stride], twiddleStart + 24 * twiddleIncrement);
		s10r = s4r - s7r;
		s10i = s4i - s7i;
		s11r = s4r + s7r;
		s11i = s4i + s7i;
		s12r = s5r - s8r;
		s12i = s5i - s8i;
		s13r = s5r + s8r;
		s13i = s5i + s8i;
		s14r = s6r - s9r;
		s14i = s6i - s9i;
		s15r = s6r + s9r;
		s15i = s6i + s9i;
		s16r = valueT(-0.86602540378443864676) * s10i;
		s16i = valueT(0.86602540378443864676) * s10r;
		s17r = s1r + s11r;
		s17i = s1i + s11i;
		s18r = valueT(-1.5) * s11r;
		s18i = valueT(-1.5) * s11i;
		s19r = valueT(-0.86602540378443864676) * s12i;
		s19i = valueT(0.86602540378443864676) * s12r;
		s20r = s2r + s13r;
		s20i = s2i + s13i;
		s21r = valueT(-1.5) * s13r;
		s21i = valueT(-1.5) * s13i;
		s22r = valueT(-0.86602540378443864676) * s14i;
		s22i = valueT(0.86602540378443864676) * s14r;
		s23r = s3r + s15r;
		s23i = s3i + s15i;
		s24r = valueT(-1.5) * s15r;
		s24i = valueT(-1.5) * s15i;
		s25r = s17r + s18r;
		s25i = s17i + s18i;
		s26r = s20r + s21r;
		s26i = s20i + s21i;
		r193 = s20r - s23r;
		i193 = s20i - s23i;
		r196 = s20r + s23r;
		i196 = s20i + s23i;
		s27r = s23r + s24r;
		s27i = s23i + s24i;
		r145 = s16r - s25r;
		i145 = s16i - s25i;
		s28r = s16r + s25r;
		s28i = s16i + s25i;
		r148 = s19r - s26r;
		i148 = s19i - s26i;
		s29r = s19r + s26r;
		s29i = s19i + s26i;
		r217 = s17r + r196;
		i217 = s17i + i196;
		r151 = s22r - s27r;
		i151 = s22i - s27i;
		s30r = s22r + s27r;
		s30i = s22i + s27i;
		s31r = valueT(0.7660444431189780352) * s29r - valueT(0.64278760968653932632) * s29i;
		s31i = valueT(0.64278760968653932632) * s29r + valueT(0.7660444431189780352) * s29i;
		s32r = valueT(0.17364817766693034885) * s30r - valueT(0.98480775301220805937) * s30i;
		s32i = valueT(0.98480775301220805937) * s30r + valueT(0.17364817766693034885) * s30i;
		s33r = s31r - s32r;
		s33i = s31i - s32i;
		s34r = s31r + s32r;
		s34i = s31i + s32i;
		s35r = valueT(-0.86602540378443864676) * s33i;
		s35i = valueT(0.86602540378443864676) * s33r;
		s36r = s28r + s34r;
		s36i = s28i + s34i;
		s37r = valueT(-1.5) * s34r;
		s37i = valueT(-1.5) * s34i;
		s38r = s36r + s37r;
		s38i = s36i + s37i;
		r319 = s35r - s38r;
		i319 = s35i - s38i;
		s39r = s35r + s38r;
		s39i = s35i + s38i;
		r372 = r345 + r344;
		i372 = i345 + i344;
		r397 = s36r + r372;
		i397 = s36i + i372;
		r403 = r378 + s39r;
		i403 = i378 + s39i;
		r432 = valueT(-1.5) * r378;
		i432 = valueT(-1.5) * i378;
	}
	pReal[4 * stride] = r403;
	pImag[4 * stride] = i403;
	r459 = r403 + r432;
	i459 = i403 + i432;
	{
		valueT s1r, s1i;
		s1r = valueT(-0.86602540378443864676) * i377;
		s1i = valueT(0.86602540378443864676) * r377;
		pReal[22 * stride] = r459 - s1r;
		pImag[22 * stride] = i459 - s1i;
		pReal[13 * stride] = r459 + s1r;
		pImag[13 * stride] = i459 + s1i;
	}
	{
		valueT s1r, s1i;
		s1r = valueT(-1.5) * r372;
		s1i = valueT(-1.5) * i372;
		pReal[1 * stride] = r397;
		pImag[1 * stride] = i397;
		r453 = r397 + s1r;
		i453 = i397 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i;
		s1r = r344 - r345;
		s1i = i344 - i345;
		s2r = valueT(-0.86602540378443864676) * s1i;
		s2i = valueT(0.86602540378443864676) * s1r;
		pReal[19 * stride] = r453 - s2r;
		pImag[19 * stride] = i453 - s2i;
		pReal[10 * stride] = r453 + s2r;
		pImag[10 * stride] = i453 + s2i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i;
		s1r = valueT(0.058144828910475828539) * r320 + valueT(0.99830815827126820805) * i320;
		s1i = valueT(0.058144828910475828539) * i320 - valueT(0.99830815827126820805) * r320;
		s2r = valueT(0.99323835774194298855) * r321 - valueT(0.11609291412523022968) * i321;
		s2i = valueT(0.11609291412523022968) * r321 + valueT(0.99323835774194298855) * i321;
		r374 = s1r - s2r;
		i374 = s1i - s2i;
		s3r = s1r + s2r;
		s3i = s1i + s2i;
		r400 = r319 - s3r;
		i400 = i319 - s3i;
		r429 = valueT(-1.5) * s3r;
		i429 = valueT(-1.5) * s3i;
	}
	pReal[7 * stride] = -r400;
	pImag[7 * stride] = -i400;
	r456 = r429 - r400;
	i456 = i429 - i400;
	{
		valueT s1r, s1i;
		s1r = valueT(-0.86602540378443864676) * i374;
		s1i = valueT(0.86602540378443864676) * r374;
		pReal[25 * stride] = r456 - s1r;
		pImag[25 * stride] = i456 - s1i;
		pReal[16 * stride] = r456 + s1r;
		pImag[16 * stride] = i456 + s1i;
	}
	r178 = valueT(0.93969262078590838405) * r151 + valueT(0.34202014332566873304) * i151;
	i178 = valueT(0.93969262078590838405) * i151 - valueT(0.34202014332566873304) * r151;
	{
		valueT s1r, s1i;
		s1r = valueT(0.98480775301220805937) * i148 - valueT(0.17364817766693034885) * r148;
		s1i = valueT(-0.98480775301220805937) * r148 - valueT(0.17364817766693034885) * i148;
		r202 = s1r - r178;
		i202 = s1i - i178;
		r205 = r178 + s1r;
		i205 = i178 + s1i;
	}
	r226 = r145 - r205;
	i226 = i145 - i205;
	r259 = valueT(-1.5) * r205;
	i259 = valueT(-1.5) * i205;
	r176 = valueT(0.98480775301220805937) * i149 - valueT(0.17364817766693034885) * r149;
	i176 = valueT(-0.98480775301220805937) * r149 - valueT(0.17364817766693034885) * i149;
	r177 = valueT(0.98480775301220805937) * i150 - valueT(0.17364817766693034885) * r150;
	i177 = valueT(-0.98480775301220805937) * r150 - valueT(0.17364817766693034885) * i150;
	r179 = valueT(0.93969262078590838405) * r152 + valueT(0.34202014332566873304) * i152;
	i179 = valueT(0.93969262078590838405) * i152 - valueT(0.34202014332566873304) * r152;
	r180 = valueT(0.93969262078590838405) * r153 + valueT(0.34202014332566873304) * i153;
	i180 = valueT(0.93969262078590838405) * i153 - valueT(0.34202014332566873304) * r153;
	r206 = r176 + r179;
	i206 = i176 + i179;
	r207 = r177 + r180;
	i207 = i177 + i180;
	r227 = r146 - r206;
	i227 = i146 - i206;
	r228 = r147 - r207;
	i228 = i147 - i207;
	r286 = r259 - r226;
	i286 = i259 - i226;
	r335 = valueT(0.44879918020046217279) * i227 - valueT(0.89363264032341224819) * r227;
	i335 = valueT(-0.44879918020046217279) * r227 - valueT(0.89363264032341224819) * i227;
	r336 = valueT(0.80212319275504378508) * i228 - valueT(0.59715859170278616485) * r228;
	i336 = valueT(-0.80212319275504378508) * r228 - valueT(0.59715859170278616485) * i228;
	r363 = r335 + r336;
	i363 = i335 + i336;
	r388 = r226 - r363;
	i388 = i226 - i363;
	{
		valueT s1r, s1i;
		s1r = valueT(-1.5) * r363;
		s1i = valueT(-1.5) * i363;
		pReal[2 * stride] = -r388;
		pImag[2 * stride] = -i388;
		r444 = s1r - r388;
		i444 = s1i - i388;
	}
	{
		valueT s1r, s1i, s2r, s2i;
		s1r = r335 - r336;
		s1i = i335 - i336;
		s2r = valueT(-0.86602540378443864676) * s1i;
		s2i = valueT(0.86602540378443864676) * s1r;
		pReal[20 * stride] = r444 - s2r;
		pImag[20 * stride] = i444 - s2i;
		pReal[11 * stride] = r444 + s2r;
		pImag[11 * stride] = i444 + s2i;
	}
	{
		valueT s1r, s1i;
		s1r = valueT(-0.86602540378443864676) * i202;
		s1i = valueT(0.86602540378443864676) * r202;
		r310 = s1r - r286;
		i310 = s1i - i286;
		r313 = r286 + s1r;
		i313 = i286 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		valueT s11r, s11i, s12r, s12i, s13r, s13i;
		s1r = r176 - r179;
		s1i = i176 - i179;
		s2r = r177 - r180;
		s2i = i177 - i180;
		s3r = valueT(-0.86602540378443864676) * s1i;
		s3i = valueT(0.86602540378443864676) * s1r;
		s4r = valueT(-1.5) * r206;
		s4i = valueT(-1.5) * i206;
		s5r = valueT(-0.86602540378443864676) * s2i;
		s5i = valueT(0.86602540378443864676) * s2r;
		s6r = valueT(-1.5) * r207;
		s6i = valueT(-1.5) * i207;
		s7r = s4r - r227;
		s7i = s4i - i227;
		s8r = s6r - r228;
		s8i = s6i - i228;
		r311 = s3r - s7r;
		i311 = s3i - s7i;
		s9r = s3r + s7r;
		s9i = s3i + s7i;
		r312 = s5r - s8r;
		i312 = s5i - s8i;
		s10r = s5r + s8r;
		s10i = s5i + s8i;
		s11r = valueT(0.3960797660391568237) * s9r - valueT(0.91821610688027401476) * s9i;
		s11i = valueT(0.91821610688027401476) * s9r + valueT(0.3960797660391568237) * s9i;
		s12r = valueT(-0.68624163786873358573) * s10r - valueT(0.72737364157304869599) * s10i;
		s12i = valueT(0.72737364157304869599) * s10r - valueT(0.68624163786873358573) * s10i;
		r368 = s11r - s12r;
		i368 = s11i - s12i;
		s13r = s11r + s12r;
		s13i = s11i + s12i;
		r394 = r313 + s13r;
		i394 = i313 + s13i;
		r423 = valueT(-1.5) * s13r;
		i423 = valueT(-1.5) * s13i;
	}
	pReal[5 * stride] = r394;
	pImag[5 * stride] = i394;
	r450 = r394 + r423;
	i450 = i394 + i423;
	{
		valueT s1r, s1i;
		s1r = valueT(-0.86602540378443864676) * i368;
		s1i = valueT(0.86602540378443864676) * r368;
		pReal[23 * stride] = r450 - s1r;
		pImag[23 * stride] = i450 - s1i;
		pReal[14 * stride] = r450 + s1r;
		pImag[14 * stride] = i450 + s1i;
	}
	r339 = valueT(0.83548781141293641965) * r312 - valueT(0.54950897807080603526) * i312;
	i339 = valueT(0.54950897807080603526) * r312 + valueT(0.83548781141293641965) * i312;
	{
		valueT s1r, s1i;
		s1r = valueT(0.2868032327110902531) * r311 + valueT(0.95798951231548887444) * i311;
		s1i = valueT(0.2868032327110902531) * i311 - valueT(0.95798951231548887444) * r311;
		r365 = s1r - r339;
		i365 = s1i - i339;
		r366 = r339 + s1r;
		i366 = i339 + s1i;
	}
	r391 = r310 - r366;
	i391 = i310 - i366;
	r420 = valueT(-1.5) * r366;
	i420 = valueT(-1.5) * i366;
	pReal[8 * stride] = -r391;
	pImag[8 * stride] = -i391;
	r447 = r420 - r391;
	i447 = i420 - i391;
	{
		valueT s1r, s1i;
		s1r = valueT(-0.86602540378443864676) * i365;
		s1i = valueT(0.86602540378443864676) * r365;
		pReal[26 * stride] = r447 - s1r;
		pImag[26 * stride] = i447 - s1i;
		pReal[17 * stride] = r447 + s1r;
		pImag[17 * stride] = i447 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i;
		s1r = valueT(-1.5) * r196;
		s1i = valueT(-1.5) * i196;
		s2r = valueT(-1.5) * r197;
		s2i = valueT(-1.5) * i197;
		s3r = valueT(-1.5) * r198;
		s3i = valueT(-1.5) * i198;
		r277 = r217 + s1r;
		i277 = i217 + s1i;
		r278 = r218 + s2r;
		i278 = i218 + s2i;
		r353 = r218 - r219;
		i353 = i218 - i219;
		s4r = r219 + r218;
		s4i = i219 + i218;
		r279 = r219 + s3r;
		i279 = i219 + s3i;
		r379 = r217 + s4r;
		i379 = i217 + s4i;
		r408 = valueT(-1.5) * s4r;
		i408 = valueT(-1.5) * s4i;
	}
	pReal[0 * stride] = r379;
	pImag[0 * stride] = i379;
	r435 = r379 + r408;
	i435 = i379 + i408;
	{
		valueT s1r, s1i;
		s1r = valueT(-0.86602540378443864676) * i353;
		s1i = valueT(0.86602540378443864676) * r353;
		pReal[18 * stride] = r435 - s1r;
		pImag[18 * stride] = i435 - s1i;
		pReal[9 * stride] = r435 + s1r;
		pImag[9 * stride] = i435 + s1i;
	}
	{
		valueT s1r, s1i;
		s1r = valueT(-0.86602540378443864676) * i195;
		s1i = valueT(0.86602540378443864676) * r195;
		r303 = s1r - r279;
		i303 = s1i - i279;
		r306 = r279 + s1r;
		i306 = i279 + s1i;
	}
	r333 = valueT(0.17364817766693034885) * r306 - valueT(0.98480775301220805937) * i306;
	i333 = valueT(0.98480775301220805937) * r306 + valueT(0.17364817766693034885) * i306;
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i;
		s1r = valueT(-0.86602540378443864676) * i194;
		s1i = valueT(0.86602540378443864676) * r194;
		r302 = s1r - r278;
		i302 = s1i - i278;
		s2r = r278 + s1r;
		s2i = i278 + s1i;
		s3r = valueT(0.7660444431189780352) * s2r - valueT(0.64278760968653932632) * s2i;
		s3i = valueT(0.64278760968653932632) * s2r + valueT(0.7660444431189780352) * s2i;
		r359 = s3r - r333;
		i359 = s3i - i333;
		r360 = r333 + s3r;
		i360 = i333 + s3i;
	}
	{
		valueT s1r, s1i, s2r, s2i;
		s1r = valueT(-0.86602540378443864676) * i193;
		s1i = valueT(0.86602540378443864676) * r193;
		r301 = s1r - r277;
		i301 = s1i - i277;
		s2r = r277 + s1r;
		s2i = i277 + s1i;
		r385 = r360 + s2r;
		i385 = i360 + s2i;
		r414 = valueT(-1.5) * r360;
		i414 = valueT(-1.5) * i360;
	}
	pReal[3 * stride] = r385;
	pImag[3 * stride] = i385;
	r441 = r385 + r414;
	i441 = i385 + i414;
	{
		valueT s1r, s1i;
		s1r = valueT(-0.86602540378443864676) * i359;
		s1i = valueT(0.86602540378443864676) * r359;
		pReal[21 * stride] = r441 - s1r;
		pImag[21 * stride] = i441 - s1i;
		pReal[12 * stride] = r441 + s1r;
		pImag[12 * stride] = i441 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i;
		s1r = valueT(0.98480775301220805937) * i302 - valueT(0.17364817766693034885) * r302;
		s1i = valueT(-0.98480775301220805937) * r302 - valueT(0.17364817766693034885) * i302;
		s2r = valueT(0.93969262078590838405) * r303 + valueT(0.34202014332566873304) * i303;
		s2i = valueT(0.93969262078590838405) * i303 - valueT(0.34202014332566873304) * r303;
		r356 = s1r - s2r;
		i356 = s1i - s2i;
		s3r = s1r + s2r;
		s3i = s1i + s2i;
		r382 = r301 - s3r;
		i382 = i301 - s3i;
		r411 = valueT(-1.5) * s3r;
		i411 = valueT(-1.5) * s3i;
	}
	pReal[6 * stride] = -r382;
	pImag[6 * stride] = -i382;
	r438 = r411 - r382;
	i438 = i411 - i382;
	{
		valueT s1r, s1i;
		s1r = valueT(-0.86602540378443864676) * i356;
		s1i = valueT(0.86602540378443864676) * r356;
		pReal[24 * stride] = r438 - s1r;
		pImag[24 * stride] = i438 - s1i;
		pReal[15 * stride] = r438 + s1r;
		pImag[15 * stride] = i438 + s1i;
	}
}

template<> void StandardModule<float, 27>::Compute(float *pReal, float *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

template<> void StandardModule<double, 27>::Compute(double *pReal, double *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

}
}
