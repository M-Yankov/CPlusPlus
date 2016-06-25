#pragma once

class Item
{
private:
	long _key;
	double _price;
	void setValue(double newValue);

public:
	// copy constructor.
	Item(const Item &item);
	Item(long, double newValue);
	double getValue() const;
	long getKey() const;

	friend class Store;
};

