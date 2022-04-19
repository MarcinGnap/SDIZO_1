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
				"\t2.Menu odejmowania.\n"
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

void Lista::pushMenu()									//	Menu dodawania element�w do listy.
{
	for (;;)
	{
		shL.cls();										//	"Wyczyszczenie" konsoli.

		short sLChoicePushMenu;

		cout << "Prosze wybrac:\n"
				"\t1.Dodanie na poczatek struktury.\n"
				"\t2.Dodanie na koniec struktury.\n"
				"\t3.Dodanie w okreslonie miejsce w strukturze.\n"
				"\t4.Odczytanie danych z pliku tekstowego.\n"
				"\t5.Wygenerowanie okreslonej ilosci danej do struktury.\n"
				"\t6.Powrot.\n";
		cin >> sLChoicePushMenu;

		switch (sLChoicePushMenu)
		{
		case 1:
		{
			pushFront();								//	Dodanie elementu na pocz�tek listy.
			break;
		}
		case 2:
		{
			pushEnd();									//	Dodanie elementu na koniec listy.
			break;
		}
		case 3:
		{
			pushMiddle();								//	Dodanie elementu w okre�lone miejsce listy.
			break;
		}
		case 4:
		{
			readFromFileL();							//	Wczytanie element�w z pliku tekstowego.
			break;
		}
		case 5:
		{
			generateElements();							//	Wygenerowanie okre�lonej liczby element�w.
			break;
		}
		case 6:
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

void Lista::popMenu()									//	Menu usuwania element�w z listy.
{
	for (;;)
	{
		shL.cls();										//	"Wyczyzczenie" konsoli.

		short sLChoicePopMenu;

		cout << "Prosze wybrac:\n"
				"\t1.Usuniecie elementu z poczatku struktury.\n"
				"\t2.Usuniecie elementu z konca struktury.\n"
				"\t3.Usuniecie elementu z okreslonego miejsca w struktury.\n"
				"\t4.Usuniecie wszytkich elementow w strukturze.\n"
				"\t5.Powrot.\n";
		cin >> sLChoicePopMenu;

		switch (sLChoicePopMenu)
		{
		case 1:
		{
			popFront();									//	Usuni�cie g�owy listy.
			break;
		}
		case 2:
		{
			popEnd();									//	Usuni�cie ogona listy.
			break;
		}
		case 3:
		{
			popMiddle();								//	Usuni�cie wskazanego elementu listy.
			break;
		}
		case 4:
		{
			clearAll();									//	Usuni�cie wszystkich element�w listy.
			break;
		}
		case 5:
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

void Lista::displayMenu()								//	Menu wy�wiatlania.
{
	for (;;)
	{
		shL.cls();										//	"Wyczyszczenie" ekranu.

		short sLChoiceDisplayMenu;

		cout << "Prosze wybrac:\n"
				"\t1.Wyswietlenie calej zawartosci struktury.\n"
				"\t2.Wyswietlenie okreslonego elementu struktury.\n"
				"\t3.Powrot.\n";
		cin >> sLChoiceDisplayMenu;

		switch (sLChoiceDisplayMenu)
		{
		case 1:
		{
			displayAll();								//	Wy�wietlenie ca�ej zawarto�ci listy.
			break;
		}
		case 2:
		{
			displayOne();								//	Wy�wietlenie okre�lonego elementu listy.
			break;
		}
		case 3:
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

void Lista::pushFront()									//	Dodanie elementu na pocz�tek listy.
{
	int iLNewFrontElement;

	cout << "Podaj liczbe jaka ma byc dodana do listy:\n";
	cin >> iLNewFrontElement;							//	Wybranie warto�ci dodawanego elementu.

	auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpocz�cia operacji.
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
	auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zako�czenia operacji.
	
	outcomeList.tMOutcome(o1, o2);						//	Wy�wietlenie czasu wykonywania operacji.

	shL.done();											//	Wy�wietlenie komunikatu zako�czenia wykonywania operacji.
}

void Lista::pushEnd()									//	Dodanie elementu na koniec listy.
{
	int iLNewEndElement;

	cout << "Podaj liczbe jaka ma byc dodana do listy:\n";
	cin >> iLNewEndElement;								//	Wyb�r warto�ci dodawanego elementu.

	auto o1 = chrono::high_resolution_clock::now();		//	Poimar czasu w momencie rozpocz�cia operacji.
	
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
	auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zako�czenia wykonywania operacji.

	outcomeList.tMOutcome(o1, o2);						//	Wy�wietlenie czasu wykonywania operacji.

	shL.done();											//	Wy�wietlenie komunikatu o zako�czeniu wykonywania zadania.
}

void Lista::pushMiddle()								//	Dodanie elementu w okre�lone miejsce w li�cie.
{
	Node *tempNode = nHead;								//	Stworzenie tyczasowego wska�nika przechowuj�cego adres g�owy.
	int iLPushPosition, iLPushElement;
	cout << "Wybierz, po ktorym elemencie ma zostac wstawiony twoj element:\n";
	cin >> iLPushPosition;								//	Wybranie po jakim elemencie ma zosta� wstawiony nowy element.
	cout << "Wybierz wartosc wstawianego elementu:\n";
	cin >> iLPushElement;								//	Wybranie warto�ci wstawianego elementu.
	cout << "Wybrany element zostanie wstawiony po elemencie: " << iLPushPosition << " i bedzie mial wartosc: " << iLPushElement << ".\n";

	auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpocz�cia wykonywania operacji,

	if (nHead != NULL)									//	Sprawdzenie czy lista jest pusta.
	{
		while (tempNode->nNext != NULL)					//	P�tla wykonuj�ca si� od pocz�tkowego elementu listy do ostatniego.
		{
			if (tempNode->iNData == iLPushPosition)		//	Sprawdzenie czy warto�� elementu zgadza si� z elementem, po kt�rym u�ytkownik chce wstawi� nowy element.
			{
				Node *newNode = new Node(iLPushElement);//	Stworzenie nowego elementu.
				if (tempNode == nTail)					//	Sprawdzenie czy znale�iony element jest ogonem.
				{
					newNode->nPrev = nTail;				//	Wska�nik nowej kom�rki na poprzedni element zostaje przypisany do porzedniego ogona.
					nTail->nNext = newNode;				//	Wska�nik poprzedniego ogona na nast�pny element zostaje przypisany do nowej kom�rki.
					nTail = newNode;					//	Przypisanie nowego elementu jako ogona.
				}
				else
				{
					tempNode->nNext->nPrev = newNode;	//	Wska�nik nast�pnego elementu po znale�ionej kom�rce na poprzedni element zostaje przypisany do nowej kom�rki.
					newNode->nNext = tempNode->nNext;	//	Wska�nik nowej kom�rki na nast�pny element zostaje przypisany do nast�pnej kom�rki po znale�ionej.
					newNode->nPrev = tempNode;			//	Wska�nik nowej kom�rki na porzedni element zostaje przypisany do znale�ionej kom�rki.
					tempNode->nNext = newNode;			//	Wska�nik znale�ionej kom�rki na nast�pny element zostaje przypisany do nowej kom�rki.
				}
				goto pushed;							//	Etykieta, dzi�ki Kt�rej program wychodzi z p�tli po znale�ieniu odpowiedniej warto��i.
			}
			tempNode = tempNode->nNext;					//	Przypisanie tymczasowego elementu do nast�pnego.
		}
	}
	else
	{
		shL.empty();									//	Wy�wietlenie komunikatu o braku zawarto�ci struktury.
	}
pushed:													//	Etykieta.
	auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zako�czenia operacji.

	outcomeList.tMOutcome(o1, o2);						//	Wy�wietlenie czasu wykonywania operacji.
	shL.done();											//	Wy�wietlenie komunikatu o zako�czeniu wykonywania operacji.
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

		shL.done();										//	Wy�wietlenie komuniaktu o wykonaniu operacji.
	}
	else
	{
		shL.noFile();									//	Wy�wietlenie komunikatu o problemie z plikiem.
	}
}

void Lista::generateElements()							//	Wygenerowanie okre�lonej liczby elemet�w do listy.
{
	int iLNumberOfGen;
	cout << "Ile elementow ma zostac wygenerowanych?\n";
	cin >> iLNumberOfGen;								//	Wyb�r ilo�ci wylosowanych element�w.

	auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpocz�cia operacji.

	srand(time(0));

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

	auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zako�czenia wykonywania operacji.

	outcomeList.tMOutcome(o1, o2);						//	Wy�wietlenie czasu wykonywania operacji.

	shL.done();											//	Wy�wietlenie komuniaktu o zako�czeniu wykonywania operacji.
}

void Lista::popFront()									//	Usuni�cie elementu z pocz�tki listy.
{
	auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpocz�cia operacji.
	if (nHead != NULL)									//	Sprawdzenie czy lista jest pusta.
	{
		if (nHead->nNext != NULL)						//	Sprawdzenie czy lista jest jedno elementowa.
		{
			Node *tempNode = nHead->nNext;				//	Stworzenie nowego wska�nika na nast�pny element po g�owie.
			delete nHead;								//	Usuni�cie g�owy.
			nHead = tempNode;							//	Przypisanie nast�pnego eleentu jako g�owy.
		}
		else
		{
			delete nHead;								//	Usuni�cie g�owy.
		}
	}
	else
	{
		shL.empty();									//	Wy�wietlenie kounikatu o braku zawarto�ci listy.
	}
	auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zako�czenia operacji.

	outcomeList.tMOutcome(o1, o2);						//	Wy�wietlenie czasu wykonywania operacji.

	shL.done();											//	Wy�wietlenie komunikatu o zako�czeniu wykonywania operacji.
}

void Lista::popEnd()									//	Usuni�cie elementu z ko�ca listy.
{
	auto o1 = chrono::high_resolution_clock::now();		//	Poiar czasu w momencie rozpocz�cia operacji.
	if (nHead != NULL)									//	Sprawdzenie czy lista ma zawarto��.
	{
		if (nTail->nPrev != NULL)						//	Sprawdzenie czy lista nie jest jednoelementowa.
		{
			Node *tempNode = nTail->nPrev;				//	Stworzenie nowego tyczasowego wska�nika i przypisanie do niego element poprzedni od ogona.
			delete nTail;								//	Usuni�cie ogona.
			nTail = tempNode;							//	Przypisanie nowego ogona do tymczasowego elementu.
		}
		else
		{
			delete nTail;								//	Uusni�cie ogona.
		}
	}
	else
	{
		shL.empty();									//	Wy�wietlenie kounikatu o braku zawarto�ci listy.
	}
	auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zako�czenia operacji.

	outcomeList.tMOutcome(o1, o2);						//	Wy�wietlenie czasu wykonywania operacji.

	shL.done();											//	Wy�wietlenie komunikatu i zako�czeniu wykonywania operacji.
}

void Lista::popMiddle()									//	Usuni�cie wskazanego elementu.
{
	Node *tempNode = nHead;								//	Stworzenie nowego wska�nika i przypisanie do niego g�owy.
	int iLPopChoice;
	cout << "Wybierz, ktory element ma zostac usuniety:\n";
	cin >> iLPopChoice;									//	Wybranie usuwanej warto�ci.
	cout << "Wybrany element: " << iLPopChoice << endl;	//	Wy�wietlenie wybranej warto�ci.

	auto o1 = chrono::high_resolution_clock::now();		//	Poiar czasu w momencie rozpocz�cia operacji.

	if (nHead != NULL)									//	Sprawdzenie czy lista nie jest pusta.
	{
		while (tempNode->nNext != NULL)					//	P�tla wykonuj�ca si� od pierwszego do ostatniego elementu listy.
		{
			if (tempNode->iNData == iLPopChoice)		//	Sprawdzenie czy warto�� przechowywana przez kom�rk� jest identyczna jak warto�� wybrana.
			{
				tempNode->nNext->nPrev = tempNode->nPrev;	//	Wska�nik kom�rki nast�pnej po elemencie tymczasowym na element nast�pny zostaje przypisany do wska�nika kom�rki tymczasowej na kom�rk� poprzedni� od nast�pnej.
				tempNode->nPrev->nNext = tempNode->nNext;	//	Wska�nik kom�rki poprzedniej od elementu usuwanego na kom�rk� nast�pn� zostaje przypisany do wska�nika usuwanej kom�rki na element nast�pny.
				delete tempNode;						//	Usuni�cie elementu.
				goto poped;								//	Etykieta przerywaj�ca p�tl� w momencie usuni�cia warto�ci.
			}
			tempNode = tempNode->nNext;					//	Zmienienie wska�nika kom�rki tymczasowej na element nast�pny.
		}
	}
	else
	{
		shL.empty();									//	Wy�wietlenie komunikatu o braku zawarto�ci listy.
	}
	poped:
	auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zako�czenia operacji.

	outcomeList.tMOutcome(o1, o2);						//	Wy�wietlenie czasu wykonywania operacji.
	shL.done();											//	Wy�wietlenie komunikatu o zako�czeniu wykonywania operacji.
}

void Lista::clearAll()									//	Usuni�cie wszystkich element�w listy.
{
	auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpocz�cia operacji.

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
	auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zako�czenia operacji.

	outcomeList.tMOutcome(o1, o2);						//	Wy�wietlenie czasu wykonywania operacji.
	shL.done();											//	Wy�wietlenie komunikatu o zako�czeniu wykonywania operacji.
}

void Lista::displayAll()								//	Wy�wietlenie ca�ej zawarto�ci listy.
{
	auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpocz�cia operacji.

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
	auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zako�czenia operacji.

	outcomeList.tMOutcome(o1, o2);						//	Wy�wietlenie czasu wykonywanie operacji.
	shL.done();											//	Wy�wietlenie komunikatu o zako�czeniu wykonywania operacji.
}

void Lista::displayOne()								//	Wy�witlenie wybranego elementu listy.
{
	Node *tempNode = nHead;								//	Stworzenie nowego wska�nika i przypisanie do niego g�owy.
	int iLDisplayChoice;
	int i = 0;
	cout << "Wybierz, ktory element ma zostac wyswietlony:\n";
	cin >> iLDisplayChoice;								//	Wyb�r warto�ci, kt�ra ma zosta� wy�wietlona.

	auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpocz�cia operacji.
	
	if (nHead != NULL)									//	Sprawdzenie czy lista ma zawarto��.
	{
		cout << "Wybrany element: " << iLDisplayChoice << endl;		//	Wy�wietlenie wybranej warto�ci.
		while (tempNode != NULL)						//	P�tla wykonuj�ca si� od pocz�tkowego do ostatniego elementu listy.
		{
			i++;										//	Iteracja ziennej odpowiadaj�cej za numer pozycji od g�owy.
			if (tempNode->iNData == iLDisplayChoice)	//	Sprawdzenie czy warto�� aktualnie "przegl�danej" kom�rki jest taka sama jak wybrana warto��.
			{
				cout << "Ilosc pozycji od glowy: " << i << endl;	//	Wy�wietlenie, na kt�rej pozycji od g�owy "le�y" wybrana warto��.
				goto displayed;
			}
			tempNode = tempNode->nNext;					//	Przypisanie wska�nikowi tyczasowej kom�rki adresu elementu nast�pnego.
		}
		cout << "Wybranego elementu nie ma w liscie.\n";
	}
	else
	{
		shL.empty();									//	Wy�wietlenie komunikatu o braku zawarto�ci listy.
	}
	displayed:
	auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zako�czenia operacji.

	outcomeList.tMOutcome(o1, o2);						//	Wy�wietlenie czasu wykonania operacji.
	shL.done();											//	Wy�wietlenie komunikatu o zako�czeniu wykonywania operacji.
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
		generateElementsTest(iLTPuChoice);

		pushFrontTest();

		clearAllTTest();
	}
	cout << "------------------------------------------\n"
		"Dodawanie na koniec:\n";
	for (int i = 0; i < 100; i++)
	{
		generateElementsTest(iLTPuChoice);

		pushEndTest();

		clearAllTTest();
	}
	cout << "------------------------------------------\n"
		"Dodawanie w srodek:\n";
	for (int i = 0; i < 100; i++)
	{
		generateElementsTest(iLTPuChoice);

		pushMiddleTest(iLTPuChoice);

		clearAllTTest();
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
		generateElementsTest(iLTPoChoice);

		popFrontTest();

		clearAllTTest();
	}
	cout << "------------------------------------------\n"
		"Usuwanie z konca:\n";
	for (int i = 0; i < 100; i++)
	{
		generateElementsTest(iLTPoChoice);

		popEndTest();

		clearAllTTest();
	}
	cout << "------------------------------------------\n"
		"Usuwanie ze srodka:\n";
	for (int i = 0; i < 100; i++)
	{
		generateElementsTest(iLTPoChoice);

		popMiddleTest(iLTPoChoice);

		clearAllTTest();
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
		generateElementsTest(iLTDChoice);

		searchTest(iLTDChoice);

		clearAllTTest();
	}
	shL.done();
}

void Lista::generateElementsTest(int iLTest)
{	
	srand(time(0));

	int iLGeneratedHead = rand();						
	Node *tempNode = new Node(iLGeneratedHead);			
	nHead = tempNode;									

	for (int i = 0; i < iLTest - 2; i++)		
	{
		int iLGenerated = rand();						
		Node *newNode = new Node(iLGenerated);			
		tempNode->nNext = newNode;						
		newNode->nPrev = tempNode;						
		tempNode = newNode;								
	}
	int iLGeneratedTail = rand();						
	Node *newNode = new Node(iLGeneratedTail);			
	tempNode->nNext = newNode;							
	newNode->nPrev = tempNode;							
	nTail = newNode;
}

void Lista::clearAllTTest()
{
	Node *tempNode = nHead;
	while (nHead != NULL)
	{
		tempNode = nHead->nNext;
		delete nHead;
		nHead = tempNode;
	}
}

void Lista::pushFrontTest()
{
	int iLNewFrontElement = rand();						

	auto o1 = chrono::high_resolution_clock::now();		
	Node *newNode = new Node(iLNewFrontElement);		

	newNode->nNext = nHead;							
	nHead->nPrev = newNode;						
	nHead = newNode;								
	auto o2 = chrono::high_resolution_clock::now();		

	outcomeList.tMShort(o1, o2);
}

void Lista::pushEndTest()
{
	int iLNewEndElement = rand();						

	auto o1 = chrono::high_resolution_clock::now();		

	Node *newNode = new Node(iLNewEndElement);			
	
	newNode->nPrev = nTail;							
	nTail->nNext = newNode;							
	nTail = newNode;								
	
	auto o2 = chrono::high_resolution_clock::now();		

	outcomeList.tMShort(o1, o2);
}

void Lista::pushMiddleTest(int iLTPuTest)
{
	Node *tempNode = nHead;								
	int iLPushPosition = rand();
	int iLPushElement = rand();
	auto o1 = chrono::high_resolution_clock::now();		

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
	pushed:
	auto o2 = chrono::high_resolution_clock::now();		

	outcomeList.tMShort(o1, o2);
}

void Lista::popFrontTest()
{
	auto o1 = chrono::high_resolution_clock::now();		
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
	auto o2 = chrono::high_resolution_clock::now();		

	outcomeList.tMShort(o1, o2);
}

void Lista::popEndTest()
{
	auto o1 = chrono::high_resolution_clock::now();
	
	Node *tempNode = nTail->nPrev;
	delete nTail;
	nTail = tempNode;

	auto o2 = chrono::high_resolution_clock::now();
	
	outcomeList.tMShort(o1, o2);
}

void Lista::popMiddleTest(int iLTPoTest)
{
	Node *tempNode = nHead;						
	int iLPopChoice = rand();
	auto o1 = chrono::high_resolution_clock::now();		
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
poped:
	auto o2 = chrono::high_resolution_clock::now();		

	outcomeList.tMShort(o1, o2);
}

void Lista::searchTest(int iLTSearch)
{
	Node *tempNode = nHead;		
	int iLDisplayChoice = rand();		

	auto o1 = chrono::high_resolution_clock::now();		

	while (tempNode != NULL)						
	{									
		if (tempNode->iNData == iLDisplayChoice)	
		{
			goto displayed;
		}
		tempNode = tempNode->nNext;				
	}
displayed:
	auto o2 = chrono::high_resolution_clock::now();	

	outcomeList.tMShort(o1, o2);
}