#pragma once
class Node
{
public:

	int iNData;
	Node *nNext, *nPrev;

	Node();
	~Node();
	Node(int data);
};