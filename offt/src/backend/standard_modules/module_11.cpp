
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

template<> StandardModuleComplexity const StandardModule<float, 11>::Complexity = { 0, 0 };
template<> StandardModuleComplexity const StandardModule<double, 11>::Complexity = { 0, 0 };

template<typename valueT>
static void ComputeCore(Phasors<valueT> const &phasors, valueT *pReal, valueT *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement)
{
	valueT r11, i11, r13, i13, r22, i22, r17, i17, r16, i16;
	valueT r15, i15, r14, i14, r30, i30, r31, i31, r36, i36;
	valueT r32, i32, r34, i34, r29, i29, r33, i33, r68, i68;
	valueT r55, i55, r69, i69, r89, i89, r90, i90, r105, i105;
	valueT r104, i104, r103, i103, r101, i101, r102, i102, r100, i100;
	valueT r98, i98, r97, i97, r96, i96;

	phasors.Multiply(r11, i11, pReal[10 * stride], pImag[10 * stride], twiddleStart + 10 * twiddleIncrement);
	{
		valueT s1r, s1i;
		phasors.Multiply(s1r, s1i, pReal[1 * stride], pImag[1 * stride], twiddleStart + 1 * twiddleIncrement);
		r13 = s1r - r11;
		i13 = s1i - i11;
		r22 = r11 + s1r;
		i22 = i11 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		valueT s11r, s11i, s12r, s12i;
		phasors.Multiply(s1r, s1i, pReal[2 * stride], pImag[2 * stride], twiddleStart + 2 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[3 * stride], pImag[3 * stride], twiddleStart + 3 * twiddleIncrement);
		phasors.Multiply(s3r, s3i, pReal[4 * stride], pImag[4 * stride], twiddleStart + 4 * twiddleIncrement);
		phasors.Multiply(s4r, s4i, pReal[5 * stride], pImag[5 * stride], twiddleStart + 5 * twiddleIncrement);
		phasors.Multiply(s5r, s5i, pReal[6 * stride], pImag[6 * stride], twiddleStart + 6 * twiddleIncrement);
		phasors.Multiply(s6r, s6i, pReal[7 * stride], pImag[7 * stride], twiddleStart + 7 * twiddleIncrement);
		phasors.Multiply(s7r, s7i, pReal[8 * stride], pImag[8 * stride], twiddleStart + 8 * twiddleIncrement);
		phasors.Multiply(s8r, s8i, pReal[9 * stride], pImag[9 * stride], twiddleStart + 9 * twiddleIncrement);
		r17 = s4r - s5r;
		i17 = s4i - s5i;
		s9r = s4r + s5r;
		s9i = s4i + s5i;
		r16 = s3r - s6r;
		i16 = s3i - s6i;
		s10r = s3r + s6r;
		s10i = s3i + s6i;
		r15 = s2r - s7r;
		i15 = s2i - s7i;
		s11r = s2r + s7r;
		s11i = s2i + s7i;
		r14 = s1r - s8r;
		i14 = s1i - s8i;
		s12r = s1r + s8r;
		s12i = s1i + s8i;
		r30 = s10r - s9r;
		i30 = s10i - s9i;
		r31 = s11r - s9r;
		i31 = s11i - s9i;
		r36 = s9r - s12r;
		i36 = s9i - s12i;
		r32 = s12r - s11r;
		i32 = s12i - s11i;
		r34 = s9r - r22;
		i34 = s9i - i22;
		r29 = r22 + s9r + s10r + s11r + s12r;
		i29 = i22 + s9i + s10i + s11i + s12i;
		r33 = r22 - s10r;
		i33 = i22 - s10i;
	}
	r68 = valueT(0.90180781188778253033) * r32;
	i68 = valueT(0.90180781188778253033) * i32;
	r55 = r33 - r32;
	i55 = i33 - i32;
	r69 = valueT(0.5971755722185702045) * r33;
	i69 = valueT(0.5971755722185702045) * i33;
	{
		valueT s1r, s1i;
		s1r = valueT(-0.042314838273285140444) * r55;
		s1i = valueT(-0.042314838273285140444) * i55;
		r89 = r68 - s1r;
		i89 = i68 - s1i;
		r90 = r69 + s1r;
		i90 = i69 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		valueT s11r, s11i, s12r, s12i, s13r, s13i, s14r, s14i, s15r, s15i;
		valueT s16r, s16i;
		phasors.Multiply(s1r, s1i, pReal[0 * stride], pImag[0 * stride], twiddleStart + 0 * twiddleIncrement);
		s2r = valueT(-0.51541501300188642553) * r30;
		s2i = valueT(-0.51541501300188642553) * i30;
		s3r = r30 - r31;
		s3i = i30 - i31;
		s4r = valueT(0.55486073394528506406) * r31;
		s4i = valueT(0.55486073394528506406) * i31;
		s5r = valueT(0.94125353283118116886) * r36;
		s5i = valueT(0.94125353283118116886) * i36;
		s6r = r36 - r34;
		s6i = i36 - i34;
		s7r = valueT(-0.85949297361449738989) * r34;
		s7i = valueT(-0.85949297361449738989) * i34;
		s8r = r29 + s1r;
		s8i = i29 + s1i;
		s9r = valueT(-1.1) * r29;
		s9i = valueT(-1.1) * i29;
		s10r = valueT(-0.89893869455789602842) * s3r;
		s10i = valueT(-0.89893869455789602842) * s3i;
		s11r = valueT(-0.47310017472860128509) * s6r;
		s11i = valueT(-0.47310017472860128509) * s6i;
		pReal[0 * stride] = s8r;
		pImag[0 * stride] = s8i;
		s12r = s8r + s9r;
		s12i = s8i + s9i;
		s13r = s2r + s10r;
		s13i = s2i + s10i;
		s14r = s4r - s10r;
		s14i = s4i - s10i;
		s15r = s5r - s11r;
		s15i = s5i - s11i;
		s16r = s7r + s11r;
		s16i = s7i + s11i;
		r105 = s13r + s14r + s15r + s16r - s12r;
		i105 = s13i + s14i + s15i + s16i - s12i;
		r104 = r89 + s12r + s15r;
		i104 = i89 + s12i + s15i;
		r103 = s12r + s14r - r89;
		i103 = s12i + s14i - i89;
		r101 = r90 + s12r + s16r;
		i101 = i90 + s12i + s16i;
		r102 = s12r + s13r - r90;
		i102 = s12i + s13i - i90;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		valueT s11r, s11i, s12r, s12i, s13r, s13i, s14r, s14i, s15r, s15i;
		valueT s16r, s16i, s17r, s17i, s18r, s18i, s19r, s19i, s20r, s20i;
		valueT s21r, s21i, s22r, s22i, s23r, s23i, s24r, s24i, s25r, s25i;
		valueT s26r, s26i, s27r, s27i;
		s1r = r16 - r17;
		s1i = i16 - i17;
		s2r = r15 - r17;
		s2i = i15 - i17;
		s3r = r17 + r14;
		s3i = i17 + i14;
		s4r = r15 + r14;
		s4i = i15 + i14;
		s5r = r17 - r13;
		s5i = i17 - i13;
		s6r = r13 + r17 + r16 + r15 - r14;
		s6i = i13 + i17 + i16 + i15 - i14;
		s7r = r16 - r13;
		s7i = i16 - i13;
		s8r = valueT(-0.492980128140842333) * s1i;
		s8i = valueT(0.492980128140842333) * s1r;
		s9r = -s1r - s2r;
		s9i = -s1i - s2i;
		s10r = valueT(-2.1583616978496189882) * s2i;
		s10i = valueT(2.1583616978496189882) * s2r;
		s11r = valueT(-0.95729268466927362052) * s3i;
		s11i = valueT(0.95729268466927362052) * s3r;
		s12r = valueT(0.70808888503950303466) * s4i;
		s12i = valueT(-0.70808888503950303466) * s4r;
		s13r = s3r + s5r;
		s13i = s3i + s5i;
		s14r = valueT(-1.2162009452834415049) * s5i;
		s14i = valueT(1.2162009452834415049) * s5r;
		s15r = valueT(-0.33166247903553998491) * s6i;
		s15i = valueT(0.33166247903553998491) * s6r;
		s16r = s4r + s7r;
		s16i = s4i + s7i;
		s17r = valueT(-0.2340718675266744486) * s7i;
		s17i = valueT(0.2340718675266744486) * s7r;
		s18r = valueT(-0.86713730126545034466) * s9i;
		s18i = valueT(0.86713730126545034466) * s9r;
		s19r = valueT(0.58313551154466560886) * s13i;
		s19i = valueT(-0.58313551154466560886) * s13r;
		s20r = valueT(0.65815896284539274746) * s16i;
		s20i = valueT(-0.65815896284539274746) * s16r;
		s21r = s8r + s18r;
		s21i = s8i + s18i;
		s22r = s10r + s18r;
		s22i = s10i + s18i;
		s23r = s11r + s19r;
		s23i = s11i + s19i;
		s24r = s14r + s19r;
		s24i = s14i + s19i;
		s25r = s12r - s20r;
		s25i = s12i - s20i;
		s26r = s17r + s20r;
		s26i = s17i + s20i;
		r100 = s15r + s21r + s22r + s23r + s24r;
		i100 = s15i + s21i + s22i + s23i + s24i;
		r98 = s22r + s25r - s15r;
		i98 = s22i + s25i - s15i;
		r97 = s15r + s25r - s23r;
		i97 = s15i + s25i - s23i;
		s27r = s15r + s26r - s21r;
		s27i = s15i + s26i - s21i;
		r96 = s15r - s24r - s26r;
		i96 = s15i - s24i - s26i;
		pReal[7 * stride] = r102 - s27r;
		pImag[7 * stride] = i102 - s27i;
		pReal[4 * stride] = r102 + s27r;
		pImag[4 * stride] = i102 + s27i;
	}
	pReal[10 * stride] = r101 - r96;
	pImag[10 * stride] = i101 - i96;
	pReal[1 * stride] = r101 + r96;
	pImag[1 * stride] = i101 + i96;
	pReal[2 * stride] = r104 - r97;
	pImag[2 * stride] = i104 - i97;
	pReal[9 * stride] = r104 + r97;
	pImag[9 * stride] = i104 + i97;
	pReal[3 * stride] = r103 - r98;
	pImag[3 * stride] = i103 - i98;
	pReal[8 * stride] = r103 + r98;
	pImag[8 * stride] = i103 + i98;
	pReal[6 * stride] = -r105 - r100;
	pImag[6 * stride] = -i105 - i100;
	pReal[5 * stride] = r100 - r105;
	pImag[5 * stride] = i100 - i105;
}

template<> void StandardModule<float, 11>::Compute(float *pReal, float *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

template<> void StandardModule<double, 11>::Compute(double *pReal, double *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

}
}
