#pragma once

#include <iostream>
#include <mutex>

class Disco
{
private:
	std::mutex myMtx;
	int peopleInDisco;
	const int MAX_PEOPLE_IN_DISCO = 100;
	int timeForEnterInDiscoMs = 300;// 30000; // 30s
	int timeForExitFromDiscoMs = 300; // 10000; // 10s
public:
	Disco();
	Disco(Disco & disc);
	void enterDisco();
	void exitDisco();
};

