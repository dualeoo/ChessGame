//
// Created by dualeoo on 30/4/17.
//
#ifndef CHESS_PLAYER_H
#define CHESS_PLAYER_H

#include <time.h>
#include "String.h"

struct Player {
    struct String *name;
//    time_t date;
    char sex;
    int score;

    void (*move)(int, int, int, int);

    void (*win)();

    void (*save)();

    void (*load)();
};

void move(int old_pos_x, int old_pos_y, int new_pos_x, int new_pos_y);

void win();

void save();

void load();

struct Player *PlayerIni(struct String *name, char sex);

#endif