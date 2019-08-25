#include <iostream>
#include "Board.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "SimpleComputerPlayer.h"
using namespace std;

int main(int argc, char* argv[]) {
	string p1 = argv[1];
	string p2 = argv[2];
	Player* ptr1 = NULL;
	Player* ptr2 = NULL;
	cout << "Let's Start a Game of Connect 4!" << endl << endl;
	if (p1 == "-h") {
		cout << "Player One, please enter your name: ";
		ptr1 = new HumanPlayer();
	}
	else if (p1 == "-c")
	{
		cout << "Enter name for Player 1 CPU: ";
		ptr1 = new SimpleComputerPlayer();
	}
	if (p2 == "-h") {
		cout << "Player Two, please enter your name: ";
		ptr2 = new HumanPlayer();
	}
	else if (p2 == "-c")
	{
		cout << "Enter name for Player 2 CPU: ";
		ptr2 = new SimpleComputerPlayer();
	}
	Board::startGame(ptr1, ptr2);
	return EXIT_SUCCESS;
}
