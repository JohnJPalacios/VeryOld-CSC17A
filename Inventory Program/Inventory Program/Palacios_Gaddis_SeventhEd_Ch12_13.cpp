//This program allows the user to manipulate a crude database.
//File: Palacios_Gaddis_SeventhEd_Ch12_13.cpp/main.
//Author: John Palacios
//Created: 10-13-2013 10:07 PM

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cctype>
#include "Palacios_Gaddis_SeventhEd_Ch12_13.h"
using namespace std;

void displayItem(InventoryItem);
//Displays selected item to screen.

void editItem(fstream &, InventoryItem, long);
//Changes values of item at pos.

bool goodMonth(char mm[]);
//input validation support function.

bool goodDay(char dd[]);
//input validation support function.

bool goodYear(char yyyy[]);
//input validation support function.

void displayMenu(int);
//precondition: none.
//postcondition: a menu of 4 choices are displayed to the screen for the user.

int getChoice();
//precondition: none.
//postcondition: getChoice returns an int value corresponding to user input, if no int.
//value corresponds to user input, ask the user for input untill an int is entered.

int main()
{
	InventoryItem item;								//data for one item.
	InventoryItem blank = {"", 0, 0.0, 0.0, ""};	//Blank inventory item.
	long int pos;									//file position.
	fstream dataFile;								//file object.
	int choice;										//User's menu choice.
	char answer;									//User's reply to prompt.
	int numItems = 0;								//The number of items stored in binary dataFile.

	cout << "This program allows a user to interact with a crude database.\n"
		<< "Please follow the prompts as they appear, thank you.\n";

	dataFile.open("database.dat", ios::in | ios::out | ios::binary);
	if(dataFile.fail())
	{
		cout << "Error occured while connecting to local database.\n";
		exit(0);
	}

	dataFile.seekg(0L, ios::end);
	numItems = dataFile.tellg() / sizeof(item);
	dataFile.seekg(0L, ios::beg);

	do
	{
		displayMenu(numItems);
		choice = getChoice();

		switch(choice)
		{
		case 1:
			dataFile.seekp(0L, ios::end);
			dataFile.write(reinterpret_cast<char *>(&blank), sizeof(blank));
			numItems++;
			cout << "Added item " << numItems -1 << " to inventory.\n"
				<< "Chose option 3 to edit this item.\n";
			break;

		case 2:
			do
			{
				cout << "Which Item would you like to display?\n"
					<< "up to: " << numItems - 1 << endl;
				cin >> pos;
			}while (pos < 0 || pos > numItems - 1);
			dataFile.seekg(pos * sizeof(item), ios::beg);
			dataFile.read(reinterpret_cast<char *>(&item), sizeof(item));
			displayItem(item);
			break;

		case 3:
			do
			{
				cout << "Which Item would you like to edit?\n"
					<< "up to: " << numItems - 1 << endl;
				cin >> pos;
			}while (pos < 0 || pos > numItems - 1);
			dataFile.seekg(pos * sizeof(item), ios::beg);
			dataFile.read(reinterpret_cast<char *>(&item), sizeof(item));
			displayItem(item);
			cout << "Edit this item? Are you sure? Enter y to edit file.\n";
			cin >> answer;
			if (tolower(answer) == 'y')
			{
				editItem(dataFile, item, pos);
				break;
			}
			else
				break;

			break;

		case 4:
			cout << "Thank you for using my application, good bye.\n";
			break;
		}

	}while(choice != 4);

	dataFile.close();
	return 0;
}

void displayMenu(int numItems)
{
	cout << "There are: " << numItems << " items in datafile, starting at 0.\n"
		<< "Enter 1 to ADD an item record to datafile.\n"
		<< "Enter 2 to VIEW an item record in datafile.\n"
		<< "Enter 3 to EDIT an item record in datafile.\n"
		<< "Enter 4 to EXIT program.\n";
}

