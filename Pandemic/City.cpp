//
//  driverProgram.cpp
//  Pandemic
//
//  Created by Ardee Aquino on 10/8/13.
//  Copyright (c) 2013 Ardee Aquino. All rights reserved.
//

#include "City.h"
using namespace std;

City::City(string iName, int iNumberOfDisease, bool iCure)
{
	cityName = iName;
	numberOfDiseases = iNumberOfDisease;
	cure = iCure;
}

string City::getName()
{
	return cityName;
}
int City::getNumberOfDiseases()
{
	return numberOfDiseases;
}
bool City::getCure()
{
	return cure;
}
