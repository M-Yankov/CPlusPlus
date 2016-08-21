#ifndef RANDOMGENERATOR_h
#define RANDOMGENERATOR_h

#include <random>
#include <ctime>
#include <iostream>

class RandomGenerator
{
private:
public:
    RandomGenerator();
    ~RandomGenerator();

    int getRandomNumber(int min, int max, bool includeMax = false);

};

#endif // !RANDOMGENERATOR_h
