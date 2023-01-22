//This file contians the class prototype headers for all Tic-tac-toe classes.
//File: Palacios_Midterm_Project.h/tic_tac_toe header.
//Author: John Palacios
//Created: 10-15-2013 11:33 AM
#include <fstream>
#include <string>
using namespace std;

#ifndef SPACE_H
#define SPACE_H

class Space;
	ostream &operator << (ostream &, const Space &);

class Space
{
private:
	bool owned;				//Spaces state in respect to being owned.
	char owner;				//owner's character if owned, or location if not owned.
	void setSpace(char);
public:
	Space()
	{owned = false; owner = ' ';}
	Space(char);
	~Space();
	void flipSpace(char);
	friend ostream &operator << (ostream & stream, const Space &instanceOf)
	{
		stream << instanceOf.owner; 
		return stream;
	}
	friend class Board;
	friend class Game;
};

#endif /* SPACE_H */

#ifndef BOARD_H
#define BOARD_H

class Board
{
private:
	int root;			//The root of the number of spaces, used for victory determination.
	int numSpaces;		//The total number of spaces.
	int rightPos;		//Keeps track of the element position when printing board.
	int downPos;		//Keeps track of the element position when printing board.
protected:
	Space **spaces;		//pointer to two dimensional dynamic array of space objects.
public:
	Board();
	~Board();
	int getRoot() const
	{ return root;}
	int getNumSpaces() const
	{ return numSpaces;}
	void flipSpace(int, char);
	void showBoard();
	void printSeps(int);
	void printSpaces(int, int);
	friend class Game;
};

#endif /* BOARD_H */

#ifndef PLAYER_H
#define PLAYER_H

struct Player
{
	string playerName;
	char playerToken;
};

#endif /* PLAYER */

#ifndef VICTORY_H
#define VICTORY_H

struct Victory
{
	char player[9];
	char board[9];
};

#endif /* VICTORY_H */

#ifndef GAME_H
#define GAME_H

class Game
{
private:
	Player ex;
	Player oh;
	Player victor;
	Board *field;
	int root;
	int numSpaces;
	int turnNum;
	int numMoves;
	char *availMoves;
	bool fatlady;
	bool victory;
	bool catsGame;
	bool exTurn;
public:
	Game();
	Game(Player, Player);
	~Game();
	void displayField();
	void cap(int, Player);
	void checkStatus(Player);
	void saveGame();
	void setTurnNum()
	{ turnNum = 1;}
	int getTurnNum() const
	{ return turnNum;}
	bool getExTurn() const
	{ return exTurn;}
	void playerXturn();
	void playerOturn();
	//void systemTurn(bool);
	bool validateMove(char);
	char *getAvailableMoves();
	static void displayMenu();
	static Victory *getVictories(int &);
	static void printVictory(Victory [], int);
	static void dispVictories();
	static bool validateComm(char);
	static int getChoice();
	static bool validateName(string);
	static void play();
	
};

#endif /* GAME_H */