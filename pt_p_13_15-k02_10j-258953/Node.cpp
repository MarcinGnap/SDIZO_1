#include "Node.h"

#include <iostream>

Node::Node()
{
	iNData = NULL;
	nNext = NULL;
	nPrev = NULL;
}

Node::~Node()
{

}

Node::Node(int data)
{
	this->iNData = data;
	this->nNext = NULL;
	this->nPrev = NULL;
}