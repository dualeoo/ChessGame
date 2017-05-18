#define BUFFER_SIZE 256

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Helper.h"

//char is_database_create = 0;


int player_mode(struct Database *database, struct Match *match) {
    printf("\nDoes your friend have an account? [y] for yes and [n] for no: ");
    char answer[BUFFER_SIZE] = {0};
//    TODOX: handle exception + what is the best way to scan character?

    char valid_input = 0;
    do {
        scanf("%s", answer);
        if (answer[0] == 'y') {
            valid_input = 1;
            printf("\nThis feature is currently not support. Assuming your friend does not have an account!\n");
        } else if (answer[0] == 'n') {
            valid_input = 1;
        }
    } while (!valid_input);
    friend_does_not_have_account(database, match);
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
    srand((unsigned) time(NULL));
//    srand(0);
//    int result;
    main_loop(database, match, player_second, 1);
    return SUCCESS;
}

int sign_in(struct Database *database, struct Player **player_p) {
    printf("\nSign in is not supported for the time being. Fallback to sign-up!\n");
    sign_up(database, player_p);
    return SUCCESS;
}

int sign_up(struct Database *database, struct Player **player_p) {
    printf("\nPlease enter your name: ");
    char name[21] = {0};
    scanf("%s", name);
//    scanf("%c");

    printf("\nWhat is your gender? [m] for male and [f] for female: ");
    char sex[2] = {0};
    scanf("%1s", sex);

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
    char valid_input = 0;
    int num_var_filled = 0;
    getchar();
    do {
        printf("\nPlease select player mode! [0] for player-player and [1] for player-AI: ");
        int scan_result = 0x7fffffff;
        char line[BUFFER_SIZE] = {0};

        fgets(line, BUFFER_SIZE, stdin);
        num_var_filled = sscanf(line, "%d", &scan_result);
        if (num_var_filled) {
            if (scan_result == 0) {
                valid_input = 1;
                player_mode(database, match);
            } else if (scan_result == 1) {
                valid_input = 1;
                AI_mode(database, match);
            } else {
                printf("\nInvalid input! Must be 0 or 1!\n");
            }
        } else {
            printf("\nInvalid input! Must be an integer!\n");
        }
//    TODOX: handle exception: int other than 0 and 1, char, string
    } while (!valid_input || !num_var_filled);

    return SUCCESS;
}

int load_game(struct Database *database, struct Player *player) {
    printf("\nLoad game is not supported for the time being. Fallback to new game!\n");
    create_game(database, player);
    return STOP_GAME;
}

int analyze_choice(char *choice, struct Database *database, struct Match *match) {
//    The field is where the checking result is saved to
    char isACellID = 0;
    isCell(choice, &isACellID);
    if (strcmp(choice, ":s") == 0) return save_game();
    else if (strcmp(choice, ":l") == 0) return load_game(database, match->player);
    else if (strcmp(choice, ":q") == 0) return quit_game();
    else if (strcmp(choice, ":n") == 0) return new_game(database, match->player);
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
                return SUCCESS;
            } else {
                printf("\nYour move is illegal. Please try it again!\n");
                return ILLEGAL_MOVE;
            }
        }
    }
//        TODOX: handle exception
    printf("\nInvalid input. Please enter again!\n");
    return INVALID_INPUT;

}

int save_game() {
    printf("\nSave game is not supported for the time being. Please enter something else!\n");
    return NOT_SUPPORT;
}

int quit_game() {
//    printf("\nQuit game is not supported for the time being. Please enter something else!");
    return STOP_GAME;
}

int new_game(struct Database *database, struct Player *player_main) {
    create_game(database, player_main);
    return STOP_GAME;
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

int friend_does_not_have_account(struct Database *database, struct Match *match) {
    struct Player *player_second = NULL;
    printf("\nCreating an account for your friend!\n");
    sign_up(database, &player_second);
    database->addMatch(database, MatchIni(match->game, player_second));
    printf("\nGreat! Let's start the game!\n\n");
    match->game->print_board_fp(match->game);
    main_loop(database, match, player_second, 0);
//    TODOX: free all memory allocated

    return SUCCESS;
}

int main_loop(struct Database *database, struct Match *match, struct Player *player_second, char ai_mode) {
    do {
        printf("\nPlayer %d's turn! Enter your move or :q, :n, :l, :s to quite, new, load, save respectively: ",
               match->game->turn % 2 == 0 ? 1 : 2);
        char choice[BUFFER_SIZE] = {0};
        scanf("%s", choice);
//    TODOX: handle exception
//    Valid options: :s, :q, :l, :n, [A-H1-8]
        int result = analyze_choice(choice, database, match);
        if (result == ILLEGAL_MOVE || result == NOT_SUPPORT || result == INVALID_INPUT) continue;
        if (match->game->found_winner || result == STOP_GAME) break;
        if (ai_mode) {
            printf("\nAI's turn: ");
            player_second->ai->next_move(match);
        }
    } while (!match->game->found_winner);
    return SUCCESS;
}