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

void Tablica::tableMenu()										//	G��wne menu tablicy.
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
			popMenu();											//	Menu usuwania element�w z tablicy.
			break;
		}
		case 3:
		{
			displayMenu();										//	Menu wy�wietlania element�w tablicy.
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
			cin >> iTNewFrontElement;							//	Wyb�r warto�ci dodawanego elementu.
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpocz�cia operacji.

			pushFront(iTNewFrontElement);						//	Dodanie elementu na pocz�tek.

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zako�czenia programu.
			outcomeTable.tMOutcome(o1, o2);						//	Wy�wietlenie czasu wykonania operacji.
			shT.done();											//	Wy�wietlenie komunikatu o zako�czeniu zadania oraz czekanie na naci�ni�cie klawisza przez u�ytkownika.
			displayAll();

			break;
		}
		case 2:
		{
			int iTNewEndElement;

			cout << "Podaj liczbe jaka ma byc dodana do tablicy:\n";
			cin >> iTNewEndElement;								//	Wyb�r dodawanej warto�ci.
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpocz�cia operacji.

			pushEnd(iTNewEndElement);							//	Dodanie elementu na koniec.

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zako�czenia wykonywania operacji.
			outcomeTable.tMOutcome(o1, o2);						//	Wypisanie czasu wykonania operacji.
			displayAll();
			shT.done();											//	Wy�wietlenie komunikatu o zako�czeniu zadania oraz czekanie na naci�ni�cie klawisza przez u�ytkownika.

			break;
		}
		case 3:
		{
			int iTNewMidElement;
			int iTPushPosition;

			cout << "Podaj pozycje, na ktora ma zostac dodany element (zakladamy ze numeracja zaczyna sie od 1):\n";
			cin >> iTPushPosition;								//	Wyb�r pozycji (pozycja + 1 ze wzgl�du na numeracj� kom�rek w tablicy), na kt�r� ma zosta� wstawiony element.

			cout << "Podaj liczbe jaka ma byc dodana do tablicy:\n";
			cin >> iTNewMidElement;								//	Wyb�r warto�ci jaka ma zosta� wpisana w okre�lone miejsce.
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpocz�cia operacji.
			int iTRightPush = iTPushPosition - 1;				//	Przypisanie do zmiennej prawdziwej pozycji w tablicy.

			pushMiddle(iTRightPush, iTNewMidElement);		//	Dodanie elementu w okre�lone miejsce.

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zako�czenia operacji.
			outcomeTable.tMOutcome(o1, o2);						//	Wy�wietlenie czasu wykonywania operacji.
			displayAll();
			shT.done();											//	Wy�wietlenie kounikatu o wykonaniu operacji.

			break;
		}
		case 4:
		{
			readFromFileT();									//	Odczytanie i wpisanie warto�ci z pliku tekstowego do tablicy.
			
			displayAll();
			shT.done();											//	Wy�wietlenie komunikatu o zako�czeniu wykonywania operacji.

			break;
		}
		case 5:
		{
			int iTNumberOfGen;
			cout << "Ile elementow ma zostac wygenerowanych?\n";
			cin >> iTNumberOfGen;								//	Wyb�r ilo�ci generowanych element�w.
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpocz�cia operacji.

			srand(time(0));

			generateElements(iTNumberOfGen);					//	Wygenerowanie danej liczby element�w.

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zako�czenia operacji.
			outcomeTable.tMOutcome(o1, o2);						//	Wy�wietlenie czasu wykonania operacji.
			displayAll();
			shT.done();											//	Wy�wieltenie komunikatu o zako�czeniu operacji.
			
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
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpocz�cia operacji.

			popFront();											//	Usuni�cie elementu z pocz�tku tablicy.

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zako�czenia operacji.
			outcomeTable.tMOutcome(o1, o2);						//	Wy�wietlenie czasu wykonania operacji.
			displayAll();
			shT.done();											//	Wy�wieltenie komunikatu o zako�czeniu operacji.

			break;
		}
		case 2:
		{
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpocz�cia operacji.

			popEnd();											//	Usuni�cie elementu z ko�ca.

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zako�czenia operacji.
			outcomeTable.tMOutcome(o1, o2);						//	Wy�wietlenie czasu wykonania operacji.
			displayAll();
			shT.done();											//	Wy�wieltenie komunikatu o zako�czeniu operacji.

			break;
		}
		case 3:
		{
			int iTPopPosition;

			cout << "Podaj pozycje, z ktorej ma zostac usuniety element (zakladamy ze numeracja zaczyna sie od 1):\n";
			cin >> iTPopPosition;								//	Wyb�r pozycji, z kt�rej ma zosta� usuni�ty element.
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpocz�cia operacji.

			popMiddleIndex(iTPopPosition);						//	Usuni�cie elementu z podanej pozycji.

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zako�czenia operacji.
			outcomeTable.tMOutcome(o1, o2);						//	Wy�wietlenie czasu wykonywania operacji.
			displayAll();
			shT.done();											//	Wy�wieltenie komunikatu o zako�czeniu operacji.

			break;
		}case 4:
		{
			int iTPopValue;

			cout << "Podaj wartosc, jaka ma zostac usunieta z tablicy:\n";
			cin >> iTPopValue;									//	Wyb�r pozycji, z kt�rej ma zosta� usuni�ty element.
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpocz�cia operacji.

			if (popMiddleValue(iTPopValue) == true)				//	Usuni�cie wskazanego elementu listy.
			{
				cout << "Wybrany element zostal usuniety ze struktury.\n";
			}
			else
			{
				shT.noIn();
			}
			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zako�czenia operacji.
			outcomeTable.tMOutcome(o1, o2);						//	Wy�wietlenie czasu wykonywania operacji.
			displayAll();
			shT.done();											//	Wy�wieltenie komunikatu o zako�czeniu operacji.

			break;
		}
		case 5:
		{
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpocz�cia operacji.

			clearAllT();										// Usuni�cie wszystkich element�w z tablicy.

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zako�czenia operacji.
			outcomeTable.tMOutcome(o1, o2);						//	Wy�wietlenie czasu wykonania operacji.
			displayAll();
			shT.done();											//	Wy�wieltenie komunikatu o zako�czeniu operacji.

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

void Tablica::displayMenu()										//	Menu wy�wietlania.
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
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momecie rozpocz�cia operacji.

			displayAll();										//	Wy�wietlenie wszystkich element�w.

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zako�czenia operacji.
			outcomeTable.tMOutcome(o1, o2);						//	Wy�wietlenie czasu wykonywania operacji.
			shT.done();
			break;
		}
		case 2:
		{
			int iTValueDisplay;

			cout << "Wybierz element, ktory chcesz wyswietlic (zakladamy ze numeracja zaczyna sie od 1): " << endl;
			cin >> iTValueDisplay;								//	Wyb�r warto�ci, jaka ma zosta� znaleziona w strukturze.
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momecie rozpocz�cia operacji.

			if (displayOneValue(iTValueDisplay) == true)
			{
				cout << "Wybrany element " << iTValueDisplay << " znajduje sie w strukturze.\n";	//	Wy�wietlenie wybranego elementu.
			}
			else
			{
				shT.noIn();
			}
			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zako�czenia operacji.
			outcomeTable.tMOutcome(o1, o2);						//	Wy�wietlenie czasu wykonywania operacji.
			shT.done();
			break;
		}
		case 3:
		{
			int iTChoiceDisplay;

			cout << "Wybierz element, ktory chcesz wyswietlic (zakladamy ze numeracja zaczyna sie od 1): " << endl;
			cin >> iTChoiceDisplay;								//	Wyb�r pozycji, z kt�rej ma zosta� wy�wietlony element.
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpocz�cia wykonywania operacji.

			displayOneIndex(iTChoiceDisplay);					//	Wy�wietlenie elementu z wybranej pozycji.

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zako�czenia operacji.
			outcomeTable.tMOutcome(o1, o2);						//	Wy�wietlenie czasu wykonywania operacji.
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

void Tablica::pushFront(int iTNewFrontElement)					//	Dodanie elementu na pocz�tek tablicy.
{
	int iTTempSize = iTSize + 1;
	auto tempTable = new int[iTSize + 1];						//	Tworzenie tymczasowej tablicy z nowym rozmiarem.
	
	tempTable[0] = iTNewFrontElement;							//	Przypisanie dodawanego elementu na odpowiednie miejsce do tymczasowej tablicy.
	if (iTSize != 0)
	{
		for (int i = iTTempSize; i >= 1; i--)					//	P�tla wykonuj�ca si� od ostatniego elementu tablicy do pierwszego.
		{
			tempTable[i] = newTable[i - 1];						//	Przypisanie elementu z tablicy poprzedniej do tablicy tymczasowej na nowe miejsce.
		}
	}
	delete [] newTable;											//	Usuni�cie zawarto�ci poprzedniej tablicy.
	newTable = tempTable;										//	Skopiowanie zawarto�ci tymczasowej tablicy do poprzedniej tablicy, kt�ra u�ywania jest w programie.
	tempTable = nullptr;										//	Usuni�cie tymczasowej tablicy.
	iTSize++;													//	Powi�kszenie rozmiaru tablicy o 1.
}

void Tablica::pushEnd(int iTNewEndElement)						//	Dodanie na koniec tablicy.
{
	auto tempTable = new int[iTSize + 1];						//	Stworzenie tymczasowej tablicy z powi�kszonym rozmiarem.

	tempTable[iTSize] = iTNewEndElement;						//	Przypisanie dodawanego elementu na ostatnie miejsce tymczasowej tablicy.
	if (iTSize != 0)
	{
		for (int i = 0; i < iTSize; i++)						//	P�tla wykonuj�ca si� od pierwszego do ostatniego elementu w porzedniej tablicy.
		{
			tempTable[i] = newTable[i];							//	Przypisanie ka�dego elementu z poprzedniej tablicy do tymczasowej tablicy.
		}
	}
	delete [] newTable;											//	Usuni�cie zawarto�ci poprzedniej tablicy.
	newTable = tempTable;										//	Skopiowanie zawarto�ci tymczasowej tablicy do tablicy u�uwanej w programie.
	tempTable = nullptr;										//	Usuni�cie tymczasowej tablicy.
	iTSize++;													//	Powi�kszenie rozmiaru o 1.
}

void Tablica::pushMiddle(int iTRightPush, int iTNewMidElement)
{
	if (iTRightPush >= 0 && iTRightPush <= iTSize)				//	Sprawdzenie czy wybrana pozycja znajduje si� w tablicy.
	{
		auto tempTable = new int[iTSize + 1];					//	Stworzenie tymczasowej tablicy z powi�kszon� liczb� element�w.
		tempTable[iTRightPush] = iTNewMidElement;				//	Przypisanie wybranej warto�ci na wybran� pozycj� w tablicy.
		for (int i = 0; i < iTRightPush; i++)					//	P�tla wykonuj�ca si� od elementu pocz�tkowego do pozycji, kt�r� wybra� u�ytkownik.
		{
			tempTable[i] = newTable[i];							//	Przypisanie danych element�w z poprzedniej tablicy do tymczasowej tablicy.
		}
		for (int i = iTRightPush + 1; i < iTSize + 1; i++)		//	P�tla wykonuj�ca si� od wybranej poprzednio pozycji do ostatniego elementu.
		{
			tempTable[i] = newTable[i-1];						//	Przypisanie danych element�w z poprzedniej tablicy do tymczasowej tablicy.
		}
		delete [] newTable;										//	Usuni�cie zawarto�ci u�ywanej w programie tablicy.
		newTable = tempTable;									//	Skopiowanie zawarto�ci tymczasowej tablicy do tablicy u�ywanej w programie.
		tempTable = nullptr;									//	Usuni�cie zawarto�ci tymczasowej tablicy.
		iTSize++;												//	Inkrementacja zmiennej przechowuj�cej rozmiar tablicy.
	}
	else
	{
		shT.away();												//	Wy�wietlenie komunikatu, �e wybrana pozycja znajduje si� poza tablic�.
	}
}

void Tablica::readFromFileT()									//	Odczyt i przypisanie warto�ci z pliku tekstowego do tablicy.
{
	ifstream ifTFile("dane.txt", ios::in);						//	Deklaracja pliku o nazwie "dane.txt" w trybie do odczytu.
	if (ifTFile.good())											//	Sprawdzenie czy plik otworzy� si� pomy�lnie.
	{
		shT.opened();											//	Wy�wietlenie komunikatu, �e plik zosta� otwarty.

		auto o1 = chrono::high_resolution_clock::now();			//	Pomiar czasu w momencie rozpocz�cia operacji.
		string sTLineCountBuffer;								//	Stworzenie zmiennej przechowyj�cej ilo�� odczytywanych element�w.
		getline(ifTFile, sTLineCountBuffer);					//	Odczytanie pierwszej linijki pliku tekstowego, w kt�rej wed�ug zamierze� ma by� ilo�� odczytywanych element�w.
		int iTLineCount = stoi(sTLineCountBuffer);				//	Zmienienie typu odczytanego elementu na liczby ca�kowite.
		iTSize = iTLineCount;									//	Zmienienie warto�ci zmiennej przechowuj�cej rozmiar tablicy na nowy rozmiar.
		cout << "Ilosc elementow przekazanych do struktury: " << iTLineCount << endl;
		
		auto tempTable = new int[iTSize];						//	Stworzenie tymczasowej tablicy z okre�lon� ilo�ci� element�w.

		for (int i = 1; i <= iTLineCount; i++)					//	P�tla wykonuj�ca si� od pierwszego pobieranego elementu z pliku tekstowego do ostatniego.
		{
			string sTLineValueBuffer;							//	Stworzenie zmiennej przechowuj�cej odczytywany element.
			getline(ifTFile, sTLineValueBuffer);				//	Odczytanie elementu z pliku tekstowego.
			
			int iTLineValue = stoi(sTLineValueBuffer);			//	Konwersja odczytanego elementu na typ ca�kowity 4-bajtowy.

			tempTable[i-1] = iTLineValue;						//	Skopiowanie odczytanej warto�ci do okre�lonej kom�rki w tymczasowej tablicy.
		}

		delete[] newTable;										//	Usuni�cie zawarto�ci u�ywanej w programie tablicy.
		newTable = tempTable;									//	Skopiowanie zawarto�ci tymczasowej tablicy do tablicy u�ywanej w programie.
		tempTable = nullptr;									//	Usuni�cie zawarto�ci tymczasowej tablicy.

		ifTFile.close();										//	Zamkni�cie pliku.

		auto o2 = chrono::high_resolution_clock::now();			//	Pomiar czasu w momecie zako�czenia operacji.

		outcomeTable.tMOutcome(o1, o2);							//	Wy�wietlenie czasu wykonywania operacji.
	}
	else
	{
		shT.noFile();											//	Wy�wietlenie informacji o problemie z plikiem tekstowym.
	}
}

void Tablica::generateElements(int iTNumberOfGen)				//	Wygenerowanie okre�lonej liczby element�w.
{
	auto tempTable = new int[iTNumberOfGen];					//	Stworzenie tymczasowej tablicy z wybran� ilo�ci� kom�rek.

	for (int i = 0; i < iTNumberOfGen; i++)						//	P�tla wykonuj�ca si� wybran� ilo�� razy.
	{
		tempTable[i] = rand();									//	Pseudo wylosowanie elemntu i przypisanie go do zmiennej.
	}
	delete[] this->newTable;									//	Usuni�cie zawarto�ci u�ywanej w programie tablicy.
	this->newTable = tempTable;									//	Skopiowanie zawarto�ci tymczasowej tablicy do tablicy u�ywanej w programie.
	tempTable = nullptr;										//	Usuni�cie zawarto�ci tymczasowej tablicy.
	this->iTSize = iTNumberOfGen;								//	Skopiowanie numeru wygenerowanych element�w do zmiennej przechowuj�cej rozmiar tablicy.
}

void Tablica::popFront()										//	Usuni�cie elementu na pierwszym miejscu tablicy.
{
	if (iTSize != 0)											//	Instrukcja warunkowa sprawdzaj�ca czy w tablicy s� elementy do usuni�cia.
	{
		auto tempTable = new int[iTSize - 1];					//	Stworzenie tymczasowej tablicy z now� ilo�ci� kom�rek.

		for (int i = iTSize - 1; i >= 0; i--)					//	P�tla wykonuj�ca si� od ostatniego elementu tablicy do drugiego.
		{
			tempTable[i] = newTable[i + 1];						//	Skopiowanie warto�ci okre�lonej kom�rki z porzedniej tablicy do kom�rki z indeksem o jeden mniejszym tablicy tymczasowej.
		}
		delete[] newTable;										//	Usuni�cie zawarto�ci u�ywanej w programie tablicy.
		newTable = tempTable;									//	Skopiowanie zawarto�ci tymczasowej tablicy do tablicy u�ywanej w programie.
		tempTable = nullptr;									//	Usuni�cie zawarto�ci tymczasowej tablicy.
		iTSize--;												//	Dekrementacja zmiennej przechowuj�cej rozmiar tablicy.
	}
	else
	{
		shT.empty();											//	Je�li tablica nie ma element�w wy�wietli si� komunikat o tym zdarzeniu.
	}
}

void Tablica::popEnd()											//	Usuni�cie ostatniego elementu z tablicy.
{
	if (iTSize != 0)											// Sprawdzenie czy tablica ma zawarto��.
	{
		auto tempTable = new int[iTSize - 1];					//	Stworzenie tymczasowej tablicy z pomniejszon� liczb� element�w.

		for (int i = 0; i < iTSize - 1; i++)					//	P�tla wykonuj�ca si� od pocz�tkowego do przed ostatniego elementu tablicy.
		{
			tempTable[i] = newTable[i];							//	Skopiowanie zawarto��i kom�rki z poprzedniej tablicy do tymczasowej tablicy.
		}
		delete[] newTable;										//	Usuni�cie zawarto�ci u�ywanej w programie tablicy.
		newTable = tempTable;									//	Skopiowanie zawarto�ci tymczasowej tablicy do tablicy u�ywanej w programie.
		tempTable = nullptr;									//	Usuni�cie zawarto�ci tymczasowej tablicy.
		iTSize--;												//	Dekrementacja zmiennej przechowuj�cej rozmiar tablicy.
	}
	else
	{
		shT.empty();											//	Je�li tablica nie ma element�w wy�wietli si� komunikat o tym zdarzeniu.
	}
}

void Tablica::popMiddleIndex(int iTPopPosition)					//	Usuni�cie elementu z wybranej pozycji tablicy.
{
	int iTRightPop = iTPopPosition - 1;							//	Zmienna zawieraj�ca poprawn� pozycj� usuwanego elementu.

	if (iTRightPop >= 0 && iTRightPop < iTSize)					//	Sprawdzenie czy wybrana pozycja znajduje si� w tablicy.
	{
		auto tempTable = new int[iTSize - 1];					//	Stworzenie tymczasowej tablicy z pomniejszon� ilo�ci� element�w.

		for (int i = 0; i < iTRightPop; i++)					//	P�tla wykonuj�ca si� od pierwszej do wybranej pozycji (wy��cznie) w tablicy.
		{
			tempTable[i] = newTable[i];							//	Skopiowanie okre�lonej warto�ci kom�rki z poprzedniej tablicy do tablicy tymczasowej.
		}
		for (int i = iTRightPop; i < iTSize; i++)				//	P�tla wykonuj�ca si� od wybranej pozycji do ostatniej.
		{
			tempTable[i] = newTable[i+1];						//	Skopiowanie okre�lonej warto�ci kom�rki z poprzedniej tablicy do kom�rki o indeksie o jeden mniejszy tablicy tymczasowej.
		}
		delete[] newTable;										//	Usuni�cie zawarto�ci u�ywanej w programie tablicy.
		newTable = tempTable;									//	Skopiowanie zawarto�ci tymczasowej tablicy do tablicy u�ywanej w programie.
		tempTable = nullptr;									//	Usuni�cie zawarto�ci tymczasowej tablicy.
		iTSize--;												//	Dekrementacja zmiennej przechowuj�cej rozmiar tablicy.
	}
	else
	{
		shT.away();												//	Wy�wietlenie komunikatu o braku wybranej pozycji w li�cie.
	}
}

bool Tablica::popMiddleValue(int iTPopValue)
{
	if (iTSize != 0)											//	Sprawdzenie czy kopiec ma zawarto��.
	{
		for (int i = 0; i < iTSize; i++)						//	P�tla wykonuj�ca si� od pierwszego do ostatniego elementu.
		{
			if (iTPopValue == newTable[i])						//	Sprawdzenie czy warto�� elementu pokrywa si� z wybran� warto�ci�.
			{
				auto tempTable = new int[iTSize - 1];			//	Stworzenie tymczasowej tablicy z pomniejszon� ilo�ci� element�w.
				for (int j = 0; j < i; j++)						//	P�tla wykonuj�ca si� od pierwszej do wybranej pozycji (wy��cznie) w tablicy.
				{
					tempTable[j] = newTable[j];					//	Skopiowanie okre�lonej warto�ci kom�rki z poprzedniej tablicy do tablicy tymczasowej.
				}
				for (int j = i; j < iTSize; j++)				//	P�tla wykonuj�ca si� od wybranej pozycji do ostatniej.
				{
					tempTable[j] = newTable[j + 1];				//	Skopiowanie okre�lonej warto�ci kom�rki z poprzedniej tablicy do kom�rki o indeksie o jeden mniejszy tablicy tymczasowej.
				}
				delete[] newTable;								//	Usuni�cie zawarto�ci u�ywanej w programie tablicy.
				newTable = tempTable;							//	Skopiowanie zawarto�ci tymczasowej tablicy do tablicy u�ywanej w programie.
				tempTable = nullptr;							//	Usuni�cie zawarto�ci tymczasowej tablicy.
				iTSize--;										//	Dekrementacja zmiennej przechowuj�cej rozmiar tablicy.

				return true;
			}
		}
	}
	else
	{
		shT.empty();											//	Wy�wietlenie komunikatu o braku zawarto�ci kopca.
	}
	return false;
}

void Tablica::clearAllT()										//	Usuni�cie wszystkich element�w z tablicy.
{
	if (iTSize != 0)
	{
		delete [] this->newTable;										//	Usuni�cie zawarto�ci u�ywanej w programie tablicy.
		this->newTable = nullptr;
		this->iTSize = 0;												//	Wyzerowanie zmiennej zawieraj�cej rozmiar tablicy.
	}
	else
	{
		shT.empty();											//	Wy�wietlenie komunikatu o braku zawarto�ci tablicy.
	}
}

void Tablica::displayAll()										//	Wy�wietlenie wszystkich element�w tablicy.
{
	if (iTSize != 0)
	{
		for (int i = 0; i < iTSize; i++)						//	P�tla wykonuj�ca si� od pierwszego do ostatniego elementu tablicy.
		{
			cout << "Element nr " << i + 1 << " = " << newTable[i] << endl;		//	Wy�wietlenie okre�lonego elementu talbicy.
		}
	}
	else
	{
		shT.empty();											//	Wy�wietlenie komunikatu o braku zawarto�ci tablicy.
	}											
}

bool Tablica::displayOneValue(int iTValueDisplay)
{
	if (iTSize != 0)											//	Sprawdzenie czy kopiec ma zawarto��.
	{
		for (int i = 0; i < iTSize; i++)						//	P�tla wykonuj�ca si� od pierwszego do ostatniego elementu.
		{
			if (iTValueDisplay == newTable[i])					//	Sprawdzenie czy warto�� elementu pokrywa si� z wybran� warto�ci�.
			{
				return true;
			}
		}
	}
	else
	{
		shT.empty();											//	Wy�wietlenie komunikatu o braku zawarto�ci kopca.
	}
	return false;
}

void Tablica::displayOneIndex(int iTChoiceDisplay)				//	Wy�wietlenie elementu z wybranej pozycji.
{
	if (iTSize != 0)											//	Sprawdzenie czy struktura ma zawarto��.
	{
		if (iTChoiceDisplay >= 0 && iTChoiceDisplay < iTSize)	//	Sprawdzenie czy wybrana pozycja znajduje si� w tablicy.
		{
			cout << "Element nr " << iTChoiceDisplay << " ma wartosc rowna: " << newTable[iTChoiceDisplay - 1] << endl;		//	Wy�witlenie warto�ci kom�rki o wybranej pozycji.
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