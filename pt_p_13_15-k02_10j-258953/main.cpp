#include "mainWindow.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "Starting..." << endl << endl;
	cout << "Press Enter to continue..." << endl;
	getchar();
	system("CLS");

	mainWindow noweOkno;	//Tworzenie obiektu obs³uguj¹cego wzystkie struktury.

	noweOkno.mainMenu();	//Wywo³anie metody g³ównego menu.

	return 0;
}