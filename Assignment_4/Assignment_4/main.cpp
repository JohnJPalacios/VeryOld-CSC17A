//Assignment 4
//File: Main
//Author: John Palacios

#include <iostream>
#include <iomanip>
#include <string>
#include "Inventory.h"
#include "DynamicNumberArray.h"
#include "NumDays.h"
#include "TimeOff.h"
#include "CruiseShip.h"
#include "CargoShip.h"
#include "Circle.h"
#include "Rectangle.h"
using namespace std;

void Menu();
int getN();
void def(int);
void problem1();
void initInventory(Inventory [], int);
void dispInventory(Inventory [], int);
void dispSubMenu1();
bool validateComm(string);
void problem2();
void dispSubMenu2();
bool validateChoice(string);
void problem3();
void dispSubMenu3a();
void dispSubMenu3b();
void dispHrsWrkd(NumDays [], int);
void dotExecute(string, bool &, NumDays [], int);
void getOpperands(NumDays [], int, int &, int &);
void problem4();
void dispSubMenu4();
char getChoice(TimeOff &);
void getReport(TimeOff &);
void problem5();
void problem6();
BasicShape *instantCircle();
BasicShape *instantRect();

int main(int argv,char *argc[]){
	int inN;
	do{
		Menu();
		inN=getN();
		switch(inN){
		case 1:    problem1();break;
		case 2:    problem2();break;
		case 3:    problem3();break;
		case 4:    problem4();break;
		case 5:    problem5();break;
		case 6:    problem6();break;
		default:   def(inN);}
	}while(inN>=1&&inN<=6);
	return 0;
}

void Menu(){
	cout<<"Menu for Assignment 4"<<endl;
	cout<<"Type 1 for problem 1: chapter 13 #6"<<endl;
	cout<<"Type 2 for problem 2: chapter 13 #11"<<endl;
	cout<<"Type 3 for problem 3: chapter 14 #4"<<endl;
	cout<<"Type 4 for problem 4: chapter 14 #5"<<endl;
	cout<<"Type 5 for problem 5: chapter 15 #12"<<endl;
	cout<<"Type 6 for problem 6: chapter 15 #13"<<endl;
	cout<<"Type anything else to exit \n"<<endl;
}

int getN(){
	int inN;
	cin>>inN;
	return inN;
}

void problem1(){
	cout<<"In problem # 1: chapter 13 #6"<<endl<<endl;
	int num = 0;
	string reply;
	Inventory *stock;

	cout << "This driver program tests a class of object called inventory\n"
		<< "Item. You will be asked to enter the number of objects you wish\n"
		<< "to create, and then you will be prompted to enter data for each\n"
		<< "Item, then offered a menu for viewing items. Please follow the\n"
		<< "prompts as they appear, thank you.\n";

	do{
		//Create an array of Inventory items based on user input.
		do
		{
			cout << "Please enter the number of items you would like to create\n"
				<< "(enter a number greater than zero)\n";
			cin >> num;
		} while (num < 0);
		stock = new Inventory [num];
		initInventory(stock, num);
		//display submenu.
		dispInventory(stock, num);
		delete [] stock;
		//loop request.
		cout << "Would you like to run again?\n";
		cin >> reply;
	} while (tolower(reply[0]) == 'y');

	cout << "Thank you for using my program, good bye.\n";
	stock = 0;
}

void initInventory(Inventory stock[], int size)
{
	int input;
	float price;

	for (int i = 0; i < size; i++){
		cout << "Please enter the item number of item " << i + 1 << endl;
		cin >> input;
		stock[i].setItemNumber(input);
		do{
			cout << "Please enter the quantity on hand of item number " << stock[i].getItemNumber() << endl;
			cin >> input;
		} while (input < 0);
		stock[i].setQuantitiy(input);
		do{
			cout << "Please enter the cost of item number " << stock[i].getItemNumber() << endl;
			cin >> price;
		} while (price < 0.0);
		stock[i].setCost(price);
	}
}

