/*
	Klasa, kt�rej zadaniem jest tworzenie pojedy�czych
	"kom�rek" w li�cie dwukierunkowej.
*/

#include "Node.h"

#include <iostream>

Node::Node()			//	Konstruktor domy�lny.
{
	iNData = NULL;
	nNext = NULL;
	nPrev = NULL;
}

Node::~Node()
{

}

Node::Node(int data)	//	Konstruktor z parametrem (warto�ci� jaka dana pozycja "przetrzymuje").
{
	this->iNData = data;
	this->nNext = NULL;
	this->nPrev = NULL;
}