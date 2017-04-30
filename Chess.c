//
// Created by Pham Anh Tuan on 4/5/17.
//

#include <stdio.h>
#include <stdlib.h>
#include "ChessConfig.h"
#include "Helper.h"

int main(int argc, char *argv[])
{
//    new_game_set();
//    print_board();
    printf("Welcome to Chess Version %d.%d\n",
           Chess_VERSION_MAJOR,
           Chess_VERSION_MINOR);

    struct Database *database = DatabaseIni();
//    TOFREE
    struct Player *player_main = malloc(sizeof(struct Player *));
    struct Player *player_second = malloc(sizeof(struct Player *));

    int scan_result = 0;
    printf("\nPlease sign-in or create an account! [0] to sign-in and [1] to create an account: ");
    scanf("%d", &scan_result);
    if (scan_result == 0) sign_in(database, &player_main);
    else sign_up(database, &player_main);

    printf("\nDo you want to create new game or load saved game? [0] create new game; [1] load saved game: ");
    scanf("%d", &scan_result);
    if (scan_result == 0) create_game(database, player_main, player_second);
    else load_game(database, player_main);


    return 0;
}