
//          Copyright Christian Volmer 2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "module_base.h"
#include "storage.h"

#include <memory>
#include <vector>

namespace offt {
namespace backend {

using std::ptrdiff_t;
using std::size_t;

template<typename valueT>
class Program {

private:

	class Impl;
	std::unique_ptr<Impl> mpImpl;

public:

	Program();
	~Program();

	void Prepare(Storage<valueT> &storage, size_t length);

	size_t GetLength() const;

	size_t GetTempRequirement() const;
	void SetTemp(valueT *pTemp);

	void ExecuteInPlaceOutOfOrderTime(valueT *pReal, valueT *pImag, ptrdiff_t stride) const;
	void ExecuteInPlaceOutOfOrderFrequency(valueT *pReal, valueT *pImag, ptrdiff_t stride) const;
	void ExecuteOutOfPlaceInOrder(valueT *pDestReal, valueT *pDestImag, ptrdiff_t destStride, valueT const *pSrcReal, valueT const *pSrcImag, ptrdiff_t srcStride) const;
};

}
}
