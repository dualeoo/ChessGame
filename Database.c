//
// Created by dualeoo on 30/4/17.
//

#include <stdlib.h>
#include "Database.h"

#define SIZE 100
//TODO: implement data strucutre using TreeSet and HashSet instead of array like now

struct Database *DatabaseIni() {
    struct Database *database = malloc(sizeof(struct Database));
//    TOFREE
    database->matches = calloc(SIZE, sizeof(struct Match *));
    database->players = calloc(SIZE, sizeof(struct Player *));
    database->games = calloc(SIZE, sizeof(struct Game *));
    database->addMatch = &addMatch;
    database->addGame = &addGame;
    database->addPlayer = &addPlayer;
    return database;
}

//TODO implement add methods
int addMatch(struct Database *this, struct Match *match) {
    this->matches[this->next_match_i++] = match;
    return 0;
}

int addPlayer(struct Database *this, struct Player *player) {
    this->players[this->next_player_i++] = player;
    return 0;
}

int addGame(struct Database *this, struct Game *game) {
    this->games[this->next_game_i++] = game;
    return 0;
}