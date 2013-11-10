#include "Model.h"

Model::Model()
{
	// staic size need to improve this
	roleDeck = new Deck(7);
    //roleDeck->readInCards("roleCards.txt",'|');
	roleDeck->shuffle();

	// will update to display ascii are of Pandemic
	title = "Pandemic";
	numberOfPlayers = 0;
	//players = 0;

}

Card Model::dealRoleCard()
{
	return roleDeck->dealCard();
}

string Model::getTitle()
{
	return title;
}
Model::~Model()
{
	//delete roleDeck;
}

void Model::setNumberOfPlayers(int num)
{
	numberOfPlayers = num;
}

int Model::getNumberOfPlayers()
{
	return numberOfPlayers;
}
