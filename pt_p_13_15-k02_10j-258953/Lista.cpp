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

		cout << "Prosze wybrac:" << endl << "1.Dodanie na poczatek struktury." << endl << "2.Dodanie na koniec struktury." << endl << "3.Dodanie w okreslonie miejsce w strukturze." << endl << "4.Odczytanie danych z pliku tekstowego." << endl << "5.Wygenerowanie okreslonej ilosci danej do struktury." << endl << "6.Powrot" << endl;
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
			readFromFileL();
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

		cout << "Prosze wybrac:" << endl << "1.Usuniecie elementu z poczatku struktury." << endl << "2.Usuniecie elementu z konca struktury." << endl << "3.Usuniecie elementu z okreslonego miejsca w struktury." << endl << "4.Usuniecie wszytkich elementow w strukturze." << endl << "5.Powrot" << endl;
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
			clearAll();
			break;
		}
		case 5:
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
		newNode->nNext = nHead;
		nHead = newNode;
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
	int iLNewEndElement;

	cout << "Podaj liczbe jaka ma byc dodana do listy: " << endl;
	cin >> iLNewEndElement;

	auto o1 = chrono::high_resolution_clock::now();
	
	Node *newNode = new Node(iLNewEndElement);
	if (nHead != NULL)
	{
		newNode->nPrev = nTail;
		nTail->nNext = newNode;
		nTail = newNode;
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

void Lista::pushMiddle()
{
	Node *tempNode = nHead;
	int iLPushPosition, iLPushElement;
	cout << "Wybierz, po ktorym elemencie ma zostac wstawiony twoj element: " << endl;
	cin >> iLPushPosition;
	cout << "Wybierz wartosc wstawianego elementu: " << endl;
	cin >> iLPushElement;
	cout << "Wybrany element zostanie wstawiony po elemencie: " << iLPushPosition << " i bedzie mial wartosc: " << iLPushElement << "." << endl;

	auto o1 = chrono::high_resolution_clock::now();

	if (nHead != NULL)
	{
		while (tempNode->nNext != NULL)
		{
			if (tempNode->iNData == iLPushPosition)
			{
				Node *newNode = new Node(iLPushElement);
				if (tempNode == nTail)
				{
					newNode->nPrev = nTail;
					nTail->nNext = newNode;
					nTail = newNode;
				}
				else
				{
					tempNode->nNext->nPrev = newNode;
					newNode->nNext = tempNode->nNext;
					newNode->nPrev = tempNode;
					tempNode->nNext = newNode;
				}
				goto pushed;
			}
			tempNode = tempNode->nNext;
		}
	}
	else
	{
		shL.empty();
	}
pushed:
	auto o2 = chrono::high_resolution_clock::now();

	outcomeList.tMOutcome(o1, o2);
	shL.done();
}

void Lista::readFromFileL()
{
	ifstream ifLFile("dane.txt", ios::in);
	if (ifLFile.good())
	{
		shL.opened();

		auto o1 = chrono::high_resolution_clock::now();

		string sLLineCountBuffer;
		getline(ifLFile, sLLineCountBuffer);
		int iLLineCount = stoi(sLLineCountBuffer);
		cout << "Ilosc elementow przekazanych do struktury: " << iLLineCount << endl;

		string sLFileHead;
		getline(ifLFile, sLFileHead);
		int iLFileHead = stoi(sLFileHead);
		Node *tempNode = new Node(iLFileHead);
		nHead = tempNode;

		for (int i = 1; i <= iLLineCount - 1; i++)
		{
			string sLLineValueBuffer;
			getline(ifLFile, sLLineValueBuffer);
			int iLLineValue = stoi(sLLineValueBuffer);

			Node *newNode = new Node(iLLineValue);
		}
		ifLFile.close();

		auto o2 = chrono::high_resolution_clock::now();

		outcomeList.tMOutcome(o1, o2);

		shL.done();
	}
	else
	{
		shL.noFile();
	}
}

void Lista::generateElements()
{

}

void Lista::popFront()
{
	auto o1 = chrono::high_resolution_clock::now();
	if (nHead != NULL)
	{
		if (nHead->nNext != NULL)
		{
			Node *tempNode = nHead->nNext;
			delete nHead;
			nHead = tempNode;
		}
		else
		{
			delete nHead;
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

void Lista::popEnd()
{
	auto o1 = chrono::high_resolution_clock::now();
	if (nHead != NULL)
	{
		if (nTail->nPrev != NULL)
		{
			Node *tempNode = nTail->nPrev;
			delete nTail;
			nTail = tempNode;
		}
		else
		{
			delete nTail;
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

void Lista::popMiddle()
{
	Node *tempNode = nHead;
	int iLPopChoice;
	cout << "Wybierz, ktory element ma zostac usuniety: " << endl;
	cin >> iLPopChoice;
	cout << "Wybrany element: " << iLPopChoice << endl;

	auto o1 = chrono::high_resolution_clock::now();

	if (nHead != NULL)
	{
		while (tempNode->nNext != NULL)
		{
			if (tempNode->iNData == iLPopChoice)
			{
				tempNode->nNext->nPrev = tempNode->nPrev;
				tempNode->nPrev->nNext = tempNode->nNext;
				delete tempNode;
				goto poped;
			}
			tempNode = tempNode->nNext;
		}
	}
	else
	{
		shL.empty();
	}
	poped:
	auto o2 = chrono::high_resolution_clock::now();

	outcomeList.tMOutcome(o1, o2);
	shL.done();
}

void Lista::clearAll()
{
	auto o1 = chrono::high_resolution_clock::now();

	Node *tempNode = nHead;

	if (nHead != NULL)
	{
		while (nHead != NULL)
		{
			tempNode = nHead->nNext;
			delete nHead;
			nHead = tempNode->nNext;
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

void Lista::displayAll()
{
	auto o1 = chrono::high_resolution_clock::now();

	if (nHead != NULL)
	{
		int i = 1;
		Node *tempNode = nHead;
		cout << "Zawartosc listy (od glowy): \n";
		while (tempNode != NULL)
		{
			cout << "Element nr " << i << " ma wartosc rowna: " << tempNode->iNData << endl;
			tempNode = tempNode->nNext;
			i++;
		}
		cout << "Head = " << nHead->iNData << endl << "Tail = " << nTail->iNData << endl;
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
	Node *tempNode = nHead;
	int iLDisplayChoice;
	int i = 0;
	cout << "Wybierz, ktory element ma zostac wyswietlony: " << endl;
	cin >> iLDisplayChoice;

	auto o1 = chrono::high_resolution_clock::now();
	
	if (nHead != NULL)
	{
		cout << "Wybrany element: " << iLDisplayChoice << endl;
		while (tempNode->nNext != NULL)
		{
			i++;
			if (tempNode->iNData == iLDisplayChoice)
			{
				cout << "Ilosc pozycji od glowy: " << i << endl;
			}
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