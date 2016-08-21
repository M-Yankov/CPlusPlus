#include "GameEngine.h"
#include "FilePrinter.h"

// defined only to output result in a file.
// #define TEST

int main()
{
    const int Rows = 5;
    const int Columns = 8;
    const int MineralsCount = 5;

    GameMap map = GameMap();
    Base aBase = Base();
    GameEngine engine;

#ifdef TEST
    engine = GameEngine(map, aBase, new FilePrinter("/Output/printer.txt"));
#endif // TEST

    engine.run(Rows, Columns, MineralsCount);
    return 0;
}