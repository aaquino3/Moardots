#ifndef MODEL_H
#define MODEL_H


#include "player.h"
#include "deck.h"
#include "hand.h"
#include "board.h"

class model {
private:
	board * Pboard;
	deck * Pdeck;	// player deck
	deck * Ideck;	// infection deck

	int numPlayers;
	player * P1;
	player * P2;
	player * P3;
	player * P4;

	int currentTurn;
	int actionCount;
	bool gameEnds;
	bool roleList[7];
	int infectionPool[4];
	bool infectionCures[4];
public:
	model();

	// model-side maniupation methods
	void InitPlayer(string Pname, string Plocation, int ID, int CID);
	void dealHands();
	void setNumPlayers(int nPlayers) { numPlayers = nPlayers; }
	bool movePlayer(int, int, int);
	void setGameEnd(bool flag) { gameEnds = flag; }
	void setActionCount(int AC) { actionCount = AC; }
	void setupGame();
	void setInfection(int,int);
	void processTurn();
	void cureDisease();

	// model-side access methods
	player * getPlayer(int ID);		// allows passingo a player object to the controller for a given turn
	string getCityNames(int CID) { return Pboard->getCityName(CID); } // allows the passing of city names to the controller
	int getNumPlayers() { return numPlayers; }
	board * accessBoard() { return Pboard; }
	hand * accessHand(int PID);
	deck * accessPdeck() { return Pdeck; }
	bool gameEnd() { return gameEnds; }
	int getCurrentTurn() {return currentTurn; }
	int getActionCount() { return actionCount; }
};

// DEFAULT CONSTRUCTOR
model::model() {
	Pboard = new board();
	Pdeck = new deck(0);
	Ideck = new deck(1);

	numPlayers = 0;
	currentTurn = 0;
	actionCount = 4;
	gameEnds = false;

	Pboard->setIRate(0);
	Pboard->setOCount(0);

	for(int i = 0; i < 7; i++) {
		roleList[i] = true;
	}
	for(int i = 0; i < 4; i++) {
		infectionPool[i] = 24;
		infectionCures[i] = false;
	}

	setupGame();
}


/*__________________________________MODEL MANIPULATION METHODS__________________________________*/

// constructs the player of the given ID, with the name and location entered.
void model::InitPlayer(string Pname, string Plocation, int ID, int CID) {
	Pboard->getCity(CID)->setPlayer(ID,true);
	switch(ID) {
	case 0: P1 = new player(Pname, Plocation, ID, CID);
		break;
	case 1: P2 = new player(Pname, Plocation, ID, CID);
		break;
	case 2: P3 = new player(Pname, Plocation, ID, CID);
		break;
	case 3: P4 = new player(Pname, Plocation, ID, CID);
	}
}

void model::dealHands() {
	int numCards = 4;
	if( numPlayers == 3 ) numCards = 3;
	else if( numPlayers == 4 ) numCards = 2;
	for(int k = 0; k < numPlayers; k++) {
		for(int i = 0; i < numCards; i++) {
			accessHand(k)->addCard(Pdeck->dealCard());
		}
	}
}

// evaluates if the player can move from/to a given city, and then changes the city information and
// player information accordingly if so, otherwise returns false to declare no movement.
bool model::movePlayer(int fromCID, int toCID, int PID) {
	city * fromCity = Pboard->getCity(fromCID);	// get the city object holding the city of fromCID
	city * toCity = Pboard->getCity(toCID);		// get the city object holding the city of toCID
	player * tempPlayer = this->getPlayer(PID);	// get the current player object
	if(!fromCity || !toCity || !tempPlayer) return false; // if any of the given method return a NULL, an error has occured.
	if(fromCity->isPlayerHere(PID)) {		// insure that the player is in the chosen from city
		fromCity->setPlayer(PID, false);	// remove the player value from the fromCity
		toCity->setPlayer(PID, true);		// add the player value to the toCity
		tempPlayer->setLocation(toCity->getName(), toCID);	// change the player's internal location data
		return true;	// signal to the client that the move was completed
	}
	return false; // signal that no move was made, and that there was an error
}

// sets up a new game
void model::setupGame() {
	// setup the infections on the board
	for(int i = 3; i > 0; i--) {
		for(int j = 0; j < 3; j++) {
			setInfection(i,Ideck->dealCard().getCity());
		}
	}
}

void model::setInfection(int changeAmount, int CID) {
	Pboard->getCity(CID)->setVCount(Pboard->getCity(CID)->getVCount() + changeAmount);
	infectionPool[Pboard->getCity(CID)->getVType()] -= changeAmount;
}

void model::processTurn() {
	if(actionCount == 0) {
		getPlayer(currentTurn)->addCard(Pdeck->dealCard());
		getPlayer(currentTurn)->addCard(Pdeck->dealCard()); // deal 2 cards
		if(Pdeck->getDeckSize() < 0) gameEnds = true; // if player draws the last 2 cards the game will end
		for(int i = 0; i < Pboard->getInfectRate(); i++) { // deal diseases at the end of turn
			int CID = Ideck->dealCard().getCity();
			setInfection(1, CID);
		}
		currentTurn = ++currentTurn % numPlayers;	// increment the turn
	}
}

void model::cureDisease() {
	int cureCounter = 0;
	int tempPC = 0;
	for(int i = 0; i < getPlayer(currentTurn)->getHand()->getHandSize(); i++) {
		int tempC = getPlayer(currentTurn)->getHand()->getCard(i).getCity();
		tempPC = Pboard->getCity(getPlayer(currentTurn)->getCID())->getVType();
		if(Pboard->getCity(tempC)->getVType() == tempPC) {
			cureCounter++;
		}
	}
	if(cureCounter > 2) {
		infectionCures[tempPC] = true;
	}
}


/*__________________________________MODEL ACCESS METHODS________________________________________*/

// returns the player object with the specified ID to the client.
player * model::getPlayer(int ID) {
	switch(ID) {
	case 0: return P1;
	case 1: return P2;
	case 2: return P3;
	case 3: return P4;
	}
	return NULL;
}

hand * model::accessHand(int PID) {
	player * temp = getPlayer(PID);
	hand * tempH = temp->getHand();
	return tempH;
}


#endif // MODEL_H