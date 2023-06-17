
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

template<> StandardModuleComplexity const StandardModule<float, 16>::Complexity = { 0, 0 };
template<> StandardModuleComplexity const StandardModule<double, 16>::Complexity = { 0, 0 };

template<typename valueT>
static void ComputeCore(Phasors<valueT> const &phasors, valueT *pReal, valueT *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement)
{
	valueT r16, i16, r40, i40, r48, i48, r36, i36, r76, i76;
	valueT r80, i80, r34, i34, r38, i38, r74, i74, r126, i126;
	valueT r128, i128, r17, i17, r35, i35, r21, i21, r39, i39;
	valueT r41, i41, r75, i75, r93, i93, r91, i91, r89, i89;
	valueT r124, i124, r55, i55, r67, i67, r71, i71, r33, i33;
	valueT r87, i87, r85, i85, r66, i66, r68, i68, r120, i120;
	valueT r100, i100, r114, i114, r116, i116, r81, i81;

	phasors.Multiply(r16, i16, pReal[15 * stride], pImag[15 * stride], twiddleStart + 15 * twiddleIncrement);
	{
		valueT s1r, s1i;
		phasors.Multiply(s1r, s1i, pReal[7 * stride], pImag[7 * stride], twiddleStart + 7 * twiddleIncrement);
		r40 = s1r - r16;
		i40 = s1i - i16;
		r48 = r16 + s1r;
		i48 = i16 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i;
		phasors.Multiply(s1r, s1i, pReal[3 * stride], pImag[3 * stride], twiddleStart + 3 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[11 * stride], pImag[11 * stride], twiddleStart + 11 * twiddleIncrement);
		r36 = s1r - s2r;
		i36 = s1i - s2i;
		s3r = s1r + s2r;
		s3i = s1i + s2i;
		r76 = s3r - r48;
		i76 = s3i - i48;
		r80 = r48 + s3r;
		i80 = i48 + s3i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i;
		phasors.Multiply(s1r, s1i, pReal[1 * stride], pImag[1 * stride], twiddleStart + 1 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[5 * stride], pImag[5 * stride], twiddleStart + 5 * twiddleIncrement);
		phasors.Multiply(s3r, s3i, pReal[9 * stride], pImag[9 * stride], twiddleStart + 9 * twiddleIncrement);
		phasors.Multiply(s4r, s4i, pReal[13 * stride], pImag[13 * stride], twiddleStart + 13 * twiddleIncrement);
		r34 = s1r - s3r;
		i34 = s1i - s3i;
		s5r = s1r + s3r;
		s5i = s1i + s3i;
		r38 = s2r - s4r;
		i38 = s2i - s4i;
		s6r = s2r + s4r;
		s6i = s2i + s4i;
		r74 = s5r - s6r;
		i74 = s5i - s6i;
		s7r = s5r + s6r;
		s7i = s5i + s6i;
		r126 = s7r - r80;
		i126 = s7i - i80;
		r128 = r80 + s7r;
		i128 = i80 + s7i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		valueT s11r, s11i, s12r, s12i, s13r, s13i, s14r, s14i, s15r, s15i;
		phasors.Multiply(s1r, s1i, pReal[0 * stride], pImag[0 * stride], twiddleStart + 0 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[2 * stride], pImag[2 * stride], twiddleStart + 2 * twiddleIncrement);
		phasors.Multiply(s3r, s3i, pReal[4 * stride], pImag[4 * stride], twiddleStart + 4 * twiddleIncrement);
		phasors.Multiply(s4r, s4i, pReal[6 * stride], pImag[6 * stride], twiddleStart + 6 * twiddleIncrement);
		phasors.Multiply(s5r, s5i, pReal[8 * stride], pImag[8 * stride], twiddleStart + 8 * twiddleIncrement);
		phasors.Multiply(s6r, s6i, pReal[10 * stride], pImag[10 * stride], twiddleStart + 10 * twiddleIncrement);
		phasors.Multiply(s7r, s7i, pReal[12 * stride], pImag[12 * stride], twiddleStart + 12 * twiddleIncrement);
		phasors.Multiply(s8r, s8i, pReal[14 * stride], pImag[14 * stride], twiddleStart + 14 * twiddleIncrement);
		r17 = s1r - s5r;
		i17 = s1i - s5i;
		s9r = s1r + s5r;
		s9i = s1i + s5i;
		r35 = s2r - s6r;
		i35 = s2i - s6i;
		s10r = s2r + s6r;
		s10i = s2i + s6i;
		r21 = s3r - s7r;
		i21 = s3i - s7i;
		s11r = s3r + s7r;
		s11i = s3i + s7i;
		r39 = s4r - s8r;
		i39 = s4i - s8i;
		s12r = s4r + s8r;
		s12i = s4i + s8i;
		r41 = s9r - s11r;
		i41 = s9i - s11i;
		s13r = s9r + s11r;
		s13i = s9i + s11i;
		r75 = s10r - s12r;
		i75 = s10i - s12i;
		s14r = s10r + s12r;
		s14i = s10i + s12i;
		r93 = s13r - s14r;
		i93 = s13i - s14i;
		s15r = s13r + s14r;
		s15i = s13i + s14i;
		pReal[8 * stride] = s15r - r128;
		pImag[8 * stride] = s15i - i128;
		pReal[0 * stride] = r128 + s15r;
		pImag[0 * stride] = i128 + s15i;
	}
	pReal[12 * stride] = i126 + r93;
	pImag[12 * stride] = i93 - r126;
	pReal[4 * stride] = r93 - i126;
	pImag[4 * stride] = r126 + i93;
	r91 = i41 + r75;
	i91 = i75 - r41;
	r89 = r41 + i75;
	i89 = i41 - r75;
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i;
		s1r = valueT(0.7071067811865475244) * r74 - valueT(0.7071067811865475244) * i74;
		s1i = valueT(0.7071067811865475244) * r74 + valueT(0.7071067811865475244) * i74;
		s2r = valueT(-0.7071067811865475244) * r76 - valueT(0.7071067811865475244) * i76;
		s2i = valueT(0.7071067811865475244) * r76 - valueT(0.7071067811865475244) * i76;
		s3r = s1r - s2r;
		s3i = s1i - s2i;
		r124 = s1r + s2r;
		i124 = s1i + s2i;
		pReal[14 * stride] = r89 + s3i;
		pImag[14 * stride] = i89 - s3r;
		pReal[6 * stride] = r89 - s3i;
		pImag[6 * stride] = i89 + s3r;
	}
	pReal[10 * stride] = -i91 - r124;
	pImag[10 * stride] = r91 - i124;
	pReal[2 * stride] = r124 - i91;
	pImag[2 * stride] = r91 + i124;
	r55 = valueT(-0.7071067811865475244) * r39 - valueT(0.7071067811865475244) * i39;
	i55 = valueT(0.7071067811865475244) * r39 - valueT(0.7071067811865475244) * i39;
	{
		valueT s1r, s1i;
		s1r = valueT(0.7071067811865475244) * r35 - valueT(0.7071067811865475244) * i35;
		s1i = valueT(0.7071067811865475244) * r35 + valueT(0.7071067811865475244) * i35;
		r67 = s1r - r55;
		i67 = s1i - i55;
		r71 = r55 + s1r;
		i71 = i55 + s1i;
	}
	{
		valueT s1r, s1i;
		s1r = i17 + r21;
		s1i = i21 - r17;
		r33 = r17 + i21;
		i33 = i17 - r21;
		r87 = r71 - s1i;
		i87 = i71 + s1r;
		r85 = s1r - i71;
		i85 = r71 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		s1r = i34 + r38;
		s1i = i38 - r34;
		r66 = r34 + i38;
		i66 = i34 - r38;
		s2r = r40 + i36;
		s2i = i40 - r36;
		r68 = i40 + r36;
		i68 = i36 - r40;
		s3r = valueT(-0.38268343236508977173) * s1r - valueT(0.92387953251128675613) * s1i;
		s3i = valueT(0.92387953251128675613) * s1r - valueT(0.38268343236508977173) * s1i;
		s4r = valueT(-0.92387953251128675613) * s2r - valueT(0.38268343236508977173) * s2i;
		s4i = valueT(0.38268343236508977173) * s2r - valueT(0.92387953251128675613) * s2i;
		s5r = s3r - s4r;
		s5i = s3i - s4i;
		r120 = s3r + s4r;
		i120 = s3i + s4i;
		pReal[13 * stride] = s5i - i85;
		pImag[13 * stride] = r85 - s5r;
		pReal[5 * stride] = -i85 - s5i;
		pImag[5 * stride] = r85 + s5r;
	}
	pReal[9 * stride] = r87 - r120;
	pImag[9 * stride] = i87 - i120;
	pReal[1 * stride] = r87 + r120;
	pImag[1 * stride] = i87 + i120;
	r100 = valueT(0.38268343236508977173) * i68 - valueT(0.92387953251128675613) * r68;
	i100 = valueT(-0.38268343236508977173) * r68 - valueT(0.92387953251128675613) * i68;
	{
		valueT s1r, s1i;
		s1r = valueT(0.38268343236508977173) * r66 - valueT(0.92387953251128675613) * i66;
		s1i = valueT(0.92387953251128675613) * r66 + valueT(0.38268343236508977173) * i66;
		r114 = s1r - r100;
		i114 = s1i - i100;
		r116 = r100 + s1r;
		i116 = i100 + s1i;
	}
	{
		valueT s1r, s1i;
		s1r = r67 + i33;
		s1i = i67 - r33;
		r81 = i67 + r33;
		i81 = i33 - r67;
		pReal[11 * stride] = -r116 - s1i;
		pImag[11 * stride] = s1r - i116;
		pReal[3 * stride] = r116 - s1i;
		pImag[3 * stride] = i116 + s1r;
	}
	pReal[15 * stride] = i114 + r81;
	pImag[15 * stride] = i81 - r114;
	pReal[7 * stride] = r81 - i114;
	pImag[7 * stride] = r114 + i81;
}

template<> void StandardModule<float, 16>::Compute(float *pReal, float *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

template<> void StandardModule<double, 16>::Compute(double *pReal, double *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

}
}
