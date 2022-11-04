
//          Copyright Christian Volmer 2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "phasors.h"
#include "storage.h"

namespace offt {
namespace backend {

template<typename valueT>
struct ModuleBase {

protected:

	ModuleBase(Phasors<valueT> const &phasors, std::size_t length, std::size_t remainingLength, std::size_t twiddleStep) :
		mPhasors(phasors),
		mLength(length),
		mRemainingLength(remainingLength),
		mTwiddleStep(twiddleStep)
	{
	}

public:

	Phasors<valueT> const &mPhasors;
	std::size_t mLength;
	std::size_t mRemainingLength;
	std::size_t mTwiddleStep;

	virtual ~ModuleBase() {}

	virtual std::size_t Prepare(Storage<valueT> &fourierStorage) = 0;
	virtual void SetTemp(valueT *pTemp) = 0;

	virtual void Compute(valueT *pReal, valueT *pImag, std::ptrdiff_t stride, std::size_t twiddleStart, std::size_t twiddleIncrement) const = 0;

	ModuleBase(ModuleBase const &) = delete;
	ModuleBase(ModuleBase &&) = delete;

	void operator =(ModuleBase const &) = delete;
	void operator =(ModuleBase &&) = delete;
};

}
}
