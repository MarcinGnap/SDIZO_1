#include "Tablica.h"

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <time.h>
#include <chrono>
#include <ratio>

using namespace std;

Tablica::Tablica()
{
	iTSize = 0;													//	Na start strukturze dajey roziar 0.
	newTable = new int[iTSize];
}

Tablica::~Tablica()
{
	
}

void Tablica::tableMenu()										//	G³ówne menu tablicy.
{
	short sTChoiceTableMenu;									//	Zmienna potrzebna do instrukcji switch.

	for (;;)
	{
		shT.cls();

		cout << "Prosze wybrac:\n"
				"\t1.Menu dodawania.\n"
				"\t2.Menu usuwania.\n"
				"\t3.Menu wyswietlania.\n"
				"\t4.Menu testow.\n"
				"\t5.Powrot\n";
		cin >> sTChoiceTableMenu;

		switch (sTChoiceTableMenu)
		{
		case 1:
		{
			pushMenu();											//	Menu dodawania do tablicy.
			break;
		}
		case 2:
		{
			popMenu();											//	Menu usuwania elementów z tablicy.
			break;
		}
		case 3:
		{
			displayMenu();										//	Menu wyœwietlania elementów tablicy.
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
			shT.noOption();
			break;
		}
		}
	}
}

void Tablica::pushMenu()										//	Menu dodawania do tablicy.
{
	short sTChoicePushMenu;										//	Menu dodawania.

	for (;;)
	{
		system("CLS");

		cout << "Prosze wybrac:\n"
				"\t1.Dodanie na poczatek struktury.\n"
				"\t2.Dodanie na koniec struktury.\n"
				"\t3.Dodanie w okreslonie miejsce w strukturze.\n"
				"\t4.Wczytanie danych z pliku tekstowego do struktury.\n"
				"\t5.Wylosowanie okreslonej liczby elementow do struktury.\n"
				"\t6.Powrot.\n";
		cin >> sTChoicePushMenu;

		switch (sTChoicePushMenu)
		{
		case 1:
		{
			int iTNewFrontElement;

			cout << "Podaj liczbe jaka ma byc dodana do tablicy:\n";
			cin >> iTNewFrontElement;							//	Wybór wartoœci dodawanego elementu.
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpoczêcia operacji.

			pushFront(iTNewFrontElement);						//	Dodanie elementu na pocz¹tek.

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakoñczenia programu.
			outcomeTable.tMOutcome(o1, o2);						//	Wyœwietlenie czasu wykonania operacji.
			shT.done();											//	Wyœwietlenie komunikatu o zakoñczeniu zadania oraz czekanie na naciœniêcie klawisza przez u¿ytkownika.
			displayAll();

			break;
		}
		case 2:
		{
			int iTNewEndElement;

			cout << "Podaj liczbe jaka ma byc dodana do tablicy:\n";
			cin >> iTNewEndElement;								//	Wybór dodawanej wartoœci.
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpoczêcia operacji.

			pushEnd(iTNewEndElement);							//	Dodanie elementu na koniec.

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakoñczenia wykonywania operacji.
			outcomeTable.tMOutcome(o1, o2);						//	Wypisanie czasu wykonania operacji.
			displayAll();
			shT.done();											//	Wyœwietlenie komunikatu o zakoñczeniu zadania oraz czekanie na naciœniêcie klawisza przez u¿ytkownika.

			break;
		}
		case 3:
		{
			int iTNewMidElement;
			int iTPushPosition;

			cout << "Podaj pozycje, na ktora ma zostac dodany element (zakladamy ze numeracja zaczyna sie od 1):\n";
			cin >> iTPushPosition;								//	Wybór pozycji (pozycja + 1 ze wzglêdu na numeracjê komórek w tablicy), na któr¹ ma zostaæ wstawiony element.

			cout << "Podaj liczbe jaka ma byc dodana do tablicy:\n";
			cin >> iTNewMidElement;								//	Wybór wartoœci jaka ma zostaæ wpisana w okreœlone miejsce.
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpoczêcia operacji.
			int iTRightPush = iTPushPosition - 1;				//	Przypisanie do zmiennej prawdziwej pozycji w tablicy.

			pushMiddle(iTRightPush, iTNewMidElement);		//	Dodanie elementu w okreœlone miejsce.

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakoñczenia operacji.
			outcomeTable.tMOutcome(o1, o2);						//	Wyœwietlenie czasu wykonywania operacji.
			displayAll();
			shT.done();											//	Wyœwietlenie kounikatu o wykonaniu operacji.

			break;
		}
		case 4:
		{
			readFromFileT();									//	Odczytanie i wpisanie wartoœci z pliku tekstowego do tablicy.
			
			displayAll();
			shT.done();											//	Wyœwietlenie komunikatu o zakoñczeniu wykonywania operacji.

			break;
		}
		case 5:
		{
			int iTNumberOfGen;
			cout << "Ile elementow ma zostac wygenerowanych?\n";
			cin >> iTNumberOfGen;								//	Wybór iloœci generowanych elementów.
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpoczêcia operacji.

			srand(time(0));

			generateElements(iTNumberOfGen);					//	Wygenerowanie danej liczby elementów.

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakoñczenia operacji.
			outcomeTable.tMOutcome(o1, o2);						//	Wyœwietlenie czasu wykonania operacji.
			displayAll();
			shT.done();											//	Wyœwieltenie komunikatu o zakoñczeniu operacji.
			
			break;
		}
		case 6:
		{
			return;
			break;
		}
		default:
		{
			shT.noOption();
			break;
		}
		}
	}
}

