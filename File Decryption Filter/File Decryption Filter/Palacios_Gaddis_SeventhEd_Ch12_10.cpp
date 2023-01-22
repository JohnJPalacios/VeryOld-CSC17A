//This program performs a simple decryption of a text file.
//File: Palacios_Gaddis_SeventhEd_Ch12_10.cpp
//Author: John Palacios
//Created: 10-14-2013 04:02 PM

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

	cout << "This simple program will \"decrypt\" the contents of a\n"
		<< "text file passed in at the first prompt, and then write\n"
		<< "the encrypted data to a second text file of your choosing.\n"
		<< "Please follow the prompts as they appear, thank you.\n";

	do
	{
		cout << "Please enter the name of the file to decrypt:\n";
		getline(cin, inputFileName);
		cout << "Please enter the name of the file to save decrypted data to:\n";
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
			byte -= 10;
			output.put(byte);

			input.get(byte);
		}
		cout << "secret revealed.\n";

		input.close();
		output.close();
		cout << "Would you like to decrypt another file?\n"
			<< "Enter anything starting with y to run again.\n";
		getline(cin, answer);
	}while (tolower(answer[0]) == 'y');

	return 0;
}