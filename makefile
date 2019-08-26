CC = g++
DEBUG = -g
CFLAGS = -Wall -c -std=gnu++11 $(DEBUG)
LFLAGS = -Wall $(DEBUG)

compile: proj2.out

proj2.out: proj2.o Board.o Player.o HumanPlayer.o SimpleComputerPlayer.o
	$(CC) $(LFLAGS) -o proj2.out proj2.o Board.o Player.o HumanPlayer.o SimpleComputerPlayer.o

proj2.o: proj2.cpp Board.o Player.o HumanPlayer.o SimpleComputerPlayer.o
	$(CC) $(CFLAGS) proj2.cpp	

Board.o: Board.cpp Board.h
	$(CC) $(CFLAGS) Board.cpp

Player.o: Player.cpp Player.h
	$(CC) $(CFLAGS) Player.cpp

HumanPlayer.o: HumanPlayer.cpp HumanPlayer.h
	$(CC) $(CFLAGS) HumanPlayer.cpp

SimpleComputerPlayer.o: SimpleComputerPlayer.cpp SimpleComputerPlayer.h
	$(CC) $(CFLAGS) SimpleComputerPlayer.cpp

run: proj2.out
	./proj2.out -h -h

clean:
	rm *.o
	rm *.out
