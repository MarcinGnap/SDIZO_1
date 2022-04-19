/*
	Klasa obs�uguj�ca list� dwukierunkow� i wszystkie metody z ni� zwi�zane.
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