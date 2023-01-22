//Implementation file for CargoShip class.
//File: CargoShip.cpp
//Author: John Palacios

#include "CargoShip.h"

void CargoShip::prntInfo()
{
	cout << "Ship name: " << getName() << endl;
	cout << "Cargo Capacity: " << getCap() << endl;
}