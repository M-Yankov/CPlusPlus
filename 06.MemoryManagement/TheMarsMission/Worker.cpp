#include "Worker.h"

Worker::Worker(GameMap & initialGameMap) : Worker(this->defaultRow, this->defaultColumn, this->defaultChar, initialGameMap)
{
}

Worker::Worker(unsigned int initialRow, unsigned int initialColumn, char symbol, GameMap & initialGameMap)
    : row(initialRow),
    column(initialColumn),
    gameMap(&initialGameMap),
    GameElement(symbol)
{
}

Worker::~Worker()
{
}

Cell Worker::findClosestMineralOnTheMap()
{
    std::vector<Cell>::iterator nextCellIterator = this->mineralCells.begin();

    if (nextCellIterator == this->mineralCells.end())
    {
        // no more minerals.
        return Cell(-1, -1);
    }

    Cell nextCell = *nextCellIterator;
    this->mineralCells.erase(nextCellIterator);

    return nextCell;
}

std::vector<Cell> Worker::makePathToCell(Cell & cell)
{
    std::vector<Cell> path;

    int colsLength = std::abs((int)this->column - cell.column);
    bool isRightDirection = (cell.column - (int)this->column) > 0;

    for (int i = 0; i < colsLength; i++)
    {
        if (isRightDirection)
        {
            // right
            path.push_back(Cell(this->row, this->column + (i + 1)));
        }
        else
        {
            // left
            path.push_back(Cell(this->row, this->column - (i + 1)));
        }
    }

    int rowsLength = std::abs((int)this->row - cell.row);
    bool isUpDirection = (cell.row - (int)this->row) > 0;

    for (int i = 0; i < rowsLength; i++)
    {
        if (isUpDirection)
        {
            // up
            path.push_back(Cell(this->row + (i + 1), cell.column));
        }
        else
        {
            // down
            path.push_back(Cell(this->row - (i - 1), cell.column));
        }
    }

    return path;
}

void Worker::pickUpMineral(std::shared_ptr<Mineral> sharedPointer)
{
    this->mineral = sharedPointer;
}

Mineral Worker::throwMineral()
{
    Mineral mineralToThrow = *this->mineral._Get();
    this->mineral.~weak_ptr();
    return mineralToThrow;
}

void Worker::findMinerals()
{
    int rowsLength = this->gameMap->mapElements.size();
    if (rowsLength == 0)
    {
        return;
    }

    int colsLength = this->gameMap->mapElements[0].size();
    bool topRightReached = false;

    for (int initialRow = 0, initialCol = 0; initialRow < rowsLength;)
    {
        if (initialCol == colsLength - 1)
        {
            topRightReached = true;
        }

        for (int row = initialRow, col = initialCol; col >= 0 && row < rowsLength; col--, row++)
        {
            if (this->gameMap->mapElements[row][col].symbol == 'M')
            {
                this->mineralCells.push_back(Cell(row, col));
            }
        }

        if (topRightReached)
        {
            initialRow++;
        }
        else
        {
            initialCol++;
        }
    }
}

Cell Worker::getPosition()
{
    return Cell(this->row, this->column);
}

void Worker::setPosition(unsigned int newRow, unsigned int newColumn)
{
    this->row = newRow;
    this->column = newColumn;
}

