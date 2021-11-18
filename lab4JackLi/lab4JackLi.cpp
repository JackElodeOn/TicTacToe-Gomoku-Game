#include "Game.h"
#include "Function.h"
#include "GameBoard.h"
#include "TicTacToe.h"
#include "Gomoku.h"
#include <vector>
#include <cstring>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

int main(int argc, char* argv[]) {
    GameBoard* game_ptr = GameBoard::initialize(argc, argv);
    if (game_ptr == 0) {
        string instruction = "TicTacToe";
        return usage_message(argv[program_name], instruction); // return ret_value::incorrect_input;
    }

    int ret = game_ptr->play();
    if (ret == func_ret_value::draw) {
        print_error(no_more_winning_moves);
        return ret_value::no_more_winning_moves;
    }
    else if (ret == func_ret_value::quit) {
        print_error(player_quit);
        return ret_value::player_quit;
    }
    else if (ret == func_ret_value::finished) {
        print_error(success);
        return ret_value::success;
    }
}