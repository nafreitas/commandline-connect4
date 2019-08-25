#ifndef BOARD_H
#define BOARD_H
#include "Player.h"
class Board {
public:
	char gameBoard[6][7];
	Board();
	static void printBoard(Board c);
	static void startGame(Player* o, Player* t);
	static void insertChar(Board* b, int column, int player);
	static int moveCheck(int move);
	static int invalidMove();
	static int winCheck(Board* b, int playerwins);
	static int drawCheck(Board* b);
};
#endif
