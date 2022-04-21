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
				"\t4.Menu testow.\n"
				"\t5.Powrot.\n";
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
		cin >> sHChoiceTestMenu;						//	Wybór opcji.

		switch (sHChoiceTestMenu)
		{
		case 1:
		{
			testPush();									//	Testowanie dodawania okreœlonej iloœci elementów.
			break;
		}
		case 2:
		{
			testPop();									//	Testowanie usuwania okreœlonej iloœci elementów.
			break;
		}
		case 3:
		{
			testSearch();								//	Testowanie wyszukiwania okreœlonej iloœci elementów.
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
	if (ifHFile.good())									//	Sprawdzenie czy plik zosta³ pomyœlnie otwarty.
	{
		shH.opened();									//	Wyœwietlenie komunikatu o pomyœlnym otwarciu pliku.

		auto o1 = chrono::high_resolution_clock::now();	//	Pomiar czasu w momencie rozpoczêcia operacji.
		string sHLineCountBuffer;
		getline(ifHFile, sHLineCountBuffer);			//	Odczytanie z pliku linii zawieraj¹cej iloœæ elementów.
		int iHLineCount = stoi(sHLineCountBuffer);		//	Zmiana typu string odczytanej wartoœci na typ int.
		cout << "Ilosc elementow przekazanych do struktury: " << iHLineCount << endl;

		auto tempHeap = new int[iHLineCount];			// Stworzenie tymczasowego kopca z okreœlon¹ iloœci¹ komórek.

		for (int i = 0; i < iHLineCount; i++)			//	Pêtla wykonuj¹ca siê tyle razy ile zostanie wczytanych elementów.
		{
			string sHLineValueBuffer;
			getline(ifHFile, sHLineValueBuffer);		//	Odczytanie z pliku linii zawieraj¹cej element.

			int iHLineValue = stoi(sHLineValueBuffer);	//	Zmiana typu string odczytanej wartoœci na typ int.

			tempHeap[i] = iHLineValue;					//	Przypisanie odczytanej wartoœci do okreœlonej komórki w kopcu.
			
			HeapifyUp();								//	Posortowanie kopca po odczytaniu wartoœci.
		}
		delete[] newHeap;								//	Usuniêcie zawartoœci kopca u¿ywanego w programie.
		newHeap = tempHeap;								//	Skopiowanie zawartoœci tymczasowego kopca do kopca u¿ywanego w programie.
		tempHeap = nullptr;
		iHSize = iHLineCount;							//	Przypisanie do zmiennej przechowuj¹cej rozmiar kopca zmiennej przechowuj¹cej iloœæ odczytanych danych z pliku.

		ifHFile.close();								//	Zamkniêcie pliku.

		auto o2 = chrono::high_resolution_clock::now();	//	Pomiar czasu w momencie zakoñczenia operacji.

		outcomeHeap.tMOutcome(o1, o2);					//	Wyœwieltenie czasu wykonywania operacji.
		
		shH.done();										//	Wyœwieltenie komunikatu o zakoñczeniu wykonywania operacji.
	}
	else
	{
		shH.noFile();									//	Wyœwietlenie komunikatu o problemie zwi¹zanym z otwarciem pliku.
	}
}

void Heap::generateElements()
{
	int iHNumberOfGen;
	cout << "Ile elementow ma zostac wygenerowanych?\n";
	cin >> iHNumberOfGen;								//	Wybranie iloœci generowanych elementów.

	auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpoczêcia operacji.

	srand(time(0));

	delete[] newHeap;									//	Usuniêcie zawartoœci kopca u¿ywanego w programie.
	newHeap = nullptr;
	iHSize = 0;											//	Wyzerowanie zmiennej przechowuj¹cej rozmiar kopca.
	newHeap = new int[iHNumberOfGen];					//	Stworzenie nowej tablicy przechowuj¹cej element kopca o okreœlonej wczeœniej wielkoœci.
	
	for (int i = 0; i < iHNumberOfGen; i++)				//	Pêtla wykonuj¹ca siê wybran¹ iloœæ razy.
	{
		newHeap[i] = rand();							//	Przypisanie generowanej wartoœci do komórki kopca.
		iHSize++;										//	Inkrementacja zmiennej przechowuj¹cej rozmiar kopca.
		HeapifyUp();									//	Posortowanie po wygenerowaniu elementu.
	}

	auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakoñczenia operacji.

	outcomeHeap.tMOutcome(o1, o2);						//	Wyœwietlenie czasu wykonywania operacji.

	shH.done();											//	Wyœwietlenie komunikatu o zakoñczeniu wykonywania operacji.
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

		HeapifyDown(0);									//	Posortowanie elementów w dó³.

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
		newHeap = nullptr;
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

		bool outOfBound = false;
		int first = 0;
		int last = 1;

		int space = pow(2, floor(log2(iHSize)) + 1) - 1;	//	Obliczenie maksymalnej iloœci elementów w warstwie.

		while (!outOfBound)									//	Pêtla wykonuj¹ca siê dopóki s¹ elementy do odczytania.
		{
			cout << string(space / 2 * 3, ' ');				//	Wydrukowanie znaku spacji przed ka¿d¹ warstw¹ kopca.

			for (int i = first; i < last; i++)				//	Wydrukowanie elementów na danej warstwie.
			{
				if (i >= iHSize)							//	Sprawdzenie czy wyœwietlany element jest wiêkszy od rozmiaru kopca.
				{
					outOfBound = true;						//	Zmiana zmiennej odpowiadaj¹cej za wykonywanie siê pêtli.
					break;
				}
				cout << '[' << newHeap[i] << ']' << string(space * 3, ' ');	//	Wyœwietlenie elementu.
			}
			cout << "\n\n";

			first = last;									//	Zmiana parametrów pierwszej i ostatniej komórki w warstwie.
			last = 2 * last + 1;

			space = space / 2;								//	Zmiana przestrzeni miêdzy elementami.
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

void Heap::HeapifyDown(int index)						//	Posortowanie kopca w dó³.
{
	int left = getLeft(index);							//	Zwrócenie pozycji lewego potomka.
	int right = getRight(index);						//	Zwrócenie pozycji prawego potomka.
	int parent = index;									//	Zwrócenie pozycji aktualnie sortowanej komórki.

	if (left < iHSize && newHeap[left] > newHeap[parent])	//	Sprawdzenie czy pozycja lewego potomka mieœci siê w kopcu i czy jego wartoœæ jest wiêksza od wartoœci rodzica.
	{
		parent = left;										//	Przypisanie pozycji lewego potomka do zmiennej przechowuj¹cej pozycjê sortowanego elementu.
	}
	if (right < iHSize && newHeap[right] > newHeap[parent])	//	Sprawdzenie czy pozycja prawego potomka mieœci siê w kopcu i czy jego wartoœæ jest wiêksza od wartoœci rodzica.
	{
		parent = right;										//	Przypisanie pozycji lewego potomka do zmiennej przechowuj¹cej pozycjê sortowanego elementu.
	}
	if (parent != index)									//	Sprawdzenie czy potomkowie okazali siê wiêksi od sortowanego elementu.
	{
		auto tmp = newHeap[parent];						//	Stworzenie tymczasowej zmiennej rpzechowuj¹cej wartoœæ rodzica w przypadku zamiany elementów.
		newHeap[parent] = newHeap[index];				//	Zamiana wiêkszego elementu z sortowanym elementem.
		newHeap[index] = tmp;

		HeapifyDown(parent);							//	Ponowne posortowanie elementu jeœli zosta³ zamieniony.
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

void Heap::testPush()									//	Testowanie dodawania.
{
	int iHTPuChoice;
	cout << "Dla ilu elementow maja zostac przeprowadzone testy?";
	cin >> iHTPuChoice;									//	Wybór iloœci daneych dla których maj¹ zostaæ przeprowadzone testy.

	srand(time(0));

	cout << "------------------------------------------\n"
		"Dodawanie:\n";
	for (int i = 0; i < 100; i++)						//	Pêtla wykonuj¹ca siê 100 razy ze wzglêdu na 100 pomiarów.
	{
		generateElementsTest(iHTPuChoice);				//	Wygenerowanie okreœlonej iloœci elementów.

		pushTest();										//	Dodanie pseudo losowego elementu.

		clearAllTTest();								//	Usuniêcie ca³ej zawartoœci struktury.
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

void Heap::generateElementsTest(int iHTPuChoice)		//	Wygenerowanie psudo losowych wartoœci (wersja skrócona ze wzglêdu na testy).
{
	auto *tempHeap = new int[iHTPuChoice];				//	Stworzenie tymczasowego kopca z now¹ liczb¹ dancyh.

	for (int z = 0; z < iHTPuChoice; z++)				//	Pêtla wykonuj¹ca siê okreœlon¹ iloœæ razy.
	{
		tempHeap[z] = rand();							//	Wygenerowanie elementu.
		HeapifyUp();									//	Posortowanie kopca.
	}
	delete[] this->newHeap;								//	Usuniêcie zawartoœci kopca u¿ywanego w programie.
	this->newHeap = tempHeap;							//	Skopiowanie zawartoœci tymczaswowego kopca do kopca u¿ywanego w programie.
	tempHeap = nullptr;	
	this->iHSize = iHTPuChoice;							//	Przypisanie do zmiennej przechowuj¹cej rozmiar nowej wartoœci.
}

void Heap::clearAllTTest()								//	Usuniêcie wszystkich elementów kopca (wersja skrócona ze wzglêdu na testy).
{
	delete[] this->newHeap;
	this->iHSize = 0;
	this->newHeap = nullptr;
}

void Heap::pushTest()									//	Testowe dodanie do kopca.
{
	int iHNewEndElement = rand();						//	Wygenerowanie nowej wartoœci.

	auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpoczêcia operacji.

	auto tempHeap = new int[iHSize + 1];				//	Stworzenie nowej tablicy o powiêkszonym rozmiarze.

	tempHeap[iHSize] = iHNewEndElement;					//	Przypisanie nowego elementu do ostatniej komórki.
	if (iHSize != 0)									//	Sprawdzenie czy struktura ma zawartoœæ.
	{
		for (int i = 0; i < iHSize; i++)				//	Pêtla wykonuj¹ca siê tyle razy ile kopiec ma elementów.
		{
			tempHeap[i] = newHeap[i];					//	Skopiowanie okreœlonej wartoœci z kopca tymczasowego do kopca u¿ywanego w programie.
		}
	}
	delete[] newHeap;									//	Usuniêcie zawartoœci kopca u¿ywanego w programie.
	newHeap = tempHeap;									//	Skopiowanie zawartoœci tymczasowego kopca do kopca u¿ywanego w programie.
	tempHeap = nullptr;									
	iHSize++;											//	Inkrementacja zmiennej zawieraj¹cej rozmiar kopca.

	HeapifyUp();										//	Posortowanie kopca.

	auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakoñczenia operacji.

	outcomeHeap.tMShort(o1, o2);						//	Wyœwietlenie czasu wykonywania operacji i zapisanie go do pliku tekstowego.
}

void Heap::popTest()
{
	auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpoczêcia operacji.
	auto tempHeap = new int[iHSize - 1];

	tempHeap[0] = newHeap[iHSize - 1];
	for (int i = 1; i < iHSize - 1; i++)				//	Pêtla wykonuj¹ca siê od pierwszego do przedostatniego elementu.
	{
		tempHeap[i] = newHeap[i];						//	Skopiowanie okreœlonej wartoœci z kopca tymczasowego do kopca u¿ywanego w programie.
	}
	delete[] newHeap;									//	Usuniêcie zawartoœci kopca u¿ywanego w programie.
	newHeap = tempHeap;
	tempHeap = nullptr;
	iHSize--;											//	Dekrementacja zmiennej zawieraj¹cej rozmiar kopca.

	HeapifyDown(0);										//	Posortowanie kopca.

	auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakoñczenia operacji.
	
	outcomeHeap.tMShort(o1, o2);						//	Wyœwietlenie czasu wykonywania operacji i zapisanie go do pliku tekstowego.
}

void Heap::searchTest(int iHTDChoicev)
{
	int iHChoiceDisplay = rand();
	auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpoczêcia operacji.

	for (int i = 0; i < iHTDChoicev; i++)				//	
	{
		if (iHChoiceDisplay == newHeap[i])				//	Sprawdzenie czy wartoœæ elementu jest równa wyszukiwanemu elementowi.
		{
			goto displayed;								//	Etykieta umo¿liwiaj¹ca wyjœcie z pêtli po znalezieniu poszukiwanego elementu.
		}
	}
displayed:
	auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakoñczenia operacji.

	outcomeHeap.tMShort(o1, o2);						//	Wyœwietlenie czasu wykonywania operacji i zapisanie go do pliku tekstowego.
}