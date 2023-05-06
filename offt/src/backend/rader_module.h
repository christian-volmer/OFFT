
//          Copyright Christian Volmer 2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "module_base.h"
#include "program.h"

namespace offt {
namespace backend {

using std::size_t;
using std::ptrdiff_t;

template<typename valueT>
class RaderModule : public ModuleBase<valueT> {

private:

	valueT *mpTemp;

	Program<valueT> mConvolutionProgram;
	RaderData<valueT> const *mRaderData;

public:

	using ModuleBase<valueT>::mPhasors;
	using ModuleBase<valueT>::mLength;

	RaderModule(Phasors<valueT> const &phasors, size_t length, size_t remainingLength, size_t twiddleStep);

	virtual size_t Prepare(Storage<valueT> &storage) override;
	virtual void SetTemp(valueT *pTemp) override;

	virtual void Compute(valueT *pReal, valueT *pImag, ptrdiff_t stride, valueT const *twiddles) const override;
};


}
}