//Header file for DynNumArray class.
//File: DynamicNumberArray.h
//Author: John Palacios

#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

#ifndef DYNNUMARRAY_H
#define DYNNUMARRAY_H

class DynNumArray
{
private:
	int size;
	float *dynArray;
	float *srtedArr;
	//returns the highest value in dynArray;
	float calcHighest();
	//returns the lowest value in dynArray.
	float calcLowest();
	//returns the average of values in dynArray.
	float calcAverage();
	//Sorts internal array.
	void sortVals();
	//Creats a copy of the values in dynArray and stores those values in srtedArr.
	float *copyVals();
public:
	//constructor sets size and allocates mem for array of floats size size.
	DynNumArray(int);
	~DynNumArray()
	{ delete [] dynArray; delete [] srtedArr; }
	//psuedo randomly generates values for array (usefull for larger arrays.)
	void genVals();
	//sets value at int element to user input.
	void setVal(int, float);
	//Returns a value at element to screen.
	float getVal(int);
	//Calls member f(x) calcHighest, then returns that value.
	float getHighest()
	{ return calcHighest(); }
	//Calls member f(x) clalcLowest, then returns that value.
	float getLowest()
	{ return calcLowest(); }
	//Calls member f(x) calcAverage, then returns that value.
	float getAverage()
	{ return calcAverage(); }
	//returns the size of the array.
	int getSize()const
	{ return size; }
	//prints entire array and all derived values to the screen.
	void prntVals() const;
};

#endif /* DYNNUMARRAY_H */