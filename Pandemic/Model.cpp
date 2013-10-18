#include "Model.h"

Model::Model()
{
	// staic size need to improve this
	roleDeck = new Deck(7);
	roleDeck->readInCards("roleCards.txt",'|');
	roleDeck->shuffle();



}

Card Model::dealRoleCard()
{
	return roleDeck->dealCard();
}


Model::~Model()
{
	delete roleDeck;
}