void Tablica::popMenu()											//	Menu usuwania.
{
	short sTChoicePopMenu;

	for (;;)
	{
		shT.cls();

		cout << "Prosze wybrac:\n"
				"\t1.Usuniecie elementu z poczatku struktury.\n"
				"\t2.Usuniecie elementu z konca struktury.\n"
				"\t3.Usuniecie elementu z okreslonego miejsca w struktury (szukajac po indeksie).\n"
				"\t4.Usuniecie elementu z okreslonego miejsca w struktury (szukajac po wartosci).\n"
				"\t5.Usuniecie wszystkich elementow ze struktury.\n"
				"\t6.Powrot.\n";
		cin >> sTChoicePopMenu;

		switch (sTChoicePopMenu)
		{
		case 1:
		{
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpoczêcia operacji.

			popFront();											//	Usuniêcie elementu z pocz¹tku tablicy.

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakoñczenia operacji.
			outcomeTable.tMOutcome(o1, o2);						//	Wyœwietlenie czasu wykonania operacji.
			displayAll();
			shT.done();											//	Wyœwieltenie komunikatu o zakoñczeniu operacji.

			break;
		}
		case 2:
		{
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpoczêcia operacji.

			popEnd();											//	Usuniêcie elementu z koñca.

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakoñczenia operacji.
			outcomeTable.tMOutcome(o1, o2);						//	Wyœwietlenie czasu wykonania operacji.
			displayAll();
			shT.done();											//	Wyœwieltenie komunikatu o zakoñczeniu operacji.

			break;
		}
		case 3:
		{
			int iTPopPosition;

			cout << "Podaj pozycje, z ktorej ma zostac usuniety element (zakladamy ze numeracja zaczyna sie od 1):\n";
			cin >> iTPopPosition;								//	Wybór pozycji, z której ma zostaæ usuniêty element.
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpoczêcia operacji.

			popMiddleIndex(iTPopPosition);						//	Usuniêcie elementu z podanej pozycji.

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakoñczenia operacji.
			outcomeTable.tMOutcome(o1, o2);						//	Wyœwietlenie czasu wykonywania operacji.
			displayAll();
			shT.done();											//	Wyœwieltenie komunikatu o zakoñczeniu operacji.

			break;
		}case 4:
		{
			int iTPopValue;

			cout << "Podaj wartosc, jaka ma zostac usunieta z tablicy:\n";
			cin >> iTPopValue;									//	Wybór pozycji, z której ma zostaæ usuniêty element.
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpoczêcia operacji.

			if (popMiddleValue(iTPopValue) == true)				//	Usuniêcie wskazanego elementu listy.
			{
				cout << "Wybrany element zostal usuniety ze struktury.\n";
			}
			else
			{
				shT.noIn();
			}
			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakoñczenia operacji.
			outcomeTable.tMOutcome(o1, o2);						//	Wyœwietlenie czasu wykonywania operacji.
			displayAll();
			shT.done();											//	Wyœwieltenie komunikatu o zakoñczeniu operacji.

			break;
		}
		case 5:
		{
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpoczêcia operacji.

			clearAllT();										// Usuniêcie wszystkich elementów z tablicy.

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakoñczenia operacji.
			outcomeTable.tMOutcome(o1, o2);						//	Wyœwietlenie czasu wykonania operacji.
			displayAll();
			shT.done();											//	Wyœwieltenie komunikatu o zakoñczeniu operacji.

			break;
		}
		case 6:
		{
			return;
			break;
		}
		default:
		{
			shT.noOption();
			break;
		}
		}
	}
}

