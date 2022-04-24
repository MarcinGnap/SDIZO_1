/*
	Klasa wykonuj�ca pomiar czasu przy wykonywaniu operacji.
*/

#include "timeMeasurement.h"

#include <iostream>
#include <chrono>
#include <fstream>

using namespace std;

//	Metoda wy�wietlaj�ca w jakim czasie (wynik podany jest w nanosekundach)
//	zosta�a wykonana operacja na podstawie podanych danych.
void timeMeasurement::tMOutcome(chrono::high_resolution_clock::time_point o1, chrono::high_resolution_clock::time_point o2)
{
	chrono::nanoseconds time_span = chrono::duration_cast<chrono::nanoseconds> (o2 - o1);
	cout << "\nWykonanie operacji zajelo " << time_span.count() << " nanosekund." << endl;
}

long long timeMeasurement::tMShort(chrono::high_resolution_clock::time_point o1, chrono::high_resolution_clock::time_point o2)
{
	chrono::nanoseconds time_span = chrono::duration_cast<chrono::nanoseconds> (o2 - o1);
	cout << "* " << time_span.count() << " nanosekund" << endl;
	fstream fTMTests("fTMTests.txt", ios::app | ios::out);
	if (fTMTests.good())
	{
		//	Zapisanie wyniku w pliku tekstowym.
		fTMTests << time_span.count() << endl;
		fTMTests.flush();
	}
	fTMTests.close();
	return time_span.count();
}