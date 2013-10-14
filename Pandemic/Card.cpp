#include "Card.h"

Card::Card()
{
    name = "";
    description = "";
}
Card::Card(string name, string description)
{
    this->name = name;
    this->description = description;
}
void Card::setType(string type)
{
    this->type = type;
}
void Card::setName(string name)
{
    this->name = name;
}

void Card::setDescription(string description)
{
    this->description = description;
}
string Card::getType()
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
