#include "BankAccount.h"

BankAccount::BankAccount() : BankAccount(0)
{
}

BankAccount::BankAccount(long double balance) : _balance(balance)
{
}

long double BankAccount::getBalance()
{
	return this->_balance;
}

void BankAccount::setBalance(long double money)
{
	this->_balance = money;
}
