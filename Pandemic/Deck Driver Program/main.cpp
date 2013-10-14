#include <iostream>
#include "Deck.h"
#include "Card.h"
#include <string>
using namespace std;

int main()
{
    int sizeOfDeck = 2;
    Deck roleDeck(sizeOfDeck);
    Card temp;
    roleDeck.readInCards("cards.txt", '|');
    for(int i = 0; i < sizeOfDeck; i++)
    {
        temp = roleDeck.dealCard(i);
        string type = temp.getType();
        string name = temp.getName();
        string description = temp.getDescription();
        cout << "\ncard delt\n\n" << endl;
        cout << "Type: " << type << endl;
        cout << "name: " << name << endl;
        cout << "Description: \n\n" << description << endl;
    }
    return 0;
}
