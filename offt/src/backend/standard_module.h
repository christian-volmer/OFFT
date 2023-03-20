
//          Copyright Christian Volmer 2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "module_base.h"
#include <memory>

namespace offt {
namespace backend {

template<typename valueT, std::size_t N> 
class StandardModule : public ModuleBase<valueT> {

private:

	StandardModule(Phasors<valueT> const &phasors, std::size_t remainingLength, std::size_t twiddleStep) :
		ModuleBase<valueT>(phasors, N, remainingLength, twiddleStep)
	{
	}

public:

	using ModuleBase<valueT>::mLength;

	static std::unique_ptr<ModuleBase<valueT>> Construct(Phasors<valueT> const &phasors, std::size_t remainingLength, std::size_t twiddleStep)
	{
		return std::unique_ptr<ModuleBase<valueT>>(new StandardModule<valueT, N>(phasors, remainingLength, twiddleStep));
	}

	virtual std::size_t Prepare(Storage<valueT> &) override
	{
		return 0;
	}

	virtual void SetTemp(valueT *) override
	{
	}

	virtual void Compute(valueT *pReal, valueT *pImag, std::ptrdiff_t stride, std::size_t twiddleStart, std::size_t twiddleIncrement) const override;
};

}
}