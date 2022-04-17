#include "Heap.h"

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <time.h>
#include <chrono>
#include <ratio>

using namespace std;

Heap::Heap() 
{
	iHSize = 0;
	newHeap = new int[iHSize];
}

Heap::~Heap()
{

}

void Heap::heapMenu()									//	Menu g��wne kopca.
{
	short sHChoiceHeapMenu;

	for (;;)
	{
		shH.cls();										//	"Wyczyszczenie" ekranu u�ytkowanika.

		cout << "Prosze wybrac:\n"
				"\t1.Menu dodawania.\n"
				"\t2.Menu odejmowania.\n"
				"\t3.Menu wyswietlania.\n"
				"\t4.Powrot.\n";
		cin >> sHChoiceHeapMenu;						//	Wyb�r opcji.

		switch (sHChoiceHeapMenu)
		{
		case 1:
		{
			pushMenu();									//	Menu dodawania.
			break;
		}
		case 2:
		{
			popMenu();									//	Menu usuwania z kopca.
			break;
		}
		case 3:
		{
			displayMenu();								//	Menu wy�wietlania element�w.
			break;
		}
		case 4:
		{
			return;
			break;
		}
		default:
		{
			shH.noOption();								//	Wy�wietlenie komunikatu o wybraniu nieistniej�cej opcji.
			break;
		}
		}
	}
}

void Heap::pushMenu()									//	Menu dodawania.
{
	for (;;)
	{
		shH.cls();										//	"Wyczyszczenie" ekranu u�ytkownika.

		short sHChoicePushMenu;

		cout << "Prosze wybrac:\n"
				"\t1.Dodanie elementu.\n"
				"\t2.Wczytanie danych z pliku tekstowego.\n"
				"\t3.Wygenerowanie okreslonej ilosci elementow.\n"
				"\t4.Powrot.\n";
		cin >> sHChoicePushMenu;						//	Wybranie opcji.

		switch (sHChoicePushMenu)
		{
		case 1:
		{
			pushElement();								//	Dodanie elementu.
			break;
		}
		case 2:
		{
			readFromFileH();							//	Odczytanie i przypisanie warto�ci z pliku tekstowego.
			break;
		}
		case 3:
		{
			generateElements();							//	Wygenerowanie okre�lonej ilo�ci element�w.
			break;
		}
		case 4:
		{
			return;
			break;
		}
		default:
		{
			shH.noOption();								//	Wy�wietlenie komunikatu o wybraniu nieistniej�cej opcji.
			break;
		}
		}
	}
}

void Heap::popMenu()									//	Menu usuwania z kopca.
{
	short sHChoicePopMenu;

	for (;;)
	{
		shH.cls();										//	"Wyczyszczenie" ekranu u�ytkownika.

		cout << "Prosze wybrac:\n"
				"\t1.Usuniecie elementu ze strultury.\n"
				"\t2.Usuniecie wszystkich elementow ze struktury.\n"
				"\t3.Powrot.\n";
		cin >> sHChoicePopMenu;							//	Wyb�r opcji.

		switch (sHChoicePopMenu)
		{
		case 1:
		{
			popElement();								//	Usuni�cie pojedy�czego elementu.
			break;
		}
		case 2:
		{
			clearAll();									//	Usuni�cie za�ej zawarto�ci kopca.
			break;
		}
		case 3:
		{
			return;
			break;
		}
		default:
		{
			shH.noOption();								//	Wy�wietlenie komunikatu o wybraniu nieistniej�cej opcji.
			break;
		}
		}
	}
}

