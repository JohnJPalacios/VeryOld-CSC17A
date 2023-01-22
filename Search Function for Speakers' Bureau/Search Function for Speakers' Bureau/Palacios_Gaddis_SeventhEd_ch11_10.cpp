//This program tracks information about speakers.
//File: Palacios_Gaddis_SeventhEd_Ch11_10.cpp
//Author: John Palacios
//Created: 09/29/2013 10:31 PM

#include <iostream>
#include<cctype>
#include "Palacios_Gaddis_Seventhed_Ch11_10.h"
using namespace std;

void getDat(SpkrDat [], int);
//Allows user to populate all elements of the SpkrDat array.

void genDat(SpkrDat []);
//Populates all elements of SpkrDat array with pre-written info automatically.

void alterDat(SpkrDat [], int);
//Allows user to alter contents of any one element of SpkrDat.

SpkrDat *findSpkr(const SpkrDat [], const int, int &);
//Returns an array of SpkrDats who match the search criterion.

void displayDat(const SpkrDat [], const int);
//Displays the information for all speakers.

void displayMenu();
//precondition: none.
//postcondition: a menu of 5 choices are displayed to the screen for the user.

int getChoice();
//precondition: none.
//postcondition: getChoice returns an int value corresponding to user input, if no int.
//value corresponds to user input, ask the user for input untill an int is entered.

int main()
{
	SpkrDat *spkrs;			//Pointer to list of speakers.
	SpkrDat *results;		//Pointer to list of matching speakers.
	int size = 0;			//Size of speaker list.
	int matches = 0;		//The number of matches found by the search function.
	int choice;				//User's choice.

	cout << "Welcome to Speakers' Bureau. This program allows the user\n"
		<< "to interact with data pertaining to various speakers. Please\n"
		<< "follow the prompts as they appear, thank you.\n\n";

	do
	{
		displayMenu();
		choice = getChoice();

		switch (choice)
		{
		case 1:
			//Check to see if an array already exists.
			if(size < 1)
			{
				do
				{
					cout << "How many speakers will be on this list?\n";
					cin >> size;
				}while (size < 1);
				cin.ignore();
				spkrs = new SpkrDat[size];
				getDat(spkrs, size);
			}
			else
			{
				cout << "There is already a list of speakers in existance.\n"
					<< "Please use the one of the other options to alter the list.\n";
				break;
			}
			break;

		case 2:
			//Generate a list of default values of ten elements.
			//Check to see if an array already exists.
			if(size < 1)
			{
				size = 10;
				spkrs = new SpkrDat[size];
				genDat(spkrs);
			}
			else
			{
				cout << "There is already a list of speakers in existance.\n"
					<< "Please use the one of the other options to alter the list.\n";
				break;
			}
			break;

		case 3:
			//Search for an element.
			if (size < 1)
			{
				cout << "Please create a list of speakers to search first, thank you.\n";
				break;
			}
			else
			{
				results = findSpkr(spkrs, size, matches);
				displayDat(results, matches);
				break;
			}

		case 4:
			//Display current list of speakers.
			if (size < 1)
			{
				cout << "Please create a list of speakers to print first, thank you.\n";
				break;
			}
			else
			{
				displayDat(spkrs, size);
				break;
			}

		case 5:
			//Change values of one element.
			if (size < 1)
			{
				cout << "Please create a list of speakers to edit first, thank you.\n";
				break;
			}
			else
			{
				alterDat(spkrs, size);
				break;
			}

		case 6:
			cout << "Thank you for using my application, good bye.\n";
			break;
		}
	}while (choice != 6);

	if (size > 0)
	{
		delete [] spkrs;
	}

	if (matches > 0)
	{
		delete [] results;
	}

	return 0;
}

void genDat(SpkrDat spkrs[])
{
	string name[10] = {
		"Dr. Carl Edward Sagan", "Dr. Neil deGrasse Tyson", "Dr. Brian Cox",
		"Dr. Michio Kaku", "Dr. Avram Noam Chomsky", "Dr. Stephen Hawking",
		"Jonathan Gillette", "Dr. Walace Wang", "Yukihiro Matsumoto", "Denis Ritchie"};
	string topic[10] = {
		"Astronomy", "Astrophysics", "Particle Physics",
		"Popular physics", "Polyarchy", "Astrophysics",
		"_why Ruby?", "Personal Internet Security", "Computer Science", "Computer Science"};
	string phone[10] = {
		"(012) 345-6789", "(234) 567-8901", "(714) 555-1234", "(888) 123-4567",
		"(555) 555-5555", "(666) 666-6666", "(777) 777-7777", "(888) 888-8888",
		"(999) 999-9999", "(000) 000-0000"};
	int fee[10] = {5000, 6000, 5500, 5500, 5000, 6000, 2400, 3000, 3000, 5000}; 

				for(int i = 0; i < 10; i++)
				{
					cout << "Please enter name of speaker " << i + 1 << endl;
					spkrs[i].name = name[i];
					cout << name[i] << endl;
					cout << "Please enter " << spkrs[i].name << "'s telephone number.\n";
					spkrs[i].telephoneNum = phone[i];
					cout << phone[i] << endl;
					cout << "Please enter " << spkrs[i].name << "'s speaking topic.\n";
					spkrs[i].speakTopic = topic[i];
					cout << topic[i] << endl;
					cout << "Please enter " << spkrs[i].name << "'s speaking fee.\n"
						<< "(Value must be integral of zero or greater value in us dollars)\n";
					spkrs[i].requiredFee = fee[i];
					cout << fee[i] << endl;
					cout << "Thank you, data saved for " << spkrs[i].name << ".\n";
				}
}

