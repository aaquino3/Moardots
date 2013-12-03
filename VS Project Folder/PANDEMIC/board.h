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
	int numCities;			// the total number of cities on the board
	city cityList[48];		// the list of the cities in nodes
	string cityNames[48];
public:
	// default contructor is all that is needed for now, 
	// will build the board with neutral settings, 
	// use methods to set specifics of game setup
	board();

	// MANIPULATION METHODS
	void upIRate() { infectRate++; }
	void upOCount() { OutbreakCounter++; }
	void setIRate(int i) { infectRate = i; }
	void setOCount(int i) { OutbreakCounter = i; }
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
	int numCities = 48;
	// string cityNames[4] = {"Atlanta", "Washington", "Toronto", "Chicago"}; // needed to construct the cities names
	string cityNames[48] = {"Atlanta", "Washington", "Montreal", "Chicago", "San Francisco", "New York", "Los Angeles", "Mexico City", "Miami"," Bogota",
							"Lima","Sao Paulo","Bueno Aires","Santiago","Lagos","Kinshasa","Johanesburg","Khartoum","Cairo","Algiers",
							"Riadh","Karachi","Baghdad","Istanbul","Moscow","Tehran","Delhi","Mumbai","Chennai",
							"Kolkata","London","Essen","St. Petersburg","Milan","Paris","Madrid","Beijing","Shanghai","Seoul",
							"Tokyo","Osaka","Tripei","Hong Kong","Bangkok","Ho Chi Minh City","Jakarta","Sydney","Manila"};
	//int cityLNums[4] = {2, 2, 2, 2};										// needed to construct the number of links
	int cityLNums[48] = {3,4,3,5,4,4,4,4,4,5,3,4,2,1,3,3,2,3,5,4,3,5,5,6,3,4,5,3,5,4,4,4,3,3,5,5,2,5,3,3,2,4,6,5,4,4,3,4};

	// the following array is composed of the arrays of links for each city, with the elements in numerical correspondence.
	//int cityLinks[4][6] = {{1,3,-1,-1,-1,-1},{0,2,-1,-1,-1,-1},{1,3,-1,-1,-1,-1},{0,2,-1,-1,-1,-1}};
	int cityLinks[48][6] = {{1,3,8,-1,-1,-1},{0,2,5,8,-1,-1},{1,3,5,-1,-1,-1},{0,2,4,6,7,-1},{3,6,40,48,-1,-1},
							{2,1,31,36,-1,-1},{4,3,7,47,-1,-1},{6,8,10,9,-1,-1},{0,1,7,9,-1,-1},{7,10,8,11,12,-1},
							{7,9,13,-1,-1,-1},{9,12,14,36,-1,-1},{9,11,-1,-1,-1,-1},{10,-1,-1,-1,-1,-1},{11,15,17,-1,-1,-1},
							{14,17,16,-1,-1,-1},{15,17,-1,-1,-1,-1},{14,15,16,-1,-1,-1},{19,23,22,20,17,-1},{36,35,23,18,-1,-1},
							{18,22,21,-1,-1,-1},{20,22,25,26,28,-1},{23,18,20,21,25,-1},{19,34,33,24,22,18},{33,23,25,-1,-1,-1},
							{24,22,21,26,-1,-1},{25,21,28,29,30,-1}, {21,25,28,-1,-1,-1},{27,25,29,43,45,-1},{25,28,45,42,-1,-1},
							{5,35,34,31,-1,-1},{30,32,34,33,-1,-1},{31,23,24,-1,-1,-1},{31,34,23,-1,-1,-1},{30,31,33,19,35,-1},
							{5,30,34,19,11,-1},{37,38,-1,-1,-1,-1},{36,38,39,41,42,-1},{36,37,39,-1,-1,-1},{38,37,40,-1,-1,-1},
							{39,41,-1,-1,-1,-1},{37,42,47,40,-1,-1},{29,43,44,47,41,37},{29,28,45,44,42,-1},{42,43,45,47,-1,-1},
							{27,43,44,46,-1,-1},{45,47,6,-1,-1,-1},{42,41,46,4,-1,-1}};

	for(int i = 0; i < numCities; i++) {
		city * cTemp = new city(cityNames[i], i, cityLNums[i], cityLinks[i]);
		cityList[i] = *cTemp;
	}
}

#endif BOARD_H // DEFINED BOARD.h