//Structure containing a speakers' details.
//File: Palacios_Gaddis_SeventhEd_Ch11_10.h
//Author: John Palacios
//Created: 09/29/2013 10:31 PM

#ifndef SPKRDAT_H
#define	SPKRDAT_H

#include<string>
using namespace std;

struct SpkrDat
{
	string name;			//The speakers name.
	string speakTopic;		//The Year the motion fearure was released.
	string telephoneNum;	//The speakers contact phone number.
	int requiredFee;		//The Fee that the speaker charges.
};

#endif /* SPKRDAT_H */