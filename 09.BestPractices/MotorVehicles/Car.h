#ifndef CAR_h
#define CAR_h

#include "Vehicle.h"

class Car : public Vehicle
{
public:
    Car();
    Car(
        std::string regNumber,
        float tonesWeight,
        unsigned short seatsCount,
        std::string chassisNum,
        std::string engineNum,
        std::string aOwner,
        Date dateOfRegistration,
        Date dateOfRegistrationInCountry);
    ~Car();
};

#endif // !CAR_h
