#include "mainWindow.h"

#include <iostream>

using namespace std;

mainWindow::mainWindow()
{
	
}

mainWindow::~mainWindow()
{

}

void mainWindow::main()
{
	Tablica nowaTablica;
	//Lista NowaLista;
	Heap nowyKopiec;
	//Tree noweDrzewo;

	short sMChoice;

	for (;;) 
	{
		system ("CLS");

		cout << "Prosze wybrac:" << endl << "1.Tablica." << endl << "2.Lista dwukierunkowa." << endl << "3.Kopiec binarny(maksymalny)." << endl << "4.Drzewo czerwono-czarne" << endl << "5.Wyjscie." << endl;
		cin >> sMChoice;

		switch (sMChoice)
		{
		case 1:
		{
			nowaTablica.tableMenu();
			break;
		}
		case 2:
		{
			//nowaLista.listMenu();
			break;
		}
		case 3:
		{
			nowyKopiec.heapMenu();
			break;
		}
		case 4:
		{
			//noweDrzewo.treeMenu();
			break;
		}
		case 5:
		{
			exit(0);
			break;
		}
		default:
		{
			cout << "Nie ma takiej opcji..." << endl << "Prosze wybrac cos innego..." << endl;
			break;
		}
		}
	}

}