void Tablica::displayMenu()										//	Menu wyœwietlania.
{
	short sTChoiceDisplayMenu;

	for (;;)
	{
		shT.cls();

		cout << "Prosze wybrac:\n"
				"\t1.Wyswietlenie calej zawartosci struktury.\n"
				"\t2.Wyswietlenie okreslonego elementu struktury po wartosci.\n"
				"\t3.Wyswietlenie okreslonego elementu struktury po indeksie.\n"
				"\t4.Powrot.\n";
		cin >> sTChoiceDisplayMenu;

		switch (sTChoiceDisplayMenu)
		{
		case 1:
		{
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momecie rozpoczêcia operacji.

			displayAll();										//	Wyœwietlenie wszystkich elementów.

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakoñczenia operacji.
			outcomeTable.tMOutcome(o1, o2);						//	Wyœwietlenie czasu wykonywania operacji.
			shT.done();
			break;
		}
		case 2:
		{
			int iTValueDisplay;

			cout << "Wybierz element, ktory chcesz wyswietlic (zakladamy ze numeracja zaczyna sie od 1): " << endl;
			cin >> iTValueDisplay;								//	Wybór wartoœci, jaka ma zostaæ znaleziona w strukturze.
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momecie rozpoczêcia operacji.

			if (displayOneValue(iTValueDisplay) == true)
			{
				cout << "Wybrany element " << iTValueDisplay << " znajduje sie w strukturze.\n";	//	Wyœwietlenie wybranego elementu.
			}
			else
			{
				shT.noIn();
			}
			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakoñczenia operacji.
			outcomeTable.tMOutcome(o1, o2);						//	Wyœwietlenie czasu wykonywania operacji.
			shT.done();
			break;
		}
		case 3:
		{
			int iTChoiceDisplay;

			cout << "Wybierz element, ktory chcesz wyswietlic (zakladamy ze numeracja zaczyna sie od 1): " << endl;
			cin >> iTChoiceDisplay;								//	Wybór pozycji, z której ma zostaæ wyœwietlony element.
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpoczêcia wykonywania operacji.

			displayOneIndex(iTChoiceDisplay);					//	Wyœwietlenie elementu z wybranej pozycji.

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakoñczenia operacji.
			outcomeTable.tMOutcome(o1, o2);						//	Wyœwietlenie czasu wykonywania operacji.
			shT.done();
			break;
		}
		case 4:
		{
			return;
			break;
		}
		default:
		{
			shT.noOption();
			break;
		}
		}
	}
}

void Tablica::testMenu()
{
	short sTChoiceTestMenu;

	for (;;)
	{
		shT.cls();

		cout << "Prosze wybrac:\n"
			"\t1.Testy dodawania.\n"
			"\t2.Testy usuwania.\n"
			"\t3.Testy wyszukiwania.\n"
			"\t4.Powrot.\n";
		cin >> sTChoiceTestMenu;

		switch (sTChoiceTestMenu)
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
			shT.noOption();
			break;
		}
		}
	}
}

