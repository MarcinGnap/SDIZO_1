/*
	Klasa, kt�rej zadaniem jest tworzenie pojedy�czych
	"kom�rek" w li�cie dwukierunkowej.
*/

#pragma once
class Node
{
public:

	int iNData;
	Node *nNext, *nPrev;

	Node();
	~Node();
	Node(int data);
};