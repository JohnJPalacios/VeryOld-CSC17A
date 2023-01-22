/*This program analizes a list of values in a file specified by the user in the current directory.
 *File: Palacios_ch7_6.cpp
 *Author: John Palacios
 *Created on September 3, 2013, 10:35 AM
 */

#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

//Get name of data file form user.
void getFile(char []);

//Load values from file into array.
void loadValues(char [], short &, const short, short []);

//Find maxima, minima, sum, and average of values.
void analyze(short [], short &, short &, short &, float &, int &);

//print results of analysis to screen.
void showReport(const short, const short, const int, const float);

int main(int argc, char** argv)
{
	const short ARRAY_SIZE = 100;		//number of elements available in array.
	short numArray[ARRAY_SIZE];			//Array with unfilled elements. Will hold values read form file.
	short lastIndexUsed = 0;			//The greatest index with used element.
	char fileName[65];					//User entered file name to load values from.
	short lowest;						//lowest value from fileName.
	short highest;						//Highest value from fileName.
	float average;						//Average of all values from fileName.
	int total;							//Sum of all values from fileName.
	char answer;						//user reply to test loop prompt.
	
	cout << "Welcome to number analysis 0.1.0! This program will analyze a set of numbers\n"
		<< "stored in a file as plain text. Please follow the prompts that follow.\n\n";
	do
	{
		getFile(fileName);
		loadValues(fileName, lastIndexUsed, ARRAY_SIZE, numArray);
		analyze(numArray, lastIndexUsed, highest, lowest, average, total);
		showReport(lowest, highest, total, average);
		cout << "\n\nWould you like to make another report?\n"
			<< "Type y to run again.";
		cin >> answer;
		cout << endl;
	}while(answer == 'y' || answer == 'Y');

	return 0;
}

void getFile(char fileName[])
{
	cout << "\nPlease enter the name of the file to read values from. No spaces please.\n";
	cin >> fileName;
}

void loadValues(char fileName[], short &lastIndexUsed, const short ARRAY_SIZE, short numArray[])
{
	ifstream dataFile;		//input file stream object instantiation.

	cout << "Loading data from " << fileName << "...\n\n";
	dataFile.open(fileName);
	if(dataFile.fail())
	{
		cout << "Failure to open data file.";
		exit(1);
	}

	//check number of values in file and load them into array.
	while(lastIndexUsed < ARRAY_SIZE && dataFile >> numArray[lastIndexUsed])
		lastIndexUsed ++;

	dataFile.close();
	dataFile.clear();

	cout << "Values successfully loaded from " << fileName << ".\n";
}

void analyze(short numArray[], short &lastIndexUsed, short &highest, short &lowest, float &average, int &total)
{
	total = 0;					//Acumulator used to sum all elements in numArray.
	highest = numArray[0];		//Will contain highest value in numArray after for loop completion.
	lowest = numArray[0];		//Will contain lowest value in numArray after for loop completion.

	//Look for Highest value, lowest value and sum of values in one pass.
	for(short i = 1; i < lastIndexUsed; i++)
	{
		total += numArray[i];

		if (numArray[i] < lowest)
		{
			lowest = numArray[i];
		}

		if (numArray[i] > highest)
		{
			highest = numArray[i];
		}
	}

	//compute average value of array.
	average = static_cast<float>(total) / lastIndexUsed;
}

void showReport(const short lowest, const short highest, const int total, const float average)
{
	//output extremes, sum and verage.
	cout << setprecision(5) << fixed
		<< left << setw(25) << "Lowest number in array: " << setw(10) << right << lowest << endl
		<< left << setw(25) << "Highest number in array: " << setw(10) << right << highest << endl
		<< left << setw(25) << "Sum of array: " << setw(10) << right << total << endl
		<< left << setw(25) << "Average value of array: " << setw(10) << right << average << endl;
}