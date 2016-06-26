#pragma once
#include "Men.h"

class Woman : public Person
{
private:
	BankAccount bankAccount;
public:
	Woman(std::string name, double money);
	Woman(std::string name, Men & man);
	void wasteMoney();

	long double getBalance() override;
};

