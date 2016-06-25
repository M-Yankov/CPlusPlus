#pragma once
#include "Node.h"
#include <string>

class NodeList
{
private:
	Node* _current;
public:
	NodeList();
	NodeList(Node *root);
	void add(Node *node);
	std::string print();
};

