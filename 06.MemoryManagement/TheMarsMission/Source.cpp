#include <iostream>
#include <Windows.h>

#include "GameEngine.h"
#include "FilePrinter.h"

// defined only to output result in a file.
// #define TEST

int main()
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    // set the cursor visibility
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false; 
    SetConsoleCursorInfo(out, &cursorInfo);

    const int Rows = 7;
    const int Columns = 4;
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