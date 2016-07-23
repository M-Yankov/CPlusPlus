#pragma once
namespace NumberProcessorFramework
{
	class PrimeNumberResult
	{
	public:
		bool isPrime;
		int smallestDivisor;
		int numberToDevide;
		PrimeNumberResult(bool isPrimeResult, int numberToDevide, int smallestDivisorInteger = 1);
	};
}