void dispInventory(Inventory stock[], int size)
{
	int pos = 0;
	string command;
	char beep = 7;
	cin.ignore();

	do{
		cout << "item " << pos + 1 << " of " << size << setprecision(2) << fixed << endl
			<< "\tItem number:\t" << stock[pos].getItemNumber() << endl
			<< "\tcost per item:\t$" << stock[pos].getCost() << endl
			<< "\tItems on hand:\t" << stock[pos].getQuantity() << endl
			<< "\tTotal asset:\t$" << stock[pos].getTotalCost() << endl;
		do{
			dispSubMenu1();
			getline(cin, command);
		} while (validateComm(command) == false);

		if(tolower(command[0] == 'n')){
			if(pos == size - 1){
				cout << beep << "There are no more entries this way, please type [back] to see\n"
					<< "next entry or [done] if done.\n";
			}
			else
				pos++;
		}

		if(tolower(command[0] == 'b')){
			if(pos == 0){
				cout << beep << "There are no more entries this way, please type [next] to see\n"
					<< "next entry or [done] if done.\n";
			}
			else
				pos--;
		}

		if(tolower(command[0] == 'd')){
			cout << "You typed [" << command << "] to return to main menue.\n";
		} 
	}while (tolower(command[0] != 'd'));
}

void dispSubMenu1()
{
	cout << "Type [back] to see the previous entry.\n"
		<< "Type [next] to see the next entry.\n"
		<< "Type [done] when you would like to return to the main menue.\n";
}

bool validateComm(string comm)
{
	bool goodComm = false;

	if(tolower(comm[0]) == 'b'){
		goodComm = true;
	}
	if(tolower(comm[0]) == 'n'){
		goodComm = true;
	}
	if(tolower(comm[0]) == 'd'){
		goodComm = true;
	}

	return goodComm;
}

void problem2(){
	cout<<"In problem # 2: chapter 13, #11"<<endl<<endl;
	int size;
	int pos;
	float val;
	char beep = 7;
	string choice;


	cout << "This driver program tests an object who acts like a vector of float values.\n"
		<< "Additionally, the object offers the ability to store numbers in any element,\n"
		<< "to retrieve values from any existant element, the largest value element,\n"
		<< "smallest value element, and the average of all values stored within.\n"
		<< "Please follow the prompts as they appear, thank you.\n";
	do{
		do{
			cout << "Please enter an integral size greater than zero for a new array:\n";
			cin >> size;
		} while (size < 1);
		DynNumArray newArray(size);
		cin.ignore();
		do{
			do{
				dispSubMenu2();
				getline(cin, choice);
				if(validateChoice(choice) == false){
					cout << beep << "Invalid command, please try again\n";
				}
			}while (validateChoice(choice) == false);

			if(tolower(choice[0] == 'e')){
				cout << "Where would you like to store this value? Please enter the index:\n"
					<< "(between 1 and " << size << ")\n";
				pos = -1;
				cin >> pos;
				if(pos > size || pos < 1){
					cout << beep << "That is not a valid index, please try again. Returning to menu.\n";
					cin.ignore();
				}
				else{
					cout << "Please enter the value to be stored\n";
					cin >> val;
					newArray.setVal(pos - 1, val);
					cin.ignore();
				}
			}

			if(tolower(choice[0] == 'h')){
				cout << "Highest value: " << newArray.getHighest() << endl;
			}

			if(tolower(choice[0] == 'l')){
				cout << "Lowest value: " << newArray.getLowest() << endl;
			}

			if(tolower(choice[0] == 'a')){
				cout << "Average value: " << newArray.getAverage() << endl;
			}

			if(tolower(choice[0] == 'p')){
				cout << "All values: \n";
				newArray.prntVals();
			}

			if(tolower(choice[0] == 'd')){
				cout << "You typed [" << choice << "] to return to main menue.\n";
			} 
		} while (tolower(choice[0] != 'd'));

		cout << "Would you like to run again? Type y or yes to run again.\n";
		getline(cin, choice);
	} while (tolower(choice[0] == 'y'));
	cout << "Thank you for using my program.\n";
}

void dispSubMenu2()
{
	cout << endl
		<< "Type [enter] to enter a value into your array.\n"
		<< "Type [highest] to see the highest value in array.\n"
		<< "Type [lowest] to see the lowest value in array.\n"
		<< "Type [average] to see the average of all values in array.\n"
		<< "Type [print] to see all of the values in array.\n"
		<< "Type [done] to return to main menu.\n";
}