void Tablica::pushFront(int iTNewFrontElement)					//	Dodanie elementu na pocz¹tek tablicy.
{
	int iTTempSize = iTSize + 1;
	auto tempTable = new int[iTSize + 1];						//	Tworzenie tymczasowej tablicy z nowym rozmiarem.
	
	tempTable[0] = iTNewFrontElement;							//	Przypisanie dodawanego elementu na odpowiednie miejsce do tymczasowej tablicy.
	if (iTSize != 0)
	{
		for (int i = iTTempSize; i >= 1; i--)					//	Pêtla wykonuj¹ca siê od ostatniego elementu tablicy do pierwszego.
		{
			tempTable[i] = newTable[i - 1];						//	Przypisanie elementu z tablicy poprzedniej do tablicy tymczasowej na nowe miejsce.
		}
	}
	delete [] newTable;											//	Usuniêcie zawartoœci poprzedniej tablicy.
	newTable = tempTable;										//	Skopiowanie zawartoœci tymczasowej tablicy do poprzedniej tablicy, która u¿ywania jest w programie.
	tempTable = nullptr;										//	Usuniêcie tymczasowej tablicy.
	iTSize++;													//	Powiêkszenie rozmiaru tablicy o 1.
}

void Tablica::pushEnd(int iTNewEndElement)						//	Dodanie na koniec tablicy.
{
	auto tempTable = new int[iTSize + 1];						//	Stworzenie tymczasowej tablicy z powiêkszonym rozmiarem.

	tempTable[iTSize] = iTNewEndElement;						//	Przypisanie dodawanego elementu na ostatnie miejsce tymczasowej tablicy.
	if (iTSize != 0)
	{
		for (int i = 0; i < iTSize; i++)						//	Pêtla wykonuj¹ca siê od pierwszego do ostatniego elementu w porzedniej tablicy.
		{
			tempTable[i] = newTable[i];							//	Przypisanie ka¿dego elementu z poprzedniej tablicy do tymczasowej tablicy.
		}
	}
	delete [] newTable;											//	Usuniêcie zawartoœci poprzedniej tablicy.
	newTable = tempTable;										//	Skopiowanie zawartoœci tymczasowej tablicy do tablicy u¿uwanej w programie.
	tempTable = nullptr;										//	Usuniêcie tymczasowej tablicy.
	iTSize++;													//	Powiêkszenie rozmiaru o 1.
}

void Tablica::pushMiddle(int iTRightPush, int iTNewMidElement)
{
	if (iTRightPush >= 0 && iTRightPush <= iTSize)				//	Sprawdzenie czy wybrana pozycja znajduje siê w tablicy.
	{
		auto tempTable = new int[iTSize + 1];					//	Stworzenie tymczasowej tablicy z powiêkszon¹ liczb¹ elementów.
		tempTable[iTRightPush] = iTNewMidElement;				//	Przypisanie wybranej wartoœci na wybran¹ pozycjê w tablicy.
		for (int i = 0; i < iTRightPush; i++)					//	Pêtla wykonuj¹ca siê od elementu pocz¹tkowego do pozycji, któr¹ wybra³ u¿ytkownik.
		{
			tempTable[i] = newTable[i];							//	Przypisanie danych elementów z poprzedniej tablicy do tymczasowej tablicy.
		}
		for (int i = iTRightPush + 1; i < iTSize + 1; i++)		//	Pêtla wykonuj¹ca siê od wybranej poprzednio pozycji do ostatniego elementu.
		{
			tempTable[i] = newTable[i-1];						//	Przypisanie danych elementów z poprzedniej tablicy do tymczasowej tablicy.
		}
		delete [] newTable;										//	Usuniêcie zawartoœci u¿ywanej w programie tablicy.
		newTable = tempTable;									//	Skopiowanie zawartoœci tymczasowej tablicy do tablicy u¿ywanej w programie.
		tempTable = nullptr;									//	Usuniêcie zawartoœci tymczasowej tablicy.
		iTSize++;												//	Inkrementacja zmiennej przechowujêcej rozmiar tablicy.
	}
	else
	{
		shT.away();												//	Wyœwietlenie komunikatu, ¿e wybrana pozycja znajduje siê poza tablic¹.
	}
}

