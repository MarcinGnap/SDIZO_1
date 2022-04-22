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
	void testMenu();

	void pushFront(int);
	void pushEnd(int);
	bool pushMiddleValue(int, int);
	bool pushMiddleIndex(int, int);
	void readFromFileL();
	void generateElements(int);

	void popFront();
	void popEnd();
	bool popMiddleValue(int);
	bool popMiddleIndex(int);
	void clearAll();

	void displayAll();
	bool displayOneValue(int);
	int displayOneIndex(int);

	void testPush();
	void testPop();
	void testSearch();
};