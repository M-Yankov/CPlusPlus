#include "Disco.h"

Disco::Disco()
{
}

Disco::Disco(Disco & disc)
{
}

void Disco::enterDisco()
{
	while (this->peopleInDisco >= MAX_PEOPLE_IN_DISCO)
	{
		_sleep(500);
	}

	myMtx.lock();
	_sleep(timeForEnterInDiscoMs);
	std::printf("Entered\n");
	peopleInDisco++;

	myMtx.unlock();
}

void Disco::exitDisco()
{
	myMtx.lock();
	_sleep(timeForExitFromDiscoMs);
	std::printf("Exit...\n");
	peopleInDisco--;

	myMtx.unlock();
}
