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
				"\t2.Menu odejmowania.\n"
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

void Lista::pushMenu()									//	Menu dodawania elementów do listy.
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
			pushFront();								//	Dodanie elementu na pocz¹tek listy.
			break;
		}
		case 2:
		{
			pushEnd();									//	Dodanie elementu na koniec listy.
			break;
		}
		case 3:
		{
			pushMiddle();								//	Dodanie elementu w okreœlone miejsce listy.
			break;
		}
		case 4:
		{
			readFromFileL();							//	Wczytanie elementów z pliku tekstowego.
			break;
		}
		case 5:
		{
			generateElements();							//	Wygenerowanie okreœlonej liczby elementów.
			break;
		}
		case 6:
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

void Lista::popMenu()									//	Menu usuwania elementów z listy.
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
			popFront();									//	Usuniêcie g³owy listy.
			break;
		}
		case 2:
		{
			popEnd();									//	Usuniêcie ogona listy.
			break;
		}
		case 3:
		{
			popMiddle();								//	Usuniêcie wskazanego elementu listy.
			break;
		}
		case 4:
		{
			clearAll();									//	Usuniêcie wszystkich elementów listy.
			break;
		}
		case 5:
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

void Lista::displayMenu()								//	Menu wyœwiatlania.
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
			displayAll();								//	Wyœwietlenie ca³ej zawartoœci listy.
			break;
		}
		case 2:
		{
			displayOne();								//	Wyœwietlenie okreœlonego elementu listy.
			break;
		}
		case 3:
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

void Lista::pushFront()									//	Dodanie elementu na pocz¹tek listy.
{
	int iLNewFrontElement;

	cout << "Podaj liczbe jaka ma byc dodana do listy:\n";
	cin >> iLNewFrontElement;							//	Wybranie wartoœci dodawanego elementu.

	auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpoczêcia operacji.
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
	auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakoñczenia operacji.
	
	outcomeList.tMOutcome(o1, o2);						//	Wyœwietlenie czasu wykonywania operacji.

	shL.done();											//	Wyœwietlenie komunikatu zakoñczenia wykonywania operacji.
}

void Lista::pushEnd()									//	Dodanie elementu na koniec listy.
{
	int iLNewEndElement;

	cout << "Podaj liczbe jaka ma byc dodana do listy:\n";
	cin >> iLNewEndElement;								//	Wybór wartoœci dodawanego elementu.

	auto o1 = chrono::high_resolution_clock::now();		//	Poimar czasu w momencie rozpoczêcia operacji.
	
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
	auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakoñczenia wykonywania operacji.

	outcomeList.tMOutcome(o1, o2);						//	Wyœwietlenie czasu wykonywania operacji.

	shL.done();											//	Wyœwietlenie komunikatu o zakoñczeniu wykonywania zadania.
}

void Lista::pushMiddle()								//	Dodanie elementu w okreœlone miejsce w liœcie.
{
	Node *tempNode = nHead;								//	Stworzenie tyczasowego wskaŸnika przechowuj¹cego adres g³owy.
	int iLPushPosition, iLPushElement;
	cout << "Wybierz, po ktorym elemencie ma zostac wstawiony twoj element:\n";
	cin >> iLPushPosition;								//	Wybranie po jakim elemencie ma zostaæ wstawiony nowy element.
	cout << "Wybierz wartosc wstawianego elementu:\n";
	cin >> iLPushElement;								//	Wybranie wartoœci wstawianego elementu.
	cout << "Wybrany element zostanie wstawiony po elemencie: " << iLPushPosition << " i bedzie mial wartosc: " << iLPushElement << ".\n";

	auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpoczêcia wykonywania operacji,

	if (nHead != NULL)									//	Sprawdzenie czy lista jest pusta.
	{
		while (tempNode->nNext != NULL)					//	Pêtla wykonuj¹ca siê od pocz¹tkowego elementu listy do ostatniego.
		{
			if (tempNode->iNData == iLPushPosition)		//	Sprawdzenie czy wartoœæ elementu zgadza siê z elementem, po którym u¿ytkownik chce wstawiæ nowy element.
			{
				Node *newNode = new Node(iLPushElement);//	Stworzenie nowego elementu.
				if (tempNode == nTail)					//	Sprawdzenie czy znaleŸiony element jest ogonem.
				{
					newNode->nPrev = nTail;				//	WskaŸnik nowej komórki na poprzedni element zostaje przypisany do porzedniego ogona.
					nTail->nNext = newNode;				//	WskaŸnik poprzedniego ogona na nastêpny element zostaje przypisany do nowej komórki.
					nTail = newNode;					//	Przypisanie nowego elementu jako ogona.
				}
				else
				{
					tempNode->nNext->nPrev = newNode;	//	WskaŸnik nastêpnego elementu po znaleŸionej komórce na poprzedni element zostaje przypisany do nowej komórki.
					newNode->nNext = tempNode->nNext;	//	WskaŸnik nowej komórki na nastêpny element zostaje przypisany do nastêpnej komórki po znaleŸionej.
					newNode->nPrev = tempNode;			//	WskaŸnik nowej komórki na porzedni element zostaje przypisany do znaleŸionej komórki.
					tempNode->nNext = newNode;			//	WskaŸnik znaleŸionej komórki na nastêpny element zostaje przypisany do nowej komórki.
				}
				goto pushed;							//	Etykieta, dziêki Której program wychodzi z pêtli po znaleŸieniu odpowiedniej wartoœæi.
			}
			tempNode = tempNode->nNext;					//	Przypisanie tymczasowego elementu do nastêpnego.
		}
	}
	else
	{
		shL.empty();									//	Wyœwietlenie komunikatu o braku zawartoœci struktury.
	}
pushed:													//	Etykieta.
	auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakoñczenia operacji.

	outcomeList.tMOutcome(o1, o2);						//	Wyœwietlenie czasu wykonywania operacji.
	shL.done();											//	Wyœwietlenie komunikatu o zakoñczeniu wykonywania operacji.
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

		shL.done();										//	Wyœwietlenie komuniaktu o wykonaniu operacji.
	}
	else
	{
		shL.noFile();									//	Wyœwietlenie komunikatu o problemie z plikiem.
	}
}

