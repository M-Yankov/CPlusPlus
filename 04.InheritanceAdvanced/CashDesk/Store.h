#pragma once
#include <map>
#include <vector>

#include "Item.h"

class Store
{
private:
	std::vector<Item> items;
	long double _totalValue;
public:
	long double given;

	Store();
	Store(long double initialValue);
	bool itemExists(long key);
	long double getValueFromItem(long key);
	void setTotalValue(long double value);
	long double getTotalValue();

	void operator<<(const long double valueToAdd);
	std::string toString();
	void changeItemPrice(long code, double price);

	std::string printItems();
};

