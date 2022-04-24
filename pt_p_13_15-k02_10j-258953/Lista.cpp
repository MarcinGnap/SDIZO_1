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

void Lista::listMenu()									//	Menu g³ówne listy dwukierunkowej.
{
	for (;;)
	{
		shL.cls();										//	"Wyczyszczenie" konsoli.

		short sLChoiceListMenu;

		cout << "Prosze wybrac:\n"
				"\t1.Menu dodawania.\n"
				"\t2.Menu usuwania.\n"
				"\t3.Menu wyswietlania.\n"
				"\t4.Menu testow.\n"
				"\t5.Powrot.\n";
		cin >> sLChoiceListMenu;

		switch (sLChoiceListMenu)
		{
		case 1:
		{
			pushMenu();									//	Menu dodawania elementów do listy.
			break;
		}
		case 2:
		{
			popMenu();									//	Menu usuwania elementów z listy.
			break;
		}
		case 3:
		{
			displayMenu();								//	Menu Wyœwietlania zawartoœci listy.
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
			shL.noOption();								//	Wyœwietlenie komunikatu o wybraniu nieistniej¹cej opcji.
			break;
		}
		}
	}
}

void Lista::pushMenu()											//	Menu dodawania elementów do listy.
{
	for (;;)
	{
		shL.cls();												//	"Wyczyszczenie" konsoli.

		short sLChoicePushMenu;

		cout << "Prosze wybrac:\n"
				"\t1.Dodanie na poczatek struktury.\n"
				"\t2.Dodanie na koniec struktury.\n"
				"\t3.Dodanie w okreslonie miejsce w strukturze (po wartosci).\n"
				"\t4.Dodanie w okreslonie miejsce w strukturze (do indeksu).\n"
				"\t5.Odczytanie danych z pliku tekstowego.\n"
				"\t6.Wygenerowanie okreslonej ilosci danej do struktury.\n"
				"\t7.Powrot.\n";
		cin >> sLChoicePushMenu;

		switch (sLChoicePushMenu)
		{
		case 1:
		{
			int iLNewFrontElement;

			cout << "Podaj liczbe jaka ma byc dodana do listy:\n";
			cin >> iLNewFrontElement;							//	Wybranie wartoœci dodawanego elementu.

			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpoczêcia operacji.

			pushFront(iLNewFrontElement);						//	Dodanie elementu na pocz¹tek listy.

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakoñczenia programu.
			outcomeList.tMOutcome(o1, o2);						//	Wyœwietlenie czasu wykonania operacji.
			displayAll();
			shL.done();											//	Wyœwietlenie komunikatu o zakoñczeniu zadania oraz czekanie na naciœniêcie klawisza przez u¿ytkownika.
			break;
		}
		case 2:
		{
			int iLNewEndElement;

			cout << "Podaj liczbe jaka ma byc dodana do listy:\n";
			cin >> iLNewEndElement;								//	Wybór wartoœci dodawanego elementu.
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpoczêcia operacji.

			pushEnd(iLNewEndElement);							//	Dodanie elementu na koniec listy.

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakoñczenia programu.
			outcomeList.tMOutcome(o1, o2);						//	Wyœwietlenie czasu wykonania operacji.
			displayAll();
			shL.done();											//	Wyœwietlenie komunikatu o zakoñczeniu zadania oraz czekanie na naciœniêcie klawisza przez u¿ytkownika.
			break;
		}
		case 3:
		{
			int iLPushValue, iLPushElement;
			cout << "Wybierz, po ktorym elemencie ma zostac wstawiony twoj element:\n";
			cin >> iLPushValue;									//	Wybranie po jakim elemencie ma zostaæ wstawiony nowy element.
			cout << "Wybierz wartosc wstawianego elementu:\n";
			cin >> iLPushElement;								//	Wybranie wartoœci wstawianego elementu.
			cout << "Wybrany element zostanie wstawiony po elemencie: " << iLPushValue << " i bedzie mial wartosc: " << iLPushElement << ".\n";
			
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpoczêcia operacji.

			if (pushMiddleValue(iLPushValue, iLPushElement) == true)	//	Dodanie elementu w okreœlone miejsce listy.
			{
				cout << "Udalo sie dodac element...\n";
			}
			else
			{
				shL.noIn();
			}

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakoñczenia programu.
			outcomeList.tMOutcome(o1, o2);						//	Wyœwietlenie czasu wykonania operacji.
			displayAll();
			shL.done();											//	Wyœwietlenie komunikatu o zakoñczeniu zadania oraz czekanie na naciœniêcie klawisza przez u¿ytkownika.
			break;
		}
		case 4:
		{
			int iLPushPosition, iLPushElement;
			cout << "Wybierz pozycje, na ktorej ma zostac wstawiony element:\n";
			cin >> iLPushPosition;								//	Wybranie po jakim elemencie ma zostaæ wstawiony nowy element.
			cout << "Wybierz wartosc wstawianego elementu:\n";
			cin >> iLPushElement;								//	Wybranie wartoœci wstawianego elementu.
			int iLRightPush = iLPushPosition - 1;
			
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpoczêcia operacji.

			if (pushMiddleIndex(iLRightPush, iLPushElement) == true)	//	Dodanie elementu w okreœlone miejsce listy.
			{
				cout << "Wybrany element zostal na pozycje: " << iLPushPosition << " i ma ma wartosc: " << iLPushElement << ".\n";
			}
			else
			{
				shL.away();
			}

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakoñczenia programu.
			outcomeList.tMOutcome(o1, o2);						//	Wyœwietlenie czasu wykonania operacji.
			displayAll();
			shL.done();											//	Wyœwietlenie komunikatu o zakoñczeniu zadania oraz czekanie na naciœniêcie klawisza przez u¿ytkownika.
			break;
		}
		case 5:
		{
			readFromFileL();									//	Wczytanie elementów z pliku tekstowego.

			displayAll();
			shL.done();											//	Wyœwietlenie komunikatu o zakoñczeniu wykonywania operacji.

			break;
		}
		case 6:
		{
			int iLNumberOfGen;
			cout << "Ile elementow ma zostac wygenerowanych?\n";
			cin >> iLNumberOfGen;								//	Wybór iloœci wylosowanych elementów.
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpoczêcia operacji.
			srand(time(0));

			generateElements(iLNumberOfGen);					//	Wygenerowanie okreœlonej liczby elementów.

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakoñczenia wykonywania operacji.
			outcomeList.tMOutcome(o1, o2);						//	Wyœwietlenie czasu wykonywania operacji.

			displayAll();
			shL.done();											//	Wyœwietlenie komuniaktu o zakoñczeniu wykonywania operacji.

			break;
		}
		case 7:
		{
			return;
			break;
		}
		default:
		{
			shL.noOption();										//	Wyœwietlenie komunikatu o wybraniu nieistniej¹cej opcji.
			break;
		}
		}
	}
}

