#ifndef WORKER_h
#define WORKER_h

#include <memory>
#include <vector>


#include "GameElement.h"
#include "GameMap.h"
#include "Cell.h"

class Worker : public GameElement
{
private:
    static const unsigned int defaultColumn = 0;
    static const unsigned int defaultRow = 0;
    static const char defaultChar = 'O';
    unsigned int column;
    unsigned int row;
    GameMap * gameMap;
    std::vector<Cell> mineralCells;
public:
    std::weak_ptr<Mineral> mineral;
    Worker(GameMap & initialGameMap);
    Worker(unsigned int initialRow, unsigned int initialColumn, char symbol, GameMap & initialGameMap);
    ~Worker();
    Cell findClosestMineralOnTheMap();
    void shrinkFoundedMinerals(const Cell & mineralToRemove);
    std::vector<Cell> makePathToCell(Cell & cell);
    void pickUpMineral(std::shared_ptr<Mineral> sharedPointer);
    Mineral throwMineral();
    void findMinerals();
    Cell getPosition();
    void setPosition(unsigned int newRow, unsigned int newColumn);
};

#endif // !WORKER_h
