#include <stdlib.h>
#include "Player.h"


struct Player *PlayerIni(struct String *name, char sex) {
    struct Player *player = malloc(sizeof(struct Player));

    player->name = name;

    player->sex = sex;

    player->ai = NULL;
    return player;
}

//struct Player *PlayerAIIni(struct String *name, char sex, struct AI * ai){
//    struct Player *player = malloc(sizeof(struct Player));
//    player->load = &load;
//    player->move = &move;
//    player->name = name;
//    player->save = &save;
//    player->load = &load;
//    player->sex = sex;
//    player->win = &win;
//    player->ai = ai;
//    return player;
//}