// Introduction.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input;
	getline(cin, input);

	size_t length = input.length();

	unsigned short symbolCode;

	int upperLettersCount = 0;
	int lowerLettersCount = 0;
	int otherSymbolCount = 0;

	for (size_t i = 0; i < length; i++)
	{
		symbolCode = input[i];

		if (isupper(input[i]))
		{
			upperLettersCount++;
		}
		else if (islower(input[i]))
		{
			lowerLettersCount++;
		}
		else
		{
			otherSymbolCount++;
		}
	}

	printf("Upper letters count: %d\n", upperLettersCount);
	printf("Lower letters count: %d\n", lowerLettersCount);
	printf("Other symbols count: %d\n", otherSymbolCount);
	printf("Full length of input %d\n", length);

	return 0;
}