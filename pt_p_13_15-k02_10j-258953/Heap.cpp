#include "Heap.h"

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <time.h>
#include <chrono>
#include <ratio>

using namespace std;

Heap::Heap() 
{
	iHSize = 0;
	newHeap = new int[iHSize];
}

Heap::~Heap()
{

}

void Heap::heapMenu()
{
	short sHChoiceHeapMenu;

	for (;;)
	{
		shH.cls();

		cout << "Prosze wybrac:" << endl << "1.Menu dodawania." << endl << "2.Menu odejmowania." << endl << "3.Menu wyswietlania." << endl << "4.Powrot" << endl;
		cin >> sHChoiceHeapMenu;

		switch (sHChoiceHeapMenu)
		{
		case 1:
		{
			pushMenu();
			break;
		}
		case 2:
		{
			popMenu();
			break;
		}
		case 3:
		{
			displayMenu();
			break;
		}
		case 4:
		{
			return;
			break;
		}
		default:
		{
			shH.noOption();
			break;
		}
		}
	}
}

void Heap::pushMenu()
{
	for (;;)
	{
		shH.cls();

		short sHChoicePushMenu;

		cout << "Prosze wybrac:" << endl << "1.Dodanie elementu." << endl << "2.Wczytanie danych z pliku tekstowego." << endl << "3.Wygenerowanie okreslonej ilosci elementow." << endl << "4.Powrot." << endl;
		cin >> sHChoicePushMenu;

		switch (sHChoicePushMenu)
		{
		case 1:
		{
			pushElement();
			break;
		}
		case 2:
		{
			readFromFileH();
			break;
		}
		case 3:
		{
			generateElements();
			break;
		}
		case 4:
		{
			return;
			break;
		}
		default:
		{
			shH.noOption();
			break;
		}
		}
	}
}

void Heap::popMenu()
{
	short sHChoicePopMenu;

	for (;;)
	{
		shH.cls();

		cout << "Prosze wybrac:" << endl << "1.Usuniecie elementu ze strultury." << endl << "2.Usuniecie wszystkich elementow ze struktury." << endl << "3.Powrót." << endl;
		cin >> sHChoicePopMenu;

		switch (sHChoicePopMenu)
		{
		case 1:
		{
			popElement();
			break;
		}
		case 2:
		{
			clearAll();
			break;
		}
		case 3:
		{
			return;
			break;
		}
		default:
		{
			shH.noOption();
			break;
		}
		}
	}
}

void Heap::displayMenu()
{
	short sHChoiceDisplayMenu;

	for (;;)
	{
		shH.cls();

		cout << "Prosze wybrac:" << endl << "1.Wyswietlenie calej zawartosci struktury." << endl << "2.Wyswietlenie okreslonego elementu struktury." << endl << "3.Powrot." << endl;
		cin >> sHChoiceDisplayMenu;

		switch (sHChoiceDisplayMenu)
		{
		case 1:
		{
			displayAll();
			break;
		}
		case 2:
		{
			displayOne();
			break;
		}
		case 3:
		{
			return;
			break;
		}
		default:
		{
			shH.noOption();
			break;
		}
		}
	}
}

void Heap::pushElement()
{
	int iHNewEndElement;

	cout << "Podaj liczbe jaka ma byc dodana do kopca: " << endl;
	cin >> iHNewEndElement;

	auto o1 = chrono::high_resolution_clock::now();

	auto tempHeap = new int[iHSize + 1];

	tempHeap[iHSize] = iHNewEndElement;
	if (iHSize != 0)
	{
		for (int i = 0; i < iHSize; i++)
		{
			tempHeap[i] = newHeap[i];
		}
	}
	delete[] newHeap;
	newHeap = tempHeap;
	tempHeap = nullptr;
	iHSize++;
	auto o2 = chrono::high_resolution_clock::now();

	outcomeHeap.tMOutcome(o1, o2);

	shH.done();
}

void Heap::readFromFileH()
{

}

void Heap::generateElements()
{

}

void Heap::popElement()
{

}

void Heap::clearAll()
{

}

void Heap::displayAll()
{
	if (iHSize != 0)
	{
		auto o1 = chrono::high_resolution_clock::now();
		for (int i = 0; i < iHSize; i++)
		{
			cout << "Element nr " << i + 1 << " = " << newHeap[i] << endl;
		}
		auto o2 = chrono::high_resolution_clock::now();

		outcomeHeap.tMOutcome(o1, o2);
	}
	else
	{
		shH.empty();
	}
	shH.done();
}

void Heap::displayOne()
{

}

void Heap::HeapifyDown()
{

}

void Heap::HeapifyUp()
{

}

int Heap::getLeft(int x)
{
	return (x * 2 + 1);
}

int Heap::getRight(int x)
{
	return (x * 2 + 2);
}

int Heap::getParent(int x)
{
	return ((x - 1) / 2);
}