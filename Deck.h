#ifndef DECK_H
#define DECK_H


#include <string>
#include <ctime>
#include <cstdlib>
#include "card.h"
using namespace std;

class deck
{
    private:
        card Pdeck[numCards];
        int type;               // this is the type of deck, player or infection. Effects what kind it builds
        int numCards;
        void builddeck();    // builds the appropriate deck based on the type input, player never needs to use this, only called by constructor.
    public:
        deck(int);
        ~deck();
	void shufflePlayerDeck();
        card dealCard();
        void shuffle();
	bool isEmpty() { return !numCards; }
	int getDeckSize() { return numCards; }
};

// Constructor to initialize deck data
deck::deck(int deckType)
{
    type = deckType;    // 0 = player, anything else = infection
    builddeck();		// build deck by type
    shuffle();          // shuffle deck after building it.
}

// Destructor erases deque
deck::~deck()
{
	// is creating problems
	//cards.erase(cards.begin(), cards.end());
    delete this;
}

void deck::builddeck() {
    string cityNames[48] = {"Atlanta", "Washington", "Montreal", "Chicago", "San Francisco", "New York", "Los Angeles", "Mexico City", "Miami"," Bogota","Lima","Sao Paulo","Bueno Aires","Santiago","Lagos","Kinshasa","Johanesburg","Khartoum","Cairo","Algiers","Riadh","Karachi","Baghdad","Istanbul","Moscow","Tehran","Delhi","Karachi","Mumbai","Chennai","Kolkata","London","Essen","St. Petersburg","Milan","Paris","Madrid","Beijing","Shanghai","Seoul","Tokyo","Osaka","Tripei","Hong Kong","Bangkok","Ho Chi Minh City","Jakarta","Sydney","Manila"}; // strings with the names of every city

    string eventNames[5] = {"Airlift", "One Quiet Night", "Forecast", "Government Grant", "Resilient Population"};

    string eventDescriptions[5];
    eventDescriptions[0] = "Move a pawn (yours or another player's) to any city. You must have a player's permission to move thier pawn.";
    eventDescriptions[1] = "The next player to begin the Playing The Infector phase of their turn may skip that phase entirely.";
    eventDescriptions[2] = "Examine the top 6 cards of the Infection Draw Pile, rearrange them in the order of your choice, then place them back on the pile.";
    eventDescriptions[3] = "Add a Research Station to any city for free.";
    eventDescriptions[4] = "Take a card from the infection Discard Pile and remove it from the game.";
    string epidemicDescription = ""; // can be handled during output to GUI
    if(type == 0) {     // player deck
        numCards = 59;
        for(int i = 0; i < 48; i++) {
            card * temp = new card(true, cityNames[i], "", 0, i);     // add all of the city cards
            Pdeck[i] = *temp;
        }
        for(int i = 0; i < 4; i++) {
            card * temp = new card(true, eventNames[i], eventDescriptions[i], i, 0);    // add the event cards
            Pdeck[i+49] = *temp;
        }
        for(int i = 0; i < 4; i++) {
            card * temp = new card(true, "epidemic", epidemicDescription, 6, 0);        // add the epidmic cards
            Pdeck[i+54] = *temp;
        }
    } else {
        numCards = 48;
        for(int i = 0; i < 48; i++) {
            card * temp = new card(false, cityNames[i], "", 0, i);     // add all of the city cards
            Pdeck[i] = *temp;
        }shuffle();//shuffles the city cards
    }
}

// will deal a card and remove it from the deck.
card deck::dealCard()
{
	card temp = Pdeck[numCards-1];
	numCards--;
	return temp;
}

/*
    needs to be altered with a custom shuffle method for the player deck.
    The player deck requires that an epidemic card is placed randomly in every 10 draws.
*/
void deck::shuffle()
{
	srand( time(0) );
	if(!isEmpty())
	{
		int random = rand()%numCards;
		card tempDeck[numCards];
		for( int i = 0; i < numCards; i++)
		{
			card tempDeck[i] = Pdeck[random-1];
		}
		for( int i = 0; i < numCards; i++)
			Pdeck[i] = tempDeck[i];
	}
}

