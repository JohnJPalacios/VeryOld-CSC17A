//This simple application tests console buffer manipulation.
//File: main.cpp
//Author: John Palacios

#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
	HANDLE mainConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	cout << "This simple application is an experiment in modifying\n"
		<< "the character color properties in the shell.\n";

	SetConsoleTextAttribute(mainConsole, (FOREGROUND_GREEN | BACKGROUND_BLUE));

	cout << "This text should be green with a blue background.\n";

	return 0;
}