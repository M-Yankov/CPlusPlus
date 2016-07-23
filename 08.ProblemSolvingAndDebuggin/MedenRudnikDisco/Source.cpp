#include <iostream>
#include <thread>
#include <vector>

#include "Disco.h"

void enterInDisco(Disco & disco);
void exitFromDisco(Disco & disco);

int main()
{
	int const startCount = 50;
	Disco disco = Disco();
	std::vector<std::thread> threards;

	for (int i = 0; i < startCount; i++)
	{
		threards.push_back(std::thread(enterInDisco, disco));

		if (i % 3 ==0)
		{
			threards.push_back(std::thread(exitFromDisco, disco));
		}
	}

	for (std::thread & ptrThread : threards)
	{
		ptrThread.join();
	}

	return 0;
}

void enterInDisco(Disco & disco)
{
	disco.enterDisco();
}

void exitFromDisco(Disco & disco)
{
	disco.exitDisco();
}
