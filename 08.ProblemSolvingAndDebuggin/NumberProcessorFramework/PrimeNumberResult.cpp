#include "PrimeNumberResult.h"

using namespace NumberProcessorFramework;

PrimeNumberResult::PrimeNumberResult(bool isPrimeResult,int numberForProcess, int smallestDivisorInteger)
	: isPrime(isPrimeResult), smallestDivisor(smallestDivisorInteger), numberToDevide(numberForProcess)
{
}
