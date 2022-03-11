#include <iostream>

using namespace std;

struct Table
{
	unsigned int uiTIndex, uiTSize;
	int iTData;
	Table *next;
};