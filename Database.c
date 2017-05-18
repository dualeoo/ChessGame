//
// Created by dualeoo on 30/4/17.
//

#include <stdlib.h>
#include "Database.h"
#include "Helper.h"


#define SIZE 100
// TODO: implement data structure using TreeSet and HashSet instead of array like now

struct Database *DatabaseIni() {
    struct Database *database = malloc(sizeof(struct Database));
//    TOFREEX
    database->matches = calloc(SIZE, sizeof(struct Match *));
//    TOFREEX
    database->players = calloc(SIZE, sizeof(struct Player *));
//    TOFREEX
    database->games = calloc(SIZE, sizeof(struct Game *));
//    TOFREEX
    database->addMatch = &addMatch;
    database->addGame = &addGame;
    database->addPlayer = &addPlayer;
    database->next_match_i = 0;
    database->next_game_i = 0;
    database->next_AI_i = 0;
    database->next_player_i = 0;
    return database;
}

//TODOX implement add methods
int addMatch(struct Database *this, struct Match *match) {
    this->matches[this->next_match_i++] = match;
    return SUCCESS;
}

int addPlayer(struct Database *this, struct Player *player) {
    this->players[this->next_player_i++] = player;
    return SUCCESS;
}

int addGame(struct Database *this, struct Game *game) {
    this->games[this->next_game_i++] = game;
    return SUCCESS;
}

int free_database(struct Database *database) {
    struct ArrayList *memory_which_has_been_free = ArrayListInit();
    for (int i = 0; i < database->next_match_i; ++i) {
        free_match(database->matches[i], memory_which_has_been_free);
    }
    for (int i = 0; i < database->next_game_i; ++i) {
        free_game(database->games[i], memory_which_has_been_free);
    }
    for (int i = 0; i < database->next_player_i; ++i) {
        free_player(database->players[i], memory_which_has_been_free);
    }
    free(database->matches);
    free(database->games);
    free(database->players);
    free(database);
    al_free(memory_which_has_been_free);
    return SUCCESS;
}