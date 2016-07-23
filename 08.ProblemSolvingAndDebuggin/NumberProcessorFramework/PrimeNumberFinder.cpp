#include "PrimeNumberFinder.h"

using namespace NumberProcessorFramework;

PrimeNumberFinder::PrimeNumberFinder()
{
}

PrimeNumberResult & PrimeNumberFinder::isPrimeNumber(int number)
{
	int lastPossibleDivisor = sqrt(number);
	PrimeNumberResult & result = PrimeNumberResult(true, number, 1);

	for (int i = 2; i <= lastPossibleDivisor; i++)
	{
		if (number % i == 0)
		{
			result.isPrime = false;
			result.smallestDivisor = i;
			return result;
			/// return PrimeNu
			/// 	mberResult(false, number, i);
		}
	}

	// all numbers (except 0) are divisible by itself and 1.
	return result;
}
