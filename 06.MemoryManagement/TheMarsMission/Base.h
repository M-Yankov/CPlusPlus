#ifndef BASE_h
#define BASE_h

#include <vector>
#include <string>

#include "Mineral.h"
#include "GameElement.h"

class Base : public GameElement
{
private:
    static const unsigned int defaultHealth = 100;
    static const char defaultSymbol = 'B';
    unsigned int health;
    std::vector<Mineral> minerals;
public:
    Base();
    Base(unsigned int initialHealth, char initialSymbol);
    ~Base();
    unsigned int getHealth();
    void addMineral(Mineral & mineral);
    std::string toString();
};

#endif // !BASE_h
