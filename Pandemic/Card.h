#ifndef CARD_H
#define CARD_H

#include <string>
using namespace std;
class Card
{
    private:
    string type;
    string name;
    string description;

    public:
        Card();
        Card(string, string);
        void setType(string);
        void setName(string);
        void setDescription(string);
        string getType();
        string getName();
        string getDescription();
};
#endif
