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

	void pushFront();
	void pushEnd();
	void pushMiddle();
	void readFromFileT();
	void generateElements();

	void popFront();
	void popEnd();
	void popMiddle();
	void clearAllT();

	void displayAll();
	void displayOne();

	void testPush();
	void testPop();
	void testSearch();

	void generateElementsTest(int);
	void clearAllTTest();

	void pushFrontTest();
	void pushEndTest();
	void pushMiddleTest(int);

	void popFrontTest();
	void popEndTest();
	void popMiddleTest(int);

	void searchTest(int);
};