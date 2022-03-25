#include "Tablica.h"
#include "table.cpp"

#include <iostream>

using namespace std;

Tablica::Tablica()
{
	int *nowaTablica = new int[];  //add here loading datas from text file or do it in another place
}

Tablica::~Tablica()
{
	delete *nowaTablica;
}

void Tablica::tableMenu()
{
	short sTChoiceTableMenu;

	cout << "Prosze wybrac:" << endl << "1.Menu dodawania." << endl << "2.Menu odejmowania." << endl << "3.Menu wyswietlania." << endl << "4.Powrot" << endl;
	cin >> sTChoiceTableMenu;

	switch (sTChoiceTableMenu)
	{
	case 1:
	{
		void pushMenu();
		break;
	}
	case 2:
	{
		void popMenu();
		break;
	}
	case 3:
	{
		void displayMenu();
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

void Tablica::pushMenu()
{
	short sTChoicePushMenu;

	cout << "Prosze wybrac:" << endl << "1.Dodanie na poczatek struktury." << endl << "2.Dodanie na koniec struktury." << endl << "3.Dodanie w okreslonie miejsce w strukturze." << endl << "4.Powrot" << endl;
	cin >> sTChoicePushMenu;

	switch (sTChoicePushMenu)
	{
	case 1:
	{
		void pushFront();
		break;
	}
	case 2:
	{
		void pushEnd();
		break;
	}
	case 3:
	{
		void pushMiddle();
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

void Tablica::popMenu()
{
	short sTChoicePopMenu;

	cout << "Prosze wybrac:" << endl << "1.Usuniecie elementu z poczatku struktury." << endl << "2.Usuniecie elementu z konca struktury." << endl << "3.Usuniecie elementu z okreslonego miejsca w struktury." << endl << "4.Powrot" << endl;
	cin >> sTChoicePopMenu;

	switch (sTChoicePopMenu)
	{
	case 1:
	{
		void popFront();
		break;
	}
	case 2:
	{
		void popEnd();
		break;
	}
	case 3:
	{
		void popMiddle();
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

void Tablica::displayMenu()
{
	short sTChoiceDisplayMenu;

	cout << "Prosze wybrac:" << endl << "1.Wyswietlenie calej zawartosci struktury." << endl << "2.Wyswietlenie okreslonego elementu struktury." << endl << "3.Powrot." << endl;
	cin >> sTChoiceDisplayMenu;

	switch (sTChoiceDisplayMenu)
	{
	case 1:
	{
		void displayAll();
		break;
	}
	case 2:
	{
		void displayOne();
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
		break;
	}
	}
}

void Tablica::pushFront()
{

    uiTIndex++;
}

void Tablica::pushEnd()
{

    uiTIndex++;
}

void Tablica::pushMiddle()
{

    uiTIndex++;
}

void Tablica::popFront()
{

    uiTIndex--;
}

void Tablica::popEnd()
{

    uiTIndex--;
}

void Tablica::popMiddle()
{
    uiTIndex--;
}

void Tablica::displayAll()
{

}

void Tablica::displayOne()
{

}

unsigned int Tablica::getSize()  //tutaj dodać unsigned int uiTindex ?
{
    return (uiTIndex + 1);
}