#include <iostream>
#include <ctime>
#include <thread>
#include <mutex>

#include "PrimeFinder.h"
#include "FibonacciFinder.h"

std::mutex mtx;
const char * format = "%s - %llu - %0.5f ms.\n";

void printResults(std::string text, unsigned long long number, float seconds);

void findPrimeNumbers(PrimeFinder & finder, unsigned long long maxNumber)
{
	unsigned long long primeNumber = 1;
	while (primeNumber < maxNumber)
	{
		clock_t startTime = std::clock();
		unsigned long long result = finder.findPrimeNumber(primeNumber);

		// catch overflow - tell me if you know a better solution.
		if (primeNumber > result)
		{
			break;
		}

		primeNumber = result;
		clock_t endTime = std::clock();

		float timeDiferenceMs = endTime - startTime;

		// it prints 0 - if the results is 0.00000000 
		printResults(finder.name, primeNumber, timeDiferenceMs);
		primeNumber++;
	}
}

void findFibonacciNumbers(FibonacciFinder & finder, unsigned long long maxNumber)
{
	// first two numbers are 1, 1,
	unsigned long long prePrevNumber = 1;
	unsigned long long prevNumber = 1;

	printResults(finder.name, prePrevNumber, 0);
	printResults(finder.name, prevNumber, 0);

	while (prevNumber < maxNumber)
	{
		std::clock_t startTime = std::clock();
		unsigned long long next = finder.findNextNumber(prePrevNumber, prevNumber);
		std::clock_t endTime = std::clock();

		// catch overflow
		if (prePrevNumber > next || prevNumber > next)
		{
			break;
		}

		float timeDiffMs = endTime - startTime;

		printResults(finder.name, next, timeDiffMs);
		prePrevNumber = prevNumber;
		prevNumber = next;
	}
}

void printResults(std::string text, unsigned long long number, float seconds)
{
	// this is critical resource.
	mtx.lock();
	std::printf(format, text.c_str(), number, seconds);
	mtx.unlock();
}

int main()
{
	PrimeFinder primeNumberFinder = PrimeFinder("Prime:");
	FibonacciFinder fibonacciNumberFinder = FibonacciFinder("Fibonacci:");

	// I am too lazy to wait for ULLONG_MAX to be calculated
	const long primeNumbersMaxRange = 20000;
	std::thread primeNumbersThread = std::thread(findPrimeNumbers, primeNumberFinder, primeNumbersMaxRange);
	std::thread fibonacciNumbersThread = std::thread(findFibonacciNumbers, fibonacciNumberFinder, ULLONG_MAX);

	primeNumbersThread.join();
	fibonacciNumbersThread.join();
}