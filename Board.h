//
// Created by dualeoo on 30/4/17.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include "ArrayList.h"

struct Board {
    int board[8][8];
};

struct Board *BoardIni();

int free_board(struct Board *board, struct ArrayList *memory_which_has_been_free);
#endif //CHESS_BOARD_H_H
