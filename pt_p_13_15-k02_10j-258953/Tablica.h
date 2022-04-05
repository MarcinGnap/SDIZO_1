#pragma once
#include "table.cpp"

#include <chrono>

class Tablica
{
public:
	int iTSize;
	int *newTable = nullptr;
	std::chrono::high_resolution_clock::time_point o1;
	std::chrono::high_resolution_clock::time_point o2;

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