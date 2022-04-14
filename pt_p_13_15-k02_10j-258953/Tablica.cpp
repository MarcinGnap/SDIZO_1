#include "Tablica.h"

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <time.h>
#include <chrono>
#include <ratio>

using namespace std;

Tablica::Tablica()
{
	iTSize = 0;
	newTable = new int[iTSize];
}

Tablica::~Tablica()
{
	
}

void Tablica::tableMenu()
{
	short sTChoiceTableMenu;

	for (;;)
	{
		shT.cls();

		cout << "Prosze wybrac:" << endl << "1.Menu dodawania." << endl << "2.Menu odejmowania." << endl << "3.Menu wyswietlania." << endl << "4.Menu pomiarow i losowania elementow." << endl << "5.Powrot" << endl;
		cin >> sTChoiceTableMenu;

		switch (sTChoiceTableMenu)
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
			testMenu();
			break;
		}
		case 5:
		{
			return;
			break;
		}
		default:
		{
			shT.noOption();
			break;
		}
		}
	}
}

void Tablica::pushMenu()
{
	short sTChoicePushMenu;

	for (;;)
	{
		system("CLS");

		cout << "Prosze wybrac:" << endl << "1.Dodanie na poczatek struktury." << endl << "2.Dodanie na koniec struktury." << endl << "3.Dodanie w okreslonie miejsce w strukturze." << endl << "4.Wczytanie danych z pliku tekstowego do struktury." << endl << "5.Wylosowanie okreslonej liczby elementow do struktury." << endl << "6.Powrot" << endl;
		cin >> sTChoicePushMenu;

		switch (sTChoicePushMenu)
		{
		case 1:
		{
			pushFront();
			break;
		}
		case 2:
		{
			pushEnd();
			break;
		}
		case 3:
		{
			pushMiddle();
			break;
		}
		case 4:
		{
			readFromFileT();
			break;
		}
		case 5:
		{
			generateElements();
			break;
		}
		case 6:
		{
			return;
			break;
		}
		default:
		{
			shT.noOption();
			break;
		}
		}
	}
}

void Tablica::popMenu()
{
	short sTChoicePopMenu;

	for (;;)
	{
		shT.cls();

		cout << "Prosze wybrac:" << endl << "1.Usuniecie elementu z poczatku struktury." << endl << "2.Usuniecie elementu z konca struktury." << endl << "3.Usuniecie elementu z okreslonego miejsca w struktury." << endl << "4.Usuniecie wszystkich elementow ze struktury." << endl << "5.Powrot" << endl;
		cin >> sTChoicePopMenu;

		switch (sTChoicePopMenu)
		{
		case 1:
		{
			popFront();
			break;
		}
		case 2:
		{
			popEnd();
			break;
		}
		case 3:
		{
			popMiddle();
			break;
		}
		case 4:
		{
			clearAllT();
			break;
		}
		case 5:
		{
			return;
			break;
		}
		default:
		{
			shT.noOption();
			break;
		}
		}
	}
}

void Tablica::displayMenu()
{
	short sTChoiceDisplayMenu;

	for (;;)
	{
		shT.cls();

		cout << "Prosze wybrac:" << endl << "1.Wyswietlenie calej zawartosci struktury." << endl << "2.Wyswietlenie okreslonego elementu struktury." << endl << "3.Powrot." << endl;
		cin >> sTChoiceDisplayMenu;

		switch (sTChoiceDisplayMenu)
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
			shT.noOption();
			break;
		}
		}
	}
}

void Tablica::testMenu()
{
	short sTChoiceTestMenu;

	for (;;)
	{
		shT.cls();

		cout << "Prosze wybrac:" << endl;
		cin >> sTChoiceTestMenu;

		switch (sTChoiceTestMenu)
		{
		case 1:
		{
			
			break;
		}
		case 2:
		{
			
			break;
		}
		case 3:
		{
			return;
			break;
		}
		default:
		{
			shT.noOption();
			break;
		}
		}
	}
}

