#ifndef MODEL_H
#define MODEL_H


#include "player.h"
#include "deck.h"
#include "hand.h"
#include "board.h"

class model {
private:
	board * Pboard;

	int numPlayers;
	player * P1;
	player * P2;
	player * P3;
	player * P4;

public:
	model();

	// model-side maniupation methods
	void InitPlayer(string Pname, string Plocation, int ID, int CID);
	void setNumPlayers(int nPlayers) { numPlayers = nPlayers; }
	bool movePlayer(int, int, int);

	// model-side access methods
	player * getPlayer(int ID);		// allows passingo a player object to the controller for a given turn
	string getCityNames(int CID) { return Pboard->getCityName(CID); } // allows the passing of city names to the controller
	int getNumPlayers() { return numPlayers; }
	board * accessBoard() { return Pboard; }
};

// DEFAULT CONSTRUCTOR
model::model() {
	Pboard = new board();
	numPlayers = 0;
}


/*__________________________________MODEL MANIPULATION METHODS__________________________________*/

// constructs the player of the given ID, with the name and location entered.
void model::InitPlayer(string Pname, string Plocation, int ID, int CID) {
	Pboard->getCity(CID)->setPlayer(ID,true);
	switch(ID) {
	case 1: P1 = new player(Pname, Plocation, ID, CID);
		break;
	case 2: P2 = new player(Pname, Plocation, ID, CID);
		break;
	case 3: P3 = new player(Pname, Plocation, ID, CID);
		break;
	case 4: P4 = new player(Pname, Plocation, ID, CID);
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

/*__________________________________MODEL ACCESS METHODS________________________________________*/

// returns the player object with the specified ID to the client.
player * model::getPlayer(int ID) {
	switch(ID) {
	case 1: return P1;
	case 2: return P2;
	case 3: return P3;
	case 4: return P4;
	}
	return NULL;
}


#endif // MODEL_H