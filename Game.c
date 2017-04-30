#include <stdlib.h>
#include <stdio.h>
#include "Game.h"
#include "Board.h"

char *names[] = {"____", "Pawn", "Knight", "Rook", "Bishop", "Queen", "King"};
char reps[] = ".pkrbqK";

int check_legal(struct Game *this, int i, int j, int m, int n, int p) {
    /** If trying to move to its own place **/
    if ((this->board->board[i][j] == 0) || ((i == m) && (j == n)))
        return 0;


    /** Looking if moving piece belong to that user or not **/
    switch (p) {
        case 1:
            if (this->board->board[i][j] % 10 != 0)
                return 0;

            break;
        case 2:
            if (this->board->board[i][j] % 10 == 0)
                return 0;

            break;
        default:
            printf("\n\n \t default legal");
    }

    int u, v;

/** Checking with RULES of the chessmen being moved  **/

    switch (this->board->board[i][j]) {
        // pawn - red - p1
        case 10:

            // checking for move into empty slot.
            if ((i + 1) == m && (j == n) && (this->board->board[m][n] == 0))
                return 1;

            if ((i == 2) && (i + 2) == m && j == n && this->board->board[m][n] == 0 &&
                this->board->board[m + 1][n] == 0)
                return 1;

            if ((i + 1) == m && (j + 1) == n && this->board->board[m][n] % 10 != 0)
                return 1;

            if (i + 1 == m && j == n + 1 && this->board->board[m][n] % 10 != 0)
                return 1;

            else
                return 0;

            // pawn - green - p2
        case 11:
            if ((m + 1) == i && (j == n) && (this->board->board[m][n] == 0))
                return 1;

            if ((i == 7) && (m + 2) == i && j == n && this->board->board[m][n] == 0 &&
                this->board->board[m - 1][n] == 0)
                return 1;

            if ((m + 1) == i && (n + 1) == j && this->board->board[m][n] != 0 && this->board->board[m][n] % 10 == 0) {

                return 1;
            }

            if (i - 1 == m && j + 1 == n && this->board->board[m][n] % 10 == 0 && this->board->board[m][n] != 0)
                return 1;
            else
                return 0;

            // rook - both players
        case 20:
        case 22:

            // Checking if rook trying to move diagonally.
            if (i != m && j != n)
                return 0;

            /*******  vertical movement  *************/
            if (j == n) {
                // Vertically moving upwards.
                if (m > i) {
                    for (int a = i + 1; a < m; a++) {
                        // checking if path of rook is empty or not.
                        if (this->board->board[a][n] != 0) {
                            return 0;
                        }
                    }

                    // if destination is empty or its occupied by opposite player chessmen
                    if (this->board->board[m][n] == 0 || this->board->board[m][n] % 10 != 0)
                        return 1;

                }
                // Vertically moving downwards.
                if (i > m) {
                    for (int a = i - 1; a > m; a--) {
                        if (this->board->board[a][n] != 0)
                            return 0;
                    }
                    if (this->board->board[m][n] == 0 || this->board->board[m][n] % 10 != 0)
                        return 1;

                }

            }
                /*******  horizontal movement  *************/
            else {
                // rook movement towards right
                if (j < n) {
                    for (int a = j + 1; a < n; a++) {
                        // checking if path of rook is empty or not.
                        if (this->board->board[m][a] != 0) {
                            return 0;
                        }
                    }

                    if (this->board->board[m][n] == 0 || this->board->board[m][n] % 10 != 0)
                        return 1;
                }

                // rook movement towards left
                if (j > n) {
                    for (int a = j - 1; a > n; a--) {
                        if (this->board->board[m][a] != 0)
                            return 0;
                    }
                    if (this->board->board[m][n] == 0 || this->board->board[m][n] % 10 != 0)
                        return 1;

                }

            }
            break;

            // knight - red - p1
        case 30:
            if (this->board->board[m][n] == 0 || this->board->board[m][n] % 10 != 0) {
                if (i + 2 == m && j + 1 == n)
                    return 1;
                else if (i + 2 == m && j - 1 == n)
                    return 1;
                else if (i + 1 == m && j - 2 == n)
                    return 1;
                else if (i - 1 == m && j - 2 == n)
                    return 1;
                else if (i - 2 == m && j - 1 == n)
                    return 1;
                else if (i - 2 == m && j + 1 == n)
                    return 1;
                else if (i - 1 == m && j + 2 == n)
                    return 1;
                else {
                    if (i + 1 == m && j + 2 == n)
                        return 1;
                    else
                        return 0;
                }
            } else
                return 0;

            // knight - green - p2
        case 33:

            if (this->board->board[m][n] == 0 || this->board->board[m][n] % 10 == 0) {
                if (i + 2 == m && j + 1 == n)
                    return 1;
                else if (i + 2 == m && j - 1 == n)
                    return 1;
                else if (i + 1 == m && j - 2 == n)
                    return 1;
                else if (i - 1 == m && j - 2 == n)
                    return 1;
                else if (i - 2 == m && j - 1 == n)
                    return 1;
                else if (i - 2 == m && j + 1 == n)
                    return 1;
                else if (i - 1 == m && j + 2 == n)
                    return 1;
                else {
                    if (i + 1 == m && j + 2 == n)
                        return 1;
                    else
                        return 0;
                }
            } else
                return 0;


            //bishop - red - p1
        case 40:

            // cross - movement
            if ((i - m) == (j - n) || (m - i) == (j - n)) {
                if (m > i) {
                    if (n > j) {
                        u = i + 1;
                        v = j + 1;

                        // check for movement path obstacles

                        for (int r = 0; r < (m - i) - 1; r++) {
                            if (this->board->board[u++][v++] != 0)
                                return 0;
                        }

                        if (this->board->board[m][n] == 0 || this->board->board[m][n] % 10 != 0)
                            return 1;
                        else
                            return 0;

                    } else {
                        u = i + 1;
                        v = j - 1;
                        // check for movement path obstacles
                        for (int r = 0; r < (m - i) - 1; r++) {

                            if (this->board->board[u++][v--] != 0)
                                return 0;
                        }
                    }
                } else  // i>m
                {
                    if (n > j) {
                        u = i - 1;
                        v = j + 1;
                        for (int r = 0; r < (i - m) - 1; r++) {

                            if (this->board->board[u--][v++] != 0)
                                return 0;
                        }
                    } else {
                        u = i - 1;
                        v = j - 1;
                        for (int r = 0; r < (i - m) - 1; r++) {
                            if (this->board->board[u--][v--] != 0)
                                return 0;
                        }
                    }


                }

                if (this->board->board[m][n] == 0 || this->board->board[m][n] % 10 != 0)
                    return 1;
                else
                    return 0;


            } else
                return 0;

            /******* knight Green : Rules compatibility *********/
        case 44:
            if ((i - m) == (j - n) || (m - i) == (j - n)) {
                if (m > i) {
                    if (n > j) {
                        u = i + 1;
                        v = j + 1;
                        for (int r = 0; r < (m - i) - 1; r++) {
                            if (this->board->board[u++][v++] != 0)
                                return 0;
                        }
                        if (this->board->board[m][n] == 0 || this->board->board[m][n] % 10 == 0)
                            return 1;
                        else
                            return 0;

                    } else {

                        u = i + 1;
                        v = j - 1;
                        for (int r = 0; r < (m - i) - 1; r++) {

                            if (this->board->board[u++][v--] != 0)
                                return 0;
                        }
                    }
                } else  // i>m
                {
                    if (n > j) {
                        u = i - 1;
                        v = j + 1;
                        for (int r = 0; r < (i - m) - 1; r++) {

                            if (this->board->board[u--][v++] != 0)
                                return 0;
                        }
                    } else {
                        u = i - 1;
                        v = j - 1;
                        for (int r = 0; r < (i - m) - 1; r++) {
                            if (this->board->board[u--][v--] != 0)
                                return 0;
                        }
                    }


                }

                if (this->board->board[m][n] == 0 || this->board->board[m][n] % 10 == 0)
                    return 1;
                else
                    return 0;
            } else
                return 0;


        case 60:
            if (this->board->board[m][n] == 0 || this->board->board[m][n] % 10 != 0) {
                if (i + 1 == m && j + 1 == n)
                    return 1;
                else if (i + 1 == m && j == n)
                    return 1;
                else if (i + 1 == m && j - 1 == n)
                    return 1;
                else if (i == m && j - 1 == n)
                    return 1;
                else if (i - 1 == m && j - 1 == n)
                    return 1;
                else if (i - 1 == m && j == n)
                    return 1;
                else if (i - 1 == m && j + 1 == n)
                    return 1;
                else {
                    if (i == m && j + 1 == n)
                        return 1;
                    else
                        return 0;
                }
            } else
                return 0;

        case 66:
            if (this->board->board[m][n] == 0 || this->board->board[m][n] % 10 == 0) {
                if ((i + 1) == m && (j + 1) == n)
                    return 1;
                else if ((i + 1) == m && j == n)
                    return 1;
                else if ((i + 1) == m && j - 1 == n)
                    return 1;
                else if (i == m && j - 1 == n)
                    return 1;
                else if (i - 1 == m && j - 1 == n)
                    return 1;
                else if (i - 1 == m && j == n)
                    return 1;
                else if (i - 1 == m && j + 1 == n)
                    return 1;
                else {
                    if (i == m && j + 1 == n)
                        return 1;
                    else
                        return 0;
                }
            } else
                return 0;


            /******* QUEEN : Rules compatibility *********/
        case 50:
        case 55:
            // elephant red code

            if (j == n) // vertical movement
            {
                if (m > i) {
                    for (int a = i + 1; a < m; a++) {
                        if (this->board->board[a][n] != 0) {
                            return 0;
                        }
                    }

                    if (this->board->board[m][n] == 0 || this->board->board[m][n] % 10 != 0)
                        return 1;

                }
                if (i > m) {
                    for (int a = i - 1; a > m; a--) {
                        if (this->board->board[a][n] != 0)
                            return 0;
                    }
                    if (this->board->board[m][n] == 0 || this->board->board[m][n] % 10 != 0)
                        return 1;

                }

            } else  // for horizontal movement
            if (i == m) {
                if (j < n) {
                    for (int a = j + 1; a < n; a++) {
                        if (this->board->board[m][a] != 0) {
                            return 0;
                        }
                    }

                    if (this->board->board[m][n] == 0 || this->board->board[m][n] % 10 != 0)
                        return 1;

                }
                if (j > n) {
                    for (int a = j - 1; a > n; a--) {
                        if (this->board->board[m][a] != 0)
                            return 0;
                    }
                    if (this->board->board[m][n] == 0 || this->board->board[m][n] % 10 != 0)
                        return 1;

                }

            }
                // camel code
            else if ((i - m) == (j - n) || (m - i) == (j - n)) {
                if (m > i) {
                    if (n > j) {
                        u = i + 1;
                        v = j + 1;
                        for (int r = 0; r < (m - i) - 1; r++) {
                            if (this->board->board[u++][v++] != 0)
                                return 0;
                        }
                        if (this->board->board[m][n] == 0 || this->board->board[m][n] % 10 != 0)
                            return 1;
                        else
                            return 0;

                    } else {

                        u = i + 1;
                        v = j - 1;
                        for (int r = 0; r < (m - i) - 1; r++) {
                            if (this->board->board[u++][v--] != 0)
                                return 0;
                        }
                    }
                } else  // i>m
                {
                    if (n > j) {
                        u = i - 1;
                        v = j + 1;
                        for (int r = 0; r < (i - m) - 1; r++) {

                            if (this->board->board[u--][v++] != 0)
                                return 0;
                        }
                    } else {
                        u = i - 1;
                        v = j - 1;
                        for (int r = 0; r < (i - m) - 1; r++) {
                            if (this->board->board[u--][v--] != 0)
                                return 0;
                        }
                    }


                }

                if (this->board->board[m][n] == 0 || this->board->board[m][n] % 10 != 0)
                    return 1;
                else
                    return 0;
            } else
                return 0;


        default:
            return 0;
    }//switch end

    return 0;
}

int print_board(struct Game *this) {
//    int board[8][8] = this->board->board;
    for (int row = 7; row >= 0; row--) {
        for (int col = 0; col < 8; col++)
            printf("%s\t\t", names[this->board->board[row][col] / 10]);
        printf("\n");
//        fflush(stdout);
    }
    return 0;
}

struct Game *GameIni() {
    struct Game *game = malloc(sizeof(struct Game));
//    TOFREE

    game->time_elapsed = 0;
    game->board = BoardIni();
    game->check_legal_fp = &check_legal;
    game->print_board_fp = &print_board;
    return game;
};