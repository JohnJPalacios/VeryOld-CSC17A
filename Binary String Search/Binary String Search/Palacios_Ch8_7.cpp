//Solution to chapter 8, problem 7
//This program uses a selection sort and binary search algorithm on an array of strings.
//File: Palacios_chap8Prob7.cpp
//Author: John Palacios
//started: 09-05-2013 03:47 PM

#include<iostream>
#include<string>
using namespace std;

//Sorting algorithm
void sortList(string [], const int);

//search algorithm
int findNamePos(const string [], const int, string);

int main()
{
	const int NUM_NAMES = 20;
	string names[NUM_NAMES] =							//A list of names to be sorted and searched through as given in problem def.
	{"Collins, Bill", "Smith, Bart", "Allen, Jim", "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
	"Taylor, Terri", "Johnson, Jill", "Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
	"James, Jean", "Weaver, Jim", "Pore, Bob", "Rutherford, Greg", "Javens, Renee", 
	"Harrison, Rose", "Setzer, Cathy", "Pike, Gordon", "Holland, Beth"};
	int searchResult;									//will be -1 if name is not found, else will be element position of name.
	string targetName;									//Target name to be found on list.
	string last;										//first input. Concatenated with first to produce targetName.
	string first;										//last input. Concatenated with last to produce targetName.
	char answer;										//User's decision to run again.

	cout << "Welcome to name search 0.0.9! This program will determine if a name is on the \n"
		<< "list of names stored in 'names,' and return its position in that list after it \n"
		<< "has been sorted in alphabetic order starting with last name. Please follow the\n"
		<< "prompts that follow.\n\n";
	
	//Organizes list of names so a binary search may be performed.
	sortList(names, NUM_NAMES);

	do
	{
		cout << "Please enter the name you wish to find (LastName, FirstName): ";
		cin >> last;
		cin >> first;
		targetName = last + " " + first;

		//Look for position of targetName.
		searchResult = findNamePos(names, NUM_NAMES, targetName);

		if (searchResult == -1)
			cout << "That name was not on the list. Be sure to type the name in the\n"
			<< "format mentioned above\n";
		else
		{
			cout << "That name was found at position " << searchResult
				<< " in names.\n";
		}
		cout << "\n\nWould you like to search for another name?\n"
			<< "Type y to search again.";
		cin >> answer;
		cout << endl;
	}while(answer == 'y' || answer == 'Y');

	return 0;
}

void sortList(string list[], const int size)
{
	//sort list using selection sort.
	int startScan;			//This is the current index to place smallest value
	int minIndex;			//thie is the index of the current smallest value
	string minValue;		//this is the current smallest value

	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;
		minValue = list[startScan];

		for (int i = startScan + 1; i < size; i++)
		{
			if (list[i] < minValue)
			{
				minValue = list[i];
				minIndex = i;
			}
		}
		list[minIndex] = list[startScan];
		list[startScan] = minValue;
	}

}

int findNamePos(const string list[], const int size, string target)
{
	//Search the sorted array using a comparison/elimination technique.
	int first = 0;			//First array element.
	int last = size -1;		//End Array element.
	int middle;				//Middle array element.
	int position = -1;		//Element of array containing target.
	bool found = false;		//state flag to end while loop.

	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if (list[middle] == target)
		{
			found = true;
			position = middle;
		}
		else if (list[middle] > target)
			last = middle - 1;
		else
			first = middle + 1;
	}
	return position;
}