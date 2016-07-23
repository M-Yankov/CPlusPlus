#include "NumberProcessor.h"

using namespace NumberProcessorFramework;

NumberProcessor::NumberProcessor()
	:finder(PrimeNumberFinder())
{
}

NumberProcessor::NumberProcessor(PrimeNumberFinder & primeNumberfinder)
	: finder(primeNumberfinder)
{
}

std::vector<PrimeNumberResult> NumberProcessorFramework::NumberProcessor::proccessNumbers(
	std::vector<int>::iterator begin, 
	std::vector<int>::iterator end)
{
	std::vector<PrimeNumberResult> results;

	while (begin != end)
	{
		PrimeNumberResult result = finder.isPrimeNumber(*begin);
		results.push_back(result);
		begin++;
	}

	return results;
}
