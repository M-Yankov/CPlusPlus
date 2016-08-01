#pragma once
class GameElement
{
private:
     static const char defaultCharSymbol = 249; // ∙
public:
    GameElement();
    GameElement(char initialSymbol);
    ~GameElement();
    char symbol;
};