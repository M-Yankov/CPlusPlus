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
    if (min == max)
    {
        return min;
    }

    if (min > max)
    {
        throw "Min should be less than max value.";
    }

    int result = std::rand() % ((max - min) + includeMax) + min;
    return result;
}
