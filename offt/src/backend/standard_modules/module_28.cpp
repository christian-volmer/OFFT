
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

template<> StandardModuleComplexity const StandardModule<float, 28>::Complexity = { 0, 0 };
template<> StandardModuleComplexity const StandardModule<double, 28>::Complexity = { 0, 0 };

template<typename valueT>
static void ComputeCore(Phasors<valueT> const &phasors, valueT *pReal, valueT *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement)
{
	valueT r28, i28, r42, i42, r56, i56, r30, i30, r72, i72;
	valueT r84, i84, r32, i32, r34, i34, r38, i38, r40, i40;
	valueT r76, i76, r74, i74, r110, i110, r114, i114, r108, i108;
	valueT r112, i112, r180, i180, r1, i1, r3, i3, r5, i5;
	valueT r7, i7, r9, i9, r11, i11, r13, i13, r15, i15;
	valueT r17, i17, r19, i19, r21, i21, r23, i23, r25, i25;
	valueT r27, i27, r45, i45, r47, i47, r49, i49, r36, i36;
	valueT r51, i51, r53, i53, r55, i55, r79, i79, r81, i81;
	valueT r83, i83, r107, i107, r131, i131, r248, i248, r246, i246;
	valueT r244, i244, r240, i240, r238, i238, r272, i272, r264, i264;
	valueT r245, i245, r243, i243, r239, i239, r237, i237, r262, i262;
	valueT r271, i271, r265, i265, r268, i268, r273, i273, r267, i267;
	valueT r266, i266, r62, i62, r60, i60, r58, i58, r96, i96;
	valueT r113, i113, r98, i98, r124, i124, r162, i162, r31, i31;
	valueT r33, i33, r35, i35, r37, i37, r39, i39, r41, i41;
	valueT r63, i63, r61, i61, r59, i59, r89, i89, r117, i117;
	valueT r198, i198, r247, i247, r232, i232, r230, i230, r226, i226;
	valueT r224, i224, r258, i258, r250, i250, r225, i225, r223, i223;
	valueT r231, i231, r229, i229, r255, i255, r251, i251, r257, i257;
	valueT r275, i275, r259, i259, r253, i253, r252, i252;

	phasors.Multiply(r28, i28, pReal[27 * stride], pImag[27 * stride], twiddleStart + 27 * twiddleIncrement);
	{
		valueT s1r, s1i;
		phasors.Multiply(s1r, s1i, pReal[13 * stride], pImag[13 * stride], twiddleStart + 13 * twiddleIncrement);
		r42 = s1r - r28;
		i42 = s1i - i28;
		r56 = r28 + s1r;
		i56 = i28 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i;
		phasors.Multiply(s1r, s1i, pReal[1 * stride], pImag[1 * stride], twiddleStart + 1 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[15 * stride], pImag[15 * stride], twiddleStart + 15 * twiddleIncrement);
		r30 = s1r - s2r;
		i30 = s1i - s2i;
		s3r = s1r + s2r;
		s3i = s1i + s2i;
		r72 = s3r - r56;
		i72 = s3i - i56;
		r84 = r56 + s3r;
		i84 = i56 + s3i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		valueT s11r, s11i, s12r, s12i, s13r, s13i, s14r, s14i;
		phasors.Multiply(s1r, s1i, pReal[3 * stride], pImag[3 * stride], twiddleStart + 3 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[5 * stride], pImag[5 * stride], twiddleStart + 5 * twiddleIncrement);
		phasors.Multiply(s3r, s3i, pReal[9 * stride], pImag[9 * stride], twiddleStart + 9 * twiddleIncrement);
		phasors.Multiply(s4r, s4i, pReal[11 * stride], pImag[11 * stride], twiddleStart + 11 * twiddleIncrement);
		phasors.Multiply(s5r, s5i, pReal[17 * stride], pImag[17 * stride], twiddleStart + 17 * twiddleIncrement);
		phasors.Multiply(s6r, s6i, pReal[19 * stride], pImag[19 * stride], twiddleStart + 19 * twiddleIncrement);
		phasors.Multiply(s7r, s7i, pReal[23 * stride], pImag[23 * stride], twiddleStart + 23 * twiddleIncrement);
		phasors.Multiply(s8r, s8i, pReal[25 * stride], pImag[25 * stride], twiddleStart + 25 * twiddleIncrement);
		r32 = s1r - s5r;
		i32 = s1i - s5i;
		s9r = s1r + s5r;
		s9i = s1i + s5i;
		r34 = s2r - s6r;
		i34 = s2i - s6i;
		s10r = s2r + s6r;
		s10i = s2i + s6i;
		r38 = s3r - s7r;
		i38 = s3i - s7i;
		s11r = s3r + s7r;
		s11i = s3i + s7i;
		r40 = s4r - s8r;
		i40 = s4i - s8i;
		s12r = s4r + s8r;
		s12i = s4i + s8i;
		r76 = s10r - s11r;
		i76 = s10i - s11i;
		s13r = s10r + s11r;
		s13i = s10i + s11i;
		r74 = s9r - s12r;
		i74 = s9i - s12i;
		s14r = s9r + s12r;
		s14i = s9i + s12i;
		r110 = s14r - s13r;
		i110 = s14i - s13i;
		r114 = s13r - r84;
		i114 = s13i - i84;
		r108 = r84 + s13r + s14r;
		i108 = i84 + s13i + s14i;
		r112 = r84 - s14r;
		i112 = i84 - s14i;
	}
	r180 = valueT(-0.055854267289647737622) * r112;
	i180 = valueT(-0.055854267289647737622) * i112;
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i;
		phasors.Multiply(r1, i1, pReal[0 * stride], pImag[0 * stride], twiddleStart + 0 * twiddleIncrement);
		phasors.Multiply(r3, i3, pReal[2 * stride], pImag[2 * stride], twiddleStart + 2 * twiddleIncrement);
		phasors.Multiply(r5, i5, pReal[4 * stride], pImag[4 * stride], twiddleStart + 4 * twiddleIncrement);
		phasors.Multiply(r7, i7, pReal[6 * stride], pImag[6 * stride], twiddleStart + 6 * twiddleIncrement);
		phasors.Multiply(s1r, s1i, pReal[7 * stride], pImag[7 * stride], twiddleStart + 7 * twiddleIncrement);
		phasors.Multiply(r9, i9, pReal[8 * stride], pImag[8 * stride], twiddleStart + 8 * twiddleIncrement);
		phasors.Multiply(r11, i11, pReal[10 * stride], pImag[10 * stride], twiddleStart + 10 * twiddleIncrement);
		phasors.Multiply(r13, i13, pReal[12 * stride], pImag[12 * stride], twiddleStart + 12 * twiddleIncrement);
		phasors.Multiply(r15, i15, pReal[14 * stride], pImag[14 * stride], twiddleStart + 14 * twiddleIncrement);
		phasors.Multiply(r17, i17, pReal[16 * stride], pImag[16 * stride], twiddleStart + 16 * twiddleIncrement);
		phasors.Multiply(r19, i19, pReal[18 * stride], pImag[18 * stride], twiddleStart + 18 * twiddleIncrement);
		phasors.Multiply(r21, i21, pReal[20 * stride], pImag[20 * stride], twiddleStart + 20 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[21 * stride], pImag[21 * stride], twiddleStart + 21 * twiddleIncrement);
		phasors.Multiply(r23, i23, pReal[22 * stride], pImag[22 * stride], twiddleStart + 22 * twiddleIncrement);
		phasors.Multiply(r25, i25, pReal[24 * stride], pImag[24 * stride], twiddleStart + 24 * twiddleIncrement);
		phasors.Multiply(r27, i27, pReal[26 * stride], pImag[26 * stride], twiddleStart + 26 * twiddleIncrement);
		s3r = r1 + r15;
		s3i = i1 + i15;
		r45 = r3 + r17;
		i45 = i3 + i17;
		r47 = r5 + r19;
		i47 = i5 + i19;
		r49 = r7 + r21;
		i49 = i7 + i21;
		r36 = s1r - s2r;
		i36 = s1i - s2i;
		s4r = s1r + s2r;
		s4i = s1i + s2i;
		r51 = r9 + r23;
		i51 = i9 + i23;
		r53 = r11 + r25;
		i53 = i11 + i25;
		r55 = r13 + r27;
		i55 = i13 + i27;
		r79 = r49 + r51;
		i79 = i49 + i51;
		r81 = r47 + r53;
		i81 = i47 + i53;
		r83 = r45 + r55;
		i83 = i45 + i55;
		r107 = r79 + r81 + r83;
		i107 = i79 + i81 + i83;
		s5r = valueT(0.73430220123575245957) * r110;
		s5i = valueT(0.73430220123575245957) * i110;
		r131 = s3r + r107;
		i131 = s3i + i107;
		s6r = valueT(-0.79015646852540019719) * r114;
		s6i = valueT(-0.79015646852540019719) * i114;
		s7r = r108 + s4r;
		s7i = i108 + s4i;
		s8r = valueT(-1.1666666666666666667) * r108;
		s8i = valueT(-1.1666666666666666667) * i108;
		pReal[14 * stride] = r131 - s7r;
		pImag[14 * stride] = i131 - s7i;
		pReal[0 * stride] = r131 + s7r;
		pImag[0 * stride] = i131 + s7i;
		s9r = s7r + s8r;
		s9i = s7i + s8i;
		r248 = s6r + s9r - s5r;
		i248 = s6i + s9i - s5i;
		r246 = r180 + s5r + s9r;
		i246 = i180 + s5i + s9i;
		r244 = s9r - r180 - s6r;
		i244 = s9i - i180 - s6i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		valueT s11r, s11i;
		s1r = r72 + r76;
		s1i = i72 + i76;
		s2r = r76 + r74 - r72;
		s2i = i76 + i74 - i72;
		s3r = r72 + r74;
		s3i = i72 + i74;
		s4r = valueT(-1.4088116512993817275) * s1i;
		s4i = valueT(1.4088116512993817275) * s1r;
		s5r = valueT(0.44095855184409843175) * s2i;
		s5i = valueT(-0.44095855184409843175) * s2r;
		s6r = s1r + s3r;
		s6i = s1i + s3i;
		s7r = valueT(-1.2157152215855879292) * s3i;
		s7i = valueT(1.2157152215855879292) * s3r;
		s8r = valueT(0.87484229096165655223) * s6i;
		s8i = valueT(-0.87484229096165655223) * s6r;
		s9r = s4r + s8r;
		s9i = s4i + s8i;
		s10r = s7r + s8r;
		s10i = s7i + s8i;
		r240 = s9r - s5r;
		i240 = s9i - s5i;
		r238 = s5r - s10r;
		i238 = s5i - s10i;
		s11r = s5r + s9r + s10r;
		s11i = s5i + s9i + s10i;
		r272 = r244 - s11r;
		i272 = i244 - s11i;
		r264 = r244 + s11r;
		i264 = i244 + s11i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		valueT s11r, s11i, s12r, s12i, s13r, s13i, s14r, s14i, s15r, s15i;
		valueT s16r, s16i, s17r, s17i, s18r, s18i, s19r, s19i, s20r, s20i;
		valueT s21r, s21i, s22r, s22i, s23r, s23i, s24r, s24i;
		s1r = r49 - r51;
		s1i = i49 - i51;
		s2r = r47 - r53;
		s2i = i47 - i53;
		s3r = r45 - r55;
		s3i = i45 - i55;
		s4r = s1r + s2r;
		s4i = s1i + s2i;
		s5r = r81 - r79;
		s5i = i81 - i79;
		s6r = s2r + s3r - s1r;
		s6i = s2i + s3i - s1i;
		s7r = s1r + s3r;
		s7i = s1i + s3i;
		s8r = r79 - r83;
		s8i = i79 - i83;
		s9r = r83 - r81;
		s9i = i83 - i81;
		s10r = valueT(1.2157152215855879292) * s4i;
		s10i = valueT(-1.2157152215855879292) * s4r;
		s11r = valueT(0.055854267289647737622) * s5r;
		s11i = valueT(0.055854267289647737622) * s5i;
		s12r = valueT(-0.44095855184409843175) * s6i;
		s12i = valueT(0.44095855184409843175) * s6r;
		s13r = -s4r - s7r;
		s13i = -s4i - s7i;
		s14r = valueT(1.4088116512993817275) * s7i;
		s14i = valueT(-1.4088116512993817275) * s7r;
		s15r = valueT(0.79015646852540019719) * s8r;
		s15i = valueT(0.79015646852540019719) * s8i;
		s16r = valueT(-1.1666666666666666667) * r107;
		s16i = valueT(-1.1666666666666666667) * i107;
		s17r = valueT(-0.73430220123575245957) * s9r;
		s17i = valueT(-0.73430220123575245957) * s9i;
		s18r = valueT(0.87484229096165655223) * s13i;
		s18i = valueT(-0.87484229096165655223) * s13r;
		s19r = r131 + s16r;
		s19i = i131 + s16i;
		s20r = s10r + s18r;
		s20i = s10i + s18i;
		s21r = s14r + s18r;
		s21i = s14i + s18i;
		s22r = s19r - s11r - s15r;
		s22i = s19i - s11i - s15i;
		r245 = s11r + s17r + s19r;
		i245 = s11i + s17i + s19i;
		r243 = s15r + s19r - s17r;
		i243 = s15i + s19i - s17i;
		r239 = s20r - s12r;
		i239 = s20i - s12i;
		r237 = s12r - s21r;
		i237 = s12i - s21i;
		s23r = s12r + s20r + s21r;
		s23i = s12i + s20i + s21i;
		r262 = s22r - s23r;
		i262 = s22i - s23i;
		s24r = s22r + s23r;
		s24i = s22i + s23i;
		pReal[2 * stride] = s24r - r264;
		pImag[2 * stride] = s24i - i264;
		pReal[16 * stride] = r264 + s24r;
		pImag[16 * stride] = i264 + s24i;
	}
	pReal[26 * stride] = r262 - r272;
	pImag[26 * stride] = i262 - i272;
	pReal[12 * stride] = r272 + r262;
	pImag[12 * stride] = i272 + i262;
	r271 = r243 - r237;
	i271 = i243 - i237;
	r265 = r243 + r237;
	i265 = i243 + i237;
	{
		valueT s1r, s1i;
		s1r = r248 - r240;
		s1i = i248 - i240;
		r268 = r248 + r240;
		i268 = i248 + i240;
		pReal[18 * stride] = r265 - s1r;
		pImag[18 * stride] = i265 - s1i;
		pReal[4 * stride] = r265 + s1r;
		pImag[4 * stride] = i265 + s1i;
	}
	pReal[10 * stride] = r271 - r268;
	pImag[10 * stride] = i271 - i268;
	pReal[24 * stride] = r271 + r268;
	pImag[24 * stride] = i271 + i268;
	r273 = r245 - r239;
	i273 = i245 - i239;
	r267 = r245 + r239;
	i267 = i245 + i239;
	{
		valueT s1r, s1i;
		s1r = r246 - r238;
		s1i = i246 - i238;
		r266 = r246 + r238;
		i266 = i246 + i238;
		pReal[6 * stride] = r267 - s1r;
		pImag[6 * stride] = i267 - s1i;
		pReal[20 * stride] = r267 + s1r;
		pImag[20 * stride] = i267 + s1i;
	}
	pReal[22 * stride] = r273 - r266;
	pImag[22 * stride] = i273 - i266;
	pReal[8 * stride] = r273 + r266;
	pImag[8 * stride] = i273 + i266;
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i;
		r62 = r34 - r38;
		i62 = i34 - i38;
		s1r = r34 + r38;
		s1i = i34 + i38;
		r60 = r32 - r40;
		i60 = i32 - i40;
		s2r = r32 + r40;
		s2i = i32 + i40;
		r58 = r30 - r42;
		i58 = i30 - i42;
		s3r = r42 + r30;
		s3i = i42 + i30;
		r96 = s1r + s2r;
		i96 = s1i + s2i;
		s4r = s1r + s3r - s2r;
		s4i = s1i + s3i - s2i;
		r113 = s1r - s3r;
		i113 = s1i - s3i;
		r98 = s2r + s3r;
		i98 = s2i + s3i;
		r124 = r36 - s4r;
		i124 = i36 - s4i;
		r162 = valueT(-1.1666666666666666667) * s4i;
		i162 = valueT(1.1666666666666666667) * s4r;
	}
	{
		valueT s1r, s1i;
		s1r = r1 - r15;
		s1i = i1 - i15;
		r31 = r3 - r17;
		i31 = i3 - i17;
		r33 = r5 - r19;
		i33 = i5 - i19;
		r35 = r7 - r21;
		i35 = i7 - i21;
		r37 = r9 - r23;
		i37 = i9 - i23;
		r39 = r11 - r25;
		i39 = i11 - i25;
		r41 = r13 - r27;
		i41 = i13 - i27;
		r63 = r35 - r37;
		i63 = i35 - i37;
		r61 = r33 - r39;
		i61 = i33 - i39;
		r59 = r31 - r41;
		i59 = i31 - i41;
		r89 = r61 - r63 - r59;
		i89 = i61 - i63 - i59;
		r117 = s1r + r89;
		i117 = s1i + i89;
		pReal[7 * stride] = i124 + r117;
		pImag[7 * stride] = i117 - r124;
		pReal[21 * stride] = r117 - i124;
		pImag[21 * stride] = r124 + i117;
		r198 = r162 - i124;
		i198 = r124 + i162;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i;
		s1r = valueT(-0.73430220123575245957) * i96;
		s1i = valueT(0.73430220123575245957) * r96;
		s2r = valueT(-0.79015646852540019719) * i113;
		s2i = valueT(0.79015646852540019719) * r113;
		s3r = valueT(-0.055854267289647737622) * i98;
		s3i = valueT(0.055854267289647737622) * r98;
		r247 = r198 + s2r - s1r;
		i247 = i198 + s2i - s1i;
		r232 = r198 + s1r + s3r;
		i232 = i198 + s1i + s3i;
		r230 = r198 - s2r - s3r;
		i230 = i198 - s2i - s3i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		valueT s11r, s11i;
		s1r = r60 + r58 - r62;
		s1i = i60 + i58 - i62;
		s2r = r62 + r58;
		s2i = i62 + i58;
		s3r = r58 - r60;
		s3i = i58 - i60;
		s4r = valueT(0.44095855184409843175) * s1r;
		s4i = valueT(0.44095855184409843175) * s1i;
		s5r = valueT(1.4088116512993817275) * s2r;
		s5i = valueT(1.4088116512993817275) * s2i;
		s6r = -s2r - s3r;
		s6i = -s2i - s3i;
		s7r = valueT(1.2157152215855879292) * s3r;
		s7i = valueT(1.2157152215855879292) * s3i;
		s8r = valueT(0.87484229096165655223) * s6r;
		s8i = valueT(0.87484229096165655223) * s6i;
		s9r = s5r + s8r;
		s9i = s5i + s8i;
		s10r = s7r + s8r;
		s10i = s7i + s8i;
		r226 = s9r - s4r;
		i226 = s9i - s4i;
		r224 = s4r - s10r;
		i224 = s4i - s10i;
		s11r = s4r + s9r + s10r;
		s11i = s4i + s9i + s10i;
		r258 = r230 - s11r;
		i258 = i230 - s11i;
		r250 = r230 + s11r;
		i250 = i230 + s11i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		valueT s11r, s11i, s12r, s12i, s13r, s13i, s14r, s14i, s15r, s15i;
		valueT s16r, s16i, s17r, s17i, s18r, s18i, s19r, s19i, s20r, s20i;
		valueT s21r, s21i, s22r, s22i, s23r, s23i, s24r, s24i;
		s1r = r35 + r37;
		s1i = i35 + i37;
		s2r = r33 + r39;
		s2i = i33 + i39;
		s3r = r31 + r41;
		s3i = i31 + i41;
		s4r = -r63 - r61;
		s4i = -i63 - i61;
		s5r = s2r - s1r;
		s5i = s2i - s1i;
		s6r = r63 - r59;
		s6i = i63 - i59;
		s7r = r61 + r59;
		s7i = i61 + i59;
		s8r = s1r + s3r;
		s8i = s1i + s3i;
		s9r = s1r + s2r - s3r;
		s9i = s1i + s2i - s3i;
		s10r = valueT(-0.055854267289647737622) * s4r;
		s10i = valueT(-0.055854267289647737622) * s4i;
		s11r = valueT(1.2157152215855879292) * s5i;
		s11i = valueT(-1.2157152215855879292) * s5r;
		s12r = valueT(-1.1666666666666666667) * r89;
		s12i = valueT(-1.1666666666666666667) * i89;
		s13r = valueT(-0.79015646852540019719) * s6r;
		s13i = valueT(-0.79015646852540019719) * s6i;
		s14r = valueT(0.73430220123575245957) * s7r;
		s14i = valueT(0.73430220123575245957) * s7i;
		s15r = s8r - s5r;
		s15i = s8i - s5i;
		s16r = valueT(-1.4088116512993817275) * s8i;
		s16i = valueT(1.4088116512993817275) * s8r;
		s17r = valueT(-0.44095855184409843175) * s9i;
		s17i = valueT(0.44095855184409843175) * s9r;
		s18r = r117 + s12r;
		s18i = i117 + s12i;
		s19r = valueT(0.87484229096165655223) * s15i;
		s19i = valueT(-0.87484229096165655223) * s15r;
		r225 = s10r + s14r + s18r;
		i225 = s10i + s14i + s18i;
		s20r = s10r + s13r - s18r;
		s20i = s10i + s13i - s18i;
		r223 = s14r - s13r - s18r;
		i223 = s14i - s13i - s18i;
		s21r = s11r + s19r;
		s21i = s11i + s19i;
		s22r = s16r + s19r;
		s22i = s16i + s19i;
		r231 = s21r - s17r;
		i231 = s21i - s17i;
		r229 = s17r - s22r;
		i229 = s17i - s22i;
		s23r = s17r + s21r + s22r;
		s23i = s17i + s21i + s22i;
		s24r = s23r - s20r;
		s24i = s23i - s20i;
		r255 = s20r + s23r;
		i255 = s20i + s23i;
		pReal[23 * stride] = s24r - r250;
		pImag[23 * stride] = s24i - i250;
		pReal[9 * stride] = r250 + s24r;
		pImag[9 * stride] = i250 + s24i;
	}
	pReal[19 * stride] = -r258 - r255;
	pImag[19 * stride] = -i258 - i255;
	pReal[5 * stride] = r258 - r255;
	pImag[5 * stride] = i258 - i255;
	r251 = r223 - r229;
	i251 = i223 - i229;
	r257 = r223 + r229;
	i257 = i223 + i229;
	{
		valueT s1r, s1i;
		r275 = r247 - r226;
		i275 = i247 - i226;
		s1r = r247 + r226;
		s1i = i247 + i226;
		pReal[3 * stride] = -r257 - s1r;
		pImag[3 * stride] = -i257 - s1i;
		pReal[17 * stride] = s1r - r257;
		pImag[17 * stride] = s1i - i257;
	}
	pReal[11 * stride] = -r251 - r275;
	pImag[11 * stride] = -i251 - i275;
	pReal[25 * stride] = r275 - r251;
	pImag[25 * stride] = i275 - i251;
	r259 = r231 - r225;
	i259 = i231 - i225;
	r253 = r225 + r231;
	i253 = i225 + i231;
	{
		valueT s1r, s1i;
		s1r = r232 - r224;
		s1i = i232 - i224;
		r252 = r232 + r224;
		i252 = i232 + i224;
		pReal[27 * stride] = r253 - s1r;
		pImag[27 * stride] = i253 - s1i;
		pReal[13 * stride] = r253 + s1r;
		pImag[13 * stride] = i253 + s1i;
	}
	pReal[15 * stride] = -r259 - r252;
	pImag[15 * stride] = -i259 - i252;
	pReal[1 * stride] = r252 - r259;
	pImag[1 * stride] = i252 - i259;
}

template<> void StandardModule<float, 28>::Compute(float *pReal, float *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

template<> void StandardModule<double, 28>::Compute(double *pReal, double *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

}
}
