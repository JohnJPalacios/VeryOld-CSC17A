//This is the header file for the inventory structure.
//File: Palacios_Gaddis_Ch12_13.h/inventory header.
//Author: John Palacios
//Created: 10-13-2013 10:10 PM

#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H

const int DESC_SIZE = 51;
const int DATE_SIZE = 11;
const float STATE_TAX = 1.08f;

struct InventoryItem
{
	char description[DESC_SIZE];		//A brief description of the item.
	int itmsOnHand;						//Items On Hand.
	float wholeCost;					//pretax cost in $.
	float retCost;						//Posttax cost in $.
	char dateAdd[DATE_SIZE];			//date in mmddyyyy format for RHI.
};
#endif /* INVENTORYITEM_H */