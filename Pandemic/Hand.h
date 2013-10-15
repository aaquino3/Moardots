#ifndef HAND_H
#define HAND_H

#include "Card.h"
#include <deque>
class Hand
{
	private:
		deque <Card> cards;
	public:
		Hand();
		~Hand();
		
		//gets a card and discards it from the hand
		Card getAndDiscardCard();
		// will send front card to the back to get next card in line
		void getNextCard();

		// adds a card to the hand
		void addCard(Card);

		// returns the front card
		Card getFrontCard();
};

#endif

