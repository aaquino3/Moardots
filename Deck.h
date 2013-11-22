#ifndef DECK_H
#define DECK_H

#include <string>
#include "card.h"
#include <deque>
#include <algorithm>
using namespace std;
class Deck
{
    private:
		/*
		 * using a dequeue because its a doubly linked list
		 * allowing use to cards from the top and bottom of the deck
		 * as well as place cards on the top or bottom of the deck.
		 */
        deque <card> cards;
        int type;               // this is the type of deck, player or infection. Effects what kind it builds
        int size;
        void buildDeck();    // builds the appropriate deck based on the type input, player never needs to use this, only called by constructor.
    public:
        Deck(int);
        ~Deck();

        card dealCard();
        void shuffle();
        bool isEmpty();
        void putCardOnBottom(card);
        void putCardOnTop(card);
};

// Constructor to initialize deck data
Deck::Deck(int deckType)
{
    type = deckType;    // 0 = player, anything else = infection
    //buildDeck();    // build deck by type
    shuffle();          // shuffle deck after building it.
}

// Destructor erases deque
Deck::~Deck()
{
	// is creating problems
	//cards.erase(cards.begin(), cards.end());
    delete this;
}
/*
void Deck::buildDeck() {
    string cityNames[48] = {}; // need to make an array of strings with the names of every city

    string eventNames[5] = {"Airlift", "One Quiet Night", "Forecast", "Government Grant", "Resilient Population"};

    string eventDescriptions[5];
    eventDescriptions[0] = "Move a pawn (yours or another player's) to any city. You must have a player's permission to move thier pawn.";
    eventDescriptions[1] = "The next player to begin the Playing The Infector phase of their turn may skip that phase entirely.";
    eventDescriptions[2] = "Examine the top 6 cards of the Infection Draw Pile, rearrange them in the order of your choice, then place them back on the pile.";
    eventDescriptions[3] = "Add a Research Station to any city for free.";
    eventDescriptions[4] = "Take a card from the infection Discard Pile and remove it from the game.";
    string epidemicDescription = ""; // can be handled during output to GUI
    if(type == 0) {     // player deck
        size = 59;
        for(int i = 1; i <= 48; i++) {
            card * temp = new card(true, cityNames[i-1], "", 0, i);     // add all of the city cards
            cards.push_front(temp);
        }
        for(int i = 1; i <= 5; i++) {
            card * temp = new card(true, eventNames[i-1], eventDescriptions[i-1], i, 0);    // add the event cards
            cards.push_front(temp);
        }
        for(int i = 0; i < 4; i++) {
            card * temp = new card(true, "epidemic", epidemicDescription, 6, 0);        // add the epidmic cards
            cards.push_front(temp);
        }
    } else {
        size = 48;
        for(int i = 1; i <= 48; i++) {
            card * temp = new card(false, cityNames[i-1], "", 0, i);     // add all of the city cards
            cards.push_front(temp);
        }
    }
}
*/
// will deal a card and remove it from the deck.
card Deck::dealCard()
{
	card temp = cards.front();
	cards.pop_front();
	return temp;
}

// check to see if deck is empty return a boolean
bool Deck::isEmpty()
{
	return cards.empty();
}

/*
	will shuffle the deck using algorithm random_shuffle
	to shuffle a dequeue holding the cards

    needs to be altered with a custom shuffle method for the player deck.
    The player deck requires that an epidemic card is placed randomly in every 10 draws.
*/
void Deck::shuffle()
{
	random_shuffle(cards.begin(), cards.end());
}

/*
 * places a card on the bottom of deck
 */
void Deck::putCardOnBottom(card Dcard)
{
	cards.push_back(Dcard);
}

/*
 * places a card on the top of deck
 */
void Deck::putCardOnTop(card Dcard)
{
	cards.push_front(Dcard);
}

#endif // DECK_H