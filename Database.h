//
// Created by dualeoo on 30/4/17.
//

#ifndef CHESS_DATABASE_H
#define CHESS_DATABASE_H

#include "Match.h"
#include "Player.h"
#include "Game.h"
#include "ArrayList.h"

struct Database {
//    The goal of the next 4 fields is to record the next ID
    int next_match_i;
    int next_player_i;
    int next_game_i;
    int next_AI_i;
    struct Match **matches;
    struct Player **players;
    struct Game **games;

    int (*addMatch)(struct Database *, struct Match *);

    int (*addPlayer)(struct Database *, struct Player *);

    int (*addGame)(struct Database *, struct Game *);

};

struct Database *DatabaseIni();

int addMatch(struct Database *this, struct Match *match);

int addPlayer(struct Database *this, struct Player *);

int addGame(struct Database *this, struct Game *);

int free_database(struct Database *database);

#endif //CHESS_DATABASE_H
