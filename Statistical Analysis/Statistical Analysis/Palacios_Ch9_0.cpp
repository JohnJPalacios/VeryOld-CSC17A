//This program tests three functions which calculate the mean, median, and modes of a set of numbers.
//File: Palacios_ch9_0.cpp.
//Author: John Palacios
//Created: September 15, 2013 09:55 PM

#include<iostream>
#include<cmath>
using namespace std;


float computeMean(int [], int);
//computes the mean of a set of numbers.

float findMedian(const int [], const int);
//Determines the median value of a sorted array.

int *findModes(const int [], const int);
//returns a pointer to a dynamically alocated array which contains
//the number of modes at element 0, the highest occurence of any
//mode in set at element 1, and then the modes of the set in subsequent elements.

int *genArray(int, int);
//This function generates a random array and returns a pointer to it.

void sortValues(int [], const int);
//Sorts a given array from smallest to largest using the selection sort algorythm.

void printArray(const int * const, const int);
//A simple function to print the contents of a pointer in a block format.

void printMoArr(const int * const, const int);
//This function is a specialized display function which prints the contents of the modalArray.

int *intArrCopy(const int * const, const int);
//This function returns a pointer to a copy of it's argument pointer or array.

int main()
{
	int *testArray;				//This pointer will point to the psuedo-randomly generated array.
	int *modalArray;			//This pointer will point to the array containing the number of modes,
								//the maximum frequency of occurence for any mode, and the modes of testArray.
	int size;					//This is the number of elements in the testArray.
	int modulo;					//Factor used to generate elements in testArray.
	float mean;					//This is the sum of a list of values divided by the number of elements in list;
	float median;				//This is the value of the midle element in a list of sorted values.
	char answer;				//User reply to loop request.

	cout << "This program tests three functions: mean, median, and mode.\n"
		<< "To expidite this testing, I generate a set of numbers using\n"
		<< "a number of elements, and a modulo factor entered by the user.\n"
		<< "Please follow the prompts as they appear, thank you.\n";
	do
	{
		do
		{
		cout << "Please enter a size greater than 0 for set of test values.\n";
		cin >> size;
		cout << "Please enter a modulo factor greater than 0 to generate test value range.\n";
		cin >> modulo;
		}while (size < 1 || modulo < 1);
		testArray = genArray(size, modulo);
		mean = computeMean(testArray, size);
		median = findMedian(testArray, size);
		cout << "\nThe mean value is: " << mean << endl;
		cout << "The median value is: " << median << endl;
		modalArray = findModes(testArray, size);
		printMoArr(modalArray, modalArray[0]);
		cout << "Review the values of the array:\n";
		printArray(testArray, size);

		cout << "\n\nWould you like to make another calculation?\n"
			<< "Type y to run again.\n";
		cin >> answer;
		cout << endl;
	}while(answer == 'y' || answer == 'Y');

	//Return dynamic memory to free store and ground pointers
	delete [] testArray;
	delete [] modalArray;
	testArray = 0;
	modalArray = 0;

	return 0;
}

