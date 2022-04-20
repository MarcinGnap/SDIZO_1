/*
	Klasa obs³uguj¹ca kopiec maksymalny i wszystkie metody z nim zwi¹zane.
*/

#pragma once
#include "timeMeasurement.h"
#include "SH.h"

class Heap {
public:

	short sHChoiceHeapMenu;
	int iHSize;
	int *newHeap = nullptr;
	SH shH;
	timeMeasurement outcomeHeap;

	Heap();
	~Heap();

	void heapMenu();

private:

	void pushMenu();
	void popMenu();
	void displayMenu();
	void testMenu();

	void pushElement();
	void readFromFileH();
	void generateElements();

	void popElement();
	void clearAll();

	void displayAll();
	void displayOne();

	void HeapifyDown(int);
	void HeapifyUp();

	int getLeft(int);
	int getRight(int);
	int getParent(int);

	void testPush();
	void testPop();
	void testSearch();

	void generateElementsTest(int);
	void clearAllTTest();

	void pushTest();

	void popTest();

	void searchTest(int);
};