void Lista::generateElements()							//	Wygenerowanie okreœlonej liczby elemetów do listy.
{
	int iLNumberOfGen;
	cout << "Ile elementow ma zostac wygenerowanych?\n";
	cin >> iLNumberOfGen;								//	Wybór iloœci wylosowanych elementów.

	auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpoczêcia operacji.

	srand(time(0));

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

	auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakoñczenia wykonywania operacji.

	outcomeList.tMOutcome(o1, o2);						//	Wyœwietlenie czasu wykonywania operacji.

	shL.done();											//	Wyœwietlenie komuniaktu o zakoñczeniu wykonywania operacji.
}

void Lista::popFront()									//	Usuniêcie elementu z pocz¹tki listy.
{
	auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpoczêcia operacji.
	if (nHead != NULL)									//	Sprawdzenie czy lista jest pusta.
	{
		if (nHead->nNext != NULL)						//	Sprawdzenie czy lista jest jedno elementowa.
		{
			Node *tempNode = nHead->nNext;				//	Stworzenie nowego wskaŸnika na nastêpny element po g³owie.
			delete nHead;								//	Usuniêcie g³owy.
			nHead = tempNode;							//	Przypisanie nastêpnego eleentu jako g³owy.
		}
		else
		{
			delete nHead;								//	Usuniêcie g³owy.
		}
	}
	else
	{
		shL.empty();									//	Wyœwietlenie kounikatu o braku zawartoœci listy.
	}
	auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakoñczenia operacji.

	outcomeList.tMOutcome(o1, o2);						//	Wyœwietlenie czasu wykonywania operacji.

	shL.done();											//	Wyœwietlenie komunikatu o zakoñczeniu wykonywania operacji.
}

void Lista::popEnd()									//	Usuniêcie elementu z koñca listy.
{
	auto o1 = chrono::high_resolution_clock::now();		//	Poiar czasu w momencie rozpoczêcia operacji.
	if (nHead != NULL)									//	Sprawdzenie czy lista ma zawartoœæ.
	{
		if (nTail->nPrev != NULL)						//	Sprawdzenie czy lista nie jest jednoelementowa.
		{
			Node *tempNode = nTail->nPrev;				//	Stworzenie nowego tyczasowego wskaŸnika i przypisanie do niego element poprzedni od ogona.
			delete nTail;								//	Usuniêcie ogona.
			nTail = tempNode;							//	Przypisanie nowego ogona do tymczasowego elementu.
		}
		else
		{
			delete nTail;								//	Uusniêcie ogona.
		}
	}
	else
	{
		shL.empty();									//	Wyœwietlenie kounikatu o braku zawartoœci listy.
	}
	auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakoñczenia operacji.

	outcomeList.tMOutcome(o1, o2);						//	Wyœwietlenie czasu wykonywania operacji.

	shL.done();											//	Wyœwietlenie komunikatu i zakoñczeniu wykonywania operacji.
}

