#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>
#include "view.h"
#include "model.h"
#include "player.h"


class controller {
private:
	model * Pmodel;
	view * Pview;
public:
	// Constructors
	controller();
	controller(model * m, view * v);

	// Control Menus
	void startGameMenu();	// displays the main menu and calls method based on user choice.
	void settingsMenu();
	void mainGameMenu(int);
	void loadMenu();
	void exitMenu();
	void actionMenu(int);
	void moveMenu();

	// Control Actions
	void newGame();		// calls appropriate methods to build a new game and begin playing.
	void loadGame();	// builds a game from a file input, then begins play.
};

// DEFAULT CONSTRUCTOR
controller::controller() {
	Pmodel = new model();
	Pview = new view();
}
// NORMAL CONSTRUCTOR - for loading save files only
controller::controller(model * m, view * v) {
	Pmodel = m;
	Pview = v;
}

/*__________________________________CONTROL MENU METHODS__________________________________*/

// finds out which main menu option the player wants, and proceeds by calling the appropriate methods
void controller::startGameMenu() {
	switch(Pview->mainMenu()) { // calls the main menu method to retrieve user choice.
	case 1: settingsMenu(); 
		newGame();
		break;
	case 2: loadMenu(); 
		break;
	}
}
// asks for the number of players, then discovers the name of each player
void controller::settingsMenu() {
	Pmodel->setNumPlayers(Pview->numPlayer());
	for(int i = 0; i < Pmodel->getNumPlayers(); i++) {
		Pmodel->InitPlayer(Pview->namePlayer(i), "Atlanta", i, 0);
	}
	Pmodel->dealHands();
}

void controller::loadMenu() {
	Pmodel->loadGame();
}

void controller::mainGameMenu(int PID) {
	Pview->infoSec(Pmodel);
	thisPlace:
	switch(Pview->gameMenu()) {
	case 1: Pview->drawBoard(Pmodel->accessBoard(), Pmodel->getNumPlayers());
		break;
	case 2: Pview->showHand(Pmodel->accessHand(PID));
		break;
	case 3: actionMenu(Pview->showActionMenu());
		break;
	case 4: Pmodel->saveGame();
		break;
	case 5: exitMenu();
		break;
	default: goto thisPlace;
	}
}

void controller::exitMenu() {
	exit(1);

}

void controller::actionMenu(int actionChoice) {
	if(actionChoice == 1)
	{
		int cityD;
		cout<<"Which City would you like to go to?"<<endl;
		Pview->drawBoard(Pmodel->accessBoard(), Pmodel->getNumPlayers());
		cout<<"Choose the number of the City."<<endl;
		cin>>cityD;
		Pmodel->movePlayer(0, cityD, 1);}
		Pview->drawBoard(Pmodel->accessBoard(), Pmodel->getNumPlayers());

}

void controller::moveMenu() {

}

/*__________________________________CONTROL ACTION METHODS__________________________________*/


void controller::newGame() {
	// build a new game, assigning the players roles and hands, and choosing who goes first. This can be handled in constructors of objects.
	while(!Pmodel->gameEnd()) {
		mainGameMenu(Pmodel->getCurrentTurn());

	}
}

void controller::loadGame() {

}

#endif CONTROLLER_H