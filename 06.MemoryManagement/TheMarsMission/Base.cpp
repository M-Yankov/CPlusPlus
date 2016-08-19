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

void Base::addMineral(Mineral & mineral)
{
    // problem with destructor.
    this->minerals.push_back(mineral);
}

std::string Base::toString()
{
    char buffer[100];
    std::sprintf(buffer, "Base: %d Minerals %d Health", this->minerals.size(), (int)this->health);
    return buffer;
}
