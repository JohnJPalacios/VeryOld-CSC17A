//Implementation file for Rectangle class.
//File: Rectangle.cpp
//Author: John Palacios

#include "Rectangle.h"

void Rectangle::calcArea()
{
	float area;
	area = static_cast<float>(length * width);
	setArea(area);
}