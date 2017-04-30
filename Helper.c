//
// Created by dualeoo on 30/4/17.
//

#include <stdio.h>
#include "Helper.h"

char is_database_create = 0;

int player_mode(struct Database *database, struct Match *match, struct Player *player_second) {
    printf("\nDoes your friend have an account? [y] for yes and [n] for no: ");
    char answer[2] = {0};
//    TODO: handle exception + what is the best way to scan character?
    scanf("%1s", answer);

    if (answer[0] == 'y') {

    } else if (answer[0] == 'n') {
        sign_up(database, &player_second);
        database->addMatch(database, MatchIni(match->game, player_second));
        printf("\nGreat! Let's start the game!\n");
        match->game->print_board_fp(match->game);

    } else {
//    TODO handle exception
    }
    return 0;
}

int AI_mode() {
    return 0;
}

int sign_in(struct Database *database, struct Player **player_p) {
    return 0;
}

int sign_up(struct Database *database, struct Player **player_p) {
    printf("\nPlease enter your name: ");
    char name[21] = {0};
//    TODO: handle case name is greater than 20 characters and other possible exception
    scanf("%s", name);
//    scanf("%c");

    printf("\nWhat is your gender? [m] for male and [f] for female: ");
//    TODO: handle exception
    char sex[2] = {0};
    scanf("%s", sex);

    struct Player *player = PlayerIni(StringIni(name), sex[0]);
    database->addPlayer(database, player);
    *player_p = player;

    return 0;
}

int create_game(struct Database *database, struct Player *player_main, struct Player *player_second) {
    struct Game *game = GameIni();
    database->addGame(database, game);
    struct Match *match = MatchIni(game, player_main);
    database->addMatch(database, match);

    printf("\nPlease select player mode! [0] for player-player and [1] for player-AI: ");
    int scan_result = 0;
    scanf("%d", &scan_result);
//    TODO: handle exception
    if (scan_result == 0) player_mode(database, match, player_second);
    else AI_mode();

    return 0;
}

int load_game(struct Database *database, struct Player *player) {
    return 0;
}