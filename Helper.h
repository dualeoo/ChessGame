//
// Created by dualeoo on 30/4/17.
//

#ifndef CHESS_HELPER_H
#define CHESS_HELPER_H

#include "Database.h"
#include "Player.h"

int player_mode(struct Database *database, struct Match *match, struct Player *player_second);

int AI_mode();

int sign_in(struct Database *database, struct Player **player);

int sign_up(struct Database *database, struct Player **player);

int create_game(struct Database *, struct Player *, struct Player *);

int load_game(struct Database *, struct Player *);

#endif //CHESS_HELPER_H
