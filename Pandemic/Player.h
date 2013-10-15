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

	public:
		Player();
		Player(string, string);
		string getPlayerName();
		string getPlayerRole();
};

#endif /* PLAYER_H_ */
