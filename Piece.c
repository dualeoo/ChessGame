//
// Created by dualeoo on 30/4/17.
//

#include <stdlib.h>
#include "Piece.h"

struct Piece *Piece(int type, struct Player *player) {
    struct Piece *piece = malloc(sizeof(struct Piece));
    piece->x = 0;
    piece->y = 0;
    piece->type = type;
    piece->player = player;
    return piece;
}