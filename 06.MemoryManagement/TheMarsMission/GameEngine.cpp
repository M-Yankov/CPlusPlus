#include "GameEngine.h"

GameEngine::GameEngine() : GameEngine(GameMap(), Base(), new ConsolePrinter())
{
    // TODO: extract this
    std::setlocale(LC_ALL, "russian");
}

GameEngine::GameEngine(GameMap & map, Base & base, BasePrinter * outputPrinter) : gameMap(map), gameBase(base)
{
    this->printer = std::unique_ptr<BasePrinter>(outputPrinter);
}

GameEngine::~GameEngine()
{
}

void GameEngine::moveWorker(Worker & worker)
{
    while (this->mineralsCount > 0)
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
             
            this->printer->writeLine(gameMap.getMap());
            this->printer->writeLine();
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
                    this->gameBase.addMineral(*this->sharedPointerMineral.get());
                    this->sharedPointerMineral.reset();
                    this->mineralsCount--;
                }

                this->printer->writeLine(this->gameMap.getMap());
                this->printer->writeLine();
            }

            this->printer->writeLine(this->gameBase.toString());
            this->printer->writeLine();
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
     this->printer->writeLine(this->gameMap.getMap());
}

void GameEngine::run(int mapRows, int mapColumns, unsigned int mineralsCount)
{
    this->setMineralsCount((int)mineralsCount);

    this->gameMap.initializeMap(mapRows, mapColumns);
    this->gameMap.randomizeMinerals(mineralsCount);

    // unnecessary
    this->gameMap.setItem(0, 0, this->gameBase);
    this->printer->writeLine(this->gameMap.getMap());

    for (size_t i = 0; i < 3; i++)
    {
        this->printer->writeLine();
    }

    Worker worker = Worker(this->gameMap);
    Catapult catapult = Catapult();

    this->moveWorker(worker);
    this->strikeWithCatapult(catapult, worker);
}

void GameEngine::setMineralsCount(int mineralsCount)
{
    this->mineralsCount = mineralsCount;
}
