/*Game.cpp
*
* Author:
*
* Email:
*
* This source file contain the definition of the constructor methods of the two structs declared in game.h.
* It also defines how the game_piece objects should be printed.
* Further, it defines an operator-overriding method for printint the game_move object.
*/

#include "Game.h"
#include <iostream>

using namespace std;

game_piece::game_piece() : display(empty) {}

string game_piece::player_one_type = "X";
string game_piece::player_two_type = "O";
string game_piece::empty = " ";

game_move::game_move() : x_coor(0), y_coor(0) {}

game_move::game_move(unsigned int x, unsigned int y) : x_coor(x), y_coor(y) {}

ostream& operator<<(ostream& out, const game_move move) {
	out << move.x_coor << "," << move.y_coor << "; ";
	return out;
}