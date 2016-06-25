#pragma once
class Node
{
private:
	Node* _next;
	int _value;

public:
	Node();
	Node(int number);
	void setNext(Node *nextNode);
	Node* getNext();

	int getValue();
};

