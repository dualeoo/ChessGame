//
// Created by dualeoo on 30/4/17.
//

#ifndef CHESS_HELPER_H
#define CHESS_HELPER_H

#include "Database.h"
#include "Player.h"
#include "Match.h"

enum RESULT {
    SUCCESS, ILLEGAL_MOVE, NOT_SUPPORT, STOP_GAME, INVALID_INPUT
};

int player_mode(struct Database *database, struct Match *match);

int AI_mode(struct Database *database, struct Match *match);

int sign_in(struct Database *database, struct Player **player);

int sign_up(struct Database *database, struct Player **player);

int create_game(struct Database *, struct Player *);

int load_game(struct Database *, struct Player *);

int analyze_choice(char *choice, struct Database *database, struct Match *match);

int save_game();

int quit_game();

int new_game(struct Database *database, struct Player *player_main);

int row_id(char *choice, int *row);

int col_id(char *choice, int *col);

/*
 * This method aims to check if an iput is a valid ccell. For example, A1 is a valid cell but Z20 is not
 * Valid range is: A to H and 1 to 8
 * @param choice: The string corresponds to user input
 * @param check_result: the pointer to the result. Instead of return the checking result, the result is written through
 * a parameter. The reason is that I want to return the error code.
 * @return: the error code*/
int isCell(char *choice, char *checking_result);

int friend_does_not_have_account(struct Database *database, struct Match *match);

int main_loop(struct Database *database, struct Match *match, struct Player *player_second, char ai_mode);

#endif //CHESS_HELPER_H
