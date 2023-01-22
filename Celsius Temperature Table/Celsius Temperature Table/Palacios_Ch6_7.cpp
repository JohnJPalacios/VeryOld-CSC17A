/*This program simply creates a table of fahrenheit and celcius temperature equivlents.
 *File: Palacios_ch6_7.cpp
 *Author: John Palacios
 *Created on september 3, 2013, 10:03 AM
 */

#include<iostream>
#include<iomanip>
using namespace std;

//converts Fahrenheit temperature to celsius temperature.
float celsius(short);

int main(int argc, char** argv)
{
	cout << "This program demonstrates the celsius function.\n";
	
	for(int i = 0; i < 21; i++)
	{
		cout << setprecision(5) << showpoint << fixed
			<< setw(2) << i << " degrees fahrenheit is equivlent to "<< setw(9) << celsius(i) << " degrees celsius\n" ;
	}
}

float celsius(short fahrenheit)
{
	float c;
	
	c = (5/9.0f)*(fahrenheit - 32);

	return c;
}