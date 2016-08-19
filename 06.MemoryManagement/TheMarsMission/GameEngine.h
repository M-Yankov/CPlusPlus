#ifndef GAMEENGINE_h
#define GAMEENGINE_h

#include <vector>
#include <memory>

#include <iostream>
#include <fstream>
#include <clocale>

#include "GameMap.h"
#include "Worker.h"
#include "Catapult.h"
#include "Cell.h"

class GameEngine
{
private:
    std::shared_ptr<Mineral> sharedPointerMineral;
    GameMap gameMap;
    Base gameBase;
    bool isGameEnded;
    int mineralsCount;
public:
    GameEngine();
    GameEngine(GameMap & map, Base & base);
    ~GameEngine();
    void moveWorker(Worker & worker);
    void strikeWithCatapult(Catapult & catapult, Worker & worker);
    void run(int mapRows, int mapColumns, unsigned int mineralsCount);
    void setMineralsCount(int mineralsCount);
};

#endif // !GAMEENGINE_h
