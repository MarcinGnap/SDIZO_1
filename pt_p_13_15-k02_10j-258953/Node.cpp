/*
	Klasa, której zadaniem jest tworzenie pojedyñczych
	"komórek" w liœcie dwukierunkowej.
*/

#include "Node.h"

#include <iostream>

Node::Node()			//	Konstruktor domyœlny.
{
	iNData = NULL;
	nNext = NULL;
	nPrev = NULL;
}

Node::~Node()
{

}

Node::Node(int data)	//	Konstruktor z parametrem (wartoœci¹ jaka dana pozycja "przetrzymuje").
{
	this->iNData = data;
	this->nNext = NULL;
	this->nPrev = NULL;
}