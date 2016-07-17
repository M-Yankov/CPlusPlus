#include "FibonacciFinder.h"

FibonacciFinder::FibonacciFinder(std::string newName) : name(newName)
{
}

unsigned long long FibonacciFinder::findNextNumber(unsigned long long prePreviousMember, unsigned long long previousMember)
{
	return prePreviousMember + previousMember;
}
