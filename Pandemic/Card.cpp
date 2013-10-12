#include "Card.h"

Card::Card()
{
    name = "Unknown";
    description = "No Description.";
}
Card::Card(string name, string description)
{
    this->name = name;
    this->description = description;
}

Card::~Card()
{
}

void Card::setName(string name)
{
    this->name = name;
}

void Card::setDescription(string description)
{
    this->description = description;
}

string Card::getName()
{
    return name;
}

string Card::getDescription()
{
    return description;
}
