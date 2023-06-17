
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

template<> StandardModuleComplexity const StandardModule<float, 18>::Complexity = { 0, 0 };
template<> StandardModuleComplexity const StandardModule<double, 18>::Complexity = { 0, 0 };

template<typename valueT>
static void ComputeCore(Phasors<valueT> const &phasors, valueT *pReal, valueT *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement)
{
	valueT r18, i18, r24, i24, r36, i36, r48, i48, r72, i72;
	valueT r2, i2, r8, i8, r26, i26, r50, i50, r138, i138;
	valueT r140, i140, r90, i90, r96, i96, r108, i108, r126, i126;
	valueT r92, i92, r134, i134, r144, i144, r94, i94, r154, i154;
	valueT r160, i160, r180, i180, r61, i61, r37, i37, r85, i85;
	valueT r129, i129, r131, i131, r99, i99, r101, i101, r141, i141;
	valueT r157, i157, r197, i197, r198, i198, r193, i193, r216, i216;
	valueT r188, i188, r119, i119, r135, i135, r137, i137, r151, i151;
	valueT r173, i173, r128, i128, r148, i148, r186, i186, r191, i191;
	valueT r184, i184, r209, i209, r182, i182, r145, i145, r167, i167;
	valueT r185, i185, r194, i194, r181, i181, r212, i212, r183, i183;

	phasors.Multiply(r18, i18, pReal[17 * stride], pImag[17 * stride], twiddleStart + 17 * twiddleIncrement);
	{
		valueT s1r, s1i;
		phasors.Multiply(s1r, s1i, pReal[5 * stride], pImag[5 * stride], twiddleStart + 5 * twiddleIncrement);
		r24 = s1r - r18;
		i24 = s1i - i18;
		r36 = r18 + s1r;
		i36 = i18 + s1i;
	}
	{
		valueT s1r, s1i;
		phasors.Multiply(s1r, s1i, pReal[11 * stride], pImag[11 * stride], twiddleStart + 11 * twiddleIncrement);
		r48 = r36 + s1r;
		i48 = i36 + s1i;
		r72 = valueT(-1.5) * r36;
		i72 = valueT(-1.5) * i36;
	}
	{
		valueT s1r, s1i;
		phasors.Multiply(r2, i2, pReal[1 * stride], pImag[1 * stride], twiddleStart + 1 * twiddleIncrement);
		phasors.Multiply(r8, i8, pReal[7 * stride], pImag[7 * stride], twiddleStart + 7 * twiddleIncrement);
		phasors.Multiply(s1r, s1i, pReal[13 * stride], pImag[13 * stride], twiddleStart + 13 * twiddleIncrement);
		r26 = r2 + r8;
		i26 = i2 + i8;
		r50 = s1r + r26;
		i50 = s1i + i26;
		r138 = r48 - r50;
		i138 = i48 - i50;
		r140 = r48 + r50;
		i140 = i48 + i50;
		r90 = r48 + r72;
		i90 = i48 + i72;
	}
	{
		valueT s1r, s1i;
		s1r = valueT(0.86602540378443864676) * i24;
		s1i = valueT(-0.86602540378443864676) * r24;
		r96 = s1r - r90;
		i96 = s1i - i90;
		r108 = r90 + s1r;
		i108 = i90 + s1i;
	}
	r126 = valueT(0.7660444431189780352) * r108 - valueT(0.64278760968653932632) * i108;
	i126 = valueT(0.64278760968653932632) * r108 + valueT(0.7660444431189780352) * i108;
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i;
		s1r = r2 - r8;
		s1i = i2 - i8;
		s2r = valueT(-0.86602540378443864676) * s1i;
		s2i = valueT(0.86602540378443864676) * s1r;
		s3r = valueT(-1.5) * r26;
		s3i = valueT(-1.5) * i26;
		s4r = r50 + s3r;
		s4i = i50 + s3i;
		r92 = s2r - s4r;
		i92 = s2i - s4i;
		s5r = s2r + s4r;
		s5i = s2i + s4i;
		s6r = valueT(0.17364817766693034885) * s5r - valueT(0.98480775301220805937) * s5i;
		s6i = valueT(0.98480775301220805937) * s5r + valueT(0.17364817766693034885) * s5i;
		r134 = s6r - r126;
		i134 = s6i - i126;
		r144 = r126 + s6r;
		i144 = i126 + s6i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		phasors.Multiply(s1r, s1i, pReal[3 * stride], pImag[3 * stride], twiddleStart + 3 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[9 * stride], pImag[9 * stride], twiddleStart + 9 * twiddleIncrement);
		phasors.Multiply(s3r, s3i, pReal[15 * stride], pImag[15 * stride], twiddleStart + 15 * twiddleIncrement);
		s4r = s1r - s3r;
		s4i = s1i - s3i;
		s5r = s1r + s3r;
		s5i = s1i + s3i;
		s6r = valueT(0.86602540378443864676) * s4i;
		s6i = valueT(-0.86602540378443864676) * s4r;
		s7r = s2r + s5r;
		s7i = s2i + s5i;
		s8r = valueT(-1.5) * s5r;
		s8i = valueT(-1.5) * s5i;
		s9r = s7r + s8r;
		s9i = s7i + s8i;
		r94 = s6r - s9r;
		i94 = s6i - s9i;
		s10r = s6r + s9r;
		s10i = s6i + s9i;
		r154 = r140 + s7r;
		i154 = i140 + s7i;
		r160 = r144 + s10r;
		i160 = i144 + s10i;
		r180 = valueT(-1.5) * r144;
		i180 = valueT(-1.5) * i144;
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
		r61 = valueT(-0.86602540378443864676) * s10i;
		i61 = valueT(0.86602540378443864676) * s10r;
		r37 = s1r + s11r;
		i37 = s1i + s11i;
		s16r = valueT(-1.5) * s11r;
		s16i = valueT(-1.5) * s11i;
		s17r = valueT(-0.86602540378443864676) * s12i;
		s17i = valueT(0.86602540378443864676) * s12r;
		s18r = s2r + s13r;
		s18i = s2i + s13i;
		s19r = valueT(-1.5) * s13r;
		s19i = valueT(-1.5) * s13i;
		s20r = valueT(-0.86602540378443864676) * s14i;
		s20i = valueT(0.86602540378443864676) * s14r;
		s21r = s3r + s15r;
		s21i = s3i + s15i;
		s22r = valueT(-1.5) * s15r;
		s22i = valueT(-1.5) * s15i;
		r85 = r37 + s16r;
		i85 = i37 + s16i;
		s23r = s18r + s19r;
		s23i = s18i + s19i;
		r129 = s18r - s21r;
		i129 = s18i - s21i;
		r131 = s18r + s21r;
		i131 = s18i + s21i;
		s24r = s21r + s22r;
		s24i = s21i + s22i;
		s25r = r61 + r85;
		s25i = i61 + i85;
		r99 = s17r - s23r;
		i99 = s17i - s23i;
		s26r = s17r + s23r;
		s26i = s17i + s23i;
		r101 = s20r - s24r;
		i101 = s20i - s24i;
		s27r = s20r + s24r;
		s27i = s20i + s24i;
		s28r = valueT(0.7660444431189780352) * s26r - valueT(0.64278760968653932632) * s26i;
		s28i = valueT(0.64278760968653932632) * s26r + valueT(0.7660444431189780352) * s26i;
		s29r = valueT(0.17364817766693034885) * s27r - valueT(0.98480775301220805937) * s27i;
		s29i = valueT(0.98480775301220805937) * s27r + valueT(0.17364817766693034885) * s27i;
		r141 = s28r - s29r;
		i141 = s28i - s29i;
		s30r = s28r + s29r;
		s30i = s28i + s29i;
		r157 = s25r + s30r;
		i157 = s25i + s30i;
		s31r = valueT(-1.5) * s30r;
		s31i = valueT(-1.5) * s30i;
		r197 = s31r - r180;
		i197 = s31i - i180;
		r198 = r180 + s31r;
		i198 = i180 + s31i;
	}
	{
		valueT s1r, s1i;
		r193 = r157 - r160;
		i193 = i157 - i160;
		s1r = r160 + r157;
		s1i = i160 + i157;
		pReal[10 * stride] = s1r;
		pImag[10 * stride] = s1i;
		r216 = r198 + s1r;
		i216 = i198 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i;
		s1r = valueT(-0.86602540378443864676) * i141;
		s1i = valueT(0.86602540378443864676) * r141;
		s2r = valueT(0.86602540378443864676) * i134;
		s2i = valueT(-0.86602540378443864676) * r134;
		r188 = s2r - s1r;
		i188 = s2i - s1i;
		s3r = s1r + s2r;
		s3i = s1i + s2i;
		pReal[16 * stride] = r216 - s3r;
		pImag[16 * stride] = i216 - s3i;
		pReal[4 * stride] = r216 + s3r;
		pImag[4 * stride] = i216 + s3i;
	}
	{
		valueT s1r, s1i;
		pReal[1 * stride] = r193;
		pImag[1 * stride] = i193;
		s1r = r197 + r193;
		s1i = i197 + i193;
		pReal[13 * stride] = s1r - r188;
		pImag[13 * stride] = s1i - i188;
		pReal[7 * stride] = r188 + s1r;
		pImag[7 * stride] = i188 + s1i;
	}
	r119 = valueT(0.93969262078590838405) * r101 + valueT(0.34202014332566873304) * i101;
	i119 = valueT(0.93969262078590838405) * i101 - valueT(0.34202014332566873304) * r101;
	{
		valueT s1r, s1i;
		s1r = valueT(0.98480775301220805937) * i99 - valueT(0.17364817766693034885) * r99;
		s1i = valueT(-0.98480775301220805937) * r99 - valueT(0.17364817766693034885) * i99;
		r135 = s1r - r119;
		i135 = s1i - i119;
		r137 = r119 + s1r;
		i137 = i119 + s1i;
	}
	{
		valueT s1r, s1i;
		s1r = r61 - r85;
		s1i = i61 - i85;
		r151 = s1r - r137;
		i151 = s1i - i137;
		r173 = valueT(-1.5) * r137;
		i173 = valueT(-1.5) * i137;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i;
		s1r = valueT(0.93969262078590838405) * r92 + valueT(0.34202014332566873304) * i92;
		s1i = valueT(0.93969262078590838405) * i92 - valueT(0.34202014332566873304) * r92;
		s2r = valueT(0.98480775301220805937) * i96 - valueT(0.17364817766693034885) * r96;
		s2i = valueT(-0.98480775301220805937) * r96 - valueT(0.17364817766693034885) * i96;
		r128 = s1r - s2r;
		i128 = s1i - s2i;
		s3r = s1r + s2r;
		s3i = s1i + s2i;
		r148 = r94 - s3r;
		i148 = i94 - s3i;
		s4r = valueT(-1.5) * s3r;
		s4i = valueT(-1.5) * s3i;
		r186 = s4r - r173;
		i186 = s4i - i173;
		r191 = r173 + s4r;
		i191 = i173 + s4i;
	}
	{
		valueT s1r, s1i;
		r184 = r148 - r151;
		i184 = i148 - i151;
		s1r = r151 + r148;
		s1i = i151 + i148;
		pReal[2 * stride] = -s1r;
		pImag[2 * stride] = -s1i;
		r209 = r191 - s1r;
		i209 = i191 - s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i;
		s1r = valueT(-0.86602540378443864676) * i135;
		s1i = valueT(0.86602540378443864676) * r135;
		s2r = valueT(0.86602540378443864676) * i128;
		s2i = valueT(-0.86602540378443864676) * r128;
		r182 = s2r - s1r;
		i182 = s2i - s1i;
		s3r = s1r + s2r;
		s3i = s1i + s2i;
		pReal[8 * stride] = r209 - s3r;
		pImag[8 * stride] = i209 - s3i;
		pReal[14 * stride] = r209 + s3r;
		pImag[14 * stride] = i209 + s3i;
	}
	{
		valueT s1r, s1i;
		pReal[11 * stride] = r184;
		pImag[11 * stride] = i184;
		s1r = r186 - r184;
		s1i = i186 - i184;
		pReal[5 * stride] = -r182 - s1r;
		pImag[5 * stride] = -i182 - s1i;
		pReal[17 * stride] = r182 - s1r;
		pImag[17 * stride] = i182 - s1i;
	}
	r145 = r37 + r131;
	i145 = i37 + i131;
	r167 = valueT(-1.5) * r131;
	i167 = valueT(-1.5) * i131;
	{
		valueT s1r, s1i;
		s1r = valueT(-1.5) * r140;
		s1i = valueT(-1.5) * i140;
		r185 = r167 - s1r;
		i185 = i167 - s1i;
		r194 = r167 + s1r;
		i194 = i167 + s1i;
	}
	{
		valueT s1r, s1i;
		r181 = r145 - r154;
		i181 = i145 - i154;
		s1r = r154 + r145;
		s1i = i154 + i145;
		pReal[0 * stride] = s1r;
		pImag[0 * stride] = s1i;
		r212 = r194 + s1r;
		i212 = i194 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i;
		s1r = valueT(-0.86602540378443864676) * i129;
		s1i = valueT(0.86602540378443864676) * r129;
		s2r = valueT(-0.86602540378443864676) * i138;
		s2i = valueT(0.86602540378443864676) * r138;
		r183 = s1r - s2r;
		i183 = s1i - s2i;
		s3r = s1r + s2r;
		s3i = s1i + s2i;
		pReal[6 * stride] = r212 - s3r;
		pImag[6 * stride] = i212 - s3i;
		pReal[12 * stride] = r212 + s3r;
		pImag[12 * stride] = i212 + s3i;
	}
	{
		valueT s1r, s1i;
		pReal[9 * stride] = r181;
		pImag[9 * stride] = i181;
		s1r = r185 + r181;
		s1i = i185 + i181;
		pReal[15 * stride] = s1r - r183;
		pImag[15 * stride] = s1i - i183;
		pReal[3 * stride] = r183 + s1r;
		pImag[3 * stride] = i183 + s1i;
	}
}

template<> void StandardModule<float, 18>::Compute(float *pReal, float *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

template<> void StandardModule<double, 18>::Compute(double *pReal, double *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

}
}
