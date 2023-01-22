//This program tests a function which sums the digits in a string passed to it.
//File: Palacios_Gaddis_SeventhEd_Ch10_8.cpp
//Author: John Palacios
//Created: 10-11-2013

#include <iostream>
#include <cctype>
#include <cstring>
#include <string>
#include <iomanip>
using namespace std;

//Returns a pointer to a three element int array, where zeroth is sum of digits in input, one and two are the extrema.
int *sumChars(string);

int main()
{
	string input;			//Users's input string.
	int *sumExtrema;		//Array containing computed results of f(x) sumChars.
	string choice;			//a string pointing to the user's reply.

	cout << "This small program tests a function which will return the sum,\n"
		<< "greatest, and least digit in a string of digits typed in by the\n"
		<< "user, who is you! Please follow the prompts as they appear, thank\n"
		<< "you.\n";
	
	do
	{
		cout << "Please type some single digit numbers with no spaces and then press enter.\n";
		getline(cin, input);
		sumExtrema = sumChars(input);
		cout << "   Sum\tgreatest digit\tleast digit\n"
			<<"=>  "<< sumExtrema[0] << setw(10) << sumExtrema[1] << setw(12) << sumExtrema[2] << endl;
		cout << "Would you like to run this test again? type y for yes.\n";
		getline(cin, choice);
	}while (tolower(choice[0]) == 'y');

	delete []sumExtrema;
	return 0;
}

int *sumChars(string chars)
{
	int sum = 0;					//Accumulator for char digits.
	int highest;					//Greatest digit in chars.
	int least;						//lowest digit in chars.
	int *sumExtrema = new int[3];	//Dynamically allocated array. [0] is sum, [1] is highest, [2] is lowest.

	//preset extrema to zeroth values for comparison.
	highest = chars[0] - 48;
	least = chars[0] - 48;

	//itterate through input parsing for digits, computing sum, finding extrema.
	for(int i = 0; i < chars.size(); i++)
	{
		if(isdigit(chars[i]))
		{
			sum += chars[i] - 48;
		}
		if(isdigit(chars[i]) && (chars[i] - 48) > highest)
		{
			highest = chars[i] - 48;
		}
		if(isdigit(chars[i]) && (chars[i] - 48) < least)
		{
			least = chars[i] - 48;
		}
	}

	sumExtrema[0] = sum;
	sumExtrema[1] = highest;
	sumExtrema[2] = least;

	return sumExtrema;
}