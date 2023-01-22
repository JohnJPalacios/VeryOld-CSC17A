//This simple program accepts a dollar value for land, then displays the assessment value and the property tax.
//file: Palacios_ch3_13.cpp
//Author: John Palacios
//Started: 08-27-2013

#include<iostream>
#include<iomanip>
using namespace std;

const float PROPERTY_TAX = 0.00640f;	//This is the current property tax used to determin property tax on land.
const float ASSESSMENT_VAL = 0.60f;		//This is the rate at which value of land is assesed based off of actual value.

//Retireves input from user.
void getValue(float &);

//computes the assessment value and property tax value.
void computeVals(const float, float &, float &);

//displays user supplied value, assessment value, and property tax values to screen.
void displayResults(const float, const float, const float);

int main()
{
	float actValue;			//User supplied dollar value of land.
	float assessValue;		//computed value; actual value of land times global constant ASSESSMENT_VAL.
	float propTax;			//computed value; assessValue times global constant PROPERTY_TAX.
	char answer;			//User's reply to loop prompt.

	cout << "Welcome to Property tax calculator 0.1.0!\n\n"
		<< "Use this calculator to determine property tax and assessment value\n"
		<< "based on actual value of land.\n\n";

	do
	{
		getValue(actValue);
		computeVals(actValue, assessValue, propTax);
		displayResults(actValue, assessValue, propTax);
		
		//Prompt user to loop.
		cout << "\n\nWould you like to make another calculation?\n"
			<< "Type y to run again.";
		cin >> answer;
		cout << endl;
	}while(answer == 'y' || answer == 'Y');

	return 0;
}

void getValue(float &userVal)
{
	float value;	//User supplied value.
	
	do
	{
	cout << "Please enter the actual dollar value of land.\n";
	cin >> value;
	}while(value < 1);
	
	userVal = value;
}

void computeVals(const float userVal, float &assessVal, float &pTax)
{
	float aVal;		//local variable for assessment Value in main.
	float pVal;		//local Variable for property tax in main.

	//calculate assessment value and property tax from user data
	//and global rate constants.
	aVal = userVal * ASSESSMENT_VAL;
	pVal = aVal * PROPERTY_TAX;

	assessVal = aVal;
	pTax = pVal;
}

void displayResults(const float userVal, const float assessVal, const float pTax)
{
	//display information to user.
	cout << setprecision(2) << fixed << showpoint << endl;
	cout << "Actual value of land: $" << userVal << endl
		<< "Assessment value of land: $" << assessVal << endl
		<< "Property tax: $" << pTax << endl;
}