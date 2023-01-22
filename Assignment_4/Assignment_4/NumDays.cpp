//Implementation file for NumDays class.
//File: NumDays.cpp
//Author: John Palacios

#include "NumDays.h"

float NumDays::operator +(const NumDays &obj)
{
	return hrsWrkd + obj.hrsWrkd;
}

float NumDays::operator -(const NumDays &obj)
{
	return hrsWrkd - obj.hrsWrkd;
}

float NumDays::operator ++()
{
	return ++hrsWrkd;
}

float NumDays::operator ++(int)
{
	return hrsWrkd++;
}

float NumDays::operator --()
{
	return --hrsWrkd;
}

float NumDays::operator --(int)
{
	return hrsWrkd--;
}