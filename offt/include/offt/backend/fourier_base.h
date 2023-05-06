
//          Copyright Christian Volmer 2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "../fourier_parameters.h"

#include <complex>
#include <memory>

namespace offt {
namespace backend {

using std::ptrdiff_t;
using std::size_t;

template<typename valueT>
class FourierBase {

	class Impl;
	std::unique_ptr<Impl> mpImpl;

public:

	using realT = valueT;
	using complexT = std::complex<valueT>;

	FourierBase(size_t const *dimensions, size_t depth, FourierParameters const &fourierParameters = FourierParameters::Default);
	~FourierBase();

	size_t GetDepth() const;
	size_t const *GetDimensions() const;

	void EnsureTemp() const;
	void ReleaseTemp() const;

	void Transform(complexT *destination, ptrdiff_t const *destinationStrides, complexT const *source, ptrdiff_t const *sourceStrides) const;
	void InverseTransform(complexT *destination, ptrdiff_t const *destinationStrides, complexT const *source, ptrdiff_t const *sourceStrides) const;
};

}
}
