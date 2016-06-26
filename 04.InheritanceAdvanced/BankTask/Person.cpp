#include "Person.h"

#include <string>

Person::Person(std::string personName) : name(personName)
{
}

long double Person::getBalance()
{
	return this->bankAccount.getBalance();
}