bool validateChoice(string comm){
	bool goodComm = false;

	if(tolower(comm[0]) == 'e'){
		goodComm = true;
	}
	if(tolower(comm[0]) == 'h'){
		goodComm = true;
	}
	if(tolower(comm[0]) == 'l'){
		goodComm = true;
	}

	if(tolower(comm[0]) == 'a'){
		goodComm = true;
	}

	if(tolower(comm[0]) == 'p'){
		goodComm = true;
	}

	if(tolower(comm[0]) == 'e'){
		goodComm = true;
	}

	if(tolower(comm[0]) == 'd'){
		goodComm = true;
	}

	return goodComm;
}

void problem3(){
	cout<<"In problem # 3: chapter 14, # 4"<<endl<<endl;
	bool opp = false;
	bool goodComm = false;
	int num;
	int pos = 0;
	int numObjcts;
	string command;
	NumDays *objctArr;

	cout << "This driver program tests the functionality of a class which manages\n"
		<< "work days in partial days assuming an eight hour work day (unless changed).\n"
		<< "Please follow the prompts as they appear, thank you.\n";

	do{
		cout << "How many objects would you like to manipulate?(must be greater than one)\n";
		cin >> num;
	} while (num < 2);
	cin.ignore();
	numObjcts = num;
	objctArr = new NumDays [numObjcts];
	do{
		dispSubMenu3a();
		getline(cin, command);
		dotExecute(command, goodComm, objctArr, numObjcts);
	} while (goodComm == false && tolower(command[0]) != 'e');
	delete [] objctArr;
}

void dispSubMenu3b()
{
	cout << "Type [select] to select this element.\n"
		<< "Type [next] to go to next element.\n"
		<< "Type [back] to go to previous element.\n"
		<< "Type [done] to go to previous menu.\n";

}

void dispSubMenu3a()
{
	cout<< "Type [add] to sum two NumDays objects.\n"
		<< "Type [subtract] for the difference of two objects.\n"
		<< "Type [pre incriment] to increment an object.\n"
		<< "Type [pre decriment] to decriment an object.\n"
		<< "Type [incriment] to incriment an object after operation.\n"
		<< "Type [decriment] to decriment an object after operation.\n"
		<< "Type [work day] to set number of hours in a work day in object.\n"
		<< "Type [hours] to set number of hours in selected object.\n"
		<< "Type [exit] to return to main menu.\n";
}

void dispHrsWrkd(NumDays arr[], int pos)
{
	cout << "Object at " << pos
		<< "\nDays " << arr[pos].getDys()
		<< "\nHours " << arr[pos].getHrs()
		<< "\nWhere each day is " << arr[pos].getHrsPrDay() << " hours per day.\n";
}

