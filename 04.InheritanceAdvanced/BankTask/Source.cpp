#include <iostream>

#include "Men.h"
#include "Woman.h"

int main()
{
	Men aPoorMan = Men(1900.500, "Tony");

	std::printf("before create woman. \nMan's balance: $%0.2f\n\n", aPoorMan.getBalance());

	Woman wife = Woman("Jane", aPoorMan);

	std::cout << "After women arrived:" << std::endl;
	// expect all to have 0.
	std::printf("Man's money: $%0.2f\n", aPoorMan.getBalance());
	std::printf("Wife's money: $%0.2f\n\n", wife.getBalance());

	std::cout << "After women wasted the money:" << std::endl;
	wife.wasteMoney();
	std::printf("Man's money: $%0.2f\n", aPoorMan.getBalance());
	std::printf("Wife's money: $%0.2f\n", wife.getBalance());
}