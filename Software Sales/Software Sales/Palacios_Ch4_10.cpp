/*This program calculates the price after discount given some number of units to sell.
 *File: Palacios_ch4_10.cpp
 *Author: John Palacios
 *Created on August 29, 2013, 11:57 AM
 */

#include<iostream>
#include<iomanip>
using namespace std;

//Prompt the user for input, validate input.
void getQuantity(short &);

//Determine the discount factor, calculate total price. 
float computePrice(const short);

//Print total quantity and price to screen.
void displayTotal(const short, const float);


int main(int argc, char** argv)
{
	short quantity;
	float cost;
	char answer;

	cout << "Welcome to bulk sales discount calculator 0.0.9!\n"
		<< "This program will ask you for a number of items purchased\n"
		<< "and then calculate the total cost after applying a discount\n"
		<< "to the price based on the bulk quantity. Please follow the \n"
		<< "promts which follow.\n\n";

	do
	{
		getQuantity(quantity);
		cost = computePrice(quantity);
		displayTotal(quantity, cost);

		//loop request.
		cout << "\n\nWould you like to make another calculation?\n"
			<< "Type y to run again. ";
		cin >> answer;
		cout << endl;
	}while(answer == 'y' || answer == 'Y');

	return 0;
}

void getQuantity (short &qty)
{
	short quantity;

	//Ask for input.
	do
	{
		cout << "Please type the number of items sold to see a total cost. \n"
			<< "Items sold (must be greater than zero): ";
		cin >> quantity;

		//Validate input.
	}while (quantity <= 0);

	qty = quantity;
}

float computePrice(const short qty)
{
	short quantity = qty;
	float cost;
	float discount;

	//determine discount factor.
	if (quantity < 10)
	{
		discount = 1.00f;
	}

	else if (quantity >= 10 && quantity < 20)
	{
		discount = 1.20f;
	}

	else if (quantity >= 20 && quantity < 49)
	{
		discount = 1.30f;
	}

	else if (quantity >= 50 && quantity < 99)
	{
		discount = 1.40f;
	}

	else
	{
		discount = 1.50f;
	}

	//Compute cost.
	cost = (quantity * 99.00f) / discount;

	return cost;
}

void displayTotal(const short qty, const float cst)
{
	short quantity = qty;
	float cost = cst;

	//standard monetery format.
	cout << setprecision(2) << fixed << showpoint;
	cout << "Quantity purchased: " << quantity << " with appllicable discount is: $" << cost << ".\n";
}