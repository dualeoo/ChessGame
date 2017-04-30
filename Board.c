#include <stdlib.h>
#include "Board.h"

struct Board *BoardIni() {
    struct Board *board = malloc(sizeof(struct Board));
//    TOFREE

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            board->board[i][j] = 0;
    for (int i = 0; i < 8; i++) {
        board->board[6][i] = 10;
        board->board[1][i] = 11;
    }

    board->board[0][0] = board->board[0][7] = 22;
    board->board[7][0] = board->board[7][7] = 20;
    board->board[0][1] = board->board[0][6] = 33;
    board->board[7][1] = board->board[7][6] = 30;
    board->board[0][2] = board->board[0][5] = 44;
    board->board[7][2] = board->board[7][5] = 40;
    board->board[0][3] = 55;
    board->board[7][3] = 50;
    board->board[0][4] = 66;
    board->board[7][4] = 60;

    return board;
}