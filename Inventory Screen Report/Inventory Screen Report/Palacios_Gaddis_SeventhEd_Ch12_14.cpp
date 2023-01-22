//This program creates an iventory report from a binary dataFile.
//File: Palacios_Gaddis_SeventhEd_Ch12_14.cpp
//Author: John Palacios
//Created: 10-14-2013 01:42 PM

#include "Palacios_Gaddis_SeventhEd_Ch12_14.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
	InventoryItem item;
	long pos;
	int numItems;
	int inventory = 0;
	long float wValue = 0;
	long float rValue = 0;
	fstream dataFile("database.dat", ios::in | ios::binary);

	cout << "This program will create a report detailing the total:\n"
		<< "wholesale value, retail value, and number of items in\n"
		<< "The given dat file.\n";

	dataFile.seekg(0L, ios::end);
	numItems = dataFile.tellg() / sizeof(item);
	for (int i = 0; i < numItems; i++)
	{
		pos = i;
		dataFile.seekg(pos * sizeof(item), ios::beg);
		dataFile.read(reinterpret_cast<char *>(&item), sizeof(item));

		wValue += item.wholeCost;
		rValue += item.retCost;
		inventory += item.itmsOnHand;
	}

	cout << "-----------------------Report----------------------\n" 
		<< setprecision(2) << fixed
		<< "Total number of items in inventory: " << inventory << endl
		<< "Total wholesale value of items: " << wValue << endl
		<< "Total retail value of items: " << rValue << endl;

	dataFile.close();
	return 0;
}