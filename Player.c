#include <stdlib.h>
#include "Player.h"

void move(int old_pos_x, int old_pos_y, int new_pos_x, int new_pos_y) {

}

void win() {

}

void save() {

}

void load() {

}

struct Player *PlayerIni(struct String *name, char sex) {
    struct Player *player = malloc(sizeof(struct Player));
    player->load = &load;
    player->move = &move;
    player->name = name;
    player->save = &save;
    player->load = &load;
    player->sex = sex;
    player->win = &win;
    return player;
}