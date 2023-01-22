/* 
 * File:   main.cpp
 * Author: John Palacios
 * Created on September 24, 2013, 5:04 PM
 */

#include <cstdlib>
#include <iostream>
#include "Palacios_Gaddis_seventhed_Ch11_4.h"
using namespace std;

void genInput(MonthDat []);
//This function generates dummy values to initialize array of MonthDats with
//for test purpuses; entering 36 values is tiresome.

void getInput(MonthDat []);
//Sets MonthDat data member values to validated user input.

void computeAnnual(MonthDat [], YearDat &);
//Populates YearDat with computed values derived from validated
//user imput values from MonthDat array.

void displayStats(YearDat &);
//Prints computed statistics in YearDat.

int main() 
{
	MonthDat *months = new MonthDat[12];			//array of abstract data type MonthDat.
	YearDat *now = new YearDat;						//pointer to abstract data type YearDat.
	char choice;									//User's decision to enter data again.
	char answer;									//User's decision to run again.

	cout << "Welcome to Annual Weather Calculator! This program will\n"
		<< "Calculate the average monthly rainfall, the total rainfall,\n"
		<< "the highest, the lowest, and average temperatures (and the\n"
		<< "month that they occured in)for for the year. Please follow\n"
		<< "the prompts as they appear, thank you.\n\n";

	cout << "Would you like to enter data for 12 months manually or have\n"
		<< "me generate the data for you? type y to ENTER the data MANUALLY.\n";
	cin >> choice;
	if (choice == 'y' || choice == 'Y')
	{
		//The user wishes to enter the data manually.
		getInput(months);
	}
	else
	{
		//The user wishes for me to generate the data automatically.
		genInput(months);
	}
	computeAnnual(months, *now);
	displayStats(*now);

	//Return memory to free store.
	delete [] months;
	delete now;

	return 0;
}

void genInput(MonthDat synodic[])
{
	for(int i = 0; i < 12; i++)
	{
		cout << "Please enter the total rainfall for\n"
			<< "month number " << i + 1 << " in inches.\n";
		synodic[i].rainfall = i * 1.2f;
		cout << synodic[i].rainfall << endl;

		cout << "Please enter the high temperature\n"
			<< "in degrees Fahrenheit for month " << i + 1 << endl
			<< "(must be between -100 and 140 degrees Fahrenheit)\n";
			synodic[i].highTemp = i * 12;
		cout << synodic[i].highTemp << endl;

		cout << "Please enter the low temperature\n"
			<< "in degrees Fahrenheit for month " << i + 1 << endl
			<< "(must be between -100 and 140 degrees Fahrenheit)\n";
		synodic[i].lowTemp = i * -1;
		cout << synodic[i].lowTemp << endl;

		synodic[i].aveTemp = (synodic[i].highTemp + synodic[0].lowTemp)/2.0f;
	}
}

void getInput(MonthDat synodic[])
{
	float totRainfall;		//User supplied monthly total rainfall.
	int highTemp;			//User supplied monthly high temp.
	int lowTemp;			//User supplied monthly low temp.

	for(int i = 0; i < 12; i++)
	{
		do
		{
			cout << "Please enter the total rainfall for\n"
				<< "month number " << i + 1 << " in inches.\n";
			cin >> totRainfall;
		}while(totRainfall < 0);
		synodic[i].rainfall = totRainfall;

		do
		{
			cout << "Please enter the high temperature\n"
				<< "in degrees Fahrenheit for month " << i + 1 << endl
				<< "(must be between -100 and 140 degrees Fahrenheit)\n";
				cin >> highTemp;
		}while(highTemp < -100 || highTemp > 140);
		synodic[i].highTemp = highTemp;

		do
		{
			cout << "Please enter the low temperature\n"
				<< "in degrees Fahrenheit for month " << i + 1 << endl
				<< "(must be between -100 and 140 degrees Fahrenheit)\n";
				cin >> lowTemp;
		}while(lowTemp < -100 || lowTemp > 140);
		synodic[i].lowTemp = lowTemp;

		synodic[i].aveTemp = (highTemp + lowTemp)/2.0f;
	}
}

void computeAnnual(MonthDat synodic[], YearDat &now)
{
	float totRain = 0;		//Total rainfall for the year.
	int highTemp;			//Highest temp this year.
	int lowTemp;			//Lowest temp this year.
	float avgTemp = 0;		//Average temp this year.

	//Preset high and low temps.
	highTemp = synodic[0].highTemp;
	lowTemp = synodic[0].lowTemp;

	for(int i = 0; i < 12; i++)
	{
		totRain += synodic[i].rainfall;
		avgTemp += synodic[i].aveTemp;

		if(synodic[i].highTemp > highTemp)
		{
			highTemp = synodic[i].highTemp;
			now.monthHigh = i;
		}

		if(synodic[i].lowTemp < lowTemp)
		{
			lowTemp = synodic[i].lowTemp;
			now.monthLow = i;
		}

	}

	//finish computing the average average temperature.
	avgTemp = avgTemp / 12.0f;

	//populate YearDat data members with derived values.
	now.annualHigh = highTemp;
	now.annualLow = lowTemp;
	now.annualRainfall = totRain;
	now.avgRainfall = totRain / 12.0f;
	now.avgTemp = avgTemp;
}

void displayStats(YearDat &now)
{
	cout << endl;
	cout << "The highest temperature for this year was: "
		<< now.annualHigh << " degrees Fahrenheit.\n"
		<< "Which occured in month " << now.monthHigh + 1 << ".\n";
	cout << "The Lowest temperature for this year was: "
		<< now.annualLow << " degrees Fahrenheit.\n"
		<< "Which occured in month " << now.monthLow + 1 << ".\n";
	cout << "The average rainfall for the year was: "
		<< now.avgRainfall << " inches of rainwater.\n";
	cout << "The total rainfall for the year was: "
		<< now.annualRainfall << " inches of rainwater.\n";
	cout << "The average temperature for this year was: "
		<< now.avgTemp << " degrees Fahrenheit.\n";
}