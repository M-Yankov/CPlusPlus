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

void Base::takeDamage(unsigned int reduceHealth)
{
    if (this->minerals.size() == 0)
    {
        if (this->health - reduceHealth >= 0)
        {
            this->health -= reduceHealth;
        }
        else
        {
            this->health = 0;
        }
    }
    else
    {
        this->minerals.erase(this->minerals.begin());
    }
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
