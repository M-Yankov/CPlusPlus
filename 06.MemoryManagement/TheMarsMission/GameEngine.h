#ifndef GAMEENGINE_h
#define GAMEENGINE_h

#include <vector>
#include <memory>
#include <thread>
#include <iostream>
#include <fstream>
#include <clocale>

#include "GameMap.h"
#include "Worker.h"
#include "Catapult.h"
#include "Cell.h"
#include "BasePrinter.h"
#include "ConsolePrinter.h"

class GameEngine
{
private:
    std::shared_ptr<Mineral> sharedPointerMineral;
    std::shared_ptr<BasePrinter> printer;
    GameMap gameMap;
    Base gameBase;
    int mineralsCount;
    bool isGameEnded();
public:
    GameEngine();
    GameEngine(GameEngine & gameEngine);
    GameEngine(GameMap & map, Base & base, BasePrinter * outputPrinter);
    ~GameEngine();
    void operator=(GameEngine & engine);
    void setMineralsCount(int mineralsCount);
    void moveWorker(Worker & worker);
    void strikeWithCatapult(Catapult & catapult, Worker & worker);
    void run(int mapRows, int mapColumns, unsigned int mineralsCount);
};

#endif // !GAMEENGINE_h
