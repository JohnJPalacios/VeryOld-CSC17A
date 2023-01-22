//This program demonstrates the rewritten function "doSomething."
//File: Palacios_ch9_5.cpp
//Author: John Palacios
//Created: 09/18/13 11:26 AM

#include<iostream>
using namespace std;

int doSomething(int *, int *);
//This function multiplies each argument by ten and then adds them together to produce it's output.

int main()
{	
	int first;			//First argument parameter for doSomething.
	int second;			//Second argument parameter for doSomething.
	char answer;		//User reply to loop request.
	int result;			//output of doSomething.

		cout << "This program tests the function doSomething.\n"
		<< "Please follow the prompts as they appear, thank you.\n";
	do
	{
		cout << "Please enter the first value:\n";
		cin >> first;
		cout << "Please enter the second value:\n";
		cin >> second;
		result = doSomething(&first, &second);
		cout << "Your result is:\n";
		cout << result;

		cout << "\n\nWould you like to make another calculation?\n"
			<< "Type y to run again.\n";
		cin >> answer;
		cout << endl;
	}while(answer == 'y' || answer == 'Y');

	return 0;
}

int doSomething(int *x, int *y)
{
	int temp = *x;
	*x = *y * 10;
	*y = temp * 10;
	return *x + *y;
}