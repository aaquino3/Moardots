#ifndef BOARD_H
#define BOARD_H

#include "city.h"
#include <string>
using namespace std;

// this node will be for a simple list of the cities.
// city object itself will hold which cities it links to.
struct Cnode {
	city * Pcity;
	Cnode * next;
};

class board {
private:
	int infectRate;			// infection rate counter
	int OutbreakCounter;	// outbreak rate counter
	city cityList[4];		// the list of the cities in nodes
	int numCities;			// the total number of cities on the board
	string cityNames[4];
public:
	// default contructor is all that is needed for now, 
	// will build the board with neutral settings, 
	// use methods to set specifics of game setup
	board();

	// MANIPULATION METHODS
	void upIRate() { infectRate++; }
	void upOCount() { OutbreakCounter++; }
	// ACCESS METHODS
	city * getCity(int CID) { return &cityList[CID]; }
	int getInfectRate() { return infectRate; }
	int getOutbreakCount() { return OutbreakCounter; }
	int getNumCities() { return numCities; }
	string getCityName(int CID) { return cityList[CID].getName(); } // returns the name of the city as indexed by CID
};

board::board() {
	int infectRate = 0;
	int OutbreakCounter = 0;
	int numCities = 4;
	string cityNames[4] = {"Atlanta", "Washington", "Toronto", "Chicago"}; // needed to construct the cities names
	int cityLNums[4] = {2, 2, 2, 2};										// needed to construct the number of links
	// the following array is composed of the arrays of links for each city, with the elements in numerical correspondence.
	int cityLinks[4][6] = {{1,3,-1,-1,-1,-1},{0,2,-1,-1,-1,-1},{1,3,-1,-1,-1,-1},{0,2,-1,-1,-1,-1}};
	for(int i = 0; i < numCities; i++) {
		city * cTemp = new city(cityNames[i], i, cityLNums[i], cityLinks[i]);
		cityList[i] = *cTemp;
	}
}

#endif BOARD_H // DEFINED BOARD.h