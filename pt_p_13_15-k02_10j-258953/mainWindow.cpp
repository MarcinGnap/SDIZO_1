#include "mainWindow.h"

#include <iostream>
#include <stdlib.h>

using namespace std;

mainWindow::mainWindow()
{
	
}

mainWindow::~mainWindow()
{

}

void mainWindow::mainMenu()
{
	Tablica nowaTablica;		//
	Lista nowaLista;			//	Tworzenie obiekt�w struktur.
	Heap nowyKopiec;			//

	short sMChoice;

	for (;;)					//	P�tla, w kt�rej dzia�a g��wne menu.
	{
		system("CLS");

		cout << "Prosze wybrac: \n"
				"\t1.Dynamiczna tablica. \n"
				"\t2.Lista dwukierunkowa.\n"
				"\t3.Kopiec binarny(maksymalny).\n"
				"\t4.Wyjscie.\n";
		cin >> sMChoice;

		switch (sMChoice)
		{
		case 1:
		{
			nowaTablica.tableMenu();	//	Wywo�anie metody odpowiadaj�cej za menu dynamicznej tablicy.
			break;
		}
		case 2:
		{
			nowaLista.listMenu();		//	Wywo�anie metody odpowiadaj�cej za menu listy dwukierunkowej.
			break;
		}
		case 3:
		{
			nowyKopiec.heapMenu();		//	Wywo�anie metody odpowiadaj�cej za menu kopca maksymalnego.
			break;
		}
		case 4:
		{
			exit(0);					//	Wyj�cie z programu.
			break;
		}
		default:
		{
			cout << "Nie ma takiej opcji...\n"
					"Prosze wybrac cos innego...\n";
			getchar();		//	Po wybraniu innej opcji ni� jest to przewidziane wy�wietla si� komunikat 
			getchar();		//	oraz program "czeka" na naci�ni�cie klawisza "enter".
			break;			//	Wyst�puje tu podw�jny getchar() ze wzgl�du na to, i� pojedy�czy nie wykonuje swojego zadania.
		}
		}
	}
}