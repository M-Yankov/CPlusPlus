#ifndef CATAPULT_h
#define CATAPULT_h

#include "GameElement.h"
class Catapult :
    public GameElement
{
private:
    static const char defaultChar = '<';
public:
    Catapult();
    Catapult(char initalSymbol);
    ~Catapult();
};

#endif // !CATAPULT_h
