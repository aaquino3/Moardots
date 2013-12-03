#ifndef DECK_H
#define DECK_H

#include <string>
#include "card.h"
#include <time.h>
using namespace std;
class deck
{
    private:
        card Pdeck[57];
        int type;               // this is the type of deck, player or infection. Effects what kind it builds
        int numCards;
        void builddeck();    // builds the appropriate deck based on the type input, player never needs to use this, only called by constructor.
		void shuffle();
		void shufflePlayerDeck();
    public:
        deck(int);
        ~deck();

        card dealCard();
		card getCard(int);						// needed to retrive information without removing card for saving game
		bool isEmpty() { return !numCards; }
		int getDeckSize() { return numCards; }
};

// Constructor to initialize deck data
deck::deck(int deckType)
{
    type = deckType;    // 0 = player, anything else = infection
    builddeck();		// build deck by type
    if( deckType == 0 ) shufflePlayerDeck();
	else shuffle();
}

// Destructor erases deque
deck::~deck()
{
	// is creating problems
	//cards.erase(cards.begin(), cards.end());
    delete this;
}

void deck::builddeck() {
    string cityNames[48] = {"Atlanta", "Washington", "Montreal", "Chicago", "San Francisco", "New York", "Los Angeles", "Mexico City", "Miami"," Bogota",
							"Lima","Sao Paulo","Bueno Aires","Santiago","Lagos","Kinshasa","Johanesburg","Khartoum","Cairo","Algiers",
							"Riadh","Karachi","Baghdad","Istanbul","Moscow","Tehran","Delhi","Mumbai","Chennai",
							"Kolkata","London","Essen","St. Petersburg","Milan","Paris","Madrid","Beijing","Shanghai","Seoul",
							"Tokyo","Osaka","Tripei","Hong Kong","Bangkok","Ho Chi Minh City","Jakarta","Sydney","Manila"}; // need to make an array of strings with the names of every city

    string eventNames[5] = {"Airlift", "One Quiet Night", "Forecast", "Government Grant", "Resilient Population"};

    string eventDescriptions[5];
    eventDescriptions[0] = "Move a pawn (yours or another player's) to any city. You must have a player's permission to move thier pawn.";
    eventDescriptions[1] = "The next player to begin the Playing The Infector phase of their turn may skip that phase entirely.";
    eventDescriptions[2] = "Examine the top 6 cards of the Infection Draw Pile, rearrange them in the order of your choice, then place them back on the pile.";
    eventDescriptions[3] = "Add a Research Station to any city for free.";
    eventDescriptions[4] = "Take a card from the infection Discard Pile and remove it from the game.";
    string epidemicDescription = ""; // can be handled during output to GUI
    if(type == 0) {     // player deck
        numCards = 57;
        for(int i = 0; i <= 47; i++) {
            card * temp = new card(true, cityNames[i], "", 0, i);     // add all of the city cards
            Pdeck[i] = *temp;
        }
        for(int i = 48; i <= 52 ; i++) {
            card * temp = new card(true, eventNames[i-48], eventDescriptions[i-48], i-48, 0);    // add the event cards
            Pdeck[i] = *temp;
        }
        for(int i = 52; i <= 56; i++) {
            card * temp = new card(true, "epidemic", epidemicDescription, 6, 0);        // add the epidmic cards
            Pdeck[i] = *temp;
        }
    } else {
        numCards = 48;
        for(int i = 0; i < 48; i++) {
            card * temp = new card(false, cityNames[i], "", 0, i);     // add all of the city cards
            Pdeck[i] = *temp;
        }
    }
}

// will deal a card and remove it from the deck.
card deck::dealCard()
{
	card temp = Pdeck[numCards-1];
	numCards--;
	return temp;
}

void deck::shuffle()
{
	srand( time(0) );
	if(!isEmpty())
	{
		int random = rand()%numCards;
		card tempDeck[48];
		bool tempDeckCheck[48];
		for( int i = 0; i < 48; i++) tempDeckCheck[i] = false;

		for( int i = 0; i < numCards; i++) {
			random = rand()%numCards;				// random should result in a value between 0 - 47, which is an array index.
			while( tempDeckCheck[random] ) random = rand()%numCards;	// checks if the card it is trying to assign has been assined.
			tempDeck[i] = Pdeck[random];			// adds the card from the constructed array to the temp array for shuffling.
			tempDeckCheck[random] = true;
		}
		for( int i = 0; i < numCards; i++)
			Pdeck[i] = tempDeck[i];					// adds the cards back to the deck object private data member
	}
}

void deck::shufflePlayerDeck() {
	// INITIALIZE VARIABLES
	srand(time(0));
	int randCard = 0;
	card TempE[4];
	card TempPiles[4][15];
	bool tempDeckCheck[53];
	for( int i = 0; i < 53; i++) tempDeckCheck[i] = false;
	for( int i = 0; i < 4; i++) TempE[i] = Pdeck[(numCards-i)-1];

	// BUILD THE PILES OF RANDOMIZED CARDS
	for( int i = 1; i < 14; i++) {
		for ( int j = 0; j < 3; j++) {
			randCard = rand()%53;
			while( tempDeckCheck[randCard] ) randCard = rand()%53;
			TempPiles[j][i] = Pdeck[randCard];
			tempDeckCheck[randCard] = true;
		}
	}
	for( int i = 1; i < 15; i++) {
		 randCard = rand()%53;
		 while( tempDeckCheck[randCard] ) randCard = rand()%53;
		 TempPiles[3][i] = Pdeck[randCard];
		 tempDeckCheck[randCard] = true;
	}
	TempPiles[0][0] = TempE[0];	// place the epidemic cards at the bottom of each pile
	TempPiles[1][0] = TempE[1];
	TempPiles[2][0] = TempE[2];
	TempPiles[3][0] = TempE[3];

	// REBUILD THE DECK WITH THE RANDOM STACKS
	int tempI = 0;
	for( int i = 0; i < 56; i++) {
		Pdeck[i] = TempPiles[i/14][tempI];
		tempI = (++tempI)%14;
	}
	Pdeck[56] = TempPiles[3][14];
}

card deck::getCard(int loc)
{
	// some one add 
	return Pdeck[loc];
}
#endif // DECK_H

/*
Shuffle method error report: 
The method was not accounting for whether a random card was pulled twice from the first array. 
This allowed for it to duplicate cards in the resulting array while trying to shuffle. I added an 
array of bools that will flag whether a specific card has been shuffled into the temp deck already.
The while loop will continue to pull new random numbers in the range until it finds the one that has 
not been pulled. This is wildly inefficient, but it is the only way I can think of doing it for now.
*/