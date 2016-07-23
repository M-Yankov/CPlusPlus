#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "NumberProcessor.h"

using namespace NumberProcessorFramework;

std::vector<int> &split(const std::string &s, char delim, std::vector<int> &elems);
std::vector<int> split(const std::string &s, char delim);

int main() 
{
	NumberProcessor numberProcess = NumberProcessor();
	std::string stringNumbers;
	std::getline(std::cin, stringNumbers);
	std::vector<int> numbersFromInput = split(stringNumbers, ' ');

	std::vector<PrimeNumberResult> results = numberProcess.proccessNumbers(numbersFromInput.begin(), numbersFromInput.end()); 

	for (PrimeNumberResult result : results)
	{
		std::printf("Number %d is %s smallest divisor: %d\n" , result.numberToDevide, result.isPrime ? "prime" : "not prime", result.smallestDivisor);
	}

	return 0;
}

std::vector<int> &split(const std::string &s, char delim, std::vector<int> &elems)
{
	std::stringstream ss(s);
	std::string item;
	while (getline(ss, item, delim))
	{
		int number = std::stoi(item);
		elems.push_back(number);
	}
	return elems;
}


std::vector<int> split(const std::string &s, char delim)
{
	std::vector<int> elems;
	split(s, delim, elems);
	return elems;
}