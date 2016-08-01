#include "Catapult.h"

Catapult::Catapult() : Catapult(this->defaultChar)
{
}

Catapult::Catapult(char initalSymbol) : GameElement(initalSymbol)
{
}

Catapult::~Catapult()
{
}
