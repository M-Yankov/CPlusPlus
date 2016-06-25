#include "NodeList.h"

#include <string>
#include <iostream>

NodeList::NodeList()
{
	
}

NodeList::NodeList(Node* root) : _current(root)
{

}

void NodeList::add(Node *node)
{
	if (!this->_current)
	{
		this->_current = node;
		return;
	}

	Node* next = this->_current->getNext();
	if (!next)
	{
		this->_current->setNext(node);
		return;
	}

	while (next->getNext())
	{
		next = next->getNext();
	}

	next->setNext(node);
}

std::string NodeList::print()
{
	Node* sub = _current;
	//char buffer[10];
	//std::sprintf(buffer, "%d", sub->getValue());

	std::cout << sub->getValue() << " " << std::endl;

	while (sub->getNext())
	{
		sub = sub->getNext();
		std::cout << sub->getValue() << " " <<  std::endl;
	}

	return "Done!";
}