//This program tests a simple function which returns the number of characters in a c-string.
//File: Palacios_Gaddis_SeventhEd_Ch10_1.cpp
//Author: John Palacios
//Created: 10-09-2013 11:40 AM

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

//Returns the number of chars in the pointer to the c style string without altering the c style string value.
int strLength(const char *);

int main()
{
	const int maxSize = 101;		//The maximum input size.
	int size;						//This is the number of characters in input.
	string choice;					//a string pointing to the user's reply.
	char input[maxSize];			//this is a c style string containing at most maxSize - 1 characters.

	cout << "This small program tests a function which returns the number of\n"
		<< "characters in a string of input characters. Please follow the\n"
		<< "prompts as they appear, thank you.\n";

	do
	{
		cout << "Please enter a string of characters to test this function\n";
		cin.getline(input, maxSize);
		size = strLength(input);
		cout << "There are " << size << " characters in your input.\n";
		cout << "Would you like to run again? Type y to run again.\n";
		getline(cin, choice);
	}while (tolower(choice[0]) == 'y');

	return 0;
}

int strLength(const char *cstr)
{
	int i = 0;		//This is the primary itteration counter.
	
	while(cstr[i] != NULL)
	{
		i++;
	}
	return i;
}