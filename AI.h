//
// Created by dualeoo on 30/4/17.
//


#ifndef CHESS_AI_H
#define CHESS_AI_H

#include "Match.h"
#include "ArrayList.h"

void next_move(struct Match *match);

struct AI {
//    struct Player *player;

    void (*next_move)(struct Match *);
};

//struct AI *AIIni(struct Player *player);
struct AI *AIIni();

int free_ai(struct AI *ai, struct ArrayList *memory_which_has_been_free);
#endif