void Lista::popMenu()									//	Menu usuwania elementów z listy.
{
	for (;;)
	{
		shL.cls();										//	"Wyczyzczenie" konsoli.

		short sLChoicePopMenu;

		cout << "Prosze wybrac:\n"
				"\t1.Usuniecie elementu z poczatku struktury.\n"
				"\t2.Usuniecie elementu z konca struktury.\n"
				"\t3.Usuniecie elementu o okreslonej wartosci ze struktury.\n"
				"\t4.Usuniecie elementu z okreslonego miejsca ze struktury.\n"
				"\t5.Usuniecie wszytkich elementow w strukturze.\n"
				"\t6.Powrot.\n";
		cin >> sLChoicePopMenu;

		switch (sLChoicePopMenu)
		{
		case 1:
		{
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpoczêcia operacji.

			popFront();											//	Usuniêcie g³owy listy.

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakoñczenia programu.
			outcomeList.tMOutcome(o1, o2);						//	Wyœwietlenie czasu wykonania operacji.
			displayAll();
			shL.done();											//	Wyœwietlenie komunikatu o zakoñczeniu zadania oraz czekanie na naciœniêcie klawisza przez u¿ytkownika.
			break;
		}
		case 2:
		{
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpoczêcia operacji.

			popEnd();											//	Usuniêcie ogona listy.

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakoñczenia programu.
			outcomeList.tMOutcome(o1, o2);						//	Wyœwietlenie czasu wykonania operacji.
			displayAll();
			shL.done();											//	Wyœwietlenie komunikatu o zakoñczeniu zadania oraz czekanie na naciœniêcie klawisza przez u¿ytkownika.
			break;
		}
		case 3:
		{
			int iLPopValue;
			cout << "Wybierz, ktory element ma zostac usuniety:\n";
			cin >> iLPopValue;									//	Wybranie usuwanej wartoœci.
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpoczêcia operacji.

			if (popMiddleValue(iLPopValue) == true)				//	Usuniêcie wskazanego elementu listy.
			{
				cout << "Wybrany element zostal usuniety ze struktury.\n";
			}
			else
			{
				shL.noIn();
			}

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakoñczenia programu.
			outcomeList.tMOutcome(o1, o2);						//	Wyœwietlenie czasu wykonania operacji.
			displayAll();
			shL.done();											//	Wyœwietlenie komunikatu o zakoñczeniu zadania oraz czekanie na naciœniêcie klawisza przez u¿ytkownika.
			break;
		}
		case 4:
		{
			int iLPopIndex;
			cout << "Wybierz, ktory element ma zostac usuniety:\n";
			cin >> iLPopIndex;									//	Wybranie usuwanej wartoœci.
			int iTRightPop = iLPopIndex - 1;					//	Zmienna zawieraj¹ca poprawn¹ pozycjê usuwanego elementu.
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpoczêcia operacji.

			if (popMiddleIndex(iTRightPop) == true)				//	Usuniêcie wskazanego elementu listy.
			{
				cout << "Wybrany element zostal usuniety ze struktury.\n";
			}
			else
			{
				shL.noIn();
			}

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakoñczenia programu.
			outcomeList.tMOutcome(o1, o2);						//	Wyœwietlenie czasu wykonania operacji.
			displayAll();
			shL.done();											//	Wyœwietlenie komunikatu o zakoñczeniu zadania oraz czekanie na naciœniêcie klawisza przez u¿ytkownika.
			break;
		}
		case 5:
		{
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpoczêcia operacji.

			clearAll();											//	Wyœwietlenie ca³ej zawartoœci listy.

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakoñczenia operacji.
			outcomeList.tMOutcome(o1, o2);						//	Wyœwietlenie czasu wykonania operacji.
			displayAll();
			shL.done();											//	Wyœwietlenie komunikatu o zakoñczeniu zadania oraz czekanie na naciœniêcie klawisza przez u¿ytkownika.
			break;
		}
		case 6:
		{
			return;
			break;
		}
		default:
		{
			shL.noOption();								//	Wyœwietlenie kounikatu o wybraniu nieistniej¹cej opcji.
			break;
		}
		}
	}
}

