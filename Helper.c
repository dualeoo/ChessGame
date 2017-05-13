//
// Created by dualeoo on 30/4/17.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Helper.h"

//char is_database_create = 0;


int player_mode(struct Database *database, struct Match *match) {
    printf("\nDoes your friend have an account? [y] for yes and [n] for no: ");
    char answer[2] = {0};
//    TODO: handle exception + what is the best way to scan character?
    scanf("%1s", answer);

    if (answer[0] == 'y') {

    } else if (answer[0] == 'n') {
        struct Player *player_second = NULL;
        sign_up(database, &player_second);
        database->addMatch(database, MatchIni(match->game, player_second));
        printf("\nGreat! Let's start the game!\n\n");
        match->game->print_board_fp(match->game);
        do {
            printf("\nPlayer %d's turn! Enter your move: ", match->game->turn % 2 == 0 ? 1 : 2);
            char choice[3] = {0};
            scanf("%s", choice);
//    TODO: handle exception
//    Valid options: :s, :q, :l, :n, [A-H1-8]
            analyze_choice(choice, database, match);
        } while (!match->game->found_winner);

    } else {
//    TODO handle exception
    }
    return SUCCESS;
}

int AI_mode(struct Database *database, struct Match *match) {
/*
 * Create an accout for AI
 * Start playing game*/
    char buffer[100] = {0};
    sprintf(buffer, "AI%03d", database->next_AI_i);
    struct Player *player_second = PlayerIni(StringIni(buffer), 'm');
    player_second->ai = AIIni();
    database->addPlayer(database, player_second);
    database->addMatch(database, MatchIni(match->game, player_second));
    printf("\nGreat! Let's start the game!\n\n");
    match->game->print_board_fp(match->game);
//    srand((unsigned) time(NULL));
    srand(0);
    int result;
    do {
        printf("\nPlayer's turn! Enter your move: ");
        char choice[3] = {0};
        scanf("%s", choice);
//    Valid options: :s, :q, :l, :n, [A-H1-8]
        result = analyze_choice(choice, database, match);
        if (result == ILLEGAL_MOVE) continue;
        if (match->game->found_winner) break;
        printf("\nAI's turn: ");
        player_second->ai->next_move(match);
//        TODOX: check if AI wins

    } while (!match->game->found_winner);

    return SUCCESS;
}

int sign_in(struct Database *database, struct Player **player_p) {
    return SUCCESS;
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

    return SUCCESS;
}

int create_game(struct Database *database, struct Player *player_main) {
    struct Game *game = GameIni();
    database->addGame(database, game);
    struct Match *match = MatchIni(game, player_main);
    database->addMatch(database, match);

    printf("\nPlease select player mode! [0] for player-player and [1] for player-AI: ");
    int scan_result = 0;
    scanf("%d", &scan_result);

    if (scan_result == 0) player_mode(database, match);
    else if (scan_result == 1) AI_mode(database, match);
    else {
//    TODO: handle exception
    }

    return SUCCESS;
}

int load_game(struct Database *database, struct Player *player) {
    return SUCCESS;
}

int analyze_choice(char *choice, struct Database *database, struct Match *match) {
    char isACellID = 0;
    isCell(choice, &isACellID);
    if (strcmp(choice, ":s") == 0) save_game();
    else if (strcmp(choice, ":l") == 0) load_game(database, match->player);
    else if (strcmp(choice, ":q") == 0) quit_game();
    else if (strcmp(choice, ":n") == 0) new_game();
    else if (isACellID) {
        printf("\nWhere do you want to place the piece? ");
        char dst[3] = {0};
        scanf("%s", dst);
        isACellID = 0;
        isCell(dst, &isACellID);
        if (isACellID) {
            int i = 0, j = 0, m = 0, n = 0;
            row_id(choice, &i);
            col_id(choice, &j);
            row_id(dst, &m);
            col_id(dst, &n);
            int legal = match->game->check_legal_fp(match->game, i, j, m, n, match->game->turn % 2 + 1);
            if (legal) {
                int previous_piece = (match->game->board->board[m][n]);
                match->game->board->board[m][n] = match->game->board->board[i][j];
                match->game->board->board[i][j] = 0;
                match->game->print_board_fp(match->game);
                if (previous_piece == 60) {
                    printf("\nPlayer 2 wins!");
                    match->game->found_winner = 1;
                } else if (previous_piece == 66) {
                    printf("\nPlayer 1 wins!");
                    match->game->found_winner = 1;
                }
                match->game->turn++;
            } else {
                printf("\nYour move is illegal. Please try it again!\n");
                return ILLEGAL_MOVE;
            }
        } else {
//        TODO: Handle exception
        }
    } else {
//        TODO handle exception
    }
    return SUCCESS;
}

int save_game() {
    return SUCCESS;
}

int quit_game() {
    return SUCCESS;
}

int new_game() {
    return SUCCESS;
}

int row_id(char *choice, int *row) {
    *row = 8 - atoi(choice + 1);
    return SUCCESS;
}

int col_id(char *choice, int *col) {
//    char* exp = "ABCDEFGH";
    *col = toupper(choice[0]) - 'A';
    return SUCCESS;
}

int isCell(char *choice, char *isACellID) {
    int col = toupper(choice[0]);
    char row = choice[1];
    char validCol = 0;
    char validRow = 0;
    if (col == 'A' || col == 'B' || col == 'C' || col == 'D' || col == 'E' || col == 'F' || col == 'G' || col == 'H')
        validCol = 1;
    if (row >= '1' && row <= '8')
        validRow = 1;
    if (validCol && validRow)
        *isACellID = 1;
    return SUCCESS;
}
