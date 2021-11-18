/*Game.h
*
* Author:
*
* Email:
*
* This header file contains two structs used by tictactoe.cpp for organizing data.
* One of them is the game_piece struct that specifies how each game piece should be displayed.
* The other is the game_move struct used for storing past game moves.
* It also defares relevant methods for the two structs.
*/


#pragma once

#include <string>

using namespace std;

struct game_piece {
	string display;

	static string player_one_type;
	static string player_two_type;
	static string empty;

	// default constructor method for game_piece
	game_piece();
};

struct game_move {
	const unsigned int x_coor;
	const unsigned int y_coor;

	// default constructor method for game_move
	game_move();

	// this constructor for the game_move takes in two unsigned ints as two coordinates
	// for a game_move object
	game_move(unsigned int x, unsigned int y);
};

// this function takes in a reference to the output stream and a game_move object as its two input parameters
// It overrides the insertion operator to printing game_move objects to the terminal.
ostream& operator<<(ostream& out, const game_move move);