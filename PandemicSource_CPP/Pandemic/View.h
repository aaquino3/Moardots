#ifndef VIEW_H_
#define VIEW_H_

#include <iostream>
#include "Card.h"
#include "Player.h"

using namespace std;

/*
View:
prints to console and get from console
*/
class View
{
	public:
		void printTitle(string);
		void printCard(Card);
		void printPlayer(Player);
		void printNumOfPlayers(int);

		// Updates
		void updateIntro(string);
		int updateGetNumOfPlayers();
};
#endif // VIEW_H_VIEW_H_
