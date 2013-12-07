#ifndef MODEL_H
#define MODEL_H
//for testing only
#include <iostream>
using namespace std;
// end of testing
//needed for loading
// dont know about Card.h since no load methods
#include <string>
#include "Card.h"
//end of loading

#include "player.h"
#include "deck.h"
#include "hand.h"
#include "board.h"
#include "File.h"

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
public:
	model();

	// model-side maniupation methods
	void InitPlayer(string Pname, string Plocation, int ID, int CID);
	void dealHands();
	void setNumPlayers(int nPlayers) { numPlayers = nPlayers; }
	bool movePlayer(int, int, int);

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

	//save game
	void saveGame();
	//load game
	void loadGame();
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

void model::saveGame()
{
	File file;
	//===================================================================================
	/*
		files:
		playerDeck.txt
		infectionDeck.txt
		board.txt
		cities.txt
		numberOfPlayers.txt
		player1.txt
		player2.txt
		player3.txt
		player4.txt
	//-----------------------------------------------------------------------------------
		playerDeck.txt
		saves:
		card name
		card description
		card event
		card city
	//-----------------------------------------------------------------------------------
		infectionDeck.txt
		saves:
		card name
		card description
		card event
		card city
	//-----------------------------------------------------------------------------------
		board.txt
		saves:
		infection rate
		outbreak count
		number of cities but is not working so hard coded !!needs fix when class fixed
	//-----------------------------------------------------------------------------------
		numberOfPlayers.txt
		just saves the amount of players playing
	//-----------------------------------------------------------------------------------
		player#.txt
		saves:
		Location
		Name
		Role
		PID
		CID
		RID
	*/
	
	//===================================================================================
	// file names

	string playerdDeckFileName = "playerDeck.txt";
	string infectionDeckFileName = "infectionDeck.txt";
	string boardFileName = "board.txt";
	string citiesFileName = "cities.txt";
	string numberOfPlayersFileName = "numberOfPlayers.txt";
	string player1FileName = "player1.txt";
	string player2FileName = "player2.txt";
	string player3FileName = "player3.txt";
	string player4FileName = "player4.txt";
	//===================================================================================
	// save Player Deck




	file.setWriteFileName(playerdDeckFileName);
	file.openWrite();
	
	int numberOfPlayerCards = Pdeck->getDeckSize();
	file.writeLine(numberOfPlayerCards);

	for(int counter = 0; counter < numberOfPlayerCards; counter++)
	{
		if(Pdeck->getCard(counter).getType() == true)
			file.writeLine(1);
		else
			file.writeLine(0);

		file.writeLine(Pdeck->getCard(counter).getName());
		file.writeLine(Pdeck->getCard(counter).getDescription());
		file.writeLine(Pdeck->getCard(counter).getEvent());
		file.writeLine(Pdeck->getCard(counter).getCity());
	}
	file.closeWrite();

	//===================================================================================
	// save infection deck
	file.setWriteFileName(infectionDeckFileName);
	file.openWrite();
	
	int numberOfInfectionCards = Ideck->getDeckSize();
	file.writeLine(numberOfInfectionCards);

	for(int counter = 0; counter < numberOfInfectionCards; counter++)
	{
		if(Pdeck->getCard(counter).getType() == true)
			file.writeLine(1);
		else
			file.writeLine(0);

		file.writeLine(Pdeck->getCard(counter).getName());
		file.writeLine(Pdeck->getCard(counter).getDescription());
		file.writeLine(Pdeck->getCard(counter).getEvent());
		file.writeLine(Pdeck->getCard(counter).getCity());
	}
	file.closeWrite();

	//===================================================================================
	// save board
	file.setWriteFileName(boardFileName);
	file.openWrite();
	file.writeLine(Pboard->getInfectRate());
	file.writeLine(Pboard->getOutbreakCount());

	// not getting right number
	int myCityNum = Pboard->getNumCities();			// ! not getting correct number
	myCityNum = 48;
	file.writeLine(myCityNum);
	file.closeWrite();


	//===================================================================================
	// save cities
	// will use the myCityNum from above
	file.setWriteFileName(citiesFileName);
	file.openWrite();
	
	for(int counter = 0; counter < myCityNum; counter++)
	{
		file.writeLine(Pboard->getCity(counter)->getVCount());
		if(Pboard->getCity(counter)->isCured() == true)
			file.writeLine(1);
		else
			file.writeLine(0);
	}
	file.closeWrite();

	//===================================================================================
	//Save player information
	file.setWriteFileName(numberOfPlayersFileName);
	file.openWrite();
	file.writeLine(numPlayers);
	file.closeWrite();

	//===================================================================================
	// save player 1-2
	if(numPlayers >= 2)
	{
		file.setWriteFileName(player1FileName);
		file.openWrite();
		file.writeLine(P1->getLocation());
		file.writeLine(P1->getName());
		file.writeLine(P1->getRole());
		file.writeLine(P1->getPID());
		file.writeLine(P1->getCID());
		file.writeLine(P1->getRID());
		file.closeWrite();
		
		file.setWriteFileName(player2FileName);
		file.openWrite();
		file.writeLine(P2->getLocation());
		file.writeLine(P2->getName());
		file.writeLine(P2->getRole());
		file.writeLine(P2->getPID());
		file.writeLine(P2->getCID());
		file.writeLine(P2->getRID());
		file.closeWrite();
	}

	//===================================================================================
	// save player 3
	if(numPlayers >= 3)
	{
		file.setWriteFileName(player3FileName);
		file.openWrite();
		file.writeLine(P3->getLocation());
		file.writeLine(P3->getName());
		file.writeLine(P3->getRole());
		file.writeLine(P3->getPID());
		file.writeLine(P3->getCID());
		file.writeLine(P3->getRID());
		file.closeWrite();
	}
	else
	{
		file.setWriteFileName(player3FileName);
		file.openWrite();
		file.closeWrite();
	}

	//===================================================================================
	// save player 4
	if(numPlayers >= 4)
	{
		file.setWriteFileName(player4FileName);
		file.openWrite();
		file.writeLine(P4->getLocation());
		file.writeLine(P4->getName());
		file.writeLine(P4->getRole());
		file.writeLine(P4->getPID());
		file.writeLine(P4->getCID());
		file.writeLine(P4->getRID());
		file.closeWrite();
	}
	else
	{
		file.setWriteFileName(player4FileName);
		file.openWrite();
		file.closeWrite();
	}
}

