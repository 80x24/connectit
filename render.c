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

SDL_Surface *load_image(char filename[])
{
	// tmp image
	SDL_Surface *tmpImage = NULL;

	// optimized image
	SDL_Surface *optimizedImage = NULL;

	// load the image
	tmpImage = IMG_Load(filename);

	if(tmpImage != NULL)
	{
		// create optimized image
		optimizedImage = SDL_DisplayFormatAlpha(tmpImage);
		// free old image
		SDL_FreeSurface(tmpImage);
	}

	return optimizedImage;
}

void draw_image(int x, int y, SDL_Surface *source, SDL_Surface *dest)
{
	// temporary rect
	SDL_Rect offset;

	// set the offsets equal to x and y
	offset.x = x;
	offset.y = y;

	/*Blit the Surface.*/
	if(SDL_BlitSurface(source, NULL, dest, &offset) == -1)
	{
		fprintf(stderr, "SDL_BlitSurface failed again ='(\n");
		exit(1);
	}
}

void render(int state)
{
	if(state == 0) {
		title();
	}
	if(state == 1) {
	    playing();
	}
	if(state == 2) {
	    win();
	}
	if(state == 3) {
	    options();
	}
	if(state == 4) {
	    sure();
    }



	// Update the screen
	if(SDL_Flip(screen) < 0)
	{
		fprintf(stderr,"Error: SDL_Flip(screen) failed\n");
		exit(4);
	}
}

void title()
{
	// what to draw during the title state
    play_rect(playLocX, playLocY);
    options_rect(optionsRectX, optionsRectY);
	// draw the background to the screen
	draw_image(0,0,background,screen);

    // draw the logo
    draw_image(205,50,logo,screen);

	// draw the play Button
	draw_image(playLocX,playLocY,play,screen);

	// draw the options Button
	draw_image(optionsRectX, optionsRectY, optionsSurface, screen);

	// draw the board
	//draw_image(75,75,board,screen);
}

void playing()
{
    // draw the background to the screen
	draw_image(0,0,background,screen);

    // draw the turn font;
    draw_image(240,25,turn,screen);

    // main menu
    main_menu_rect(mainMenuRectX, mainMenuRectY);
    draw_image(mainMenuRectX, mainMenuRectY, mainMenuSurface, screen);

	// draw the board
	draw_image(94,80,boardImg,screen);

    int i = 0;

    // yellow has to start first. I really don't know
    // why, but it just has to.

    // yellow balls are even (their value in the array is 3)
    for(i = 0; i < clicked; i+=2)
    {
        newBall[i] = yellow;
        draw_image(staticBallPosX[i],staticBallPosY[i],newBall[i],screen);
    }

    // red balls are odd (their value in the array is 7)
    for(i = 0; i < clicked; i++)
    {
        // gets the odd numbers
        if(i % 2 != 0)
        {
            newBall[i] = red;
        }
        draw_image(staticBallPosX[i],staticBallPosY[i],newBall[i],screen);
    }

    SDL_Color turnColor = {0,191,255};
    if(clicked % 2 == 0)
    {
        turn = TTF_RenderText_Blended(turnFont, "Player 1's Turn", turnColor);
    }

    if(clicked % 2 != 0)
    {
        turn = TTF_RenderText_Blended(turnFont, "Player 2's Turn", turnColor);
        /*displayed += 1;
        printf("Number of times Ai was displayed: %i\n", displayed);*/
    }

    // board rect 1
    br1.x = 94;
    br1.y = 80;
    br1.w = 64;
    br1.h = 384;
    board_rect1(br1.x, br1.y, br1.w, br1.h);

    // board rect 2
    br2.x = 158;
    br2.y = 80;
    br2.w = 64;
    br2.h = 384;
    board_rect2(br2.x, br2.y, br2.w, br2.h);

    // board rect 3
    br3.x = 222;
    br3.y = 80;
    br3.w = 64;
    br3.h = 384;
    board_rect3(br3.x, br3.y, br3.w, br3.h);

    // board rect 4
    br4.x = 286;
    br4.y = 80;
    br4.w = 64;
    br4.h = 384;
    board_rect4(br4.x, br4.y, br4.w, br4.h);

    // board rect 5
    br5.x = 350;
    br5.y = 80;
    br5.w = 64;
    br5.h = 384;
    board_rect5(br5.x, br5.y, br5.w, br5.h);

    // board rect 6
    br6.x = 414;
    br6.y = 80;
    br6.w = 64;
    br6.h = 384;
    board_rect6(br6.x, br6.y, br6.w, br6.h);

    // board rect 7
    br7.x = 478;
    br7.y = 80;
    br7.w = 64;
    br7.h = 384;
    board_rect7(br7.x, br7.y, br7.w, br7.h);

}

