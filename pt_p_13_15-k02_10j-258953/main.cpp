#include "mainWindow.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "Starting..." << endl << endl;
	cout << "Press Enter to continue..." << endl;
	getchar();
	system("CLS");

	mainWindow noweOkno;	//Tworzenie obiektu obs�uguj�cego wzystkie struktury.

	noweOkno.mainMenu();	//Wywo�anie metody g��wnego menu.

	return 0;
}