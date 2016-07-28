#include "GameMap.h"

GameMap::GameMap() : isInitialized(false)
{
}

GameMap::~GameMap()
{
    for (std::vector<GameElement> elements : this->mapElements)
    {
        elements.clear();
    }

    this->mapElements.clear();
    this->isInitialized = false;
}

void GameMap::setItem(int row, int column, GameElement & gameElement)
{
    this->mapElements[row][column] = gameElement;
}

void GameMap::initializeMap(int rows, int columns)
{
    this->mapElements = std::vector<std::vector<GameElement>>(rows);

    for (int i = 0; i < rows; i++)
    {
        for (int col = 0; col < columns; col++)
        {
            this->mapElements[i].push_back(GameElement());
        }
    }

    this->isInitialized = true;
}

std::string GameMap::getMap()
{
    if (!this->isInitialized)
    {
        return "Game map is not initialized";
    }

    std::stringstream ss;
    for (std::vector<GameElement> row : this->mapElements)
    {
        for (GameElement columnCell : row)
        {
            ss << columnCell.symbol << " ";
        }

        ss << std::endl;
    }

    return ss.str();
}

