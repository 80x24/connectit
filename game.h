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
#ifndef GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

/*
  __    __    _    _   _    _   ____    __   _____     _   _____   _
 / _|  /  \  |  \ | | |  \ | | |____|  / _| |_____|   | | |_____| | |
/ /   / /\ \ | | \| | | | \| | |___   / /     | |     | |   | |   |_|
\ \_  \ \/ / | |\ \ | | |\ \ | |____  \ \_    | |     | |   | |    _
 \__|  \__/  |_| \__| |_| \__| |____|  \__|   |_|     |_|   |_|   |_|

*/



/*
 --- A Note About the Code ---
This game was thrown together rather quickly and uses some "quick and dirty"
tactics to get the job done. The code is by no means perfect, and there are
probably many bad programming "habits". As with anything I am sure there are
plenty of modifications that can be made to the code. Feel free to modify/change
and optimize as you would like, but just remember to comply with the GPL version
3.0. If you have any comments, concerns, or do anything interesting with this
game let me know. My email is admin@mopiz.com
*/


typedef enum {
	true = 1,
	false = 0
}bool;

// board array
// board[row][col]
int board[6][7];

// main.c
void clean_up();
int start;
int finish;
bool running;
int again;
int playedWinSound;

// checkmatch.c
int row, col;
void checkmatch();
int playerWon;


// render.c
SDL_Surface *load_image(char filename[]);
void draw_image(int x, int y, SDL_Surface *source, SDL_Surface *dest);
void render();
void title();
void playing();
void win();
void options();
void sure();
int delayCount;
int displayed;
bool soundOff;


// init.c
bool init();
bool load_assets();
bool render_fonts();

// input.c
void input(SDL_Event event, int mouseX, int mouseY);
void get_zeros(int colNumber);
void update_board(int numZeros, int col);
int numZeros;
int clicked;
int menuClicked;

// position of the ball
int ballPosX;
int ballPosY;
int staticBallPosX[50];
int staticBallPosY[50];

// rect.c
void play_rect(int rectLocX, int rectLocY);
void again_rect_yes(int rectLocX, int rectLocY);
void again_rect_no(int rectLocX, int rectLocY);
void options_rect(int rectLocX, int rectLocY);
void back_rect(int rectLocX, int rectLocY);
void music_rect_off(int rectLocX, int rectLocY);
void music_rect_on(int rectLocX, int rectLocY);
void sure_rect_yes(int rectLocX, int rectLocY);
void sure_rect_no(int rectLocX, int rectLocY);
void main_menu_rect(int rectLocX, int rectLocY);

//sound.c
bool load_sounds();

// background music
Mix_Music *bgMusic;
// sound effect
Mix_Chunk *boing;
Mix_Chunk *boing2;
Mix_Chunk *winSound;

// Set up the screen surfaces
// This part is a mess
SDL_Surface *screen;
SDL_Surface *background;
SDL_Surface *boardImg;
SDL_Surface *play;
SDL_Surface *logo;
SDL_Surface *turn;
SDL_Surface *red;
SDL_Surface *yellow;
SDL_Surface *newBall[50];
SDL_Surface *icon;
SDL_Surface *winSurface;
SDL_Surface *againSurface;
SDL_Surface *againSurfaceYes;
SDL_Surface *againSurfaceNo;
SDL_Surface *optionsSurface;
SDL_Surface *optionsSurfaceBig;
SDL_Surface *backSurface;
SDL_Surface *musicSurface;
SDL_Surface *musicOnSurface;
SDL_Surface *musicOffSurface;
SDL_Surface *chargedProductionsSurface;
SDL_Surface *websiteSurface;
SDL_Surface *chargedProductionsLogo;
SDL_Surface *sureSurface;
SDL_Surface *sureYesSurface;
SDL_Surface *sureNoSurface;
SDL_Surface *mainMenuSurface;

//SDL_Surface *testSurface[50];

// Set up fonts
TTF_Font *playFont;
TTF_Font *logoFont;
TTF_Font *turnFont;
TTF_Font *winFont;
TTF_Font *againFont;
TTF_Font *againFontYes;
TTF_Font *againFontNo;
TTF_Font *optionsFont;
TTF_Font *optionsFontBig;
TTF_Font *backFont;
TTF_Font *musicFont;
TTF_Font *musicOnFont;
TTF_Font *musicOffFont;
TTF_Font *chargedProductionsFont;
TTF_Font *websiteFont;
TTF_Font *sureFont;
TTF_Font *sureYesFont;
TTF_Font *sureNoFont;
TTF_Font *mainMenuFont;

// ========= DECLARE RECTS ====================

// play rect
SDL_Rect playRect;
int playLocX;
int playLocY;

// ---- Play Again Rects ---

// yes
SDL_Rect againRectYes;
int againRectYesX;
int againRectYesY;

// no
SDL_Rect againRectNo;
int againRectNoX;
int againRectNoY;

// Options
SDL_Rect optionsRect;
int optionsRectX;
int optionsRectY;

// back button
SDL_Rect backRect;
int backRectX;
int backRectY;

// music on rect
SDL_Rect musicRectOn;
int musicRectOnX;
int musicRectOnY;

// music off rect
SDL_Rect musicRectOff;
int musicRectOffX;
int musicRectOffY;

// sure yes
SDL_Rect sureRectYes;
int sureRectYesX;
int sureRectYesY;

// sure no
SDL_Rect sureRectNo;
int sureRectNoX;
int sureRectNoY;

// main menu rect
SDL_Rect mainMenuRect;
int mainMenuRectX;
int mainMenuRectY;


// --------- BOARD Rects -----------------------------
// rects are the coloumns starting from left to right
SDL_Rect boardRect1;
typedef struct
{
    int x;
    int y;
    int w;
    int h;
}br1Loc;
br1Loc br1;

SDL_Rect boardRect2;
typedef struct
{
    int x;
    int y;
    int w;
    int h;
}br2Loc;
br2Loc br2;

SDL_Rect boardRect3;
typedef struct
{
    int x;
    int y;
    int w;
    int h;
}br3Loc;
br3Loc br3;

SDL_Rect boardRect4;
typedef struct
{
    int x;
    int y;
    int w;
    int h;
}br4Loc;
br4Loc br4;

SDL_Rect boardRect5;
typedef struct
{
    int x;
    int y;
    int w;
    int h;
}br5Loc;
br5Loc br5;

SDL_Rect boardRect6;
typedef struct
{
    int x;
    int y;
    int w;
    int h;
}br6Loc;
br6Loc br6;

SDL_Rect boardRect7;
typedef struct
{
    int x;
    int y;
    int w;
    int h;
}br7Loc;
br7Loc br7;

// ---------------------------------------------------
/*
State machine
0 = title screen
1 = playing
2 = game over
3 = options screen
4 = confirm quit
*/

int state;

#endif
