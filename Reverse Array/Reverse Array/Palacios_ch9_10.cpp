//This program tests a fuction which copys a reverse image of a given array.
//File: Palacios_ch9_10.cpp
//Author: John Palacios
//Created: September 15, 2013 07:43 AM

#include<iostream>
#include<ctime>
using namespace std;

int *genArray(int);
//This function generates a random array and returns a pointer to it.

int *reverseCopy(const int [], const int);
//This function copys an int array, but in reverse order.

void printArray(const int * const, const int);
//A simple function to print the contents of a pointer.

int main()
{
	int *origional;			//Pointer to origional array to be copied.
	int *mirror;			//Pointer to reverse copied array.
	int size;				//The number of elements in the array.
	char answer;			//User's reply to loop prompt.

	cout << "This program creates a random array of integral values\n"
		<< "and then creates a copy of that array with elements in \n"
		<< "reverse order. Please follow the prompts as they appear,\n"
		<< "Thank you.\n";

	do
	{
		do
		{
		cout << "Please enter a size greater than zero for origional array.\n";
		cin >> size;
		}while (size < 1);
		origional = genArray(size);
		printArray(origional, size);

		cout << "\nNow to copy your array in reverse order...\n";
		mirror = reverseCopy(origional, size);
		printArray(mirror, size);

		//Return dynamic memory to free store and ground pointers
		//Before asking for more memory and reusing pointers.
		delete [] origional;
		delete [] mirror;
		origional = 0;
		mirror = 0;

		cout << "\n\nWould you like to mirror another array?\n"
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

int *reverseCopy(const int arr[], const int size)
{
	int *mirror;						//Local pointer variable for reversed arr.
	mirror = new int[size];

	for(int i = 0, r = size - 1; i < size; i++, r--)
	{
		*(mirror + i) = arr[r];
	}
	
	return mirror;
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