void dotExecute(string comm, bool &goodComm, NumDays arr[], int size)
{
	char ch;
	int fst;
	int scd;
	float hrs;

	if(tolower(comm[0]) == 'p' && tolower(comm[4]) == 'i'){
		ch = 'x';
	}
	else if(tolower(comm[0]) == 'p' && tolower(comm[4]) == 'd'){
		ch = 'y';
	}
	else
		ch = comm[0];
	switch(ch){
		case 'a':
			cout << "Please select first operand:\n";
			getOpperands(arr, size, fst, scd);
			cout << arr[fst].getDys() << " days plus " << arr[scd].getDys() << " days = " << arr[fst] + arr[scd] << " hours.\n";
			break;
		case 's':
			cout << "Please select first operand:\n";
			getOpperands(arr, size, fst, scd);
			cout << arr[fst].getDys() << " days minus " << arr[scd].getDys() << " days = " << arr[fst] - arr[scd] << " hours.\n";
			break;
		case 'x':
			cout << "Please select object to increment (only first opperand will be manipulated).\n";
			getOpperands(arr, size, fst, scd);
			cout << "selected object " << arr[fst].getDys() << " before pre increment = " << arr[fst].getHrs() << " hours,";
			++arr[fst];
			cout << " but now = " << arr[fst].getDys() << " days.\n";
			break;
		case 'y':
			cout << "Please select object to decrement (only first opperand will be manipulated).\n";
			getOpperands(arr, size, fst, scd);
			cout << "selected object " << arr[fst].getDys() << " before pre decrement = " << arr[fst].getHrs() << " hours,";
			--arr[fst];
			cout << " but now = " << arr[fst].getDys() << " days.\n";
			break;
		case 'i':
			cout << "Please select object to increment (only first opperand will be manipulated).\n";
			getOpperands(arr, size, fst, scd);
			cout << "selected object " << arr[fst].getDys() << " before post increment = " << arr[fst].getHrs() << " hours,";
			arr[fst]++;
			cout << " but now = " << arr[fst].getDys() << " days.\n";
			break;
		case 'd':
			cout << "Please select object to decrement (only first opperand will be manipulated).\n";
			getOpperands(arr, size, fst, scd);
			cout << "selected object " << arr[fst].getDys() << " before post decrement = " << arr[fst].getHrs() << " hours,";
			arr[fst]--;
			cout << " but now = " << arr[fst].getDys() << " days.\n";
			break;
		case 'w':
			cout << "Please select object to manipulate (only first opperand will be manipulated).\n";
			getOpperands(arr, size, fst, scd);
			do{
				cout << arr[fst].getHrsPrDay() << " hours per day. Please enter new standard work day:\n";
				cin >> hrs;
				if(hrs < 1){
					cout << "Please enter a number of hours greater than zero.";
				}
			} while (hrs < 1);
			arr[fst].setDay(hrs);
			cout << arr[fst].getHrsPrDay() << " hours per day.\n";
			break;
		case 'h':
			cout << "Please select object to manipulate (only first opperand will be manipulated).\n";
			getOpperands(arr, size, fst, scd);
			do{
				cout << arr[fst].getHrs() << " hours worked. Please enter new hours worked:\n";
				cin >> hrs;
				if(hrs < 1){
					cout << "Please enter a number of hours greater than zero.";
				}
			} while (hrs < 1);
			arr[fst].setHrs(hrs);
			cout << arr[fst].getHrs() << " hours worked.\n";
			break;
		case 'e':
			cout << "You typed [" << comm << "] to return to previous menue.\n";
			break;
		default:
			cout <<"[" << comm << "] is not a recognized command.\n";
			goodComm = false;
			break;
	}
}

void getOpperands(NumDays arr[], int size, int &first, int &second)
{
	char beep = 7;
	int pos = 0;
	string sel;
	bool sec = false;
	bool badSel = false;
	do{
		dispHrsWrkd(arr, pos);
		dispSubMenu3b();
		getline(cin, sel);
		switch (sel[0]){
			case 's':
				if(sec == false){
					first = pos;
					sec = true;
					cout << "Please select second operand:\n";
				}
				else
					second = pos;
				break;
			case 'n':
				if(pos == size - 1){
					cout << beep << "There are no more entries this way, please type [back] to see\n"
						<< "previous entry or [done] if done.\n";
				}
				else
					pos++;
				break;
			case 'b':
				if(pos == 0){
					cout << beep << "There are no more entries this way, please type [next] to see\n"
						<< "next entry or [done] if done.\n";
				}
				else
					pos--;
				break;
			case 'd':
				cout << "You typed [" << sel << "] to return to previous menue.\n";
				break;
			default:
				cout << "[" << sel << "] is not a recognized command.\n";
				badSel = true;
				break;
		}
	} while (tolower(sel[0]) != 'd' || badSel == true);
}

void problem4(){
	cout<<"In problem # 4: chapter 14, #5"<<endl<<endl;
	string name[3];
	char ch;
	int synodics;
	cin.ignore();
	cout << "This problem simply test drives an object of the TimeOff\n"
		<< "class, which is an agregate of NumDays objects. Please\n"
		<< "follow the prompts as they appear, thank you.\n\n"
		<< "Please enter the first name of this employee:\n";
	getline(cin, name[0]);
	cout << "Please enter the last name of this employee:\n";
	getline(cin, name[1]);
	cout << "Please enter the employee's identification number:\n";
	getline(cin, name[2]);
	cout << "How many months has this employee held this job?\n";
	cin >> synodics;
	TimeOff newEmp(name[0], name[1], name[2], synodics);
	cin.ignore();
	do{
		dispSubMenu4();
		ch = getChoice(newEmp);
	} while (ch != 'e');
}

