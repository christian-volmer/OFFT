
//          Copyright Christian Volmer 2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "module_base.h"
#include "program.h"

namespace offt {
namespace backend {

template<typename valueT>
class RaderModule : public ModuleBase<valueT> {

private:

	valueT *mpTemp;

	Program<valueT> mConvolutionProgram;
	RaderData<valueT> const *mRaderData;

public:

	using ModuleBase<valueT>::mPhasors;
	using ModuleBase<valueT>::mLength;

	RaderModule(Phasors<valueT> const &phasors, std::size_t length, std::size_t remainingLength, std::size_t twiddleStep);

	virtual std::size_t Prepare(Storage<valueT> &storage) override;
	virtual void SetTemp(valueT *pTemp) override;

	virtual void Compute(valueT *pReal, valueT *pImag, std::ptrdiff_t stride, std::size_t twiddleStart, std::size_t twiddleIncrement) const override;
};


}
}