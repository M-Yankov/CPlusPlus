#include <iostream>
#include <string>
#include <ctype.h>

#include "Store.h"

// OK, to clear all misunderstandings 
// I am not good in English so - I assume that:
// change means - "ресто" in my native language. This is for step when "G" is pressed.
// Please tell me if I am wrong.

int main()
{
	std::string input;
	Store store = Store();

	std::cout << "Enter code: ";
	std::cin >> input;

	if (input.length() == 10)
	{
		long codeKey = std::stol(input);

		if (store.itemExists(codeKey))
		{
			long double valueToAdd = store.getValueFromItem(codeKey);
			store << valueToAdd; 
			std::cout << "Value added to total value" << std::endl;
		}
		else
		{
			std::cout << "Item cannot be found! " << std::endl;
		}
	}
	else if (input == "c" || input == "C")
	{
		store.setTotalValue(0);
		std::cout << "Total value is cleared!" << std::endl;
	}
	else if (input == "t" || input == "T")
	{
		std::cout << store.getTotalValue() << std::endl;
	}
	else if (input == "g" || input == "G")
	{
		std::cout << "Enter amount: ";
		std::string amountInput;
		std::cin >> amountInput;
		double amount = std::stod(amountInput);

		long double total = store.getTotalValue();
		while (amount < total)
		{
			std::cout << "Enter amount bigger than " << total<< ": ";
			std::cin >> amountInput;
			amount = std::stod(amountInput);
		}

		char buffer[50];
		store.given = amount;
		std::sprintf(buffer, "The change is %2.2f leva.", amount - total);
		std::cout << buffer << std::endl;
	}
	else if (input == "s" || input == "S")
	{
		std::cout << store.toString() << std::endl;
	}
	else if (input == "p" || input == "P")
	{
		char * code;
		std::cout << "Enter 10-symbol-length product code: ";
		std::cin >> code;

		long codeReal = std::stol(code); 
		if (store.itemExists(codeReal))
		{
			std::cout << "Enter new price: ";
			std::string newPrice;
			std::cin >> newPrice;
			double price = std::stod(newPrice);
		}
	}

	return 0;
}