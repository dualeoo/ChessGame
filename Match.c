#include <stdlib.h>
#include "Match.h"
#include "Helper.h"


struct Match *MatchIni(struct Game *game, struct Player *player) {
    struct Match *match = malloc(sizeof(struct Match *));
//    TOFREEX
    match->game = game;
    match->player = player;
    return match;
}

int free_match(struct Match *match, struct ArrayList *memory_which_has_been_free) {
    char contain = 0;
    memory_which_has_been_free->al_search(memory_which_has_been_free, match, &contain);
    if (!contain) {
        free_game(match->game, memory_which_has_been_free);
        free_player(match->player, memory_which_has_been_free);
        free(match);
    }
    return SUCCESS;
}


