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

void Heap::heapMenu()									//	Menu g³ówne kopca.
{
	short sHChoiceHeapMenu;

	for (;;)
	{
		shH.cls();										//	"Wyczyszczenie" ekranu u¿ytkowanika.

		cout << "Prosze wybrac:\n"
				"\t1.Menu dodawania.\n"
				"\t2.Menu odejmowania.\n"
				"\t3.Menu wyswietlania.\n"
				"\t4.Powrot.\n";
		cin >> sHChoiceHeapMenu;						//	Wybór opcji.

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
			displayMenu();								//	Menu wyœwietlania elementów.
			break;
		}
		case 4:
		{
			return;
			break;
		}
		default:
		{
			shH.noOption();								//	Wyœwietlenie komunikatu o wybraniu nieistniej¹cej opcji.
			break;
		}
		}
	}
}

void Heap::pushMenu()									//	Menu dodawania.
{
	for (;;)
	{
		shH.cls();										//	"Wyczyszczenie" ekranu u¿ytkownika.

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
			readFromFileH();							//	Odczytanie i przypisanie wartoœci z pliku tekstowego.
			break;
		}
		case 3:
		{
			generateElements();							//	Wygenerowanie okreœlonej iloœci elementów.
			break;
		}
		case 4:
		{
			return;
			break;
		}
		default:
		{
			shH.noOption();								//	Wyœwietlenie komunikatu o wybraniu nieistniej¹cej opcji.
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
		shH.cls();										//	"Wyczyszczenie" ekranu u¿ytkownika.

		cout << "Prosze wybrac:\n"
				"\t1.Usuniecie elementu ze strultury.\n"
				"\t2.Usuniecie wszystkich elementow ze struktury.\n"
				"\t3.Powrot.\n";
		cin >> sHChoicePopMenu;							//	Wybór opcji.

		switch (sHChoicePopMenu)
		{
		case 1:
		{
			popElement();								//	Usuniêcie pojedyñczego elementu.
			break;
		}
		case 2:
		{
			clearAll();									//	Usuniêcie za³ej zawartoœci kopca.
			break;
		}
		case 3:
		{
			return;
			break;
		}
		default:
		{
			shH.noOption();								//	Wyœwietlenie komunikatu o wybraniu nieistniej¹cej opcji.
			break;
		}
		}
	}
}

void Heap::displayMenu()								//	Menu wyœwietlania.
{
	short sHChoiceDisplayMenu;

	for (;;)
	{
		shH.cls();										//	"Wyczyszczenie" ekranu u¿ytkownika.

		cout << "Prosze wybrac:\n"
				"\t1.Wyswietlenie calej zawartosci struktury.\n"
				"\t2.Wyswietlenie okreslonego elementu struktury.\n"
				"\t3.Powrot.\n";
		cin >> sHChoiceDisplayMenu;						//	Wybór opcji.

		switch (sHChoiceDisplayMenu)
		{
		case 1:
		{
			displayAll();								//	Wyœwietlenie wszystkich elementów kopca.
			break;
		}
		case 2:
		{
			displayOne();								//	Wyœwietlenie okreœlonego elementu.
			break;
		}
		case 3:
		{
			return;
			break;
		}
		default:
		{
			shH.noOption();								//	Wyœwietlenie komunikatu o wybraniu nieistniej¹cej opcji.
			break;
		}
		}
	}
}

