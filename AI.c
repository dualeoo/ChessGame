#include <stdlib.h>
#include "AI.h"
#include "Helper.h"
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
//    The goal is to identify the name of the piece corresponds with board[i][j]
    match->game->pieceName(match->game->board->board[i][j], &name);
    /* The goal is to print out the starting and ending positions of the AI. For example, if i, j, m, n are 0, 3, 7, 2
     * respectively, the starting and ending positions are D0 and C1 respectively.*/
    printf("%s from %c%d to %c%d\n\n", name, 'A' + j, 8 - i, 'A' + n, 8 - m);
    int previous_piece = (match->game->board->board[m][n]);
    match->game->board->board[m][n] = match->game->board->board[i][j];
    match->game->board->board[i][j] = 0;
    match->game->print_board_fp(match->game);
//    60 is the king of player 1
    if (previous_piece == 60) {
        printf("\nAI wins!");
        match->game->found_winner = 1;
    }
    match->game->turn++;

}

struct AI *AIIni() {
    struct AI *ai = malloc(sizeof(struct AI));
//    TOFREEX
//    ai->player = player;
    ai->next_move = &next_move;
    return ai;
}

int free_ai(struct AI *ai, struct ArrayList *memory_which_has_been_free) {
    char contain = 0;
    memory_which_has_been_free->al_search(memory_which_has_been_free, ai, &contain);
    if (!contain) {
        free(ai);
        memory_which_has_been_free->al_insert(memory_which_has_been_free, -1, ai);
    }
    return SUCCESS;
}
