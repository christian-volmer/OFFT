
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

template<> StandardModuleComplexity const StandardModule<float, 9>::Complexity = { 0, 0 };
template<> StandardModuleComplexity const StandardModule<double, 9>::Complexity = { 0, 0 };

template<typename valueT>
static void ComputeCore(Phasors<valueT> const &phasors, valueT *pReal, valueT *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement)
{
	valueT r9, i9, r15, i15, r18, i18, r21, i21, r36, i36;
	valueT r5, i5, r8, i8, r17, i17, r20, i20, r65, i65;
	valueT r66, i66, r45, i45, r51, i51, r54, i54, r63, i63;
	valueT r50, i50, r71, i71, r72, i72, r49, i49, r73, i73;
	valueT r79, i79, r90, i90, r99, i99, r93, i93, r68, i68;
	valueT r76, i76, r87, i87, r96, i96;

	phasors.Multiply(r9, i9, pReal[8 * stride], pImag[8 * stride], twiddleStart + 8 * twiddleIncrement);
	{
		valueT s1r, s1i;
		phasors.Multiply(s1r, s1i, pReal[5 * stride], pImag[5 * stride], twiddleStart + 5 * twiddleIncrement);
		r15 = s1r - r9;
		i15 = s1i - i9;
		r18 = r9 + s1r;
		i18 = i9 + s1i;
	}
	{
		valueT s1r, s1i;
		phasors.Multiply(s1r, s1i, pReal[2 * stride], pImag[2 * stride], twiddleStart + 2 * twiddleIncrement);
		r21 = r18 + s1r;
		i21 = i18 + s1i;
		r36 = valueT(-1.5) * r18;
		i36 = valueT(-1.5) * i18;
	}
	{
		valueT s1r, s1i;
		phasors.Multiply(s1r, s1i, pReal[1 * stride], pImag[1 * stride], twiddleStart + 1 * twiddleIncrement);
		phasors.Multiply(r5, i5, pReal[4 * stride], pImag[4 * stride], twiddleStart + 4 * twiddleIncrement);
		phasors.Multiply(r8, i8, pReal[7 * stride], pImag[7 * stride], twiddleStart + 7 * twiddleIncrement);
		r17 = r5 + r8;
		i17 = i5 + i8;
		r20 = s1r + r17;
		i20 = s1i + i17;
		r65 = r20 - r21;
		i65 = i20 - i21;
		r66 = r21 + r20;
		i66 = i21 + i20;
		r45 = r21 + r36;
		i45 = i21 + i36;
	}
	{
		valueT s1r, s1i;
		s1r = valueT(-0.86602540378443864676) * i15;
		s1i = valueT(0.86602540378443864676) * r15;
		r51 = s1r - r45;
		i51 = s1i - i45;
		r54 = r45 + s1r;
		i54 = i45 + s1i;
	}
	r63 = valueT(0.17364817766693034885) * r54 - valueT(0.98480775301220805937) * i54;
	i63 = valueT(0.98480775301220805937) * r54 + valueT(0.17364817766693034885) * i54;
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i;
		s1r = r5 - r8;
		s1i = i5 - i8;
		s2r = valueT(-0.86602540378443864676) * s1i;
		s2i = valueT(0.86602540378443864676) * s1r;
		s3r = valueT(-1.5) * r17;
		s3i = valueT(-1.5) * i17;
		s4r = r20 + s3r;
		s4i = i20 + s3i;
		r50 = s2r - s4r;
		i50 = s2i - s4i;
		s5r = s2r + s4r;
		s5i = s2i + s4i;
		s6r = valueT(0.7660444431189780352) * s5r - valueT(0.64278760968653932632) * s5i;
		s6i = valueT(0.64278760968653932632) * s5r + valueT(0.7660444431189780352) * s5i;
		r71 = s6r - r63;
		i71 = s6i - i63;
		r72 = r63 + s6r;
		i72 = i63 + s6i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		phasors.Multiply(s1r, s1i, pReal[0 * stride], pImag[0 * stride], twiddleStart + 0 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[3 * stride], pImag[3 * stride], twiddleStart + 3 * twiddleIncrement);
		phasors.Multiply(s3r, s3i, pReal[6 * stride], pImag[6 * stride], twiddleStart + 6 * twiddleIncrement);
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
		r49 = s6r - s9r;
		i49 = s6i - s9i;
		s10r = s6r + s9r;
		s10i = s6i + s9i;
		r73 = r66 + s7r;
		i73 = i66 + s7i;
		r79 = r72 + s10r;
		i79 = i72 + s10i;
		r90 = valueT(-1.5) * r72;
		i90 = valueT(-1.5) * i72;
	}
	pReal[1 * stride] = r79;
	pImag[1 * stride] = i79;
	r99 = r79 + r90;
	i99 = i79 + i90;
	{
		valueT s1r, s1i;
		s1r = valueT(-0.86602540378443864676) * i71;
		s1i = valueT(0.86602540378443864676) * r71;
		pReal[7 * stride] = r99 - s1r;
		pImag[7 * stride] = i99 - s1i;
		pReal[4 * stride] = r99 + s1r;
		pImag[4 * stride] = i99 + s1i;
	}
	{
		valueT s1r, s1i;
		s1r = valueT(-1.5) * r66;
		s1i = valueT(-1.5) * i66;
		pReal[0 * stride] = r73;
		pImag[0 * stride] = i73;
		r93 = r73 + s1r;
		i93 = i73 + s1i;
	}
	{
		valueT s1r, s1i;
		s1r = valueT(-0.86602540378443864676) * i65;
		s1i = valueT(0.86602540378443864676) * r65;
		pReal[6 * stride] = r93 - s1r;
		pImag[6 * stride] = i93 - s1i;
		pReal[3 * stride] = r93 + s1r;
		pImag[3 * stride] = i93 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i;
		s1r = valueT(0.98480775301220805937) * i50 - valueT(0.17364817766693034885) * r50;
		s1i = valueT(-0.98480775301220805937) * r50 - valueT(0.17364817766693034885) * i50;
		s2r = valueT(0.93969262078590838405) * r51 + valueT(0.34202014332566873304) * i51;
		s2i = valueT(0.93969262078590838405) * i51 - valueT(0.34202014332566873304) * r51;
		r68 = s1r - s2r;
		i68 = s1i - s2i;
		s3r = s1r + s2r;
		s3i = s1i + s2i;
		r76 = r49 - s3r;
		i76 = i49 - s3i;
		r87 = valueT(-1.5) * s3r;
		i87 = valueT(-1.5) * s3i;
	}
	pReal[2 * stride] = -r76;
	pImag[2 * stride] = -i76;
	r96 = r87 - r76;
	i96 = i87 - i76;
	{
		valueT s1r, s1i;
		s1r = valueT(-0.86602540378443864676) * i68;
		s1i = valueT(0.86602540378443864676) * r68;
		pReal[8 * stride] = r96 - s1r;
		pImag[8 * stride] = i96 - s1i;
		pReal[5 * stride] = r96 + s1r;
		pImag[5 * stride] = i96 + s1i;
	}
}

template<> void StandardModule<float, 9>::Compute(float *pReal, float *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

template<> void StandardModule<double, 9>::Compute(double *pReal, double *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

}
}
