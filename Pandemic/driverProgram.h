//
//  driverProgram.h
//  Pandemic
//
//  Created by Ardee Aquino on 10/8/13.
//  Copyright (c) 2013 Ardee Aquino. All rights reserved.
//

#ifndef PANDEMIC_H
#define PANDEMIC_H

#include <iostream>
#include <string>
using namespace std;


class City
{
private:
	string cityName;
	int numberOfDiseases;
	bool cure;
public:
	City();
	City(string,int,bool);

	string getCityName();
	string getName();
	int getNumberOfDiseases();
	bool getCure();
};
#endif /* defined(__Pandemic__driverProgram__) */



