//This program uses a pair of pointers to reverse a c string input, and prints the reversed
//c string to the screen.
//File: Palacios_SavitchBook_ch9_4.cpp
//Author: John Palacios
//Created: 09-14-2013 08:10 AM

#include<iostream>
#include<cstring>
using namespace std;

void backtalk(char []);
//Reverses the order of char array's values.

int main()
{
	char *input;
	int size;
	char answer;

	do
	{
		cout << "How many characters will be in the string to be reversed?\n";
		cin >> size;
		input = new char[size + 1];
		cout << "Please type " << size << " characters or less to be reversed.\n";
		cin.ignore(1, '\n');
		cin.getline(input, size + 1);
		backtalk(input);
		cout << input << endl;
		cout << "\n\nWould you like to reverse another string?\n"
			<< "Type y to run again.";
		cin >> answer;
		cout << endl;
	}while(answer == 'y' || answer == 'Y');

	//return allocated memory to free store.
	delete [] input;
	return 0;
}

void backtalk(char input[])
{
	int size = strlen(input);			//number of used spaces in cstring input.
	char *front = input;				//pointer pointing at the first of the two index addresses.
	char *rear = &input[size - 1];		//pointer pointing at the last of the two index addresses.
	char temp;							//temporary memory location for first, while juggling values.

	//Swaps values in c string using pointers.
	for(int i = 0; i < size/2; i++)
	{
		temp = *front;
		*front = *rear;
		*rear = temp;
		front++;
		rear--;
	}
}