void Tablica::readFromFileT()									//	Odczyt i przypisanie wartoœci z pliku tekstowego do tablicy.
{
	ifstream ifTFile("dane.txt", ios::in);						//	Deklaracja pliku o nazwie "dane.txt" w trybie do odczytu.
	if (ifTFile.good())											//	Sprawdzenie czy plik otworzy³ siê pomyœlnie.
	{
		shT.opened();											//	Wyœwietlenie komunikatu, ¿e plik zosta³ otwarty.

		auto o1 = chrono::high_resolution_clock::now();			//	Pomiar czasu w momencie rozpoczêcia operacji.
		string sTLineCountBuffer;								//	Stworzenie zmiennej przechowyj¹cej iloœæ odczytywanych elementów.
		getline(ifTFile, sTLineCountBuffer);					//	Odczytanie pierwszej linijki pliku tekstowego, w której wed³ug zamierzeñ ma byæ iloœæ odczytywanych elementów.
		int iTLineCount = stoi(sTLineCountBuffer);				//	Zmienienie typu odczytanego elementu na liczby ca³kowite.
		iTSize = iTLineCount;									//	Zmienienie wartoœci zmiennej przechowuj¹cej rozmiar tablicy na nowy rozmiar.
		cout << "Ilosc elementow przekazanych do struktury: " << iTLineCount << endl;
		
		auto tempTable = new int[iTSize];						//	Stworzenie tymczasowej tablicy z okreœlon¹ iloœci¹ elementów.

		for (int i = 1; i <= iTLineCount; i++)					//	Pêtla wykonuj¹ca siê od pierwszego pobieranego elementu z pliku tekstowego do ostatniego.
		{
			string sTLineValueBuffer;							//	Stworzenie zmiennej przechowuj¹cej odczytywany element.
			getline(ifTFile, sTLineValueBuffer);				//	Odczytanie elementu z pliku tekstowego.
			
			int iTLineValue = stoi(sTLineValueBuffer);			//	Konwersja odczytanego elementu na typ ca³kowity 4-bajtowy.

			tempTable[i-1] = iTLineValue;						//	Skopiowanie odczytanej wartoœci do okreœlonej komórki w tymczasowej tablicy.
		}

		delete[] newTable;										//	Usuniêcie zawartoœci u¿ywanej w programie tablicy.
		newTable = tempTable;									//	Skopiowanie zawartoœci tymczasowej tablicy do tablicy u¿ywanej w programie.
		tempTable = nullptr;									//	Usuniêcie zawartoœci tymczasowej tablicy.

		ifTFile.close();										//	Zamkniêcie pliku.

		auto o2 = chrono::high_resolution_clock::now();			//	Pomiar czasu w momecie zakoñczenia operacji.

		outcomeTable.tMOutcome(o1, o2);							//	Wyœwietlenie czasu wykonywania operacji.
	}
	else
	{
		shT.noFile();											//	Wyœwietlenie informacji o problemie z plikiem tekstowym.
	}
}

void Tablica::generateElements(int iTNumberOfGen)				//	Wygenerowanie okreœlonej liczby elementów.
{
	auto tempTable = new int[iTNumberOfGen];					//	Stworzenie tymczasowej tablicy z wybran¹ iloœci¹ komórek.

	for (int i = 0; i < iTNumberOfGen; i++)						//	Pêtla wykonuj¹ca siê wybran¹ iloœæ razy.
	{
		tempTable[i] = rand();									//	Pseudo wylosowanie elemntu i przypisanie go do zmiennej.
	}
	delete[] this->newTable;									//	Usuniêcie zawartoœci u¿ywanej w programie tablicy.
	this->newTable = tempTable;									//	Skopiowanie zawartoœci tymczasowej tablicy do tablicy u¿ywanej w programie.
	tempTable = nullptr;										//	Usuniêcie zawartoœci tymczasowej tablicy.
	this->iTSize = iTNumberOfGen;								//	Skopiowanie numeru wygenerowanych elementów do zmiennej przechowuj¹cej rozmiar tablicy.
}

