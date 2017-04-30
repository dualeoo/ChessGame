//
// Created by dualeoo on 30/4/17.
//
struct AI {
    struct Player player;

    void (*next_move)() = &next_move;
};

void next_move() {

}