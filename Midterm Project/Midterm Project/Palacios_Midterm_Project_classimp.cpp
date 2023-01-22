//This is the implementation file for my classes.
//File: Class implementation: Palacios_Midterm_Imp.cpp
//Author: John Palacios
//Created: 10-15-2013 02:10 PM

#include <iostream>
#include "Palacios_Midterm_Project.h"
using namespace std;

Space::Space(char pos)
{
	owned = false;
	owner = pos;
}

Space::~Space()
{
}

void Space::setSpace(char num)
{
	owner = num;
}

void Space::flipSpace(char token)
{
	if(owned == false && (!isdigit(token))){
		owner = token;
		owned = true;
	}
	if(owned == false && isdigit(token)){
		setSpace(token);
	}
}

//Board implementation.

Board::Board()
{
	root = 3;
	numSpaces = root * root;
	spaces = new Space* [root];		//creat rows.
	int ch = 55;					//Interger base to assigned count character.

	for(int i = 0; i < root; i++)
	{
		spaces[i] = new Space[root];	//creat collumns.
	}

	for(int i = 0; i < root; i++)
	{
		for(int j = 0; j < root; j++)
		{
			ch -= i * root;
			ch += j;
			spaces[i][j].flipSpace(ch);
			ch = 55;						//Reset char base.
		}
	}
}

Board::~Board()
{
	/*for(int i = 0; i < root; i++)
	{
	delete [] spaces[i];
	}

	delete [] spaces;*/
}

void Board::flipSpace(int pos, char token)
{
	int i;
	int j;
	if(pos >= numSpaces - 2 && pos <= numSpaces)
	{
		i = 0;
		j = pos - 7;
	}
	if(pos >= numSpaces - 5 && pos <= numSpaces - root)
	{
		i = 1;
		j = pos - 4;
	}
	if(pos >= numSpaces - 8 && pos <= numSpaces - (root*2))
	{
		i = 2;
		j = pos - 1;
	}
	spaces[i][j].flipSpace(token);
}

void Board::showBoard()
{	
	rightPos = 0;
	downPos = 0;

	for(int row = 0; row < root + 2; row++){
		for(int col = 0; col < root + 2; col++){
			if(row % 2 == 0)
				printSpaces(col, row);
			else{
				printSeps(col);
			}
		}
		if(row % 2 == 1){
			downPos++;
		}
		rightPos = 0;
		cout << endl;
	}
	cout << endl;

}

void Board::printSeps(int col)
{
	if(col % 2 == 0)
		cout << "- ";
	else
		cout << "+ ";
}

void Board::printSpaces(int col, int row)
{
	if(col % 2 == 0){
		cout << spaces[downPos][rightPos];
		rightPos++;
	}
	else
		cout << " | ";
}

//Game implementation.

Game::Game()
{
	ex.playerName = "Player X";
	ex.playerToken = 'X';
	oh.playerName = "Player O";
	oh.playerToken = 'O';
	field = new Board;
	root = field->getRoot();
	numSpaces = field->getNumSpaces();
	turnNum = 1;
	numMoves = numSpaces;
	fatlady = false;
	victory = false;
	catsGame = false;
}

Game::Game(Player eX, Player oH)
{
	ex.playerName = eX.playerName;
	ex.playerToken = eX.playerToken;
	oh.playerName = oH.playerName;
	oh.playerToken = oH.playerToken;
	field = new Board;
	root = field->getRoot();
	numSpaces = field->getNumSpaces();
	turnNum = 1;
	numMoves = numSpaces;
	fatlady = false;
	victory = false;
	catsGame = false;
}

Game::~Game()
{
}
void Game::displayField()
{
	field->showBoard();
}

void Game::cap(int pos, Player act)
{
	field->flipSpace(pos, act.playerToken);

	if(turnNum > 2 * root + 1 && victory == false)
	{
		cout << "Looks like no one wins this game.\n";
		fatlady = true;
		catsGame = true;
	}

	else if(turnNum >= root)
	{
		checkStatus(act);
	}
}

