
//          Copyright Christian Volmer 2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "module_base.h"
#include "phasors.h"
#include <map>
#include <memory>

namespace offt {
namespace backend {

template<typename valueT>
class ModuleManager {

private:

	std::map<std::size_t, std::unique_ptr<ModuleBase<valueT>>(*)(Phasors<valueT> const &, std::size_t, std::size_t)> mStandardModules;

	template<std::size_t N>
	void RegisterStandardModule();

public:

	ModuleManager();

	std::unique_ptr<ModuleBase<valueT>> ConstructModule(Phasors<valueT> const &phasors, std::size_t length, std::size_t remainingLength, std::size_t twiddleStep) const;
	std::vector<std::size_t> Factorise(std::size_t length) const;
};


}
}
