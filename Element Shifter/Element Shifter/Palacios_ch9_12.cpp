//This program tests a function which shifts the elements of a given array
//up one element, filling element zero with 0, and elongating the array by one element.
//File: Palacios_ch9_12.cpp
//Author: John Palacios
//Created: September 15, 2013 09:50 AM

#include<iostream>
#include<ctime>
using namespace std;

int *genArray(int);
//This function generates a random array and returns a pointer to it.

int *shiftVals(const int [], const int);
//This function creates a copy of param array with one more element,
//elment 0 of new array contains zero, all other elements are copies
//of param array values, increased by one element position.

void printArray(const int * const, const int);
//A simple function to print the contents of a pointer in a block format.

int main()
{
	int *origional;				//This pointer will point to origional array.
	int *longerCopy;			//This pointer will point to the longer copy of origional.
	int size;					//This is the size of the origional array.
	char answer;				//User's reply to loop request.

	cout << "This program tests the shiftVals function which creates\n"
		<< "a copy of the origional array, but increases it's length\n"
		<< "by one element, and shifts all copies of origional values\n"
		<< "up one element in the longer copy. Element zero will\n"
		<< "contain the value '0'. Please follow the prompts as they\n"
		<< "appear, thank you.\n";

	do
	{
		do
		{
		cout << "Please enter a size larger than 0 for origional array.\n";
		cin >> size;
		}while (size < 1);
		origional = genArray(size);
		printArray(origional, size);

		cout << "\nNow to add 0 to the front of that array...\n";
		longerCopy = shiftVals(origional, size);
		printArray(longerCopy, size + 1);

		//Return dynamic memory to free store and ground pointers
		//Before asking for more memory and reusing pointers.
		delete [] origional;
		delete [] longerCopy;
		origional = 0;
		longerCopy = 0;

		cout << "\n\nWould you like to make another longer copy of an array?\n"
			<< "Type y to run again.\n";
		cin >> answer;
		cout << endl;
	}while(answer == 'y' || answer == 'Y');

	return 0;
}

int *genArray(int num)
{
	int *set;				//local pointer variable to be returned by *genArray.
	set = new int[num];
	
	//set current time to seed number for rand.
	srand( static_cast<unsigned int>(time(0)));

	for(int i = 0; i < num; i++)
	{
		*(set + i) = rand() % 9;
	}
	return set;
}

int *shiftVals(const int arr[], const int size)
{
	int *newSet;					//Local pointer variable to hold longer array. Returned by function.
	newSet = new int[size + 1];

	*newSet = 0;
	for(int i = 1; i < (size + 1); i++)
	{
		*(newSet + i) = arr[i - 1];
	}

	return newSet;
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