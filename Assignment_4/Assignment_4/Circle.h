//this class determines some analytic geometry information concerning elipses with e = 1.
//File: Circle.h
//Author: John Palacios

#ifndef CIRCLE_H
#define CIRCLE_H
#include "BasicShape.h"
#include <cmath>
using namespace std;

class Circle : public BasicShape
{
private:
	long centerX;
	long centerY;
	float radius;
public:
	Circle(long x, long y, float rad) : BasicShape()
	{ centerX = x, centerY = y, radius = rad, calcArea(); }
	long getCenterX()
	{ return centerX; }
	long getCenterY()
	{ return centerY; }
	void calcArea();
};

#endif /* CIRCLE_H */