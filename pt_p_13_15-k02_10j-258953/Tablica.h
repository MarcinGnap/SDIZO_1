#pragma once
#include "table.cpp"

class Tablica
{
public:
	int iTSize;
	int *newTable = nullptr;

	Tablica();
	~Tablica();

	void tableMenu();

private:

	void pushMenu();
	void popMenu();
	void displayMenu();

	void pushFront();
	void pushEnd();
	void pushMiddle();
	void readFromFileT();

	void popFront();
	void popEnd();
	void popMiddle();
	void clearAllT();

	void displayAll();
	void displayOne();
};