//
// Created by Pham Anh Tuan on 4/5/17.
//

#include <stdio.h>


char *names[] = {" ","Pawn","Knight", "Rook", "Bishop","Queen","King" };
char reps[]=".pkrbqK";

/*
 * p1/p2 Pawn = 10/11
 * p1/p2 Rook = 20/22
 * p1/p2 Knight = 30/33
 * p1/p2 Bishop = 40/44
 * p1/p2 Queen = 50/55
 * p1/p2 King = 60/66
 */

int board[8][8];

void new_game_set(void) {
    int i,j;
    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
            board[i][j]=0;
    for(i=0;i<8;i++){
        board[6][i]=10;
        board[1][i]=11;
    }

    board[0][0]=board[0][7]=22;
    board[7][0]=board[7][7]=20;
    board[0][1]=board[0][6]=33;
    board[7][1]=board[7][6]=30;
    board[0][2]=board[0][5]=44;
    board[7][2]=board[7][5]=40;
    board[0][3]=55;
    board[7][3]=50;
    board[0][4]=66;
    board[7][4]=60;
};

void print_board(void)
{
    for(int row=0;row<8;row++) {
        for(int col=0;col<8;col++)
            putchar(reps[board[row][col]/10]);
        putchar('\n');
    }
}

int legal(int i,int j,int m,int n,int p)
/***
	Checks if the move is LEGAL or NOT
	 move from (i,j) to (m,n)
	 p = 1 :: RED chessMen
	 p = 2 :: GREEN chessMen
	 return 1 is legal, 0 is not legal.
***/
{

    /** If trying to move to its own place **/
    if((board[i][j]==0)||((i==m)&&(j==n)))
        return 0;


    /** Looking if moving piece belong to that user or not **/
    switch(p)
    {
        case 1: if(board[i][j]%10 != 0)
                return 0;

            break;
        case 2: if(board[i][j]%10 == 0)
                return 0;

            break;
        default: printf("\n\n \t default legal");
    }

    int u,v;

/** Checking with RULES of the chessmen being moved  **/

    switch(board[i][j])
    {
            // pawn - red - p1
        case 10:

            // checking for move into empty slot.
            if((i+1)==m&&(j==n)&&(board[m][n]==0))
                return 1;

            if((i==2) && (i+2)==m && j==n && board[m][n]==0 && board[m+1][n]==0)
                return 1;

            if((i+1)==m && (j+1)==n && board[m][n]%10!=0)
                return 1;

            if(i+1==m && j==n+1 && board[m][n]%10!=0)
                return 1;

            else
                return 0;

            // pawn - green - p2
        case 11:
            if((m+1)==i&&(j==n)&&(board[m][n]==0))
                return 1;

            if((i==7) && (m+2)==i && j==n && board[m][n]==0 && board[m-1][n]==0)
                return 1;

            if((m+1)==i && (n+1)==j && board[m][n]!=0 && board[m][n]%10 == 0)
            {

                return 1;
            }

            if(i-1==m && j+1==n && board[m][n]%10==0 && board[m][n]!=0)
                return 1;
            else
                return 0;

            // rook - both players
        case 20:
        case 22:

            // Checking if rook trying to move diagonally.
            if(i!=m && j!=n)
                return 0;

                /*******  vertical movement  *************/
            if(j==n)
            {
                // Vertically moving upwards.
                if(m>i)
                {
                    for(int a=i+1;a<m;a++)
                    {
                        // checking if path of rook is empty or not.
                        if(board[a][n]!=0)
                        {
                            return 0;
                        }
                    }

                    // if destination is empty or its occupied by opposite player chessmen
                    if(board[m][n]==0 || board[m][n]%10!=0)
                        return 1;

                }
                // Vertically moving downwards.
                if(i>m)
                {
                    for(int a=i-1;a>m;a--)
                    {
                        if(board[a][n]!=0)
                            return 0;
                    }
                    if(board[m][n]==0 || board[m][n]%10!=0)
                        return 1;

                }

            }
                /*******  horizontal movement  *************/
            else
            {
                // rook movement towards right
                if(j<n)
                {
                    for(int a=j+1;a<n;a++)
                    {
                        // checking if path of rook is empty or not.
                        if(board[m][a]!=0)
                        {
                            return 0;
                        }
                    }

                    if(board[m][n]==0 || board[m][n]%10!=0)
                        return 1;
                }

                // rook movement towards left
                if(j>n)
                {
                    for(int a=j-1;a>n;a--)
                    {
                        if(board[m][a]!=0)
                            return 0;
                    }
                    if(board[m][n]==0 || board[m][n]%10!=0)
                        return 1;

                }

            }
            break;

            // knight - red - p1
        case 30:
            if(board[m][n]==0||board[m][n]%10!=0)
            {
                if(i+2==m && j+1==n)
                    return 1;
                else
                if(i+2==m && j-1==n)
                    return 1;
                else
                if(i+1==m && j-2==n)
                    return 1;
                else
                if(i-1==m && j-2==n)
                    return 1;
                else
                if(i-2==m && j-1==n)
                    return 1;
                else
                if(i-2==m && j+1==n)
                    return 1;
                else
                if(i-1==m && j+2==n)
                    return 1;
                else
                {
                    if(i+1==m && j+2==n)
                        return 1;
                    else
                        return 0;
                }
            }
            else
                return 0;

            // knight - green - p2
        case 33:

            if(board[m][n]==0||board[m][n]%10==0)
            {
                if(i+2==m && j+1==n)
                    return 1;
                else
                if(i+2==m && j-1==n)
                    return 1;
                else
                if(i+1==m && j-2==n)
                    return 1;
                else
                if(i-1==m && j-2==n)
                    return 1;
                else
                if(i-2==m && j-1==n)
                    return 1;
                else
                if(i-2==m && j+1==n)
                    return 1;
                else
                if(i-1==m && j+2==n)
                    return 1;
                else
                {
                    if(i+1==m && j+2==n)
                        return 1;
                    else
                        return 0;
                }
            }
            else
                return 0;


            //bishop - red - p1
        case 40:

            // cross - movement
            if((i-m)==(j-n) || (m-i)==(j-n))
            {
                if(m>i)
                {
                    if(n>j)
                    {
                        u=i+1;
                        v=j+1;

                        // check for movement path obstacles

                        for(int r=0;r<(m-i)-1;r++)
                        {
                            if(board[u++][v++] != 0)
                                return 0;
                        }

                        if(board[m][n]==0 || board[m][n]%10!=0)
                            return 1;
                        else
                            return 0;

                    }
                    else
                    {
                        u=i+1;
                        v=j-1;
                        // check for movement path obstacles
                        for(int r=0;r<(m-i)-1;r++)
                        {

                            if(board[u++][v--] != 0)
                                return 0;
                        }
                    }
                }
                else  // i>m
                {
                    if(n>j)
                    {
                        u=i-1;
                        v=j+1;
                        for(int r=0;r<(i-m)-1;r++)
                        {

                            if(board[u--][v++] != 0)
                                return 0;
                        }
                    }
                    else
                    {
                        u=i-1;
                        v=j-1;
                        for(int r=0;r<(i-m)-1;r++)
                        {
                            if(board[u--][v--] != 0)
                                return 0;
                        }
                    }


                }

                if(board[m][n]==0 || board[m][n]%10!=0)
                    return 1;
                else
                    return 0;


            }
            else
                return 0;

            /******* knight Green : Rules compatibility *********/
        case 44:
            if((i-m)==(j-n) || (m-i)==(j-n))
            {
                if(m>i)
                {
                    if(n>j)
                    {
                        u=i+1;
                        v=j+1;
                        for(int r=0;r<(m-i)-1;r++)
                        {
                            if(board[u++][v++] != 0)
                                return 0;
                        }
                        if(board[m][n]==0 || board[m][n]%10==0)
                            return 1;
                        else
                            return 0;

                    }
                    else
                    {

                        u=i+1;
                        v=j-1;
                        for(int r=0;r<(m-i)-1;r++)
                        {

                            if(board[u++][v--] != 0)
                                return 0;
                        }
                    }
                }
                else  // i>m
                {
                    if(n>j)
                    {
                        u=i-1;
                        v=j+1;
                        for(int r=0;r<(i-m)-1;r++)
                        {

                            if(board[u--][v++] != 0)
                                return 0;
                        }
                    }
                    else
                    {
                        u=i-1;
                        v=j-1;
                        for(int r=0;r<(i-m)-1;r++)
                        {
                            if(board[u--][v--] != 0)
                                return 0;
                        }
                    }


                }

                if(board[m][n]==0 || board[m][n]%10==0)
                    return 1;
                else
                    return 0;
            }
            else
                return 0;


        case 60:
            if(board[m][n]==0||board[m][n]%10!=0)
            {
                if(i+1==m&&j+1==n)
                    return 1;
                else
                if(i+1==m&&j==n)
                    return 1;
                else
                if(i+1==m&&j-1==n)
                    return 1;
                else
                if(i==m&&j-1==n)
                    return 1;
                else
                if(i-1==m&&j-1==n)
                    return 1;
                else
                if(i-1==m&&j==n)
                    return 1;
                else
                if(i-1==m&&j+1==n)
                    return 1;
                else
                {
                    if(i==m&&j+1==n)
                        return 1;
                    else
                        return 0;
                }
            }
            else
                return 0;

        case 66:
            if(board[m][n]==0||board[m][n]%10==0)
            {
                if((i+1)==m&&(j+1)==n)
                    return 1;
                else
                if((i+1)==m&&j==n)
                    return 1;
                else
                if((i+1)==m&&j-1==n)
                    return 1;
                else
                if(i==m&&j-1==n)
                    return 1;
                else
                if(i-1==m&&j-1==n)
                    return 1;
                else
                if(i-1==m&&j==n)
                    return 1;
                else
                if(i-1==m&&j+1==n)
                    return 1;
                else
                {
                    if(i==m&&j+1==n)
                        return 1;
                    else
                        return 0;
                }
            }
            else
                return 0;


            /******* QUEEN : Rules compatibility *********/
        case 50:
        case 55:
            // elephant red code

            if(j==n) // vertical movement
            {
                if(m>i)
                {
                    for(int a=i+1;a<m;a++)
                    {
                        if(board[a][n]!=0)
                        {
                            return 0;
                        }
                    }

                    if(board[m][n]==0 || board[m][n]%10!=0)
                        return 1;

                }
                if(i>m)
                {
                    for(int a=i-1;a>m;a--)
                    {
                        if(board[a][n]!=0)
                            return 0;
                    }
                    if(board[m][n]==0 || board[m][n]%10!=0)
                        return 1;

                }

            }
            else  // for horizontal movement
            if(i==m)
            {
                if(j<n)
                {
                    for(int a=j+1;a<n;a++)
                    {
                        if(board[m][a]!=0)
                        {
                            return 0;
                        }
                    }

                    if(board[m][n]==0 || board[m][n]%10!=0)
                        return 1;

                }
                if(j>n)
                {
                    for(int a=j-1;a>n;a--)
                    {
                        if(board[m][a]!=0)
                            return 0;
                    }
                    if(board[m][n]==0 || board[m][n]%10!=0)
                        return 1;

                }

            }
                // camel code
            else
            if((i-m)==(j-n) || (m-i)==(j-n))
            {
                if(m>i)
                {
                    if(n>j)
                    {
                        u=i+1;
                        v=j+1;
                        for(int r=0;r<(m-i)-1;r++)
                        {
                            if(board[u++][v++] != 0)
                                return 0;
                        }
                        if(board[m][n]==0 || board[m][n]%10!=0)
                            return 1;
                        else
                            return 0;

                    }
                    else
                    {

                        u=i+1;
                        v=j-1;
                        for(int r=0;r<(m-i)-1;r++)
                        {
                            if(board[u++][v--] != 0)
                                return 0;
                        }
                    }
                }
                else  // i>m
                {
                    if(n>j)
                    {
                        u=i-1;
                        v=j+1;
                        for(int r=0;r<(i-m)-1;r++)
                        {

                            if(board[u--][v++] != 0)
                                return 0;
                        }
                    }
                    else
                    {
                        u=i-1;
                        v=j-1;
                        for(int r=0;r<(i-m)-1;r++)
                        {
                            if(board[u--][v--] != 0)
                                return 0;
                        }
                    }


                }

                if(board[m][n]==0 || board[m][n]%10!=0)
                    return 1;
                else
                    return 0;
            }
            else
                return 0;



        default: return 0;
    }//switch end

    return 0;
}  // fun end



int main(void)
{
    new_game_set();
    print_board();
    return 0;
}