#pragma once

// Man is already defined in the solution!
#include "BankAccount.h"
#include "Person.h"
#include <string>

class Men : public Person
{
public:
	Men(double money, std::string name);
};

