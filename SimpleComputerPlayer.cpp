#include <iostream>
#include "Player.h"
#include "SimpleComputerPlayer.h"
#include "Board.h"
using namespace std;


SimpleComputerPlayer::SimpleComputerPlayer() {
	string n = "Zoey";
	this->name = n;
	cout << "Zoey" << endl;;
}
SimpleComputerPlayer::~SimpleComputerPlayer() {
}
int SimpleComputerPlayer::makeMove(Board* b) {
	for (int i = 0; i < 7; i++) {
		if (b->gameBoard[0][i] == '_') {
			cout << i + 1 << endl;
			return i + 1;
		}
	}
	return 0;
}
