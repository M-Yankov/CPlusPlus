#pragma once
#include <string>

class PrimeFinder
{
public:
	PrimeFinder(std::string newName);
	std::string name;
	unsigned long long findPrimeNumber(unsigned long long startFrom);
};