void getDat(SpkrDat spkrs[], int size)
{
	int userDat;	//Unvalidated user fee data.

	for(int i = 0; i < size; i++)
	{
		cout << "Please enter name of speaker " << i + 1 << endl;
		getline(cin, spkrs[i].name);
		cout << "Please enter " << spkrs[i].name << "'s telephone number.\n";
		getline(cin, spkrs[i].telephoneNum);
		cout << "Please enter " << spkrs[i].name << "'s speaking topic.\n";
		getline(cin, spkrs[i].speakTopic);
		do
		{
			cout << "Please enter " << spkrs[i].name << "'s speaking fee.\n"
				<< "(Value must be integral of zero or greater value in us dollars)\n";
			cin >> userDat;
		}while (userDat < 0);
		spkrs[i].requiredFee = userDat;
		cout << "Thank you, data saved for " << spkrs[i].name << ".\n";
		cin.ignore();
	}
}

void alterDat(SpkrDat spkrs[], int size)
{
	int target;
	int userDat;	//Unvalidated user fee data.

	do
	{
		cout << "Please enter the number of the Speaker's entry\n"
			<< "you wish to edit. (up to " << size  << ")\n";
		cin >> target;
	}while (target < 1 || target > size);

	cin.ignore();

	//manually edit speaker's entry.
	cout << "Please enter name of speaker " << target << endl;
	target -= 1;
	getline(cin, spkrs[target].name);
	cout << "Please enter " << spkrs[target].name << "'s telephone number.\n";
	getline(cin, spkrs[target].telephoneNum);
	cout << "Please enter " << spkrs[target].name << "'s speaking topic.\n";
	getline(cin, spkrs[target].speakTopic);
	do
	{
		cout << "Please enter " << spkrs[target].name << "'s speaking fee.\n"
			<< "(Value must be integral of zero or greater value in us dollars)\n";
		cin >> userDat;
	}while (userDat < 0);
	spkrs[target].requiredFee = userDat;
	cout << "Thank you, data saved for " << spkrs[target].name << ".\n";

}

SpkrDat *findSpkr(const SpkrDat spkrs[], const int size, int &matches)
{
	cin.ignore();
	string target;			//User's key-word.
	SpkrDat *results;		//points to array holding matching speakers.
	int numMatches = 0;		//The number of times target matches a speaker.	
	int j = 0;				//Secondary itteration counter.

	cout << "Please enter the speaking topic you wish to search for.\n";
	getline(cin, target);

	for(int i = 0; i < size; i++)
	{
		if(spkrs[i].speakTopic == target)
		{
			numMatches++;
		}
	}

	if (numMatches > 0)
	{
		results = new SpkrDat[numMatches];
		for(int i = 0; i < size; i++)
		{
			if(spkrs[i].speakTopic == target)
			{
				results[j] = spkrs[i];
				j++;
			}
		}
		matches = numMatches;
		return results;
	}
	else
	{
		return 0;
	}
}

void displayDat(const SpkrDat spkrs[], const int size)
{
	if(size == 0)
	{
		cout << "There are no speakers matching your criterion.\n";
	}
	else
	{
		for(int i = 0; i < size; i++)
		{
			cout << "Speaker: " << spkrs[i].name << endl;
			cout << "Topic: " << spkrs[i].speakTopic << endl;
			cout << "Telephone number: " << spkrs[i].telephoneNum << endl;
			cout << spkrs[i].name << "'s fee: " << spkrs[i].requiredFee << endl << endl;;
		}
	}
}

void displayMenu()
{
	cout << "Enter 1 to MANUALLY create a list of speaker's data.\n"
		<< "Enter 2 to AUTOMATICALLY create a list of speker's data.\n"
		<< "Enter 3 to SEARCH the list for a speaker by topic.\n"
		<< "Enter 4 to VIEW the contents of existant speaker's list.\n"
		<< "Enter 5 to EDIT an entry in the list.\n"
		<< "Enter 6 to EXIT program.\n";
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