#pragma once
class GameElement
{
private:
     char defaultCharSymbol = 249; // ∙
public:
    GameElement();
    GameElement(char initialSymbol);
    ~GameElement();
    char symbol;
};