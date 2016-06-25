#include "Item.h"

Item::Item(long key, double newValue) : _key(key)
{
	this->_price = 0;
	this->_price = newValue;
	this->setValue(newValue);
}

// copy constructor
Item::Item(const Item & item) : _key(item.getKey())
{
}

double Item::getValue()
{
	return this->_price;
}

void Item::setValue(double price)
{
	if (price < 0)
	{
		throw "Value should be positive.";
	}

	this->_price = price;
}

long Item::getKey() const
{
	return this->_key;
}

