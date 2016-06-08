#include <iostream>
#include <string>

using namespace std;

class Car 
{
public:
	string make;
	string model;
	float horsePower;
	double timeToSixtyMph;
	float fuelConsumption;
	bool isRunning;

	void Run();
	void Stop();
};


void Car::Run()
{
	isRunning = true;
}

void Car::Stop()
{
	isRunning = false;
}


/// <summary>
/// This program can called from outside- CMD and can accept arguments.
/// </summary>
/// <param name="argc">The number of the arguments.</param>
/// <param name="argv">The argv[0] - the name of the called program. argv[1...n] arguments</param>
/// <returns></returns>
int main(int argc, char ** argv)
{
	Car fordMustang;
	fordMustang.fuelConsumption = 10;
	fordMustang.horsePower = 400;
	fordMustang.isRunning = false;
	fordMustang.model = "Mustang";
	fordMustang.make = "Ford";

	Car fordFocus;
	fordFocus.model = "Focus";
	fordFocus.horsePower = 200;
	fordFocus.make = "Ford";
	fordFocus.isRunning = false;

	int ù = 0;
	return ù;
}
