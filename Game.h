#ifndef CHESS_GAME_H
#define CHESS_GAME_H

#include <time.h>

/*
 * p1/p2 Pawn = 10/11
 * p1/p2 Rook = 20/22
 * p1/p2 Knight = 30/33
 * p1/p2 Bishop = 40/44
 * p1/p2 Queen = 50/55
 * p1/p2 King = 60/66
 */

struct Game {
    time_t time_elapsed;
    char found_winner;
    struct Board *board;
    int turn;

    int (*check_legal_fp)(struct Game *, int i, int j, int m, int n, int p);

    int (*print_board_fp)(struct Game *);
};

/***
	Checks if the move is LEGAL or NOT
	 move from (i,j) to (m,n)
	 p = 1 :: RED chessMen (modulus 10 == 0)
	 p = 2 :: GREEN chessMen (modulus 10 != 0)
	 return 1 is legal, 0 is not legal.
***/
int check_legal(struct Game *this, int i, int j, int m, int n, int p);

int print_board(struct Game *this);

struct Game *GameIni();

#endif