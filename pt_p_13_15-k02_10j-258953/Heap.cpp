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

void Heap::heapMenu()									//	Menu g³ówne kopca.
{
	short sHChoiceHeapMenu;

	for (;;)
	{
		shH.cls();										//	"Wyczyszczenie" ekranu u¿ytkowanika.

		cout << "Prosze wybrac:\n"
				"\t1.Menu dodawania.\n"
				"\t2.Menu odejmowania.\n"
				"\t3.Menu wyswietlania.\n"
				"\t4.Powrot.\n";
		cin >> sHChoiceHeapMenu;						//	Wybór opcji.

		switch (sHChoiceHeapMenu)
		{
		case 1:
		{
			pushMenu();									//	Menu dodawania.
			break;
		}
		case 2:
		{
			popMenu();									//	Menu usuwania z kopca.
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

		cout << "Prosze wybrac:\n"
				"\t1.Dodanie elementu.\n"
				"\t2.Wczytanie danych z pliku tekstowego.\n"
				"\t3.Wygenerowanie okreslonej ilosci elementow.\n"
				"\t4.Powrot.\n";
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

		cout << "Prosze wybrac:\n"
				"\t1.Usuniecie elementu ze strultury.\n"
				"\t2.Usuniecie wszystkich elementow ze struktury.\n"
				"\t3.Powrot.\n";
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

		cout << "Prosze wybrac:\n"
				"\t1.Wyswietlenie calej zawartosci struktury.\n"
				"\t2.Wyswietlenie okreslonego elementu struktury.\n"
				"\t3.Powrot.\n";
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

	cout << "Podaj liczbe jaka ma byc dodana do kopca:\n";
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
	
	HeapifyUp();

	auto o2 = chrono::high_resolution_clock::now();

	outcomeHeap.tMOutcome(o1, o2);

	shH.done();
}

void Heap::readFromFileH()
{
	ifstream ifHFile("dane.txt", ios::in);
	if (ifHFile.good())
	{
		shH.opened();

		auto o1 = chrono::high_resolution_clock::now();
		string sHLineCountBuffer;
		getline(ifHFile, sHLineCountBuffer);
		int iHLineCount = stoi(sHLineCountBuffer);
		cout << "Ilosc elementow przekazanych do struktury: " << iHLineCount << endl;

		auto tempHeap = new int[iHSize];

		for (int i = 1; i <= iHLineCount; i++)
		{
			string sHLineValueBuffer;
			getline(ifHFile, sHLineValueBuffer);

			int iHLineValue = stoi(sHLineValueBuffer);

			tempHeap[i - 1] = iHLineValue;
			iHSize++;
			HeapifyUp();
		}
		delete[] newHeap;
		newHeap = tempHeap;
		tempHeap = nullptr;

		ifHFile.close();

		auto o2 = chrono::high_resolution_clock::now();

		outcomeHeap.tMOutcome(o1, o2);

		shH.done();
	}
	else
	{
		shH.noFile();
	}
}

void Heap::generateElements()
{
	int iHNumberOfGen;
	cout << "Ile elementow ma zostac wygenerowanych?\n";
	cin >> iHNumberOfGen;

	auto o1 = chrono::high_resolution_clock::now();

	srand(time(0));

	delete[] newHeap;
	newHeap = new int[iHNumberOfGen];
	
	for (int i = 0; i < iHNumberOfGen; i++)
	{
		newHeap[i] = rand();
		iHSize++;
		HeapifyUp();
	}

	auto o2 = chrono::high_resolution_clock::now();

	outcomeHeap.tMOutcome(o1, o2);

	shH.done();
}

void Heap::popElement()
{
	if (iHSize != 0)
	{
		auto o1 = chrono::high_resolution_clock::now();
		auto tempHeap = new int[iHSize - 1];

		tempHeap[0] = newHeap[iHSize - 1];
		for (int i = 1; i < iHSize - 1; i++)
		{
			tempHeap[i] = newHeap[i];
		}
		delete[] newHeap;
		newHeap = tempHeap;
		tempHeap = nullptr;
		iHSize--;

		HeapifyDown();

		auto o2 = chrono::high_resolution_clock::now();

		outcomeHeap.tMOutcome(o1, o2);
	}
	else
	{
		shH.empty();
	}

	shH.done();
}

void Heap::clearAll()
{
	if (iHSize != 0)
	{
		auto o1 = chrono::high_resolution_clock::now();
		delete[] newHeap;
		iHSize = 0;
		auto o2 = chrono::high_resolution_clock::now();

		outcomeHeap.tMOutcome(o1, o2);
	}
	else
	{
		shH.empty();
	}

	shH.done();
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
	if (iHSize != 0)
	{
		int iHChoiceDisplay;

		cout << "Wybierz element, ktory chcesz wyswietlic:\n";
		cin >> iHChoiceDisplay;

		auto o1 = chrono::high_resolution_clock::now();

		for (int i = 0; i<iHSize; i++)
		{
			if (iHChoiceDisplay == newHeap[i])
			{
				cout << "Wybrany element " << iHChoiceDisplay << " znajduje sie w strukturze.\n";
				goto displayed;
			}
		}
		cout << "Wybranego elementu nie ma w strukturze.\n";
		displayed:
		auto o2 = chrono::high_resolution_clock::now();

		outcomeHeap.tMOutcome(o1, o2);
	}
	else
	{
		shH.empty();
	}
	shH.done();
}

void Heap::HeapifyDown()
{
	int x = 0;
	while (x < iHSize && (newHeap[x] < newHeap[getLeft(x)] || newHeap[x] < newHeap[getRight(x)]))
	{
		int tempParent = newHeap[x];
		if (newHeap[getLeft(x)] >= newHeap[getRight(x)])
		{
			newHeap[x] = newHeap[getLeft(x)];
			newHeap[getLeft(x)] = tempParent;
			x = getLeft(x);
		}
		else if (newHeap[getLeft(x)] < newHeap[getRight(x)])
		{
			newHeap[x] = newHeap[getRight(x)];
			newHeap[getRight(x)] = tempParent;
			x = getRight(x);
		}
	}
}

void Heap::HeapifyUp()
{
	if (iHSize > 0)
	{
		int x = iHSize - 1;
		while (x != 0 && newHeap[getParent(x)] < newHeap[x])
		{
			int tempValue = newHeap[getParent(x)];
			newHeap[getParent(x)] = newHeap[x];
			newHeap[x] = tempValue;
			x = getParent(x);
		}
	}
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
	return floor((x - 1) / 2);
}