#ifndef CHESS_MATCH_H
#define CHESS_MATCH_H

#include "Game.h"
#include "Player.h"
#include "ArrayList.h"

struct Match {
    struct Game *game;
    struct Player *player;
};

struct Match *MatchIni(struct Game *, struct Player *);

int free_match(struct Match *match, struct ArrayList *memory_which_has_been_free);

#endif