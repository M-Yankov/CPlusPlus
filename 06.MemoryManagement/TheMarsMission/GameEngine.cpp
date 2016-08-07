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

    bool workerReachedMineral;
    Mineral mineral;

    workerReachedMineral = false;
    for (Cell & cell : path)
    {
        Cell workerPosition = worker.getPosition();
        worker.setPosition(cell.row, cell.column);

        if (mineralCell.row == cell.row && mineralCell.column == cell.column &&
            this->gameMap.at(mineralCell).symbol == 'M')
        {
            mineral = Mineral();
            workerReachedMineral = true;
            worker.pickUpMineral(mineral);
        }

        if (workerPosition.row != 0 || workerPosition.column != 0)
        {
            this->gameMap.setItem(workerPosition.row, workerPosition.column, GameElement());
        }

        this->gameMap.setItem(cell.row, cell.column, worker);
        std::cout << gameMap.getMap() << std::endl;
    }
    
    // TODO: Learn this!
    std::shared_ptr<Mineral> shared = std::shared_ptr<Mineral>(&mineral);
    std::weak_ptr<Mineral> weak = shared;
    std::weak_ptr<Mineral> weak2 = shared;
    std::shared_ptr<Mineral> shared2 = shared;
    if (workerReachedMineral)
    {
        worker.pickUpMineral(mineral);
    }

    // TODO: pass shared pointer to worker
    // * pass shared pointer to catapult
    // catapult can reset the value when it is hidded;
    std::cout << worker.mineral._Get()->getValue() << std::endl;
    std::cout << shared->getValue() << std::endl;
    std::cout << weak._Get()->getValue() << std::endl;
    std::cout << std::boolalpha << weak.expired() << std::endl;

    shared2 = nullptr;
    shared = nullptr;
    //shared.reset();

    std::cout << std::boolalpha << weak.expired() << std::endl;
    std::cout << weak._Get()->getValue() << std::endl;

}

void GameEngine::run(int mapRows, int mapColumns, unsigned int mineralsCount)
{
    this->gameMap.initializeMap(mapRows, mapColumns);
    this->gameMap.randomizeMinerals(mineralsCount);

    std::cout << this->gameMap.getMap();

    Worker worker = Worker(this->gameMap);

    std::cout << "\n\n\n";

    this->moveWorker(worker);
}
