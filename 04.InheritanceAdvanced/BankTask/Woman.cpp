#include "Woman.h"

Woman::Woman(std::string name, double money) : bankAccount(money), Person(name)
{
}

// copy constructor
Woman::Woman(std::string name, Men & men) : Person(name)
{
	this->bankAccount = BankAccount(men.bankAccount.getBalance());
	men.bankAccount.setBalance(0);
}

void Woman::wasteMoney()
{
	this->bankAccount.setBalance(0);
}

long double Woman::getBalance()
{
	return this->bankAccount.getBalance();
}
