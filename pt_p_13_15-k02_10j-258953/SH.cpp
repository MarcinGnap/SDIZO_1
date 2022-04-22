/*
	Klasa, kt�rej celem jest zmniejszenie obj�to�ci kodu.
	Nie zmienia ona dzia�ania programu, a jedynie skraca proces pisania
	i wygl�d wizualny kodu.
*/

#include "SH.h"

#include <iostream>
#include <stdlib.h>

using namespace std;

void SH::cls()			//	Metoda, kt�ra "czy�ci" ekran.
{
	system("CLS");
}

						//	Metoda oczekuj�ca klawisza z klawiatury.
void SH::done()			//	G��wnie wykorzystywana do "pokazania", �e operacja zosta�a wykonana.
{
	cout << "Operacja wykonana.\n"
			"Nacisnij Enter, zeby kontynuwac...\n";
	getchar();
	getchar();
	system("CLS");
}

void SH::noOption()		//	Metoda m�wi�ca u�ytkownikowi, �e wybra� nieistniej�c� opcj�.
{
	cout << "Nie ma takiej opcji...\n"
			"Prosze wybrac cos innego...\n";
	getchar();
	getchar();
}

void SH::away()			//	Metoda m�wi�ca u�ytkownikowi, �e wybrana pozycja znajduje si� poza struktur�.
{
	cout << "Wybrana pozycja znajduje sie poza struktura...\n"
			"Wybierz inna pozycje...\n";
}

void SH::opened()		//	Metoda daj�ca komunikat, �e plik zosta� otwarty poy�lnie.
{
	cout << "Plik pomyslnie otwarto...\n";
	getchar();
	getchar();
}

void SH::noFile()		//	Metoda daj�ca komunikat, �e plik nie zosta� otwarty poy�lnie.
{
	cout << "Nie udalo sie otworzyc pliku...\n";
	getchar();
	getchar();
	system("CLS");
}

void SH::empty()		//	Metoda m�wi�ca u�ytkownikowi, �e struktura nie ma zawarto�ci.
{
	cout << "Struktura nie ma zawartosci...\n";
}

void SH::noIn()			//	Metoda m�wi�ca u�ytkownikowi, �e wybranej warto�ci nie ma w strukturze.
{
	cout << "Wybranego elementu nie ma w strukturze.\n";
}