void model::loadGame()
{
	File file;
	//==================================================================================
	string playerdDeckFileName = "playerDeck.txt";
	string infectionDeckFileName = "infectionDeck.txt";
	string boardFileName = "board.txt";
	string citiesFileName = "cities.txt";
	string numberOfPlayersFileName = "numberOfPlayers.txt";
	string player1FileName = "player1.txt";
	string player2FileName = "player2.txt";
	string player3FileName = "player3.txt";
	string player4FileName = "player4.txt";
	//===================================================================================
	//temp data because no methods to load data

	int tempInfectionDeckSize = 0;
	int tempPlayerDeckSize = 0;
	card *tempPlayerCards;
	card *tempInfectionCards;
	//card *tempCard;
	//===================================================================================
	// read number of players
	file.setReadFileName(numberOfPlayersFileName);
	file.openRead();
	file.readLine();
	numPlayers = atoi(file.getLine().c_str());
	file.closeRead();
	//===================================================================================
	// read player deck size;
	file.setReadFileName(playerdDeckFileName);
	file.openRead();
	
	if(file.readLine() == 0)
		tempPlayerDeckSize = atoi(file.getLine().c_str());
	
	tempPlayerCards = new card[tempPlayerDeckSize];
	for(int i = 0; i < tempPlayerDeckSize; i++)
	{
		bool type = true;	// player card = true
		string name = "";
		string description = "";
		int event = 0;
		int city = 0;
		
		file.readLine();
		name = file.getLine();

		file.readLine();
		description = file.getLine();

		file.readLine();
		event = atoi(file.getLine().c_str());

		file.readLine();
		city = atoi(file.getLine().c_str());

		card tempCard(type,name,description,event,city);
		tempPlayerCards[i] = tempCard;
	}// end for loop

	// test for checking cards where inserted
	//for(int i = 0; i < tempPlayerDeckSize; i++)
	//{
	//	cout << "start of card" << endl;
	//	cout << tempPlayerCards[i].getCity() << endl;
	//	cout << tempPlayerCards[i].getDescription() << endl;
	//	cout << tempPlayerCards[i].getEvent() << endl;
	//	cout << tempPlayerCards[i].getName() << endl;
	//	cout << tempPlayerCards[i].getType() << endl;
	//	cout << "End of card " << "\n\n" << endl;
	//}
	
	file.closeRead();
	//===================================================================================
	// read infection deck size
	file.setReadFileName(infectionDeckFileName);
	file.openRead();
	
	if(file.readLine() == 0)
		tempInfectionDeckSize = atoi(file.getLine().c_str());

	//create temp cards
	tempInfectionCards = new card[tempInfectionDeckSize];
	//===================================================================================
	// read in infection cards
	for(int i = 0; i < tempInfectionDeckSize; i++)
	{
		bool type = true;	// player card = true
		string name = "";
		string description = "";
		int event = 0;
		int city = 0;
		
		file.readLine();
		name = file.getLine();

		file.readLine();
		description = file.getLine();

		file.readLine();
		event = atoi(file.getLine().c_str());

		file.readLine();
		city = atoi(file.getLine().c_str());

		card tempCard(type,name,description,event,city);
		tempInfectionCards[i] = tempCard;
	}// end for loop
	file.closeRead();
}
#endif // MODEL_H