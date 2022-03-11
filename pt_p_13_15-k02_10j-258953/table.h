#pragma once
class table
{
	int iTElement;

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