/*
	Klasa obs³uguj¹ca listê dwukierunkow¹ i wszystkie metody z ni¹ zwi¹zane.
*/

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
	void readFromFileL();
	void generateElements();

	void popFront();
	void popEnd();
	void popMiddle();
	void clearAll();

	void displayAll();
	void displayOne();
};