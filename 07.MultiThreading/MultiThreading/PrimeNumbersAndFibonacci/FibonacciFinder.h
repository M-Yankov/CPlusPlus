#pragma once
#include <string>

class FibonacciFinder
{
public:
	FibonacciFinder(std::string newName);
	std::string name; 
	unsigned long long findNextNumber(unsigned long long prePreviousMember, unsigned long long previousMember);
};

