// LearnedFunctions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int checkAge(unsigned short age)
{
	if (age < 14)
	{
		return 2;
	}
	else if (age < 18)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool containsLetter(string text, char letter)
{
	int length = text.length();
	
	// http://www.cplusplus.com/reference/string/string/find/
	size_t index = text.find(letter);
	
	// npos: http://www.cplusplus.com/reference/string/string/npos/
	// found
	if (index != std::string::npos)
	{
		return true;
	}

	return false;
}

// place functions above main() method. Visual Studio don't recognize them.
int main()
{
	unsigned short testAge = 17;
	cout << "Check age function: " << checkAge(testAge) << endl;
	
	// using printf() have easy formating options like %0.2 means 2 digits after decimal point 
	// reference http://www.cplusplus.com/reference/cstdio/printf/
	printf("printf() function: %0.2f\n", 3.141591);

	string line;
	
	// getline() have two arguments, first method to get user input and second variable. 
	// This function allows to read whole line from console while "cin" will read until first space 
	cout << "Write something: ";
	getline(cin, line);

	// and some function from tasks 
	bool isTextContainsLetterO = containsLetter(line, 'o');
	if (isTextContainsLetterO)
	{
		cout << "Your text contains letter 'o'" << endl;
	}
	else
	{
		cout << "Your text DOESN'T contains letter 'o'" << endl;
	}

	return 0;
}