//
// Created by dualeoo on 30/4/17.
//
#ifndef CHESS_AI_H
#define CHESS_AI_H

#include "Player.h"

struct AI {
    struct Player *player;

    void (*next_move)();
};

void next_move();

struct AI *AIIni(struct Player *player);

#endif