#include "Mineral.h"


Mineral::Mineral(unsigned char initialValue) : mineralValue(initialValue)
{
}

Mineral::~Mineral()
{
    std::cout << "Mineral destroyed." << std::endl;
}
