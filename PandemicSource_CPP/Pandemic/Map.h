/*
 * Map.h
 *
 *  Created on: Oct 25, 2013
 *      Author: ed
 */

#ifndef MAP_H_
#define MAP_H_
#include <iostream>
#include <vector>
#include "City.h"
using namespace std;

class Map {
	private:
	vector <City> cities;

	public:
	Map();
	virtual ~Map();
	void pushBackCity(City);
	void popBackCity();
	int GetNumberOfCities();
	City getCity(string);
	City getCity(int);

};

#endif /* MAP_H_ */