void Game::checkStatus(Player act)
{
	int numOpXeY = 0;
	int numExEqY = 0;
	int numConst = 0;
	int numUndef = 0;

	//Show me what victory looks like!
	//diagonal left to right
	for(int pos = 0; pos < root; pos++){
		if(field->spaces[pos][pos].owner == act.playerToken){
			numOpXeY++;
			if(numOpXeY == root){
				cout << act.playerName << " wins!\n";
				victor = act;
				victory = true;
				fatlady = true;
			}
		}
	}

	//diagonal right to left
	for(int row = 0, col = root - 1; row < root; row++, col--){
		if(field->spaces[row][col].owner == act.playerToken){
			numExEqY++;
			if(numExEqY == root){
				cout << act.playerName << " wins!\n";
				victor = act;
				victory = true;
				fatlady = true;
			}
		}
	}

	//accross.
	for(int i = 0; i < root; i++){
		numConst = 0;
		for(int j = 0; j < root; j++){
			if(field->spaces[i][j].owner == act.playerToken){
				numConst++;
				if(numConst == root){
					cout << act.playerName << " wins!\n";
					victor = act;
					victory = true;
					fatlady = true;
				}
			}
		}
	}

	//down.
	for(int i = 0; i < root; i++){
		numUndef = 0;
		for(int j = 0; j < root; j++){
			if(field->spaces[j][i].owner == act.playerToken){
				numUndef++;
				if(numUndef == root){
					cout << act.playerName << " wins!\n";
					victor = act;
					victory = true;
					fatlady = true;
				}
			}
		}
	}
}

void Game::saveGame()
{
	Victory winner;
	fstream dataFile;
	int count = 0;
	int i = 0;

	do
	{
		winner.player[count] = victor.playerName[count];
		count++;
	}while (victor.playerName[count] != '\0');
	winner.player[8] = '\0';
	for(int row = 0; row < root; row++){
		for(int col = 0; col < root; col++){
			winner.board[i] = field->spaces[row][col].owner;
			i++;
		}
	}

	dataFile.open("victories.dat", ios::app | ios::binary);
	dataFile.write(reinterpret_cast<char *>(&winner), sizeof(winner));
	dataFile.close();
}

void Game::displayMenu()
{
	cout << "type [rules] to learn how you play this game.\n"
		<< "type [play] to play a game of Tic-Tac-Toe!\n"
		<< "type [fast play] to play a fast game of Tic-Tac-Toe.\n"
		<< "Type [victories] to see past victories.\n"
		<< "type [exit] to exit game.\n";
}

Victory *Game::getVictories(int &numEntries)
{
	fstream dataFile;
	Victory *entries;

	dataFile.open("victories.dat", ios::in | ios::binary);

	if(dataFile.fail()){
		cout << "Error oppening victories.dat.";
		exit(1);
	}

	dataFile.seekg(0L, ios::end);
	numEntries = dataFile.tellg() / sizeof(Victory);
	dataFile.seekg(0L, ios::beg);

	entries = new Victory [numEntries];

	for(int i = 0; i < numEntries; i++){
		dataFile.seekg(i * sizeof(Victory), ios::beg);
		dataFile.read(reinterpret_cast<char *>(&entries[i]), sizeof(Victory));
	}
	dataFile.close();
	return entries;
}

void Game::printVictory(Victory entries[], int pos)
{
	int count = 0;

	cout << entries[pos].player << endl;
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			if(i % 2 == 0){
				if(j % 2 == 0){
					cout << entries[pos].board[count];
					count++;
				}
				if(j % 2 == 1){
					cout << " | ";
				}
			}
			if(i % 2 == 1){
				if(j % 2 == 0){
					cout << "- ";
				}
				if(j % 2 == 1){
					cout << "+ ";
				}
			}

		}
		cout << endl;
	}
}

