#include <stdlib.h>
#include "Board.h"
#include "Helper.h"


struct Board *BoardIni() {
    struct Board *board = malloc(sizeof(struct Board));
//    TOFREE

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            board->board[i][j] = 0;
//    The for loop is to set the position of the pawn
    for (int i = 0; i < 8; i++) {
        board->board[6][i] = 11;
        board->board[1][i] = 10;
    }
//    Set the position of remaining pieces
//    Rook
    board->board[0][0] = board->board[0][7] = 20;
    board->board[7][0] = board->board[7][7] = 22;
//    Knight
    board->board[0][1] = board->board[0][6] = 30;
    board->board[7][1] = board->board[7][6] = 33;
//    Bishop
    board->board[0][2] = board->board[0][5] = 40;
    board->board[7][2] = board->board[7][5] = 44;
//    Queen
    board->board[0][3] = 50;
    board->board[7][3] = 55;
//    King
    board->board[0][4] = 60;
    board->board[7][4] = 66;

    return board;
}

int free_board(struct Board *board, struct ArrayList *memory_which_has_been_free) {
    char contain = 0;
    memory_which_has_been_free->al_search(memory_which_has_been_free, board, &contain);
    if (!contain) {
        free(board);
        memory_which_has_been_free->al_insert(memory_which_has_been_free, -1, board);
    }
    return SUCCESS;
};