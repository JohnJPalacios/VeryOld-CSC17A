//This program tests a function which creates a copy twice as long of a given array.
//File: Palacios_ch9_11.cpp
//Created: September 15, 2013 07:53 AM

#include<iostream>
#include<ctime>
using namespace std;

int *genArray(int);
//This function generates a random array and returns a pointer to it.

int *expandArray(const int [], const int);
//This function creates a copy of it's parameter array, allocates memory
//for an array twice as long, copies param. array, then fills the rest
//of the elements with zeros.

void printArray(const int * const, const int);
//A simple function to print the contents of a pointer in a block format.

int main()
{
	int *origional;				//This pointer will point to origional array.
	int *kingSized;				//This pointer will point to expanded array.
	int size;					//This is the size of the origional array.
	char answer;				//User's reply to loop request.

	cout << "This program tests the expandArray function which creates\n"
		<< "a copy of the given array, but doubles it's length and fills\n"
		<< "the additional elements with zeros. Please follow the prompts\n"
		<< "as the appear, thank you.\n";

	do
	{
		do
		{
		cout << "Please enter a size larger than 0 for origional array.\n";
		cin >> size;
		}while (size < 1);
		origional = genArray(size);
		printArray(origional, size);
		
		cout << "\nNow to feed your array some donuts...\n";
		kingSized = expandArray(origional, size);
		printArray(kingSized, size * 2);

		//Return dynamic memory to free store and ground pointers
		//Before asking for more memory and reusing pointers.
		delete [] origional;
		delete [] kingSized;
		origional = 0;
		kingSized = 0;

		cout << "\n\nWould you like to make another array fat?\n"
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

int *expandArray(const int arr[], const int size)
{
	int *bigSet;				//Local pointer variable for expanded array.
	bigSet = new int[size * 2];

	for(int i = 0; i < size * 2; i++)
	{
		if (i >= size)
		{
			*(bigSet + i) = 0;
		}
		else
		{
		*(bigSet + i) = arr[i];
		}
	}
	return bigSet;
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