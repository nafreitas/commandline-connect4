#include <iostream>
#include "Board.h"
#include "Player.h"
using namespace std;
int plyr = 0; //keeps track of which player's turn it is
/*Board() initializes the bord with underscores*/
Board::Board() {
	for (unsigned int i = 0; i < 6; i++) {
		for (unsigned int j = 0; j < 7; j++) {
			this->gameBoard[i][j] = '_';
		}
	}
}
/* printBoard iterates through the 2d array and print the elemtns with the pipe symbol
 * surrounding each element as well as some additional formatting to replicate the
 * look of a real connect 4 board*/
void Board::printBoard(Board c) {
	cout << endl << " ===============" << endl;
	for (int i = 0; i < 6; i++) {
		cout << " ";
		for (int j = 0; j < 7; j++) {
			cout << "|" << c.gameBoard[i][j];
		}
		cout << "|" << endl;
	}
	cout << "/|\\           /|\\";
	cout << endl << endl;
}
/*starGame creates the board and begins the game*/
void Board::startGame(Player* o, Player* t) {
	Board bb;
	Board::printBoard(bb);
	int turnCount = 1;
	bool inprogress = true;
	while (inprogress == true) {
		int col = 0; // column for move made
		int gameState = 0; //0=in progress, 1=player 1 wins, 2=player 2 wins, 3=draw
		if (turnCount % 2 != 0) {
			plyr = 1;
			cout << o->getName() << "'s turn, Please enter an integer between 1 and 7: ";
			col = o->makeMove();
		}
		else {
			plyr = 2;
			cout << t->getName() << "'s turn, Please enter an integer between 1 and 7: ";
			col = t->makeMove();
		}
		col = Board::moveCheck(col);
		Board::insertChar(&bb, col, plyr); //places char in array from the int user input
		Board::printBoard(bb);//reprint board to reflect change

		/*check if game state changed*/
		if (gameState == 0)
			gameState = Board::winCheck(&bb, plyr);
		if (gameState == 0)
			gameState = Board::drawCheck(&bb);

		/*if game state changed, print message and end game*/

		switch (gameState)
		{
		case 0: turnCount++;
			break;
		case 1: cout << endl << o->getName() << " connected Four and Wins!" << endl;
			inprogress = false;
			break;
		case 2: cout << endl << t->getName() << " connected Four and Wins!" << endl;
			inprogress = false;
			break;
		case 3: cout << endl << "The board is full, it is a draw!" << endl;
			inprogress = false;
			break;
		default: break;
		}

	}//while loop
}//startGame

/*insertChar takes the player's column choice and inserts the appropriate
 *char value. The function starts at the bottom of the column working its way up
 *in search of an underscore to replace. Depending on the player flag, the function
 *knows whether to drop in an X or an O*/
void Board::insertChar(Board* b, int column, int player) {
	char c = NULL;
	int rows = 5;
	bool foundMove = false;
	if (player == 1) c = 'X';
	if (player == 2) c = 'O';
	for (int i = 0; i < 6; i++) {
		if (b->gameBoard[rows][column] == '_') {
			b->gameBoard[rows][column] = c;
			foundMove = true;
			break;
		}//if
		else rows--;
	}//for
	if (foundMove == false) {
		int move = Board::invalidMove();
		Board::insertChar(b, move, player);
	}
}//insertChar
/*winCheck checks if a player connected 4 in any direction*/
int Board::winCheck(Board* b, int playerwins) {
	int stillinprogress = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			/*compares the next 3 elements in the row that aren't underscores for a match*/
			if (b->gameBoard[i][j] != '_' && j <= 3 &&
				b->gameBoard[i][j] == b->gameBoard[i][j + 1] &&
				b->gameBoard[i][j] == b->gameBoard[i][j + 2] &&
				b->gameBoard[i][j] == b->gameBoard[i][j + 3]) {
				return playerwins;//returns gamestate indicating whether player 1 or 2 won
			}//if
			if (b->gameBoard[i][j] != '_' && i <= 2 &&
				b->gameBoard[i][j] == b->gameBoard[i + 1][j] &&
				b->gameBoard[i][j] == b->gameBoard[i + 2][j] &&
				b->gameBoard[i][j] == b->gameBoard[i + 3][j]) {
				return playerwins;
			}
			if (b->gameBoard[i][j] != '_' && j <= 3 && i <= 2 &&
				b->gameBoard[i][j] == b->gameBoard[i + 1][j + 1] &&
				b->gameBoard[i][j] == b->gameBoard[i + 2][j + 2] &&
				b->gameBoard[i][j] == b->gameBoard[i + 3][j + 3]) {
				return playerwins;
			}
			if (b->gameBoard[i][j] != '_' && j >= 3 && i <= 2 &&
				b->gameBoard[i][j] == b->gameBoard[i + 1][j - 1] &&
				b->gameBoard[i][j] == b->gameBoard[i + 2][j - 2] &&
				b->gameBoard[i][j] == b->gameBoard[i + 3][j - 3]) {
				return playerwins;
			}// if
		}//for j
	}//for i
	return stillinprogress;
}//winCheck

/*moveCheck makes sure a player entered an integer within the accepted 1-7 range*/
int Board::moveCheck(int move) {
	if (move >= 0 && move <= 6)
		return move;
	else return Board::invalidMove();
}
/*invalidMove makes sure they aren't inputting character strings,
 *and also makes sure that they aren't trying to make a move where
 *the column is already full*/
int Board::invalidMove() {
	cout << "Invalid move selection, please pick a column 1-7 that isn't full." << endl;
	int move;
	cin >> move;
	while (true)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please enter 1-7" << endl;
			cin >> move;
		}
		if (!cin.fail())
			break;
	}
	move--;

	move = Board::moveCheck(move);
	return move;
}

/*drawCheck skims the top row looking for an underscore to denote an empty space, else draw*/
int Board::drawCheck(Board* b) {
	int draw = 3;
	int stillinprogress = 0;
	for (int i = 0; i < 7; i++) {
		if (b->gameBoard[0][i] == '_')
			return stillinprogress;
	}
	return draw;
}