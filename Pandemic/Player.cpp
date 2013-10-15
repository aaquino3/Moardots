/*
 * Player.cpp
 *
 *  Created on: Oct 15, 2013
 *      Author: Ardee
 */

#include "Player.h"

Player::Player()
{

}

Player::Player(string pName, string pRole)
{
	playerName = pName;
	playerRole = pRole;
	cout << "My name is " << pName << " and my role is a " << pRole << endl;
}

 string Player::getPlayerName()
{
	return playerName;
}

 string Player::getPlayerRole()
 {
	 return playerRole;
 }
