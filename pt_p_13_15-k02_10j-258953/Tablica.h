#pragma once
#include "timeMeasurement.h"

class Tablica
{
public:
	int iTSize;
	int *newTable = nullptr;
	timeMeasurement outcomeTable;

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
};