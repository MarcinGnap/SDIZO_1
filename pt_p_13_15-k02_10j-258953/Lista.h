#pragma once
#include "Node.h"
#include "timeMeasurement.h"
#include "SH.h"

class Lista
{
public:

	short sLChoiceListMenu;
	timeMeasurement outcomeList;
	SH shL;

	Lista();
	~Lista();

	void listMenu();

private:

	Node *nHead, *nTail;

	void pushMenu();
	void popMenu();
	void displayMenu();

	void pushFront();
	void pushEnd();
	void pushMiddle();

	void popFront();
	void popEnd();
	void popMiddle();

	void displayAll();
	void displayOne();
};