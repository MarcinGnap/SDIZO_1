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
	iTSize = 0;						//	Na start strukturze dajey roziar 0.
	newTable = new int[iTSize];
}

Tablica::~Tablica()
{
	
}

void Tablica::tableMenu()			//	G³ówne menu tablicy.
{
	short sTChoiceTableMenu;		//	Zmienna potrzebna do instrukcji switch.

	for (;;)
	{
		shT.cls();

		cout << "Prosze wybrac:\n"
				"\t1.Menu dodawania.\n"
				"\t2.Menu odejmowania.\n"
				"\t3.Menu wyswietlania.\n"
				"\t4.Test menu\n"
				"\t5.Powrot\n";
		cin >> sTChoiceTableMenu;

		switch (sTChoiceTableMenu)
		{
		case 1:
		{
			pushMenu();				//	Menu dodawania do tablicy.
			break;
		}
		case 2:
		{
			popMenu();				//	Menu usuwania elementów z tablicy.
			break;
		}
		case 3:
		{
			displayMenu();			//	Menu wyœwietlania elementów tablicy.
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

void Tablica::pushMenu()			//	Menu dodawania do tablicy.
{
	short sTChoicePushMenu;			//	Menu dodawania.

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
			pushFront();			//	Dodanie elementu na pocz¹tek.
			break;
		}
		case 2:
		{
			pushEnd();				//	Dodanie elementu na koniec.
			break;
		}
		case 3:
		{
			pushMiddle();			//	Dodanie elementu w okreœlone miejsce.
			break;
		}
		case 4:
		{
			readFromFileT();		//	Odczytanie i wpisanie wartoœci z pliku tekstowego do tablicy.
			break;
		}
		case 5:
		{
			generateElements();		//	Wygenerowanie danej liczby elementów.
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

void Tablica::popMenu()				//	Menu usuwania.
{
	short sTChoicePopMenu;

	for (;;)
	{
		shT.cls();

		cout << "Prosze wybrac:\n"
				"\t1.Usuniecie elementu z poczatku struktury.\n"
				"\t2.Usuniecie elementu z konca struktury.\n"
				"\t3.Usuniecie elementu z okreslonego miejsca w struktury.\n"
				"\t4.Usuniecie wszystkich elementow ze struktury.\n"
				"\t5.Powrot.\n";
		cin >> sTChoicePopMenu;

		switch (sTChoicePopMenu)
		{
		case 1:
		{
			popFront();				//	Usuniêcie elementu z pocz¹tku tablicy.
			break;
		}
		case 2:
		{
			popEnd();				//	Usuniêcie elementu z koñca.
			break;
		}
		case 3:
		{
			popMiddle();			//	Usuniêcie elementu z podanej pozycji.
			break;
		}
		case 4:
		{
			clearAllT();			// Usuniêcie wszystkich elementów z tablicy.
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

void Tablica::displayMenu()			//	Menu wyœwietlania.
{
	short sTChoiceDisplayMenu;

	for (;;)
	{
		shT.cls();

		cout << "Prosze wybrac:\n"
				"\t1.Wyswietlenie calej zawartosci struktury.\n"
				"\t2.Wyswietlenie okreslonego elementu struktury.\n"
				"\t3.Powrot.\n";
		cin >> sTChoiceDisplayMenu;

		switch (sTChoiceDisplayMenu)
		{
		case 1:
		{
			displayAll();			//	Wyœwietlenie wszystkich elementów.
			break;
		}
		case 2:
		{
			displayOne();			// Wyœwietlenie elementu z wybranej pozycji.
			break;
		}
		case 3:
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
			"\t3.Testy wyswietlania.\n"
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

void Tablica::pushFront()			//	Dodanie elementu na pocz¹tek tablicy.
{
	int iTNewFrontElement;
	
	cout << "Podaj liczbe jaka ma byc dodana do tablicy:\n";
	cin >> iTNewFrontElement;									//	Wybór wartoœci dodawanego elementu.
	
	auto o1 = chrono::high_resolution_clock::now();				//	Pomiar czasu w momencie rozpoczêcia operacji.

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
	auto o2 = chrono::high_resolution_clock::now();				//	Pomiar czasu w momencie zakoñczenia programu.

	outcomeTable.tMOutcome(o1, o2);								//	Wyœwietlenie czasu wykonania operacji.
	
	shT.done();													//	Wyœwietlenie komunikatu o zakoñczeniu zadania oraz czekanie na naciœniêcie klawisza przez u¿ytkownika.
}

void Tablica::pushEnd()											//	Dodanie na koniec tablicy.
{
	int iTNewEndElement;

	cout << "Podaj liczbe jaka ma byc dodana do tablicy:\n";
	cin >> iTNewEndElement;										//	Wybór dodawanej wartoœci.

	auto o1 = chrono::high_resolution_clock::now();				// Pomiar czasu	w momencie rozpoczêcia operacji.

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
	auto o2 = chrono::high_resolution_clock::now();				//	Pomiar czasu w momencie zakoñczenia wykonywania operacji.

	outcomeTable.tMOutcome(o1, o2);								//	Wypisanie czasu wykonania operacji.

	shT.done();													//	Wyœwietlenie komunikatu o zakoñczeniu zadania oraz czekanie na naciœniêcie klawisza przez u¿ytkownika.
}

void Tablica::pushMiddle()
{
	int iTNewMidElement;
	int iTPushPosition;

	cout << "Podaj pozycje, na ktora ma zostac dodany element (zakladamy ze numeracja zaczyna sie od 1):\n";
	cin >> iTPushPosition;										//	Wybór pozycji (pozycja + 1 ze wzglêdu na numeracjê komórek w tablicy), na któr¹ ma zostaæ wstawiony element.

	int iTRightPush = iTPushPosition - 1;						//	Przypisanie do zmiennej prawdziwej pozycji w tablicy.

	if (iTRightPush >= 0 && iTRightPush <= iTSize)				//	Sprawdzenie czy wybrana pozycja znajduje siê w tablicy.
	{
		cout << "Podaj liczbe jaka ma byc dodana do tablicy:\n";
		cin >> iTNewMidElement;									//	Wybór wartoœci jaka ma zostaæ wpisana w okreœlone miejsce.

		auto o1 = chrono::high_resolution_clock::now();			//	Pomiar czasu w momencie rozpoczêcia operacji.
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
		auto o2 = chrono::high_resolution_clock::now();			//	Pomiar czasu w momencie zakoñczenia operacji.

		outcomeTable.tMOutcome(o1, o2);							//	Wyœwietlenie czasu wykonywania operacji.
	}
	else
	{
		shT.away();												//	Wyœwietlenie komunikatu, ¿e wybrana pozycja znajduje siê poza tablic¹.
	}
	shT.done();													//	Wyœwietlenie kounikatu o wykonaniu operacji.
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

		shT.done();												//	Wyœwietlenie komunikatu o zakoñczeniu wykonywania operacji.
	}
	else
	{
		shT.noFile();											//	Wyœwietlenie informacji o problemie z plikiem tekstowym.
	}
}

void Tablica::generateElements()								//	Wygenerowanie okreœlonej liczby elementów.
{
	int iTNumberOfGen;
	cout << "Ile elementow ma zostac wygenerowanych?\n";
	cin >> iTNumberOfGen;										//	Wybór iloœci generowanych elementów.

	auto o1 = chrono::high_resolution_clock::now();				//	Pomiar czasu w momencie rozpoczêcia operacji.

	auto tempTable = new int[iTNumberOfGen];					//	Stworzenie tymczasowej tablicy z wybran¹ iloœci¹ komórek.

	srand(time(0));

	for (int i = 0; i < iTNumberOfGen; i++)						//	Pêtla wykonuj¹ca siê wybran¹ iloœæ razy.
	{
		int iTGenerated = rand();								//	Pseudo wylosowanie elemntu i przypisanie go do zmiennej.
		tempTable[i] = iTGenerated;								//	Skopiowanie elementu do okreœlonego miejsca w tablicy.
	}
	delete[] newTable;											//	Usuniêcie zawartoœci u¿ywanej w programie tablicy.
	newTable = tempTable;										//	Skopiowanie zawartoœci tymczasowej tablicy do tablicy u¿ywanej w programie.
	tempTable = nullptr;										//	Usuniêcie zawartoœci tymczasowej tablicy.
	iTSize = iTNumberOfGen;										//	Skopiowanie numeru wygenerowanych elementów do zmiennej przechowuj¹cej rozmiar tablicy.
	auto o2 = chrono::high_resolution_clock::now();				//	Pomiar czasu w momencie zakoñczenia operacji.

	outcomeTable.tMOutcome(o1, o2);								//	Wyœwietlenie czasu wykonania operacji.

	shT.done();													//	Wyœwieltenie komunikatu o zakoñczeniu operacji.
}

void Tablica::popFront()										//	Usuniêcie elementu na pierwszym miejscu tablicy.
{
	if (iTSize != 0)											//	Instrukcja warunkowa sprawdzaj¹ca czy w tablicy s¹ elementy do usuniêcia.
	{
		auto o1 = chrono::high_resolution_clock::now();			//	Pomiar czasu w momencie rozpoczêcia operacji.
		auto tempTable = new int[iTSize - 1];					//	Stworzenie tymczasowej tablicy z now¹ iloœci¹ komórek.

		for (int i = iTSize - 1; i >= 0; i--)					//	Pêtla wykonuj¹ca siê od ostatniego elementu tablicy do drugiego.
		{
			tempTable[i] = newTable[i + 1];						//	Skopiowanie wartoœci okreœlonej komórki z porzedniej tablicy do komórki z indeksem o jeden mniejszym tablicy tymczasowej.
		}
		delete[] newTable;										//	Usuniêcie zawartoœci u¿ywanej w programie tablicy.
		newTable = tempTable;									//	Skopiowanie zawartoœci tymczasowej tablicy do tablicy u¿ywanej w programie.
		tempTable = nullptr;									//	Usuniêcie zawartoœci tymczasowej tablicy.
		iTSize--;												//	Dekrementacja zmiennej przechowuj¹cej rozmiar tablicy.
		auto o2 = chrono::high_resolution_clock::now();			//	Pomiar czasu w momencie zakoñczenia operacji.

		outcomeTable.tMOutcome(o1, o2);							//	Wyœwietlenie czasu wykonania operacji.
	}
	else
	{
		shT.empty();											//	Jeœli tablica nie ma elementów wyœwietli siê komunikat o tym zdarzeniu.
	}

	shT.done();													//	Wyœwietlenie komunikatu o zakoñczeniu wykonywania operacji.
}

void Tablica::popEnd()											//	Usuniêcie ostatniego elementu z tablicy.
{
	if (iTSize != 0)											// Sprawdzenie czy tablica ma zawartoœæ.
	{
		auto o1 = chrono::high_resolution_clock::now();			//	Pomiar czasu w momencie rozpoczêcia operacji.
		auto tempTable = new int[iTSize - 1];					//	Stworzenie tymczasowej tablicy z pomniejszon¹ liczb¹ elementów.

		for (int i = 0; i < iTSize - 1; i++)					//	Pêtla wykonuj¹ca siê od pocz¹tkowego do przed ostatniego elementu tablicy.
		{
			tempTable[i] = newTable[i];							//	Skopiowanie zawartoœæi komórki z poprzedniej tablicy do tymczasowej tablicy.
		}
		delete[] newTable;										//	Usuniêcie zawartoœci u¿ywanej w programie tablicy.
		newTable = tempTable;									//	Skopiowanie zawartoœci tymczasowej tablicy do tablicy u¿ywanej w programie.
		tempTable = nullptr;									//	Usuniêcie zawartoœci tymczasowej tablicy.
		iTSize--;												//	Dekrementacja zmiennej przechowuj¹cej rozmiar tablicy.
		auto o2 = chrono::high_resolution_clock::now();			//	Pomiar czasu w momencie zakoñczenia operacji.

		outcomeTable.tMOutcome(o1, o2);							//	Wyœwietlenie czasu wykonania operacji.
	}
	else
	{
		shT.empty();											//	Jeœli tablica nie ma elementów wyœwietli siê komunikat o tym zdarzeniu.
	}
	shT.done();													//	Wyœwietlenie komunikatu o zakoñczeniu wykonywania operacji.
}

void Tablica::popMiddle()										//	Usuniêcie elementu z wybranej pozycji tablicy.
{
	int iTPopPosition;

	cout << "Podaj pozycje, z ktorej ma zostac usuniety element (zakladamy ze numeracja zaczyna sie od 1):\n";
	cin >> iTPopPosition;										//	Wybór pozycji, z której ma zostaæ usuniêty element.

	int iTRightPop = iTPopPosition - 1;							//	Zmienna zawieraj¹ca poprawn¹ pozycjê usuwanego elementu.

	if (iTRightPop >= 0 && iTRightPop < iTSize)					//	Sprawdzenie czy wybrana pozycja znajduje siê w tablicy.
	{
		auto o1 = chrono::high_resolution_clock::now();			//	Poiar czasu w momencie rozpoczêcia operacji.
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
		auto o2 = chrono::high_resolution_clock::now();			//	Pomiar czasu w momencie zakoñczenia operacji.

		outcomeTable.tMOutcome(o1, o2);							//	Wyœwietlenie czasu wykonania operacji.
	}
	else
	{
		shT.away();												//	Wyœwietlenie komunikatu o braku wybranej pozycji w liœcie.
	}
	shT.done();													//	Wyœwietlenie komunikatu o zakoñczeniu wykonywania operacji.
}

void Tablica::clearAllT()										//	Usuniêcie wszystkich elementów z tablicy.
{
	if (iTSize != 0)
	{
		auto o1 = chrono::high_resolution_clock::now();			//	Pomiar czasu w momencie rozpoczêcia operacji.
		delete [] newTable;										//	Usuniêcie zawartoœci u¿ywanej w programie tablicy.
		newTable = nullptr;
		iTSize = 0;												//	Wyzerowanie zmiennej zawieraj¹cej rozmiar tablicy.
		auto o2 = chrono::high_resolution_clock::now();			//	Pomiar czasu w momencie zakoñczenia operacji.

		outcomeTable.tMOutcome(o1, o2);							//	Wyœwietlenie czasu wykonania operacji.
	}
	else
	{
		shT.empty();											//	Wyœwietlenie komunikatu o braku zawartoœci tablicy.
	}

	shT.done();													//	Wyœwietlenie komunikatu o zakoñczeniu wykonywania operacji.
}

void Tablica::displayAll()										//	Wyœwietlenie wszystkich elementów tablicy.
{
	if (iTSize != 0)
	{
		auto o1 = chrono::high_resolution_clock::now();			//	Pomiar czasu w momecie rozpoczêcia operacji.
		for (int i = 0; i < iTSize; i++)						//	Pêtla wykonuj¹ca siê od pierwszego do ostatniego elementu tablicy.
		{
			cout << "Element nr " << i + 1 << " = " << newTable[i] << endl;		//	Wyœwietlenie okreœlonego elementu talbicy.
		}
		auto o2 = chrono::high_resolution_clock::now();			//	Pomiar czasu w momencie zakoñczenia operacji.

		outcomeTable.tMOutcome(o1,o2);							//	Wyœwietlenie czasu wykonywania operacji.
	}
	else
	{
		shT.empty();											//	Wyœwietlenie komunikatu o braku zawartoœci tablicy.
	}
	shT.done();													//	Wyœwietlenie komunikatu o zakoñczeniu wykonywania operacji.
}

void Tablica::displayOne()										//	Wyœwietlenie elementu z wybranej pozycji.
{
	if (iTSize != 0)											//	Sprawdzenie czy struktura ma zawartoœæ.
	{
		int iTChoiceDisplay;

		cout << "Wybierz element, ktory chcesz wyswietlic (zakladamy ze numeracja zaczyna sie od 1): " << endl;
		cin >> iTChoiceDisplay;									//	Wybór pozycji, z której ma zostaæ wyœwietlony element.

		auto o1 = chrono::high_resolution_clock::now();			//	Pomiar czasu w momencie rozpoczêcia wykonywania operacji.

		if (iTChoiceDisplay >= 0 && iTChoiceDisplay < iTSize)	//	Sprawdzenie czy wybrana pozycja znajduje siê w tablicy.
		{
			cout << "Element nr " << iTChoiceDisplay << " ma wartosc rowna: " << newTable[iTChoiceDisplay - 1] << endl;		//	Wyœwitlenie wartoœci komórki o wybranej pozycji.
		}
		else
		{
			cout << "Wybranego elementu nie ma w strukturze.\n";
		}
		auto o2 = chrono::high_resolution_clock::now();			//	Pomiar czasu w momencie zakoñczenia operacji.

		outcomeTable.tMOutcome(o1, o2);							//	Wyœwietlenie czasu wykonywania operacji.
	}
	else
	{
		cout << "Struktura nie ma zawartosci...\n";
	}
	shT.done();													//	Wyœwietlenie komunikatu o zakoñczeniu wykonywania operacji.
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
		generateElementsTest(iTTPuChoice);
		
		pushFrontTest();

		clearAllTTest();
	}
	cout << "------------------------------------------\n"
			"Dodawanie na koniec:\n";
	for (int i = 0; i < 100; i++)
	{
		generateElementsTest(iTTPuChoice);

		pushEndTest();

		clearAllTTest();
	}
	cout << "------------------------------------------\n"
			"Dodawanie w srodek:\n";
	for (int i = 0; i < 100; i++)
	{
		generateElementsTest(iTTPuChoice);

		pushMiddleTest(iTTPuChoice);

		clearAllTTest();
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
		generateElementsTest(iTTPoChoice);

		popFrontTest();

		clearAllTTest();
	}
	cout << "------------------------------------------\n"
		"Usuwanie z konca:\n";
	for (int i = 0; i < 100; i++)
	{
		generateElementsTest(iTTPoChoice);

		popEndTest();

		clearAllTTest();
	}
	cout << "------------------------------------------\n"
		"Usuwanie ze srodka:\n";
	for (int i = 0; i < 100; i++)
	{
		generateElementsTest(iTTPoChoice);

		popMiddleTest(iTTPoChoice);

		clearAllTTest();
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
		generateElementsTest(iTTDChoice);

		searchTest(iTTDChoice);

		clearAllTTest();
	}
	shT.done();
}

void Tablica::generateElementsTest(int iTTPuChoice)
{
	auto *tempTable = new int[iTTPuChoice];

	

	for (int z = 0; z < iTTPuChoice; z++)
	{							
		tempTable[z] = rand();
	}
	delete[] this->newTable;											
	this->newTable = tempTable;										
	tempTable = nullptr;										
	this->iTSize = iTTPuChoice;						
}

void Tablica::clearAllTTest()
{		
	delete[] this->newTable;										
	this->iTSize = 0;
	this->newTable = nullptr;
}

void Tablica::pushFrontTest()
{
	auto o1 = chrono::high_resolution_clock::now();				

	int iTTempSize = iTSize + 1;
	auto tempTable = new int[iTSize + 1];						

	tempTable[0] = rand();
	if (iTSize != 0)
	{
		for (int i = iTTempSize; i >= 1; i--)					
		{
			tempTable[i] = newTable[i - 1];						
		}
	}
	delete[] newTable;											
	newTable = tempTable;										
	tempTable = nullptr;										
	iTSize++;													
	auto o2 = chrono::high_resolution_clock::now();			

	outcomeTable.tMShort(o1, o2);						

}

void Tablica::pushEndTest()
{
	auto o1 = chrono::high_resolution_clock::now();				

	auto tempTable = new int[iTSize + 1];						

	tempTable[iTSize] = rand();						
	if (iTSize != 0)
	{
		for (int i = 0; i < iTSize; i++)						
		{
			tempTable[i] = newTable[i];							
		}
	}
	delete[] newTable;											
	newTable = tempTable;										
	tempTable = nullptr;										
	iTSize++;													
	auto o2 = chrono::high_resolution_clock::now();				

	outcomeTable.tMShort(o1, o2);								

}

void Tablica::pushMiddleTest(int iTTPuChoice)
{
	int iTNewMidElement = rand();
										
	int iTRightPush = ((rand() % iTTPuChoice) + 0);
								

	auto o1 = chrono::high_resolution_clock::now();			
	auto tempTable = new int[iTSize + 1];					
	tempTable[iTRightPush] = iTNewMidElement;				
	for (int i = 0; i < iTRightPush; i++)					
	{
		tempTable[i] = newTable[i];							
	}
	for (int i = iTRightPush + 1; i < iTSize + 1; i++)		
	{
		tempTable[i] = newTable[i - 1];						
	}
	delete[] newTable;										
	newTable = tempTable;									
	tempTable = nullptr;									
	iTSize++;												
	auto o2 = chrono::high_resolution_clock::now();			
	outcomeTable.tMShort(o1, o2);						
}

void Tablica::popFrontTest()
{
	auto o1 = chrono::high_resolution_clock::now();			
	auto tempTable = new int[iTSize - 1];					

	for (int i = iTSize - 1; i >= 0; i--)				
	{
		tempTable[i] = newTable[i + 1];						
	}
	delete[] newTable;										
	newTable = tempTable;									
	tempTable = nullptr;									
	iTSize--;												
	auto o2 = chrono::high_resolution_clock::now();			

	outcomeTable.tMShort(o1, o2);
}

void Tablica::popEndTest()
{
	auto o1 = chrono::high_resolution_clock::now();			
	auto tempTable = new int[iTSize - 1];					

	for (int i = 0; i < iTSize - 1; i++)					
	{
		tempTable[i] = newTable[i];							
	}
	delete[] newTable;										
	newTable = tempTable;									
	tempTable = nullptr;									
	iTSize--;												
	auto o2 = chrono::high_resolution_clock::now();			

	outcomeTable.tMShort(o1, o2);

}

void Tablica::popMiddleTest(int iTTPoChoice)
{
	int iTRightPop = ((rand() % iTTPoChoice) + 0);

	auto o1 = chrono::high_resolution_clock::now();			
	auto tempTable = new int[iTSize - 1];					

	for (int i = 0; i < iTRightPop; i++)					
	{
		tempTable[i] = newTable[i];							
	}
	for (int i = iTRightPop; i < iTSize; i++)				
	{
		tempTable[i] = newTable[i + 1];						
	}
	delete[] newTable;										
	newTable = tempTable;									 
	tempTable = nullptr;									
	iTSize--;												
	auto o2 = chrono::high_resolution_clock::now();			

	outcomeTable.tMShort(o1, o2);
}

void Tablica::searchTest(int iTTDChoicev)
{
	int iTChoiceDisplay = rand();
								
	auto o1 = chrono::high_resolution_clock::now();			

	for (int s = 0; s < iTTDChoicev; s++)
	{
		if (newTable[s] == iTChoiceDisplay)
		{
			goto searched;
		}
	}
	searched:
	auto o2 = chrono::high_resolution_clock::now();			

	outcomeTable.tMShort(o1, o2);
}