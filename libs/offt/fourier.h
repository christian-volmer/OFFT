
//          Copyright Christian Volmer 2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

/*

'fourier.h' is the main header file for the OpenFFT library.
It provides the 'Fourier' class in the 'offt' namespace, which
is the primary interface for performing one- and multi-
dimensional Fast Fourier Transforms and the corresponding 
inverses.

*/

#pragma once

#include "backend/fourier_base.h"

namespace offt {

// The 'Fourier' template class is the primary interface for
// performing one- and multi-dimensional fast Fourier transforms.
//
// Template parameters:
//    'valueT'   floating point type to use: 'float' or 'double'
//    'depth'    array depth: specify '1' for one-dimensional 
//               transforms, '2' for two-dimensional, and so on.
template<typename valueT = double, std::size_t depth = 1>
class Fourier : protected backend::FourierBase<valueT> {

	static_assert(depth >= 1, "offt::Fourier template class: the 'depth' parameter must be greater than or equal to '1'.");
	static_assert(std::is_same<valueT, double>::value || std::is_same<valueT, float>::value, "offt::Fourier template class: the 'valueT' parameter must be either 'float' or 'double'.");

private:

	using FourierBase = backend::FourierBase<valueT>;

public:

	// Alias for the underlying floating point type
	using realT = valueT;

	// Alias for the complex value type
	using complexT = std::complex<valueT>;

	// Constructor parameters:
	//    'dimensions'          array of the dimensions of the fast Fourier transform.
	//    'fourierParameters'   Fourier parameters that specify the convention to use for
	//                          the scaling and the sign of the imaginary part of the 
	//                          transform result.
	Fourier(std::size_t const (&dimensions)[depth], FourierParameters const &fourierParameters = FourierParameters::Default) :
		FourierBase(dimensions, depth, fourierParameters)
	{
	}

	~Fourier() = default;

	// Returns the depth (i.e., the number of dimensions) of the transform, which is 
	// equal to the 'depth' template parameter.
	std::size_t constexpr GetDepth() const
	{
		return depth;
	}

	// Returns a pointer to the dimensions of the transform. The array points to 
	// has length equal to the 'depth' template parameter.
	std::size_t const *GetDimensions() const
	{
		return FourierBase::GetDimensions();
	}

	// Returns a reference to a copy of the Fourier parameters passed to the 
	// constructor.
	FourierParameters const &GetFourierParameters() const
	{
		return FourierBase::GetFourierParameters();
	}

	// Ensures that temporary memory has been allocated as required for the transform.
	// Called automatically by 'Transform()' and 'InverseTransform()' methods.
	void EnsureTemp() const
	{
		FourierBase::EnsureTemp();
	}

	// Frees any temporary memory that has been allocated previously for the transform.
	void ReleaseTemp() const
	{
		FourierBase::ReleaseTemp();
	}

	void Transform(complexT *destination, std::ptrdiff_t const (&destinationStrides)[depth], complexT const *source, std::ptrdiff_t const (&sourceStrides)[depth]) const
	{
		FourierBase::Transform(destination, destinationStrides, source, sourceStrides);
	}

	void InverseTransform(complexT *destination, std::ptrdiff_t const (&destinationStrides)[depth], complexT const *source, std::ptrdiff_t const (&sourceStrides)[depth]) const
	{
		FourierBase::InverseTransform(destination, destinationStrides, source, sourceStrides);
	}
};

// Specialisation for one-dimensional transforms.
template<typename valueT>
class Fourier<valueT, 1> : protected backend::FourierBase<valueT> {

	static_assert(std::is_same<valueT, double>::value || std::is_same<valueT, float>::value, "offt::Fourier template class: the 'valueT' parameter must be either 'float' or 'double'.");

private:

	using FourierBase = backend::FourierBase<valueT>;

public:

	using realT = valueT;
	using complexT = std::complex<valueT>;

	Fourier(size_t length, FourierParameters const &fourierParameters = FourierParameters::Default) :
		FourierBase(&length, 1, fourierParameters)
	{
	}

	~Fourier() = default;

	std::size_t GetDepth() const
	{
		return 1;
	}

	std::size_t const *GetDimensions() const
	{
		return FourierBase::GetDimensions();
	}

	FourierParameters const &GetFourierParameters() const
	{
		return FourierBase::GetFourierParameters();
	}

	void EnsureTemp() const
	{
		FourierBase::EnsureTemp();
	}

	void ReleaseTemp() const
	{
		FourierBase::ReleaseTemp();
	}

	void Transform(complexT *destination, ptrdiff_t destinationStride, complexT const *source, ptrdiff_t sourceStride) const
	{
		FourierBase::Transform(destination, &destinationStride, source, &sourceStride);
	}

	void InverseTransform(complexT *destination, ptrdiff_t destinationStride, complexT const *source, ptrdiff_t sourceStride) const
	{
		FourierBase::InverseTransform(destination, &destinationStride, source, &sourceStride);
	}

	std::size_t GetLength() const
	{
		return FourierBase::GetDimensions()[0];
	}
};

}
