//This simple program demonstrates a function which counts the number of words in a string of input and 
// and the average number of letters per word, then returns a pointer to a float array. The zeroth element is the number
//of words in the string, and the first element is the average number of letters per world.
//File: Palacios_Gaddis_SeventhEd_Ch10_4.cpp
//Author: John Palacios
//Created: 10-10-2013 04:38 PM

#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
using namespace std;

//Returns a pointer to a float array, where the zeroth element are the number of words in the input, and the first element
//is the average number of letters per word.
float *numWordsAvgLet(const char *);

int main()
{
	const int maxSize = 201;		//The maximum input size.
	float *numAvgLet;				//two elemnt float array; zeroth elem is number of words, and first is avg letters per word.
	string choice;					//a string pointing to the user's reply.
	char input[maxSize];			//this is a c style string containing at most maxSize - 1 characters.

	cout << "This small program tests a function which returns the number of\n"
		<< "words and the average number of letters per word. Please follow the\n"
		<< "prompts as they appear, thank you.\n";

	do
	{
		cout << "Please enter a string of characters to test this function.\n"
			<< "(Please enter fewer than " << maxSize << " characters.)\n";
		cin.getline(input, maxSize);
		numAvgLet = numWordsAvgLet(input);
		cout << "There were " << *(numAvgLet) << " words found in your input which\n"
			<< "contain " << *(numAvgLet + 1) << " letters on average.\n";
		cout << "Would you like to run again? Type y to run again.\n";
		getline(cin, choice);
	}while (tolower(choice[0]) == 'y');

	return 0;
}

float *numWordsAvgLet(const char *cstr)
{
	int i = 0;			//This is the primary itteration counter.
	int spaces = 0;		//The number of spaces encountered in char array.
	int letters = 0;	//Total number of alphabetic characters in array.
	float *numNavg = new float[2];	//This is the array returned by this function.		
	
	while(cstr[i] != NULL)
	{
		if(isspace(cstr[i]))
		{
			spaces++;
		}
		if(isalpha(cstr[i]))
		{
			letters++;
		}
		i++;
	}
	numNavg[0] = static_cast<float>(spaces + 1);
	numNavg[1] = letters / numNavg[0];
	return numNavg;
}