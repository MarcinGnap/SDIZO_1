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

void Lista::listMenu()									//	Menu g��wne listy dwukierunkowej.
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
			pushMenu();									//	Menu dodawania element�w do listy.
			break;
		}
		case 2:
		{
			popMenu();									//	Menu usuwania element�w z listy.
			break;
		}
		case 3:
		{
			displayMenu();								//	Menu Wy�wietlania zawarto�ci listy.
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
			shL.noOption();								//	Wy�wietlenie komunikatu o wybraniu nieistniej�cej opcji.
			break;
		}
		}
	}
}

void Lista::pushMenu()											//	Menu dodawania element�w do listy.
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
			cin >> iLNewFrontElement;							//	Wybranie warto�ci dodawanego elementu.

			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpocz�cia operacji.

			pushFront(iLNewFrontElement);						//	Dodanie elementu na pocz�tek listy.

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zako�czenia programu.
			outcomeList.tMOutcome(o1, o2);						//	Wy�wietlenie czasu wykonania operacji.
			displayAll();
			shL.done();											//	Wy�wietlenie komunikatu o zako�czeniu zadania oraz czekanie na naci�ni�cie klawisza przez u�ytkownika.
			break;
		}
		case 2:
		{
			int iLNewEndElement;

			cout << "Podaj liczbe jaka ma byc dodana do listy:\n";
			cin >> iLNewEndElement;								//	Wyb�r warto�ci dodawanego elementu.
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpocz�cia operacji.

			pushEnd(iLNewEndElement);							//	Dodanie elementu na koniec listy.

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zako�czenia programu.
			outcomeList.tMOutcome(o1, o2);						//	Wy�wietlenie czasu wykonania operacji.
			displayAll();
			shL.done();											//	Wy�wietlenie komunikatu o zako�czeniu zadania oraz czekanie na naci�ni�cie klawisza przez u�ytkownika.
			break;
		}
		case 3:
		{
			int iLPushValue, iLPushElement;
			cout << "Wybierz, po ktorym elemencie ma zostac wstawiony twoj element:\n";
			cin >> iLPushValue;									//	Wybranie po jakim elemencie ma zosta� wstawiony nowy element.
			cout << "Wybierz wartosc wstawianego elementu:\n";
			cin >> iLPushElement;								//	Wybranie warto�ci wstawianego elementu.
			cout << "Wybrany element zostanie wstawiony po elemencie: " << iLPushValue << " i bedzie mial wartosc: " << iLPushElement << ".\n";
			
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpocz�cia operacji.

			if (pushMiddleValue(iLPushValue, iLPushElement) == true)	//	Dodanie elementu w okre�lone miejsce listy.
			{
				cout << "Udalo sie dodac element...\n";
			}
			else
			{
				shL.noIn();
			}

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zako�czenia programu.
			outcomeList.tMOutcome(o1, o2);						//	Wy�wietlenie czasu wykonania operacji.
			displayAll();
			shL.done();											//	Wy�wietlenie komunikatu o zako�czeniu zadania oraz czekanie na naci�ni�cie klawisza przez u�ytkownika.
			break;
		}
		case 4:
		{
			int iLPushPosition, iLPushElement;
			cout << "Wybierz pozycje, na ktorej ma zostac wstawiony element:\n";
			cin >> iLPushPosition;								//	Wybranie po jakim elemencie ma zosta� wstawiony nowy element.
			cout << "Wybierz wartosc wstawianego elementu:\n";
			cin >> iLPushElement;								//	Wybranie warto�ci wstawianego elementu.
			int iLRightPush = iLPushPosition - 1;
			
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpocz�cia operacji.

			if (pushMiddleIndex(iLRightPush, iLPushElement) == true)	//	Dodanie elementu w okre�lone miejsce listy.
			{
				cout << "Wybrany element zostal na pozycje: " << iLPushPosition << " i ma ma wartosc: " << iLPushElement << ".\n";
			}
			else
			{
				shL.away();
			}

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zako�czenia programu.
			outcomeList.tMOutcome(o1, o2);						//	Wy�wietlenie czasu wykonania operacji.
			displayAll();
			shL.done();											//	Wy�wietlenie komunikatu o zako�czeniu zadania oraz czekanie na naci�ni�cie klawisza przez u�ytkownika.
			break;
		}
		case 5:
		{
			readFromFileL();									//	Wczytanie element�w z pliku tekstowego.

			displayAll();
			shL.done();											//	Wy�wietlenie komunikatu o zako�czeniu wykonywania operacji.

			break;
		}
		case 6:
		{
			int iLNumberOfGen;
			cout << "Ile elementow ma zostac wygenerowanych?\n";
			cin >> iLNumberOfGen;								//	Wyb�r ilo�ci wylosowanych element�w.
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpocz�cia operacji.
			srand(time(0));

			generateElements(iLNumberOfGen);					//	Wygenerowanie okre�lonej liczby element�w.

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zako�czenia wykonywania operacji.
			outcomeList.tMOutcome(o1, o2);						//	Wy�wietlenie czasu wykonywania operacji.

			displayAll();
			shL.done();											//	Wy�wietlenie komuniaktu o zako�czeniu wykonywania operacji.

			break;
		}
		case 7:
		{
			return;
			break;
		}
		default:
		{
			shL.noOption();										//	Wy�wietlenie komunikatu o wybraniu nieistniej�cej opcji.
			break;
		}
		}
	}
}