float computeMean(int arr[], int size)
{
	int sum = 0;		//The sum of values in arr.
	float mean;			//The average of all values in arr.

	for(int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	mean = sum / static_cast<float>(size);
	return mean;
}

float findMedian(const int list[], const int size)
{
	float median;						//This is the middle value of the sorted list of values.
	int *arr;							//This is the local pointer vairable to a copy of parameter list[].
	int upperMid;						//If there are an even number of values, this is the integral value greater than size / 2.
	int lowerMid;						//If there are an even number of values, this is the integral value less than size / 2.
	float mid = (size - 1)/2.0f;		//half the size of the list.
	int test = static_cast<int>(mid);	//Value used to determine if the list is even or odd length.
	
	//copy values in list[] so as not to disturb the values in list[].
	arr = intArrCopy(list, size);

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

int *findModes(const int list[], const int size)
{
	int *arr;				//Local pointer variable for the copy of list[] parameter.
	int k = 0;				//This is the counter for potential modes and corresponding frequencies.
	int occurance = 1;		//The number of times any one number appears in arr.
	int mostFreq = 0;		//This is the greatest frequency of appearance for any value in set.
	int nModes = 0;			//This is the final number of modes found in the set.
	int *modalArray;		//Pointer to array which contains number of modes, max frequency, and modes.
	int *modes;				//Pointer to array that will contain the modes which appear in the set.
	int *frequency;			//Pointer to array that will contain the frequency of any coresponding repeated number.
	int *potential;			//pointer to array that will contain numbers which repeat themselves in the set and are potential modes.
	
	//create a copy of values to work with so as not to disturb the origional array.
	arr = intArrCopy(list, size);

	//Easiest to find modes in a sorted list of values.
	sortValues(arr, size);
	
	//create arrays for potential modes and coressponding frequencies.
	//The maximum number of modes can't be more than half of the array's size.
	potential = new int[size / 2];
	frequency = new int[size / 2];

	//Step through arr through second to last element, comparing each element 
	//with next element, a match signifies a potential mode.
	for (int i = 0; i < size - 1; i++)
	{
		int j = i + 1;					//j is a secondary itteration counter which will be a number of spaces beyond i.
		
		if(arr[i] == arr[j])
		{

			while (arr[i] == arr[j])
			{
				occurance++;
				j++;
			}
			
			if(occurance >= mostFreq)
			{
				mostFreq = occurance;
				frequency[k] = occurance;
				potential[k] = arr[i];
				k++;
			}
			
			//skip comparisons of values already found to be duplicates of potential mode.
			//Since i will be incremented in for loop after this execution, j must be one less.
			i = j - 1;
			occurance = 1;
		}
	}
	
	if (k > 0)
	{
	//Now we can narrow down the number of potential modes to the real modes, alocate memory to track those.
	modes = new int[k];
	}

	//Search for numbers which repeat themselves mostFreq times; these are our modes.
	for(int i = 0; i < k; i++)
	{
		if (frequency[i] == mostFreq)
		{
			modes[nModes] = potential[i];
			nModes++;
		}
	}

	//potential array and frequency array no longer needed.
	delete [] potential;
	delete [] frequency;
	potential = 0;
	frequency = 0;

	//build modal array.
	modalArray = new int [nModes + 2];
	modalArray[0] = nModes;
	modalArray[1] = mostFreq;
	for(int i = 2; i < k + 2; i++)
	{
		modalArray[i] = *(modes + (i - 2));
	}

	if(k > 0)
	{
	//modes no longer needed.
	delete [] modes;
	modes = 0;
	}

	return modalArray;
}

int *genArray(int num, int mod)
{
	int *set;				//local pointer variable to be returned by *genArray.
	set = new int[num];

	for(int i = 0; i < num; i++)
	{
		*(set + i) = i % mod;
	}
	return set;
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

void printMoArr(const int * const arr, const int size)
{
	if(size > 1)
	{
		cout << "There are: " << arr[0] << " modes in the set of values.\n"
			<< "The modes are: \n{";
		for(int i = 2; i < size + 1; i++)	
		{
			cout << arr[i] << ", ";
		}
		cout << arr[size + 1] << "}" << endl;
	}
	else if(size == 1)
	{
		cout << "There is 1 mode in the set of values.\n"
			<< "The mode is "<< arr[2] << endl;
	}
	else
	{
		cout << "There do not seem to be any modes in the set of values.\n";
	}

	if(arr[1] > 1)
	{
		cout << "which occur: " << arr[1] << " times in the set of values.\n";
	}
	else if(arr[1] == 1)
	{
		cout << "which occurs once in the set of values.\n";
	}
	else
	{
		cout << "\n";
	}
}

int *intArrCopy(const int * const arr, const int size)
{
	int *copy = new int[size];

	for(int i = 0; i < size; i++)
	{
		*(copy + i) = *(arr + i);
	}

	return copy;
}