#pragma once
#include "PrimeNumberResult.h"
#include <math.h>

namespace NumberProcessorFramework
{
	class PrimeNumberFinder
	{
	public:
		PrimeNumberFinder();
		PrimeNumberResult & isPrimeNumber(int number);
	};
}