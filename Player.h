/*
 * Player.h
 *
 *  Created on: Oct 15, 2013
 *      Author: Ardee
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include <string>
using namespace std;

class Player
{
	private:
		string playerName;
		string playerRole;
		/*
		 * Objects that we may need up to you.
		 * - Player needs a Hand to hold the cards he may have. other then Role card
		 * - player needs a card to hold the Role card
		 *
		 */

	public:
		Player();
		Player(string, string);
		string getPlayerName();
		string getPlayerRole();

		/*
		 * Some methods we may need:
		 * + able to get a role card
		 * + Hand Methods look in Hand class to get ideas
		 *
		 */
};

#endif /* PLAYER_H_ */
