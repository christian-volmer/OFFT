
//          Copyright Christian Volmer 2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "phasors.h"
#include "storage.h"

namespace offt {
namespace backend {

using std::ptrdiff_t;
using std::size_t;

template<typename valueT>
class ModuleBase {

protected:

	ModuleBase(Phasors<valueT> const &phasors, size_t length, size_t remainingLength, size_t twiddleStep) :
		mPhasors(phasors),
		mLength(length),
		mRemainingLength(remainingLength),
		mTwiddleStep(twiddleStep)
	{
	}

public:

	Phasors<valueT> const &mPhasors;
	size_t const mLength;
	size_t const mRemainingLength;
	size_t const mTwiddleStep;

	virtual ~ModuleBase() { }

	virtual size_t Prepare(Storage<valueT> &fourierStorage) = 0;
	virtual void SetTemp(valueT *pTemp) = 0;

	virtual void Compute(valueT *pReal, valueT *pImag, ptrdiff_t stride, size_t twiddleStart, size_t twiddleIncrement) const = 0;

	void ComputeLoop(
		valueT *pReal, valueT *pImag, ptrdiff_t step,
		size_t twiddleStep, size_t twiddleIncrement, size_t twiddleIncrementStep) const;

	ModuleBase(ModuleBase const &) = delete;
	ModuleBase(ModuleBase &&) = delete;

	void operator=(ModuleBase const &) = delete;
	void operator=(ModuleBase &&) = delete;
};

}
}
