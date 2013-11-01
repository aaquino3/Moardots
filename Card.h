#ifndef CARD_H
#define CARD_H

// This object is intended to be used simply to hold necessary values of cards.
// No set-methods are necessary here as all objects of card type will be initiated at application launch.
// The event logic will be handled outside of this class, since the logical effects act on other objects.
// all those other objects and contexts need to function, is to know what kind of effect the card has.

#include <string>
using namespace std;
class Card
{
    private:
    bool type;       // this will either be a player card (city/event/epidemic) or an infection card (just cities).
    string name;        // The name of the city if it is an infection or city card, or simply "epidemic", or event title.
    string description; // english description for the player of what the card does.
    int eventType;      // a number 1 - 5 that determines what kind of event card this is, if 0 it is city, if 6 it is epidemic.
    int cityType;       // 0 = not a city, 1-48 = corresponding city

    public:
        Card();                         // init all values to irrelevant
        Card(bool,string,string,int);   // init all values as needed by context
        bool getType();                 // get the card type (for game handling)
        string getName();               // get card name (for game handling)
        string getDescription();        // get card description (so player can see)
        int getEvent();                 // determine card function of the card (0 = city (player or infection), 1-5 = event, 6 = epidemic)
        int getCity();                  // determine what kind of city this card is.
};
#endif
