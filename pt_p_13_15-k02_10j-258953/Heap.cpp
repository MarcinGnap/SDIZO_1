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
				"\t4.Menu testow.\n"
				"\t5.Powrot.\n";
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

void Heap::testMenu()									//	Menu testowania operacji kopca.
{
	short sHChoiceTestMenu;

	for (;;)
	{
		shH.cls();

		cout << "Prosze wybrac:\n"
			"\t1.Testy dodawania.\n"
			"\t2.Testy usuwania.\n"
			"\t3.Testy wyswietlania.\n"
			"\t4.Powrot.\n";
		cin >> sHChoiceTestMenu;						//	Wyb�r opcji.

		switch (sHChoiceTestMenu)
		{
		case 1:
		{
			testPush();									//	Testowanie dodawania okre�lonej ilo�ci element�w.
			break;
		}
		case 2:
		{
			testPop();									//	Testowanie usuwania okre�lonej ilo�ci element�w.
			break;
		}
		case 3:
		{
			testSearch();								//	Testowanie wyszukiwania okre�lonej ilo�ci element�w.
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
	if (ifHFile.good())									//	Sprawdzenie czy plik zosta� pomy�lnie otwarty.
	{
		shH.opened();									//	Wy�wietlenie komunikatu o pomy�lnym otwarciu pliku.

		auto o1 = chrono::high_resolution_clock::now();	//	Pomiar czasu w momencie rozpocz�cia operacji.
		string sHLineCountBuffer;
		getline(ifHFile, sHLineCountBuffer);			//	Odczytanie z pliku linii zawieraj�cej ilo�� element�w.
		int iHLineCount = stoi(sHLineCountBuffer);		//	Zmiana typu string odczytanej warto�ci na typ int.
		cout << "Ilosc elementow przekazanych do struktury: " << iHLineCount << endl;

		auto tempHeap = new int[iHLineCount];			// Stworzenie tymczasowego kopca z okre�lon� ilo�ci� kom�rek.

		for (int i = 0; i < iHLineCount; i++)			//	P�tla wykonuj�ca si� tyle razy ile zostanie wczytanych element�w.
		{
			string sHLineValueBuffer;
			getline(ifHFile, sHLineValueBuffer);		//	Odczytanie z pliku linii zawieraj�cej element.

			int iHLineValue = stoi(sHLineValueBuffer);	//	Zmiana typu string odczytanej warto�ci na typ int.

			tempHeap[i] = iHLineValue;					//	Przypisanie odczytanej warto�ci do okre�lonej kom�rki w kopcu.
			
			HeapifyUp();								//	Posortowanie kopca po odczytaniu warto�ci.
		}
		delete[] newHeap;								//	Usuni�cie zawarto�ci kopca u�ywanego w programie.
		newHeap = tempHeap;								//	Skopiowanie zawarto�ci tymczasowego kopca do kopca u�ywanego w programie.
		tempHeap = nullptr;
		iHSize = iHLineCount;							//	Przypisanie do zmiennej przechowuj�cej rozmiar kopca zmiennej przechowuj�cej ilo�� odczytanych danych z pliku.

		ifHFile.close();								//	Zamkni�cie pliku.

		auto o2 = chrono::high_resolution_clock::now();	//	Pomiar czasu w momencie zako�czenia operacji.

		outcomeHeap.tMOutcome(o1, o2);					//	Wy�wieltenie czasu wykonywania operacji.
		
		shH.done();										//	Wy�wieltenie komunikatu o zako�czeniu wykonywania operacji.
	}
	else
	{
		shH.noFile();									//	Wy�wietlenie komunikatu o problemie zwi�zanym z otwarciem pliku.
	}
}

void Heap::generateElements()
{
	int iHNumberOfGen;
	cout << "Ile elementow ma zostac wygenerowanych?\n";
	cin >> iHNumberOfGen;								//	Wybranie ilo�ci generowanych element�w.

	auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpocz�cia operacji.

	srand(time(0));

	delete[] newHeap;									//	Usuni�cie zawarto�ci kopca u�ywanego w programie.
	newHeap = nullptr;
	iHSize = 0;											//	Wyzerowanie zmiennej przechowuj�cej rozmiar kopca.
	newHeap = new int[iHNumberOfGen];					//	Stworzenie nowej tablicy przechowuj�cej element kopca o okre�lonej wcze�niej wielko�ci.
	
	for (int i = 0; i < iHNumberOfGen; i++)				//	P�tla wykonuj�ca si� wybran� ilo�� razy.
	{
		newHeap[i] = rand();							//	Przypisanie generowanej warto�ci do kom�rki kopca.
		iHSize++;										//	Inkrementacja zmiennej przechowuj�cej rozmiar kopca.
		HeapifyUp();									//	Posortowanie po wygenerowaniu elementu.
	}

	auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zako�czenia operacji.

	outcomeHeap.tMOutcome(o1, o2);						//	Wy�wietlenie czasu wykonywania operacji.

	shH.done();											//	Wy�wietlenie komunikatu o zako�czeniu wykonywania operacji.
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

		HeapifyDown(0);									//	Posortowanie element�w w d�.

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
		newHeap = nullptr;
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

		bool outOfBound = false;
		int first = 0;
		int last = 1;

		int space = pow(2, floor(log2(iHSize)) + 1) - 1;	//	Obliczenie maksymalnej ilo�ci element�w w warstwie.

		while (!outOfBound)									//	P�tla wykonuj�ca si� dop�ki s� elementy do odczytania.
		{
			cout << string(space / 2 * 3, ' ');				//	Wydrukowanie znaku spacji przed ka�d� warstw� kopca.

			for (int i = first; i < last; i++)				//	Wydrukowanie element�w na danej warstwie.
			{
				if (i >= iHSize)							//	Sprawdzenie czy wy�wietlany element jest wi�kszy od rozmiaru kopca.
				{
					outOfBound = true;						//	Zmiana zmiennej odpowiadaj�cej za wykonywanie si� p�tli.
					break;
				}
				cout << '[' << newHeap[i] << ']' << string(space * 3, ' ');	//	Wy�wietlenie elementu.
			}
			cout << "\n\n";

			first = last;									//	Zmiana parametr�w pierwszej i ostatniej kom�rki w warstwie.
			last = 2 * last + 1;

			space = space / 2;								//	Zmiana przestrzeni mi�dzy elementami.
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

void Heap::HeapifyDown(int index)						//	Posortowanie kopca w d�.
{
	int left = getLeft(index);							//	Zwr�cenie pozycji lewego potomka.
	int right = getRight(index);						//	Zwr�cenie pozycji prawego potomka.
	int parent = index;									//	Zwr�cenie pozycji aktualnie sortowanej kom�rki.

	if (left < iHSize && newHeap[left] > newHeap[parent])	//	Sprawdzenie czy pozycja lewego potomka mie�ci si� w kopcu i czy jego warto�� jest wi�ksza od warto�ci rodzica.
	{
		parent = left;										//	Przypisanie pozycji lewego potomka do zmiennej przechowuj�cej pozycj� sortowanego elementu.
	}
	if (right < iHSize && newHeap[right] > newHeap[parent])	//	Sprawdzenie czy pozycja prawego potomka mie�ci si� w kopcu i czy jego warto�� jest wi�ksza od warto�ci rodzica.
	{
		parent = right;										//	Przypisanie pozycji lewego potomka do zmiennej przechowuj�cej pozycj� sortowanego elementu.
	}
	if (parent != index)									//	Sprawdzenie czy potomkowie okazali si� wi�ksi od sortowanego elementu.
	{
		auto tmp = newHeap[parent];						//	Stworzenie tymczasowej zmiennej rpzechowuj�cej warto�� rodzica w przypadku zamiany element�w.
		newHeap[parent] = newHeap[index];				//	Zamiana wi�kszego elementu z sortowanym elementem.
		newHeap[index] = tmp;

		HeapifyDown(parent);							//	Ponowne posortowanie elementu je�li zosta� zamieniony.
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

void Heap::testPush()									//	Testowanie dodawania.
{
	int iHTPuChoice;
	cout << "Dla ilu elementow maja zostac przeprowadzone testy?";
	cin >> iHTPuChoice;									//	Wyb�r ilo�ci daneych dla kt�rych maj� zosta� przeprowadzone testy.

	srand(time(0));

	cout << "------------------------------------------\n"
		"Dodawanie:\n";
	for (int i = 0; i < 100; i++)						//	P�tla wykonuj�ca si� 100 razy ze wzgl�du na 100 pomiar�w.
	{
		generateElementsTest(iHTPuChoice);				//	Wygenerowanie okre�lonej ilo�ci element�w.

		pushTest();										//	Dodanie pseudo losowego elementu.

		clearAllTTest();								//	Usuni�cie ca�ej zawarto�ci struktury.
	}

	shH.done();
}

void Heap::testPop()
{
	int iHTPoChoice;
	cout << "Dla ilu elementow maja zostac przeprowadzone testy?";
	cin >> iHTPoChoice;

	srand(time(0));

	cout << "------------------------------------------\n"
		"Usuwanie:\n";
	for (int i = 0; i < 100; i++)
	{
		generateElementsTest(iHTPoChoice);

		popTest();

		clearAllTTest();
	}

	shH.done();
}

void Heap::testSearch()
{
	int iHTDChoice;
	cout << "Dla ilu elementow maja zostac przeprowadzone testy?";
	cin >> iHTDChoice;

	srand(time(0));

	cout << "------------------------------------------\n"
		"Szukanie elementu:\n";
	for (int i = 0; i < 100; i++)
	{
		generateElementsTest(iHTDChoice);

		searchTest(iHTDChoice);

		clearAllTTest();
	}
	shH.done();
}

void Heap::generateElementsTest(int iHTPuChoice)		//	Wygenerowanie psudo losowych warto�ci (wersja skr�cona ze wzgl�du na testy).
{
	auto *tempHeap = new int[iHTPuChoice];				//	Stworzenie tymczasowego kopca z now� liczb� dancyh.

	for (int z = 0; z < iHTPuChoice; z++)				//	P�tla wykonuj�ca si� okre�lon� ilo�� razy.
	{
		tempHeap[z] = rand();							//	Wygenerowanie elementu.
		HeapifyUp();									//	Posortowanie kopca.
	}
	delete[] this->newHeap;								//	Usuni�cie zawarto�ci kopca u�ywanego w programie.
	this->newHeap = tempHeap;							//	Skopiowanie zawarto�ci tymczaswowego kopca do kopca u�ywanego w programie.
	tempHeap = nullptr;	
	this->iHSize = iHTPuChoice;							//	Przypisanie do zmiennej przechowuj�cej rozmiar nowej warto�ci.
}

void Heap::clearAllTTest()								//	Usuni�cie wszystkich element�w kopca (wersja skr�cona ze wzgl�du na testy).
{
	delete[] this->newHeap;
	this->iHSize = 0;
	this->newHeap = nullptr;
}

void Heap::pushTest()									//	Testowe dodanie do kopca.
{
	int iHNewEndElement = rand();						//	Wygenerowanie nowej warto�ci.

	auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpocz�cia operacji.

	auto tempHeap = new int[iHSize + 1];				//	Stworzenie nowej tablicy o powi�kszonym rozmiarze.

	tempHeap[iHSize] = iHNewEndElement;					//	Przypisanie nowego elementu do ostatniej kom�rki.
	if (iHSize != 0)									//	Sprawdzenie czy struktura ma zawarto��.
	{
		for (int i = 0; i < iHSize; i++)				//	P�tla wykonuj�ca si� tyle razy ile kopiec ma element�w.
		{
			tempHeap[i] = newHeap[i];					//	Skopiowanie okre�lonej warto�ci z kopca tymczasowego do kopca u�ywanego w programie.
		}
	}
	delete[] newHeap;									//	Usuni�cie zawarto�ci kopca u�ywanego w programie.
	newHeap = tempHeap;									//	Skopiowanie zawarto�ci tymczasowego kopca do kopca u�ywanego w programie.
	tempHeap = nullptr;									
	iHSize++;											//	Inkrementacja zmiennej zawieraj�cej rozmiar kopca.

	HeapifyUp();										//	Posortowanie kopca.

	auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zako�czenia operacji.

	outcomeHeap.tMShort(o1, o2);						//	Wy�wietlenie czasu wykonywania operacji i zapisanie go do pliku tekstowego.
}

void Heap::popTest()
{
	auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpocz�cia operacji.
	auto tempHeap = new int[iHSize - 1];

	tempHeap[0] = newHeap[iHSize - 1];
	for (int i = 1; i < iHSize - 1; i++)				//	P�tla wykonuj�ca si� od pierwszego do przedostatniego elementu.
	{
		tempHeap[i] = newHeap[i];						//	Skopiowanie okre�lonej warto�ci z kopca tymczasowego do kopca u�ywanego w programie.
	}
	delete[] newHeap;									//	Usuni�cie zawarto�ci kopca u�ywanego w programie.
	newHeap = tempHeap;
	tempHeap = nullptr;
	iHSize--;											//	Dekrementacja zmiennej zawieraj�cej rozmiar kopca.

	HeapifyDown(0);										//	Posortowanie kopca.

	auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zako�czenia operacji.
	
	outcomeHeap.tMShort(o1, o2);						//	Wy�wietlenie czasu wykonywania operacji i zapisanie go do pliku tekstowego.
}

void Heap::searchTest(int iHTDChoicev)
{
	int iHChoiceDisplay = rand();
	auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpocz�cia operacji.

	for (int i = 0; i < iHTDChoicev; i++)				//	
	{
		if (iHChoiceDisplay == newHeap[i])				//	Sprawdzenie czy warto�� elementu jest r�wna wyszukiwanemu elementowi.
		{
			goto displayed;								//	Etykieta umo�liwiaj�ca wyj�cie z p�tli po znalezieniu poszukiwanego elementu.
		}
	}
displayed:
	auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zako�czenia operacji.

	outcomeHeap.tMShort(o1, o2);						//	Wy�wietlenie czasu wykonywania operacji i zapisanie go do pliku tekstowego.
}