void Tablica::popFront()										//	Usuniêcie elementu na pierwszym miejscu tablicy.
{
	if (iTSize != 0)											//	Instrukcja warunkowa sprawdzaj¹ca czy w tablicy s¹ elementy do usuniêcia.
	{
		auto tempTable = new int[iTSize - 1];					//	Stworzenie tymczasowej tablicy z now¹ iloœci¹ komórek.

		for (int i = iTSize - 1; i >= 0; i--)					//	Pêtla wykonuj¹ca siê od ostatniego elementu tablicy do drugiego.
		{
			tempTable[i] = newTable[i + 1];						//	Skopiowanie wartoœci okreœlonej komórki z porzedniej tablicy do komórki z indeksem o jeden mniejszym tablicy tymczasowej.
		}
		delete[] newTable;										//	Usuniêcie zawartoœci u¿ywanej w programie tablicy.
		newTable = tempTable;									//	Skopiowanie zawartoœci tymczasowej tablicy do tablicy u¿ywanej w programie.
		tempTable = nullptr;									//	Usuniêcie zawartoœci tymczasowej tablicy.
		iTSize--;												//	Dekrementacja zmiennej przechowuj¹cej rozmiar tablicy.
	}
	else
	{
		shT.empty();											//	Jeœli tablica nie ma elementów wyœwietli siê komunikat o tym zdarzeniu.
	}
}

void Tablica::popEnd()											//	Usuniêcie ostatniego elementu z tablicy.
{
	if (iTSize != 0)											// Sprawdzenie czy tablica ma zawartoœæ.
	{
		auto tempTable = new int[iTSize - 1];					//	Stworzenie tymczasowej tablicy z pomniejszon¹ liczb¹ elementów.

		for (int i = 0; i < iTSize - 1; i++)					//	Pêtla wykonuj¹ca siê od pocz¹tkowego do przed ostatniego elementu tablicy.
		{
			tempTable[i] = newTable[i];							//	Skopiowanie zawartoœæi komórki z poprzedniej tablicy do tymczasowej tablicy.
		}
		delete[] newTable;										//	Usuniêcie zawartoœci u¿ywanej w programie tablicy.
		newTable = tempTable;									//	Skopiowanie zawartoœci tymczasowej tablicy do tablicy u¿ywanej w programie.
		tempTable = nullptr;									//	Usuniêcie zawartoœci tymczasowej tablicy.
		iTSize--;												//	Dekrementacja zmiennej przechowuj¹cej rozmiar tablicy.
	}
	else
	{
		shT.empty();											//	Jeœli tablica nie ma elementów wyœwietli siê komunikat o tym zdarzeniu.
	}
}

void Tablica::popMiddleIndex(int iTPopPosition)					//	Usuniêcie elementu z wybranej pozycji tablicy.
{
	int iTRightPop = iTPopPosition - 1;							//	Zmienna zawieraj¹ca poprawn¹ pozycjê usuwanego elementu.

	if (iTRightPop >= 0 && iTRightPop < iTSize)					//	Sprawdzenie czy wybrana pozycja znajduje siê w tablicy.
	{
		auto tempTable = new int[iTSize - 1];					//	Stworzenie tymczasowej tablicy z pomniejszon¹ iloœci¹ elementów.

		for (int i = 0; i < iTRightPop; i++)					//	Pêtla wykonuj¹ca siê od pierwszej do wybranej pozycji (wy³¹cznie) w tablicy.
		{
			tempTable[i] = newTable[i];							//	Skopiowanie okreœlonej wartoœci komórki z poprzedniej tablicy do tablicy tymczasowej.
		}
		for (int i = iTRightPop; i < iTSize; i++)				//	Pêtla wykonuj¹ca siê od wybranej pozycji do ostatniej.
		{
			tempTable[i] = newTable[i+1];						//	Skopiowanie okreœlonej wartoœci komórki z poprzedniej tablicy do komórki o indeksie o jeden mniejszy tablicy tymczasowej.
		}
		delete[] newTable;										//	Usuniêcie zawartoœci u¿ywanej w programie tablicy.
		newTable = tempTable;									//	Skopiowanie zawartoœci tymczasowej tablicy do tablicy u¿ywanej w programie.
		tempTable = nullptr;									//	Usuniêcie zawartoœci tymczasowej tablicy.
		iTSize--;												//	Dekrementacja zmiennej przechowuj¹cej rozmiar tablicy.
	}
	else
	{
		shT.away();												//	Wyœwietlenie komunikatu o braku wybranej pozycji w liœcie.
	}
}