void Game::dispVictories()
{
	int pos = 0;
	int numEntries;
	string command;
	Victory *victories;
	victories = getVictories(numEntries);
	cout << "~Hall of fame~\n"
		<< "Here you will find the Tic-tac-toe champions of days gone bye;\n"
		<< "you may browse this list of victories at your leasure.\n";
	do
	{
		do
		{
			printVictory(victories, pos);
			cout << endl;
			cout << "This is entry " << pos + 1 << " of " << numEntries << endl;
			cout << "Type [back] to see the previous entry.\n"
				<< "Type [next] to see the next entry.\n"
				<< "Type [done] when you would like to return to the main menue.\n";
			
			getline(cin, command);
		} while(validateComm(tolower(command[0])) == false);
		if(tolower(command[0]) == 'b' && pos == 0){
			cout << "No more entries this way; type [next] to see next entry.\n";
		}
		if(tolower(command[0]) == 'b' && pos > 0){
			pos--;
		}
		if(tolower(command[0]) == 'n' && pos == numEntries - 1){
			cout << "No more entries this way; type [back] to see next entry.\n";
		}
		if(tolower(command[0]) == 'n' && pos < numEntries - 1){
			pos++;
		}
		if(tolower(command[0]) == 'd'){
			cout << "You typed [" << command << "]. Exiting hall of fame...\n";
		}
	}while(tolower(command[0]) != 'd');
	delete [] victories;
}

bool Game::validateComm(char comm)
{
	bool goodComm = false;

	if(tolower(comm) == 'b'){
		goodComm = true;
	}
	if(tolower(comm) == 'n'){
		goodComm = true;
	}
	if(tolower(comm) == 'd'){
		goodComm = true;
	}

	return goodComm;
}

int Game::getChoice()
{
	string choice;
	int num = 0;
	getline(cin, choice);

	if(tolower(choice[0]) == 'r'){
		num = 1;
	}

	if(tolower(choice[0]) == 'p'){
		num = 2;
	}

	if(tolower(choice[0]) == 'f'){
		num = 3;
	}

	if(tolower(choice[0]) == 'v'){
		num = 4;
	}

	if(tolower(choice[0]) == 'e'){
		num = 5;
	}

	else if(num == 0){
		cout << "[" << choice << "] was not an option, please try again.\n";
	}

	return num;
}

bool Game::validateName(string name)
{
	bool goodName = true;		//input validity flag
	if(name.size() > 8){
		goodName = false;
	}
	return goodName;
}

void Game::playerXturn()
{
	string move;

	cout << "Turn number " << turnNum << endl;
	cout << ex.playerName << "'s turn.\n";
	availMoves = getAvailableMoves();
	displayField();
	cout << "Available moves: ";
	for(int i = 0; i < numMoves; i++){
		cout << availMoves[i] << " ";
	}
	cout << endl;
	do{
		cout << "Please select an available move.\n";
		getline(cin, move);
	} while (validateMove(move[0]) == false);
	cap(move[0] - 48, ex);
	turnNum++;
	exTurn = false;
}

void Game::playerOturn()
{
	string move;

	cout << "Turn number " << turnNum << endl;
	cout << oh.playerName << "'s turn.\n";
	availMoves = getAvailableMoves();
	displayField();
	cout << "Available moves: ";
	for(int i = 0; i < numMoves; i++){
		cout << availMoves[i] << " ";
	}
	cout << endl;
	do{
		cout << "Please select an available move.\n";
		getline(cin, move);
	} while (validateMove(move[0]) == false);
	cap(move[0] - 48, oh);
	turnNum++;
	exTurn = true;
}

bool Game::validateMove(char move)
{
	bool goodMove = false;

	for(int i = 0; i < numMoves; i++){
		if(move == availMoves[i]){
			goodMove = true;
		}
	}
	return goodMove;
}

char *Game::getAvailableMoves()
{
	int moves = 0;
	char *availableMoves;
	availableMoves = new char[numMoves];

	for(int row = 0; row < root; row++){
		for(int col = 0; col < root; col++){
			if(field->spaces[row][col].owned == false){
				availableMoves[moves] = field->spaces[row][col].owner;
				moves++;
			}
		}
	}
	numMoves = moves;
	return availableMoves;
}

