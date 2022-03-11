#include "Tablica.h"
#include "table.cpp"

#include <iostream>

using namespace std;

Tablica::Tablica()
{
	Table *nowaTablica = new Table;
}

Tablica::~Tablica()
{
	
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

}

void Tablica::pushEnd()
{

}

void Tablica::pushMiddle()
{

}

void Tablica::popFront()
{

}

void Tablica::popEnd()
{

}

void Tablica::popMiddle()
{

}

void Tablica::displayAll()
{

}

void Tablica::displayOne()
{

}