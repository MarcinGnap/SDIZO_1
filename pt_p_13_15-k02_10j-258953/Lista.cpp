#include "Lista.h"
#include "list.cpp"

#include <iostream>

using namespace std;

Lista::Lista()
{
	Lista *nowaLista = new Lista;
}

Lista::~Lista()
{

}

void Lista::listMenu()
{
	short sLChoiceListMenu;

	cout << "Prosze wybrac:" << endl << "1.Menu dodawania." << endl << "2.Menu odejmowania." << endl << "3.Menu wyswietlania." << endl << "4.Powrot" << endl;
	cin >> sLChoiceListMenu;

	switch (sLChoiceListMenu)
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
		void displayMenu(List *head);
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

void Lista::pushMenu()
{
	short sLChoicePushMenu;

	cout << "Prosze wybrac:" << endl << "1.Dodanie na poczatek struktury." << endl << "2.Dodanie na koniec struktury." << endl << "3.Dodanie w okreslonie miejsce w strukturze." << endl << "4.Powrot" << endl;
	cin >> sLChoicePushMenu;

	switch (sLChoicePushMenu)
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

void Lista::popMenu()
{
	short sLChoicePopMenu;

	cout << "Prosze wybrac:" << endl << "1.Usuniecie elementu z poczatku struktury." << endl << "2.Usuniecie elementu z konca struktury." << endl << "3.Usuniecie elementu z okreslonego miejsca w struktury." << endl << "4.Powrot" << endl;
	cin >> sLChoicePopMenu;

	switch (sLChoicePopMenu)
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

void Lista::displayMenu(List *head)
{
	short sLChoiceDisplayMenu;

	cout << "Prosze wybrac:" << endl << "1.Wyswietlenie calej zawartosci struktury." << endl << "2.Wyswietlenie okreslonego elementu struktury." << endl << "3.Powrot." << endl;
	cin >> sLChoiceDisplayMenu;

	switch (sLChoiceDisplayMenu)
	{
	case 1:
	{
		void displayAll(List *head);
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

void Lista::pushFront()
{

}

void Lista::pushEnd()
{

}

void Lista::pushMiddle()
{

}

void Lista::popFront()
{

}

void Lista::popEnd()
{

}

void Lista::popMiddle()
{

}

void Lista::displayAll(List *head)
{
	while (head != NULL)
	{
		cout << head->iLData << " ";
		head = head->next;
	}
}

void Lista::displayOne()
{

}