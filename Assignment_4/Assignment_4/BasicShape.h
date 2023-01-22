//This is a purely abstract class.
//File: BasicShape.h
//Author: John Palacios

#ifndef BASICSHAPE_H
#define BASICSHAPE_H

class BasicShape
{
private:
	float area;
public:
	BasicShape()
	{ area = 0; }
	void setArea(float ar)
	{ area = ar; }
	float getArea();
	virtual void calcArea() = 0;
};

#endif /* BASICSHAPE_H */