#include "MotorCycle.h"

MotorCycle::MotorCycle()
{
}

MotorCycle::MotorCycle(std::string regNumber, float tonesWeight, unsigned short seatsCount, std::string chassisNum, std::string engineNum, std::string aOwner, Date dateOfRegistration, Date dateOfRegistrationInCountry)
    : Vehicle(regNumber, tonesWeight, seatsCount, chassisNum, engineNum, aOwner, dateOfRegistration, dateOfRegistrationInCountry)
{
}

MotorCycle::~MotorCycle()
{
}
