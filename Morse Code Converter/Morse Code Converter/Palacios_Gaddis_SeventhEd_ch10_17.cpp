//This program tests several functions which turn user character input into Morse code.
//File: Palacios_Gaddis_SeventhEd_ch10_17.cpp
//Author: John Palacios
//Created: 10-12-2013

#include <iostream>
#include <string>
using namespace std;

//This function parses string input and returns a morse code equivelent.
string *encodeMorse(string);

//encodeMorse support function for punctuation.
string encodePunct(char);

//supports encodeMorse, specializing in numerals.
string encodeNum(char);

//supports encodeMorse, specializing in alphbetic characters.
string encodeAlpha(char);

//Prints the encoded string to the screen.
void prntCode(string [], int);

int main()
{
	string input;
	string *output;
	string choice;			//User reply to loop request.

	cout << "This program test several functions who encode your input into Morse code!\n"
		<< "Please follow the prompts as they appear, thank you.\n";

	do
	{
	cout << "Please enter a string of input.\n";
	getline(cin, input);
	output = encodeMorse(input);
	prntCode(output, input.size());
	cout << "Would you like to run again? Enter y to run again.\n";
	getline(cin, choice);
	}while(tolower(choice[0]) == 'y');

	delete [] output;
	return 0;
}

string *encodeMorse(string input)
{
	string *codedString;	//Two dimensional string array of string pointers.
	
	codedString = new string [input.length()];

	for (int i = 0; i < input.length(); i++)
	{
		if(isspace(input[i]))
		{
			codedString[i] = " ";
		}

		else if(ispunct(input[i]))
		{
			codedString[i] = encodePunct(input[i]);
		}
		
		else if(isdigit(input[i]))
		{
			codedString[i] = encodeNum(input[i]);
		}

		else if(isalpha(input[i]))
		{
			codedString[i] = encodeAlpha(input[i]);
		}
	
	}

	return codedString;
}

string encodePunct(char input)
{
	string codedPunct;

		if(input == ',')
		{
			codedPunct = "--..--";
		}

		else if(input == '.')
		{
			codedPunct = ".-.-.-";
		}

		else if(input == '?')
		{
			codedPunct = "..--..";
		}

		else if(input == '\'')
		{
			codedPunct = ".----.";
		}

		else if(input == '!')
		{
			codedPunct = "-.-.--";
		}

		else if(input == '/')
		{
			codedPunct = "-..-.";
		}

		else if(input == '(')
		{
			codedPunct = "-.--.";
		}

		else if(input == ')')
		{
			codedPunct = "-.--.-";
		}
		else
		{
			codedPunct = "?";
		}

	return codedPunct;
}

string encodeNum(char input)
{
	string codedNum;							//Eventual output.
	int first;									//number of first characters.
	int last;									//Number of last characters.
	int val = static_cast<int>(input - 48);		//ascii decimal value of input char.

	if(val <= 5)
	{
		first = val;
		last = 5 - val;
		codedNum.insert(0, first, '.');
		codedNum.append(last, '-');
	}

	else
	{
		first = val - 5;
		last = 10 - val;
		codedNum.insert(0, first, '-');
		codedNum.append(last, '.');
	}

	return codedNum;
}

string encodeAlpha(char input)
{
	string alphas[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.",				//Morse code representation of alpha characters.
		"....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
		"--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
	char upcase = toupper(input);
	int val = upcase - 65;
	string codedAlpha = alphas[val];

	return codedAlpha;
}

void prntCode(string output[], int size)
{
	for(int i = 0; i < size; i++)
	{
		cout << output[i];
	}
	cout << endl;
}