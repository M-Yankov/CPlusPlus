#include "Worker.h"

Worker::Worker(GameMap & initialGameMap) : Worker(this->defaultRow, this->defaultColumn, this->defaultChar, initialGameMap)
{
    
}

Worker::Worker(unsigned int initialRow, unsigned int initialColumn, char symbol, GameMap & initialGameMap) 
    : row(initialRow),
    column(initialColumn), 
    gameMap(&initialGameMap) ,
    GameElement(symbol)
{
}

Worker::~Worker()
{
}

void Worker::FindClosestMineralOnTheMap()
{

    std::cout <<
        this->gameMap->mapElements[1][1].symbol
        << std::endl;
        
}
