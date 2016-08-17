#ifndef GAMEENGINE_h
#define GAMEENGINE_h

#include <vector>
#include <memory>

#include "GameMap.h"
#include "Worker.h"
#include "Catapult.h"
#include "Cell.h"

class GameEngine
{
private:
    std::shared_ptr<Mineral> sharedPointerMineral;
    GameMap gameMap;
public:
    GameEngine();
    GameEngine(GameMap & map);
    ~GameEngine();
    void moveWorker(Worker & worker);
    void strikeWithCatapult(Catapult & catapult, Worker & worker);
    void run(int mapRows, int mapColumns, unsigned int mineralsCount);
};

#endif // !GAMEENGINE_h
