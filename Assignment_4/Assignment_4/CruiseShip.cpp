//Implementation file for the CruiseShip class.
//File: CruiseShip.cpp
//Author: John Palacios

#include "CruiseShip.h"

void CruiseShip::prntInfo()
{
	cout << "Cruise Ship name: " << getName() << endl;
	cout << "Number of passengers: " << getPass() << endl;
}