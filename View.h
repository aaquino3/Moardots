#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include "model.h"
using namespace std;

class view {
private:
public:
	view();
	int mainMenu(); // cout a menu to ask the user for what their first option is
	int numPlayer();
	string namePlayer(int PID);
	void drawBoard(board * b, int numPlayers);
};

view::view() {

}

int view::mainMenu() {
	int choice = 0;
	while(choice == 0) {
		cout << "Pandemic: Main Menu:" << endl<<endl;
		cout << "Please select an option from the following: " << endl;
		cout << "1) Start a new game (press 1 then enter)" << endl;
		cout << "2) Load a game from a file (press 2 then enter)" << endl;
		cout << "3) Quit Application (press anything beside 0, 1, or 2 then enter)" << endl;
		cin >> choice;
		system("CLS");
	}
	return choice;
}

int view::numPlayer() {
	int nPlay = 0;
	while( nPlay == 0 ) {
		cout << "How many players will there be?" << endl;
		cin >> nPlay;
		if(nPlay > 4 || nPlay < 2) {
			nPlay = 0;
		}
		system("CLS");
	}
	return nPlay;
}

string view::namePlayer(int PID) {
	string PlayerName = "";
	while( PlayerName == "" ) {
		cout << "What is the name of Player" << PID << " :" << endl;
		cin >> PlayerName;
		system("CLS");
	}
	return PlayerName;
}

void view::drawBoard(board * b, int numPlayers) {
	cout << endl << endl;
	for(int i = 0; i < 4; i++) {
		cout << i << ") " << b->getCityName(i);
		for(int k = 0; k < numPlayers; k++) {
			if( b->getCity(i)->isPlayerHere(k) ) {
				cout << " P" << k;
			}
		}
		cout << endl;
	}
}

#endif VIEW_H