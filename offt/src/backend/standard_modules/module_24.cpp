
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

template<> StandardModuleComplexity const StandardModule<float, 24>::Complexity = { 0, 0 };
template<> StandardModuleComplexity const StandardModule<double, 24>::Complexity = { 0, 0 };

template<typename valueT>
static void ComputeCore(Phasors<valueT> const &phasors, valueT *pReal, valueT *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement)
{
	valueT r24, i24, r32, i32, r48, i48, r36, i36, r52, i52;
	valueT r64, i64, r116, i116, r120, i120, r144, i144, r2, i2;
	valueT r6, i6, r14, i14, r18, i18, r38, i38, r42, i42;
	valueT r70, i70, r58, i58, r118, i118, r100, i100, r208, i208;
	valueT r214, i214, r168, i168, r104, i104, r180, i180, r192, i192;
	valueT r98, i98, r110, i110, r174, i174, r210, i210, r216, i216;
	valueT r81, i81, r89, i89, r75, i75, r83, i83, r73, i73;
	valueT r101, i101, r79, i79, r117, i117, r109, i109, r183, i183;
	valueT r198, i198, r189, i189, r103, i103, r97, i97, r113, i113;
	valueT r158, i158, r155, i155, r164, i164, r202, i202, r161, i161;
	valueT r99, i99, r177, i177, r185, i185, r170, i170, r176, i176;
	valueT r206, i206, r171, i171, r200, i200;

	phasors.Multiply(r24, i24, pReal[23 * stride], pImag[23 * stride], twiddleStart + 23 * twiddleIncrement);
	{
		valueT s1r, s1i;
		phasors.Multiply(s1r, s1i, pReal[7 * stride], pImag[7 * stride], twiddleStart + 7 * twiddleIncrement);
		r32 = s1r - r24;
		i32 = s1i - i24;
		r48 = r24 + s1r;
		i48 = i24 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		phasors.Multiply(s1r, s1i, pReal[3 * stride], pImag[3 * stride], twiddleStart + 3 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[11 * stride], pImag[11 * stride], twiddleStart + 11 * twiddleIncrement);
		phasors.Multiply(s3r, s3i, pReal[15 * stride], pImag[15 * stride], twiddleStart + 15 * twiddleIncrement);
		phasors.Multiply(s4r, s4i, pReal[19 * stride], pImag[19 * stride], twiddleStart + 19 * twiddleIncrement);
		r36 = s2r - s4r;
		i36 = s2i - s4i;
		s5r = s2r + s4r;
		s5i = s2i + s4i;
		r52 = s1r + s5r;
		i52 = s1i + s5i;
		r64 = r48 + s3r;
		i64 = i48 + s3i;
		r116 = s5r - r48;
		i116 = s5i - i48;
		r120 = r48 + s5r;
		i120 = i48 + s5i;
	}
	r144 = valueT(-1.5) * r120;
	i144 = valueT(-1.5) * i120;
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i;
		phasors.Multiply(r2, i2, pReal[1 * stride], pImag[1 * stride], twiddleStart + 1 * twiddleIncrement);
		phasors.Multiply(r6, i6, pReal[5 * stride], pImag[5 * stride], twiddleStart + 5 * twiddleIncrement);
		phasors.Multiply(s1r, s1i, pReal[9 * stride], pImag[9 * stride], twiddleStart + 9 * twiddleIncrement);
		phasors.Multiply(r14, i14, pReal[13 * stride], pImag[13 * stride], twiddleStart + 13 * twiddleIncrement);
		phasors.Multiply(r18, i18, pReal[17 * stride], pImag[17 * stride], twiddleStart + 17 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[21 * stride], pImag[21 * stride], twiddleStart + 21 * twiddleIncrement);
		r38 = r6 + r14;
		i38 = i6 + i14;
		r42 = r2 + r18;
		i42 = i2 + i18;
		r70 = s2r + r38;
		i70 = s2i + i38;
		r58 = s1r + r42;
		i58 = s1i + i42;
		r118 = r70 + r58;
		i118 = i70 + i58;
		r100 = r52 - r64;
		i100 = i52 - i64;
		s3r = r52 + r64;
		s3i = i52 + i64;
		r208 = s3r - r118;
		i208 = s3i - i118;
		r214 = r118 + s3r;
		i214 = i118 + s3i;
		r168 = r144 + s3r;
		i168 = i144 + s3i;
	}
	{
		valueT s1r, s1i, s2r, s2i;
		s1r = r36 - r32;
		s1i = i36 - i32;
		r104 = r32 + r36;
		i104 = i32 + i36;
		s2r = valueT(-0.86602540378443864676) * s1i;
		s2i = valueT(0.86602540378443864676) * s1r;
		r180 = s2r - r168;
		i180 = s2i - i168;
		r192 = r168 + s2r;
		i192 = i168 + s2i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i;
		s1r = r6 - r14;
		s1i = i6 - i14;
		s2r = r2 - r18;
		s2i = i2 - i18;
		s3r = s1r - s2r;
		s3i = s1i - s2i;
		r98 = s1r + s2r;
		i98 = s1i + s2i;
		r110 = r38 - r42;
		i110 = i38 - i42;
		s4r = r38 + r42;
		s4i = i38 + i42;
		s5r = valueT(-0.86602540378443864676) * s3i;
		s5i = valueT(0.86602540378443864676) * s3r;
		s6r = valueT(-1.5) * s4r;
		s6i = valueT(-1.5) * s4i;
		s7r = r118 + s6r;
		s7i = i118 + s6i;
		r174 = s5r - s7r;
		i174 = s5i - s7i;
		s8r = s5r + s7r;
		s8i = s5i + s7i;
		r210 = s8r - r192;
		i210 = s8i - i192;
		r216 = r192 + s8r;
		i216 = i192 + s8i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		valueT s11r, s11i, s12r, s12i, s13r, s13i, s14r, s14i, s15r, s15i;
		valueT s16r, s16i, s17r, s17i, s18r, s18i, s19r, s19i, s20r, s20i;
		valueT s21r, s21i, s22r, s22i, s23r, s23i, s24r, s24i, s25r, s25i;
		valueT s26r, s26i, s27r, s27i, s28r, s28i, s29r, s29i, s30r, s30i;
		valueT s31r, s31i, s32r, s32i, s33r, s33i, s34r, s34i, s35r, s35i;
		valueT s36r, s36i, s37r, s37i;
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
		s13r = s2r - s6r;
		s13i = s2i - s6i;
		s14r = s2r + s6r;
		s14i = s2i + s6i;
		s15r = s5r - s9r;
		s15i = s5i - s9i;
		s16r = s5r + s9r;
		s16i = s5i + s9i;
		s17r = s3r - s11r;
		s17i = s3i - s11i;
		s18r = s3r + s11r;
		s18i = s3i + s11i;
		s19r = s8r - s12r;
		s19i = s8i - s12i;
		s20r = s8r + s12r;
		s20i = s8i + s12i;
		s21r = s10r + s14r;
		s21i = s10i + s14i;
		s22r = s1r + s16r;
		s22i = s1i + s16i;
		s23r = s17r - s15r;
		s23i = s17i - s15i;
		r81 = s15r + s17r;
		i81 = s15i + s17i;
		s24r = s7r + s18r;
		s24i = s7i + s18i;
		r89 = s16r - s18r;
		i89 = s16i - s18i;
		s25r = s16r + s18r;
		s25i = s16i + s18i;
		r75 = s13r - s19r;
		i75 = s13i - s19i;
		s26r = s13r + s19r;
		s26i = s13i + s19i;
		s27r = s4r + s20r;
		s27i = s4i + s20i;
		r83 = s14r - s20r;
		i83 = s14i - s20i;
		s28r = s14r + s20r;
		s28i = s14i + s20i;
		r73 = s22r - s24r;
		i73 = s22i - s24i;
		s29r = s22r + s24r;
		s29i = s22i + s24i;
		s30r = s26r - s23r;
		s30i = s26i - s23i;
		r101 = s23r + s26r;
		i101 = s23i + s26i;
		r79 = s27r - s21r;
		i79 = s27i - s21i;
		s31r = s21r + s27r;
		s31i = s21i + s27i;
		r117 = s25r - s28r;
		i117 = s25i - s28i;
		s32r = s25r + s28r;
		s32i = s25i + s28i;
		s33r = valueT(-0.86602540378443864676) * s30i;
		s33i = valueT(0.86602540378443864676) * s30r;
		r109 = s29r - s31r;
		i109 = s29i - s31i;
		s34r = s29r + s31r;
		s34i = s29i + s31i;
		s35r = valueT(-1.5) * s32r;
		s35i = valueT(-1.5) * s32i;
		s36r = s34r + s35r;
		s36i = s34i + s35i;
		pReal[12 * stride] = s34r - r214;
		pImag[12 * stride] = s34i - i214;
		pReal[0 * stride] = r214 + s34r;
		pImag[0 * stride] = i214 + s34i;
		r183 = s33r - s36r;
		i183 = s33i - s36i;
		s37r = s33r + s36r;
		s37i = s33i + s36i;
		pReal[4 * stride] = s37r - r216;
		pImag[4 * stride] = s37i - i216;
		pReal[16 * stride] = r216 + s37r;
		pImag[16 * stride] = i216 + s37i;
	}
	{
		valueT s1r, s1i;
		r198 = r174 - r180;
		i198 = i174 - i180;
		s1r = r180 + r174;
		s1i = i180 + i174;
		pReal[8 * stride] = -r183 - s1r;
		pImag[8 * stride] = -i183 - s1i;
		pReal[20 * stride] = s1r - r183;
		pImag[20 * stride] = s1i - i183;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i;
		s1r = valueT(0.86602540378443864676) * i101;
		s1i = valueT(-0.86602540378443864676) * r101;
		s2r = valueT(-1.5) * r117;
		s2i = valueT(-1.5) * i117;
		s3r = r109 + s2r;
		s3i = i109 + s2i;
		pReal[6 * stride] = i208 + r109;
		pImag[6 * stride] = i109 - r208;
		pReal[18 * stride] = r109 - i208;
		pImag[18 * stride] = r208 + i109;
		s4r = s1r - s3r;
		s4i = s1i - s3i;
		r189 = s1r + s3r;
		i189 = s1i + s3i;
		pReal[14 * stride] = i198 - s4r;
		pImag[14 * stride] = -r198 - s4i;
		pReal[2 * stride] = -i198 - s4r;
		pImag[2 * stride] = r198 - s4i;
	}
	pReal[10 * stride] = i210 + r189;
	pImag[10 * stride] = i189 - r210;
	pReal[22 * stride] = r189 - i210;
	pImag[22 * stride] = r210 + i189;
	r103 = i73 + r79;
	i103 = i79 - r73;
	r97 = r73 + i79;
	i97 = i73 - r79;
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i;
		s1r = r58 - r70;
		s1i = i58 - i70;
		s2r = valueT(-1.0606601717798212866) * r110 - valueT(1.0606601717798212866) * i110;
		s2i = valueT(1.0606601717798212866) * r110 - valueT(1.0606601717798212866) * i110;
		s3r = i89 + r83;
		s3i = i83 - r89;
		r113 = r89 + i83;
		i113 = i89 - r83;
		s4r = valueT(1.0606601717798212866) * i116 - valueT(1.0606601717798212866) * r116;
		s4i = valueT(-1.0606601717798212866) * r116 - valueT(1.0606601717798212866) * i116;
		s5r = valueT(-0.7071067811865475244) * s1r - valueT(0.7071067811865475244) * s1i;
		s5i = valueT(0.7071067811865475244) * s1r - valueT(0.7071067811865475244) * s1i;
		s6r = valueT(1.5) * s3i;
		s6i = valueT(-1.5) * s3r;
		s7r = valueT(0.7071067811865475244) * r100 - valueT(0.7071067811865475244) * i100;
		s7i = valueT(0.7071067811865475244) * r100 + valueT(0.7071067811865475244) * i100;
		r158 = s2r + s5r;
		i158 = s2i + s5i;
		r155 = r97 + s6r;
		i155 = i97 + s6i;
		r164 = s4r + s7r;
		i164 = s4i + s7i;
		s8r = s7r - s5r;
		s8i = s7i - s5i;
		r202 = s5r + s7r;
		i202 = s5i + s7i;
		pReal[15 * stride] = r97 + s8i;
		pImag[15 * stride] = i97 - s8r;
		pReal[3 * stride] = r97 - s8i;
		pImag[3 * stride] = i97 + s8r;
	}
	{
		valueT s1r, s1i;
		s1r = valueT(-1.5) * r113;
		s1i = valueT(-1.5) * i113;
		r161 = s1r - i103;
		i161 = r103 + s1i;
		pReal[21 * stride] = -i103 - r202;
		pImag[21 * stride] = r103 - i202;
		pReal[9 * stride] = r202 - i103;
		pImag[9 * stride] = r103 + i202;
	}
	{
		valueT s1r, s1i, s2r, s2i;
		r99 = i81 + r75;
		i99 = i75 - r81;
		s1r = r81 + i75;
		s1i = i81 - r75;
		s2r = valueT(-0.86602540378443864676) * s1i;
		s2i = valueT(0.86602540378443864676) * s1r;
		r177 = s2r - r161;
		i177 = s2i - i161;
		r185 = r161 + s2r;
		i185 = i161 + s2i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		s1r = valueT(0.61237243569579452455) * r98 - valueT(0.61237243569579452455) * i98;
		s1i = valueT(0.61237243569579452455) * r98 + valueT(0.61237243569579452455) * i98;
		s2r = valueT(-0.61237243569579452455) * r104 - valueT(0.61237243569579452455) * i104;
		s2i = valueT(0.61237243569579452455) * r104 - valueT(0.61237243569579452455) * i104;
		r170 = s1r - r158;
		i170 = s1i - i158;
		s3r = r158 + s1r;
		s3i = i158 + s1i;
		r176 = s2r - r164;
		i176 = s2i - i164;
		s4r = r164 + s2r;
		s4i = i164 + s2i;
		r206 = s3r - s4r;
		i206 = s3i - s4i;
		s5r = s3r + s4r;
		s5i = s3i + s4i;
		pReal[13 * stride] = r185 - s5r;
		pImag[13 * stride] = i185 - s5i;
		pReal[1 * stride] = r185 + s5r;
		pImag[1 * stride] = i185 + s5i;
	}
	{
		valueT s1r, s1i, s2r, s2i;
		s1r = valueT(-0.86602540378443864676) * r99;
		s1i = valueT(-0.86602540378443864676) * i99;
		r171 = s1r - r155;
		i171 = s1i - i155;
		s2r = r155 + s1r;
		s2i = i155 + s1i;
		pReal[19 * stride] = i206 + s2r;
		pImag[19 * stride] = s2i - r206;
		pReal[7 * stride] = s2r - i206;
		pImag[7 * stride] = r206 + s2i;
	}
	{
		valueT s1r, s1i;
		s1r = r170 - r176;
		s1i = i170 - i176;
		r200 = r170 + r176;
		i200 = i170 + i176;
		pReal[23 * stride] = s1i - r171;
		pImag[23 * stride] = -i171 - s1r;
		pReal[11 * stride] = -r171 - s1i;
		pImag[11 * stride] = s1r - i171;
	}
	pReal[17 * stride] = -r177 - r200;
	pImag[17 * stride] = -i177 - i200;
	pReal[5 * stride] = r200 - r177;
	pImag[5 * stride] = i200 - i177;
}

template<> void StandardModule<float, 24>::Compute(float *pReal, float *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

template<> void StandardModule<double, 24>::Compute(double *pReal, double *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

}
}
