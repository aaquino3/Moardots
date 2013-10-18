#ifndef _MODEL_H
#define _MODEL_H

#include "City.h"
#include "Card.h"
#include "Deck.h"
#include "Dice.h"
#include "File.h"
#include "Hand.h"
#include "Player.h"

class Model
{
    private:
        int numberOfPlayers;
		Player *players;		// array of players
		Deck *roleDeck;			// Deck to deal role cards
		string title;

    public:
        Model();
        ~Model();
		Card dealRoleCard();
		string getTitle();
};
#endif // _MODEL_H
