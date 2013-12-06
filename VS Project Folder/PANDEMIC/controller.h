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

	// Control Menus
	void startGameMenu();	// displays the main menu and calls method based on user choice.
	void settingsMenu();
	void mainGameMenu(int);
	void loadMenu();
	void exitMenu();
	bool actionMenu(int);
	bool moveMenu();
	bool buildRS();
	bool shareCard();
	bool removeDisease();
	bool cureDisease();
	bool playEvent();
	void showHands(int);

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

}

void controller::mainGameMenu(int PID) {
	Pview->infoSec(Pmodel);
	int temp = 0;
	while( temp == 0 ) {
		temp = Pview->gameMenu();
		switch(temp) {
		case 1: Pview->drawBoard(Pmodel->accessBoard(), Pmodel->getNumPlayers());
			break;
		case 2: showHands(PID);
			break;
		case 3: if(!actionMenu(Pview->showActionMenu())) temp = 0;
			break;
		case 4: exitMenu();
			break;
		default: temp = 0;
		}
	}
}

void controller::showHands(int PID) {
	for(int i = 0; i < Pmodel->getNumPlayers(); i++) {
		cout << endl << "Player " << i << ") " << endl;
		Pview->showHand(Pmodel->accessHand(i));
	}
}

void controller::exitMenu() {
	switch(Pview->showExitMenu()) {
	case 1: Pmodel->setGameEnd(true);
			return;
	case 2: return;
	}
}

// will need to be expanded to include role options (view method will too)
bool controller::actionMenu(int actionChoice) {
	switch( actionChoice ) {
	case 1: return moveMenu();
	case 2: return buildRS();
	case 3: return shareCard();
	case 4: return removeDisease();
	case 5: return cureDisease();
	case 6: return playEvent();
	default: return false;
	}
}

bool controller::moveMenu() {
	int cityD;
	cout << "Which City would you like to go to?" << endl;
	Pview->drawBoard(Pmodel->accessBoard(), Pmodel->getNumPlayers());
	cout << "Choose the number of the City." << endl;
	cin >> cityD;
	if( Pmodel->movePlayer(Pmodel->getPlayer(Pmodel->getCurrentTurn())->getCID(), cityD, Pmodel->getCurrentTurn()) ) {
		Pmodel->setActionCount(Pmodel->getActionCount() - 1);
		return true;
	}
	return false;
}

// not a big deal, move isn't even checking if a move is legal by game rules yet
bool controller::buildRS() {
	return false;
}

bool controller::shareCard() {
	int PID = 0;
	showHands(0);
	cout << "Which player would you like to take a card from?" << endl;
	cin >> PID;
	showHands(0);
	int temp = 0;
	cout << "Which card would you like to take?" << endl;
	cin >> temp;
	card tempCard = Pmodel->getPlayer(PID)->getHand()->getCard(temp);
	Pmodel->getPlayer(PID)->getHand()->discard(temp);
	Pmodel->getPlayer(Pmodel->getCurrentTurn())->addCard(tempCard);
	return false;
}

bool controller::removeDisease() {
	if(Pmodel->accessBoard()->getCity(Pmodel->getPlayer(Pmodel->getCurrentTurn())->getCID())->getVCount() > 0) {
		Pmodel->setInfection(1,Pmodel->getPlayer(Pmodel->getCurrentTurn())->getCID());
		Pmodel->setActionCount(Pmodel->getActionCount() - 1);	// decrement action count because action was performed
		return true; // return action performed
	}
	return false;
}

bool controller::cureDisease() {
	
	return false;
}

bool controller::playEvent() {
	return false;
}

/*__________________________________CONTROL ACTION METHODS__________________________________*/


void controller::newGame() {
	// build a new game, assigning the players roles and hands, and choosing who goes first. This can be handled in constructors of objects.
	while(!Pmodel->gameEnd()) {
		mainGameMenu(Pmodel->getCurrentTurn());
		Pmodel->processTurn();
	}
}

void controller::loadGame() {

}

#endif CONTROLLER_H