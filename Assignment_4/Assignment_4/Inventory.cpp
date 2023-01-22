//Implementation file for the Inventory class
//File: Inventory.cpp
//Author: John Palacios

#include "Inventory.h"
Inventory::Inventory()
{
	itemNumber = 0;
	cost = 0.0f;
	quantity = 0;
	totalCost = 0;
}

Inventory::Inventory(int squ, float price, int qty)
{
	itemNumber = squ;
	cost = price;
	quantity = qty;
	totalCost = 0;
}

void Inventory::setItemNumber(int squ)
{
	itemNumber = squ;
}

void Inventory::setCost(float price)
{
	cost = price;
}

void Inventory::setQuantitiy(int qty)
{
	quantity = qty;
}

void Inventory::setTotalCost()
{
	totalCost = cost * quantity;
}

float Inventory::getTotalCost()
{
	setTotalCost();
	
	return totalCost;
}