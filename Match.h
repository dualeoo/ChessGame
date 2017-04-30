#ifndef CHESS_MATCH_H
#define CHESS_MATCH_H

#include "Game.h"
#include "Player.h"

struct Match {
    struct Game *game;
    struct Player *player;
};

struct Match *MatchIni(struct Game *, struct Player *);

#endif