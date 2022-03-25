#include "Heap.h"
#include <iostream>

using namespace std;

Heap::Heap() {

}

Heap::~Heap()
{

}

void Heap::heapMenu()
{
	short sHChoiceHeapMenu;

	for (;;)
	{
		system("CLS");

		cout << "Prosze wybrac:" << endl << "1.Dodanie elementu." << endl << "2.Usuniecie elementu." << endl << "3.Wyswietlenie struktury." << endl << "4.Powrot" << endl;
		cin >> sHChoiceHeapMenu;

		switch (sHChoiceHeapMenu)
		{
		case 1:
		{
			pushElement();
			break;
		}
		case 2:
		{
			popElement();
			break;
		}
		case 3:
		{
			displayAll();
			break;
		}
		case 4:
		{
			return;
			break;
		}
		default:
		{
			cout << "Nie ma takiej opcji..." << endl << "Prosze wybrac cos innego..." << endl;
			break;
		}
		}
	}
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
	return (0);
}

bool Heap::isEmpty()
{
	return getSize() == 0;
}

void Heap::pushElement()
{
	/*unsigned int uiIndex = getSize() - 1;
	int iNewElement;
	cout << "Podaj wartosc jaka chcesz dodac do kopca:" << endl;
	cin >> iNewElement;

	iHTab[uiIndex] = iNewElement;

	HeapifyUp(uiIndex);
*/}

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