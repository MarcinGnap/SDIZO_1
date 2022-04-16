/*
	Klasa, której zadaniem jest tworzenie pojedyñczych
	"komórek" w liœcie dwukierunkowej.
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