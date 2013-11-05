#include "Hand.h"


Hand::Hand()
{
}


Hand::~Hand()
{
}

void Hand::addCard(Card card)
{
    numCards++;
	cards.push_front(card);
}

void Hand::getNextCard()
{
	Card temp;

	temp = cards.front();
	cards.push_back(temp);
}

Card Hand::useCard()
{
    numCards--;
	Card temp;
	temp = cards.front();
	cards.pop_front();

	return temp;
}


Card Hand::getFrontCard()
{
	return cards.front();
}

int Hand::getHandSize() {
    return numCards;
}