void Heap::pushElement()								//	Dodanie elementu do kopca.
{
	int iHNewEndElement;

	cout << "Podaj liczbe jaka ma byc dodana do kopca:\n";
	cin >> iHNewEndElement;								//	Wybór wartoœci jaka ma zostaæ dodana do kopca.

	auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpoczêcia operacji.

	auto tempHeap = new int[iHSize + 1];				//	Stworzenie tyczasowego kopca z powiêkszon¹ iloœci¹ elementów.

	tempHeap[iHSize] = iHNewEndElement;					//	Przypisanie wybranej wartoœci do komórki z najwiêkszym indeksem.
	if (iHSize != 0)									//	Sprawdzenie czy kopiec ma zawartoœæ.
	{
		for (int i = 0; i < iHSize; i++)				//	Pêtla wykonuj¹ca siê od pierwszego do przedostatniego elementu.
		{
			tempHeap[i] = newHeap[i];					//	Przypisanie wartoœci z poprzedniego kopca z okreœlonej pozycji do tymczasowego kopca.
		}
	}
	delete[] newHeap;									//	Usuniêcie zawartoœci poprzedniego kopca.
	newHeap = tempHeap;									//	Skopiowanie zawartoœci tymczasowego kopca do kopca u¿ywanego w programie.
	tempHeap = nullptr;									//	Usuniêcie zawartoœci tymczasowego kopca.
	iHSize++;											//	Iteracja zmiennej przechowuj¹cej rozmiar kopca.
	
	HeapifyUp();										//	Sortowanie kopca w górê zaczynaj¹c od dodanego elementu.

	auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakoñczenia operacji.

	outcomeHeap.tMOutcome(o1, o2);						//	Wyœwietlenie czasu wykonania operacji.

	shH.done();											//	Wyœwietlenie komunikatu o zakoñczeniu wykonywania operacji.
}

void Heap::readFromFileH()								//	Odczytanie i skopiowanie wartoœci z pliku tekstowego do kopca.
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

void Heap::popElement()									//	Usuniêcie elementu z kopca.
{
	if (iHSize != 0)									//	Sprawdzenie czy kopiec ma zawartoœæ.
	{
		auto o1 = chrono::high_resolution_clock::now();	//	Pomiar czasu w momencie ropzoczêcia operacji.
		auto tempHeap = new int[iHSize - 1];			//	Stworzenie nowego kopca z pomniejszon¹ iloœci¹ elementów.

		tempHeap[0] = newHeap[iHSize - 1];				//	Przypisanie wartoœæ ostatniego elementu do pierwszego miejsca.
		for (int i = 1; i < iHSize - 1; i++)			//	Pêtla wykonuj¹ca siê od drugiego do przedostatniego elementu.
		{
			tempHeap[i] = newHeap[i];					//	Przypisanie wartoœci poprzedniego kopca do nowego kopca.
		}
		delete[] newHeap;								//	Usuniêcie zawartoœci poprzedniego kopca.
		newHeap = tempHeap;								//	Przypisanie zawartoœci tyczasowego kopca do kopca u¿ywanego w programie.
		tempHeap = nullptr;								//	Usuniêcie zawartoœci tymczasowego kopca.
		iHSize--;										//	Dekrementacja zimennej przechowuj¹cej rozmiar kopca.

		HeapifyDown();									//	Posortowanie elementów w dó³.

		auto o2 = chrono::high_resolution_clock::now();	//	Pomiar czasu w momencie zakoñczenia operacji.

		outcomeHeap.tMOutcome(o1, o2);					//	Wyœwietlenie czasu wykonywania operacji.
	}
	else
	{
		shH.empty();									//	Wyœwietlenie komunikatu o braku zawartoœci kopca.
	}
	shH.done();											//	Wyœwietlenie komunikatu o zakoñczeniu wykonywania operacji.
}

void Heap::clearAll()									//	Usuniêcie wszystkich elementów kopca.
{
	if (iHSize != 0)									//	Sprawdzenie czy kopiec ma zawartoœæ.
	{
		auto o1 = chrono::high_resolution_clock::now();	//	Pomiar czasu w momencie rozpoczêcia operacji.
		delete[] newHeap;								//	Usuniêcie zawartoœci kopca.
		iHSize = 0;										//	Wyzerowanie zmiennej przechowuj¹cej rozmiar kopca.
		auto o2 = chrono::high_resolution_clock::now();	//	Pomiar czasu w momencie zakoñczenia operacji.

		outcomeHeap.tMOutcome(o1, o2);					//	Wyœwietlenie czasu wykonywania operacji.
	}
	else
	{
		shH.empty();									//	Wyœwietlenie komunikatu o braku zawartoœci kopca.
	}

	shH.done();											//	Wyœwietlenie komunikatu o zakoñczeniu wykonywania operacji.
}

