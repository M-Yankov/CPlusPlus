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

    workerReachedMineral = false;
    for (Cell & cell : path)
    {
        Cell workerPosition = worker.getPosition();
        worker.setPosition(cell.row, cell.column);

        if (mineralCell.row == cell.row && mineralCell.column == cell.column &&
            this->gameMap.at(mineralCell).symbol == 'M')
        {
            this->sharedPointerMineral = std::shared_ptr<Mineral>(new Mineral());
            workerReachedMineral = true;
            worker.pickUpMineral(this->sharedPointerMineral);
        }

        if (workerPosition.row != 0 || workerPosition.column != 0)
        {
            this->gameMap.setItem(workerPosition.row, workerPosition.column, GameElement());
        }

        this->gameMap.setItem(cell.row, cell.column, worker);
        std::cout << gameMap.getMap() << std::endl;
    }
}

void GameEngine::strikeWithCatapult(Catapult & catapult, Worker & worker)
{
    Cell workerCell = worker.getPosition();
    Cell strikeCell = catapult.getCellToStrike(workerCell.row, workerCell.row, workerCell.column, workerCell.column);

    // TODO: X 
    // The worker is hit.
    if (this->gameMap.at(strikeCell.row, strikeCell.column).symbol == 'O')
    {
        std::cout << worker.mineral.expired() << std::endl; 
        this->sharedPointerMineral.reset();
        std::cout << worker.mineral.expired() << std::endl;
    }
    
    this->gameMap.setItem(strikeCell.row, strikeCell.column, GameElement('X'));
    std::cout << this->gameMap.getMap() << std::endl;
}

void GameEngine::run(int mapRows, int mapColumns, unsigned int mineralsCount)
{
    this->gameMap.initializeMap(mapRows, mapColumns);
    this->gameMap.randomizeMinerals(mineralsCount);

    std::cout << this->gameMap.getMap();

    Worker worker = Worker(this->gameMap);
    Catapult catapult = Catapult();

    std::cout << "\n\n\n";

    this->moveWorker(worker);
    this->strikeWithCatapult(catapult, worker);
}
