#include "Catapult.h"

Catapult::Catapult() : Catapult(this->defaultChar, RandomGenerator())
{
}

Catapult::Catapult(char initalSymbol , RandomGenerator & generator) : GameElement(initalSymbol), randomGenerator(generator)
{
}

Catapult::~Catapult()
{
}

Cell Catapult::getCellToStrike(int maxRow, int maxColumn)
{
    int row = this->randomGenerator.getRandomNumber(0, maxRow);
    int column = this->randomGenerator.getRandomNumber(0, maxColumn);

    return Cell(row, column);
}

Cell Catapult::getCellToStrike(int minRow, int maxRow, int minColumn, int maxColumn)
{
    int row = this->randomGenerator.getRandomNumber(minRow, maxRow);
    int column = this->randomGenerator.getRandomNumber(minColumn, maxColumn);

    return Cell(row, column);
}