void Lista::popMenu()									//	Menu usuwania element�w z listy.
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
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpocz�cia operacji.

			popFront();											//	Usuni�cie g�owy listy.

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zako�czenia programu.
			outcomeList.tMOutcome(o1, o2);						//	Wy�wietlenie czasu wykonania operacji.
			displayAll();
			shL.done();											//	Wy�wietlenie komunikatu o zako�czeniu zadania oraz czekanie na naci�ni�cie klawisza przez u�ytkownika.
			break;
		}
		case 2:
		{
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpocz�cia operacji.

			popEnd();											//	Usuni�cie ogona listy.

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zako�czenia programu.
			outcomeList.tMOutcome(o1, o2);						//	Wy�wietlenie czasu wykonania operacji.
			displayAll();
			shL.done();											//	Wy�wietlenie komunikatu o zako�czeniu zadania oraz czekanie na naci�ni�cie klawisza przez u�ytkownika.
			break;
		}
		case 3:
		{
			int iLPopValue;
			cout << "Wybierz, ktory element ma zostac usuniety:\n";
			cin >> iLPopValue;									//	Wybranie usuwanej warto�ci.
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpocz�cia operacji.

			if (popMiddleValue(iLPopValue) == true)				//	Usuni�cie wskazanego elementu listy.
			{
				cout << "Wybrany element zostal usuniety ze struktury.\n";
			}
			else
			{
				shL.noIn();
			}

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zako�czenia programu.
			outcomeList.tMOutcome(o1, o2);						//	Wy�wietlenie czasu wykonania operacji.
			displayAll();
			shL.done();											//	Wy�wietlenie komunikatu o zako�czeniu zadania oraz czekanie na naci�ni�cie klawisza przez u�ytkownika.
			break;
		}
		case 4:
		{
			int iLPopIndex;
			cout << "Wybierz, ktory element ma zostac usuniety:\n";
			cin >> iLPopIndex;									//	Wybranie usuwanej warto�ci.
			int iTRightPop = iLPopIndex - 1;					//	Zmienna zawieraj�ca poprawn� pozycj� usuwanego elementu.
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpocz�cia operacji.

			if (popMiddleIndex(iTRightPop) == true)				//	Usuni�cie wskazanego elementu listy.
			{
				cout << "Wybrany element zostal usuniety ze struktury.\n";
			}
			else
			{
				shL.noIn();
			}

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zako�czenia programu.
			outcomeList.tMOutcome(o1, o2);						//	Wy�wietlenie czasu wykonania operacji.
			displayAll();
			shL.done();											//	Wy�wietlenie komunikatu o zako�czeniu zadania oraz czekanie na naci�ni�cie klawisza przez u�ytkownika.
			break;
		}
		case 5:
		{
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpocz�cia operacji.

			clearAll();											//	Wy�wietlenie ca�ej zawarto�ci listy.

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zako�czenia operacji.
			outcomeList.tMOutcome(o1, o2);						//	Wy�wietlenie czasu wykonania operacji.
			displayAll();
			shL.done();											//	Wy�wietlenie komunikatu o zako�czeniu zadania oraz czekanie na naci�ni�cie klawisza przez u�ytkownika.
			break;
		}
		case 6:
		{
			return;
			break;
		}
		default:
		{
			shL.noOption();								//	Wy�wietlenie kounikatu o wybraniu nieistniej�cej opcji.
			break;
		}
		}
	}
}

