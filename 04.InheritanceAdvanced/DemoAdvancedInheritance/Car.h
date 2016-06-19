#pragma once

#include "Man.h"

class Car
{
private:
	bool isGoodCondition;
public:
	Car(int priceValue) : price(priceValue), isGoodCondition(true) {};
	friend class Mechanic;
	friend void Man::CrashCar(Car &car);
	int price;
};

