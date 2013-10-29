#ifndef _CITY_H
#define _CITY_H

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