void Lista::displayMenu()										//	Menu wy�wiatlania.
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
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpocz�cia operacji.

			displayAll();										//	Wy�wietlenie ca�ej zawarto�ci listy.

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zako�czenia operacji.
			outcomeList.tMOutcome(o1, o2);						//	Wy�wietlenie czasu wykonania operacji.
			shL.done();
			break;
		}
		case 2:
		{
			int iLDisplayChoice;
			cout << "Wybierz, ktory element ma zostac wyswietlony:\n";
			cin >> iLDisplayChoice;								//	Wyb�r warto�ci, kt�ra ma zosta� wy�wietlona.
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpocz�cia operacji.

			if (displayOneValue(iLDisplayChoice) == true)		//	Wy�wietlenie okre�lonego elementu listy.
			{
				cout << "Wybrany element znajduje sie w strukturze." << endl;
			}
			else
			{
				shL.noIn();
			}

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zako�czenia operacji.
			outcomeList.tMOutcome(o1, o2);						//	Wy�wietlenie czasu wykonania operacji.
			shL.done();											//	Wy�wietlenie komunikatu o zako�czeniu wykonywania operacji.

			break;
		}
		case 3:
		{
			int iLDisplayIndex;
			cout << "Wybierz, ktory element ma zostac wyswietlony:\n";
			cin >> iLDisplayIndex;								//	Wyb�r elementu, kt�ry ma zosta� wy�wietlony.
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpocz�cia operacji.

			int iLIndex = displayOneIndex(iLDisplayIndex);
			if (iLIndex == NULL)								//	Wy�wietlenie okre�lonego elementu listy.
			{
				shL.noIn();
			}
			else
			{
				cout << "Wybrany element: " << iLDisplayIndex << " ma wartosc rowna " << iLIndex << endl;
			}

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zako�czenia operacji.
			outcomeList.tMOutcome(o1, o2);						//	Wy�wietlenie czasu wykonania operacji.
			shL.done();											//	Wy�wietlenie komunikatu o zako�czeniu wykonywania operacji.

			break;
		}
		case 4:
		{
			return;
			break;
		}
		default:
		{
			shL.noOption();										//	Wy�wietlenie komunikatu o wybraniu nieistniej�cej opcji.
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

void Lista::pushFront(int iLNewFrontElement)			//	Dodanie elementu na pocz�tek listy.
{
	Node *newNode = new Node(iLNewFrontElement);		//	Stworzenie nowej "kom�rki" listy dla dodawanego elementu.

	if (nHead != NULL)									//	Sprawdzenie czy listy jest pusta.
	{
		newNode->nNext = nHead;							//	Wska�nik nowej kom�rki na nast�pny element zostaje przypisany poprzedniej g�owie.
		nHead->nPrev = newNode;							//	Wska�nik poprzedniej g�owy na poprzedni element zostaje przypisany nowemu elementowi.
		nHead = newNode;								//	Zmiana g�owy na nowy element.
	}
	else
	{
		nHead = newNode;								//	Przypisanie nowego elementu jako g�owy.
		nTail = newNode;								//	Przypisanie nowego elementu jako ogona.
	}
}

void Lista::pushEnd(int iLNewEndElement)				//	Dodanie elementu na koniec listy.
{
	Node *newNode = new Node(iLNewEndElement);			//	Stworzenie nowej kom�rki z wybran� warto�ci�.
	if (nHead != NULL)									//	Sprawdzenie czy lista jest pusta.
	{
		newNode->nPrev = nTail;							//	Wska�nik nowej ko�rki na element poprzedni zostaje przypisany do ogona.
		nTail->nNext = newNode;							//	Wska�nik ogona na nast�pny element zostaje przypisany do nowej kom�rki.
		nTail = newNode;								//	Przypisanie nowego elementu jako ogona.
	}
	else
	{
		nHead = newNode;								//	Przypisanie nowego elementu jako g�owy.
		nTail = newNode;								//	Przypisanie nowego elementu jako ogona.
	}
}

bool Lista::pushMiddleValue(int iLPushValue, int iLPushElement)		//	Dodanie elementu w okre�lone miejsce w li�cie.
{
	Node *tempNode = nHead;								//	Stworzenie tyczasowego wska�nika przechowuj�cego adres g�owy.
	if (nHead != NULL)									//	Sprawdzenie czy lista jest pusta.
	{
		while (tempNode->nNext != NULL)					//	P�tla wykonuj�ca si� od pocz�tkowego elementu listy do ostatniego.
		{
			if (tempNode->iNData == iLPushValue)		//	Sprawdzenie czy warto�� elementu zgadza si� z elementem, po kt�rym u�ytkownik chce wstawi� nowy element.
			{
				if (tempNode == nTail)					//	Sprawdzenie czy znale�iony element jest ogonem.
				{
					pushEnd(iLPushElement);
				}
				else
				{
					Node *newNode = new Node(iLPushElement);//	Stworzenie nowego elementu.
					tempNode->nNext->nPrev = newNode;	//	Wska�nik nast�pnego elementu po znale�ionej kom�rce na poprzedni element zostaje przypisany do nowej kom�rki.
					newNode->nNext = tempNode->nNext;	//	Wska�nik nowej kom�rki na nast�pny element zostaje przypisany do nast�pnej kom�rki po znale�ionej.
					newNode->nPrev = tempNode;			//	Wska�nik nowej kom�rki na porzedni element zostaje przypisany do znale�ionej kom�rki.
					tempNode->nNext = newNode;			//	Wska�nik znale�ionej kom�rki na nast�pny element zostaje przypisany do nowej kom�rki.
				}
				return true;;							//	Etykieta, dzi�ki Kt�rej program wychodzi z p�tli po znale�ieniu odpowiedniej warto��i.
			}
			tempNode = tempNode->nNext;					//	Przypisanie tymczasowego elementu do nast�pnego.
		}
	}
	else
	{
		shL.empty();									//	Wy�wietlenie komunikatu o braku zawarto�ci struktury.
	}
	return false;
}

bool Lista::pushMiddleIndex(int iLRightPush, int iLPushElementI)
{
	int i = 0;
	Node *tempNode = nHead;								//	Stworzenie nowego wska�nika i przypisanie do niego g�owy.
	if (nHead != NULL)									//	Sprawdzenie czy lista ma zawarto��.
	{
		while (tempNode != NULL)						//	P�tla wykonuj�ca si� od pocz�tkowego do ostatniego elementu listy.
		{
			if (i == iLRightPush)						//	Sprawdzenie czy index aktualnie "przegl�danej" kom�rki jest taki sama jak wybrany.
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
					tempNode->nNext->nPrev = newNode;	//	Wska�nik nast�pnego elementu po znale�ionej kom�rce na poprzedni element zostaje przypisany do nowej kom�rki.
					newNode->nNext = tempNode->nNext;	//	Wska�nik nowej kom�rki na nast�pny element zostaje przypisany do nast�pnej kom�rki po znale�ionej.
					newNode->nPrev = tempNode;			//	Wska�nik nowej kom�rki na porzedni element zostaje przypisany do znale�ionej kom�rki.
					tempNode->nNext = newNode;			//	Wska�nik znale�ionej kom�rki na nast�pny element zostaje przypisany do nowej kom�rki.

				}
				return true;
			}
			i++;
			tempNode = tempNode->nNext;					//	Przypisanie wska�nikowi tyczasowej kom�rki adresu elementu nast�pnego.
		}
	}
	else
	{
		shL.empty();									//	Wy�wietlenie komunikatu o braku zawarto�ci listy.
	}
	return false;
}