void win()
{

    // draw the background to the screen
	draw_image(0,0,background,screen);

    // draw the board
	draw_image(94,80,boardImg,screen);

    // win font
    SDL_Color winColor = {50,205,50};
    if(playerWon == 1)
    {
        winSurface = TTF_RenderText_Blended(winFont, "Player 1 Won", winColor);
        draw_image(212,0,winSurface,screen);
    }

    SDL_Color winColor2 = {255,0,0};
    if(playerWon == 2)
    {
        winSurface =  TTF_RenderText_Blended(winFont, "Player 2 Won", winColor2);
        draw_image(207,0,winSurface,screen);
    }

    // ------------------------------------------------------------------
    // PLAY AGAIN BUTTON
    // ------------------------------------------------------------------

    // play again
    SDL_Color againColor = {0,191,255};
    againSurface = TTF_RenderText_Blended(againFont, "PlayAgain?", againColor);
    draw_image(205,40,againSurface,screen);

    // yes
    againSurfaceYes = TTF_RenderText_Blended(againFontYes, "Yes", againColor);
    again_rect_yes(againRectYesX, againRectYesY);
    draw_image(335,40,againSurfaceYes,screen);

    // no
    againSurfaceNo = TTF_RenderText_Blended(againFontNo, "No", againColor);
    again_rect_no(againRectNoX, againRectNoY);
    draw_image(385,40,againSurfaceNo,screen);

    // yellow balls are even (their value in the array is 3)
    int i = 0;
    for(i = 0; i < clicked; i+=2)
    {
        newBall[i] = yellow;
        draw_image(staticBallPosX[i],staticBallPosY[i],newBall[i],screen);
    }

    // red balls are odd (their value in the array is 7)
    for(i = 0; i < clicked; i++)
    {
        // gets the odd numbers
        if(i % 2 != 0)
        {
            newBall[i] = red;
        }
        draw_image(staticBallPosX[i],staticBallPosY[i],newBall[i],screen);
    }
}

void options()
{
    // back button
    back_rect(backRectX, backRectY);
    // music on
    music_rect_on(musicRectOnX, musicRectOnY);
    // music off
    music_rect_off(musicRectOffX, musicRectOffY);

    // draw the background to the screen
	draw_image(0,0,background,screen);

    // back button
    draw_image(backRectX, backRectY, backSurface, screen);

    // cp logo
    draw_image(160, 375, chargedProductionsLogo, screen);

    // website
    draw_image(110, 420, websiteSurface, screen);

    // draw developed by
    draw_image(242, 320, chargedProductionsSurface, screen);

    // music
    draw_image(240,200,musicSurface, screen);

    // music on
    draw_image(musicRectOnX, musicRectOnY, musicOnSurface, screen);
    // music off
    draw_image(musicRectOffX, musicRectOffY, musicOffSurface, screen);

	// big options
	SDL_Color optionsColor = {0,0,0};
    optionsSurfaceBig = TTF_RenderText_Blended(optionsFontBig, "Options", optionsColor);
    draw_image(250, 50, optionsSurfaceBig, screen);

}

void sure()
{
    sure_rect_yes(sureRectYesX, sureRectYesY);
    sure_rect_no(sureRectNoX, sureRectNoY);
    draw_image(0,0,background, screen);
    draw_image(200, 150, sureSurface, screen);
    draw_image(sureRectYesX, sureRectYesY, sureYesSurface, screen);
    draw_image(sureRectNoX, sureRectNoY, sureNoSurface, screen);
}
