/// TASK DESCRIPTION:
/// 10000 people must leave a concert from one exit. Only one can exit at time and
/// needs 20ms to leave. Represent the people by spawning threads and
/// represent the door as a critical resource;

/// Each should be printed at one line. 
/// Example output:
/// Pesho exits the concert.
/// Gosho exits the concert.
/// Goerge exits the concert.
/// Ivan exits the concert.
/// Kami exits the concert.
/// ... and so on, names can be in deferent order.

#include <iostream>
#include <thread>
#include <ctime>
#include <mutex>
#include <string>

#include <Windows.h>

// a global variable of Mutex to hold on threads
std::mutex securityGurad;
int normalConsoleColor = 7;
int violetConsoleColor = 13;
int peopleAtExit = 0;
int timeForExitPerPersonInMs = 20;
// HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void exitFromConcert(std::string name)
{
	// the person comes to the exit.
	peopleAtExit++;
	std::printf("[%s] wants to leave.  %7.0d to go.\n", name.c_str(), peopleAtExit);
	
	// critical resource:
	// person pass throw the door exit; 
	securityGurad.lock();
	peopleAtExit--;

	_sleep(timeForExitPerPersonInMs);
	std::printf("%s exits the concert. %7.0d to go. \n", name.c_str(), peopleAtExit);
	securityGurad.unlock();
}

std::string getName(char num)
{
	switch (num)
	{
	case 0:
		return "Pesho";
	case 1:
		return "Gosho";
	case 2:
		return "Maria";
	default:
		throw std::exception("Error");
	}
}

/// <summary>
/// Run this application with x64 configuration.
/// </summary>
/// <returns></returns>
int main()
{
	// SetConsoleTextAttribute(hConsole, violetConsoleColor);
	// person means thread.
	const int peopleInConcert = 10000;
	std::clock_t startTime = std::clock();
	std::thread people[peopleInConcert];

	for (int i = 0; i < peopleInConcert; i++)
	{
		people[i] = std::thread(exitFromConcert, getName(i % 3));
	}

	for (auto& person : people)
	{
		person.join();
	}

	std::clock_t endTime = std::clock();
	double timeDiff = endTime - startTime;
	std::cout << peopleInConcert << " people leaves the concert for: " << timeDiff / CLOCKS_PER_SEC << " s."  << std::endl;
	return 0;
}