void Heap::displayMenu()								//	Menu wy�wietlania.
{
	short sHChoiceDisplayMenu;

	for (;;)
	{
		shH.cls();										//	"Wyczyszczenie" ekranu u�ytkownika.

		cout << "Prosze wybrac:\n"
				"\t1.Wyswietlenie calej zawartosci struktury.\n"
				"\t2.Wyswietlenie okreslonego elementu struktury.\n"
				"\t3.Powrot.\n";
		cin >> sHChoiceDisplayMenu;						//	Wyb�r opcji.

		switch (sHChoiceDisplayMenu)
		{
		case 1:
		{
			displayAll();								//	Wy�wietlenie wszystkich element�w kopca.
			break;
		}
		case 2:
		{
			displayOne();								//	Wy�wietlenie okre�lonego elementu.
			break;
		}
		case 3:
		{
			return;
			break;
		}
		default:
		{
			shH.noOption();								//	Wy�wietlenie komunikatu o wybraniu nieistniej�cej opcji.
			break;
		}
		}
	}
}

void Heap::pushElement()								//	Dodanie elementu do kopca.
{
	int iHNewEndElement;

	cout << "Podaj liczbe jaka ma byc dodana do kopca:\n";
	cin >> iHNewEndElement;								//	Wyb�r warto�ci jaka ma zosta� dodana do kopca.

	auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpocz�cia operacji.

	auto tempHeap = new int[iHSize + 1];				//	Stworzenie tyczasowego kopca z powi�kszon� ilo�ci� element�w.

	tempHeap[iHSize] = iHNewEndElement;					//	Przypisanie wybranej warto�ci do kom�rki z najwi�kszym indeksem.
	if (iHSize != 0)									//	Sprawdzenie czy kopiec ma zawarto��.
	{
		for (int i = 0; i < iHSize; i++)				//	P�tla wykonuj�ca si� od pierwszego do przedostatniego elementu.
		{
			tempHeap[i] = newHeap[i];					//	Przypisanie warto�ci z poprzedniego kopca z okre�lonej pozycji do tymczasowego kopca.
		}
	}
	delete[] newHeap;									//	Usuni�cie zawarto�ci poprzedniego kopca.
	newHeap = tempHeap;									//	Skopiowanie zawarto�ci tymczasowego kopca do kopca u�ywanego w programie.
	tempHeap = nullptr;									//	Usuni�cie zawarto�ci tymczasowego kopca.
	iHSize++;											//	Iteracja zmiennej przechowuj�cej rozmiar kopca.
	
	HeapifyUp();										//	Sortowanie kopca w g�r� zaczynaj�c od dodanego elementu.

	auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zako�czenia operacji.

	outcomeHeap.tMOutcome(o1, o2);						//	Wy�wietlenie czasu wykonania operacji.

	shH.done();											//	Wy�wietlenie komunikatu o zako�czeniu wykonywania operacji.
}

void Heap::readFromFileH()								//	Odczytanie i skopiowanie warto�ci z pliku tekstowego do kopca.
{
	ifstream ifHFile("dane.txt", ios::in);
	if (ifHFile.good())
	{
		shH.opened();

		auto o1 = chrono::high_resolution_clock::now();
		string sHLineCountBuffer;
		getline(ifHFile, sHLineCountBuffer);
		int iHLineCount = stoi(sHLineCountBuffer);
		cout << "Ilosc elementow przekazanych do struktury: " << iHLineCount << endl;

		auto tempHeap = new int[iHLineCount];

		for (int i = 0; i < iHLineCount; i++)
		{
			string sHLineValueBuffer;
			getline(ifHFile, sHLineValueBuffer);

			int iHLineValue = stoi(sHLineValueBuffer);

			tempHeap[i] = iHLineValue;
			
			HeapifyUp();
		}
		delete[] newHeap;
		newHeap = tempHeap;
		tempHeap = nullptr;
		iHSize = iHLineCount;

		ifHFile.close();

		auto o2 = chrono::high_resolution_clock::now();

		outcomeHeap.tMOutcome(o1, o2);

		shH.done();
	}
	else
	{
		shH.noFile();
	}
}

void Heap::generateElements()
{
	int iHNumberOfGen;
	cout << "Ile elementow ma zostac wygenerowanych?\n";
	cin >> iHNumberOfGen;

	auto o1 = chrono::high_resolution_clock::now();

	srand(time(0));

	delete[] newHeap;
	newHeap = new int[iHNumberOfGen];
	
	for (int i = 0; i < iHNumberOfGen; i++)
	{
		newHeap[i] = rand();
		iHSize++;
		HeapifyUp();
	}

	auto o2 = chrono::high_resolution_clock::now();

	outcomeHeap.tMOutcome(o1, o2);

	shH.done();
}