void Lista::readFromFileL()								//	Odczytanie i zapisanie element�w z pliku tekstowego.
{
	ifstream ifLFile("dane.txt", ios::in);				//	Otworzenie pliku tekstowego o nazwie "dane.txt" w trybie odczytu.
	if (ifLFile.good())									//	Sprawdzenie czy plik zosta� pomy�lnie otwarty.
	{
		shL.opened();									//	Wy�wietlenie komunikatu o pomy�lnym otwarciu pliku tekstowego.

		auto o1 = chrono::high_resolution_clock::now();	//	Pomiar czasu w momencie rozpocz�cia operacji.

		string sLLineCountBuffer;
		getline(ifLFile, sLLineCountBuffer);			//	Odczytanie pierwszej linii do wcze�niej utworzonej zmiennej. Docelowo linia ta ma przechowywa� ilo�� element�w odczytywanych z pliku.
		int iLLineCount = stoi(sLLineCountBuffer);		//	Zmienienie typu odczytanej zmiennej na typ ca�kowyti 4-bajtowy.
		cout << "Ilosc elementow przekazanych do struktury: " << iLLineCount << endl;

		string sLFileHead;
		getline(ifLFile, sLFileHead);					//	Odczytanie pierwszego elementu z pliku tekstowego.
		int iLFileHead = stoi(sLFileHead);				//	Zmienienie typu odczytanej zmiennej na typ ca�kowyti 4-bajtowy.
		Node *tempNode = new Node(iLFileHead);			//	Stworzenie nowego elementu.
		nHead = tempNode;								//	Przypisanie nowego elemtnu jako g�owy.

		for (int i = 1; i <= iLLineCount - 2; i++)		//	P�tla wykonuj�ca si� od drugiego elementu odczytanego do przedostatniego.
		{
			string sLLineValueBuffer;
			getline(ifLFile, sLLineValueBuffer);		//	Odczytanie elementu.
			int iLLineValue = stoi(sLLineValueBuffer);	//	Zmienienie typu odczytanej zmiennej na typ ca�kowyti 4-bajtowy.

			Node *newNode = new Node(iLLineValue);		//	Stworzenie nowego elemntu z odczytan� warto�ci�.
			tempNode->nNext = newNode;					//	Wska�nik porpzedniego elementu na nast�pny element zostaje przypisany do nowego elementu.
			newNode->nPrev = tempNode;					//	Wska�nik nowego elementu na poprzedni element zostaje przypisany do porzedniego elementu.
			tempNode = newNode;							//	Nowy element zostaje uznany za tymczasowy element.
		}
		string sLFileTail;
		getline(ifLFile, sLFileTail);					//	Odczytanie ostatniego elementu.
		int iLFileTail = stoi(sLFileTail);				//	Zmienienie typu odczytanej zmiennej na typ ca�kowyti 4-bajtowy.
		Node *newNode = new Node(iLFileTail);			//	Stworzenie nowego elementu z odczytanymi danymi.
		tempNode->nNext = newNode;						//	Wska�nik porpzedniego elementu na nast�pny element zostaje przypisany do nowego elementu.
		newNode->nPrev = tempNode;						//	Wska�nik nowego elementu na poprzedni element zostaje przypisany do porzedniego elementu.
		nTail = newNode;								//	Przypisanie nowego elementu jako ogona.

		ifLFile.close();								//	Zamkni�cie pliku.

		auto o2 = chrono::high_resolution_clock::now();	//	Pomiaer czasu w momencie zako�czenia operacji.

		outcomeList.tMOutcome(o1, o2);					//	Wy�wietlenie czasu wykonywania operacji.
	}
	else
	{
		shL.noFile();									//	Wy�wietlenie komunikatu o problemie z plikiem.
	}
}

