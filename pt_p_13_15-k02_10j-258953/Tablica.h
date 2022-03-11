#pragma once
class Tablica
{
	short sTChoiceTableMenu;

	Tablica();
	~Tablica();

	void tableMenu();

	void pushMenu();
	void popMenu();
	void displayMenu();

	void pushFront();
	void pushEnd();
	void pushMiddle();

	void popFront();
	void popEnd();
	void popMiddle();

	void displayAll();
	void displayOne();
};