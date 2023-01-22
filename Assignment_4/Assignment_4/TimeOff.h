//Header file for the TimeOff class
//File: TimeOff.h
//Author John Palacios

#include "NumDays.h"
#include <iostream>
#include <string>
using namespace std;

#ifndef TIMEOFF_H
#define TIMEOFF_H

class TimeOff
{
private:
	string firstName;
	string lastName;
	string empNum;
	int monthsEmployed;
	NumDays *maxSickDays;
	NumDays *sickTaken;
	NumDays *maxVacation;
	NumDays *vacTaken;
	NumDays *maxUnpaid;
	NumDays *unpaidTaken;
public:
	TimeOff();
	TimeOff(string, string, string, int);
	void setFstNm(string name)
	{ firstName = name; }
	void setLstNm(string name)
	{ lastName = name; }
	void setEmpNum(string num)
	{ empNum = num; }
	void setMonths(int synodic)
	{ monthsEmployed = synodic; }
	int operator++();
	int operator++(int);
	string getName()
	{ return firstName + " " + lastName; }
	string getNum()
	{ return empNum; }
	void takeSick(int);
	void takeVaca(int);
	void takeUnpd(int);
	float getSickRemain()
	{ return this->maxSickDays->getDys() - this->sickTaken->getDys(); }
	float getVacaRemain()
	{ return this->maxVacation->getDys() - this->vacTaken->getDys(); }
	float getUnpdRemain()
	{ return this->maxUnpaid->getDys() - this->unpaidTaken->getDys(); }
};

#endif /* TIMEOFF_H */