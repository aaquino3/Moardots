#include <iostream>
#include "Deck.h"
#include "Card.h"
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
	// random seeder
	srand(unsigned(time(0)));

    int sizeOfDeck = 7;
    Deck roleDeck(sizeOfDeck);
    Card temp;
    roleDeck.readInCards("cards.txt", '|');
	roleDeck.shuffle();
    for(int i = 0; i < sizeOfDeck; i++)
    {
        temp = roleDeck.dealCard();
        string type = temp.getType();
        string name = temp.getName();
        string description = temp.getDescription();
        cout << "\ncard delt\n\n" << endl;
        cout << "Type: " << type << endl;
        cout << "name: " << name << endl;
        cout << "Description: \n\n" << description << endl;
    }

	getchar();
    return 0;
}
