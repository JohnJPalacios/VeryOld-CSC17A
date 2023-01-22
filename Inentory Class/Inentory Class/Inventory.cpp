//Implementation file for the Inventory class
//File: Inventory.cpp
//Author: John Palacios

#include "Inventory.h"
using namespace std;

Inventory::Inventory();
{
}

Inventory::Inventory(int squ, float price, int qty)
{
	itemNumber = squ;
	cost = price;
	quantity = qty;
	totalCost = 0;
}

Inventory::setItemNumber(int squ)
{
	itemNumber = squ;
}

Inventory::setCost(float price)
{
	cost = price;
}

Inventory::setQuantitiy(int qty)
{
	quantity = qty;
}

Inventory::setTotalCost()
{
	totalCost = cost * quantity;
}

Inventory::getTotalCost()
{
	setTotalCost();
	
	return totalCost;
}