void Heap::popElement()									//	Usuni�cie elementu z kopca.
{
	if (iHSize != 0)									//	Sprawdzenie czy kopiec ma zawarto��.
	{
		auto o1 = chrono::high_resolution_clock::now();	//	Pomiar czasu w momencie ropzocz�cia operacji.
		auto tempHeap = new int[iHSize - 1];			//	Stworzenie nowego kopca z pomniejszon� ilo�ci� element�w.

		tempHeap[0] = newHeap[iHSize - 1];				//	Przypisanie warto�� ostatniego elementu do pierwszego miejsca.
		for (int i = 1; i < iHSize - 1; i++)			//	P�tla wykonuj�ca si� od drugiego do przedostatniego elementu.
		{
			tempHeap[i] = newHeap[i];					//	Przypisanie warto�ci poprzedniego kopca do nowego kopca.
		}
		delete[] newHeap;								//	Usuni�cie zawarto�ci poprzedniego kopca.
		newHeap = tempHeap;								//	Przypisanie zawarto�ci tyczasowego kopca do kopca u�ywanego w programie.
		tempHeap = nullptr;								//	Usuni�cie zawarto�ci tymczasowego kopca.
		iHSize--;										//	Dekrementacja zimennej przechowuj�cej rozmiar kopca.

		HeapifyDown();									//	Posortowanie element�w w d�.

		auto o2 = chrono::high_resolution_clock::now();	//	Pomiar czasu w momencie zako�czenia operacji.

		outcomeHeap.tMOutcome(o1, o2);					//	Wy�wietlenie czasu wykonywania operacji.
	}
	else
	{
		shH.empty();									//	Wy�wietlenie komunikatu o braku zawarto�ci kopca.
	}
	shH.done();											//	Wy�wietlenie komunikatu o zako�czeniu wykonywania operacji.
}

void Heap::clearAll()									//	Usuni�cie wszystkich element�w kopca.
{
	if (iHSize != 0)									//	Sprawdzenie czy kopiec ma zawarto��.
	{
		auto o1 = chrono::high_resolution_clock::now();	//	Pomiar czasu w momencie rozpocz�cia operacji.
		delete[] newHeap;								//	Usuni�cie zawarto�ci kopca.
		iHSize = 0;										//	Wyzerowanie zmiennej przechowuj�cej rozmiar kopca.
		auto o2 = chrono::high_resolution_clock::now();	//	Pomiar czasu w momencie zako�czenia operacji.

		outcomeHeap.tMOutcome(o1, o2);					//	Wy�wietlenie czasu wykonywania operacji.
	}
	else
	{
		shH.empty();									//	Wy�wietlenie komunikatu o braku zawarto�ci kopca.
	}

	shH.done();											//	Wy�wietlenie komunikatu o zako�czeniu wykonywania operacji.
}

void Heap::displayAll()									//	Wy�wietlenie wszystkich element�w kopca.
{
	if (iHSize != 0)									//	Sprawdzenie czy kopiec ma zawarto��.
	{
		auto o1 = chrono::high_resolution_clock::now();	//	Pomiar czasu w momencie rozpocz�cia operacji.
		for (int i = 0; i < iHSize; i++)				//	P�tla wykonuj�ca si� od pierwszego do ostatniego elementu kopca.
		{
			cout << "Element nr " << i + 1 << " = " << newHeap[i] << endl;	//	Wy�wietlenie elementu.
		}
		auto o2 = chrono::high_resolution_clock::now();	//	Pomiar czasu w momencie zako�czenia operacji.

		outcomeHeap.tMOutcome(o1, o2);					//	Wy�wietlenie czasu wykonywania operacji.
	}
	else
	{
		shH.empty();									//	Wy�wietlenie komunikatu o braku zawarto�ci kopca.
	}
	shH.done();											//	Wy�wietlenie komunikatu o zako�czeniu wykonywania operacji.
}

