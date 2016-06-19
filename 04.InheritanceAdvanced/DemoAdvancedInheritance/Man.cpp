// it is very important the order of the includes.

#include "Man.h"
#include "Car.h"

void Man::CrashCar(Car &car)
{
	car.isGoodCondition = false;
};