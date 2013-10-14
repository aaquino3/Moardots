#ifndef DECK_H
#define DECK_H

#include <string>
#include "Card.h"
#include "File.h"
#include <string>
using namespace std;
class Deck
{
    private:
        Card *cards;
        // may not be needed
        //string *cardTypes;
        int size;
        File *file;
    public:
        // Deck size
        Deck(int);
        ~Deck();

        // reads in cards from file, and delimiter
        void readInCards(string, char);
        void setCard(string, string);

        Card dealCard(int);
        void shuffle();

};

#endif // DECK_H
