#include "Store.h"

#include <vector>
#include <algorithm>

Store::Store() : Store(0)
{
}

Store::Store(long double initialValue) : _totalValue(initialValue), given(-1)
{
	Item test = Item(1111111, 231.3111);

	// not working ....
	this->items.push_back(test);
	this->items.push_back(Item(1111111111, 13.34));
	this->items.push_back(Item(1111111112, 11.13));
	this->items.push_back(Item(1111111113, 9.99));
	this->items.push_back(Item(1111111114, 15.59));
	this->items.push_back(Item(1111111115, 18.34));
	this->items.push_back(Item(1111111116, 6.05));
}

bool Store::itemExists(long key)
{
	std::vector<Item>::iterator it = std::find_if(
		this->items.begin(),
		this->items.end(),
		[key](const Item &item)
	{
		return item.getKey() == key;
	});

	if (it != this->items.end())
	{
		return true;
	}

	return false;
}

long double Store::getValueFromItem(long key)
{
	std::vector<Item>::iterator it = std::find_if(
		this->items.begin(),
		this->items.end(),
		[key](const Item &item)
	{
		return item.getKey() == key;
	});


	if (it != this->items.end())
	{
		return it->getValue();
	}

	throw "Cannot find Item";
}

void Store::setTotalValue(long double value)
{
	if (value < 0)
	{
		throw "value cannot be negative";
	}

	_totalValue = value;
}

long double Store::getTotalValue()
{
	return this->_totalValue;
}

void Store::operator<<(long double value)
{
	this->_totalValue += value;
}

char * Store::toString()
{
	char buffer[100];
	const char * format = "CandyShop\n "
		"BIC:12345678\n"
		"Address: Somewhere in the middle of nowhere\n"
		"Purchases: 2.2f leva\n"
		"Given: 2.2f\n"
		"Change: 2.2f\n";

	if (given == -1)
	{
		return "You should give money first.";
	}

	std::sprintf(buffer, format, this->_totalValue, this->given, this->given - this->_totalValue);

	return buffer;
}

void Store::changeItemPrice(long code, double price)
{
	std::vector<Item>::iterator it = std::find_if(
		this->items.begin(),
		this->items.end(),
		[code](const Item &item)
	{
		return item.getKey() == code;
	});

	if (it != this->items.end())
	{
		it->setValue(price);
	}
}