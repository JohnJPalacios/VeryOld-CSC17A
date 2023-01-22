//A type of Ship, the CruiseShip class maintains data concerning name and passenger count.
//File: CruiseShip.h
//Author: John Palacios

#ifndef CRUISESHIP_H
#define CRUISESHIP_H
#include "Ship.h"

class CruiseShip : public Ship
{
private:
	int numPass;
public:
	CruiseShip() : Ship()
	{ numPass = 0; }
	CruiseShip(string name, int pass) : Ship()
	{ numPass = pass, Ship::setName(name); }
	void setNumPass(int pass)
	{ numPass = pass; }
	int getPass()
	{ return numPass; }
	void virtual prntInfo();
};

#endif /* CRUISESHIP_H */