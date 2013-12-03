#ifndef HAND_H
#define HAND_H

#include "card.h"
class hand
{
	private:
		card Phand[10]; // player hand should never exceed 7, otherwise it should auto-discard.
		int handSize;
	public:
		hand();
		
		//gets a card 
		card * getCard(int n) { return &Phand[n]; }
		int getHandSize() { return handSize; }

		// adds a card to the hand
		void addCard(card);
};

hand::hand() {
	handSize = 0;
}

void hand::addCard(card C) {
	Phand[handSize] = C;
	handSize++;
}

#endif