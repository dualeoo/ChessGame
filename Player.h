//
// Created by dualeoo on 30/4/17.
//
#ifndef CHESS_PLAYER_H
#define CHESS_PLAYER_H

#include <time.h>
#include "String.h"
#include "AI.h"
#include "ArrayList.h"

struct Player {
    struct String *name;
//    time_t date;
    char sex;
    int score;
    struct AI *ai;
};

struct Player *PlayerIni(struct String *name, char sex);

//struct Player *PlayerAIIni(struct String *name, char sex, struct AI * ai);

int free_player(struct Player *player, struct ArrayList *memory_which_has_been_free);

#endif