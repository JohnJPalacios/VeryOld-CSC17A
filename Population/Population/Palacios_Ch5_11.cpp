/*This program determines the number of individuals in a population given user input.
 *File: Palacios_ch5_11.cpp
 *Author: John Palacios
 *created on september 2, 2013, 09:28 PM
 */

#include<iostream>
using namespace std;

//Prompts the user for data, validates input.
void getStats(float &, short &, short &);

//Calculates population growth each day.
void growthRate(float &, const short);

//Displays the daily population totals.
void dispPop(const float, const short);

int main(int argc, char** argv)
{
	float pop;		//The number of individuals in a given population.
	short days;		//The number of days to simulate population growth.
	short rate;		//The rate at which populations increase stored as a whole number.
	char answer;	//User reply to loop request.

	do
	{
		getStats(pop, days, rate);

		for(int i = 0; i < days; i++)
		{
			short day = i;
			growthRate(pop, rate);
			dispPop(pop, day);
		}
		
		//loop request.
		cout << "\n\nWould you like to run simulation again?\n"
			<< "Type y to run again. ";
		cin >> answer;
		cout << endl;
	}while(answer == 'y' || answer == 'Y');

	return 0;
}

void getStats(float &population, short &time, short &factor)
{
	float pop;		//The number of individuals in a given population.
	short days;		//The number of days to simulate population growth.
	short rate;		//The rate at which populations increase stored as a whole number.

	do
	{
		cout << "Please enter the starting population:\n";
		cin >> pop;
	}while(pop < 2);

	do
	{
		cout << "Please enter the number of days to run simulation:\n";
		cin >> days;
	}while(days < 1);

	do
	{
		cout << "Please enter the rate per one hundered of daily \n"
			<< "population increase:\n";
		cin >> rate;
	}while(rate < 0);

	population = pop;
	time = days;
	factor = rate;
}

void growthRate(float &population, const short factor)
{
	float pop = population;		//The number of individuals in a given population.

	pop += pop * (factor/100.00f);

	population = pop;
}

void dispPop(const float population, const short day)
{
	int pop = population;		//The truncated integer number of individuals in a given population.

	cout << "End of day number: " << day + 1  << endl
		<< "the population is: " << pop << endl << endl;
}