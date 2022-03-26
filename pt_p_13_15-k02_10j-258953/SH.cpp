#include "SH.h"

#include <iostream>

using namespace std;

void SH::proceed()
{
	cout << "Operacja wykonana." << endl << "Nacisnij Enter, zeby kontynuwac..." << endl;
	getchar();
	system("CLS");
}

void SH::cls()
{
	system("CLS");
}

void SH::outOfChoice()
{
	cout << "Nie ma takiej opcji..." << endl << "Prosze wybrac cos innego..." << endl;
	getchar();
}