#include "Vehicle.h"

Vehicle::Vehicle()
{
}

Vehicle::Vehicle(
    std::string regNumber,
    float tonesWeight,
    unsigned short seatsCount,
    std::string chassisNum,
    std::string engineNum,
    std::string aOwner,
    Date dateOfRegistration,
    Date dateOfRegistrationInCountry)
    :
    registrationNumber(regNumber),
    weightInTones(tonesWeight),
    numberOfSeats(seatsCount),
    engineNumber(engineNum),
    chassisNumber(chassisNum),
    owner(aOwner),
    dateRegistered(dateOfRegistration),
    dateRegisteredInCountry(dateOfRegistrationInCountry)
{
}

Vehicle::~Vehicle()
{
}

std::string Vehicle::toString()
{
    const char * format = "%s\n"
        "Weight %0.1f\n"
        "Number of seats: %d\n"
        "Chassis number %s\n"
        "Engine number: %s\n"
        "Owner: %s\n"
        "Date of first registration: %s\n"
        "Date of registration in country: %s\n";

    char buffer[600];
    std::sprintf(
        buffer,
        format,
        this->registrationNumber.c_str(),
        this->weightInTones,
        this->numberOfSeats,
        this->chassisNumber.c_str(),
        this->engineNumber.c_str(),
        this->owner.c_str(),
        this->dateRegistered.toString().c_str(),
        this->dateRegisteredInCountry.toString().c_str());

    return buffer;
}

std::string Vehicle::getRegistrationNumber()
{
    return this->registrationNumber;
}
