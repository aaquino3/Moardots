/*******************************************
* By: Edgar Reyes
*
* Descreption: This class represents a single
* card. It has a name and a descreption of
* what the card does.
*******************************************/

#ifndef CARD_H
#define CARD_H
#include <string>
using namespace std;

class Card
{
    private:
        string name;
        string description;
    public:
        Card();
        Card(string, string);
        ~Card();
        void setName(string);
        string getName();
        void setDescription(string);
        string getDescription();
};

#endif // CARD_H
