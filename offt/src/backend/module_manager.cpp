
//          Copyright Christian Volmer 2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include "module_manager.h"

#include "rader_module.h"
#include "standard_module.h"
#include <offt/math/factor_integer.h>

#include <algorithm>
#include <cassert>
#include <iostream>

namespace offt {
namespace backend {

using std::ptrdiff_t;
using std::size_t;

template class ModuleManager<float>;
template class ModuleManager<double>;

template<typename valueT>
template<size_t N>
void ModuleManager<valueT>::RegisterStandardModule()
{
	if (mStandardModules.count(N) > 0)
		throw std::invalid_argument("ModuleManager::RegisterStandardModule(): a module of given size 'N' has already been registered.");

	mStandardModules.emplace(N, std::unique_ptr<StandardModuleFactoryBase<valueT> const>(new StandardModuleFactory<valueT, N>()));
}

template<typename valueT>
ModuleManager<valueT>::ModuleManager() :
	mStandardModules()
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

	// RegisterStandardModule<64>();
	// RegisterStandardModule<128>();
}

template<typename valueT>
std::unique_ptr<ModuleBase<valueT>> ModuleManager<valueT>::ConstructModule(Phasors<valueT> const &phasors, size_t length, size_t remainingLength, size_t twiddleStep) const
{
	if (!(length >= 2))
		throw std::invalid_argument("ModuleManager::ConstructModule(): parameter 'length' must be greater than or equal to '2'.");

	auto found = mStandardModules.find(length);
	if (found != mStandardModules.end())
		return found->second->Construct(phasors, remainingLength, twiddleStep);

	return std::unique_ptr<ModuleBase<valueT>>(new RaderModule<valueT>(phasors, length, remainingLength, twiddleStep));
}

template<typename valueT>
size_t ModuleManager<valueT>::CostForLength(size_t length) const
{
	/*
		//size_t bestFactor = 0;
		size_t bestCost = 0;
		for (auto const &module : mStandardModules) {

			size_t moduleFactor = module.first;

			if (length % moduleFactor == 0) {

				size_t remainingLength = length / moduleFactor;
				size_t remainingCost = CostForLength(remainingLength);

				StandardModuleComplexity complexity = module.second->GetComplexity();
				size_t moduleCost = complexity.AdditionCount + complexity.MultiplicationCount;

				size_t thisCost = moduleCost * remainingLength + moduleFactor * remainingCost;

				if (bestCost == 0 || thisCost < bestCost) {

					//bestFactor = moduleFactor;
					bestCost = thisCost;
				}
			}
		}
	*/

	return 4 * length;
}

template<typename valueT>
std::vector<size_t> ModuleManager<valueT>::Factorise(size_t length) const
{
	if (!(length >= 1))
		throw std::invalid_argument("ModuleManager::Factorise(): parameter 'length' must be greater than or equal to '1'.");

	std::vector<size_t> factors;

	/*

	// Attempt to predict runtime based on standard module complexity failed. 

	bool doingStandardModules = true;
	while (doingStandardModules) {

		doingStandardModules = false;
		size_t bestFactor = 0;
		double bestCost = 0;
		for (auto const &module : mStandardModules) {

			size_t moduleFactor = module.first;

			if (length % moduleFactor == 0) {

				size_t remainingLength = length / moduleFactor;
				double remainingCost = 20 * double(remainingLength) * std::log(double(remainingLength));

				StandardModuleComplexity complexity = module.second->GetComplexity();
				size_t moduleCost = complexity.AdditionCount + complexity.MultiplicationCount;

				double thisCost = moduleCost * remainingLength + moduleFactor * remainingCost;

				// std::cout << "Factor = " << moduleFactor << ": cost = " << thisCost << "\n";

				if (bestCost == 0 || thisCost < bestCost) {

					bestFactor = moduleFactor;
					bestCost = thisCost;
				}
			}
		}

		if (bestFactor != 0) {

			factors.push_back(bestFactor);
			length /= bestFactor;
			doingStandardModules = true;
		}
	}

	*/

	for (auto factorIt = mStandardModules.crbegin(); factorIt != mStandardModules.crend();) {

		if (length % factorIt->first == 0) {

			factors.push_back(factorIt->first);
			length /= factorIt->first;
		}
		else
			++factorIt;
	}

	/*

	// Equalising the list of standard factors sometimes helps, sometimes doesn't.
	// 25 20 2 ---> 10 10 10   improves
	// 32 32 32 32 4 ---> 16 16 16 32 32   degrades

	for (auto factor : factors)
		std::cout << " " << factor;

	std::cout << " ---> ";

	bool equalise = factors.size() >= 2;
	while (equalise) {

		equalise = false;
		std::sort(factors.begin(), factors.end());
		size_t &min = factors.front();
		size_t max = factors.back();

		for (size_t c : { 5, 4, 3, 2 }) {

			if (min * c < max) {

				for (auto it = std::next(factors.begin()); it != factors.end(); ++it) {

					if (*it % c == 0 && *it / c > min) {

						*it /= c;
						min *= c;
						equalise = true;
						break;
					}
				}
			}

			if (equalise)
				break;
		}
	}

	for (auto factor : factors)
		std::cout << factor << " ";

	std::cout << "\n";
	*/

	math::FactorInteger(length, [&factors](ptrdiff_t factor) {
		if (factor != 1)
			factors.push_back(static_cast<size_t>(factor));
	});

	std::sort(factors.begin(), factors.end());

	return factors;
}

}
}
