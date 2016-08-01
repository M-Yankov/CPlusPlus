#include "Mineral.h"

Mineral::Mineral() : Mineral(this->defaultValue, this->defaultMineralSymbol)
{
}

Mineral::Mineral(unsigned int initialValue, char initialChar) : mineralValue(initialValue), GameElement(initialChar)
{
}

Mineral::~Mineral()
{
    std::cout << "Mineral destroyed." << std::endl;
}

unsigned int Mineral::getValue()
{
    return this->mineralValue;
}
