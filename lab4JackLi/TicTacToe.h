#pragma once
#include <vector>
#include "Game.h"
#include "GameBoard.h"
#include <iostream>

class TicTacToeGame : public GameBoard {
	friend ostream& operator<<(ostream& out, const TicTacToeGame& game);

public:

	TicTacToeGame();
	virtual ~TicTacToeGame();

	virtual void print();

	// This funtion determines whether one of the player has won the game
	// by determining whether there os a <win_num> number of game pieces
	// of the same kind on a row, column, or disgonally.
	virtual bool done();

	// This function determines whether there are additional valid
	// moves left on the game board.
	virtual bool draw();


	// This function determines which player's turn it is. It prompts the appropriate user
	// (via prompt()) for coordinates for their next move, and determine if that move is valid.
	// After the move, it prints out the updated game board, as well as the set of moves played
	// by the player who just made a move. 
	virtual int turn();

	// The function continuously calls the done(), draw(), and play() methods to update the status 
	// of the game. It returns the appropriate value corresponding to user quitted the game, draw,
	// or success (one of the players won the game).
	virtual int play();

};

// this function overloads the insertion operator for printing the TicTacToeGame object to
// the terminal window by printing each of the game pieces located on the board. 
ostream & operator<<(ostream & out, const TicTacToeGame & game);
