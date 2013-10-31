#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Deck.h"
#include "Card.h"
#include "Player.h"
#include "City.h"
#include "Hand.h"
#include "File.h"
#include "Model.h"
#include "View.h"
#include "Controller.h"

using namespace std;

int main()
{

	// random seeder It's only called once in main
	srand(unsigned(time(0)));

	// Model View Controller
	Model model;
	View view;
	Controller controller(model, view);

	controller.updateIntro();
	controller.updateGetNumOfPlayers();
	controller.updateDisplayNumOfPlayers();

	/*
	//checking if player works
    cout << endl;
    Player getInfo("Ardee", "Nerd");
	*/

	/*
    int sizeOfDeck = 7;
    Deck roleDeck(sizeOfDeck);
    Card temp;
    roleDeck.readInCards("roleCards.txt", '|');
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
	*/
	/* this was a test for new methods in File, planning on updating the way it
		reads the file
    File *file = new File("countTest.txt");
	int wordCount = file->countWords();
	string *str = file->getWords();

    cout << "word count = " << file->countWords() << endl;
    
	for(int i = 0; i < wordCount; i++)
	{
		cout << str[i] << endl;
	}
	delete file;
	*/
	getchar();
    return 0;
}