#ifndef VIEW_H_
#define VIEW_H_

#include <iostream>
#include "Card.h"
#include "Player.h"

using namespace std;
class View
{
	public:
		void printTitle(string);
		void printCard(Card);
		void printPlayer(Player);
		

		// Updates
		void updateIntro(string);
};
#endif // VIEW_H_VIEW_H_
