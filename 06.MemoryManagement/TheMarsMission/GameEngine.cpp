#include "GameEngine.h"

bool GameEngine::isGameEnded()
{
    return this->mineralsCount <= 0 || this->gameBase.getHealth() <= 0;
}

GameEngine::GameEngine() : GameEngine(GameMap(), Base(), new ConsolePrinter())
{
}

GameEngine::GameEngine(GameEngine & gameEngine) : GameEngine(gameEngine.gameMap, gameEngine.gameBase, gameEngine.printer.get())
{
}

GameEngine::GameEngine(GameMap & map, Base & base, BasePrinter * outputPrinter) : gameMap(map), gameBase(base)
{
    std::setlocale(LC_ALL, "russian");
    this->printer = std::unique_ptr<BasePrinter>(outputPrinter);
}

GameEngine::~GameEngine()
{
}

void GameEngine::operator=(GameEngine & engine)
{
    this->gameBase = engine.gameBase;
    this->gameMap = engine.gameMap;
    this->printer = engine.printer;
    this->mineralsCount = engine.mineralsCount;
    this->sharedPointerMineral = engine.sharedPointerMineral;
}

void GameEngine::setMineralsCount(int mineralsCount)
{
    this->mineralsCount = mineralsCount;
}

void GameEngine::moveWorker(Worker & worker)
{
    while (this->mineralsCount > 0)
    {
        Cell mineralCell = worker.findClosestMineralOnTheMap();

        if (mineralCell.row < 0 || mineralCell.row < 0)
        {
            return;
        }

        std::vector<Cell> path = worker.makePathToCell(mineralCell);

        bool workerReachedMineral = false;
        for (Cell & cell : path)
        {
            Cell workerOldPosition = worker.getPosition();
            worker.setPosition(cell.row, cell.column);

            if (mineralCell.row == cell.row && mineralCell.column == cell.column &&
                this->gameMap.at(mineralCell).symbol == 'M')
            {
                this->sharedPointerMineral = std::shared_ptr<Mineral>(new Mineral());
                workerReachedMineral = true;
                worker.pickUpMineral(this->sharedPointerMineral);
            }

            if (workerOldPosition.row != 0 || workerOldPosition.column != 0)
            {
                this->gameMap.setItem(workerOldPosition.row, workerOldPosition.column, GameElement());
            }

            this->gameMap.setItem(cell.row, cell.column, worker);

            _sleep(1000);
            this->printer->writeLine(gameMap.getMap());
            this->printer->writeLine("", false);
        }

        // path back to base.
        if (workerReachedMineral)
        {
            // reverse the path
            std::reverse(path.begin(), path.end());

            // remove the mineral cell
            path.erase(path.begin());

            // add base cell
            path.push_back(Cell(0, 0));
            int counter = 0;
            int end = path.size();

            for (Cell & cell : path)
            {
                counter++;

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

                _sleep(1000);

                this->printer->writeLine(this->gameMap.getMap());
                this->printer->writeLine("", false);
            }

            this->printer->writeLine(this->gameBase.toString(), false);
            this->printer->writeLine("", false);
        }
    }
}

void GameEngine::strikeWithCatapult(Catapult & catapult, Worker & worker)
{
    while (!this->isGameEnded())
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
            // TODO: more logic here !
            /*this->sharedPointerMineral.reset();
            this->mineralsCount--;*/
        }

        GameElement oldGameElement = this->gameMap.at(strikeCell);
        this->gameMap.setItem(strikeCell.row, strikeCell.column, GameElement('X'));

        this->printer->writeLine(this->gameMap.getMap());
        this->printer->writeLine("", false);

        this->gameMap.setItem(strikeCell.row, strikeCell.column, oldGameElement);
        _sleep(3000);
    }
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
        this->printer->writeLine("", false);
    }

    _sleep(1000);

    Worker worker = Worker(this->gameMap);


    std::thread workerThread([&] { this->moveWorker(worker); });
    std::thread catapultThread([&] { this->strikeWithCatapult(Catapult(), worker); });

    workerThread.join();
    catapultThread.join();

    /*
    this->moveWorker(worker);
    this->strikeWithCatapult(catapult, worker);
    */
}