void Tablica::pushFront()
{
	int iTNewFrontElement;
	
	cout << "Podaj liczbe jaka ma byc dodana do tablicy: " << endl;
	cin >> iTNewFrontElement;
	
	auto o1 = chrono::high_resolution_clock::now();

	int iTTempSize = iTSize + 1;
	auto tempTable = new int[iTSize + 1];
	
	tempTable[0] = iTNewFrontElement;
	if (iTSize != 0)
	{
		for (int i = iTTempSize; i >= 1; i--)
		{
			tempTable[i] = newTable[i - 1];
		}
	}
	delete [] newTable;
	newTable = tempTable;
	tempTable = nullptr;
	iTSize++;
	auto o2 = chrono::high_resolution_clock::now();

	outcomeTable.tMOutcome(o1, o2);
	
	shT.done();
}

void Tablica::pushEnd()
{
	int iTNewEndElement;

	cout << "Podaj liczbe jaka ma byc dodana do tablicy: " << endl;
	cin >> iTNewEndElement;

	auto o1 = chrono::high_resolution_clock::now();

	auto tempTable = new int[iTSize + 1];

	tempTable[iTSize] = iTNewEndElement;
	if (iTSize != 0)
	{
		for (int i = 0; i < iTSize; i++)
		{
			tempTable[i] = newTable[i];
		}
	}
	delete [] newTable;
	newTable = tempTable;
	tempTable = nullptr;
	iTSize++;
	auto o2 = chrono::high_resolution_clock::now();

	outcomeTable.tMOutcome(o1, o2);

	shT.done();
}

void Tablica::pushMiddle()
{
	int iTNewMidElement;
	int iTPushPosition;

	cout << "Podaj pozycje, na ktora ma zostac dodany element (zakladamy ze numeracja zaczyna sie od 1): " << endl;
	cin >> iTPushPosition;

	int iTRightPush = iTPushPosition - 1;

	if (iTRightPush >= 0 && iTRightPush <= iTSize)
	{
		cout << "Podaj liczbe jaka ma byc dodana do tablicy: " << endl;
		cin >> iTNewMidElement;

		auto o1 = chrono::high_resolution_clock::now();
		auto tempTable = new int[iTSize + 1];
		tempTable[iTRightPush] = iTNewMidElement;
		for (int i = 0; i < iTRightPush; i++)
		{
			tempTable[i] = newTable[i];
		}
		for (int i = iTRightPush + 1; i < iTSize + 1; i++)
		{
			tempTable[i] = newTable[i-1];
		}
		delete [] newTable;
		newTable = tempTable;
		tempTable = nullptr;
		iTSize++;
		auto o2 = chrono::high_resolution_clock::now();

		outcomeTable.tMOutcome(o1, o2);
	}
	else
	{
		shT.away();
	}
	shT.done();
}

void Tablica::readFromFileT()
{
	ifstream ifTFile("dane.txt", ios::in);
	if (ifTFile.good())
	{
		shT.opened();		

		auto o1 = chrono::high_resolution_clock::now();
		string sTLineCountBuffer;
		getline(ifTFile, sTLineCountBuffer);
		int iTLineCount = stoi(sTLineCountBuffer);
		iTSize = iTLineCount;
		cout << "Ilosc elementow przekazanych do struktury: " << iTLineCount << endl;
		
		auto tempTable = new int[iTSize];

		for (int i = 1; i <= iTLineCount; i++)
		{
			string sTLineValueBuffer;
			getline(ifTFile, sTLineValueBuffer);
			
			int iTLineValue = stoi(sTLineValueBuffer);

			tempTable[i-1] = iTLineValue;
		}

		delete[] newTable;
		newTable = tempTable;
		tempTable = nullptr;

		ifTFile.close();

		auto o2 = chrono::high_resolution_clock::now();

		outcomeTable.tMOutcome(o1, o2);

		shT.done();
	}
	else
	{
		shT.noFile();
	}
}

void Tablica::generateElements()
{
	int iTNumberOfGen;
	cout << "Ile elementow ma zostac wygenerowanych?" << endl;
	cin >> iTNumberOfGen;

	auto o1 = chrono::high_resolution_clock::now();

	auto tempTable = new int[iTNumberOfGen];

	srand(time(0));

	for (int i = 0; i < iTNumberOfGen; i++)
	{
		int iTGenerated = rand();
		tempTable[i] = iTGenerated;
	}
	delete[] newTable;
	newTable = tempTable;
	tempTable = nullptr;
	iTSize = iTNumberOfGen;
	auto o2 = chrono::high_resolution_clock::now();

	outcomeTable.tMOutcome(o1, o2);

	shT.done();
}

