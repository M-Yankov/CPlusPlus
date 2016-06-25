#include "Node.h"
#include <iostream>

Node::Node() : _value(0)
{
	_next = NULL;
}

Node::Node(int number) : _value(number)
{
	_next = NULL;
}

Node* Node::getNext()
{
	return this->_next;
}

void Node::setNext(Node *nextNode)
{
	this->_next = nextNode;
}

int Node::getValue()
{
	return this->_value;
}