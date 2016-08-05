#include "GameEngine.h"

GameEngine::GameEngine() : gameMap(GameMap())
{
}

GameEngine::~GameEngine()
{
}

void GameEngine::moveWorker(Worker & worker)
{
    Cell mineralCell = worker.findClosestMineralOnTheMap();
    std::vector<Cell> path = worker.makePathToCell(mineralCell);
    
    for (Cell & cell : path)
    {
        Cell workerPosition = worker.getPosition();
        worker.setPosition(cell.row, cell.column);
        if (workerPosition.row != 0 || workerPosition.column != 0)
        {
            this->gameMap.setItem(workerPosition.row, workerPosition.column, GameElement());
        }

        this->gameMap.setItem(cell.row, cell.column, worker);


        std::cout << gameMap.getMap() << std::endl;
    }
}

void GameEngine::run(int mapRows, int mapColumns, unsigned int mineralsCount)
{
    this->gameMap.initializeMap(mapRows, mapColumns);
    this->gameMap.randomizeMinerals(mineralsCount);

    std::cout << this->gameMap.getMap();

    Worker worker = Worker(this->gameMap);
   /* Cell mineralCell = worker.findClosestMineralOnTheMap();

    std::cout << "Closest mineral: " << mineralCell.row << ", " << mineralCell.column << std::endl;

    std::vector<Cell> path = worker.makePathToCell(mineralCell);

    std::cout << "Path: " << std::endl;
    for (Cell & cell : path)
    {
        std::cout << cell.row << " " << cell.column << std::endl;
    }*/

    std::cout << "\n\n\n";


    this->moveWorker(worker);
}
