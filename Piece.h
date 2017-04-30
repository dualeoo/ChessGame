//
// Created by dualeoo on 30/4/17.
//

#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include "Player.h"

struct Piece {
    int x;
    int y;
    int type;
    struct Player *player;
};

struct Piece *Piece(int type, struct Player *player);

#endif //CHESS_PIECE_H