void Game::play()
{
	bool replay = false;
	int choice;
	int numMoves;
	string move;
	string name;
	string set;
	Player eX;
	Player oH;
	char *availableMoves;

	cout << "Welcome to Tic-Tac-Toe! The clasic strategy edition.\n"
		<< "The object of the game is to get three of your tokens in\n"
		<< "a row while preventing your opponent from doing the same!\n";

	do
	{
		do
		{
			displayMenu();
			choice = getChoice();
		}while (choice == 0);

		switch (choice)
		{
		case 1:
			cout << "7 | 8 | 9     type one of these numbers\n"
				<< "- + - + - "
				<< "4 | 5 | 6  <- to capture that space!\n"
				<< "- + - + - "
				<< "1 | 2 | 3    \n"
				<< "Available Moves: 7 8 9 4 5 6 1 2 3\n"
				<< "Please select an available move.\n"
				<< "[type a number, then press enter]\n\n"
				<< "you may choose any space displayed that\n"
				<< "does not belong to another player. here's\n"
				<< "an example of such a condition:\n"
				<< "X | 8 | O     type one of these numbers\n"
				<< "- + - + -  \n"
				<< "4 | X | 6   <- to capture that space!\n"
				<< "- + - + -  \n"
				<< "1 | 2 | O     \n"
				<< "Available Moves: 7 8 9 4 5 6 1 2 3\n"
				<< "Please select an available move.\n"
				<< "[type a number, then press enter]\n\n"
				<< "The spaces 3 and 9 have been captured by\n"
				<< "player Oh; therefore player eX may not take\n"
				<< "Those spaces, nor spaces marked with thier own\n"
				<< "token \"X\" this game.\n\n"
				<< "Once a player has achieved victory or the game\n"
				<< "is a cat's game, you will be asked if you would\n"
				<< "like to play again.\n"
				<< "If you manage to win, your name and the board\n"
				<< "Configureation will be saved and you may use it\n"
				<< "to brag to your friends later.\n";
			break;

		case 2:
			do
			{
				cout << "Setting up new game...\n";
				do
				{
					cout << "Please enter the name of player eX:\n"
						<< "(up to eight characters long)\n";
					getline(cin, name);
				}while (validateName(name) == false);
				eX.playerName = name.c_str();
				name.clear();

				do
				{
					cout << "Please enter the name of player oH:\n"
						<< "(up to eight characters long)\n";
					getline(cin, name);
				}while (validateName(name) == false);
				oH.playerName = name.c_str();
				name.clear();

				eX.playerToken = 'X';
				oH.playerToken = 'O';
				Game *newGame;
				newGame = new Game(eX, oH);

				do
				{
					if(newGame->getExTurn()){
						newGame->playerXturn();
					}
					else
						newGame->playerOturn();

				} while (newGame->fatlady == false);

				if(newGame->victory){
					newGame->saveGame();
				}

				move.clear();
				cout << "would you like to play again?\n";
				getline(cin, move);
				if(tolower(move[0]) == 'y'){
					newGame->~Game();
					replay = true;
				}
				else
					delete newGame;

			} while (replay == true);
			break;

		case 3:
			do
			{
				Game *newGame;
				newGame = new Game();

				do
				{
					if(newGame->getExTurn()){
						newGame->playerXturn();
					}
					else
						newGame->playerOturn();

				} while (newGame->fatlady == false);

				if(newGame->victory){
					newGame->saveGame();
				}

				move.clear();
				cout << "would you like to play again?\n";
				getline(cin, move);
				if(tolower(move[0]) == 'y'){
					newGame->~Game();
					replay = true;
				}
				else
					delete newGame;

			} while (replay == true);
			break;

		case 4:
			dispVictories();
			break;

		case 5:
			cout << "Good bye.\n";
			break;
		} 
	}while(choice != 5);
}