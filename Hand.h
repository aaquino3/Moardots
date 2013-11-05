#ifndef HAND_H
#define HAND_H

#include "Card.h"
#include <deque>
class Hand
{
	private:
        deque <Card> cards; // data structure to hold cards in hand
        int numCards;       // used to easily check for how many cards to search for by client
	public:
		Hand();
		~Hand();
		
		//gets a card and discards it from the hand
        Card useCard();

		// will send front card to the back to get next card in line
		void getNextCard();

		// adds a card to the hand
		void addCard(Card);

		// returns the front card
		Card getFrontCard();

        // Informs client of hand size
        int getHandSize();
};

#endif

