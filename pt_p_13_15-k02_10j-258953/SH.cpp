/*
	Klasa, której celem jest zmniejszenie objêtoœci kodu.
	Nie zmienia ona dzia³ania programu, a jedynie skraca proces pisania
	i wygl¹d wizualny kodu.
*/

#include "SH.h"

#include <iostream>
#include <stdlib.h>

using namespace std;

void SH::cls()			//	Metoda, która "czyœci" ekran.
{
	system("CLS");
}

						//	Metoda oczekuj¹ca klawisza z klawiatury.
void SH::done()			//	G³ównie wykorzystywana do "pokazania", ¿e operacja zosta³a wykonana.
{
	cout << "Operacja wykonana.\n"
			"Nacisnij Enter, zeby kontynuwac...\n";
	getchar();
	getchar();
	system("CLS");
}

void SH::noOption()		//	Metoda mówi¹ca u¿ytkownikowi, ¿e wybra³ nieistniej¹c¹ opcjê.
{
	cout << "Nie ma takiej opcji...\n"
			"Prosze wybrac cos innego...\n";
	getchar();
	getchar();
}

void SH::away()			//	Metoda mówi¹ca u¿ytkownikowi, ¿e wybrana pozycja znajduje siê poza struktur¹.
{
	cout << "Wybrana pozycja znajduje sie poza struktura...\n"
			"Wybierz inna pozycje...\n";
}

void SH::opened()		//	Metoda daj¹ca komunikat, ¿e plik zosta³ otwarty poyœlnie.
{
	cout << "Plik pomyslnie otwarto...\n";
	getchar();
	getchar();
}

void SH::noFile()		//	Metoda daj¹ca komunikat, ¿e plik nie zosta³ otwarty poyœlnie.
{
	cout << "Nie udalo sie otworzyc pliku...\n";
	getchar();
	getchar();
	system("CLS");
}

void SH::empty()		//	Metoda mówi¹ca u¿ytkownikowi, ¿e struktura nie ma zawartoœci.
{
	cout << "Struktura nie ma zawartosci...\n";
}

void SH::noIn()			//	Metoda mówi¹ca u¿ytkownikowi, ¿e wybranej wartoœci nie ma w strukturze.
{
	cout << "Wybranego elementu nie ma w strukturze.\n";
}