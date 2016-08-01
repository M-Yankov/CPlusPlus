#ifndef Mineral_h
#define Mineral_h

#include "GameElement.h"
#include <iostream>

class Mineral : public GameElement
{
private:
    unsigned int mineralValue;
    static const unsigned int defaultValue = 5;
    static const char defaultMineralSymbol = 'M';
public:
    Mineral();
    Mineral(unsigned int initialValue, char initialChar);
    ~Mineral();
    unsigned int getValue();
};

#endif 
