#include <stdlib.h>
#include "Player.h"
#include "Helper.h"



struct Player *PlayerIni(struct String *name, char sex) {
//    TOFREEX
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

int free_player(struct Player *player, struct ArrayList *memory_which_has_been_free) {
    char contain = 0;
    memory_which_has_been_free->al_search(memory_which_has_been_free, player, &contain);
    if (!contain) {
        free_string(player->name, memory_which_has_been_free);
        free_ai(player->ai, memory_which_has_been_free);
        free(player);
        memory_which_has_been_free->al_insert(memory_which_has_been_free, -1, player);
    }
    return SUCCESS;
}