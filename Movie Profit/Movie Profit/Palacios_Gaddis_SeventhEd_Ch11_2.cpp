//This program displays information stored in Two movie data structs and determines first year proffit or loss.
//File: Palacios_Gaddis_SeventhEd_Ch11_2.cpp
//Author: John Palacios
//Created: 09/28/13 07:40 AM


#include <iostream>
#include <cmath>
#include "Palacios_Gaddis_Seventhed_Ch11_2.h"
using namespace std;

void setDat(MovieDat *);
//Sets data members of MovieDat struct.

void displayDat(MovieDat *);
//Prints the details contained in MovieDat struct and determines loss or profit of film.

int main()
{
	MovieDat *feature1 = new MovieDat;		//First MovieDat struct instance.
	MovieDat *feature2 = new MovieDat;		//Second MovieDat struct instance.
	char answer;							//User's reply to loop request.

	cout << "This program tests two functions who work with a\n"
		<< "MovieDat struct abstract data type. Please follow\n"
		<< "the prompts as they appear, thank you.\n\n";

	do
	{
		setDat(feature1);
		cin.ignore();
		setDat(feature2);
		displayDat(feature1);
		displayDat(feature2);
		cout << "\nWould you like to run the program again?\n"
			<< "Type y to run again.\n";
		cin >> answer;
	}while(answer == 'y' || answer == 'Y');

	delete feature1;
	delete feature2;

	return 0;
}

void setDat(MovieDat *film)
{
	cout << "\nPlease provide the following data:\n"
		<< "Please enter the title of the film.\n";
	getline(cin, film -> title);
	cout << "Please enter the director of the film.\n";
	getline(cin, film -> director);
	cout << "Please enter the year the film was released.\n";
	cin >> film -> YearReleased;
	cout << "Please enter the running time of the film in minutes.\n";
	cin >> film -> RunningTime;
	cout << "Please enter the production cost of the film in whole dollars.\n";
	cin >> film -> ProductionCost;
	cout << "Please enter the first year gross of the film in whole dollars.\n";
	cin >> film -> firstRevenue;
	cout << endl;
}

void displayDat(MovieDat *film)
{
	cout << "\n** Movie information **\n"
		<< "\tThe film "
		<< film -> title
		<< " was directed by "
		<<	film -> director
		<< "\n\tand was released in "
		<<	film -> YearReleased
		<< ", running "
		<< film -> RunningTime << " minutes long.\n";
	if(film -> ProductionCost > film ->firstRevenue)
		cout << "\n\tThis feature lost $"
		<< abs(film ->firstRevenue - film ->ProductionCost)
		<< " it's first year.\n";
	if(film -> ProductionCost < film -> firstRevenue)
		cout << "\n\tThis feature gained $"
		<< (film ->firstRevenue - film ->ProductionCost)
		<< " it's first year.\n";
}