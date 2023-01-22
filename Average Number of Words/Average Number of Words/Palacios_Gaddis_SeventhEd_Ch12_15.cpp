//This program parses a text file to determine the average number of words used in the sentences there.
//File: Palacios_Gaddis_SeventhEd_Ch12_15.cpp
//Author: John Palacios
//Created: 10-13-2013 07:04 PM

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

//itterates through char array, looking for spaces and sentence termination.
float avgWords(const char *);

int main()
{
	ifstream file;
	string fileName;
	string input;
	string data;
	string choice;
	float avgWpSent;

	cout << "This program determines the number of words per sentance in a\n"
		<< "given text file. Please choose text.txt or Sagan Quote.txt, or\n"
		<< "add a text file of your choosing encoded in ASCII characters\n"
		<< "to the current directory. Please follow the prompts as they appear,\n"
		<< "Thank you.\n";

	do
	{
		cout << "Please enter a file name to read data from.\n";
		getline(cin, fileName);

		file.open(fileName.c_str());

		if(file)
		{
			getline(file, input);

			while (file)
			{
				data.append(input);
				data.append(1, ' ');

				getline(file, input);
			}

			file.close();
			file.clear();
			input.clear();

			data.append(1, '\0');

			avgWpSent = avgWords(data.c_str());
			data.clear();

			cout << "There are " << avgWpSent << " words per sentence in " << fileName << endl; 
		}

		else
		{
			cout << "Failure to open " << fileName << endl;
			file.clear();
			fileName.clear();
		}

		cout << "Would you like to run again? Type y to run again.\n";
		getline(cin, choice);
	}while (tolower(choice[0]) == 'y');
	return 0;
}

float avgWords(const char *cstr)
{
	int i = 0;							//This is the primary itteration counter.
	int spaces = 0;						//The number of spaces encountered in char array.
	int sentences = 0;					//Total number of sentences in array.
	float avgWords;

	while(cstr[i] != NULL)
	{
		if(isspace(cstr[i]))
		{
			spaces++;
		}

		if(cstr[i] == '.' || cstr[i] == '!' || cstr[i] == '?')
		{
			sentences++;
		}
		i++;
	}

	avgWords = static_cast<float>(spaces) / sentences;
	return avgWords;
}