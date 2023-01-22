//Implementation file for the DynNumArray class.
//File: DynamicNumberArray.cpp
//Author: John Palacios

#include "DynamicNumberArray.h"
#include <iostream>
using namespace std;

DynNumArray::DynNumArray(int length){
	size = length;
	dynArray = new float[size];

	genVals();
}

float DynNumArray::calcHighest(){
	float highest = srtedArr[size - 1];

	return highest;
}

float DynNumArray::calcLowest(){
	float lowest = srtedArr[0];
	
	return lowest;
}

float DynNumArray::calcAverage(){
	float sum = 0;

	for(int i = 0; i < size; i++){
		sum += dynArray[i];
	}

	return sum / size;
}

float *DynNumArray::copyVals(){

	float *copy = new float[size];

	for(int i = 0; i < size; i++)
	{
		*(copy + i) = *(dynArray + i);
	}

	return copy;
}

void DynNumArray::sortVals(){
	int startScan;			//This is the current index to place smallest value
	int minIndex;			//thie is the index of the current smallest value
	float minValue;			//this is the current smallest value

	srtedArr = copyVals();

	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;
		minValue = srtedArr[startScan];

		for (int i = startScan + 1; i < size; i++)
		{
			if (srtedArr[i] < minValue)
			{
				minValue = srtedArr[i];
				minIndex = i;
			}
		}
		srtedArr[minIndex] = srtedArr[startScan];
		srtedArr[startScan] = minValue;
	}
}

void DynNumArray::genVals(){
	srand(static_cast<unsigned int>(time(0)));
	for(int i = 0; i < size; i++){
		dynArray[i] = rand() % 1000 / 99.9f;
	}

	sortVals();
}

void DynNumArray::setVal(int pos, float val){
	dynArray[pos] = val;

	delete [] srtedArr;

	sortVals();
}

void DynNumArray::prntVals() const{
	cout << endl;
	for(int i = 0; i < size; i++){
		cout << dynArray[i] << " ";
	}
	cout << endl;
}