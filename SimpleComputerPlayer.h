#include "Player.h"
#ifndef SIMPLECOMPUTERPLAYER_H
#define SIMPLECOMPUTERPLAYER_H

class SimpleComputerPlayer : public Player {
public:
	SimpleComputerPlayer();
	virtual ~SimpleComputerPlayer();
	virtual int makeMove(Board* b);
};
#endif
