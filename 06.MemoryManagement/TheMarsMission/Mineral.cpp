#include "Mineral.h"

Mineral::Mineral(unsigned char initialValue, char initialChar) : mineralValue(initialValue), GameElement(initialChar)
{
}

Mineral::~Mineral()
{
    std::cout << "Mineral destroyed." << std::endl;
}

unsigned char Mineral::getValue()
{
    return this->mineralValue;
}