bool Tablica::popMiddleValue(int iTPopValue)
{
	if (iTSize != 0)											//	Sprawdzenie czy kopiec ma zawartoœæ.
	{
		for (int i = 0; i < iTSize; i++)						//	Pêtla wykonuj¹ca siê od pierwszego do ostatniego elementu.
		{
			if (iTPopValue == newTable[i])						//	Sprawdzenie czy wartoœæ elementu pokrywa siê z wybran¹ wartoœci¹.
			{
				auto tempTable = new int[iTSize - 1];			//	Stworzenie tymczasowej tablicy z pomniejszon¹ iloœci¹ elementów.
				for (int j = 0; j < i; j++)						//	Pêtla wykonuj¹ca siê od pierwszej do wybranej pozycji (wy³¹cznie) w tablicy.
				{
					tempTable[j] = newTable[j];					//	Skopiowanie okreœlonej wartoœci komórki z poprzedniej tablicy do tablicy tymczasowej.
				}
				for (int j = i; j < iTSize; j++)				//	Pêtla wykonuj¹ca siê od wybranej pozycji do ostatniej.
				{
					tempTable[j] = newTable[j + 1];				//	Skopiowanie okreœlonej wartoœci komórki z poprzedniej tablicy do komórki o indeksie o jeden mniejszy tablicy tymczasowej.
				}
				delete[] newTable;								//	Usuniêcie zawartoœci u¿ywanej w programie tablicy.
				newTable = tempTable;							//	Skopiowanie zawartoœci tymczasowej tablicy do tablicy u¿ywanej w programie.
				tempTable = nullptr;							//	Usuniêcie zawartoœci tymczasowej tablicy.
				iTSize--;										//	Dekrementacja zmiennej przechowuj¹cej rozmiar tablicy.

				return true;
			}
		}
	}
	else
	{
		shT.empty();											//	Wyœwietlenie komunikatu o braku zawartoœci kopca.
	}
	return false;
}

void Tablica::clearAllT()										//	Usuniêcie wszystkich elementów z tablicy.
{
	if (iTSize != 0)
	{
		delete [] this->newTable;										//	Usuniêcie zawartoœci u¿ywanej w programie tablicy.
		this->newTable = nullptr;
		this->iTSize = 0;												//	Wyzerowanie zmiennej zawieraj¹cej rozmiar tablicy.
	}
	else
	{
		shT.empty();											//	Wyœwietlenie komunikatu o braku zawartoœci tablicy.
	}
}

void Tablica::displayAll()										//	Wyœwietlenie wszystkich elementów tablicy.
{
	if (iTSize != 0)
	{
		for (int i = 0; i < iTSize; i++)						//	Pêtla wykonuj¹ca siê od pierwszego do ostatniego elementu tablicy.
		{
			cout << "Element nr " << i + 1 << " = " << newTable[i] << endl;		//	Wyœwietlenie okreœlonego elementu talbicy.
		}
	}
	else
	{
		shT.empty();											//	Wyœwietlenie komunikatu o braku zawartoœci tablicy.
	}											
}

bool Tablica::displayOneValue(int iTValueDisplay)
{
	if (iTSize != 0)											//	Sprawdzenie czy kopiec ma zawartoœæ.
	{
		for (int i = 0; i < iTSize; i++)						//	Pêtla wykonuj¹ca siê od pierwszego do ostatniego elementu.
		{
			if (iTValueDisplay == newTable[i])					//	Sprawdzenie czy wartoœæ elementu pokrywa siê z wybran¹ wartoœci¹.
			{
				return true;
			}
		}
	}
	else
	{
		shT.empty();											//	Wyœwietlenie komunikatu o braku zawartoœci kopca.
	}
	return false;
}

void Tablica::displayOneIndex(int iTChoiceDisplay)				//	Wyœwietlenie elementu z wybranej pozycji.
{
	if (iTSize != 0)											//	Sprawdzenie czy struktura ma zawartoœæ.
	{
		if (iTChoiceDisplay >= 0 && iTChoiceDisplay < iTSize)	//	Sprawdzenie czy wybrana pozycja znajduje siê w tablicy.
		{
			cout << "Element nr " << iTChoiceDisplay << " ma wartosc rowna: " << newTable[iTChoiceDisplay - 1] << endl;		//	Wyœwitlenie wartoœci komórki o wybranej pozycji.
		}
		else
		{
			shT.away();
		}
	}
	else
	{
		shT.empty();
	}
}