void Lista::generateElements(int iLNumberOfGen)			//	Wygenerowanie okre�lonej liczby elemet�w do listy.
{
	if (iLNumberOfGen == 0)
	{
		shL.noOption();
	}
	else if (iLNumberOfGen == 1)
	{
		int iLGenerated = rand();							//	Pseudo wylosowanie nowej warto�ci.
		Node *newNode = new Node(iLGenerated);				//	Stworzenie nowego elementu z now� warto�ci�.
		nHead = newNode;									//	Przypisanie nowego elementu jako g�owy.
		nTail = newNode;									//	Przypisanie nowego elementu jako ogona.
	}
	else if (iLNumberOfGen == 2)
	{
		int iLGeneratedHead = rand();						//	Pseudo wylosowanie elementu.
		Node *tempNode = new Node(iLGeneratedHead);			//	Stworzenie nowego elementu z nowymi danymi.
		nHead = tempNode;									//	Przypisanie nowego elementu jako g�owy.

		int iLGeneratedTail = rand();						//	Pseudo wylosowanie nowej warto�ci.
		Node *newNode = new Node(iLGeneratedTail);			//	Stworzenie nowej kom�rki z now� warto�ci�.
		tempNode->nNext = newNode;							//	Wska�nik tymczasowej kom�rki na nast�pny element zostaje przypisany do nowego elementu.
		newNode->nPrev = tempNode;							//	Wska�nik nowego elementu na poprzedni element zostaje przypisany do tymczasowego elementu.
		nTail = newNode;									//	Nowy element zostaje przypisany jako ogon.
	}
	else
	{
		int iLGeneratedHead = rand();						//	Pseudo wylosowanie elementu.
		Node *tempNode = new Node(iLGeneratedHead);			//	Stworzenie nowego elementu z nowymi danymi.
		nHead = tempNode;									//	Przypisanie nowego elementu jako g�owy.

		for (int i = 0; i < iLNumberOfGen - 2; i++)			//	P�tla wykonuj�ca si� od drugiego do przedostatniego elementu.
		{
			int iLGenerated = rand();						//	Pseudo wylosowanie nowej warto�ci.
			Node *newNode = new Node(iLGenerated);			//	Stworzenie nowego elementu z now� warto�ci�.
			tempNode->nNext = newNode;						//	Wska�nik tymczasowego elementu na nast�pny element zostaje przypisany do nowego elementu.
			newNode->nPrev = tempNode;						//	Wska�nik nowego elementu na poprzedni element zostaje przypisany do tymczasowego elementu.
			tempNode = newNode;								//	Nowy element zostaje przypisany jako tymczasowy element.
		}
		int iLGeneratedTail = rand();						//	Pseudo wylosowanie nowej warto�ci.
		Node *newNode = new Node(iLGeneratedTail);			//	Stworzenie nowej kom�rki z now� warto�ci�.
		tempNode->nNext = newNode;							//	Wska�nik tymczasowej kom�rki na nast�pny element zostaje przypisany do nowego elementu.
		newNode->nPrev = tempNode;							//	Wska�nik nowego elementu na poprzedni element zostaje przypisany do tymczasowego elementu.
		nTail = newNode;									//	Nowy element zostaje przypisany jako ogon.
	}
}

