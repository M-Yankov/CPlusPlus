// it is very important the order of the includes.

#include "Car.h"
#include "Man.h"

void Man::CrashCar(Car &car)
{
	car.isGoodCondition = false;
};