void Tablica::popFront()
{
	if (iTSize != 0)
	{
		auto o1 = chrono::high_resolution_clock::now();
		auto tempTable = new int[iTSize - 1];

		for (int i = iTSize - 1; i >= 0; i--)
		{
			tempTable[i] = newTable[i + 1];
		}
		delete [] newTable;
		newTable = tempTable;
		tempTable = nullptr;
		iTSize--;
		auto o2 = chrono::high_resolution_clock::now();

		outcomeTable.tMOutcome(o1, o2);
	}
	else
	{
		shT.empty();
	}

	shT.done();
}

void Tablica::popEnd()
{
	if (iTSize != 0)
	{
		auto o1 = chrono::high_resolution_clock::now();
		auto tempTable = new int[iTSize - 1];

		for (int i = 0; i < iTSize - 1; i++)
		{
			tempTable[i] = newTable[i];
		}
		delete [] newTable;
		newTable = tempTable;
		tempTable = nullptr;
		iTSize--;
		auto o2 = chrono::high_resolution_clock::now();

		outcomeTable.tMOutcome(o1, o2);
	}
	else
	{
		shT.empty();
	}
	shT.done();
}

void Tablica::popMiddle()
{
	int iTPopPosition;

	cout << "Podaj pozycje, z ktorej ma zostac usuniety element (zakladamy ze numeracja zaczyna sie od 1): " << endl;
	cin >> iTPopPosition;

	int iTRightPop = iTPopPosition - 1;

	if (iTRightPop >= 0 && iTRightPop < iTSize)
	{
		auto o1 = chrono::high_resolution_clock::now();
		auto tempTable = new int[iTSize - 1];

		for (int i = 0; i < iTRightPop; i++)
		{
			tempTable[i] = newTable[i];
		}
		for (int i = iTRightPop; i < iTSize; i++)
		{
			tempTable[i] = newTable[i+1];
		}
		delete [] newTable;
		newTable = tempTable;
		tempTable = nullptr;
		iTSize--;
		auto o2 = chrono::high_resolution_clock::now();

		outcomeTable.tMOutcome(o1, o2);
	}
	else
	{
		shT.away();
	}
	shT.done();
}

void Tablica::clearAllT()
{
	if (iTSize != 0)
	{
		auto o1 = chrono::high_resolution_clock::now();
		delete [] newTable;
		iTSize = 0;
		auto o2 = chrono::high_resolution_clock::now();

		outcomeTable.tMOutcome(o1, o2);
	}
	else
	{
		cout << "Tablica nie ma elementow do usuniecia..." << endl;
	}

	shT.done();
}

void Tablica::displayAll()
{
	if (iTSize != 0)
	{
		auto o1 = chrono::high_resolution_clock::now();
		for (int i = 0; i < iTSize; i++)
		{
			cout << "Element nr " << i + 1 << " = " << newTable[i] << endl;
		}
		auto o2 = chrono::high_resolution_clock::now();

		outcomeTable.tMOutcome(o1,o2);
	}
	else
	{
		shT.empty();
	}
	shT.done();
}

void Tablica::displayOne()
{
	if (iTSize != 0)
	{
		int iTChoiceDisplay;

		cout << "Wybierz element, ktory chcesz wyswietlic (zakladamy ze numeracja zaczyna sie od 1): " << endl;
		cin >> iTChoiceDisplay;

		auto o1 = chrono::high_resolution_clock::now();

		if (iTChoiceDisplay >= 0 && iTChoiceDisplay < iTSize)
		{
			cout << "Element nr " << iTChoiceDisplay << " ma wartosc rowna: " << newTable[iTChoiceDisplay - 1] << endl;
		}
		else
		{
			cout << "Wybranego elementu nie ma w strukturze." << endl;
		}
		auto o2 = chrono::high_resolution_clock::now();

		outcomeTable.tMOutcome(o1, o2);
	}
	else
	{
		cout << "Struktura nie ma zawartosci..." << endl;
	}
	shT.done();
}