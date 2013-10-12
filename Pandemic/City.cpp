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
