//This class represents a quadrangle.
//File: Rectangle.h
//Author: John Palacios

#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "BasicShape.h"

class Rectangle : public BasicShape
{
private:
	long width;
	long length;
public:
	Rectangle(long w, long l) : BasicShape()
	{ width = w, length = l, calcArea(); }
	long getWidth()
	{ return width; }
	long getLength()
	{ return length; }
	void calcArea();
};

#endif /* RECTANGLE_H */