#ifndef DECK_H
#define DECK_H

#include <string>
#include "Card.h"
#include "File.h"
#include <deque>
#include <algorithm>
using namespace std;
class Deck
{
    private:
        /*
         * using a dequeue because its a doubly linked list
         * allowing use to cards from the top and bottom of the deck
         * as well as place cards on the top or bottom of the deck.
         */
        deque <Card> cards;
        int type;               // this is the type of deck, player or infection. Effects what kind it builds
        int size;
        void buildDeck(int);    // builds the appropriate deck based on the type input, player never needs to use this, only called by constructor.
    public:
        Deck(int);
        ~Deck();

        Card dealCard();
        void shuffle();
        bool isEmpty();
        void putCardOnBottom(Card);
        void putCardOnTop(Card);
};

#endif // DECK_H
