#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>
#include "view.h"
#include "model.h"


class controller {
private:
	model * Pmodel;
	view * Pview;
public:
	// Constructors
	controller();
	controller(model * m, view * v);

	// APP RUNNING
	void startGame();	// displays the main menu and calls method based on user choice.
	void settingsMenu();
	void loadMenu();
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
// finds out which main menu option the player wants, and proceeds by calling the appropriate methods
void controller::startGame() {
	int MenuChoice = Pview->mainMenu(); // calls the main menu method to retrieve user choice.
	switch(MenuChoice) {
	case 1: settingsMenu(); break;
	case 2: loadMenu(); break;
	}
}
// asks for the number of players, then discovers the name of each player
void controller::settingsMenu() {
	Pmodel->setNumPlayers(Pview->numPlayer());
	for(int i = 0; i < Pmodel->getNumPlayers(); i++) {
		Pmodel->InitPlayer(Pview->namePlayer(i), "Atlanta", i, 0);
	}
	newGame();
}

void controller::loadMenu() {

}

void controller::newGame() {
	Pview->drawBoard(Pmodel->accessBoard(), Pmodel->getNumPlayers());

}

void controller::loadGame() {

}

#endif CONTROLLER_H