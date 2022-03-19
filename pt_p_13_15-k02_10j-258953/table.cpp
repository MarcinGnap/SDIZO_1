#include <iostream>

using namespace std;

struct Table
{
	unsigned int uiTIndex;
	int iTData;
    unsigned int *next, *prev;
};