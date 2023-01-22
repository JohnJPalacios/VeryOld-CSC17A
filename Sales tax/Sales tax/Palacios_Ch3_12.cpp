//This console app accepts a month, the year, and total collected collected at the cash register,
//Then calculates the collected of sales tax in that total, and presents a report of these figures.
//File: Palacios_ch3_12.cpp
//Author: John Palacios
//Started: 08-28-2013

#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

const float STATE_TAX = 0.040f;		//The state sales tax rate.
const float COUNTY_TAX = 0.020f;	//The county sales tax rate.

//prompts the user for data, populating month, year, and collected in main.
void promptUser(char [], short &, float &);

//calculates dollar values of sales and taxes from register sales.
void computeTaxes(const float, float &, float &, float &, float &);

//Prints a formated report to screen; detailing: year, month, collected, sales, county, state and total taxes.
void displayReport(char [], short, float, float, float, float, float);

int main()
{
	char month[10];				//A char array accepted from user to distinguish the report from others.
	short year;					//A four digit year used to distinguish the report from others.
	float collected;			//The total money collected at the cash register.
	float sales;				//The amount of money left over after State and county sales tax.
	float countyTax;			//The amount of money the county gets from sales.
	float stateTax;				//the amount of money the state gets from sales.
	float totalTax;				//The total amount of money to pay in taxes.
	char answer;				//user reply to test loop prompt.
	
	cout << "welcome to tax calculator 0.9.0! \nThis program will generate a taxes incured report.\n\n";
	do
	{
		promptUser(month, year, collected);
		computeTaxes(collected, sales, countyTax, stateTax, totalTax);
		displayReport(month, year, collected, sales, countyTax, stateTax, totalTax);
		cout << "\n\nWould you like to make another report?\n"
			<< "Type y to run again.";
		cin >> answer;
		cout << endl;
	}while(answer == 'y' || answer == 'Y');

	return 0;
}

void promptUser(char month [10], short &year, float &collected)
{

	char siderealPeriod[10];	//user supplied data for month.
	short eclipticPeriod;		//user supplied data for year.
	float value;				//user supplied data for collected.

	//prompt the user for input with light validation.
	do
	{
	cout << "Pleas enter the month that this report will detail:\n";
	cin >> siderealPeriod;
	}while (!isalpha(siderealPeriod[0]));
	strncpy(month, siderealPeriod, 10);

	do
	{
	cout << "Please enter the year that this report will detail:\n";
	cin >> eclipticPeriod;
	}while (eclipticPeriod > 9999 || eclipticPeriod < 1900);
	year = eclipticPeriod;

	do
	{
	cout << "Pleae enter the total collected at register:\n";
	cin >> value;
	}while (value < 0);
	collected = value;

}

void computeTaxes(const float collected, float &sales, float &countyTax, float &stateTax, float &totalTax)
{
	float totalSales = collected;		//User supplied total sales at register, including tax collected.
	float salesProfit;					//total sales without tax dollars - computed value.
	float cTax;							//dollar value of county sales tax - computed value.
	float sTax;							//dollar value of state sales tax - computed value.
	float tTax;							//dollar value of combined county and state sales tax - computed value.

	//The following statements derive vlaues using simple arithmatic.
	salesProfit = totalSales / (1 + STATE_TAX + COUNTY_TAX);
	tTax = salesProfit * (STATE_TAX + COUNTY_TAX);
	cTax = salesProfit * COUNTY_TAX;
	sTax = salesProfit * STATE_TAX;
	
	sales = salesProfit;
	countyTax = cTax;
	stateTax = sTax;
	totalTax = tTax;
	
}

void displayReport(char month [10], short year, float collected, float sales, float countyTax, float stateTax, float totalTax)
{
	char siderealPeriod [10];				//local variable for user supplied month in main.
	strncpy(siderealPeriod, month, 10);		
	short eclipticPeriod = year;			//local variable for user supplied year in main.
	float total = collected;				//local variable for  collected in main; represents money collected through register.
	float income = sales;					//local variable for sales in main; represents pretax sales.
	float cTax = countyTax;					//local variable for countyTax in main, in dollars.
	float sTax = stateTax;					//local variable for stateTax in main, in dollars.
	float tTax = totalTax;					//local variable for totalTax in main, in dollars.

	//identify and print report to screen with formating and seperation bar for clairity.
	cout << "Year: " << eclipticPeriod << " Month: " << siderealPeriod << endl;
	cout << setfill('-') << setw(29) << '-' << endl;
	cout << setprecision(2) << fixed << setfill(' ') << showpoint;
	cout << setw(20) << left << "Total Collected: " << "$" << setw(10) << right << total << endl
		<< setw(20) << left << "Sales: " << "$" << setw(10) << right << income << endl
		<< setw(20) << left << "County Sales Tax: " << "$" << setw(10) << right << cTax << endl
		<< setw(20) << left << "State sales Tax: " << "$" << setw(10) << right << sTax << endl
		<< setw(20) << left << "Total sales Tax: " << "$" << setw(10) << right << tTax << endl;

}