void Lista::popMiddle()									//	Usuniêcie wskazanego elementu.
{
	Node *tempNode = nHead;								//	Stworzenie nowego wskaŸnika i przypisanie do niego g³owy.
	int iLPopChoice;
	cout << "Wybierz, ktory element ma zostac usuniety:\n";
	cin >> iLPopChoice;									//	Wybranie usuwanej wartoœci.
	cout << "Wybrany element: " << iLPopChoice << endl;	//	Wyœwietlenie wybranej wartoœci.

	auto o1 = chrono::high_resolution_clock::now();		//	Poiar czasu w momencie rozpoczêcia operacji.

	if (nHead != NULL)									//	Sprawdzenie czy lista nie jest pusta.
	{
		while (tempNode->nNext != NULL)					//	Pêtla wykonuj¹ca siê od pierwszego do ostatniego elementu listy.
		{
			if (tempNode->iNData == iLPopChoice)		//	Sprawdzenie czy wartoœæ przechowywana przez komórkê jest identyczna jak wartoœæ wybrana.
			{
				tempNode->nNext->nPrev = tempNode->nPrev;	//	WskaŸnik komórki nastêpnej po elemencie tymczasowym na element nastêpny zostaje przypisany do wskaŸnika komórki tymczasowej na komórkê poprzedni¹ od nastêpnej.
				tempNode->nPrev->nNext = tempNode->nNext;	//	WskaŸnik komórki poprzedniej od elementu usuwanego na komórkê nastêpn¹ zostaje przypisany do wskaŸnika usuwanej komórki na element nastêpny.
				delete tempNode;						//	Usuniêcie elementu.
				goto poped;								//	Etykieta przerywaj¹ca pêtlê w momencie usuniêcia wartoœci.
			}
			tempNode = tempNode->nNext;					//	Zmienienie wskaŸnika komórki tymczasowej na element nastêpny.
		}
	}
	else
	{
		shL.empty();									//	Wyœwietlenie komunikatu o braku zawartoœci listy.
	}
	poped:
	auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakoñczenia operacji.

	outcomeList.tMOutcome(o1, o2);						//	Wyœwietlenie czasu wykonywania operacji.
	shL.done();											//	Wyœwietlenie komunikatu o zakoñczeniu wykonywania operacji.
}

void Lista::clearAll()									//	Usuniêcie wszystkich elementów listy.
{
	auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpoczêcia operacji.

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
	auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakoñczenia operacji.

	outcomeList.tMOutcome(o1, o2);						//	Wyœwietlenie czasu wykonywania operacji.
	shL.done();											//	Wyœwietlenie komunikatu o zakoñczeniu wykonywania operacji.
}

void Lista::displayAll()								//	Wyœwietlenie ca³ej zawartoœci listy.
{
	auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpoczêcia operacji.

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
	auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakoñczenia operacji.

	outcomeList.tMOutcome(o1, o2);						//	Wyœwietlenie czasu wykonywanie operacji.
	shL.done();											//	Wyœwietlenie komunikatu o zakoñczeniu wykonywania operacji.
}

void Lista::displayOne()								//	Wyœwitlenie wybranego elementu listy.
{
	Node *tempNode = nHead;								//	Stworzenie nowego wskaŸnika i przypisanie do niego g³owy.
	int iLDisplayChoice;
	int i = 0;
	cout << "Wybierz, ktory element ma zostac wyswietlony:\n";
	cin >> iLDisplayChoice;								//	Wybór wartoœci, która ma zostaæ wyœwietlona.

	auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpoczêcia operacji.
	
	if (nHead != NULL)									//	Sprawdzenie czy lista ma zawartoœæ.
	{
		cout << "Wybrany element: " << iLDisplayChoice << endl;		//	Wyœwietlenie wybranej wartoœci.
		while (tempNode != NULL)						//	Pêtla wykonuj¹ca siê od pocz¹tkowego do ostatniego elementu listy.
		{
			i++;										//	Iteracja ziennej odpowiadaj¹cej za numer pozycji od g³owy.
			if (tempNode->iNData == iLDisplayChoice)	//	Sprawdzenie czy wartoœæ aktualnie "przegl¹danej" komórki jest taka sama jak wybrana wartoœæ.
			{
				cout << "Ilosc pozycji od glowy: " << i << endl;	//	Wyœwietlenie, na której pozycji od g³owy "le¿y" wybrana wartoœæ.
				goto displayed;
			}
			tempNode = tempNode->nNext;					//	Przypisanie wskaŸnikowi tyczasowej komórki adresu elementu nastêpnego.
		}
		cout << "Wybranego elementu nie ma w liscie.\n";
	}
	else
	{
		shL.empty();									//	Wyœwietlenie komunikatu o braku zawartoœci listy.
	}
	displayed:
	auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakoñczenia operacji.

	outcomeList.tMOutcome(o1, o2);						//	Wyœwietlenie czasu wykonania operacji.
	shL.done();											//	Wyœwietlenie komunikatu o zakoñczeniu wykonywania operacji.
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