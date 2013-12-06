#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include "model.h"
using namespace std;

class view {
private:
public:
	view();
	// MENUS
	int mainMenu(); // cout a menu to ask the user for what their first option is
	int gameMenu();
	int showActionMenu();
	int showExitMenu();

	// INFO GATHERING
	int numPlayer();
	string namePlayer(int PID);

	// INFO DISPLAYING
	void drawBoard(board * b, int numPlayers);
	void infoSec(model *);
	void showHand(hand *);

};

view::view() {

}

/*__________________________________VIEW MENU METHODS__________________________________*/


int view::mainMenu() {
	int choice = 0;
	while(choice == 0) {
		cout << "Pandemic: Main Menu:" << endl << endl;
		cout << "Please select an option from the following: " << endl;
		cout << "1) Start a new game (press 1 then enter)" << endl;
		cout << "2) Load a game from a file (press 2 then enter)" << endl;
		cout << "3) Quit Application (press anything beside 0, 1, or 2 then enter)" << endl;
		cin >> choice;
		system("CLS");
	}
	return choice;
}

int view::gameMenu() {
	int temp = 0;
	while( temp == 0 ) {
		cout << "1) Show the game board. " << endl;
		cout << "2) Show the hands of all players. " << endl;
		cout << "3) Show the Action Menu. " << endl;
		cout << "4) Exit Game. " << endl;
		cin >> temp;
	}
	system("CLS");
	return temp;
}

int view::showActionMenu() {
	int temp = 0;
	cout << "1) Move to a city (only options in range)." << endl;
	cout << "2) Build a Research Station. " << endl;
	cout << "3) Share a card with another player. " << endl;
	cout << "4) Remove a disease counter from the current city. " << endl;
	cout << "5) Cure a disease." << endl;
	cout << "6) Play an Event Card." << endl;
	cin >> temp;
	system("CLS");
	return temp;
}

int view::showExitMenu() {
	int temp = 0;
	cout << "1) Exit without saving game." << endl;
	cout << "2) Save game and exit." << endl;
	cin >> temp;
	system("CLS");
	return temp;
}

/*__________________________________VIEW INFO GATHERING METHODS__________________________________*/


int view::numPlayer() {
	int nPlay;

	while (cout << "Please enter the amount of players:\n" && (!(cin >>nPlay) || nPlay > 4 || nPlay < 2))
	{
		cin.clear();
		string line;
		getline(cin,line);
		cout << "I am sorry, please enter number of players" << endl;
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

/*__________________________________VIEW INFO DISPLAYING METHODS__________________________________*/


void view::drawBoard(board * b, int numPlayers) {
	cout << endl << endl;
	for(int i = 0; i < 48; i++) {
		cout << i << ") " << b->getCityName(i);
		cout << " VC:" << b->getCity(i)->getVCount();
		for(int k = 0; k < numPlayers; k++) {
			if( b->getCity(i)->isPlayerHere(k) ) {
				cout << " P" << k;
			}
		}
		cout << endl << endl;
	}
}

void view::infoSec(model * M) {
	cout << endl << endl;
	cout << "Current Player: P" << M->getCurrentTurn() << " " << M->getPlayer(M->getCurrentTurn())->getName() << endl;
	cout << "Player Role: " << M->getPlayer(M->getCurrentTurn())->getRole() << endl;
	cout << "Actions Left: " << M->getActionCount() << endl;
	cout << "Player Hand total: " << M->getPlayer(M->getCurrentTurn())->getHand()->getHandSize() << endl;
	cout << "Infection Rate: " << M->accessBoard()->getInfectRate() << endl;
	cout << "Outbreak Count: " << M->accessBoard()->getOutbreakCount() << endl;
	cout << "Player Deck has " << M->accessPdeck()->getDeckSize() << " cards left." << endl << endl;
}

void view::showHand(hand * H) {
	cout << endl << endl;
	for(int i = 0; i < H->getHandSize(); i++) {
		cout << "Card " << i << ") " << H->getCard(i).getName() << endl;
	}
	cout << endl;
}

#endif VIEW_H