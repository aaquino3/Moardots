#ifndef CITY_H
#define CITY_H

#include <string>
using namespace std;

class city {
private:
	string name;
	int virusType;
	int virusCount;
	bool cure;
	int CID; // city has ID for quick linking and searching
	int links[6]; // no city should have more than 6 links, but this can be dymanic eventually.
	int numLinks;
	bool players[4]; // if true then the given player is in this city
public:
	city();
	city(string Cname, int ID, int Linknum, int Clinks[]);
	// city(string Cname, int ID, int vCount, int links[], int players[]); // this is the load game constructor.

	// MANIPULATION METHODS
	void setName(string Cname) { name = Cname; }
	void setID(int ID) { CID = ID; }
	bool addVirus() { if(virusCount < 3) { virusCount++; return true; } return false; }
	void removeVirus() {virusCount--; }
	void setVCount(int vCount) { virusCount = vCount; }
	void setPlayer(int PID, bool present) { players[PID] = present; }
	void setCure(bool CityCure) { cure = CityCure; }
	void setVType(int Vtype) { virusType = Vtype; }

	// ACCESS METHODS
	string getName() { return name; }
	int getVCount() { return virusCount; }
	int getVType() { return virusType; }
	bool isCured() { return cure; }
	int getCID() { return CID; }
	bool isPlayerHere(int PID) { return players[PID]; }
	bool canMove(int ID);
};

// DEFAULT CONSTRUCTOR
city::city() {
	name = "noName";
	virusCount = 0;
	virusType = 0;
	cure = false;
	CID = 0;
	numLinks = 0;
	for(int i = 0; i < 6; i++) { links[i] = 0; }
	for(int i = 0; i < 4; i++) { players[i] = false; }
}

// NORMAL CONSTRUCTOR
city::city(string Cname, int ID, int Linknum, int Clinks[]) {
	name = Cname;
	virusCount = 0;
	virusType = 0;
	cure = false;
	CID = ID;
	numLinks = Linknum;
	for(int i = 0; i < 4; i++) { players[i] = false; }
	for(int i = 0; i < numLinks; i++) { links[i] = Clinks[i]; }
}

// checks if the city specified is a valid move from this one.
bool city::canMove(int ID) {
	for(int i = 0; i < numLinks; i++) {
		if( links[i] == ID ) return true;
	}
	return false;
}

#endif // !CITY_H