int getChoice()
{
	char input;		//raw unvalidated user input.
	int choice;		//corresponding integer value to validated user input.

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

void displayItem(InventoryItem item)
{
	cout << setprecision(2) << fixed << endl;
	cout << "description: " << item.description << endl;
	cout << "Items on hand: " << item.itmsOnHand << endl;
	cout << "Wholesale cost: " << item.wholeCost << endl;
	cout << "Retail cost: " << item.retCost << endl;
	cout << "Date added: " << item.dateAdd << endl;
	cout << endl;
}

void editItem(fstream &dataFile, InventoryItem item, long pos)
{
	int iOH;						//Items on hand.
	float wCost;					//Wholseale cost to purchase.
	char mm[3];						//two char month.
	char dd[3];						//Two char day.
	char yyyy[5];					//four char year.
	char date[DATE_SIZE] = "";		//ten char date.

	cout << "Please enter the new data:\n";
	cout << "Description:\n";
	cin.ignore();
	cin.getline(item.description, DESC_SIZE);
	cout << "Date added to inventory:\n";
	do
	{
		cout << "Please enter the month in the form mm\n";
		cin.getline(mm, 3);
	}while (!goodMonth(mm));

	do
	{
		cout << "Please enter the day in the form dd\n";
		cin.getline(dd, 3);
	}while (!goodDay(dd));

	do
	{
		cout << "Please enter the year in the form yyyy\n";
		cin.getline(yyyy, 5);
	}while (!goodYear(yyyy));
	date[0] = mm[0];
	date[1] = mm[1];
	date[2] = '-';
	date[3] = dd[0];
	date[4] = dd[1];
	date[5] = '-';
	date[6] = yyyy[0];
	date[7] = yyyy[1];
	date[8] = yyyy[2];
	date[9] = yyyy[3];
	strncpy(item.dateAdd, date, 11);

	do
	{
		cout << "Number of items on hand:\n(must be positive value)\n";
		cin >> iOH;
	}while (iOH < 0);
	item.itmsOnHand = iOH;

	do
	{
		cout << "Wholesale cost:\n(must be positive value)\n";
		cin >> wCost;
	}while (wCost < 0);
	item.wholeCost = wCost;
	item.retCost = wCost * STATE_TAX;
	dataFile.seekp(pos * sizeof(item), ios::beg);
	dataFile.write(reinterpret_cast<char *>(&item), sizeof(item));
}

bool goodMonth(char mm[])
{
	int tens = mm[0] - 48;			//Tens digit.
	int ones = mm[1] - 48;			//ones digit.
	int month = tens * 10 + ones;	//Value of month.
	bool goodInput;					//Return value of function.

	//Check to be sure that chars entered are digits.
	if(isdigit(mm[0]) && isdigit(mm[1]))
	{
		//Check value range.
		if(month >= 1 && month <= 12)
			goodInput = true;
	}
	else
		goodInput = false;

	return goodInput;
}

bool goodDay(char dd[])
{
	int tens = dd[0] - 48;			//Tens digit.
	int ones = dd[1] - 48;			//ones digit.
	int day = tens * 10 + ones;		//Value of day.
	bool goodInput;					//Return value of function.

	//Check to be sure that chars entered are digits.
	if(isdigit(dd[0]) && isdigit(dd[1]))
	{
		//Check value range.
		if(day >= 1 && day <= 31)
			goodInput = true;
	}
	else
		goodInput = false;

	return goodInput;
}

bool goodYear(char yyyy[])
{
	int thousands = yyyy[0] - 48;												//thousands digit.
	int hundereds = yyyy[1] - 48;												//hundereds digit.
	int tens = yyyy[2] - 48;													//Tens digit.
	int ones = yyyy[3] - 48;													//ones digit.
	int Year = (thousands * 1000) + (hundereds *100) + (tens * 10) + ones;		//value of year.
	bool goodInput;																//Return value of function.

	//Check to be sure that chars entered are digits.
	if(isdigit(yyyy[0]) && isdigit(yyyy[1]) && isdigit(yyyy[2]) && isdigit(yyyy[3]))
	{
		//Check value range.
		if(Year >= 1995 && Year <= 2013)
			goodInput = true;
	}
	else
		goodInput = false;

	return goodInput;
}