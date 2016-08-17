#include "GameEngine.h"

GameEngine::GameEngine() : GameEngine(GameMap())
{
}

GameEngine::GameEngine(GameMap & map) : gameMap(map)
{
}

GameEngine::~GameEngine()
{
}

void GameEngine::moveWorker(Worker & worker)
{
    Cell mineralCell = worker.findClosestMineralOnTheMap();
    std::vector<Cell> path = worker.makePathToCell(mineralCell);

    bool workerReachedMineral = false;
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

    if (workerReachedMineral)
    {
        // reverse the path
        std::reverse(path.begin(), path.end());

        // remove the mineral cell
        path.erase(path.begin());

        // add base cell
        path.push_back(Cell(0, 0));

        for (Cell & cell : path)
        {
            Cell workerPosition = worker.getPosition();
            worker.setPosition(cell.row, cell.column);

            this->gameMap.setItem(workerPosition.row, workerPosition.column, GameElement());
            
            if (cell.row != 0 || cell.column != 0)
            {
                this->gameMap.setItem(cell.row, cell.column, worker);
            }
            else
            {
                // TODO: Add mineral in database.
            }

            std::cout << gameMap.getMap() << std::endl;
        }
    }
}

void GameEngine::strikeWithCatapult(Catapult & catapult, Worker & worker)
{
    Cell workerCell = worker.getPosition();
    Cell strikeCell = catapult.getCellToStrike(0, this->gameMap.getRows(), 0, this->gameMap.getColumns());
    while (strikeCell.column == 0 && strikeCell.row == 0)
    {
        strikeCell = catapult.getCellToStrike(0, this->gameMap.getRows(), 0, this->gameMap.getColumns());
    }


    // TODO: X 
    // The worker is hit.
    if (this->gameMap.at(strikeCell.row, strikeCell.column).symbol == 'O')
    {
        this->sharedPointerMineral.reset();
    }

    this->gameMap.setItem(strikeCell.row, strikeCell.column, GameElement('X'));
    std::cout << this->gameMap.getMap() << std::endl;
}

void GameEngine::run(int mapRows, int mapColumns, unsigned int mineralsCount)
{
    this->gameMap.initializeMap(mapRows, mapColumns);
    this->gameMap.randomizeMinerals(mineralsCount);

    std::cout << this->gameMap.getMap();
    std::cout << "\n\n\n";

    Worker worker = Worker(this->gameMap);
    Catapult catapult = Catapult();

    this->moveWorker(worker);
    this->strikeWithCatapult(catapult, worker);
}
