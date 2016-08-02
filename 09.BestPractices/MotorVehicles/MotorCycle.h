#ifndef MOTORCYCLE_h
#define MOTORCYCLE_h

#include "Vehicle.h"
class MotorCycle : public Vehicle
{
public:
    MotorCycle();
    MotorCycle(
        std::string regNumber,
        float tonesWeight,
        unsigned short seatsCount,
        std::string chassisNum,
        std::string engineNum,
        std::string aOwner,
        Date dateOfRegistration,
        Date dateOfRegistrationInCountry);
    ~MotorCycle();
};

#endif // !MOTORCYCLE_h
