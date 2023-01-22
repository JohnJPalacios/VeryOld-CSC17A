//This program demonstrates the use of a structure containing a two dimensional array data member.
//File: Palacios_Ch11_0\Palacios_Ch11_0_main.cpp
//Author: John Palacios
//Created: 09-26-2013 10:30 AM

#include<iostream>
#include<cstdlib>
#include<ctime>
#include"TwoDArray.h"
using namespace std;

TwoDArray *fillStruct(int, int);
//Returns a TwoDArray struct with members populated with random numbers.

void printStruct(TwoDArray *);
//Prints values of TwoDArray struct in a block format resembling a table.

void deleteStruct(TwoDArray *);
//dealocates data, then deletes the pointer.

int main()
{
	TwoDArray *arr1;		//Pointer to first created struct.
	TwoDArray *arr2;		//Pointer to second created struct.

	//Seed f(x) rand.
	srand(static_cast<unsigned int>(time(0)));

	//Alocate memory and populate two dimensional arrays.
	arr1 = fillStruct(3, 3);
	arr2 = fillStruct(4, 4);

	//print the values contained in the structs.
	printStruct(arr1);
	printStruct(arr2);

	//Return memory to the free store.
	deleteStruct(arr1);
	deleteStruct(arr2);

	arr1 = 0;
	arr2 = 0;

	return 0;
}

TwoDArray *fillStruct(int cols, int rows)
{
	//Create pointer to structure
	TwoDArray *arr = new TwoDArray;

	//Set row and col data members
	arr ->col = cols;
	arr ->row = rows;

	//populate the two dimensional array.
	arr ->data = new int* [rows];
	for(int row = 0; row < rows; row++)
	{
		arr ->data[row] = new int [cols];
	}
	for(int row = 0; row < rows; row++)
	{
		for(int col = 0; col < cols; col++)
		{
			arr ->data[row][col] = rand() % 90 + 10;
		}
	}

	return arr;
}

void printStruct(TwoDArray *arr)
{
	cout << endl;
	for(int row = 0; row < arr ->row; row++)
	{
		for(int col = 0; col < arr ->col; col++)
		{
			cout << arr ->data[row][col] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void deleteStruct(TwoDArray *arr)
{
	//Return the allocated memory to the free store.
	for(int row = 0; row < arr ->row; row++)
	{
		delete [] arr ->data[row];
	}
	delete [] arr ->data;
	delete arr;
}