void deck::shufflePlayerDeck()
{
	if(!isEmpty())
	{
		int j = 0;
		card tempE[5];
		card tempD[numCards];
		card pileA[11];
		card pileB[12];
		card pileC[12];
		card pileD[12];
		card pileE[12];
	
		for(int i = 0; i<numCards; i++) //removing epidemic cards
		{		
			if(Pdeck[i].getName()) == "epidemic")
			{
				tempE[j] = Pdeck[i];
				j++;
			}
			else
			{
				tempD[i-j] = Pdeck[i];
			}
		}
		for(int i = 0; i<numCards; i++) //shuffling deck without epidemic cards
		{
			Pdeck[i] = tempD[i];
		}
		shuffle();
		
		for(int i = 0; i<10; i++) // splitting 1st deck
		{
			pileA[i] = Pdeck[i];
		}
		//adding in 1st epidemic card randomly
		pileA[11] = tempE[0];
		int random = rand()%11;
		card tempPile[11];
		for( int i = 0; i < 11; i++)
		{
			tempPile[i] = pileA[random-1];
		}
		for( int i = 0; i < 11; i++)
			pileA[i] = tempPile[i];
		
		//splitting 2nd
		for(int i = 0; i<11; i++) 
		{
			pileB[i] = Pdeck[i+10];
		}
		//adding in 2nd epidemic card
		pileB[12] = tempE[1];
		int random = rand()%12;
		card tempPile[12];
		for( int i = 0; i < 12; i++)
		{
			tempPile[i] = pileB[random-1];
		}
		for( int i = 0; i < 12; i++)
			pileB[i] = tempPile[i];
			
		//splitting 3rd	
		for(int i = 0; i<11; i++) 
		{
			pileC[i] = Pdeck[i+10+11];
		}
		//adding in 3rd epidemic card
		pileC[12] = tempE[2];
		int random = rand()%12;
		card tempPile[12];
		for( int i = 0; i < 12; i++)
		{
			tempPile[i] = pileC[random-1];
		}
		for( int i = 0; i < 12; i++)
			pileC[i] = tempPile[i];
		
		//splitting 4th
		for(int i = 0; i<11; i++) 
		{
			pileD[i] = Pdeck[i+10+11+11];
		}
		//adding in 4th epidemic card
		pileD[12] = tempE[3];
		int random = rand()%12;
		card tempPile[12];
		for( int i = 0; i < 12; i++)
		{
			tempPile[i] = pileD[random-1];
		}
		for( int i = 0; i < 12; i++)
			pileD[i] = tempPile[i];
		
		//splitting last one
		for(int i = 0; i<11; i++) 
		{
			pileE[i] = Pdeck[i+10+11+11+11];
		}
		//adding in last epidemic card
		pileE[12] = tempE[4];
		int random = rand()%12;
		card tempPile[12];
		for( int i = 0; i < 12; i++)
		{
			tempPile[i] = pileE[random-1];
		}
		for( int i = 0; i < 12; i++)
			pileE[i] = tempPile[i];

		//stacking deck back together
		for(int i = 0; i<11; i++)
		{
			pDeck[i] = pileA[i];
		}
		for(int i = 0; i<12; i++) 
		{
			Pdeck[i+11] = pileB[i];
		}
		for(int i = 0; i<12; i++) 
		{
			Pdeck[i+11+12] = pileC[i];
		}
		for(int i = 0; i<12; i++) 
		{
			Pdeck[i+11+12+12] = pileD[i];
		}
		for(int i = 0; i<12; i++) 
		{
			Pdeck[i+11+12+12+12] = pileE[i];
		}
	}
}





#endif // DECK_H
