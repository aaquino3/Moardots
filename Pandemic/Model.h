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

        /*
         * will be a dynamic array of players
         */
        Player *players;
        Dice *dice;

    public:
        Model();
        ~Model();
};
#endif // _MODEL_H
