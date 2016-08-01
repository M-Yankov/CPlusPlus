#include "RandomGenerator.h"

RandomGenerator::RandomGenerator()
{
    // reset random seed - to generate different values each time.
    std::srand(time(0));
}

RandomGenerator::~RandomGenerator()
{
    std::cout << "Random deleted" << std::endl;
}

int RandomGenerator::getRandomNumber(int min, int max, bool includeMax)
{
    return std::rand() % ((max - min) + includeMax) + min;
}
