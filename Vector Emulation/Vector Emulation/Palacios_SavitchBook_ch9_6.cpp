//This program emulates vector ability to add or remove elements using two functions
//Which return pointers to new dynamically created arrays with the desired alteration.
//Author: John Palacios
//File: Palacios_SavitchBook_ch9_6.cpp
//Created: 09/19/13 04:35 PM

#include<iostream>
#include<string>
#include<cctype>
using namespace std;

string* addEntry(string *, int &, string);
//This function adds newEntry to dynamicArray, adding one to the size of the array.

string* deleteEntry(string *, int &, string);
//This function removes entryToDelete from dynamicArray if entryToDelete is found
//in dynamicArray, decrimenting size.

void displayMenu();
//precondition: none.
//postcondition: a menu of five choices are displayed to the screen for the user.

int getChoice();
//precondition: none.
//postcondition: getChoice returns an int value corresponding to user input, if no int.
//value corresponds to user input, ask the user for input untill an int is entered.

void printArray(const string * const, const int);
//A simple function to print the contents of a pointer in a block format.

int main()
{
	string *list;			//This is the pointer variable to our list of string values.
	string elem;			//This is the string value entered by user.
	int size = 0;			//This is the number of string objects in list.
	int choice;				//This is the user's choice of action.
	
	cout << "This program tests two functions called addEntry, and deleteEntry\n"
		<< "which allow a dynamically alocated array to act as a vector; adding\n"
		<< "or removeing elements dynamically, thus altering the size of the list\n"
		<< "dynamically. Please follow the prompts as they appear, thank you.\n\n";

	do
	{
		displayMenu();
		choice = getChoice();
		
		switch (choice)
		{
		case 1:
			//check to see if array of elements already exists.
			if(size < 1)
			{
			//create array of elements.
				do
				{
				cout << "How many string elements will be on this list?\n";
				cin >> size;
				}while(size < 1);
				list = new string[size];

				for(int i = 0; i < size; i++)
				{
					cout << "Please enter item " << i + 1 << ".\n";
					cin >> elem;
					list[i] = elem;
				}

			}
			else
			{
				cout << "A list of elements already exists. Please add or delete\n"
					<< "elements using one of the provided options.\n";
				break;
			}
			break;

		case 2:
			//add user string to list.
			if(size > 0)
			{
			cout << "Please enter the element to be added.\n";
			cin >> elem;
			list = addEntry(list, size, elem);
			}
			else
			{
				cout << "Please create a list of elements first.\n";
				break;
			}
			break;

		case 3:
			//remove user string from list.
			if(size > 0)
			{
			cout << "Please enter the element to be deleted.\n";
			cin >> elem;
			list = deleteEntry(list, size, elem);
			}
			else
			{
				cout << "Please create a list of elements first.\n";
				break;
			}
			break;

		case 4:
			//display array to screen.
			if(size > 0)
			{
			printArray(list, size);
			}
			else
			{
				cout << "There is nothing to display yet! Please create a list first.\n";
				break;
			}
			break;
			
		case 5:
			cout << "Exiting program...\n";
			break;

		default:
			cout << "Error: That input was not anticipated, please try again.\n"
				<< "Choices are 1, 2, 3, 4, or 5.\n";
		}


	}while(choice != 5);

	cout << "Thank you for using my application. Good bye.\n";

	return 0;
}

string* addEntry(string *dynamicArray, int &size, string newEntry)
{
	string *newArray;
	newArray = new string[size + 1];

	for(int i = 0; i < size; i++)
	{
		newArray[i] = dynamicArray[i];
	}
	newArray[size] = newEntry;
	size = size + 1;

	//dynamicArray no longer needed, return memory to the freestore.
	delete []dynamicArray;

	return newArray;
}

string* deleteEntry(string *dynamicArray, int &size, string entryToDelete)
{
	string *newArray;				//This is the pointer variable to our new list of string values.
	int j = 0;						//secondary itteration counter for dynamicArray.
	int position = -1;				//The element position of entryToDelete.

	for(int i = 0; i < size; i++)
	{
		if(dynamicArray[i] == entryToDelete)
		{
			position = i;
		}
	}

	if(position > -1 && position < size)
	{
		newArray = new string[size - 1];

		for(int i = 0; i < size - 1; i++)
		{


			if(dynamicArray[i] == entryToDelete)
			{
				//Do nothing
			}
			else
			{
				newArray[j] = dynamicArray[i];
				j++;
			}
		}
		
		//Return memory allocated to dynamicArray back to free store.
		delete []dynamicArray;
		size = size - 1;
	}

	//Determine which array to return based on encountering entryToDelete.
	if(position == -1)
	{
		//Element not found, do not alter array.
		return dynamicArray;
	}
	else
	{
	return newArray;
	}
}

void displayMenu()
{
	cout << "Enter 1 to CREATE a list of string elements.\n"
		<< "Enter 2 to ADD an element to the list of string elements.\n"
		<< "Enter 3 to DELETE an element from the list of string elements.\n"
		<< "Enter 4 to DISPLAY current list.\n"
		<< "Enter 5 to EXIT program.\n";
}

int getChoice()
{
	char input;		//raw unvalidated user input.
	int choice;		//corresponding integer value to validated user input... hopefully.

	do
	{
	cin >> input;
	if(!isdigit(input))
		cout << "Error: That is not a valid choice; please try again.\n";
	else
		choice = input - 48;
	}while(!isdigit(input));

	return choice;
}

void printArray(const string * const arr, const int size)
{
	cout << "Your list looks like...\n";

	for(int i = 0; i < size; i++)
	{
		cout << *(arr + i) << " ";
	}
	cout << endl;
}