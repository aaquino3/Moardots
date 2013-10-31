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

//List of Stubs

Card::Card(string name, string description) {}
void Card::setType(string type) {}
void Card::setName(string name) {}
void Card::setDescription(string description) {}
string Card::getType() { return ""; }
string Card::getName() { return ""; }
string Card::getDescription() { return ""; }
City::City(string iName, int iNumberOfDisease, bool iCure) {}
string City::getName() { return ""; }
int City::getNumberofDiseases() { return 10; }
bool City::getCure() { return true; }
Controller::Controller(Model model, View view) {}
void Controller::updateIntro() {}
void Controller::updateGetNumOfPlayers() {}
void Controller::updateDisplayNumOfPlayers() {}
void View::updateIntro(string title) { cout << ""<< endl; }
int View::updateGetNumOfPlayers() { return 4; }
void View::printNumOfPlayers(int num) { cout << "4" << endl; }
Player::Player(string pName, string pRole) {}
string Player::getPlayerName() { return ""; }
string Player::getPlayerRole() { return ""; }
Model::Model() {}
Card Model::dealRoleCard() { return Card; }
string Model::getTitle() { return ""; }
Model::~Model() {}
void Model::setNumberOfPlayers(int num) {}
int Model::getNumberOfPlayers() { return 4; }
Hand::Hand() {}
Hand::~Hand() {}
void Hand::addCard(Card card) {}
void Hand::getNextCard() {}
Card Hand::getAndDiscardCard() { return Card; }
Card Hand::getFrontCard() { return Card; }
File::File(string fileName) {}
void File::fileOpen(string fileName) { return; }
void File::fileClose() {}
string File::getStr() { return ""; }
bool File::eof() { return false; }
string File::getStr(char delimiter) { return ""; }
void File::setErrorLog(bool toggle) {}
int File::countWords() { return 10; }
string* File::getWords() { return ""; }
File::~File() {}
Deck::Deck(int size) {}
Deck::~Deck() {}
void Deck::readInCards(string fileName, char delimiter) {}
Card Deck::dealCard() { return Card; }
bool Deck::isDeckEmpty() { return false; }
void Deck::shuffle() {}
void Deck::putCardOnBack(Card card) {}
void Deck::putCardOnFront(Card card) {}




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
