
//          Copyright Christian Volmer 2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include "module_manager.h"

#include "rader_module.h"
#include "standard_module.h"
#include <offt/math/factor_integer.h>

#include <cassert>
#include <algorithm>

namespace offt {
namespace backend {

using std::size_t;
using std::ptrdiff_t;

template class ModuleManager<float>;
template class ModuleManager<double>;

template<typename valueT>
template<size_t N>
void ModuleManager<valueT>::RegisterStandardModule()
{
	if (mStandardModules.count(N) > 0)
		throw std::invalid_argument("ModuleManager::RegisterStandardModule(): a module of given size 'N' has already been registered.");

	mStandardModules.emplace(N, StandardModule<valueT, N>::Construct);
}

template<typename valueT>
ModuleManager<valueT>::ModuleManager()
{
	RegisterStandardModule<2>();
	RegisterStandardModule<3>();
	RegisterStandardModule<4>();
	RegisterStandardModule<5>();
	RegisterStandardModule<6>();
	RegisterStandardModule<7>();
	RegisterStandardModule<8>();

	RegisterStandardModule<9>();
	RegisterStandardModule<10>();
	RegisterStandardModule<11>();
	RegisterStandardModule<12>();
	RegisterStandardModule<13>();
	RegisterStandardModule<14>();
	RegisterStandardModule<15>();
	RegisterStandardModule<16>();

	RegisterStandardModule<17>();
	RegisterStandardModule<18>();
	RegisterStandardModule<19>();
	RegisterStandardModule<20>();
	RegisterStandardModule<21>();
	RegisterStandardModule<22>();
	RegisterStandardModule<23>();
	RegisterStandardModule<24>();

	RegisterStandardModule<25>();
	RegisterStandardModule<26>();
	RegisterStandardModule<27>();
	RegisterStandardModule<28>();
	RegisterStandardModule<29>();
	RegisterStandardModule<30>();
	RegisterStandardModule<31>();
	RegisterStandardModule<32>();
}

template<typename valueT>
std::unique_ptr<ModuleBase<valueT>> ModuleManager<valueT>::ConstructModule(Phasors<valueT> const &phasors, size_t length, size_t remainingLength, size_t twiddleStep) const
{
	if (!(length >= 2))
		throw std::invalid_argument("ModuleManager::ConstructModule(): parameter 'length' must be greater than or equal to '2'.");
	
	auto found = mStandardModules.find(length);
	if (found != mStandardModules.end())
		return found->second(phasors, remainingLength, twiddleStep);

	return std::unique_ptr<ModuleBase<valueT>>(new RaderModule<valueT>(phasors, length, remainingLength, twiddleStep));
}

template<typename valueT>
std::vector<size_t> ModuleManager<valueT>::Factorise(size_t length) const
{
	if (!(length >= 1))
		throw std::invalid_argument("ModuleManager::Factorise(): parameter 'length' must be greater than or equal to '1'.");

	std::vector<size_t> factors;

	for (auto factorIt = mStandardModules.crbegin(); factorIt != mStandardModules.crend();) {

		if (length % factorIt->first == 0) {

			factors.push_back(factorIt->first);
			length /= factorIt->first;
		}
		else
			++factorIt;
	}

	math::FactorInteger(length, [&factors](ptrdiff_t factor) {

		if (factor != 1)
			factors.push_back(static_cast<size_t>(factor));
		});

	std::sort(factors.begin(), factors.end());

	return factors;
}

}
}
