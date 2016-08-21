#ifndef GAMEMAP_h
#define GAMEMAP_h

#include <vector>
#include <sstream>
#include <unordered_set>
#include <mutex>

#include "Mineral.h"
#include "Base.h"
#include "Cell.h"
#include "Catapult.h"
#include "CellHash.h"
#include "RandomGenerator.h"

class GameMap
{
private:
    std::vector<std::vector<GameElement>> mapElements;
    static const int defaultDimensionLength = 0;
    static const int defaultBaseRow = 0;
    static const int defailtBaseColumn = 0;
    bool isInitialized;
    int mapRows;
    int mapColumns;
    RandomGenerator * randomGenerator;
    std::mutex locker;
public:
    GameMap();
    GameMap(GameMap & gameMap);
    GameMap(RandomGenerator & generator);
    ~GameMap();
    void operator=(GameMap & gameMap);
    void setItem(int row, int column, GameElement & gameElement);
    void initializeMap(int rows, int columns, bool useDefaultPositonsForBaseAndCatapult = true);
    void randomizeMinerals(unsigned int mineralsCount);
    void placeBaseOnDefaultPosiotion();
    void placeCatapultOnDefaultPosition();
    std::string getMap();
    GameElement at(int row, int column);
    GameElement at(const Cell & cell);
    int getRows();
    int getColumns();
    friend class Worker;
};

#endif // !GAMEMAP_h