#pragma once
#include "PrimeNumberFinder.h"
#include "PrimeNumberResult.h"
#include <vector>

namespace NumberProcessorFramework
{
	class NumberProcessor
	{
	private:
		PrimeNumberFinder finder;
	public:
		NumberProcessor();
		NumberProcessor(PrimeNumberFinder & primeNumberfinder);
		std::vector<PrimeNumberResult> proccessNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	};
}

