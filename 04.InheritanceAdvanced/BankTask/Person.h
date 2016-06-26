#pragma once
#include "BankAccount.h"
#include <string>

class Person
{
public:
	Person(std::string personName);
	virtual long double getBalance();
protected:
	BankAccount bankAccount;
	std::string name;

	friend class Woman;
};

