//NumDays offers a simpler way of managing work days.
//File: NumDays.h
//Author: John Palacios

#ifndef NUMDAYS_H
#define NUMDAYS_H

#include <iostream>
using namespace std;

class NumDays
{
private:
	float hrsPrDay;
	float hrsWrkd;
public:
	NumDays()
	{ hrsWrkd = 25, hrsPrDay = 8; }
	NumDays(float hrs)
	{ hrsWrkd = hrs, hrsPrDay = 8; }
	void setDay(float hrs)
	{ hrsPrDay = hrs; }
	void setHrs(float hrs)
	{ hrsWrkd = hrs; }
	float getHrs()
	{ return hrsWrkd; }
	float getDys()
	{ return hrsWrkd / hrsPrDay; }
	float getHrsPrDay()
	{ return hrsPrDay; }
	float operator+(const NumDays &);
	float operator-(const NumDays &);
	float operator++();
	float operator++(int);
	float operator--();
	float operator--(int);
};

#endif /* NUMDAYS_H */