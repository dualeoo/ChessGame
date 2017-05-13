#include <stdlib.h>
#include "AI.h"
#include <stdio.h>

void next_move(struct Match *match) {
    int legal = 0;
    char i = 0;
    char j = 0;
    char m = 0;
    char n = 0;
    do {
        i = (char) (rand() % 8);
        j = (char) (rand() % 8);
        m = (char) (rand() % 8);
        n = (char) (rand() % 8);
        legal = match->game->check_legal_fp(match->game, i, j, m, n, match->game->turn % 2 + 1);
    } while (!legal);
    char *name = NULL;
    match->game->pieceName(match->game->board->board[i][j], &name);
    printf("%s from %c%d to %c%d\n\n", name, 'A' + j, 8 - i, 'A' + n, 8 - m);
    int previous_piece = (match->game->board->board[m][n]);
    match->game->board->board[m][n] = match->game->board->board[i][j];
    match->game->board->board[i][j] = 0;
    match->game->print_board_fp(match->game);
    if (previous_piece == 60) {
        printf("\nAI wins!");
        match->game->found_winner = 1;
    }
    match->game->turn++;

}

struct AI *AIIni() {
    struct AI *ai = malloc(sizeof(struct AI));
//    ai->player = player;
    ai->next_move = &next_move;
    return ai;
}
