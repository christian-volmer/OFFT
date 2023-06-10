
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

template<> StandardModuleComplexity const StandardModule<float, 22>::Complexity = { 0, 0 };
template<> StandardModuleComplexity const StandardModule<double, 22>::Complexity = { 0, 0 };

template<typename valueT>
static void ComputeCore(Phasors<valueT> const &phasors, valueT *pReal, valueT *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement)
{
	valueT r22, i22, r24, i24, r44, i44, r32, i32, r30, i30;
	valueT r28, i28, r26, i26, r62, i62, r64, i64, r68, i68;
	valueT r58, i58, r60, i60, r67, i67, r66, i66, r139, i139;
	valueT r107, i107, r138, i138, r181, i181, r180, i180, r3, i3;
	valueT r5, i5, r7, i7, r9, i9, r11, i11, r13, i13;
	valueT r15, i15, r17, i17, r19, i19, r21, i21, r35, i35;
	valueT r37, i37, r39, i39, r41, i41, r43, i43, r57, i57;
	valueT r75, i75, r210, i210, r204, i204, r206, i206, r208, i208;
	valueT r202, i202, r198, i198, r196, i196, r194, i194, r192, i192;
	valueT r224, i224, r212, i212, r195, i195, r193, i193, r197, i197;
	valueT r191, i191, r207, i207, r205, i205, r201, i201, r203, i203;
	valueT r231, i231, r219, i219, r225, i225, r230, i230, r213, i213;
	valueT r223, i223, r220, i220, r227, i227, r217, i217, r228, i228;
	valueT r215, i215, r229, i229, r218, i218;

	phasors.Multiply(r22, i22, pReal[21 * stride], pImag[21 * stride], twiddleStart + 21 * twiddleIncrement);
	{
		valueT s1r, s1i;
		phasors.Multiply(s1r, s1i, pReal[1 * stride], pImag[1 * stride], twiddleStart + 1 * twiddleIncrement);
		r24 = s1r - r22;
		i24 = s1i - i22;
		r44 = r22 + s1r;
		i44 = i22 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		valueT s11r, s11i, s12r, s12i;
		phasors.Multiply(s1r, s1i, pReal[3 * stride], pImag[3 * stride], twiddleStart + 3 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[5 * stride], pImag[5 * stride], twiddleStart + 5 * twiddleIncrement);
		phasors.Multiply(s3r, s3i, pReal[7 * stride], pImag[7 * stride], twiddleStart + 7 * twiddleIncrement);
		phasors.Multiply(s4r, s4i, pReal[9 * stride], pImag[9 * stride], twiddleStart + 9 * twiddleIncrement);
		phasors.Multiply(s5r, s5i, pReal[13 * stride], pImag[13 * stride], twiddleStart + 13 * twiddleIncrement);
		phasors.Multiply(s6r, s6i, pReal[15 * stride], pImag[15 * stride], twiddleStart + 15 * twiddleIncrement);
		phasors.Multiply(s7r, s7i, pReal[17 * stride], pImag[17 * stride], twiddleStart + 17 * twiddleIncrement);
		phasors.Multiply(s8r, s8i, pReal[19 * stride], pImag[19 * stride], twiddleStart + 19 * twiddleIncrement);
		r32 = s4r - s5r;
		i32 = s4i - s5i;
		s9r = s4r + s5r;
		s9i = s4i + s5i;
		r30 = s3r - s6r;
		i30 = s3i - s6i;
		s10r = s3r + s6r;
		s10i = s3i + s6i;
		r28 = s2r - s7r;
		i28 = s2i - s7i;
		s11r = s2r + s7r;
		s11i = s2i + s7i;
		r26 = s1r - s8r;
		i26 = s1i - s8i;
		s12r = s1r + s8r;
		s12i = s1i + s8i;
		r62 = s11r - s10r;
		i62 = s11i - s10i;
		r64 = s12r - s9r;
		i64 = s12i - s9i;
		r68 = s9r - r44;
		i68 = s9i - i44;
		r58 = r44 + s9r + s10r + s11r + s12r;
		i58 = i44 + s9i + s10i + s11i + s12i;
		r60 = s10r - r44;
		i60 = s10i - i44;
		r67 = s11r - r44;
		i67 = s11i - i44;
		r66 = r44 - s12r;
		i66 = i44 - s12i;
	}
	r139 = valueT(0.55486073394528506406) * r67;
	i139 = valueT(0.55486073394528506406) * i67;
	r107 = -r67 - r66;
	i107 = -i67 - i66;
	r138 = valueT(0.51541501300188642553) * r66;
	i138 = valueT(0.51541501300188642553) * i66;
	{
		valueT s1r, s1i;
		s1r = valueT(-0.89893869455789602842) * r107;
		s1i = valueT(-0.89893869455789602842) * i107;
		r181 = r139 - s1r;
		i181 = i139 - s1i;
		r180 = r138 + s1r;
		i180 = i138 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		valueT s11r, s11i, s12r, s12i, s13r, s13i, s14r, s14i, s15r, s15i;
		valueT s16r, s16i, s17r, s17i;
		phasors.Multiply(s1r, s1i, pReal[0 * stride], pImag[0 * stride], twiddleStart + 0 * twiddleIncrement);
		phasors.Multiply(r3, i3, pReal[2 * stride], pImag[2 * stride], twiddleStart + 2 * twiddleIncrement);
		phasors.Multiply(r5, i5, pReal[4 * stride], pImag[4 * stride], twiddleStart + 4 * twiddleIncrement);
		phasors.Multiply(r7, i7, pReal[6 * stride], pImag[6 * stride], twiddleStart + 6 * twiddleIncrement);
		phasors.Multiply(r9, i9, pReal[8 * stride], pImag[8 * stride], twiddleStart + 8 * twiddleIncrement);
		phasors.Multiply(r11, i11, pReal[10 * stride], pImag[10 * stride], twiddleStart + 10 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[11 * stride], pImag[11 * stride], twiddleStart + 11 * twiddleIncrement);
		phasors.Multiply(r13, i13, pReal[12 * stride], pImag[12 * stride], twiddleStart + 12 * twiddleIncrement);
		phasors.Multiply(r15, i15, pReal[14 * stride], pImag[14 * stride], twiddleStart + 14 * twiddleIncrement);
		phasors.Multiply(r17, i17, pReal[16 * stride], pImag[16 * stride], twiddleStart + 16 * twiddleIncrement);
		phasors.Multiply(r19, i19, pReal[18 * stride], pImag[18 * stride], twiddleStart + 18 * twiddleIncrement);
		phasors.Multiply(r21, i21, pReal[20 * stride], pImag[20 * stride], twiddleStart + 20 * twiddleIncrement);
		r35 = r11 + r13;
		i35 = i11 + i13;
		r37 = r9 + r15;
		i37 = i9 + i15;
		r39 = r7 + r17;
		i39 = i7 + i17;
		r41 = r5 + r19;
		i41 = i5 + i19;
		r43 = r3 + r21;
		i43 = i3 + i21;
		r57 = r35 + r37 + r39 + r41 + r43;
		i57 = i35 + i37 + i39 + i41 + i43;
		s3r = valueT(-0.90180781188778253033) * r62;
		s3i = valueT(-0.90180781188778253033) * i62;
		s4r = r62 - r64;
		s4i = i62 - i64;
		s5r = valueT(-0.5971755722185702045) * r64;
		s5i = valueT(-0.5971755722185702045) * i64;
		r75 = s1r + r57;
		i75 = s1i + i57;
		s6r = valueT(0.85949297361449738989) * r68;
		s6i = valueT(0.85949297361449738989) * i68;
		s7r = r58 + s2r;
		s7i = i58 + s2i;
		s8r = valueT(-1.1) * r58;
		s8i = valueT(-1.1) * i58;
		s9r = r68 - r60;
		s9i = i68 - i60;
		s10r = valueT(-0.94125353283118116886) * r60;
		s10i = valueT(-0.94125353283118116886) * i60;
		s11r = valueT(-0.042314838273285140444) * s4r;
		s11i = valueT(-0.042314838273285140444) * s4i;
		pReal[11 * stride] = r75 - s7r;
		pImag[11 * stride] = i75 - s7i;
		pReal[0 * stride] = r75 + s7r;
		pImag[0 * stride] = i75 + s7i;
		s12r = s7r + s8r;
		s12i = s7i + s8i;
		s13r = valueT(-0.47310017472860128509) * s9r;
		s13i = valueT(-0.47310017472860128509) * s9i;
		s14r = s3r - s11r;
		s14i = s3i - s11i;
		s15r = s5r + s11r;
		s15i = s5i + s11i;
		s16r = s6r + s13r;
		s16i = s6i + s13i;
		s17r = s10r - s13r;
		s17i = s10i - s13i;
		r210 = s12r + s15r + s16r;
		i210 = s12i + s15i + s16i;
		r204 = s12r + s14r + s17r;
		i204 = s12i + s14i + s17i;
		r206 = s14r - r181 - s12r;
		i206 = s14i - i181 - s12i;
		r208 = s15r - r180 - s12r;
		i208 = s15i - i180 - s12i;
		r202 = s12r - r181 - r180 - s16r - s17r;
		i202 = s12i - i181 - i180 - s16i - s17i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		valueT s11r, s11i, s12r, s12i, s13r, s13i, s14r, s14i, s15r, s15i;
		valueT s16r, s16i, s17r, s17i, s18r, s18i, s19r, s19i, s20r, s20i;
		valueT s21r, s21i, s22r, s22i, s23r, s23i, s24r, s24i, s25r, s25i;
		valueT s26r, s26i, s27r, s27i;
		s1r = r30 + r28;
		s1i = i30 + i28;
		s2r = r26 - r32;
		s2i = i26 - i32;
		s3r = r24 + r32 + r28 + r26 - r30;
		s3i = i24 + i32 + i28 + i26 - i30;
		s4r = r32 - r24;
		s4i = i32 - i24;
		s5r = r24 + r30;
		s5i = i24 + i30;
		s6r = r28 - r24;
		s6i = i28 - i24;
		s7r = r24 - r26;
		s7i = i24 - i26;
		s8r = valueT(-0.70808888503950303466) * s1i;
		s8i = valueT(0.70808888503950303466) * s1r;
		s9r = -s1r - s2r;
		s9i = -s1i - s2i;
		s10r = valueT(0.2340718675266744486) * s2i;
		s10i = valueT(-0.2340718675266744486) * s2r;
		s11r = valueT(0.33166247903553998491) * s3i;
		s11i = valueT(-0.33166247903553998491) * s3r;
		s12r = valueT(-1.2162009452834415049) * s4i;
		s12i = valueT(1.2162009452834415049) * s4r;
		s13r = s4r - s5r;
		s13i = s4i - s5i;
		s14r = valueT(0.95729268466927362052) * s5i;
		s14i = valueT(-0.95729268466927362052) * s5r;
		s15r = valueT(2.1583616978496189882) * s6i;
		s15i = valueT(-2.1583616978496189882) * s6r;
		s16r = s6r - s7r;
		s16i = s6i - s7i;
		s17r = valueT(-0.492980128140842333) * s7i;
		s17i = valueT(0.492980128140842333) * s7r;
		s18r = valueT(0.65815896284539274746) * s9i;
		s18i = valueT(-0.65815896284539274746) * s9r;
		s19r = valueT(0.58313551154466560886) * s13i;
		s19i = valueT(-0.58313551154466560886) * s13r;
		s20r = valueT(-0.86713730126545034466) * s16i;
		s20i = valueT(0.86713730126545034466) * s16r;
		s21r = s8r - s18r;
		s21i = s8i - s18i;
		s22r = s10r + s18r;
		s22i = s10i + s18i;
		s23r = s12r + s19r;
		s23i = s12i + s19i;
		s24r = s14r + s19r;
		s24i = s14i + s19i;
		s25r = s15r + s20r;
		s25i = s15i + s20i;
		s26r = s17r + s20r;
		s26i = s17i + s20i;
		r198 = s22r + s23r - s11r;
		i198 = s22i + s23i - s11i;
		r196 = s24r - s11r - s21r;
		i196 = s24i - s11i - s21i;
		r194 = s21r + s25r - s11r;
		i194 = s21i + s25i - s11i;
		s27r = s11r + s23r + s24r + s25r + s26r;
		s27i = s11i + s23i + s24i + s25i + s26i;
		r192 = s11r + s22r - s26r;
		i192 = s11i + s22i - s26i;
		r224 = r202 - s27r;
		i224 = i202 - s27i;
		r212 = r202 + s27r;
		i212 = i202 + s27i;
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
		s1r = r11 - r13;
		s1i = i11 - i13;
		s2r = r9 - r15;
		s2i = i9 - i15;
		s3r = r7 - r17;
		s3i = i7 - i17;
		s4r = r5 - r19;
		s4i = i5 - i19;
		s5r = r3 - r21;
		s5i = i3 - i21;
		s6r = s2r - s1r;
		s6i = s2i - s1i;
		s7r = r37 - r35;
		s7i = i37 - i35;
		s8r = s3r - s1r;
		s8i = s3i - s1i;
		s9r = r39 - r35;
		s9i = i39 - i35;
		s10r = s1r + s4r;
		s10i = s1i + s4i;
		s11r = s3r + s4r;
		s11i = s3i + s4i;
		s12r = r35 - r41;
		s12i = i35 - i41;
		s13r = r41 - r39;
		s13i = i41 - i39;
		s14r = s1r - s5r;
		s14i = s1i - s5i;
		s15r = s1r + s2r + s3r + s5r - s4r;
		s15i = s1i + s2i + s3i + s5i - s4i;
		s16r = s2r - s5r;
		s16i = s2i - s5i;
		s17r = r35 - r43;
		s17i = i35 - i43;
		s18r = r43 - r37;
		s18i = i43 - i37;
		s19r = valueT(-0.492980128140842333) * s6i;
		s19i = valueT(0.492980128140842333) * s6r;
		s20r = valueT(-0.51541501300188642553) * s7r;
		s20i = valueT(-0.51541501300188642553) * s7i;
		s21r = -s6r - s8r;
		s21i = -s6i - s8i;
		s22r = valueT(-2.1583616978496189882) * s8i;
		s22i = valueT(2.1583616978496189882) * s8r;
		s23r = s7r - s9r;
		s23i = s7i - s9i;
		s24r = valueT(0.55486073394528506406) * s9r;
		s24i = valueT(0.55486073394528506406) * s9i;
		s25r = valueT(-0.95729268466927362052) * s10i;
		s25i = valueT(0.95729268466927362052) * s10r;
		s26r = valueT(0.70808888503950303466) * s11i;
		s26i = valueT(-0.70808888503950303466) * s11r;
		s27r = valueT(0.94125353283118116886) * s12r;
		s27i = valueT(0.94125353283118116886) * s12i;
		s28r = valueT(0.90180781188778253033) * s13r;
		s28i = valueT(0.90180781188778253033) * s13i;
		s29r = s10r + s14r;
		s29i = s10i + s14i;
		s30r = valueT(-1.2162009452834415049) * s14i;
		s30i = valueT(1.2162009452834415049) * s14r;
		s31r = valueT(-0.33166247903553998491) * s15i;
		s31i = valueT(0.33166247903553998491) * s15r;
		s32r = s11r + s16r;
		s32i = s11i + s16i;
		s33r = valueT(-0.2340718675266744486) * s16i;
		s33i = valueT(0.2340718675266744486) * s16r;
		s34r = s12r - s17r;
		s34i = s12i - s17i;
		s35r = valueT(-0.85949297361449738989) * s17r;
		s35i = valueT(-0.85949297361449738989) * s17i;
		s36r = valueT(-1.1) * r57;
		s36i = valueT(-1.1) * i57;
		s37r = s18r - s13r;
		s37i = s18i - s13i;
		s38r = valueT(0.5971755722185702045) * s18r;
		s38i = valueT(0.5971755722185702045) * s18i;
		s39r = valueT(-0.86713730126545034466) * s21i;
		s39i = valueT(0.86713730126545034466) * s21r;
		s40r = valueT(-0.89893869455789602842) * s23r;
		s40i = valueT(-0.89893869455789602842) * s23i;
		s41r = valueT(0.58313551154466560886) * s29i;
		s41i = valueT(-0.58313551154466560886) * s29r;
		s42r = valueT(0.65815896284539274746) * s32i;
		s42i = valueT(-0.65815896284539274746) * s32r;
		s43r = valueT(-0.47310017472860128509) * s34r;
		s43i = valueT(-0.47310017472860128509) * s34i;
		s44r = r75 + s36r;
		s44i = i75 + s36i;
		s45r = valueT(-0.042314838273285140444) * s37r;
		s45i = valueT(-0.042314838273285140444) * s37i;
		s46r = s19r + s39r;
		s46i = s19i + s39i;
		s47r = s22r + s39r;
		s47i = s22i + s39i;
		s48r = s20r + s40r;
		s48i = s20i + s40i;
		s49r = s24r - s40r;
		s49i = s24i - s40i;
		s50r = s25r + s41r;
		s50i = s25i + s41i;
		s51r = s30r + s41r;
		s51i = s30i + s41i;
		s52r = s26r - s42r;
		s52i = s26i - s42i;
		s53r = s33r + s42r;
		s53i = s33i + s42i;
		s54r = s27r - s43r;
		s54i = s27i - s43i;
		s55r = s35r + s43r;
		s55i = s35i + s43i;
		s56r = s28r - s45r;
		s56i = s28i - s45i;
		s57r = s38r + s45r;
		s57i = s38i + s45i;
		s58r = s31r + s46r + s47r + s50r + s51r;
		s58i = s31i + s46i + s47i + s50i + s51i;
		r195 = s47r + s52r - s31r;
		i195 = s47i + s52i - s31i;
		r193 = s31r + s52r - s50r;
		i193 = s31i + s52i - s50i;
		r197 = s31r + s53r - s46r;
		i197 = s31i + s53i - s46i;
		r191 = s31r - s51r - s53r;
		i191 = s31i - s51i - s53i;
		s59r = s48r + s49r + s54r + s55r - s44r;
		s59i = s48i + s49i + s54i + s55i - s44i;
		r207 = s44r + s54r + s56r;
		i207 = s44i + s54i + s56i;
		r205 = s44r + s49r - s56r;
		i205 = s44i + s49i - s56i;
		r201 = s44r + s55r + s57r;
		i201 = s44i + s55i + s57i;
		r203 = s44r + s48r - s57r;
		i203 = s44i + s48i - s57i;
		s60r = s58r - s59r;
		s60i = s58i - s59i;
		r231 = s58r + s59r;
		i231 = s58i + s59i;
		pReal[5 * stride] = s60r - r212;
		pImag[5 * stride] = s60i - i212;
		pReal[16 * stride] = r212 + s60r;
		pImag[16 * stride] = i212 + s60i;
	}
	pReal[17 * stride] = -r224 - r231;
	pImag[17 * stride] = -i224 - i231;
	pReal[6 * stride] = r224 - r231;
	pImag[6 * stride] = i224 - i231;
	r219 = r197 - r203;
	i219 = i197 - i203;
	r225 = r197 + r203;
	i225 = i197 + i203;
	{
		valueT s1r, s1i;
		s1r = r192 - r208;
		s1i = i192 - i208;
		r230 = r208 + r192;
		i230 = i208 + i192;
		pReal[15 * stride] = r225 - s1r;
		pImag[15 * stride] = i225 - s1i;
		pReal[4 * stride] = r225 + s1r;
		pImag[4 * stride] = i225 + s1i;
	}
	pReal[18 * stride] = -r219 - r230;
	pImag[18 * stride] = -i219 - i230;
	pReal[7 * stride] = r230 - r219;
	pImag[7 * stride] = i230 - i219;
	r213 = r191 - r201;
	i213 = i191 - i201;
	r223 = r191 + r201;
	i223 = i191 + i201;
	{
		valueT s1r, s1i;
		s1r = r210 - r198;
		s1i = i210 - i198;
		r220 = r210 + r198;
		i220 = i210 + i198;
		pReal[1 * stride] = r223 - s1r;
		pImag[1 * stride] = i223 - s1i;
		pReal[12 * stride] = r223 + s1r;
		pImag[12 * stride] = i223 + s1i;
	}
	pReal[21 * stride] = -r213 - r220;
	pImag[21 * stride] = -i213 - i220;
	pReal[10 * stride] = r220 - r213;
	pImag[10 * stride] = i220 - i213;
	r227 = r205 - r195;
	i227 = i205 - i195;
	r217 = r195 + r205;
	i217 = i195 + i205;
	{
		valueT s1r, s1i;
		s1r = r194 - r206;
		s1i = i194 - i206;
		r228 = r206 + r194;
		i228 = i206 + i194;
		pReal[19 * stride] = r217 - s1r;
		pImag[19 * stride] = i217 - s1i;
		pReal[8 * stride] = r217 + s1r;
		pImag[8 * stride] = i217 + s1i;
	}
	pReal[14 * stride] = r227 - r228;
	pImag[14 * stride] = i227 - i228;
	pReal[3 * stride] = r227 + r228;
	pImag[3 * stride] = i227 + i228;
	r215 = r193 - r207;
	i215 = i193 - i207;
	r229 = r193 + r207;
	i229 = i193 + i207;
	{
		valueT s1r, s1i;
		s1r = r204 - r196;
		s1i = i204 - i196;
		r218 = r204 + r196;
		i218 = i204 + i196;
		pReal[9 * stride] = r229 - s1r;
		pImag[9 * stride] = i229 - s1i;
		pReal[20 * stride] = r229 + s1r;
		pImag[20 * stride] = i229 + s1i;
	}
	pReal[13 * stride] = -r215 - r218;
	pImag[13 * stride] = -i215 - i218;
	pReal[2 * stride] = r218 - r215;
	pImag[2 * stride] = i218 - i215;
}

template<> void StandardModule<float, 22>::Compute(float *pReal, float *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

template<> void StandardModule<double, 22>::Compute(double *pReal, double *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

}
}
