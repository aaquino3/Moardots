#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class player {
private:
	string name; // player name
	int role;
	string location; // name of the city this player is currently in.
	int PID; // player ID number, distinguish from other players.
	int CID; // city ID of the player's location
public:
	player();
	player(string Pname, string Plocation, int ID, int CID);

	// MANIPULATION METHODS
	void setLocation(string newLocation, int ID) { location = newLocation; CID = ID; }
	void setName(string newName) { name = newName; }
	void setPID(int ID) {PID = ID; }

	// ACCESS METHODS
	string getLocation() { return location; }
	string getName() { return name; }
	int getPID() { return PID; }
	int getCID() { return CID; }
};

player::player() {
	name = "please set";
	location = "atlanta";
	PID = 1;
	CID = 1;
	role = 0;
}

player::player(string Pname, string Plocation, int ID, int CityID) {
	name = Pname;
	location = Plocation;
	PID = ID;
	CID = CityID;
}

#endif PLAYER_H
