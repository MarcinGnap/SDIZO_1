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
				"\t4.Powrot.\n";
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
	cout << "Wybierz, ktory element ma zostac usuniety:\n";
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
		cout << "Zawartosc listy (od glowy):\n";
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
	cout << "Wybierz, ktory element ma zostac wyswietlony:\n";
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