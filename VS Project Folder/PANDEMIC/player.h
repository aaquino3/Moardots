#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "hand.h"
using namespace std;

class player {
private:
	string name; // player name
	string role;
	hand * Phand;
	string location; // name of the city this player is currently in.
	int PID; // player ID number, distinguish from other players.
	int CID; // city ID of the player's location
	int RID;
public:
	player();
	player(string Pname, string Plocation, int ID, int CID);

	// MANIPULATION METHODS
	void setLocation(string newLocation, int ID) { location = newLocation; CID = ID; }
	void setName(string newName) { name = newName; }
	void setPID(int ID) {PID = ID; }
	void addCard(card C) { Phand->addCard(C); }
	void playCard(int);

	// ACCESS METHODS
	string getLocation() { return location; }
	string getName() { return name; }
	string getRole() { return role; }
	int getPID() { return PID; }
	int getCID() { return CID; }
	int getRID() { return RID; }
	hand * getHand() { return Phand; }
};

player::player() {
	name = "please set";
	location = "atlanta";
	PID = 1;
	CID = 1;
	RID = 0;
	role = "terminator";
}

player::player(string Pname, string Plocation, int ID, int CityID) {
	name = Pname;
	location = Plocation;
	PID = ID;
	CID = CityID;
	RID = 0;
	Phand = new hand();
	role = "president";
}

#endif PLAYER_H