void Lista::popFront()									//	Usuni�cie elementu z pocz�tki listy.
{
	if (nHead != NULL)									//	Sprawdzenie czy lista jest pusta.
	{
		if (nHead->nNext != NULL)						//	Sprawdzenie czy lista jest jedno elementowa.
		{
			nHead = nHead->nNext;						//	Zmiana g�owy na element poprzedni.
			delete nHead->nPrev;						//	Usuni�cie starej g�owy.
			nHead->nPrev = nullptr;						//	Wyzerowanie wska�nika na poprzedni element przed now� g�ow�.
		}
		else
		{
			delete nHead;								//	Usuni�cie g�owy.
			nTail = nullptr;
			nHead = nullptr;
		}
	}
	else
	{
		shL.empty();									//	Wy�wietlenie kounikatu o braku zawarto�ci listy.
	}
}

void Lista::popEnd()									//	Usuni�cie elementu z ko�ca listy.
{
	if (nHead != NULL)									//	Sprawdzenie czy lista ma zawarto��.
	{
		if (nTail->nPrev != NULL)						//	Sprawdzenie czy lista nie jest jednoelementowa.
		{
			nTail = nTail->nPrev;						//	Zmiana ogona na element poprzedni.

			delete nTail->nNext;						//	Usuni�cie starego ogona.
			nTail->nNext = nullptr;						//	Wyzerowanie wska�nika na nast�pny element po nowym ogonie.
		}
		else
		{
			delete nTail;								//	Uusni�cie ogona.
			nTail = nullptr;
			nHead = nullptr;
		}
	}
	else
	{
		shL.empty();									//	Wy�wietlenie kounikatu o braku zawarto�ci listy.
	}
}

