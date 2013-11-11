// test

#include "View.h"

void View::updateIntro(string title)
{
	cout << title << endl;	
}

int View::updateGetNumOfPlayers()
{
	cout << "How many players? " << endl;
	int num = 0;
	cin >> num;
	cin.ignore(1000,10);
	return num;
}

void View::printNumOfPlayers(int num)
{
	cout << "Number of player: " << num << endl;
}
