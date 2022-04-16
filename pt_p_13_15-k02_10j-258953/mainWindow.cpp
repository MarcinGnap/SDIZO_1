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
	Lista nowaLista;			//	Tworzenie obiektów struktur.
	Heap nowyKopiec;			//

	short sMChoice;

	for (;;)					//	Pêtla, w której dzia³a g³ówne menu.
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
			nowaTablica.tableMenu();	//	Wywo³anie metody odpowiadaj¹cej za menu dynamicznej tablicy.
			break;
		}
		case 2:
		{
			nowaLista.listMenu();		//	Wywo³anie metody odpowiadaj¹cej za menu listy dwukierunkowej.
			break;
		}
		case 3:
		{
			nowyKopiec.heapMenu();		//	Wywo³anie metody odpowiadaj¹cej za menu kopca maksymalnego.
			break;
		}
		case 4:
		{
			exit(0);					//	Wyjœcie z programu.
			break;
		}
		default:
		{
			cout << "Nie ma takiej opcji...\n"
					"Prosze wybrac cos innego...\n";
			getchar();		//	Po wybraniu innej opcji ni¿ jest to przewidziane wyœwietla siê komunikat 
			getchar();		//	oraz program "czeka" na naciœniêcie klawisza "enter".
			break;			//	Wystêpuje tu podwójny getchar() ze wzglêdu na to, i¿ pojedyñczy nie wykonuje swojego zadania.
		}
		}
	}
}