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



        /*
         * will be a dynamic array of players
         */
        Player *players;
        Dice *dice;

    public:
        Model();
        ~Model();
		Card dealRoleCard();
};
#endif // _MODEL_H
