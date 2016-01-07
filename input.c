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

void input(SDL_Event event, int mouseX, int mouseY)
{
    /*
    I would normally use a switch here so that I could capture multiple
    button inputs at the same time, but in this case I am using an if statement
    so that the user can only click once.
    */
        if(event.button.button == SDL_BUTTON_LEFT)
        {
            // play the boing sound effect
            if(state == 1)
            {

                if((mouseX > mainMenuRect.x) && (mouseX < mainMenuRect.x + mainMenuRect.w)
                && (mouseY > mainMenuRect.y) && (mouseY < mainMenuRect.y + mainMenuRect.h))
                {
                    state = 0;
                    menuClicked = 1;
                }

                if(clicked % 2 == 0 && menuClicked == 0)
                {
                    if(soundOff == false)
                    {
                        Mix_VolumeChunk(boing, 25);
                        if(Mix_PlayChannel(-1, boing, 0) < 0)
                        {
                            fprintf("Sound effect 1 play failed: %s", Mix_GetError());
                            exit(1);
                        }
                    }
                }
                if(clicked % 2 != 0)
                {
                    if(soundOff == false)
                    {
                        Mix_VolumeChunk(boing2, 25);
                        if(Mix_PlayChannel(-1, boing2, 0) < 0)
                        {
                            fprintf("Sound effect 2 play failed: %s", Mix_GetError());
                            exit(1);
                        }
                    }
                }
            }
            if(state == 1)
            {
            if((mouseX > boardRect1.x) && (mouseX < boardRect1.x + boardRect1.w)
            && (mouseY > boardRect1.y) && (mouseY < boardRect1.y + boardRect1.h))
            {
                // column 1
                get_zeros(0);
                if(numZeros >= 1)
                {
                    ballPosY = (((numZeros * 64) + 80) - 64);
                    ballPosX = boardRect1.x;
                    staticBallPosX[clicked] = ballPosX;
                    staticBallPosY[clicked] = ballPosY;
                    clicked += 1;
                    /*printf("Clicked in Input: %i\n", clicked);*/
                    update_board(numZeros,0);
                }
                else
                {
                    printf("Pick a different spot!!: Col 1\n");
                }

                //printf("BallPosX %d\n", ballPosX);
                //printf("BallPosY %d\n", ballPosY);
            }

            if((mouseX > boardRect2.x) && (mouseX < boardRect2.x + boardRect2.w)
            && (mouseY > boardRect2.y) && (mouseY < boardRect2.y + boardRect2.h))
            {
                // column 2
                get_zeros(1);
                if(numZeros >= 1)
                {
                    ballPosY = (((numZeros * 64) + 80) - 64);
                    ballPosX = boardRect2.x;
                    staticBallPosX[clicked] = ballPosX;
                    staticBallPosY[clicked] = ballPosY;
                    clicked += 1;
                    /*printf("Clicked in Input: %i\n", clicked);*/
                    update_board(numZeros, 1);
                }
                else
                {
                    printf("Pick a different spot: Col 2\n");
                }

            }

            if((mouseX > boardRect3.x) && (mouseX < boardRect3.x + boardRect3.w)
            && (mouseY > boardRect3.y) && (mouseY < boardRect3.y + boardRect3.h))
            {
                // column 3
                get_zeros(2);
                if(numZeros >= 1)
                {
                    ballPosY = (((numZeros * 64) + 80) - 64);
                    ballPosX = boardRect3.x;
                    staticBallPosX[clicked] = ballPosX;
                    staticBallPosY[clicked] = ballPosY;
                    clicked += 1;
                   /* printf("Clicked in Input: %i\n", clicked);*/
                    update_board(numZeros, 2);
                }
                else
                {
                    printf("Pick a different spot: Col 3\n");
                }
            }

            if((mouseX > boardRect4.x) && (mouseX < boardRect4.x + boardRect4.w)
            && (mouseY > boardRect4.y) && (mouseY < boardRect4.y + boardRect4.h))
            {
                // column 4
                get_zeros(3);
                if(numZeros >= 1)
                {
                    ballPosY = (((numZeros * 64) + 80) - 64);
                    ballPosX = boardRect4.x;
                    staticBallPosX[clicked] = ballPosX;
                    staticBallPosY[clicked] = ballPosY;
                    clicked += 1;
                    /*printf("Clicked in Input: %i\n", clicked);*/
                    update_board(numZeros, 3);
                }
                else
                {
                    printf("Pick a different spot: Col 4\n");
                }
            }

            if((mouseX > boardRect5.x) && (mouseX < boardRect5.x + boardRect5.w)
            && (mouseY > boardRect5.y) && (mouseY < boardRect5.y + boardRect5.h))
            {
                // column 5
                get_zeros(4);
                if(numZeros >= 1)
                {
                    ballPosY = (((numZeros * 64) + 80) - 64);
                    ballPosX = boardRect5.x;
                    staticBallPosX[clicked] = ballPosX;
                    staticBallPosY[clicked] = ballPosY;
                    clicked += 1;
                    /*printf("Clicked in Input: %i\n", clicked);*/
                    update_board(numZeros, 4);
                }
                else
                {
                    printf("Pick a different spot: Col 5\n");
                }
            }

            if((mouseX > boardRect6.x) && (mouseX < boardRect6.x + boardRect6.w)
            && (mouseY > boardRect6.y) && (mouseY < boardRect6.y + boardRect6.h))
            {
                // column 6
                get_zeros(5);
                if(numZeros >= 1)
                {
                    ballPosY = (((numZeros * 64) + 80) - 64);
                    ballPosX = boardRect6.x;
                    staticBallPosX[clicked] = ballPosX;
                    staticBallPosY[clicked] = ballPosY;
                    clicked += 1;
                    /*printf("Clicked in Input: %i\n", clicked);*/
                    update_board(numZeros, 5);
                }
                else
                {
                    printf("Pick a different spot: Col 6\n");
                }
            }

            if((mouseX > boardRect7.x) && (mouseX < boardRect7.x + boardRect7.w)
            && (mouseY > boardRect7.y) && (mouseY < boardRect7.y + boardRect7.h))
            {
                // column 7
                get_zeros(6);
                if(numZeros >= 1)
                {
                    ballPosY = (((numZeros * 64) + 80) - 64);
                    ballPosX = boardRect7.x;
                    staticBallPosX[clicked] = ballPosX;
                    staticBallPosY[clicked] = ballPosY;
                    clicked += 1;
                    /*printf("Clicked in Input: %i\n", clicked);*/
                    update_board(numZeros, 6);
                }
                else
                {
                    printf("Pick a different spot: Col 7\n");
                }
            }

            }

            if(state == 2)
            {
                if((mouseX > againRectYes.x) && (mouseX < againRectYes.x + againRectYes.w)
                && (mouseY > againRectYes.y) && (mouseY < againRectYes.y + againRectYes.h))
                {
                    state = 0;
                }

                if((mouseX > againRectNo.x) && (mouseX < againRectNo.x + againRectNo.w)
                && (mouseY > againRectNo.y) && (mouseY < againRectNo.y + againRectNo.h))
                {

                    state = 4;
                }
            }

            if(state == 0)
            {
                if((mouseX > playRect.x) && (mouseX < playRect.x + playRect.w) &&
                (mouseY > playRect.y) && (mouseY < playRect.y + playRect.h))
                {
                    //printf("Collision with rect\n")
                    state = 1;
                }

                if((mouseX > optionsRect.x) && (mouseX < optionsRect.x + optionsRect.w)
                && (mouseY > optionsRect.y) && (mouseY < optionsRect.y + optionsRect.h))
                {
                    // go to the options menu
                    //printf("Collision with options rect\n");
                    state = 3;
                }

                // need this to re initialize everything
                ballPosX = -94;
                ballPosY = -64;
                clicked = 0;
                delayCount = 0;
                playedWinSound = 0;
                menuClicked = 0;

                // zero out the board
                int i,j;
                for(i = 0; i < 6; i++)
                {
                    for(j = 0; j < 7; j++)
                    {
                        board[i][j] = 0;
                    }
                }

            }

            if(state == 3)
            {
                // --- Options Page -----

                // back button
                if((mouseX > backRect.x) && (mouseX < backRect.x + backRect.w)
                && (mouseY > backRect.y) && (mouseY < backRect.y + backRect.h))
                {
                    // go to the options menu
                    //printf("Collision with options rect\n");
                    state = 0;
                }

                // music on button
                if((mouseX > musicRectOn.x) && (mouseX < musicRectOn.x + musicRectOn.w)
                && (mouseY > musicRectOn.y) && (mouseY < musicRectOn.y + musicRectOn.h))
                {
                    /*printf("Collision with music on rect\n");*/
                    soundOff = false;
                    Mix_ResumeMusic();
                }

                // music on button
                if((mouseX > musicRectOff.x) && (mouseX < musicRectOff.x + musicRectOff.w)
                && (mouseY > musicRectOff.y) && (mouseY < musicRectOff.y + musicRectOff.h))
                {
                    /*printf("Collision with music off rect\n");*/
                    soundOff = true;
                    Mix_PauseMusic();
                }

            }

            if(state == 4)
            {
                // yes
                if((mouseX > sureRectYes.x) && (mouseX < sureRectYes.x + sureRectYes.w)
                && (mouseY > sureRectYes.y) && (mouseY < sureRectYes.y + sureRectYes.h))
                {
                    /*printf("Collision with sure yes rect\n");*/
                    running = false;
                }

                // no
                if((mouseX > sureRectNo.x) && (mouseX < sureRectNo.x + sureRectNo.w)
                && (mouseY > sureRectNo.y) && (mouseY < sureRectNo.y + sureRectNo.h))
                {
                    /*printf("Collision with sure no rect\n");*/
                    state = 2;
                    playedWinSound = 1;
                }
            }

            /* ---Print Mouse Location For Debuging----
            printf("Mouse X location: %d\n", mouseX);
            printf("Mouse Y location: %d\n", mouseY);
            */
        }
}

void get_zeros(int colNumber)
{
    int row;
    numZeros = 0;
    for(row = 0; row < 6; row++)
    {
        if(board[row][colNumber] == 0)
        {
            numZeros += 1;
        }
    }

    return numZeros;
}

void update_board(int numZeros, int col)
{
    if(clicked % 2 == 0)
    {
        // player 2 is 7
        board[numZeros - 1][col] = 7;
    }
    else
    {
        board[numZeros - 1][col] = 3;
    }
}
