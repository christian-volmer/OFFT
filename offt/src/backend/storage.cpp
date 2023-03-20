
//          Copyright Christian Volmer 2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include "storage.h"

namespace offt {
namespace backend {

using std::size_t;
using std::ptrdiff_t;

template class Storage<float>;
template class Storage<double>;

template<typename valueT>
Storage<valueT>::Storage() :
	mPhasors(),
	mRaderData()
{
}

template<typename valueT>
Phasors<valueT> const &Storage<valueT>::GetPhasors(size_t length)
{
	auto found = mPhasors.find(length);
	if (found != mPhasors.end())
		return found->second;

	return mPhasors.emplace(length, length).first->second;
}

template<typename valueT>
RaderData<valueT> &Storage<valueT>::GetRaderData(size_t length)
{
	return mRaderData[length];
}

}
}
