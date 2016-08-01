#include <iostream>

/// <summary>
/// Task description:
/// Minerals on the Mars.
/// In the game exists the following objects: Worker, Base, Map, Minerals, Enemy catapult.
/// The map is a sample two dimensional array (table N x M). At [0,0] on the map is placed the Base.
/// At bottom-right corner [N - 1, M - 1] there is the enemy catapult. Minerals are on random cells on the map.
/// The Worker starts from the Base and it's task is to bring all minerals to the base. The enemy catapult makes shot
/// every 3s to a random cell. One move from one cell to another of the worker costs 1s.
/// If the catapult hits the worker - he is returned to the base. Then the Base loses 1 mineral or 20% 
/// of initial health. If the worker holds a mineral while it is hit, then only the mineral is destroyed.
/// If the catapult hits just a mineral - nothing happens. The catapult cannot hit directly the Base.
/// 
/// From the console you will receive N and M one line.
/// On the second line the numbers of minerals
///
/// Constraints:
/// N and M will be always between 4 and 100.
/// Number of minerals will be less than (N * M) - 4. 
///
/// Your task:
/// *   Implement a logic that fills the map with minerals on the random places. 
///     *   Each start of application minerals should be placed on different cells.
/// *   Initial health of the Base is 100.
/// *   Worker move costs 1s.
/// *   worker can wear only 1 mineral at time.
/// *   The catapults fires every 3s.
/// *   Print the Base info when worker brings mineral or is damage taken.
///     *   Format "Base X Minerals X Health"  
/// *   Implement a logic for get all minerals on the map. (Don't waste moves).
/// *   Print the map after each move of worker and after each shot of catapult.
/// *   Use weak point for Base and Worker holds minerals.
///     *   Base symbol - B
///     *   Worker symbol - O
///     *   Empty cell - ·  (middle dot char code 250)
///     *   Mineral symbol - M
///     *   Catapult strikes symbol - X
///     *   Catapult symbol - <
///     *   Split cells with one space
/// *   Clear console before print.
/// *   Implement logic for random fire of catapult.
/// *   The game ends when all minerals are collected or the base is destroyed.
/// *   When game is finished print Base info.
/// Sample Input:
/// 4 4
/// 5
///
/// Sample output:
/// B · · M
/// · M · M
/// · · M ·
/// M · · <

/// B · · M
/// O M · M
/// · · M ·
/// M · · <

/// B · · M
/// · O · M
/// · · M ·
/// M · · <

/// B · · M
/// O · · M
/// · X M ·
/// M · · <

/// B · · M
/// · · · M
/// · · M ·
/// M · · <
/// Base: 1 Minerals 100 health
/// </summary>
/// <returns></returns>
#include "Mineral.h"
#include "GameMap.h"
#include "RandomGenerator.h"
#include "CellHash.h"
#include "Base.h"
#include "Worker.h"
#include <vector>
#include <exception>
#include <unordered_set>

int main()
{
    const int Matrix = 9;
    const int Mirealscount = 12;

    GameMap map = GameMap();
    map.initializeMap(Matrix, Matrix);
    map.randomizeMinerals(Mirealscount);

    std::cout << map.getMap() << std::endl;

    Worker worker = Worker(map);
    worker.FindClosestMineralOnTheMap();
    return 0;
}