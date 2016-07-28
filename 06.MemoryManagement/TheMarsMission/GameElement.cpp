#include "GameElement.h"
#include <iostream>

GameElement::GameElement() : symbol(this->defaultCharSymbol)
{
}

GameElement::GameElement(char initialSymbol) : symbol(initialSymbol)
{
}

GameElement::~GameElement()
{
    // std::cout << "Game element destroyed!" << std::endl;
}
