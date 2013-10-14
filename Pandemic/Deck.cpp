#include "Deck.h"

Deck::Deck(int size)
{
    this->size = size;
    cards = new Card[size];
    file = 0;
}

Deck::~Deck()
{
    delete [] cards;
}

void Deck::readInCards(string fileName, char delimiter)
{
    //will read untill delimiter found
    file = new File(fileName);
    for(int count = 0; count < size; count++)
    {
        cards[count].setType(file->getStr(delimiter));
        cards[count].setName(file->getStr(delimiter));
        cards[count].setDescription(file->getStr(delimiter));
    }
    // delete file reader since will will not use anymore;
    delete file;
    file = 0;
}

Card Deck::dealCard(int loc)
{
    return cards[loc];
}