void Lista::displayMenu()										//	Menu wyœwiatlania.
{
	for (;;)
	{
		shL.cls();												//	"Wyczyszczenie" ekranu.

		short sLChoiceDisplayMenu;

		cout << "Prosze wybrac:\n"
				"\t1.Wyswietlenie calej zawartosci struktury.\n"
				"\t2.Wyswietlenie okreslonego elementu struktury (szukajac wartosci).\n"
				"\t3.Wyswietlenie okreslonego elementu struktury (szukajac indeksu).\n"
				"\t4.Powrot.\n";
		cin >> sLChoiceDisplayMenu;

		switch (sLChoiceDisplayMenu)
		{
		case 1:
		{
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpoczêcia operacji.

			displayAll();										//	Wyœwietlenie ca³ej zawartoœci listy.

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakoñczenia operacji.
			outcomeList.tMOutcome(o1, o2);						//	Wyœwietlenie czasu wykonania operacji.
			shL.done();
			break;
		}
		case 2:
		{
			int iLDisplayChoice;
			cout << "Wybierz, ktory element ma zostac wyswietlony:\n";
			cin >> iLDisplayChoice;								//	Wybór wartoœci, która ma zostaæ wyœwietlona.
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpoczêcia operacji.

			if (displayOneValue(iLDisplayChoice) == true)		//	Wyœwietlenie okreœlonego elementu listy.
			{
				cout << "Wybrany element znajduje sie w strukturze." << endl;
			}
			else
			{
				shL.noIn();
			}

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakoñczenia operacji.
			outcomeList.tMOutcome(o1, o2);						//	Wyœwietlenie czasu wykonania operacji.
			shL.done();											//	Wyœwietlenie komunikatu o zakoñczeniu wykonywania operacji.

			break;
		}
		case 3:
		{
			int iLDisplayIndex;
			cout << "Wybierz, ktory element ma zostac wyswietlony:\n";
			cin >> iLDisplayIndex;								//	Wybór elementu, który ma zostaæ wyœwietlony.
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpoczêcia operacji.

			int iLIndex = displayOneIndex(iLDisplayIndex);
			if (iLIndex == NULL)								//	Wyœwietlenie okreœlonego elementu listy.
			{
				shL.noIn();
			}
			else
			{
				cout << "Wybrany element: " << iLDisplayIndex << " ma wartosc rowna " << iLIndex << endl;
			}

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakoñczenia operacji.
			outcomeList.tMOutcome(o1, o2);						//	Wyœwietlenie czasu wykonania operacji.
			shL.done();											//	Wyœwietlenie komunikatu o zakoñczeniu wykonywania operacji.

			break;
		}
		case 4:
		{
			return;
			break;
		}
		default:
		{
			shL.noOption();										//	Wyœwietlenie komunikatu o wybraniu nieistniej¹cej opcji.
			break;
		}
		}
	}
}

