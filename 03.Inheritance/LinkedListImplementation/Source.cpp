#include "NodeList.h"
#include <iostream>
#include <vector>

int main()
{
	Node root = Node(1);
	NodeList list = NodeList(&root);

	std::vector<Node> nodeS = { Node(8), Node(16), Node(23), Node(31), Node(45) };

	for (size_t i = 0; i < nodeS.size(); i++)
	{
		list.add(&nodeS[i]);
	}

	list.print();

	return 0;
}