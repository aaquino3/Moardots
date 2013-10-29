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
        int size;
        File *file;
    public:
        // Deck size
        Deck(int);
        ~Deck();

        void readInCards(string, char);
        Card dealCard();
        void shuffle();
		bool isDeckEmpty();
		void putCardOnBack(Card);
		void putCardOnFront(Card);
};

#endif // DECK_H
