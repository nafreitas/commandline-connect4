#include <string>
#ifndef PLAYER_H
#define PLAYER_H
class Board;
class Player {
public:
	Player();
	virtual ~Player() {};
	std::string name;
	std::string getName();
	virtual int makeMove();
};
#endif
