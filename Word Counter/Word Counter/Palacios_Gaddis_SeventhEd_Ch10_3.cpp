//This simple program demonstrates a function which counts the number of words in a string of input and returns 
//a corresponding interger value.
//File: Palacios_Gaddis_SeventhEd_Ch10_3.cpp
//Author: John Palacios
//Created: 10-10-2013 04:06 PM

#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
using namespace std;

//Returns the number of words in the pointer to the c style string without altering the c style string value,
//also works with string objects using ".c_str()" function.
int numWords(const char *);

int main()
{
	const int maxSize = 201;		//The maximum input size.
	int qtyWords;					//This is the number of words found in input.
	string choice;					//a string pointing to the user's reply.
	char input[maxSize];			//this is a c style string containing at most maxSize - 1 characters.

	cout << "This small program tests a function which returns the number of\n"
		<< "words found in a string of input characters. Please follow the\n"
		<< "prompts as they appear, thank you.\n";

	do
	{
		cout << "Please enter a string of characters to test this function\n"
			<< "(Please enter fewer than " << maxSize << " characters.)\n";
		cin.getline(input, maxSize);
		qtyWords = numWords(input);
		cout << "There were " << qtyWords << " words found in your input.\n";
		cout << "Would you like to run again? Type y to run again.\n";
		getline(cin, choice);
	}while (tolower(choice[0]) == 'y');

	return 0;
}

int numWords(const char *cstr)
{
	int i = 0;			//This is the primary itteration counter.
	int spaces = 0;		//The number of spaces encountered in char array.
	
	while(cstr[i] != NULL)
	{
		if(isspace(cstr[i]))
		{
			spaces++;
		}
		i++;
	}
	return spaces + 1;
}