//Implementation file for TimeOff class.
//File: TimeOff.cpp
//Author: John Palacios

#include "TimeOff.h"

TimeOff::TimeOff()
{ 
	firstName = "";
	lastName = "";
	empNum = "000000";
	monthsEmployed = 0;
	maxSickDays = new NumDays;
	maxSickDays->setHrs(0);
	sickTaken = new NumDays;
	sickTaken->setHrs(0);
	maxVacation = new NumDays;
	maxVacation->setHrs(0);
	vacTaken = new NumDays;
	vacTaken->setHrs(0);
	maxUnpaid = new NumDays;
	maxUnpaid->setHrs(0);
	unpaidTaken = new NumDays;
	unpaidTaken->setHrs(0);
}

TimeOff::TimeOff(string frst, string scnd, string num, int months)
{ 
	firstName = frst;
	lastName = scnd;
	empNum = num;
	monthsEmployed = months;
	maxSickDays = new NumDays;
	maxSickDays->setHrs(8.0f*monthsEmployed);
	sickTaken = new NumDays;
	sickTaken->setHrs(0);
	maxVacation = new NumDays;
	maxVacation->setHrs(12.0f*monthsEmployed);
	vacTaken = new NumDays;
	vacTaken->setHrs(0);
	maxUnpaid = new NumDays;
	maxUnpaid->setHrs(160.0f*monthsEmployed);
	unpaidTaken = new NumDays;
	unpaidTaken->setHrs(0);
}

int TimeOff::operator++()
{
	return ++monthsEmployed;
}

int TimeOff::operator++(int)
{
	return monthsEmployed++;
}

void TimeOff::takeSick(int hrs)
{
	maxSickDays->setHrs(8.0f*monthsEmployed);
	maxVacation->setHrs(12.0f*monthsEmployed);
	maxUnpaid->setHrs(160.0f*monthsEmployed);
	
	for(int i = 0; i < hrs; i++){
		if(sickTaken->getHrs() <= maxSickDays->getHrs()){
			sickTaken++;
		}
	}
}

void TimeOff::takeUnpd(int hrs)
{
	maxSickDays->setHrs(8.0f*monthsEmployed);
	maxVacation->setHrs(12.0f*monthsEmployed);
	maxUnpaid->setHrs(160.0f*monthsEmployed);

	for(int i = 0; i < hrs; i++){
		if(unpaidTaken->getHrs() <= maxUnpaid->getHrs()){
		unpaidTaken++;
		}
	}
}

void TimeOff::takeVaca(int hrs)
{
	maxSickDays->setHrs(8.0f*monthsEmployed);
	maxVacation->setHrs(12.0f*monthsEmployed);
	maxUnpaid->setHrs(160.0f*monthsEmployed);

	for(int i = 0; i < hrs; i++){
		if(vacTaken->getHrs() <= maxVacation->getHrs()){
		vacTaken++;
		}
	}
}