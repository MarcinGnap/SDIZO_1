#include "timeMeasurement.h"

#include <iostream>
#include <chrono>

using namespace std;

void timeMeasurement::tMOutcome(chrono::high_resolution_clock::time_point o1, chrono::high_resolution_clock::time_point o2)
{
	chrono::nanoseconds time_span = chrono::duration_cast<chrono::nanoseconds> (o2 - o1);
	cout << "\n Wykonanie operacji zajelo: " << time_span.count() << " nanosekund." << endl;
}
