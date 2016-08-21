#include "GameMap.h"

GameMap::GameMap() : GameMap(RandomGenerator())
{
}

GameMap::GameMap(GameMap & gameMap) : GameMap(*gameMap.randomGenerator)
{
}

GameMap::GameMap(RandomGenerator & generator) : isInitialized(false), mapColumns(this->defaultDimensionLength), mapRows(this->defaultDimensionLength), randomGenerator(&generator)
{
}

GameMap::~GameMap()
{
    for (std::vector<GameElement> elements : this->mapElements)
    {
        elements.clear();
    }

    this->mapElements.clear();
    this->isInitialized = false;
}

void GameMap::operator=(GameMap & gameMap)
{
    this->isInitialized = gameMap.isInitialized;
    this->randomGenerator = gameMap.randomGenerator;
    this->mapColumns = gameMap.mapColumns;
    this->mapRows = gameMap.mapRows;
    this->mapElements = gameMap.mapElements;
}

void GameMap::setItem(int row, int column, GameElement & gameElement)
{
    this->locker.lock();
    this->mapElements[row][column] = gameElement;
    this->locker.unlock();
}

void GameMap::placeBaseOnDefaultPosiotion()
{
    this->setItem(this->defaultBaseRow, this->defailtBaseColumn, Base());
}

void GameMap::placeCatapultOnDefaultPosition()
{
    this->setItem(this->mapRows - 1, this->mapColumns - 1, Catapult());
}

void GameMap::initializeMap(int rows, int columns, bool useDefaultPositonsForBaseAndCatapult)
{
    this->mapElements = std::vector<std::vector<GameElement>>(rows);
    this->mapColumns = columns;
    this->mapRows = rows;

    for (int i = 0; i < rows; i++)
    {
        for (int col = 0; col < columns; col++)
        {
            this->mapElements[i].push_back(GameElement());
        }
    }

    if (useDefaultPositonsForBaseAndCatapult)
    {
        this->placeBaseOnDefaultPosiotion();
        this->placeCatapultOnDefaultPosition();
    }

    this->isInitialized = true;
}

void GameMap::randomizeMinerals(unsigned int mineralsCount)
{
    if (!this->isInitialized)
    {
        throw "Game map is not initialized!";
    }

    std::unordered_set<Cell> cells;
    while (cells.size() < mineralsCount)
    {
        int generatedRow = this->randomGenerator->getRandomNumber(0, this->mapRows);
        int generatedColumn = this->randomGenerator->getRandomNumber(0, this->mapColumns);

        // top-left and bottom-right cells are not allowed (base and enemyCatapult)
        if ((generatedRow == 0 && generatedColumn == 0) ||
            (generatedRow == this->mapRows - 1 && generatedColumn == this->mapColumns - 1))
        {
            continue;
        }

        Cell cell = Cell(generatedRow, generatedColumn);
        cells.insert(cell);
        cell.~Cell();
    }

    // free memory no need generator anymore.
    this->randomGenerator->~RandomGenerator();
    this->randomGenerator = nullptr;

    for (Cell currentCell : cells)
    {
        this->setItem(currentCell.row, currentCell.column, Mineral());
    }
}

std::string GameMap::getMap()
{
    if (!this->isInitialized)
    {
        return "Game map is not initialized!";
    }

    std::stringstream ss;
    int currentRow = 0;
    int length = this->mapElements.size();
    for (std::vector<GameElement> row : this->mapElements)
    {
        currentRow++;
        for (GameElement columnCell : row)
        {
            ss << columnCell.symbol << " ";
        }

        if (currentRow != length)
        {
            ss << std::endl;
        }
    }

    return ss.str();
}

GameElement GameMap::at(int row, int column)
{
    return this->mapElements[row][column];
}

GameElement GameMap::at(const Cell & cell)
{
    return this->mapElements[cell.row][cell.column];
}

int GameMap::getRows()
{
    return this->mapRows;
}

int GameMap::getColumns()
{
    return this->mapColumns;
}

