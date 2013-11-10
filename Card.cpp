#include "Card.h"

/*
 * Constructor initialize strings to empty strings
 */
Card::Card()
{
    type = true;    // true = player car, false = infection card
    name = "";      // fill name with nothing
    description = "";   // no description, empty card
    eventType = 0;      // city
    cityType = 0;       // not a city
}

/*
 * Constructor to initialize name and description
 */

/*Card::Card(bool type, string name, string description, int event, int city)
{
    this->type = type;
    this->name = name;
    this->description = description;
    this->eventType = event;
    this->cityType = city;
}
*/

bool Card::getType()
{
    return type;
}

string Card::getName()
{
    return name;
}

string Card::getDescription()
{
    return description;
}

int Card::getEvent() {
    return eventType;
}

int Card::getCity() {
    return cityType;
}
