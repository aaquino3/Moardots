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
		//using deque because it can push front and back
        deque <Card> cards;
        int size;
        File *file;
    public:
        // Deck size
        Deck(int);
        ~Deck();

        // reads in cards from file, and delimiter
        void readInCards(string, char);

        Card dealCard();
        void shuffle();
		bool isDeckEmpty();
		void putCardOnBack(Card);
		void putCardOnFront(Card);
};

#endif // DECK_H
