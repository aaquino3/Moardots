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
		card getCard(int n) { return Phand[n]; }
		int getHandSize() { return handSize; }

		// adds a card to the hand
		void addCard(card);
		void discard(int);
};

hand::hand() {
	handSize = 0;
}

void hand::addCard(card C) {
	Phand[handSize] = C;
	handSize++;
}

void hand::discard(int cardNum) {
	if(handSize > 0) {
		Phand[cardNum] = Phand[--handSize];
	}
}

#endif