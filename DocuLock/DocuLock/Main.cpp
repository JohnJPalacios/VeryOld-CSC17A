//This aplication stores short character strings relating to account information in a binary file.
//File: main.cpp
//Author: John Palacios

#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <string>
using namespace std;
//Include block


//Prototype block

int main()
{
	string user;
	string passWord;

	cout << "Doculoc version 0.0.1.\n\n"
		<< "This application allows the user to maintain a number of binary\n"
		<< "encypted files containing personal account information.\n";
	
	//Determine user identity/file.
	cout << "Please enter your user name.\n";
	getline(cin, user);
	cout << "Thank you, please enter your password.\n";
	getline(cin, passWord);

	//test input data.
	cout << "User name: " << user << " , password: ";
	for(int i = 0; i < passWord.length(); i++){ cout << "*"; }
	cout << endl;

	return 0;
}