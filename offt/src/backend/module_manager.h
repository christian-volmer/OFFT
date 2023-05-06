
//          Copyright Christian Volmer 2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "standard_module.h"
#include <map>
#include <memory>

namespace offt {
namespace backend {

using std::ptrdiff_t;
using std::size_t;

template<typename valueT>
class ModuleManager {

private:

	std::map<size_t, std::unique_ptr<StandardModuleFactoryBase<valueT> const>> mStandardModules;

	template<size_t N>
	void RegisterStandardModule();

	size_t CostForLength(size_t length) const;

public:

	ModuleManager();

	std::unique_ptr<ModuleBase<valueT>> ConstructModule(Phasors<valueT> const &phasors, size_t length, size_t remainingLength, size_t twiddleStep) const;
	std::vector<size_t> Factorise(size_t length) const;
};

}
}