void Lista::testMenu()
{
	for (;;)
	{
		shL.cls();								

		short sLChoiceTestMenu;

		cout << "Prosze wybrac:\n"
			"\t1.Testy dodawania.\n"
			"\t2.Testy usuwania.\n"
			"\t3.Testy wyswietlania.\n"
			"\t4.Powrot.\n";
		cin >> sLChoiceTestMenu;

		switch (sLChoiceTestMenu)
		{
		case 1:
		{
			testPush();
			break;
		}
		case 2:
		{
			testPop();
			break;
		}
		case 3:
		{
			testSearch();
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

void Lista::pushFront(int iLNewFrontElement)			//	Dodanie elementu na pocz¹tek listy.
{
	Node *newNode = new Node(iLNewFrontElement);		//	Stworzenie nowej "komórki" listy dla dodawanego elementu.

	if (nHead != NULL)									//	Sprawdzenie czy listy jest pusta.
	{
		newNode->nNext = nHead;							//	WskaŸnik nowej komórki na nastêpny element zostaje przypisany poprzedniej g³owie.
		nHead->nPrev = newNode;							//	WskaŸnik poprzedniej g³owy na poprzedni element zostaje przypisany nowemu elementowi.
		nHead = newNode;								//	Zmiana g³owy na nowy element.
	}
	else
	{
		nHead = newNode;								//	Przypisanie nowego elementu jako g³owy.
		nTail = newNode;								//	Przypisanie nowego elementu jako ogona.
	}
}

void Lista::pushEnd(int iLNewEndElement)				//	Dodanie elementu na koniec listy.
{
	Node *newNode = new Node(iLNewEndElement);			//	Stworzenie nowej komórki z wybran¹ wartoœci¹.
	if (nHead != NULL)									//	Sprawdzenie czy lista jest pusta.
	{
		newNode->nPrev = nTail;							//	WskaŸnik nowej koórki na element poprzedni zostaje przypisany do ogona.
		nTail->nNext = newNode;							//	WskaŸnik ogona na nastêpny element zostaje przypisany do nowej komórki.
		nTail = newNode;								//	Przypisanie nowego elementu jako ogona.
	}
	else
	{
		nHead = newNode;								//	Przypisanie nowego elementu jako g³owy.
		nTail = newNode;								//	Przypisanie nowego elementu jako ogona.
	}
}

bool Lista::pushMiddleValue(int iLPushValue, int iLPushElement)		//	Dodanie elementu w okreœlone miejsce w liœcie.
{
	Node *tempNode = nHead;								//	Stworzenie tyczasowego wskaŸnika przechowuj¹cego adres g³owy.
	if (nHead != NULL)									//	Sprawdzenie czy lista jest pusta.
	{
		while (tempNode->nNext != NULL)					//	Pêtla wykonuj¹ca siê od pocz¹tkowego elementu listy do ostatniego.
		{
			if (tempNode->iNData == iLPushValue)		//	Sprawdzenie czy wartoœæ elementu zgadza siê z elementem, po którym u¿ytkownik chce wstawiæ nowy element.
			{
				if (tempNode == nTail)					//	Sprawdzenie czy znaleŸiony element jest ogonem.
				{
					pushEnd(iLPushElement);
				}
				else
				{
					Node *newNode = new Node(iLPushElement);//	Stworzenie nowego elementu.
					tempNode->nNext->nPrev = newNode;	//	WskaŸnik nastêpnego elementu po znaleŸionej komórce na poprzedni element zostaje przypisany do nowej komórki.
					newNode->nNext = tempNode->nNext;	//	WskaŸnik nowej komórki na nastêpny element zostaje przypisany do nastêpnej komórki po znaleŸionej.
					newNode->nPrev = tempNode;			//	WskaŸnik nowej komórki na porzedni element zostaje przypisany do znaleŸionej komórki.
					tempNode->nNext = newNode;			//	WskaŸnik znaleŸionej komórki na nastêpny element zostaje przypisany do nowej komórki.
				}
				return true;;							//	Etykieta, dziêki Której program wychodzi z pêtli po znaleŸieniu odpowiedniej wartoœæi.
			}
			tempNode = tempNode->nNext;					//	Przypisanie tymczasowego elementu do nastêpnego.
		}
	}
	else
	{
		shL.empty();									//	Wyœwietlenie komunikatu o braku zawartoœci struktury.
	}
	return false;
}

bool Lista::pushMiddleIndex(int iLRightPush, int iLPushElementI)
{
	int i = 0;
	Node *tempNode = nHead;								//	Stworzenie nowego wskaŸnika i przypisanie do niego g³owy.
	if (nHead != NULL)									//	Sprawdzenie czy lista ma zawartoœæ.
	{
		while (tempNode != NULL)						//	Pêtla wykonuj¹ca siê od pocz¹tkowego do ostatniego elementu listy.
		{
			if (i == iLRightPush)						//	Sprawdzenie czy index aktualnie "przegl¹danej" komórki jest taki sama jak wybrany.
			{
				if (tempNode == nHead)
				{
					pushFront(iLPushElementI);
				}
				else if (tempNode == nTail)
				{
					pushEnd(iLPushElementI);
				}
				else
				{
					Node *newNode = new Node(iLPushElementI);
					tempNode->nNext->nPrev = newNode;	//	WskaŸnik nastêpnego elementu po znaleŸionej komórce na poprzedni element zostaje przypisany do nowej komórki.
					newNode->nNext = tempNode->nNext;	//	WskaŸnik nowej komórki na nastêpny element zostaje przypisany do nastêpnej komórki po znaleŸionej.
					newNode->nPrev = tempNode;			//	WskaŸnik nowej komórki na porzedni element zostaje przypisany do znaleŸionej komórki.
					tempNode->nNext = newNode;			//	WskaŸnik znaleŸionej komórki na nastêpny element zostaje przypisany do nowej komórki.

				}
				return true;
			}
			i++;
			tempNode = tempNode->nNext;					//	Przypisanie wskaŸnikowi tyczasowej komórki adresu elementu nastêpnego.
		}
	}
	else
	{
		shL.empty();									//	Wyœwietlenie komunikatu o braku zawartoœci listy.
	}
	return false;
}

void Lista::readFromFileL()								//	Odczytanie i zapisanie elementów z pliku tekstowego.
{
	ifstream ifLFile("dane.txt", ios::in);				//	Otworzenie pliku tekstowego o nazwie "dane.txt" w trybie odczytu.
	if (ifLFile.good())									//	Sprawdzenie czy plik zosta³ pomyœlnie otwarty.
	{
		shL.opened();									//	Wyœwietlenie komunikatu o pomyœlnym otwarciu pliku tekstowego.

		auto o1 = chrono::high_resolution_clock::now();	//	Pomiar czasu w momencie rozpoczêcia operacji.

		string sLLineCountBuffer;
		getline(ifLFile, sLLineCountBuffer);			//	Odczytanie pierwszej linii do wczeœniej utworzonej zmiennej. Docelowo linia ta ma przechowywaæ iloœæ elementów odczytywanych z pliku.
		int iLLineCount = stoi(sLLineCountBuffer);		//	Zmienienie typu odczytanej zmiennej na typ ca³kowyti 4-bajtowy.
		cout << "Ilosc elementow przekazanych do struktury: " << iLLineCount << endl;

		string sLFileHead;
		getline(ifLFile, sLFileHead);					//	Odczytanie pierwszego elementu z pliku tekstowego.
		int iLFileHead = stoi(sLFileHead);				//	Zmienienie typu odczytanej zmiennej na typ ca³kowyti 4-bajtowy.
		Node *tempNode = new Node(iLFileHead);			//	Stworzenie nowego elementu.
		nHead = tempNode;								//	Przypisanie nowego elemtnu jako g³owy.

		for (int i = 1; i <= iLLineCount - 2; i++)		//	Pêtla wykonuj¹ca siê od drugiego elementu odczytanego do przedostatniego.
		{
			string sLLineValueBuffer;
			getline(ifLFile, sLLineValueBuffer);		//	Odczytanie elementu.
			int iLLineValue = stoi(sLLineValueBuffer);	//	Zmienienie typu odczytanej zmiennej na typ ca³kowyti 4-bajtowy.

			Node *newNode = new Node(iLLineValue);		//	Stworzenie nowego elemntu z odczytan¹ wartoœci¹.
			tempNode->nNext = newNode;					//	WskaŸnik porpzedniego elementu na nastêpny element zostaje przypisany do nowego elementu.
			newNode->nPrev = tempNode;					//	WskaŸnik nowego elementu na poprzedni element zostaje przypisany do porzedniego elementu.
			tempNode = newNode;							//	Nowy element zostaje uznany za tymczasowy element.
		}
		string sLFileTail;
		getline(ifLFile, sLFileTail);					//	Odczytanie ostatniego elementu.
		int iLFileTail = stoi(sLFileTail);				//	Zmienienie typu odczytanej zmiennej na typ ca³kowyti 4-bajtowy.
		Node *newNode = new Node(iLFileTail);			//	Stworzenie nowego elementu z odczytanymi danymi.
		tempNode->nNext = newNode;						//	WskaŸnik porpzedniego elementu na nastêpny element zostaje przypisany do nowego elementu.
		newNode->nPrev = tempNode;						//	WskaŸnik nowego elementu na poprzedni element zostaje przypisany do porzedniego elementu.
		nTail = newNode;								//	Przypisanie nowego elementu jako ogona.

		ifLFile.close();								//	Zamkniêcie pliku.

		auto o2 = chrono::high_resolution_clock::now();	//	Pomiaer czasu w momencie zakoñczenia operacji.

		outcomeList.tMOutcome(o1, o2);					//	Wyœwietlenie czasu wykonywania operacji.
	}
	else
	{
		shL.noFile();									//	Wyœwietlenie komunikatu o problemie z plikiem.
	}
}

void Lista::generateElements(int iLNumberOfGen)			//	Wygenerowanie okreœlonej liczby elemetów do listy.
{
	if (iLNumberOfGen == 0)
	{
		shL.noOption();
	}
	else if (iLNumberOfGen == 1)
	{
		int iLGenerated = rand();							//	Pseudo wylosowanie nowej wartoœci.
		Node *newNode = new Node(iLGenerated);				//	Stworzenie nowego elementu z now¹ wartoœci¹.
		nHead = newNode;									//	Przypisanie nowego elementu jako g³owy.
		nTail = newNode;									//	Przypisanie nowego elementu jako ogona.
	}
	else if (iLNumberOfGen == 2)
	{
		int iLGeneratedHead = rand();						//	Pseudo wylosowanie elementu.
		Node *tempNode = new Node(iLGeneratedHead);			//	Stworzenie nowego elementu z nowymi danymi.
		nHead = tempNode;									//	Przypisanie nowego elementu jako g³owy.

		int iLGeneratedTail = rand();						//	Pseudo wylosowanie nowej wartoœci.
		Node *newNode = new Node(iLGeneratedTail);			//	Stworzenie nowej komórki z now¹ wartoœci¹.
		tempNode->nNext = newNode;							//	WskaŸnik tymczasowej komórki na nastêpny element zostaje przypisany do nowego elementu.
		newNode->nPrev = tempNode;							//	WskaŸnik nowego elementu na poprzedni element zostaje przypisany do tymczasowego elementu.
		nTail = newNode;									//	Nowy element zostaje przypisany jako ogon.
	}
	else
	{
		int iLGeneratedHead = rand();						//	Pseudo wylosowanie elementu.
		Node *tempNode = new Node(iLGeneratedHead);			//	Stworzenie nowego elementu z nowymi danymi.
		nHead = tempNode;									//	Przypisanie nowego elementu jako g³owy.

		for (int i = 0; i < iLNumberOfGen - 2; i++)			//	Pêtla wykonuj¹ca siê od drugiego do przedostatniego elementu.
		{
			int iLGenerated = rand();						//	Pseudo wylosowanie nowej wartoœci.
			Node *newNode = new Node(iLGenerated);			//	Stworzenie nowego elementu z now¹ wartoœci¹.
			tempNode->nNext = newNode;						//	WskaŸnik tymczasowego elementu na nastêpny element zostaje przypisany do nowego elementu.
			newNode->nPrev = tempNode;						//	WskaŸnik nowego elementu na poprzedni element zostaje przypisany do tymczasowego elementu.
			tempNode = newNode;								//	Nowy element zostaje przypisany jako tymczasowy element.
		}
		int iLGeneratedTail = rand();						//	Pseudo wylosowanie nowej wartoœci.
		Node *newNode = new Node(iLGeneratedTail);			//	Stworzenie nowej komórki z now¹ wartoœci¹.
		tempNode->nNext = newNode;							//	WskaŸnik tymczasowej komórki na nastêpny element zostaje przypisany do nowego elementu.
		newNode->nPrev = tempNode;							//	WskaŸnik nowego elementu na poprzedni element zostaje przypisany do tymczasowego elementu.
		nTail = newNode;									//	Nowy element zostaje przypisany jako ogon.
	}
}

void Lista::popFront()									//	Usuniêcie elementu z pocz¹tki listy.
{
	if (nHead != NULL)									//	Sprawdzenie czy lista jest pusta.
	{
		if (nHead->nNext != NULL)						//	Sprawdzenie czy lista jest jedno elementowa.
		{
			nHead = nHead->nNext;						//	Zmiana g³owy na element poprzedni.
			delete nHead->nPrev;						//	Usuniêcie starej g³owy.
			nHead->nPrev = nullptr;						//	Wyzerowanie wskaŸnika na poprzedni element przed now¹ g³ow¹.
		}
		else
		{
			delete nHead;								//	Usuniêcie g³owy.
			nTail = nullptr;
			nHead = nullptr;
		}
	}
	else
	{
		shL.empty();									//	Wyœwietlenie kounikatu o braku zawartoœci listy.
	}
}

void Lista::popEnd()									//	Usuniêcie elementu z koñca listy.
{
	if (nHead != NULL)									//	Sprawdzenie czy lista ma zawartoœæ.
	{
		if (nTail->nPrev != NULL)						//	Sprawdzenie czy lista nie jest jednoelementowa.
		{
			nTail = nTail->nPrev;						//	Zmiana ogona na element poprzedni.

			delete nTail->nNext;						//	Usuniêcie starego ogona.
			nTail->nNext = nullptr;						//	Wyzerowanie wskaŸnika na nastêpny element po nowym ogonie.
		}
		else
		{
			delete nTail;								//	Uusniêcie ogona.
			nTail = nullptr;
			nHead = nullptr;
		}
	}
	else
	{
		shL.empty();									//	Wyœwietlenie kounikatu o braku zawartoœci listy.
	}
}

bool Lista::popMiddleValue(int iLPopValue)				//	Usuniêcie wskazanego elementu.
{
	Node *tempNode = nHead;								//	Stworzenie nowego wskaŸnika i przypisanie do niego g³owy.
	if (nHead != NULL)									//	Sprawdzenie czy lista nie jest pusta.
	{
		while (tempNode->nNext != NULL)					//	Pêtla wykonuj¹ca siê od pierwszego do ostatniego elementu listy.
		{
			if (tempNode->iNData == iLPopValue)			//	Sprawdzenie czy wartoœæ przechowywana przez komórkê jest identyczna jak wartoœæ wybrana.
			{
				tempNode->nNext->nPrev = tempNode->nPrev;	//	WskaŸnik komórki nastêpnej po elemencie tymczasowym na element nastêpny zostaje przypisany do wskaŸnika komórki tymczasowej na komórkê poprzedni¹ od nastêpnej.
				tempNode->nPrev->nNext = tempNode->nNext;	//	WskaŸnik komórki poprzedniej od elementu usuwanego na komórkê nastêpn¹ zostaje przypisany do wskaŸnika usuwanej komórki na element nastêpny.
				delete tempNode;						//	Usuniêcie elementu.
				return true;
			}
			tempNode = tempNode->nNext;					//	Zmienienie wskaŸnika komórki tymczasowej na element nastêpny.
		}
	}
	else
	{
		shL.empty();									//	Wyœwietlenie komunikatu o braku zawartoœci listy.
	}
	return false;
}

bool Lista::popMiddleIndex(int iLPopIndex)
{
	int i = 0;
	Node *tempNode = nHead;								//	Stworzenie nowego wskaŸnika i przypisanie do niego g³owy.
	if (nHead != NULL)									//	Sprawdzenie czy lista nie jest pusta.
	{
		while (tempNode != NULL)						//	Pêtla wykonuj¹ca siê od pocz¹tkowego do ostatniego elementu listy.
		{
			if (i == iLPopIndex)						//	Sprawdzenie czy index aktualnie "przegl¹danej" komórki jest taki sama jak wybrany.
			{
				if (tempNode == nHead)
				{
					popFront();
				}
				else if (tempNode == nTail)
				{
					popEnd();
				}
				else
				{
					tempNode->nNext->nPrev = tempNode->nPrev;	//	WskaŸnik komórki nastêpnej po elemencie tymczasowym na element nastêpny zostaje przypisany do wskaŸnika komórki tymczasowej na komórkê poprzedni¹ od nastêpnej.
					tempNode->nPrev->nNext = tempNode->nNext;	//	WskaŸnik komórki poprzedniej od elementu usuwanego na komórkê nastêpn¹ zostaje przypisany do wskaŸnika usuwanej komórki na element nastêpny.
					delete tempNode;							//	Usuniêcie elementu.
				}
				return true;
			}
			i++;
			tempNode = tempNode->nNext;							//	Przypisanie wskaŸnikowi tyczasowej komórki adresu elementu nastêpnego.
		}
	}
	else
	{
		shL.empty();											//	Wyœwietlenie komunikatu o braku wybranej pozycji w liœcie.
	}
	return false;
}

void Lista::clearAll()									//	Usuniêcie wszystkich elementów listy.
{
	Node *tempNode = nHead;								//	Stworzenie tymczasowego wskaŸnika i przypisanie do niego g³owy.

	if (nHead != NULL)									//	Sprawdzenie czy lista nie jest pusta.
	{
		while (nHead != NULL)							//	Pêtla wykonuj¹ca siê dopóki g³owa ma wartoœæ.
		{
			tempNode = nHead->nNext;					//	Przypisanie do wskaŸnika tymczasowego elementu nastêpnego po g³owie.
			delete nHead;								//	Usuniêcie g³owy.
			nHead = tempNode;							//	Przypisanie do g³owy nastêpnej komórki.
		}
	}
	else
	{
		shL.empty();									//	Wyœwietlenie komunikatu o braku zawartoœci listy.
	}
}

void Lista::displayAll()								//	Wyœwietlenie ca³ej zawartoœci listy.
{
	if (nHead != NULL)									//	Sprawdzenie czy lista nie jest pusta.
	{
		int i = 1;
		Node *tempNode = nHead;							//	Stworzenie tyczasowego wskaŸnika i przypisanie do niego g³owy.
		cout << "Zawartosc listy (od glowy):\n";
		while (tempNode != NULL)						//	Pêtla wykonuj¹ca siê dopóki wartoœæ tyczasowego wskaŸnika nie jest pusta.
		{
			cout << "Element nr " << i << " ma wartosc rowna: " << tempNode->iNData << endl;	//	Wyœwietlenie zawartoœci komórki.
			tempNode = tempNode->nNext;					//	Przypisanie do wskaŸnika tyczasowej komórki element nastêpny po danej komórce.
			i++;										//	Iteracja ziennej odpowiadaj¹cej za wyœwietlanie "numeru" elementu.
		}
		cout << "Head = " << nHead->iNData << endl << "Tail = " << nTail->iNData << endl;	//	Wyœwietlenie wartoœci g³owy i ogona.
	}
	else
	{
		shL.empty();									//	Wyœwietlenie komunikatu o braku zawartoœci listy.
	}
}

bool Lista::displayOneValue(int iLDisplayChoice)		//	Wyœwitlenie wybranego elementu listy.
{
	Node *tempNode = nHead;								//	Stworzenie nowego wskaŸnika i przypisanie do niego g³owy.
	if (nHead != NULL)									//	Sprawdzenie czy lista ma zawartoœæ.
	{
		while (tempNode != NULL)						//	Pêtla wykonuj¹ca siê od pocz¹tkowego do ostatniego elementu listy.
		{
			if (tempNode->iNData == iLDisplayChoice)	//	Sprawdzenie czy wartoœæ aktualnie "przegl¹danej" komórki jest taka sama jak wybrana wartoœæ.
			{
				cout << "Ilosc pozycji od glowy: " << endl;	//	Wyœwietlenie, na której pozycji od g³owy "le¿y" wybrana wartoœæ.
				return true;
			}
			tempNode = tempNode->nNext;					//	Przypisanie wskaŸnikowi tyczasowej komórki adresu elementu nastêpnego.
		}
		return false;
	}
	else
	{
		shL.empty();									//	Wyœwietlenie komunikatu o braku zawartoœci listy.
	}
	return false;
}

int Lista::displayOneIndex(int iLDisplayIndex)
{
	int i = 0;
	Node *tempNode = nHead;								//	Stworzenie nowego wskaŸnika i przypisanie do niego g³owy.
	if (nHead != NULL)									//	Sprawdzenie czy lista ma zawartoœæ.
	{
		while (tempNode != NULL)						//	Pêtla wykonuj¹ca siê od pocz¹tkowego do ostatniego elementu listy.
		{
			if (i == iLDisplayIndex)					//	Sprawdzenie czy index aktualnie "przegl¹danej" komórki jest taki sama jak wybrany.
			{
				return tempNode->iNData;
			}
			i++;
			tempNode = tempNode->nNext;					//	Przypisanie wskaŸnikowi tyczasowej komórki adresu elementu nastêpnego.
		}
		return NULL;
	}
	else
	{
		shL.empty();									//	Wyœwietlenie komunikatu o braku zawartoœci listy.
	}
	return NULL;
}

void Lista::testPush()
{
	int iLTPuChoice;
	cout << "Dla ilu elementow maja zostac przeprowadzone testy?";
	cin >> iLTPuChoice;

	srand(time(0));

	cout << "------------------------------------------\n"
		"Dodawanie na poczatek:\n";
	for (int i = 0; i < 100; i++)
	{
		generateElements(iLTPuChoice);

		int iLTNewFrontElement = rand();
		auto o1 = chrono::high_resolution_clock::now();

		pushFront(iLTNewFrontElement);

		auto o2 = chrono::high_resolution_clock::now();
		outcomeList.tMShort(o1, o2);

		clearAll();
	}
	cout << "------------------------------------------\n"
		"Dodawanie na koniec:\n";
	for (int i = 0; i < 100; i++)
	{
		generateElements(iLTPuChoice);

		int iLTNewEndElement = rand();
		auto o1 = chrono::high_resolution_clock::now();

		pushEnd(iLTNewEndElement);

		auto o2 = chrono::high_resolution_clock::now();
		outcomeList.tMShort(o1, o2);

		clearAll();
	}
	cout << "------------------------------------------\n"
		"Dodawanie w srodek:\n";
	for (int i = 0; i < 100; i++)
	{
		generateElements(iLTPuChoice);

		int iLTNewMiddleIndex = rand();
		int iLTNewMiddleElement = rand();
		auto o1 = chrono::high_resolution_clock::now();

		pushMiddleIndex(iLTNewMiddleIndex, iLTNewMiddleElement);

		auto o2 = chrono::high_resolution_clock::now();
		outcomeList.tMShort(o1, o2);

		clearAll();
	}

	shL.done();
}

void Lista::testPop()
{
	int iLTPoChoice;
	cout << "Dla ilu elementow maja zostac przeprowadzone testy?";
	cin >> iLTPoChoice;

	srand(time(0));

	cout << "------------------------------------------\n"
		"Usuwanie z poczatku:\n";
	for (int i = 0; i < 100; i++)
	{
		generateElements(iLTPoChoice);

		auto o1 = chrono::high_resolution_clock::now();

		popFront();

		auto o2 = chrono::high_resolution_clock::now();
		outcomeList.tMShort(o1, o2);

		clearAll();
	}
	cout << "------------------------------------------\n"
		"Usuwanie z konca:\n";
	for (int i = 0; i < 100; i++)
	{
		generateElements(iLTPoChoice);

		auto o1 = chrono::high_resolution_clock::now();

		popEnd();

		auto o2 = chrono::high_resolution_clock::now();
		outcomeList.tMShort(o1, o2);

		clearAll();
	}
	cout << "------------------------------------------\n"
		"Usuwanie ze srodka:\n";
	for (int i = 0; i < 100; i++)
	{
		generateElements(iLTPoChoice);

		int iLTPopValue = ((rand() % iLTPoChoice) + 0);
		auto o1 = chrono::high_resolution_clock::now();

		popMiddleIndex(iLTPopValue);

		auto o2 = chrono::high_resolution_clock::now();
		outcomeList.tMShort(o1, o2);

		clearAll();
	}

	shL.done();
}

void Lista::testSearch()
{
	int iLTDChoice;
	cout << "Dla ilu elementow maja zostac przeprowadzone testy?";
	cin >> iLTDChoice;

	srand(time(0));

	cout << "------------------------------------------\n"
		"Szukanie elementu:\n";
	for (int i = 0; i < 100; i++)
	{
		generateElements(iLTDChoice);

		int iLTSearchValue = rand();
		auto o1 = chrono::high_resolution_clock::now();

		displayOneValue(iLTSearchValue);

		auto o2 = chrono::high_resolution_clock::now();
		outcomeList.tMShort(o1, o2);

		clearAll();
	}
	shL.done();
}