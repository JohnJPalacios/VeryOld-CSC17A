//Implementation file for the Basic shape abstract class.
//File: BasicShape.cpp
//Author: John Palacios

#include "BasicShape.h"

float BasicShape::getArea()
{ 
	calcArea();
	return area;
}