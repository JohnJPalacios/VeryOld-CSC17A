//This file contains the movie data struct used in Palacios_Gaddis_SeventhEd_Ch11_2.cpp
//File: Palacios_Gaddis_SeventhEd_Ch11_2.h
//Author: John Palacios
//Created: 09/28/13 09:30 AM

#ifndef MOVIEDAT_H
#define	MOVIEDAT_H

#include<string>
using namespace std;

struct MovieDat
{
	string title;			//The Title of the motion feature.
	string director;		//The name of the Director.
	int YearReleased;		//The Year the motion feature was released.
	int RunningTime;		//The length in minutes of the motion feature.
	int ProductionCost;		//The cost incurred manufacturing motion feature.
	int firstRevenue;		//The first year revenue of motion feature.
};

#endif /* MOVIEDAT_H */