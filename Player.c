//
// Created by dualeoo on 30/4/17.
//
struct Player {
    struct String name;
    struct Date date;
    char sex;
    int score;

    void (*move)(int, int, int, int) = &move;

    void (*win)() = &win;

    void (*save)() = &save;

    void (*load)() = &load;
};

void move(int old_pos_x, int old_pos_y, int new_pos_x, int new_pos_y) {

}

void win() {

}

void save() {

}

void load() {

}