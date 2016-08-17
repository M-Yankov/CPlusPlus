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
    int rowsLength = this->gameMap->mapElements.size();
    if (rowsLength == 0)
    {
        return Cell(-1, -1);
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
                return Cell(row, col);
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

    return Cell(-1, -1);
    // No more minerals games ends. But should find it in better way;
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

Cell Worker::getPosition()
{
    return Cell(this->row, this->column);
}

void Worker::setPosition(unsigned int newRow, unsigned int newColumn)
{
    this->row = newRow;
    this->column = newColumn;
}

