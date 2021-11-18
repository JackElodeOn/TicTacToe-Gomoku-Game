#pragma once
#include <vector>
#include "Game.h"
#include <iostream>

class GameBoard {
	friend ostream& operator<<(ostream& out, const GameBoard& game);
protected:

	// full size of the board
	unsigned int width;
	unsigned int height;

	// the minimum x- and y-coordinates allowed on the board
	unsigned int width_lower;
	unsigned int height_lower;

	// the maximum x- and y-coordinates allowed on the board
	unsigned int width_upper;
	unsigned int height_upper;

	// number of pieces in a line to constitue a win
	unsigned int win_num;

	// longest display string length
	unsigned int display_length;

	// 2D vector for holding game_piece objects
	vector<vector<game_piece>> pieces;

	// boolean specifying the current player's turn 
	bool p1_turn;

	// the total number of turns already places
	unsigned int turn_count;

	// vectors for holding the moves for player 1 and player 2, respectively
	vector<game_move> p1_moves;
	vector<game_move> p2_moves;


public:

	GameBoard(
		unsigned int, unsigned int,
		unsigned int, unsigned int,
		unsigned int, unsigned int,
		unsigned int, unsigned int,
		bool);

	// This function prompt the user for input coordinates for a new game piece
	// to be places on the board. This function expects either the string "quit"
	// or two space and/or comma separated unsigned int values that are within 
	// the current range.
	// This function will keep prompting the user for input if neither of the 
	// expected values are receives.
	int prompt(unsigned int& x_coor, unsigned int& y_coor);

	static GameBoard* initialize(int, char* []);

	// This function checks whether a given set of unsigned ints are within set limits
	bool check_bound(const unsigned int, const unsigned int);

	virtual void print() = 0;

	// This funtion determines whether one of the player has won the game
	// by determining whether there os a <win_num> number of game pieces
	// of the same kind on a row, column, or disgonally.
	virtual bool done() = 0;

	// This function determines whether there are additional valid
	// moves left on the game board.
	virtual bool draw() = 0;


	// This function determines which player's turn it is. It prompts the appropriate user
	// (via prompt()) for coordinates for their next move, and determine if that move is valid.
	// After the move, it prints out the updated game board, as well as the set of moves played
	// by the player who just made a move. 
	virtual int turn() = 0;

	// The function continuously calls the done(), draw(), and play() methods to update the status 
	// of the game. It returns the appropriate value corresponding to user quitted the game, draw,
	// or success (one of the players won the game).
	virtual int play() = 0;

	void set_win_num(unsigned int);
};