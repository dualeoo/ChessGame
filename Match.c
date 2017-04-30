#include <stdlib.h>
#include "Match.h"

struct Match *MatchIni(struct Game *game, struct Player *player) {
    struct Match *match = malloc(sizeof(struct Match *));
    match->game = game;
    match->player = player;
    return match;
}

