/* This program tracks the scores of 12 soccer players.
 * File:   Palacios_Gaddis_SeventhEd_Ch11_6.cpp
 * Author: John Palacios
 * Created on September 30, 2013, 5:51 PM
 */

#include <cstdlib>
#include <iostream>
#include "Palacios_Gaddis_SeventhEd_Ch11_6.h"
using namespace std;

PlayerScore *allocate(int);
//Allocates memory for playerScore array.

void deallocate(PlayerScore *, int);
//Deallocates memory from PlayerScore.

void deallocate(string *, int);
//Deallocates memory from allStars.

void getDat(PlayerScore [], int);
//Allows user to populate data in a player scores array

void genDat(PlayerScore [], int);
//generates some dummy values to test program.

int sumScores(PlayerScore [], int);
//returns the total score of the team.

PlayerScore *highScore(PlayerScore [], int, int &);
//returns the name of the player(s) who scored the most points.

void displayDat(PlayerScore [], int);  
//Displays data contained in PlayerScore array.

void dispTotHigh(PlayerScore *, int, int);
//Displays the total score and the top scoring players.

int main(int argc, char** argv) {
    int size = 12;              //Number of players on the team.
    int total;                  //Total team score.
    int numAllstars;            //length of allstars array.
    PlayerScore *roster;        //Player data for team.
    PlayerScore *allStars;      //highest scoring players.
	char choice;				//User's decision to manually enter data.
	char answer;				//user's reply to loop request.

	cout << "Welcome to Soccer Scores! This program tracks data for twelve soccer players.\n"
		<< "You may ENTER data for all twelve players MANUALLY (" << size * 3 << " pieces of data) or allow\n"
		<< "me to enter it for you. Please follow the prompts as they appear, thank you.\n\n";
	
    do
	{
		cout << "Would you like to enter the all " << size*3 << " items of data MANNUALLY?\n"
			<< "Enter y to enter the data manually, else I will enter it for you.\n";
		cin >> choice;
    roster = allocate(size);
	if (choice == 'y' || choice == 'Y')
	{
		//User has chosen to enter data manually.
    getDat(roster, size);
	}
	else
	{
		//User has not chosen to enter data manually.
	genDat(roster, size);
	}
    total = sumScores(roster, size);
    allStars = highScore(roster, size, numAllstars);  //Last f(x) written.
    displayDat(roster, size);
    cout << endl << endl;
    dispTotHigh(allStars, numAllstars, total);
    deallocate(allStars, numAllstars);
    deallocate(roster, size);

	cout << "Would you like to run the program again?\n"
		<< "enter y to run again.\n";
	cin >> answer;
	}while(answer == 'y' || answer == 'Y');
    return 0;
}

PlayerScore *allocate(int size){
    PlayerScore *ptr = new PlayerScore[size];
    
    return ptr;
}

void deallocate(PlayerScore *roster, int size){
    if (size > 0){ delete []roster;}
}

void deallocate(string *roster, int size){
    if (size > 0){ delete []roster;}
}

void getDat(PlayerScore roster[], int size){
    
    for (int i = 0; i < size; i++){
        cout << "Please enter the name of player.\n";
        getline(cin, roster[i].name);
        cout << "Please enter the players number.\n";
        cin >> roster[i].num;
        cout << "Please enter the players score.\n";
        cin >> roster[i].pointsScored;
		cin.ignore();
    }
}

void genDat(PlayerScore roster[], int size){
    string names[12] = {
        "Angel REYNA", "Oribe PERALTA", "Pablo VELAZQUEZ",
        "Hector MANCILLA", "Carlos OCHOA", "Fidel Martínez",
        "Raul JIMENEZ", "Alan PULIDO", "Esteban PAREDES",
        "Jeff MONTERO", "Matias Alustiza", "Mauro Boselli"
    };
    short nums[12] = {
        10, 13, 15, 18, 21, 23, 22, 03, 05, 07, 06, 11
    };
    int scored[12] = {
        8, 8, 7, 7, 6, 6, 6, 5, 5, 5, 4, 4
    };
    
    for (int i = 0; i < size; i++){
        cout << "Please enter the name of player.\n";
        roster[i].name = names[i];
        cout << roster[i].name << endl;
        cout << "Please enter the players number.\n";
        roster[i].num = nums[i];
        cout << roster[i].num << endl;
        cout << "Please enter the players score.\n";
        roster[i].pointsScored = scored[i];
        cout << roster[i].pointsScored << endl;
    }
}

int sumScores(PlayerScore roster[], int size){
    int sum = 0;
    for (int i = 0; i < size; i++){
        sum += roster[i].pointsScored;
    }
    
    return sum;
}

PlayerScore *highScore(PlayerScore roster[], int size, int &topPlayers){
    int highScore;
    int numAllstars = 0;
    PlayerScore *allStars;
    highScore = roster[0].pointsScored;
    
    //find highest score in the set.
    for (int i = 0; i < size; i++){
        if (roster[i].pointsScored > highScore){
            highScore = roster[i].pointsScored;
        }
    }
    
    //find the number of players who have the highest score.
    for (int i = 0; i < size; i++){
        if (roster[i].pointsScored == highScore){
            numAllstars++;
        }
    }
    
	//Add the names of the highscoring players to the array.
    allStars = new PlayerScore[numAllstars];
	for (int i = 0; i < numAllstars; i++){
		if (roster[i].pointsScored == highScore){
			allStars[i] = roster[i];
		}
	}

    topPlayers = numAllstars;
    return allStars;
}

void displayDat(PlayerScore roster[], int size)
{
   cout << "\nPlayers who scored the highest: \n"
		<< "Player name		Player number	Points scored\n"
		<< "-----------------------------------------------------\n";
    for (int i = 0; i < size; i++){
    cout << roster[i].name << "\t\t" << roster[i].num << "\t\t" << roster[i].pointsScored << endl;
    cout << endl;
    }
}

void dispTotHigh(PlayerScore *players, int size, int total){
    cout << "\nPlayers who scored the highest: \n"
		<< "Player name		Player number\n"
		<< "-------------------------------------\n";
    for (int i = 0; i < size; i++){
		cout << players[i].name << "\t\t"
			<< players[i].num << endl;
    }
    cout << endl
           << "Total score: " << total << endl;
}