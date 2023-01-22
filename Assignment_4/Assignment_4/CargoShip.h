//Prototpe file for CargoShip class who tracks it's tonnage.
//File: CargoShip.h
//Author: John Palacios

#ifndef CARGOSHIP_H
#define CARGOSHIP_H
#include "Ship.h"

class CargoShip : public Ship
{
private:
	int cargoCap;
public:
	CargoShip() : Ship()
	{ cargoCap = 0; }
	CargoShip(int cap, string name, string built) : Ship(name, built)
	{ cargoCap = cap; }
	void setCap(int cap)
	{ cargoCap = cap; }
	int getCap()
	{ return cargoCap; }
	void virtual prntInfo();
};

#endif /* CARGOSHIP_H */