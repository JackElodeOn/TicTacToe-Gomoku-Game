/*TicTacToe.cpp
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


#include "Game.h"
#include "Function.h"
#include "GameBoard.h"
#include "TicTacToe.h"
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

TicTacToeGame::TicTacToeGame() : GameBoard(5, 5, 1, 1, 3, 3, 3, 1, true) {
    game_piece::player_one_type = "X";
    game_piece::player_two_type = "O";
}

TicTacToeGame::~TicTacToeGame() {
    delete this;
}

void TicTacToeGame::print() {
    cout << *this << endl;
}


bool TicTacToeGame::done() {

    bool win = false;

    // checking for wins along the rows
    // iterating through each row
    for (unsigned int j = height_lower; j <= height_upper; ++j) {
        //iterating over game pieces on the same row
        for (unsigned int i = width_lower; i <= width_upper - win_num + 1; ++i) {
            game_piece curr_piece = pieces[i][j];
            // only check along the row if current position is occupied
            if (curr_piece.display != game_piece::empty) {
                for (unsigned int k = 1; k < win_num; ++k) {
                    if (pieces[i + k][j].display == curr_piece.display) {
                        win = true;
                    }
                    else {
                        win = false;
                        break;
                    }
                    curr_piece = pieces[i + k][j];
                }
                if (win) {
                    return win;
                }
            }
        }
    }

    // checking for wins along the columns

     // iterating through each column
    for (unsigned int i = width_lower; i <= width_upper; ++i) {
        //iterating over game pieces on the same column
        for (unsigned int j = height_lower; j <= height_upper - win_num + 1; ++j) {
            game_piece curr_piece = pieces[i][j];
            // only check along the row if current position is occupied
            if (curr_piece.display != game_piece::empty) {
                for (unsigned int k = 1; k < win_num; ++k) {
                    if (pieces[i][j + k].display == curr_piece.display) {
                        win = true;
                    }
                    else {
                        win = false;
                        break;
                    }
                    curr_piece = pieces[i][j + k];
                }
                if (win) {
                    return win;
                }
            }
        }
    }

    // checking for wins along diagnals in "\" direction (I)
    for (unsigned int j = height_lower; j <= height_upper - win_num + 1; ++j) {

        for (unsigned int i = width_upper; i >= width_lower + win_num - 1; --i) {
            game_piece curr_piece = pieces[i][j];
            // only check along the disgonal if current position is occupied
            if (curr_piece.display != game_piece::empty) {
                for (unsigned int k = 1; k < win_num; ++k) {
                    if (pieces[i - k][j + k].display == curr_piece.display) {
                        win = true;
                    }
                    else {
                        win = false;
                        break;
                    }
                    curr_piece = pieces[i - k][j + k];
                }
                if (win) {
                    return win;
                }
            }
        }
    }

    // checking for wins along diagnals in "/" direction (II)
    for (unsigned int j = height_lower; j <= height_upper - win_num + 1; ++j) {

        for (unsigned int i = width_lower; i <= width_upper - win_num + 1; ++i) {
            game_piece curr_piece = pieces[i][j];

            // only check along the disgonal if current position is occupied
            if (curr_piece.display != game_piece::empty) {
                for (unsigned int k = 1; k < win_num; ++k) {
                    if (pieces[i + k][j + k].display == curr_piece.display) {
                        win = true;
                    }
                    else {
                        win = false;
                        break;
                    }
                    curr_piece = pieces[i + k][j + k];
                }
                if (win) {
                    return win;
                }
            }
        }
    }
    return win;
}

bool TicTacToeGame::draw() {
    if (turn_count == (width_upper - width_lower + 1) * (height_upper - height_lower + 1)) {
        return true;
    }

    bool win_move = false;

    // checking for wins along the rows
    // iterating through each row
    for (unsigned int j = height_lower; j <= height_upper; ++j) {
        //iterating over game pieces on the same row
        for (unsigned int i = width_lower; i <= width_upper - win_num + 1; ++i) {
            game_piece curr_piece = pieces[i][j];
            // only check along the row if current position is occupied
            if (curr_piece.display == game_piece::player_one_type) {
                for (unsigned int k = 1; k < win_num; ++k) {
                    if (pieces[i + k][j].display == game_piece::player_two_type) {
                        win_move = false;
                        break;
                    }
                    else {
                        win_move = true;
                    }
                }
                if (win_move) {
                    return !win_move;
                }
            }
            else if (curr_piece.display == game_piece::player_two_type) {
                for (unsigned int k = 1; k < win_num; ++k) {
                    if (pieces[i + k][j].display == game_piece::player_one_type) {
                        win_move = false;
                        break;
                    }
                    else {
                        win_move = true;
                    }
                }
                if (win_move) {
                    return !win_move;
                }
            }
            else if (curr_piece.display == game_piece::empty) {
                string temp = game_piece::empty;
                bool temp_set = false;
                for (unsigned int k = 1; k < win_num; ++k) {
                    if (pieces[i + k][j].display != game_piece::empty && temp_set == false) {
                        temp = pieces[i + k][j].display;
                        temp_set = true;
                    }
                    if (pieces[i + k][j].display != game_piece::empty && pieces[i + k][j].display != temp) {
                        win_move = false;
                        break;
                    }
                    else if (pieces[i + k][j].display == game_piece::empty || pieces[i + k][j].display == temp) {
                        win_move = true;
                    }
                }
                if (win_move) {
                    return !win_move;
                }
            }
        }
    }

    // checking for wins along the columns

     // iterating through each column
    for (unsigned int i = width_lower; i <= width_upper; ++i) {
        //iterating over game pieces on the same column
        for (unsigned int j = height_lower; j <= height_upper - win_num + 1; ++j) {
            game_piece curr_piece = pieces[i][j];
            // only check along the row if current position is occupied

            if (curr_piece.display == game_piece::player_one_type) {
                for (unsigned int k = 1; k < win_num; ++k) {
                    if (pieces[i][j + k].display == game_piece::player_two_type) {
                        win_move = false;
                        break;
                    }
                    else {
                        win_move = true;
                    }
                }
                if (win_move) {
                    return !win_move;
                }
            }
            else if (curr_piece.display == game_piece::player_two_type) {
                for (unsigned int k = 1; k < win_num; ++k) {
                    if (pieces[i][j + k].display == game_piece::player_one_type) {
                        win_move = false;
                        break;
                    }
                    else {
                        win_move = true;
                    }
                }
                if (win_move) {
                    return !win_move;
                }
            }
            else if (curr_piece.display == game_piece::empty) {
                string temp = game_piece::empty;
                bool temp_set = false;
                for (unsigned int k = 1; k < win_num; ++k) {
                    if (pieces[i][j + k].display != game_piece::empty && temp_set == false) {
                        temp = pieces[i][j + k].display;
                        temp_set = true;
                    }
                    if (pieces[i][j + k].display != game_piece::empty && pieces[i][j + k].display != temp) {
                        win_move = false;
                        break;
                    }
                    else if (pieces[i][j + k].display == game_piece::empty || pieces[i][j + k].display == temp) {
                        win_move = true;
                    }
                }
                if (win_move) {
                    return !win_move;
                }
            }
        }
    }

    // checking for wins along diagnals in "\" direction (I)
    for (unsigned int j = height_lower; j <= height_upper - win_num + 1; ++j) {

        for (unsigned int i = width_upper; i >= width_lower + win_num - 1; --i) {
            game_piece curr_piece = pieces[i][j];
            // only check along the disgonal if current position is occupied

            if (curr_piece.display == game_piece::player_one_type) {
                for (unsigned int k = 1; k < win_num; ++k) {
                    if (pieces[i - k][j + k].display == game_piece::player_two_type) {
                        win_move = false;
                        break;
                    }
                    else {
                        win_move = true;
                    }
                }
                if (win_move) {
                    return !win_move;
                }
            }
            else if (curr_piece.display == game_piece::player_two_type) {
                for (unsigned int k = 1; k < win_num; ++k) {
                    if (pieces[i - k][j + k].display == game_piece::player_one_type) {
                        win_move = false;
                        break;
                    }
                    else {
                        win_move = true;
                    }
                }
                if (win_move) {
                    return !win_move;
                }
            }
            else if (curr_piece.display == game_piece::empty) {
                string temp = game_piece::empty;
                bool temp_set = false;
                for (unsigned int k = 1; k < win_num; ++k) {
                    if (pieces[i - k][j + k].display != game_piece::empty && temp_set == false) {
                        temp = pieces[i - k][j + k].display;
                        temp_set = true;
                    }
                    if (pieces[i - k][j + k].display != game_piece::empty && pieces[i - k][j + k].display != temp) {
                        win_move = false;
                        break;
                    }
                    else if (pieces[i - k][j + k].display == game_piece::empty || pieces[i - k][j + k].display == temp) {
                        win_move = true;
                    }
                }
                if (win_move) {
                    return !win_move;
                }
            }
        }
    }

    // checking for wins along diagnals in "/" direction (II)
    for (unsigned int j = height_lower; j <= height_upper - win_num + 1; ++j) {

        for (unsigned int i = width_lower; i <= width_upper - win_num + 1; ++i) {
            game_piece curr_piece = pieces[i][j];



            if (curr_piece.display == game_piece::player_one_type) {
                for (unsigned int k = 1; k < win_num; ++k) {
                    if (pieces[i + k][j + k].display == game_piece::player_two_type) {
                        win_move = false;
                        break;
                    }
                    else {
                        win_move = true;
                    }
                }
                if (win_move) {
                    return !win_move;
                }
            }
            else if (curr_piece.display == game_piece::player_two_type) {
                for (unsigned int k = 1; k < win_num; ++k) {
                    if (pieces[i + k][j + k].display == game_piece::player_one_type) {
                        win_move = false;
                        break;
                    }
                    else {
                        win_move = true;
                    }
                }
                if (win_move) {
                    return !win_move;
                }
            }
            else if (curr_piece.display == game_piece::empty) {
                string temp = game_piece::empty;
                bool temp_set = false;
                for (unsigned int k = 1; k < win_num; ++k) {
                    if (pieces[i + k][j + k].display != game_piece::empty && temp_set == false) {
                        temp = pieces[i + k][j + k].display;
                        temp_set = true;
                    }
                    if (pieces[i + k][j + k].display != game_piece::empty && pieces[i + k][j + k].display != temp) {
                        win_move = false;
                        break;
                    }
                    else if (pieces[i + k][j + k].display == game_piece::empty || pieces[i + k][j + k].display == temp) {
                        win_move = true;
                    }
                }
                if (win_move) {
                    return !win_move;
                }
            }
        }
    }
    return !win_move;
}


int TicTacToeGame::turn() {
    unsigned int x_;
    unsigned int y_;
    while (true) {
        if (p1_turn) {
            cout << "Play one's (" << game_piece::player_one_type << ") turn." << endl;
            if (prompt(x_, y_) == func_ret_value::quit) {
                return func_ret_value::quit;
            }
            else {
                // setting the game piece only if target position is unoccupied
                if (pieces[x_][y_].display == game_piece::empty) {
                    pieces[x_][y_].display = game_piece::player_one_type;
                    p1_moves.push_back(game_move(x_, y_));
                    turn_count++;
                    p1_turn = false;

                    // printing the board
                    cout << endl;
                    this->print();
                    cout << endl;

                    // printing the list of moves
                    cout << "Play one's (" << game_piece::player_one_type << ") moves: ";
                    for (unsigned int i = 0; i < p1_moves.size(); ++i) {
                        cout << p1_moves[i];
                    }

                    cout << endl;
                    cout << endl;
                    return func_ret_value::turn_success;
                }
                else {
                    cout << "The specified square is not empty. " << endl;
                    continue;
                }
            }
        }
        else {
            cout << "Play two's (" << game_piece::player_two_type << ") turn." << endl;
            if (prompt(x_, y_) == func_ret_value::quit) {
                return func_ret_value::quit;
            }
            else {
                // setting the game piece only if target position is unoccupied
                if (pieces[x_][y_].display == game_piece::empty) {
                    pieces[x_][y_].display = game_piece::player_two_type;
                    p2_moves.push_back(game_move(x_, y_));
                    turn_count++;
                    p1_turn = true;

                    // printing the board
                    cout << endl;
                    this->print();
                    cout << endl;

                    // printing the list of moves
                    cout << "Play two's (" << game_piece::player_two_type << ") moves: ";
                    for (unsigned int i = 0; i < p2_moves.size(); ++i) {
                        cout << p2_moves[i];
                    }
                    cout << endl;
                    cout << endl;

                    return func_ret_value::turn_success;
                }
                else {
                    cout << "The specified square is not empty. " << endl;
                    continue;
                }
            }
        }
    }
}

int TicTacToeGame::play() {
    cout << endl;
    this->print();
    cout << endl;
    while (true) {
        // player quits
        if (turn() == func_ret_value::quit) {
            if (p1_turn) {
                cout << turn_count << " turns were played. Player 1 (" << game_piece::player_one_type << ") quitted the game. " << endl;
            }
            else {
                cout << turn_count << " turns were played. Player 2 (" << game_piece::player_two_type << ") quitted the game. " << endl;
            }
            return func_ret_value::quit;
        }
        // one of the players won
        if (done()) {
            if (p1_turn) {
                cout << "Play two's (" << game_piece::player_two_type << ") won the game! ";
            }
            else {
                cout << "Play one's (" << game_piece::player_one_type << ") won the game!";
            }
            return func_ret_value::finished;
        }
        // no more valid moves
        if (draw()) {
            cout << turn_count << " turns were played. No winning moves remain. " << endl;
            return func_ret_value::draw;
        }
    }
}

ostream& operator<<(ostream& out, const TicTacToeGame& game) {
    for (unsigned int j = game.height - 1; j >= 0 && j < game.height; --j) {
        cout << j << " ";
        for (unsigned int i = 0; i < game.width; ++i) {
            cout << game.pieces[i][j].display << " ";
        }
        cout << endl;
    }
    cout << "  ";
    for (unsigned int i = 0; i < game.width; ++i) {
        cout << i << " ";
    }
    cout << endl;
    return out;
}