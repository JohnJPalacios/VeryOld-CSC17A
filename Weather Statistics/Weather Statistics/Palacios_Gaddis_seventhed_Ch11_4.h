/* 
 * File:   Palacios_Gaddis_seventhed_11_4.h
 * Author: John Palacios
 * Created on September 24, 2013, 5:06 PM
 */

#ifndef MONTHDAT_H
#define	MONTHDAT_H

struct MonthDat
{
    //Data members
    float rainfall;     //inches of rainfall
    int highTemp;       //The highest temperature of that month.
    int lowTemp;        //The lowest temperature of that month.
    float aveTemp;      //The mean temperature of that month.
    
};

#endif	/* MONTHDAT_H */

#ifndef YEARDAT_H
#define YEARDAT_H

struct YearDat
{
	//Data members
	float avgRainfall;			//Average rainfall for the year, computed from months.rainfall.
	float annualRainfall;		//total rainfall for the year, computed from months.rainfall.
	int annualHigh;				//Highest temp for year, computed from months.highTemp.
	int monthHigh;				//This is the month in which the high temperature occured.
	int annualLow;				//Lowest temp for year, computed from months.lowTemp.
	int monthLow;				//This is the month in which the low temperature occured.
	float avgTemp;				//Average monthly average temperature computed from months.aveTemp.
};

#endif	/* YEARDAT_H */