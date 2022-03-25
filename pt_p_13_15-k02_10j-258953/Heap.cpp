#include "Heap.h"
#include <iostream>

using namespace std;

Heap::Heap() {

}

Heap::~Heap()
{

}

int Heap::checkLeft(int i)
{
	return (i * 2 + 1);
}

int Heap::checkRight(int i)
{
	return (i * 2 + 2);
}

int Heap::checkParent(int i)
{
	return (i - 1) / 2;
}

unsigned int Heap::getSize()
{
	return (sizeof(iHTab) / sizeof(*iHTab));
}

bool Heap::isEmpty()
{
	return getSize() == 0;
}

void Heap::pushElement()
{
	unsigned int uiIndex = getSize() - 1;
	int iNewElement;
	cout << "Podaj wartosc jaka chcesz dodac do kopca:" << endl;
	cin >> iNewElement;

	iHTab[uiIndex] = iNewElement;

	HeapifyUp(uiIndex);
}

void Heap::popElement()
{
	iHTab[0] = iHTab[getSize() - 1];
}

void Heap::HeapifyDown()
{

}

void Heap::HeapifyUp(int i)
{

}

void Heap::displayAll()
{

}