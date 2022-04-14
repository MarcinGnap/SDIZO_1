#include "SH.h"

#include <iostream>

using namespace std;

void SH::cls()
{
	system("CLS");
}

void SH::done()
{
	cout << "Operacja wykonana." << endl << "Nacisnij Enter, zeby kontynuwac..." << endl;
	getchar();
	getchar();
	system("CLS");
}

void SH::noOption()
{
	cout << "Nie ma takiej opcji..." << endl << "Prosze wybrac cos innego..." << endl;
	getchar();
	getchar();
}

void SH::away()
{
	cout << "Wybrana pozycja znajduje sie poza struktura..." << endl << "Wybierz inna pozycje..." << endl;
}

void SH::opened()
{
	cout << "Plik pomyslnie otwarto..." << endl;
	getchar();
	getchar();
}

void SH::noFile()
{
	cout << "Nie udalo sie otworzyc pliku..." << endl;
	getchar();
	getchar();
	system("CLS");
}

void SH::empty()
{
	cout << "Struktura nie ma zawartosci..." << endl;
}