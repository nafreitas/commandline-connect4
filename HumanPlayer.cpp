#include <iostream>
#include "Player.h"
#include "HumanPlayer.h"
using namespace std;

HumanPlayer::HumanPlayer() {
	string n;
	getline(cin, n);
	this->name = n;
}
HumanPlayer::~HumanPlayer() {
}
int HumanPlayer::makeMove() {
	int mov;
	cin >> mov;
	while (true)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please enter 1-7" << endl;
			cin >> mov;
		}
		if (!cin.fail())
			break;
	}

	//i = stoi(s, nullptr, 10) - 1;
	return mov - 1;
}
