#include <stdlib.h>
#include "AI.h"

void next_move() {


}

struct AI *AIIni(struct Player *player) {
    struct AI *ai = malloc(sizeof(struct AI));
    ai->player = player;
    ai->next_move = &next_move;
    return ai;
}
