//
//  driverProgram.cpp
//  Pandemic
//
//  Created by Ardee Aquino on 10/8/13.
//  Copyright (c) 2013 Ardee Aquino. All rights reserved.
//

#include "driverProgram.h"

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
int City:: getCure()
{
	return cure;
}