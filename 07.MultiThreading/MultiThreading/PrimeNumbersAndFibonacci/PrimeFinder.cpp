#include "PrimeFinder.h"
#include <math.h>

PrimeFinder::PrimeFinder(std::string newName) : name(newName)
{
}

unsigned long long PrimeFinder::findPrimeNumber(unsigned long long startFrom)
{
	for (unsigned long long  i = startFrom; true; i++)
	{
		if (i <= 2)
		{
			return i;
		}
		
		unsigned long long length = sqrt(i);
		int startNumber = 2;
		if (startNumber > length)
		{
			return i;
		}

		for (unsigned long long c = startNumber; c <= length; c++)
		{
			if (i % c == 0)
			{
				break;
			}

			if (c == length)
			{
				return i;
			}
		}
	}
}
