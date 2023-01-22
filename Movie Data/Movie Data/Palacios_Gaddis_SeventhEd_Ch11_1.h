//This file contains the movie data struct used in Palacios_Gaddis_SeventhEd_Ch11_1.cpp
//File: Palacios_Gaddis_SeventhEd_Ch11_1.h
//Author: John Palacios
//Created: 09/28/13 07:40 AM

#ifndef MOVIEDAT_H
#define	MOVIEDAT_H

#include<string>
using namespace std;

struct MovieDat
{
	string title;		//The Title of the motion feature.
	string director;	//The name of the Director.
	int YearReleased;	//The Year the motion fearure was released.
	int RunningTime;	//The length in minutes of the motion fearure.
};

#endif /* MOVIEDAT_H */