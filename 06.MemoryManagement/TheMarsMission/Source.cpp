#include <iostream>
#include <vector>
#include <exception>
#include <unordered_set>

#include "GameEngine.h"

int main()
{
    const int Matrix = 9;
    const int MineralsCount = 12;

    GameEngine engine = GameEngine();
    engine.run(Matrix, Matrix, MineralsCount);

    return 0;
}