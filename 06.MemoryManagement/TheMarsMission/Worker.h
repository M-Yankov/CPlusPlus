#ifndef WORKER_h
#define WORKER_h

#include "GameElement.h"
#include "GameMap.h"

class Worker : public GameElement
{
private:
    static const unsigned int defaultColumn = 0;
    static const unsigned int defaultRow = 0;
    static const char defaultChar = 'O';
    unsigned int column;
    unsigned int row;
    GameMap * gameMap;
public:
    Worker(GameMap & initialGameMap);
    Worker(unsigned int initialRow, unsigned int initialColumn, char symbol, GameMap & initialGameMap);
    ~Worker();
    void FindClosestMineralOnTheMap();
};

#endif // !WORKER_h
