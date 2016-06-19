#include "Mechanic.h"
#include "Car.h"

void Mechanic::RepairCar(Car &car)
{
	car.isGoodCondition = true;
}

float Mechanic::RepairCost(Car &car)
{
	if (car.isGoodCondition)
	{
		return 0;
	}

	return car.price * 0.05;
}