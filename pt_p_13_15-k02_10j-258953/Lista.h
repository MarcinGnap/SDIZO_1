#pragma once
#include "timeMeasurement.h"


class Lista
{
public:

	short sLChoiceListMenu;

	Lista();
	~Lista();

	void listMenu();

private:

	int iLData;
	Lista *next, *prev;

	void pushMenu();
	void popMenu();
	void displayMenu();

	void pushFront(Lista &*head);
	void pushEnd();
	void pushMiddle();

	void popFront();
	void popEnd();
	void popMiddle();

	void displayAll(Lista *head);
	void displayOne();
};