bool Lista::popMiddleValue(int iLPopValue)				//	Usuni�cie wskazanego elementu.
{
	Node *tempNode = nHead;								//	Stworzenie nowego wska�nika i przypisanie do niego g�owy.
	if (nHead != NULL)									//	Sprawdzenie czy lista nie jest pusta.
	{
		while (tempNode->nNext != NULL)					//	P�tla wykonuj�ca si� od pierwszego do ostatniego elementu listy.
		{
			if (tempNode->iNData == iLPopValue)			//	Sprawdzenie czy warto�� przechowywana przez kom�rk� jest identyczna jak warto�� wybrana.
			{
				tempNode->nNext->nPrev = tempNode->nPrev;	//	Wska�nik kom�rki nast�pnej po elemencie tymczasowym na element nast�pny zostaje przypisany do wska�nika kom�rki tymczasowej na kom�rk� poprzedni� od nast�pnej.
				tempNode->nPrev->nNext = tempNode->nNext;	//	Wska�nik kom�rki poprzedniej od elementu usuwanego na kom�rk� nast�pn� zostaje przypisany do wska�nika usuwanej kom�rki na element nast�pny.
				delete tempNode;						//	Usuni�cie elementu.
				return true;
			}
			tempNode = tempNode->nNext;					//	Zmienienie wska�nika kom�rki tymczasowej na element nast�pny.
		}
	}
	else
	{
		shL.empty();									//	Wy�wietlenie komunikatu o braku zawarto�ci listy.
	}
	return false;
}

bool Lista::popMiddleIndex(int iLPopIndex)
{
	int i = 0;
	Node *tempNode = nHead;								//	Stworzenie nowego wska�nika i przypisanie do niego g�owy.
	if (nHead != NULL)									//	Sprawdzenie czy lista nie jest pusta.
	{
		while (tempNode != NULL)						//	P�tla wykonuj�ca si� od pocz�tkowego do ostatniego elementu listy.
		{
			if (i == iLPopIndex)						//	Sprawdzenie czy index aktualnie "przegl�danej" kom�rki jest taki sama jak wybrany.
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
					tempNode->nNext->nPrev = tempNode->nPrev;	//	Wska�nik kom�rki nast�pnej po elemencie tymczasowym na element nast�pny zostaje przypisany do wska�nika kom�rki tymczasowej na kom�rk� poprzedni� od nast�pnej.
					tempNode->nPrev->nNext = tempNode->nNext;	//	Wska�nik kom�rki poprzedniej od elementu usuwanego na kom�rk� nast�pn� zostaje przypisany do wska�nika usuwanej kom�rki na element nast�pny.
					delete tempNode;							//	Usuni�cie elementu.
				}
				return true;
			}
			i++;
			tempNode = tempNode->nNext;							//	Przypisanie wska�nikowi tyczasowej kom�rki adresu elementu nast�pnego.
		}
	}
	else
	{
		shL.empty();											//	Wy�wietlenie komunikatu o braku wybranej pozycji w li�cie.
	}
	return false;
}

