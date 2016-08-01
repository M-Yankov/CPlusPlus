#ifndef BASE_h
#define BASE_h

#include "GameElement.h"

class Base : public GameElement
{
    static const unsigned int defaultHealth = 100;
    static const char defaultSymbol = 'B';
    unsigned int health;
public:
    Base();
    Base(unsigned int initialHealth, char initialSymbol);
    ~Base();
    unsigned int getHealth();
};

#endif // !BASE_h