void Tablica::testPush()
{
	int iTTPuChoice;
	cout << "Dla ilu elementow maja zostac przeprowadzone testy?";
	cin >> iTTPuChoice;

	srand(time(0));

	cout << "------------------------------------------\n"
			"Dodawanie na poczatek:\n";
	for (int i = 0; i < 100; i++)
	{
		generateElements(iTTPuChoice);
		int iTTGenerated = rand();

		auto o1 = chrono::high_resolution_clock::now();

		pushFront(iTTGenerated);

		auto o2 = chrono::high_resolution_clock::now();
		outcomeTable.tMShort(o1, o2);

		clearAllT();
	}
	cout << "------------------------------------------\n"
			"Dodawanie na koniec:\n";
	for (int i = 0; i < 100; i++)
	{
		generateElements(iTTPuChoice);
		int iTTGenerated = rand();

		auto o1 = chrono::high_resolution_clock::now();

		pushEnd(iTTGenerated);

		auto o2 = chrono::high_resolution_clock::now();
		outcomeTable.tMShort(o1, o2);

		clearAllT();
	}
	cout << "------------------------------------------\n"
			"Dodawanie w srodek:\n";
	for (int i = 0; i < 100; i++)
	{
		generateElements(iTTPuChoice);
		int iTTPuPosition = ((rand() % iTTPuChoice) + 0);
		int iTTNewMidElement = rand();

		auto o1 = chrono::high_resolution_clock::now();

		pushMiddle(iTTPuPosition, iTTNewMidElement);

		auto o2 = chrono::high_resolution_clock::now();
		outcomeTable.tMShort(o1, o2);

		clearAllT();
	}

	shT.done();
}

void Tablica::testPop()
{
	int iTTPoChoice;
	cout << "Dla ilu elementow maja zostac przeprowadzone testy?";
	cin >> iTTPoChoice;

	srand(time(0));

	cout << "------------------------------------------\n"
		"Usuwanie z poczatku:\n";
	for (int i = 0; i < 100; i++)
	{
		generateElements(iTTPoChoice);

		auto o1 = chrono::high_resolution_clock::now();

		popFront();

		auto o2 = chrono::high_resolution_clock::now();
		outcomeTable.tMShort(o1, o2);

		clearAllT();
	}
	cout << "------------------------------------------\n"
		"Usuwanie z konca:\n";
	for (int i = 0; i < 100; i++)
	{
		generateElements(iTTPoChoice);

		auto o1 = chrono::high_resolution_clock::now();

		popEnd();

		auto o2 = chrono::high_resolution_clock::now();
		outcomeTable.tMShort(o1, o2);

		clearAllT();
	}
	cout << "------------------------------------------\n"
		"Usuwanie ze srodka:\n";
	for (int i = 0; i < 100; i++)
	{
		generateElements(iTTPoChoice);

		int iTTPopValue = ((rand() % iTTPoChoice) + 0);
		auto o1 = chrono::high_resolution_clock::now();

		popMiddleValue(iTTPopValue);

		auto o2 = chrono::high_resolution_clock::now();
		outcomeTable.tMShort(o1, o2);

		clearAllT();
	}
	shT.done();
}

void Tablica::testSearch()
{
	int iTTDChoice;
	cout << "Dla ilu elementow maja zostac przeprowadzone testy?";
	cin >> iTTDChoice;

	srand(time(0));

	cout << "------------------------------------------\n"
		"Szukanie elementu:\n";
	for (int i = 0; i < 100; i++)
	{
		generateElements(iTTDChoice);

		int iTTSearchValue = rand();
		auto o1 = chrono::high_resolution_clock::now();

		displayOneValue(iTTSearchValue);

		auto o2 = chrono::high_resolution_clock::now();
		outcomeTable.tMShort(o1, o2);

		clearAllT();
	}
	shT.done();
}