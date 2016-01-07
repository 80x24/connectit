/*
    Connect It!
    Copyright (C) 2011  Kyle Schreiber

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#include "game.h"

void checkmatch()
{
    if(state == 1)
    {
    int row = 0;
    int col = 0;

    // checks for diagonal forward
    for(row = 6; row > 0; row--)
    {
        for(col = 0; col < 7; col++)
        {
            if((board[row - 1][col] + board[row - 2][col + 1] + board[row - 3][col + 2] + board[row - 4][col + 3]) == 12)
            {
                printf("Diagonal forward match: Player 1 wins!\n");
                playerWon = 1;
                state = 2;
            }
            if((board[row][col] + board[row - 1][col + 1] + board[row - 2][col + 2] + board[row - 3][col + 3]) == 28)
            {
                printf("Diagonal forward match: Player 2 wins!\n");
                playerWon = 2;
                state = 2;
            }
        }
    }


    // checks for diagonal backward

    for(row = 6; row > 0; row--)
    {
        for(col = 7; col > 0; col--)
        {
            if((board[row - 1][col - 1] + board[row - 2][col - 2] + board[row - 3][col - 3] + board[row - 4][col - 4]) == 12)
            {
                printf("Diagonal backward match: Player 1 wins!\n");
                playerWon = 1;
                state = 2;
            }
            if((board[row - 1][col - 1] + board[row - 2][col - 2] + board[row - 3][col - 3] + board[row - 4][col - 4]) == 28)
            {
                printf("Diagonal backward match: Player 2 wins!\n");
                playerWon = 2;
                state = 2;
            }
        }
    }

    // checks for vertical match

    for(row = 6; row > 0; row--)
    {
        for(col = 0; col < 7; col++)
        {
            if((board[row - 1][col] + board[row - 2][col] + board[row - 3][col] + board[row - 4][col]) == 12)
            {
                printf("Vertical match: Player 1 wins\n");
                playerWon = 1;
                state = 2;
            }

            if((board[row - 1][col] + board[row - 2][col] + board[row - 3][col] + board[row - 4][col]) == 28)
            {
                printf("Vertical match: Player 2 wins\n");
                playerWon = 2;
                state = 2;
            }

        }
    }

    // checks for horizantal match
    for(row = 6; row > 0; row --)
    {
        for(col = 0; col < 7; col++)
        {
            if((board[row - 1][col] + board[row - 1][col + 1] + board[row - 1][col + 2] + board[row - 1][col + 3]) == 12)
            {
                printf("Horizantal match: Player 1 wins\n");
                playerWon = 1;
                state = 2;
            }

            if((board[row - 1][col] + board[row - 1][col + 1] + board[row - 1][col + 2] + board[row - 1][col + 3]) == 28)
            {
                printf("Horizantal match: Player 2 wins\n");
                playerWon = 2;
                state = 2;
            }
        }
    }
    }
}
