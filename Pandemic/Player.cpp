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
}

 string Player::getPlayerName()
{
	return playerName;
}

 string Player::getPlayerRole()
 {
	 return playerRole;
 }
