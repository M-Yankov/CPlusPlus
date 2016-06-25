#include <iostream>
#include <string>
#include <ctype.h>

#include "Store.h"
#include <vector>

// OK, to clear all misunderstandings 
// I am not good in English so - I assume that:
// change means - "ресто" in my native language. This is for step when "G" is pressed.
// Please tell me if I am wrong.

// check Store constructor to see item codes;
void menu();

int main()
{
	std::string input;
	Store store = Store();

	menu();


	while (input != "exit")
	{
		std::cout << ">";
		std::cin >> input;

		if (input.length() == 10)
		{
			long codeKey = std::stol(input);

			if (store.itemExists(codeKey))
			{
				long double valueToAdd = store.getValueFromItem(codeKey);
				store << valueToAdd;
				std::cout << "Price added to total value" << std::endl;
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
				std::cout << "Enter amount bigger than " << total << ": ";
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
			std::string code;
			std::cout << "Enter 10-symbol-length product code: ";
			std::cin >> code;

			long codeReal = std::stol(code);
			if (store.itemExists(codeReal))
			{
				std::cout << "Enter new price: ";
				std::string newPrice;
				std::cin >> newPrice;
				double price = std::stod(newPrice);
				store.changeItemPrice(codeReal, price);
				std::cout << "Price changed." << std::endl;

			}
		}
		else if (input == "m" || input == "M")
		{
			std::cout << store.printItems() << std::endl;
		}
		else
		{
			std::cout << "Not a command!" << std::endl;
		}

		std::cout << std::endl;
	}

	return 0;
}

void menu()
{
	std::cout << "Type a ten digit code's product to add it's value to total. " << std::endl
		<< "Type \"C\" to clear total." << std::endl
		<< "Type \"T\" to display total." << std::endl
		<< "Type \"G\" to calculate change." << std::endl
		<< "Type \"P\" to change product price." << std::endl
		<< "Type \"S\" to print customer information." << std::endl
		<< "Type \"M\" to print menu products." << std::endl
		<< "Type \"exit\" to exit program." <<std::endl;
}