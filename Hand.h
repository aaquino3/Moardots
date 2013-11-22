#ifndef HAND_H
#define HAND_H

#include "card.h"
#include <deque>
class Hand
{
	private:
		deque <card> cards;
	public:
		Hand();
		~Hand();
		
		//gets a card and discards it from the hand
		card getAndDiscardCard();
		// will send front card to the back to get next card in line
		void getNextCard();

		// adds a card to the hand
		void addCard(card);

		// returns the front card
		card getFrontCard();
};

Hand::Hand()
{
}


Hand::~Hand()
{
}

void Hand::addCard(card card)
{
	cards.push_front(card);
}

void Hand::getNextCard()
{
	card temp;

	temp = cards.front();
	cards.push_back(temp);
}

card Hand::getAndDiscardCard()
{
	card temp;
	temp = cards.front();
	cards.pop_front();

	return temp;
}


card Hand::getFrontCard()
{
	return cards.front();
}

#endif