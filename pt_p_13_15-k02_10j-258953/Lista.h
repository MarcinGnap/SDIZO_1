#pragma once
#include "list.cpp"

class Lista
{
	short sLChoiceListMenu;

	Lista();
	~Lista();

	List *findTail(val, head);

	void listMenu();

	void pushMenu();
	void popMenu();
	void displayMenu(List *head);

	void pushFront();
	void pushEnd();
	void pushMiddle();

	void popFront();
	void popEnd();
	void popMiddle();

	void displayAll(List *head);
	void displayOne();
};