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

	void pushElement();
	void readFromFileH();
	void generateElements();

	void popElement();
	void clearAll();

	void displayAll();
	void displayOne();

	void HeapifyDown();
	void HeapifyUp();

	int getLeft(int x);
	int getRight(int x);
	int getParent(int x);
};