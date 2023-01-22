//This program tests a function which dynamically alocates memory for an array of integers.
//File: Palacios_ch9_1.cpp
//Author: John Palacios
//Created: September 13, 2013, 10:11 PM

#include<iostream>
#include<cmath>
#include<ctime>
using namespace std;

int *allocate(int);
//This function dynamically allocates memory for an array.

void printArray(const int * const, const int);
//A simple function to print the contents of a pointer.

int main()
{
	int *randArray;		//Pointer to array of random numbers to be allocated in *allocate;
	int quantity;		//The quantity of random numbers to be generated.
	char answer;		//User's reply to loop request.

	cout << "This program simply tests the function allocate by\n"
		<< "filling a dynamically allocated array with a set of\n"
		<< "psuedo-randomly chosen numbers. Please follow the \n"
		<< "prompts as they appear, thank you.\n";

	do
	{	
		do
		{
		cout << "Please enter the length of the set of random\n"
			<< "numbers greater than zero.\n";
		cin >> quantity;
		cout << endl;
		}while (quantity < 1);
		randArray = allocate(quantity);
		printArray(randArray, quantity);
		cout << "\n\nWould you like to make another array?\n"
			<< "Type y to run again.\n";
		cin >> answer;
		cout << endl;
	}while(answer == 'y' || answer == 'Y');

	//Free up memory.
	delete [] randArray;
	randArray = 0;

	return 0;
}

int *allocate(int num)
{
	int *set;				//local pointer variable to be returned by *alocate.
	set = new int[num];
	
	//set current time to seed number for rand.
	srand( static_cast<unsigned int>(time(0)));

	for(int i = 0; i < num; i++)
	{
		*(set + i) = rand() % 9;
	}
	return set;
}

void printArray(const int * const arr, const int size)
{
	cout << "Your array looks like...\n";

	//Produce a block format filled with at most 20 numbers
	//per line of block.
	for(int i = 0; i < size; i++)
	{
		cout << *(arr + i) << " ";
		if(i%20 == 19)
		{
			cout << endl;
		}
	}
}