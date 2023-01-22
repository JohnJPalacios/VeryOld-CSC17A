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
	int getItemNumber()
	{ return itemNumber; }
	int getQuantity()
	{ return quantity; }
	float getCost()
	{ return cost; }
	float getTotalCost();
};

#endif /* INVENTORY_H */