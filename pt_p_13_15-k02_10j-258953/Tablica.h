/*
	Klasa obs³uguj¹ca tablicê dynamiczn¹ i wszystkie metody z ni¹ zwi¹zane.
*/

#pragma once
#include "timeMeasurement.h"
#include "SH.h"

class Tablica
{
public:
	int iTSize;
	int *newTable = nullptr;
	timeMeasurement outcomeTable;
	SH shT;

	Tablica();
	~Tablica();

	void tableMenu();

private:

	void pushMenu();
	void popMenu();
	void displayMenu();
	void testMenu();

	void pushFront(int);
	void pushEnd(int);
	void pushMiddle(int, int);
	void readFromFileT();
	void generateElements(int);

	void popFront();
	void popEnd();
	void popMiddleIndex(int);
	void popMiddleValue(int);
	void clearAllT();

	void displayAll();
	bool displayOneValue(int);
	void displayOneIndex(int);

	void testPush();
	void testPop();
	void testSearch();
};