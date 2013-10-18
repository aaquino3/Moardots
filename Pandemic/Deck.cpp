#include "Deck.h"

/*
 * Constructor to initialize size
 */
Deck::Deck(int size)
{
    this->size = size;
    file = 0;
}

/*
 * Destructor erases dequeue
 */
Deck::~Deck()
{
	cards.erase(cards.begin(), cards.end());
}

/*
	reads in card information from a file
	uses a dequeue which is a doubly link list
*/

void Deck::readInCards(string fileName, char delimiter)
{
    //will read until delimiter found
    file = new File(fileName);
    for(int count = 0; count < size; count++)
    {
		Card temp;
		temp.setType(file->getStr(delimiter));
		temp.setName(file->getStr(delimiter));
		temp.setDescription(file->getStr(delimiter));
		cards.push_back(temp);
    }
    // delete file reader since will will not use anymore;
    delete file;
    file = 0;
}

/*
	will deal a card and remove it from the deck.
*/
Card Deck::dealCard()
{
	Card temp = cards.front();
	cards.pop_front();
	return temp;
}

/*
	check to see if deck is empty return a boolean
*/
bool Deck::isDeckEmpty()
{
	return cards.empty();
}

/*
	will shuffle the deck using algorithm random_shuffle
	to shuffle a dequeue holding the cards
*/
void Deck::shuffle()
{
	random_shuffle(cards.begin(), cards.end());
}

/*
 * places a card on the bottom of deck
 */
void Deck::putCardOnBack(Card card)
{
	cards.push_back(card);
}

/*
 * places a card on the top of deck
 */
void Deck::putCardOnFront(Card card)
{
	cards.push_front(card);
}
