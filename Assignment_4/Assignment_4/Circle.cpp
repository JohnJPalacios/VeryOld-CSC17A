//Implementation file for the Circle class.
//File: Circle.cpp
//Author: John Palacios

#include "Circle.h"
#include <iostream>
using namespace std;

void Circle::calcArea()
{
	float area;
	area = static_cast<float>(4*atan(1.0)) * radius * radius;
	setArea(area);
}