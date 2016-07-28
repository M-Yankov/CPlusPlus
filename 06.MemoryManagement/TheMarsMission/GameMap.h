#pragma once
#include <vector>
#include <sstream>
#include "Mineral.h"

char const DefaultChar = 249;

class GameMap
{
private:
    std::vector<std::vector<GameElement>> mapElements;
    bool isInitialized;
public:
    GameMap();
    ~GameMap();
    void setItem(int row, int column, GameElement & gameElement);
    void initializeMap(int rows, int columns);
    std::string getMap();
};