void Lista::clearAll()									//	Usuni�cie wszystkich element�w listy.
{
	Node *tempNode = nHead;								//	Stworzenie tymczasowego wska�nika i przypisanie do niego g�owy.

	if (nHead != NULL)									//	Sprawdzenie czy lista nie jest pusta.
	{
		while (nHead != NULL)							//	P�tla wykonuj�ca si� dop�ki g�owa ma warto��.
		{
			tempNode = nHead->nNext;					//	Przypisanie do wska�nika tymczasowego elementu nast�pnego po g�owie.
			delete nHead;								//	Usuni�cie g�owy.
			nHead = tempNode;							//	Przypisanie do g�owy nast�pnej kom�rki.
		}
	}
	else
	{
		shL.empty();									//	Wy�wietlenie komunikatu o braku zawarto�ci listy.
	}
}

void Lista::displayAll()								//	Wy�wietlenie ca�ej zawarto�ci listy.
{
	if (nHead != NULL)									//	Sprawdzenie czy lista nie jest pusta.
	{
		int i = 1;
		Node *tempNode = nHead;							//	Stworzenie tyczasowego wska�nika i przypisanie do niego g�owy.
		cout << "Zawartosc listy (od glowy):\n";
		while (tempNode != NULL)						//	P�tla wykonuj�ca si� dop�ki warto�� tyczasowego wska�nika nie jest pusta.
		{
			cout << "Element nr " << i << " ma wartosc rowna: " << tempNode->iNData << endl;	//	Wy�wietlenie zawarto�ci kom�rki.
			tempNode = tempNode->nNext;					//	Przypisanie do wska�nika tyczasowej kom�rki element nast�pny po danej kom�rce.
			i++;										//	Iteracja ziennej odpowiadaj�cej za wy�wietlanie "numeru" elementu.
		}
		cout << "Head = " << nHead->iNData << endl << "Tail = " << nTail->iNData << endl;	//	Wy�wietlenie warto�ci g�owy i ogona.
	}
	else
	{
		shL.empty();									//	Wy�wietlenie komunikatu o braku zawarto�ci listy.
	}
}

bool Lista::displayOneValue(int iLDisplayChoice)		//	Wy�witlenie wybranego elementu listy.
{
	Node *tempNode = nHead;								//	Stworzenie nowego wska�nika i przypisanie do niego g�owy.
	if (nHead != NULL)									//	Sprawdzenie czy lista ma zawarto��.
	{
		while (tempNode != NULL)						//	P�tla wykonuj�ca si� od pocz�tkowego do ostatniego elementu listy.
		{
			if (tempNode->iNData == iLDisplayChoice)	//	Sprawdzenie czy warto�� aktualnie "przegl�danej" kom�rki jest taka sama jak wybrana warto��.
			{
				cout << "Ilosc pozycji od glowy: " << endl;	//	Wy�wietlenie, na kt�rej pozycji od g�owy "le�y" wybrana warto��.
				return true;
			}
			tempNode = tempNode->nNext;					//	Przypisanie wska�nikowi tyczasowej kom�rki adresu elementu nast�pnego.
		}
		return false;
	}
	else
	{
		shL.empty();									//	Wy�wietlenie komunikatu o braku zawarto�ci listy.
	}
	return false;
}

int Lista::displayOneIndex(int iLDisplayIndex)
{
	int i = 0;
	Node *tempNode = nHead;								//	Stworzenie nowego wska�nika i przypisanie do niego g�owy.
	if (nHead != NULL)									//	Sprawdzenie czy lista ma zawarto��.
	{
		while (tempNode != NULL)						//	P�tla wykonuj�ca si� od pocz�tkowego do ostatniego elementu listy.
		{
			if (i == iLDisplayIndex)					//	Sprawdzenie czy index aktualnie "przegl�danej" kom�rki jest taki sama jak wybrany.
			{
				return tempNode->iNData;
			}
			i++;
			tempNode = tempNode->nNext;					//	Przypisanie wska�nikowi tyczasowej kom�rki adresu elementu nast�pnego.
		}
		return NULL;
	}
	else
	{
		shL.empty();									//	Wy�wietlenie komunikatu o braku zawarto�ci listy.
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