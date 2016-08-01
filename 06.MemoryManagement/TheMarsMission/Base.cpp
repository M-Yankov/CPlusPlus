#include "Base.h"

Base::Base() : Base(this->defaultHealth, this->defaultSymbol)
{
}

Base::Base(unsigned int initialHealth, char initialSymbol) : health(initialHealth), GameElement(initialSymbol)
{
}

Base::~Base()
{
}

unsigned int Base::getHealth()
{
    return this->health;
}
