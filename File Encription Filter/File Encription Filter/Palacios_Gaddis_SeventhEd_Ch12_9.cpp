//This program performs a simple encription of a text file.
//File: Palacios_Gaddis_SeventhEd_Ch12_9.cpp
//Author: John Palacios
//Created: 10-14-2013 03:32 PM

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	ifstream input;
	ofstream output;
	string inputFileName;
	string outputFileName;
	string answer;
	char byte;

	cout << "This simple program will \"encrypt\" the contents of a\n"
		<< "text file passed in at the first prompt, and then write\n"
		<< "the altered data to a second text file of your choosing.\n"
		<< "Please follow the prompts as they appear, thank you.\n";

	do
	{
		cout << "Please enter the name of the file to encrypt:\n";
		getline(cin, inputFileName);
		cout << "Please enter the name fo the file to save encrypted data to:\n";
		getline(cin, outputFileName);
		
		input.open(inputFileName.c_str());
		if(input.fail())
		{
			cout << "Error opening file.\n";
			exit (0);
		}
		output.open(outputFileName.c_str());

		input.get(byte);
		while(input)
		{
			byte += 10;
			output.put(byte);

			input.get(byte);
		}
		cout << "secret safe (sort of).\n";

		input.close();
		output.close();
		cout << "Would you like to encrypt another file?\n"
			<< "Enter anything starting with y to run again.\n";
		getline(cin, answer);
	}while (tolower(answer[0]) == 'y');

	return 0;
}