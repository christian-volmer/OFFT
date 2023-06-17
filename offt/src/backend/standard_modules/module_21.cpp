
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

template<> StandardModuleComplexity const StandardModule<float, 21>::Complexity = { 0, 0 };
template<> StandardModuleComplexity const StandardModule<double, 21>::Complexity = { 0, 0 };

template<typename valueT>
static void ComputeCore(Phasors<valueT> const &phasors, valueT *pReal, valueT *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement)
{
	valueT r21, i21, r35, i35, r42, i42, r23, i23, r58, i58;
	valueT r49, i49, r72, i72, r84, i84, r26, i26, r24, i24;
	valueT r32, i32, r27, i27, r61, i61, r52, i52, r46, i46;
	valueT r75, i75, r55, i55, r80, i80, r104, i104, r107, i107;
	valueT r102, i102, r105, i105, r156, i156, r29, i29, r82, i82;
	valueT r76, i76, r79, i79, r100, i100, r109, i109, r243, i243;
	valueT r206, i206, r207, i207, r204, i204, r198, i198, r203, i203;
	valueT r225, i225, r216, i216, r202, i202, r205, i205, r193, i193;
	valueT r196, i196, r220, i220, r237, i237, r191, i191, r189, i189;
	valueT r197, i197, r200, i200, r213, i213, r221, i221, r212, i212;
	valueT r228, i228, r226, i226, r249, i249, r210, i210, r218, i218;
	valueT r224, i224, r217, i217, r245, i245;

	phasors.Multiply(r21, i21, pReal[20 * stride], pImag[20 * stride], twiddleStart + 20 * twiddleIncrement);
	{
		valueT s1r, s1i;
		phasors.Multiply(s1r, s1i, pReal[13 * stride], pImag[13 * stride], twiddleStart + 13 * twiddleIncrement);
		r35 = s1r - r21;
		i35 = s1i - i21;
		r42 = r21 + s1r;
		i42 = i21 + s1i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		phasors.Multiply(s1r, s1i, pReal[1 * stride], pImag[1 * stride], twiddleStart + 1 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[6 * stride], pImag[6 * stride], twiddleStart + 6 * twiddleIncrement);
		phasors.Multiply(s3r, s3i, pReal[8 * stride], pImag[8 * stride], twiddleStart + 8 * twiddleIncrement);
		phasors.Multiply(s4r, s4i, pReal[15 * stride], pImag[15 * stride], twiddleStart + 15 * twiddleIncrement);
		r23 = s1r - s3r;
		i23 = s1i - s3i;
		s5r = s1r + s3r;
		s5i = s1i + s3i;
		r58 = s4r + s5r;
		i58 = s4i + s5i;
		r49 = r42 + s2r;
		i49 = i42 + s2i;
		r72 = s5r - r42;
		i72 = s5i - i42;
		r84 = r42 + s5r;
		i84 = i42 + s5i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		valueT s11r, s11i, s12r, s12i, s13r, s13i, s14r, s14i, s15r, s15i;
		valueT s16r, s16i, s17r, s17i, s18r, s18i;
		phasors.Multiply(s1r, s1i, pReal[2 * stride], pImag[2 * stride], twiddleStart + 2 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[3 * stride], pImag[3 * stride], twiddleStart + 3 * twiddleIncrement);
		phasors.Multiply(s3r, s3i, pReal[4 * stride], pImag[4 * stride], twiddleStart + 4 * twiddleIncrement);
		phasors.Multiply(s4r, s4i, pReal[5 * stride], pImag[5 * stride], twiddleStart + 5 * twiddleIncrement);
		phasors.Multiply(s5r, s5i, pReal[9 * stride], pImag[9 * stride], twiddleStart + 9 * twiddleIncrement);
		phasors.Multiply(s6r, s6i, pReal[10 * stride], pImag[10 * stride], twiddleStart + 10 * twiddleIncrement);
		phasors.Multiply(s7r, s7i, pReal[11 * stride], pImag[11 * stride], twiddleStart + 11 * twiddleIncrement);
		phasors.Multiply(s8r, s8i, pReal[12 * stride], pImag[12 * stride], twiddleStart + 12 * twiddleIncrement);
		phasors.Multiply(s9r, s9i, pReal[16 * stride], pImag[16 * stride], twiddleStart + 16 * twiddleIncrement);
		phasors.Multiply(s10r, s10i, pReal[17 * stride], pImag[17 * stride], twiddleStart + 17 * twiddleIncrement);
		phasors.Multiply(s11r, s11i, pReal[18 * stride], pImag[18 * stride], twiddleStart + 18 * twiddleIncrement);
		phasors.Multiply(s12r, s12i, pReal[19 * stride], pImag[19 * stride], twiddleStart + 19 * twiddleIncrement);
		r26 = s3r - s7r;
		i26 = s3i - s7i;
		s13r = s3r + s7r;
		s13i = s3i + s7i;
		r24 = s1r - s9r;
		i24 = s1i - s9i;
		s14r = s1r + s9r;
		s14i = s1i + s9i;
		r32 = s6r - s10r;
		i32 = s6i - s10i;
		s15r = s6r + s10r;
		s15i = s6i + s10i;
		r27 = s4r - s12r;
		i27 = s4i - s12i;
		s16r = s4r + s12r;
		s16i = s4i + s12i;
		r61 = s11r + s13r;
		i61 = s11i + s13i;
		r52 = s5r + s14r;
		i52 = s5i + s14i;
		r46 = s2r + s15r;
		i46 = s2i + s15i;
		r75 = s13r - s15r;
		i75 = s13i - s15i;
		s17r = s13r + s15r;
		s17i = s13i + s15i;
		r55 = s8r + s16r;
		i55 = s8i + s16i;
		r80 = s14r - s16r;
		i80 = s14i - s16i;
		s18r = s14r + s16r;
		s18i = s14i + s16i;
		r104 = s18r - s17r;
		i104 = s18i - s17i;
		r107 = s17r - r84;
		i107 = s17i - i84;
		r102 = r84 + s17r + s18r;
		i102 = i84 + s17i + s18i;
		r105 = r84 - s18r;
		i105 = i84 - s18i;
	}
	r156 = valueT(-1.1852347027881002958) * r105;
	i156 = valueT(-1.1852347027881002958) * i105;
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		valueT s11r, s11i;
		phasors.Multiply(s1r, s1i, pReal[0 * stride], pImag[0 * stride], twiddleStart + 0 * twiddleIncrement);
		phasors.Multiply(s2r, s2i, pReal[7 * stride], pImag[7 * stride], twiddleStart + 7 * twiddleIncrement);
		phasors.Multiply(s3r, s3i, pReal[14 * stride], pImag[14 * stride], twiddleStart + 14 * twiddleIncrement);
		r29 = s2r - s3r;
		i29 = s2i - s3i;
		s4r = s2r + s3r;
		s4i = s2i + s3i;
		s5r = s1r + s4r;
		s5i = s1i + s4i;
		r82 = r61 + r46;
		i82 = i61 + i46;
		r76 = r52 + r55;
		i76 = i52 + i55;
		r79 = r58 + r49;
		i79 = i58 + i49;
		s6r = valueT(1.1014533018536286894) * r104;
		s6i = valueT(1.1014533018536286894) * i104;
		r100 = r82 + r76 + r79;
		i100 = i82 + i76 + i79;
		s7r = valueT(-0.083781400934471606433) * r107;
		s7i = valueT(-0.083781400934471606433) * i107;
		s8r = r102 + s4r;
		s8i = i102 + s4i;
		s9r = valueT(1.75) * r102;
		s9i = valueT(1.75) * i102;
		r109 = s5r + r100;
		i109 = s5i + i100;
		s10r = valueT(-1.5) * s8r;
		s10i = valueT(-1.5) * s8i;
		s11r = s9r + s10r;
		s11i = s9i + s10i;
		r243 = r109 + s10r;
		i243 = i109 + s10i;
		r206 = s6r - r156 - s11r;
		i206 = s6i - i156 - s11i;
		r207 = s6r + s7r + s11r;
		i207 = s6i + s7i + s11i;
		r204 = s11r - r156 - s7r;
		i204 = s11i - i156 - s7i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		valueT s11r, s11i;
		s1r = r75 - r72;
		s1i = i75 - i72;
		s2r = r72 + r75 + r80;
		s2i = i72 + i75 + i80;
		s3r = r72 - r80;
		s3i = i72 - i80;
		s4r = valueT(1.8235728323783818938) * s1i;
		s4i = valueT(-1.8235728323783818938) * s1r;
		s5r = valueT(-0.66143782776614764763) * s2i;
		s5i = valueT(0.66143782776614764763) * s2r;
		s6r = s1r - s3r;
		s6i = s1i - s3i;
		s7r = valueT(-2.1132174769490725912) * s3i;
		s7i = valueT(2.1132174769490725912) * s3r;
		s8r = valueT(-1.3122634364424848283) * s6i;
		s8i = valueT(1.3122634364424848283) * s6r;
		s9r = s4r + s8r;
		s9i = s4i + s8i;
		s10r = s7r + s8r;
		s10i = s7i + s8i;
		r198 = s9r - s5r;
		i198 = s9i - s5i;
		r203 = s5r - s10r;
		i203 = s5i - s10i;
		s11r = s5r + s9r + s10r;
		s11i = s5i + s9i + s10i;
		r225 = r204 - s11r;
		i225 = i204 - s11i;
		r216 = r204 + s11r;
		i216 = i204 + s11i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		valueT s11r, s11i, s12r, s12i, s13r, s13i, s14r, s14i, s15r, s15i;
		valueT s16r, s16i, s17r, s17i, s18r, s18i, s19r, s19i, s20r, s20i;
		valueT s21r, s21i, s22r, s22i, s23r, s23i, s24r, s24i;
		s1r = r46 - r61;
		s1i = i46 - i61;
		s2r = r52 - r55;
		s2i = i52 - i55;
		s3r = r49 - r58;
		s3i = i49 - i58;
		s4r = r82 - r76;
		s4i = i82 - i76;
		s5r = s3r - s1r;
		s5i = s3i - s1i;
		s6r = s1r + s3r - s2r;
		s6i = s1i + s3i - s2i;
		s7r = s2r + s3r;
		s7i = s2i + s3i;
		s8r = r82 - r79;
		s8i = i82 - i79;
		s9r = r76 - r79;
		s9i = i76 - i79;
		s10r = valueT(0.73430220123575245957) * s4r;
		s10i = valueT(0.73430220123575245957) * s4i;
		s11r = valueT(-1.2157152215855879292) * s5i;
		s11i = valueT(1.2157152215855879292) * s5r;
		s12r = valueT(-0.44095855184409843175) * s6i;
		s12i = valueT(0.44095855184409843175) * s6r;
		s13r = s5r + s7r;
		s13i = s5i + s7i;
		s14r = valueT(-1.4088116512993817275) * s7i;
		s14i = valueT(1.4088116512993817275) * s7r;
		s15r = valueT(0.055854267289647737622) * s8r;
		s15i = valueT(0.055854267289647737622) * s8i;
		s16r = valueT(-1.1666666666666666667) * r100;
		s16i = valueT(-1.1666666666666666667) * i100;
		s17r = valueT(-0.79015646852540019719) * s9r;
		s17i = valueT(-0.79015646852540019719) * s9i;
		s18r = valueT(0.87484229096165655223) * s13i;
		s18i = valueT(-0.87484229096165655223) * s13r;
		pReal[0 * stride] = r109;
		pImag[0 * stride] = i109;
		s19r = r109 + s16r;
		s19i = i109 + s16i;
		s20r = s11r + s18r;
		s20i = s11i + s18i;
		s21r = s14r + s18r;
		s21i = s14i + s18i;
		r202 = s17r + s19r - s10r;
		i202 = s17i + s19i - s10i;
		r205 = s10r + s15r + s19r;
		i205 = s10i + s15i + s19i;
		s22r = s15r + s17r - s19r;
		s22i = s15i + s17i - s19i;
		r193 = s20r - s12r;
		i193 = s20i - s12i;
		r196 = s21r - s12r;
		i196 = s21i - s12i;
		s23r = s12r + s20r + s21r;
		s23i = s12i + s20i + s21i;
		s24r = s23r - s22r;
		s24i = s23i - s22i;
		r220 = s22r + s23r;
		i220 = s22i + s23i;
		r237 = r216 + s24r;
		i237 = i216 + s24i;
		pReal[9 * stride] = s24r;
		pImag[9 * stride] = s24i;
	}
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i, s5r, s5i;
		valueT s6r, s6i, s7r, s7i, s8r, s8i, s9r, s9i, s10r, s10i;
		valueT s11r, s11i, s12r, s12i, s13r, s13i, s14r, s14i, s15r, s15i;
		valueT s16r, s16i, s17r, s17i, s18r, s18i, s19r, s19i, s20r, s20i;
		valueT s21r, s21i, s22r, s22i, s23r, s23i, s24r, s24i, s25r, s25i;
		valueT s26r, s26i, s27r, s27i, s28r, s28i, s29r, s29i, s30r, s30i;
		s1r = r26 - r32;
		s1i = i26 - i32;
		s2r = r26 + r32;
		s2i = i26 + i32;
		s3r = r24 - r27;
		s3i = i24 - i27;
		s4r = r24 + r27;
		s4i = i24 + i27;
		s5r = r23 - r35;
		s5i = i23 - i35;
		s6r = r35 + r23;
		s6i = i35 + i23;
		s7r = s2r + s4r;
		s7i = s2i + s4i;
		s8r = s3r - s1r - s5r;
		s8i = s3i - s1i - s5i;
		s9r = s1r - s5r;
		s9i = s1i - s5i;
		s10r = s3r + s5r;
		s10i = s3i + s5i;
		s11r = s2r + s6r - s4r;
		s11i = s2i + s6i - s4i;
		s12r = s2r - s6r;
		s12i = s2i - s6i;
		s13r = s4r + s6r;
		s13i = s4i + s6i;
		s14r = valueT(-0.63592436032499464686) * s7i;
		s14i = valueT(0.63592436032499464686) * s7r;
		s15r = valueT(-0.38188130791298666722) * s8r;
		s15i = valueT(-0.38188130791298666722) * s8i;
		s16r = valueT(-1.0528402656605470886) * s9r;
		s16i = valueT(-1.0528402656605470886) * s9i;
		s17r = s9r - s10r;
		s17i = s9i - s10i;
		s18r = valueT(1.2200666791727688395) * s10r;
		s18i = valueT(1.2200666791727688395) * s10i;
		s19r = r29 + s11r;
		s19i = i29 + s11i;
		s20r = valueT(1.0103629710818450879) * s11i;
		s20i = valueT(-1.0103629710818450879) * s11r;
		s21r = valueT(-0.048371214382601145551) * s12i;
		s21i = valueT(0.048371214382601145551) * s12r;
		s22r = valueT(-0.68429557470759579241) * s13i;
		s22i = valueT(0.68429557470759579241) * s13r;
		s23r = valueT(0.75763564827777197604) * s17r;
		s23i = valueT(0.75763564827777197604) * s17i;
		s24r = valueT(-0.86602540378443864676) * s19i;
		s24i = valueT(0.86602540378443864676) * s19r;
		s25r = s16r + s23r;
		s25i = s16i + s23i;
		s26r = s18r + s23r;
		s26i = s18i + s23i;
		s27r = s20r + s24r;
		s27i = s20i + s24i;
		r191 = s25r - s15r;
		i191 = s25i - s15i;
		r189 = s15r - s26r;
		i189 = s15i - s26i;
		s28r = s15r + s25r + s26r;
		s28i = s15i + s25i + s26i;
		r197 = s14r - s22r - s27r;
		i197 = s14i - s22i - s27i;
		r200 = s14r + s21r + s27r;
		i200 = s14i + s21i + s27i;
		s29r = s21r + s22r - s27r;
		s29i = s21i + s22i - s27i;
		pReal[14 * stride] = r243 - s24r;
		pImag[14 * stride] = i243 - s24i;
		pReal[7 * stride] = r243 + s24r;
		pImag[7 * stride] = i243 + s24i;
		s30r = s28r - s29r;
		s30i = s28i - s29i;
		r213 = s28r + s29r;
		i213 = s28i + s29i;
		pReal[2 * stride] = r237 - s30r;
		pImag[2 * stride] = i237 - s30i;
		pReal[16 * stride] = r237 + s30r;
		pImag[16 * stride] = i237 + s30i;
	}
	{
		valueT s1r, s1i;
		s1r = r225 - r220;
		s1i = i225 - i220;
		pReal[12 * stride] = -r220;
		pImag[12 * stride] = -i220;
		pReal[19 * stride] = s1r - r213;
		pImag[19 * stride] = s1i - i213;
		pReal[5 * stride] = r213 + s1r;
		pImag[5 * stride] = i213 + s1i;
	}
	r221 = r200 - r191;
	i221 = i200 - i191;
	r212 = r191 + r200;
	i212 = i191 + i200;
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i;
		r228 = r207 - r198;
		i228 = i207 - i198;
		s1r = r207 + r198;
		s1i = i207 + i198;
		r226 = r205 - r193;
		i226 = i205 - i193;
		s2r = r205 + r193;
		s2i = i205 + i193;
		s3r = s1r + s2r;
		s3i = s1i + s2i;
		pReal[6 * stride] = s2r;
		pImag[6 * stride] = s2i;
		pReal[20 * stride] = s3r - r212;
		pImag[20 * stride] = s3i - i212;
		pReal[13 * stride] = r212 + s3r;
		pImag[13 * stride] = i212 + s3i;
	}
	r249 = r228 + r226;
	i249 = i228 + i226;
	pReal[15 * stride] = r226;
	pImag[15 * stride] = i226;
	pReal[8 * stride] = r249 - r221;
	pImag[8 * stride] = i249 - i221;
	pReal[1 * stride] = r221 + r249;
	pImag[1 * stride] = i221 + i249;
	r210 = r189 - r197;
	i210 = i189 - i197;
	r218 = r189 + r197;
	i218 = i189 + i197;
	{
		valueT s1r, s1i, s2r, s2i, s3r, s3i;
		r224 = r203 - r206;
		i224 = i203 - i206;
		s1r = r206 + r203;
		s1i = i206 + i203;
		r217 = r196 - r202;
		i217 = i196 - i202;
		s2r = r202 + r196;
		s2i = i202 + i196;
		s3r = s1r - s2r;
		s3i = s1i - s2i;
		pReal[3 * stride] = s2r;
		pImag[3 * stride] = s2i;
		pReal[10 * stride] = -r218 - s3r;
		pImag[10 * stride] = -i218 - s3i;
		pReal[17 * stride] = r218 - s3r;
		pImag[17 * stride] = i218 - s3i;
	}
	r245 = r224 - r217;
	i245 = i224 - i217;
	pReal[18 * stride] = -r217;
	pImag[18 * stride] = -i217;
	pReal[11 * stride] = r245 - r210;
	pImag[11 * stride] = i245 - i210;
	pReal[4 * stride] = r210 + r245;
	pImag[4 * stride] = i210 + i245;
}

template<> void StandardModule<float, 21>::Compute(float *pReal, float *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

template<> void StandardModule<double, 21>::Compute(double *pReal, double *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const
{
	ComputeCore(mPhasors, pReal, pImag, stride, twiddleStart, twiddleIncrement);
}

}
}
