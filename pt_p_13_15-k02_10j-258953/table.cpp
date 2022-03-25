#include <iostream>

using namespace std;

struct Table
{
	unsigned int uiTIndex;
	int iTData;
	Table *next, *head;
};