void Heap::displayAll()									//	Wyœwietlenie wszystkich elementów kopca.
{
	if (iHSize != 0)									//	Sprawdzenie czy kopiec ma zawartoœæ.
	{
		auto o1 = chrono::high_resolution_clock::now();	//	Pomiar czasu w momencie rozpoczêcia operacji.
		for (int i = 0; i < iHSize; i++)				//	Pêtla wykonuj¹ca siê od pierwszego do ostatniego elementu kopca.
		{
			cout << "Element nr " << i + 1 << " = " << newHeap[i] << endl;	//	Wyœwietlenie elementu.
		}
		auto o2 = chrono::high_resolution_clock::now();	//	Pomiar czasu w momencie zakoñczenia operacji.

		outcomeHeap.tMOutcome(o1, o2);					//	Wyœwietlenie czasu wykonywania operacji.
	}
	else
	{
		shH.empty();									//	Wyœwietlenie komunikatu o braku zawartoœci kopca.
	}
	shH.done();											//	Wyœwietlenie komunikatu o zakoñczeniu wykonywania operacji.
}

void Heap::displayOne()									//	Wyœwietlenie wybranego elementu.
{
	if (iHSize != 0)									//	Sprawdzenie czy kopiec ma zawartoœæ.
	{
		int iHChoiceDisplay;							

		cout << "Wybierz element, ktory chcesz wyswietlic:\n";
		cin >> iHChoiceDisplay;							//	Wybór wyœwietlanego elementu.

		auto o1 = chrono::high_resolution_clock::now();	//	Pomiar czasu w momencie rozpoczêcia operacji.

		for (int i = 0; i<iHSize; i++)					//	Pêtla wykonuj¹ca siê od pierwszego do ostatniego elementu.
		{
			if (iHChoiceDisplay == newHeap[i])			//	Sprawdzenie czy wartoœæ elementu pokrywa siê z wybran¹ wartoœci¹.
			{
				cout << "Wybrany element " << iHChoiceDisplay << " znajduje sie w strukturze.\n";	//	Wyœwietlenie wybranego elementu.
				goto displayed;							//	Etykieta umo¿liwiaj¹ca wyjœcie z pêtli po znalezieniu poszukiwanego elementu.
			}
		}
		cout << "Wybranego elementu nie ma w strukturze.\n";	//	Wyœwietlenie inforamcji, ¿e podanego elementu nie ma w strukturze.
		displayed:
		auto o2 = chrono::high_resolution_clock::now();	//	Pomiar czasu w momencie zakoñczenia operacji.

		outcomeHeap.tMOutcome(o1, o2);					//	Wyœwietlenie czasu wykonywania operacji.
	}
	else
	{
		shH.empty();									//	Wyœwietlenie komunikatu o braku zawartoœci kopca.
	}
	shH.done();											//	Wyœwietlenie komunikatu o zakoñczeniu wykonywania operacji.
}

void Heap::HeapifyDown()								//	Posortowanie kopca w dó³.
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

void Heap::HeapifyUp()									//	Posortowanie w górê kopca zaczynaj¹c od elementu ostatnio dodanego.
{
	if (iHSize > 0)										//	Sprawdzenie czy kopiec ma zawartoœæ.
	{
		int x = iHSize - 1;								//	Zmienna zawieraj¹ca indeks porównywanywanego elementu kopca.
		while (x != 0 && newHeap[getParent(x)] < newHeap[x])	//	Pêtla wykonuj¹ca siê od ostatniego elementu dopóki rodzic bêdzie wiêkszy od porównywanego potomka.
		{
			int tempValue = newHeap[getParent(x)];		//	Tyczasowa zienna przechowuj¹ca rodzica zamienianego elementu.
			newHeap[getParent(x)] = newHeap[x];			//	Zamiana rodzica elementu z komórk¹.
			newHeap[x] = tempValue;						//	Zamiana elementu z rodzicem.
			x = getParent(x);
		}
	}
}

int Heap::getLeft(int x)								//	Zwrócenie indeksu lewego potomka.
{
	return (x * 2 + 1);
}

int Heap::getRight(int x)								//	Zwrócenie indeksu prawego potomka.
{
	return (x * 2 + 2);
}

int Heap::getParent(int x)								//	Zwrócenie indeksu rodzica.
{
	return floor((x - 1) / 2);
}