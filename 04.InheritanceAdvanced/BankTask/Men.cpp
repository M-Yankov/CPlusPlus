#include "Men.h"

Men::Men(double money, std::string name) : Person(name)
{
	this->bankAccount = BankAccount(money);
}
