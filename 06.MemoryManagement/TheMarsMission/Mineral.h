#ifndef Mineral_h
#define Mineral_h

#include "GameElement.h"
#include <iostream>

class Mineral : public GameElement
{
private:
    unsigned char mineralValue;
public:
    Mineral(unsigned char initialValue, char initialChar);
    ~Mineral();
    unsigned char getValue();
};

#endif 