void dispSubMenu4()
{
	cout << "Type [sick] to take sick time off.\n"
		<< "Type [unpaid] to take unpaid time off.\n"
		<< "Type [vacation] to take vacation time.\n"
		<< "Type [month] to increase number of months employed.\n"
		<< "Type [report] to see employee's personel file.\n"
		<< "Type [exit] to return to main menu.\n";
}

char getChoice(TimeOff &emp)
{
	string choice;
	int hrs;
	getline(cin, choice);

	switch (tolower(choice[0])){
		case 's':
			cout << "How many hours sick time will " << emp.getName() << " take?\n";
			cin >> hrs;
			emp.takeSick(hrs);
			cin.ignore();
			return 'c';
		case 'u':
			cout << "How many hours unpaid time will " << emp.getName() << " take?\n";
			cin >> hrs;
			emp.takeUnpd(hrs);
			cin.ignore();
			return 'c';
		case 'v':
			cout << "How many hours vacation will " << emp.getName() << " take?\n";
			cin >> hrs;
			emp.takeVaca(hrs);
			cin.ignore();
			return 'c';
		case 'm':
			do{
				cout << "How many months would you like to add to " << emp.getName() << "'s file?\n"
					<< "(Must be greater than zero)\n";
				cin >> hrs;
			} while (hrs < 1);
			for(int i = 0; i < hrs; i++){
				emp++;
			}
			cin.ignore();
			return 'c';
		case 'r':
			getReport(emp);
			return 'c';
		case 'e':
			cout << "You typed [" << choice << "] to return to main menu.\n";
			return 'e';
		default:
			cout << "[" << choice << "] was not an option\n";
			return 'c';
	}
}

void getReport(TimeOff &emp)
{
	cout << "Employee name: " << emp.getName()
		<< "\nEmployee number: " << emp.getNum()
		<< "\nSick leave remaining: " << emp.getSickRemain() << " days.\n"
		<< "Unpaid time remaining: " << emp.getUnpdRemain() << " days.\n"
		<< "Vacation time remaining: " << emp.getVacaRemain() << " days.\n";
}

void problem5(){
	cout<<"In problem # 5: chapter 15 #12"<<endl<<endl;
	Ship *fleet[3] = 
	{	new Ship("SS Minow", "07-05-1960"),
	new CruiseShip("SS Titanic", 500),
	new CargoShip(500, "Exxon Valdese", "05-12-1980")
	};

	cout << "This option tests several clases of objects representing\n"
		<< "several different types of ship. If done properly, each\n"
		<< "object will call it's dynamically bound prntIfo member f(x).\n";
	for(int i = 0; i < 3; i++){
		fleet[i]->prntInfo();
		cout << endl;
		delete fleet[i];
	}
}

void problem6(){
	cout<<"In problem # 6: chapter 15 #13"<<endl<<endl;

	string repeat;
	BasicShape *circle;
	BasicShape *rect;
	cout << "This program demonstrates two objects who are inherited\n"
		<< "from an abstract base class. Please follow the Prompts as\n"
		<< "they appear, thank you.\n";

	do{
		cout << "Creating circle...\n";
		circle = instantCircle();
		cout << "Creating rectangle...\n";
		rect = instantRect();

		cout << "Your circle's area: "
			<< circle->getArea() << endl
			<< "Your rectangle's area: "
			<< rect->getArea() << endl;

		delete [] circle;
		delete [] rect;
		cin.ignore();

		cout << "Would you like to run again? type anything starting with y\n"
			<< "to run again.\n";
		getline(cin, repeat);
	} while (tolower(repeat[0]) == 'y');

	circle = 0;
	rect = 0;
}

BasicShape *instantCircle()
{
	long eX;
	long wY;
	float rad;
	BasicShape *circle;
	cout << "Please enter x coordinate of center\n";
	cin >> eX;
	cout << "Please enter y coordinate of center\n";
	cin >> wY;
	cout << "Please enter the radius of the circle\n";
	cin >> rad;
	circle = new Circle(eX, wY, rad);
	return circle;
}

BasicShape *instantRect()
{
	long eX;
	long wY;
	BasicShape *rect;

	cout << "Please enter the width of rectangle\n";
	cin >> eX;
	cout << "Please enter the length of rectangle\n";
	cin >> wY;
	rect = new Rectangle(eX, wY);

	return rect;
}

void def(int inN){
	cout<<"You typed "<<inN<<" to exit the program"<<endl;
}