#include "Lista.h"

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <time.h>
#include <chrono>
#include <ratio>

using namespace std;

Lista::Lista()
{
	nHead = NULL;
	nTail = NULL;
}

Lista::~Lista()
{

}

void Lista::listMenu()
{
	for (;;)
	{
		shL.cls();

		short sLChoiceListMenu;

		cout << "Prosze wybrac:" << endl << "1.Menu dodawania." << endl << "2.Menu odejmowania." << endl << "3.Menu wyswietlania." << endl << "4.Powrot" << endl;
		cin >> sLChoiceListMenu;

		switch (sLChoiceListMenu)
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
			shL.noOption();
			break;
		}
		}
	}
}

void Lista::pushMenu()
{
	for (;;)
	{
		shL.cls();

		short sLChoicePushMenu;

		cout << "Prosze wybrac:" << endl << "1.Dodanie na poczatek struktury." << endl << "2.Dodanie na koniec struktury." << endl << "3.Dodanie w okreslonie miejsce w strukturze." << endl << "4.Powrot" << endl;
		cin >> sLChoicePushMenu;

		switch (sLChoicePushMenu)
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
			shL.noOption();
			break;
		}
		}
	}
}

void Lista::popMenu()
{
	for (;;)
	{
		shL.cls();

		short sLChoicePopMenu;

		cout << "Prosze wybrac:" << endl << "1.Usuniecie elementu z poczatku struktury." << endl << "2.Usuniecie elementu z konca struktury." << endl << "3.Usuniecie elementu z okreslonego miejsca w struktury." << endl << "4.Powrot" << endl;
		cin >> sLChoicePopMenu;

		switch (sLChoicePopMenu)
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
			shL.noOption();
			break;
		}
		}
	}
}

void Lista::displayMenu()
{
	for (;;)
	{
		shL.cls();

		short sLChoiceDisplayMenu;

		cout << "Prosze wybrac:" << endl << "1.Wyswietlenie calej zawartosci struktury." << endl << "2.Wyswietlenie okreslonego elementu struktury." << endl << "3.Powrot." << endl;
		cin >> sLChoiceDisplayMenu;

		switch (sLChoiceDisplayMenu)
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
			shL.noOption();
			break;
		}
		}
	}
}

void Lista::pushFront()
{
	int iLNewFrontElement;

	cout << "Podaj liczbe jaka ma byc dodana do listy: " << endl;
	cin >> iLNewFrontElement;

	auto o1 = chrono::high_resolution_clock::now();
	
	Node *newNode = new Node(iLNewFrontElement);
	if (nHead != NULL)
	{
		Node *tempNode = nHead;
		while (tempNode->nNext != NULL)
		{
			tempNode = tempNode->nNext;
		}
		tempNode->nNext = newNode;
	}
	else
	{
		nHead = newNode;
		nTail = newNode;
	}

	auto o2 = chrono::high_resolution_clock::now();
	
	outcomeList.tMOutcome(o1, o2);

	shL.done();
}

void Lista::pushEnd()
{


	shL.done();
}

void Lista::pushMiddle()
{


	shL.done();
}

void Lista::popFront()
{
	if (nHead != NULL)
	{
		
	}
	else
	{
		shL.empty();
	}
	shL.done();
}

void Lista::popEnd()
{
	if (nHead != NULL)
	{

	}
	else
	{
		shL.empty();
	}
	shL.done();
}

void Lista::popMiddle()
{


	shL.done();
}

void Lista::displayAll()
{
	auto o1 = chrono::high_resolution_clock::now();

	if (nHead != NULL)
	{
		Node *tempNode = nHead;
		cout << "Zawartosc listy: \n";
		while (tempNode != NULL)
		{
			cout << tempNode->iNData << " ";
			tempNode = tempNode->nNext;
		}
	}
	else
	{
		shL.empty();
	}
	auto o2 = chrono::high_resolution_clock::now();

	outcomeList.tMOutcome(o1, o2);
	shL.done();
}

void Lista::displayOne()
{


	shL.done();
}