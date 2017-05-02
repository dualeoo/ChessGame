//
// Created by dualeoo on 30/4/17.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Helper.h"
#include "Board.h"

//char is_database_create = 0;

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
        playing(database, match);

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

int playing(struct Database *database, struct Match *match) {
    do {
        printf("\nPlayer %d's turn! Enter your move: ", match->game->turn % 2 == 0 ? 1 : 2);
        char choice[3] = {0};
        scanf("%s", choice);
//    TODO: handle exception
//    Valid options: :s, :q, :l, :n, [A-H1-8]
        analyze_choice(choice, database, match);
    } while (!match->game->found_winner);
    return 0;
}

int analyze_choice(char *choice, struct Database *database, struct Match *match) {
    if (strcmp(choice, ":s") == 0) save_game();
    else if (strcmp(choice, ":l") == 0) load_game(database, match->player);
    else if (strcmp(choice, ":q") == 0) quit_game();
    else if (strcmp(choice, ":n") == 0) new_game();
    else {
        printf("\nWhere do you want to place the piece? ");
        char dst[3] = {0};
        scanf("%s", dst);
//        TODO: Handle exception
        int i = 0, j = 0, m = 0, n = 0;
        row_id(choice, &i);
        col_id(choice, &j);
        row_id(dst, &m);
        col_id(dst, &n);
        int legal = match->game->check_legal_fp(match->game, i, j, m, n, match->game->turn % 2 + 1);
        if (legal) {
            match->game->board->board[m][n] = match->game->board->board[i][j];
            match->game->board->board[i][j] = 0;
            match->game->print_board_fp(match->game);
            match->game->turn++;
        } else {
            printf("\nYour move is illegal. Please try it again!\n");
        }
    }
    return 0;
}

int save_game() {
    return 0;
}

int quit_game() {
    return 0;
}

int new_game() {
    return 0;
}

int row_id(char *choice, int *row) {
    *row = 8 - atoi(choice + 1);
    return 0;
}

int col_id(char *choice, int *col) {
//    char* exp = "ABCDEFGH";
    *col = choice[0] - 'A';
    return 0;
}
