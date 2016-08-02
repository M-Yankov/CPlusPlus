#include "Truck.h"



Truck::Truck()
{
}

Truck::Truck(std::string regNumber, float tonesWeight, unsigned short seatsCount, std::string chassisNum, std::string engineNum, std::string aOwner, Date dateOfRegistration, Date dateOfRegistrationInCountry)
    : Vehicle(regNumber, tonesWeight, seatsCount, chassisNum, engineNum, aOwner, dateOfRegistration, dateOfRegistrationInCountry)
{
}


Truck::~Truck()
{
}
