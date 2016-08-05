#ifndef GAMEENGINE_h
#define GAMEENGINE_h

#include <vector>

#include "GameMap.h"
#include "Worker.h"
#include "Catapult.h"
#include "Cell.h"

class GameEngine
{
private:
    GameMap gameMap;
public:
    GameEngine();
    ~GameEngine();
    void moveWorker(Worker & worker);
    void run(int mapRows, int mapColumns, unsigned int mineralsCount);
};

#endif // !GAMEENGINE_h
