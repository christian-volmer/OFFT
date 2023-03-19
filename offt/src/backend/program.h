
//          Copyright Christian Volmer 2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "module_base.h"
#include "storage.h"

#include <vector>
#include <memory>

namespace offt {
namespace backend {

template<typename valueT>
class Program {

private:

	class Impl;
	std::unique_ptr<Impl> mpImpl;

public:

	Program();
	~Program();

	void Prepare(Storage<valueT> &storage, std::size_t length);

	std::size_t GetLength() const;

	std::size_t GetTempRequirement() const;
	void SetTemp(valueT *pTemp);

	void ExecuteInPlaceOutOfOrderTime(valueT *pReal, valueT *pImag, std::ptrdiff_t stride) const;
	void ExecuteInPlaceOutOfOrderFrequency(valueT *pReal, valueT *pImag, std::ptrdiff_t stride) const;
	void ExecuteOutOfPlaceInOrder(valueT *pDestReal, valueT *pDestImag, std::ptrdiff_t destStride, valueT const *pSrcReal, valueT const *pSrcImag, std::ptrdiff_t srcStride) const;
};

}
}
