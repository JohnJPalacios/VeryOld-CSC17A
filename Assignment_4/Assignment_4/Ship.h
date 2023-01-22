//Abstract class Ship to be inherited from.
//File: Ship.h
//Author: John Palacios

#ifndef SHIP_H
#define SHIP_H
#include <string>
#include <iostream>
using namespace std;

class Ship
{
private:
	string name;
	string built;
public:
	Ship()
	{ name = "", built = ""; }
	Ship(string n, string date)
	{ name = n, built = date; }
	void setName(string n)
	{ name = n; }
	void setDate(string date)
	{ built = date; }
	string getName()
	{ return name; }
	string getBuilt()
	{ return built; }
	virtual void prntInfo();
};

#endif /* SHIP_H */