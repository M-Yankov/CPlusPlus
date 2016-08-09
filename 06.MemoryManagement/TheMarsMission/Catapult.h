#ifndef CATAPULT_h
#define CATAPULT_h

#include "GameElement.h"
#include "RandomGenerator.h"
#include "Cell.h"

class Catapult : public GameElement
{
private:
    static const char defaultChar = '<';
    RandomGenerator randomGenerator;
public:
    Catapult();
    Catapult(char initalSymbol, RandomGenerator & generator);
    ~Catapult();
    Cell getCellToStrike(int maxRow, int maxColumn);
    Cell getCellToStrike(int minRow, int maxRow, int minColumn, int maxColumn);
};

#endif // !CATAPULT_h
