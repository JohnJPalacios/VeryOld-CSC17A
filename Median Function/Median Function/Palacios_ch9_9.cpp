//This program test drives a function which determines the median of a sorted list of integers.
//File: Palacios_ch9_9.cpp
//Author: John Palacios
//Created: September 14, 2013 7:19 PM

#include<iostream>
#include<cmath>
#include<ctime>
using namespace std;

int *allocate(int);
//This function dynamically allocates memory for an array
//of random numbers.

void printArray(const int * const, const int);
//A simple function to print the contents of a pointer.

void sortValues(int [], const int);
//Sorts a given array using the selection sort algorythm.

float findMedian(int [], int);
//Determines the median value of a sorted array. Returns type
//Float instead of type double because type double in not
//necessary.

int main()
{
	int *randArray;		//Pointer to array of random numbers to be allocated in *allocate;
	int quantity;		//The quantity of random numbers to be generated.
	char answer;		//user reply to repeat loop.
	float median;		//The median of a set of numbers.

	cout << "This program tests a function named median which\n"
		<< "finds the median value in a set of values. Please\n"
		<< "follow the prompts below, thank you.\n";

	do
	{
		do
		{
		cout << "Please enter the length of the set of random\n"
			<< "Numbers to be generated to test function median.\n"
			<< "Please use a value greater than 0.\n";
		cin >> quantity;
		}while (quantity < 1);
		cout << endl;
		
		randArray = allocate(quantity);
		printArray(randArray, quantity);
		median = findMedian(randArray, quantity);
		
		cout << "\nThe median value in that set was: " << median;
		cout << "\nWould you like to find another median value?\n"
			<< "Type y to run again.\n";
		cin >> answer;
		cout << endl;
	}while(answer == 'y' || answer == 'Y');

	//Return alocated memory to free store and ground pointer.
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
		*(set + i) = rand() % 100;
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
		if(i % 20 == 19)
		{
			cout << endl;
		}
	}
}

void sortValues(int arr[], const int size)
{
	int startScan;			//This is the current index to place smallest value
	int minIndex;			//thie is the index of the current smallest value
	int minValue;			//this is the current smallest value

	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;
		minValue = arr[startScan];

		for (int i = startScan + 1; i < size; i++)
		{
			if (arr[i] < minValue)
			{
				minValue = arr[i];
				minIndex = i;
			}
		}
		arr[minIndex] = arr[startScan];
		arr[startScan] = minValue;
	}

}

float findMedian(int arr[], int size)
{
	float median;
	int upperMid;
	int lowerMid;
	float mid = (size - 1)/2.0f;
	int test = static_cast<int>(mid);
	
	//Array must be sorted to find the median value.
	sortValues(arr, size);

	//Determine if the mean of the two mid values must be derived.
	if(mid - test > 0)
	{
		upperMid = static_cast<int>(ceil(mid));

		//Static cast mid as an int to return only integral part of mid.
		//Could have used f(x) floor.
		lowerMid = static_cast<int>(mid);
		median = (*(arr + upperMid) + *(arr + lowerMid)) / 2.0f;
	}
	else
	{
		//Index must be integral, though mid may be float for calculation purposes.
		median = arr[static_cast<int>(mid)];
	}

	return median;
}