void Heap::displayOne()									//	Wy�wietlenie wybranego elementu.
{
	if (iHSize != 0)									//	Sprawdzenie czy kopiec ma zawarto��.
	{
		int iHChoiceDisplay;							

		cout << "Wybierz element, ktory chcesz wyswietlic:\n";
		cin >> iHChoiceDisplay;							//	Wyb�r wy�wietlanego elementu.

		auto o1 = chrono::high_resolution_clock::now();	//	Pomiar czasu w momencie rozpocz�cia operacji.

		for (int i = 0; i<iHSize; i++)					//	P�tla wykonuj�ca si� od pierwszego do ostatniego elementu.
		{
			if (iHChoiceDisplay == newHeap[i])			//	Sprawdzenie czy warto�� elementu pokrywa si� z wybran� warto�ci�.
			{
				cout << "Wybrany element " << iHChoiceDisplay << " znajduje sie w strukturze.\n";	//	Wy�wietlenie wybranego elementu.
				goto displayed;							//	Etykieta umo�liwiaj�ca wyj�cie z p�tli po znalezieniu poszukiwanego elementu.
			}
		}
		cout << "Wybranego elementu nie ma w strukturze.\n";	//	Wy�wietlenie inforamcji, �e podanego elementu nie ma w strukturze.
		displayed:
		auto o2 = chrono::high_resolution_clock::now();	//	Pomiar czasu w momencie zako�czenia operacji.

		outcomeHeap.tMOutcome(o1, o2);					//	Wy�wietlenie czasu wykonywania operacji.
	}
	else
	{
		shH.empty();									//	Wy�wietlenie komunikatu o braku zawarto�ci kopca.
	}
	shH.done();											//	Wy�wietlenie komunikatu o zako�czeniu wykonywania operacji.
}

void Heap::HeapifyDown()								//	Posortowanie kopca w d�.
{
	int x = 0;
	while (x < iHSize && (newHeap[x] < newHeap[getLeft(x)] || newHeap[x] < newHeap[getRight(x)]))
	{
		int tempParent = newHeap[x];
		if (newHeap[getLeft(x)] >= newHeap[getRight(x)])
		{
			newHeap[x] = newHeap[getLeft(x)];
			newHeap[getLeft(x)] = tempParent;
			x = getLeft(x);
		}
		else if (newHeap[getLeft(x)] < newHeap[getRight(x)])
		{
			newHeap[x] = newHeap[getRight(x)];
			newHeap[getRight(x)] = tempParent;
			x = getRight(x);
		}
	}
}

void Heap::HeapifyUp()									//	Posortowanie w g�r� kopca zaczynaj�c od elementu ostatnio dodanego.
{
	if (iHSize > 0)										//	Sprawdzenie czy kopiec ma zawarto��.
	{
		int x = iHSize - 1;								//	Zmienna zawieraj�ca indeks por�wnywanywanego elementu kopca.
		while (x != 0 && newHeap[getParent(x)] < newHeap[x])	//	P�tla wykonuj�ca si� od ostatniego elementu dop�ki rodzic b�dzie wi�kszy od por�wnywanego potomka.
		{
			int tempValue = newHeap[getParent(x)];		//	Tyczasowa zienna przechowuj�ca rodzica zamienianego elementu.
			newHeap[getParent(x)] = newHeap[x];			//	Zamiana rodzica elementu z kom�rk�.
			newHeap[x] = tempValue;						//	Zamiana elementu z rodzicem.
			x = getParent(x);
		}
	}
}

int Heap::getLeft(int x)								//	Zwr�cenie indeksu lewego potomka.
{
	return (x * 2 + 1);
}

int Heap::getRight(int x)								//	Zwr�cenie indeksu prawego potomka.
{
	return (x * 2 + 2);
}

int Heap::getParent(int x)								//	Zwr�cenie indeksu rodzica.
{
	return floor((x - 1) / 2);
}