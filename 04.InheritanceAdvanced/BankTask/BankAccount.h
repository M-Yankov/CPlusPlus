#pragma once

class BankAccount
{
private:
	 long double _balance;
public:
	BankAccount();
	BankAccount(long double balance);
	long double getBalance();
	void setBalance(long double money);
};

