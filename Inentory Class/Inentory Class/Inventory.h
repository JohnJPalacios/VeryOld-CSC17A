//Header file for inventry class
//File: Inventory.h
//Author: John Palacios

#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory
{
private:
	int itemNumber;
	int quantity;
	float cost;
	float totalCost;
public:
	Inventory();
	//default constructor.
	Inventory(int, float, int);
	void setItemNumber(int);
	void setQuantitiy(int);
	void setCost(float);
	void setTotalCost();
	void getItemNumber()
	{ return itemNumber; }
	void getQuantity()
	{ return quantity; }
	void getCost()
	{ return cost; }
	void getTotalCost();
};

#endif /* INVENTORY_H */