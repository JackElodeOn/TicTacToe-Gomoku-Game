/*GameBoard.cpp
*
* Author:
*
* Email:
*

*/

#pragma once

#include "Game.h"
#include "Function.h"
#include "GameBoard.h"
#include "TicTacToe.h"
#include "Gomoku.h"
#include <vector>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

GameBoard::GameBoard(unsigned int width_, unsigned int height_,
    unsigned int width_lower_, unsigned int height_lower_,
    unsigned int width_upper_, unsigned int height_upper_,
    unsigned int win_num_, unsigned int display_length_,
    bool p1_turn_) :
    pieces(vector<vector<game_piece>>(width_, vector<game_piece>(height_, game_piece()))),
    p1_moves(vector<game_move>(0)),
    p2_moves(vector<game_move>(0))
{

    width = width_;
    height = height_;
    width_lower = width_lower_;
    height_lower = height_lower_;
    width_upper = width_upper_;
    height_upper = height_upper_;
    win_num = win_num_;
    display_length = display_length_;
    p1_turn = p1_turn_;
    turn_count = 0;
}

int GameBoard::prompt(unsigned int& x_, unsigned int& y_) {
    string line;
    string first_;
    string second_;
    bool received = false;
    while (true) {
        cout << "Type <quit> to quit, or type <x,y>, <x, y> or <x y> as coordinates to make a move." << endl;
        getline(cin, line);
        replace(line.begin(), line.end(), ',', ' '); // eliminating comma
        istringstream iss(line);
        if (iss >> first_) {
            to_lower(first_); // convert to all lower case
            if (first_ == "quit") {
                return func_ret_value::quit;
            }
            else {
                istringstream iss2(first_);
                if (iss2 >> x_) {
                    if (iss >> y_) {
                        if (check_bound(x_, y_)) {
                            return func_ret_value::size_extraction_success;
                        }
                        else {
                            cout << "Coordinate(s) out of bounds." << endl;
                            continue;
                        }
                    }
                    else {
                        cout << "Invalid input." << endl;
                        continue;
                    }
                }
                else {
                    cout << "Invalid input. " << endl;
                    continue;
                }
            }
        }
        else {
            cout << "Invalid input." << endl;
            continue;
        }
    }
}

GameBoard* GameBoard::initialize(int args_num, char* args[]) {
    if (args_num == num_of_arguments && strcmp(args[game_name], "TicTacToe") == 0) {
        TicTacToeGame* game = new TicTacToeGame();
        return game;
    }
    else if (args_num == num_of_arguments && strcmp(args[game_name], "Gomoku") == 0) {
        GomokuGame* game = new GomokuGame();
        return game;
    }
    else if (args_num == arguments_with_size && strcmp(args[game_name], "Gomoku") == 0) {
        GomokuGame* game = new GomokuGame(atoi(args[game_size]));
        return game;
    }
    else if (args_num == arguments_with_win && strcmp(args[game_name], "Gomoku") == 0) {
        GomokuGame* game = new GomokuGame(atoi(args[game_size]), atoi(args[win_size]));
        return game;
    }
    return 0;
}

bool GameBoard::check_bound(const unsigned int x_, const unsigned int y_) {
    return ((x_ >= width_lower && x_ <= width_upper) && (y_ >= height_lower && y_ <= height_upper));
}

void GameBoard::set_win_num(unsigned int winNum) {
    win_num = winNum;
}