#include "Tablica.h"
#include "SH.h"
#include "table.cpp"

#include <iostream>
#include <stdlib.h>

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
		system("CLS");

		cout << "Prosze wybrac:" << endl << "1.Menu dodawania." << endl << "2.Menu odejmowania." << endl << "3.Menu wyswietlania." << endl << "4.Powrot" << endl;
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
			return;
			break;
		}
		default:
		{
			cout << "Nie ma takiej opcji..." << endl << "Prosze wybrac cos innego..." << endl;
			getchar();
			getchar();
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

		cout << "Prosze wybrac:" << endl << "1.Dodanie na poczatek struktury." << endl << "2.Dodanie na koniec struktury." << endl << "3.Dodanie w okreslonie miejsce w strukturze." << endl << "4.Powrot" << endl;
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
			return;
			break;
		}
		default:
		{
			cout << "Nie ma takiej opcji..." << endl << "Prosze wybrac cos innego..." << endl;
			getchar();
			getchar();
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
		system("CLS");

		cout << "Prosze wybrac:" << endl << "1.Usuniecie elementu z poczatku struktury." << endl << "2.Usuniecie elementu z konca struktury." << endl << "3.Usuniecie elementu z okreslonego miejsca w struktury." << endl << "4.Powrot" << endl;
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
			return;
			break;
		}
		default:
		{
			cout << "Nie ma takiej opcji..." << endl << "Prosze wybrac cos innego..." << endl;
			getchar();
			getchar();
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
		system("CLS");

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
			cout << "Nie ma takiej opcji..." << endl << "Prosze wybrac cos innego..." << endl;
			getchar();
			getchar();
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
	
	cout << "Operacja wykonana." << endl << "Nacisnij Enter, zeby kontynuwac..." << endl;
	getchar();
	getchar();
	system("CLS");
}

void Tablica::pushEnd()
{
	int iTNewEndElement;

	cout << "Podaj liczbe jaka ma byc dodana do tablicy: " << endl;
	cin >> iTNewEndElement;

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

	cout << "Operacja wykonana." << endl << "Nacisnij Enter, zeby kontynuwac..." << endl;
	getchar();
	getchar();
	system("CLS");
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
	}
	else
	{
		cout << "Wybrana pozycja znajduje sie poza tablica..." << endl << "Wybierz inna pozycje..." << endl;
	}
	cout << "Operacja wykonana." << endl << "Nacisnij Enter, zeby kontynuwac..." << endl;
	getchar();
	getchar();
	system("CLS");
}

void Tablica::popFront()
{
	if (iTSize != 0)
	{
		auto tempTable = new int[iTSize - 1];

		for (int i = iTSize - 1; i >= 0; i--)
		{
			tempTable[i] = newTable[i + 1];
		}
		delete [] newTable;
		newTable = tempTable;
		tempTable = nullptr;
		iTSize--;
	}
	else
	{
		cout << "Tablica nie ma elementow do usuniecia..." << endl;
	}

	cout << "Operacja wykonana." << endl << "Nacisnij Enter, zeby kontynuwac..." << endl;
	getchar();
	getchar();
	system("CLS");
}

void Tablica::popEnd()
{
	if (iTSize != 0)
	{
		auto tempTable = new int[iTSize - 1];

		for (int i = 0; i < iTSize - 1; i++)
		{
			tempTable[i] = newTable[i];
		}
		delete [] newTable;
		newTable = tempTable;
		tempTable = nullptr;
		iTSize--;
	}
	else
	{
		cout << "Tablica nie ma elementow do usuniecia..." << endl;
	}
	cout << "Operacja wykonana." << endl << "Nacisnij Enter, zeby kontynuwac..." << endl;
	getchar();
	getchar();
	system("CLS");
}

void Tablica::popMiddle()
{
	int iTPopPosition;

	cout << "Podaj pozycje, z ktorej ma zostac usuniety element (zakladamy ze numeracja zaczyna sie od 1): " << endl;
	cin >> iTPopPosition;
	int iTRightPop = iTPopPosition - 1;

	if (iTRightPop >= 0 && iTRightPop < iTSize)
	{
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
	}
	else
	{
		cout << "Wybrana pozycja znajduje sie poza tablica..." << endl << "Wybierz inna pozycje..." << endl;
	}
	cout << "Operacja wykonana." << endl << "Nacisnij Enter, zeby kontynuwac..." << endl;
	getchar();
	getchar();
	system("CLS");
}

void Tablica::displayAll()
{
	if (iTSize != 0)
	{
		for (int i = 0; i < iTSize; i++)
		{
			cout << "Element nr " << i + 1 << " = " << newTable[i] << endl;
		}
	}
	else
	{
		cout << "Struktura nie ma zawartosci..." << endl;
	}
	cout << "Operacja wykonana." << endl << "Nacisnij Enter, zeby kontynuwac..." << endl;
	getchar();
	getchar();
	system("CLS");
}

void Tablica::displayOne()
{
	if (iTSize != 0)
	{
		int iTChoiceDisplay;

		cout << "Wybierz element, ktory chcesz wyswietlic (zakladamy ze numeracja zaczyna sie od 1): " << endl;
		cin >> iTChoiceDisplay;

		if (iTChoiceDisplay >= 0 && iTChoiceDisplay < iTSize)
		{
			cout << "Element nr " << iTChoiceDisplay << " ma wartosc rowna: " << newTable[iTChoiceDisplay - 1] << endl;
		}
		else
		{
			cout << "Wybranego elementu nie ma w strukturze." << endl;
		}
	}
	else
	{
		cout << "Struktura nie ma zawartosci..." << endl;
	}
	cout << "Operacja wykonana." << endl << "Nacisnij Enter, zeby kontynuwac..." << endl;
	getchar();
	getchar();
	system("CLS");
}