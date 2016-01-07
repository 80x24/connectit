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

int main(int argc, char *argv[])
{
    // --- Random Vars ----
	state = 0;
	playedWinSound = 0;
    running = true;
    ballPosX = -94;
    ballPosY = -64;
    clicked = 0;
    delayCount = 0;
    srand(time(NULL));
    soundOff = false;

    // Delete these
    int transitionStartTime = 0;
    int tCalled = 0;

    // zero out the board
    int i,j;
    for(i = 0; i < 6; i++)
    {
        for(j = 0; j < 7; j++)
        {
            board[i][j] = 0;
        }
    }


	// Initialize
	if(init() == false)
	{
		fprintf(stderr, "Error: initialization failed\n");
		exit(2);
	}

	// load assets
	if(load_assets() == false)
	{
		fprintf(stderr, "Error: file loading failed\n");
		exit(3);
	}

	// Set the window icon
	SDL_WM_SetIcon(icon,NULL);

	// render fonts
	if(render_fonts() == false)
	{
		fprintf(stderr,"Error: Font Rendering Failed\n");
		exit(4);
	}

	// Mouse Location
	int mouseX;
	int mouseY;

    SDL_Event event;
    // fps
    const int FPS = 120;

    // ------ SET UP RECTS -----------
    againRectYesX = 335;
    againRectYesY = 40;
    againRectNoX = 385;
    againRectNoY = 40;

    // play button
    playLocX = 290;
    playLocY = 225;

    // options button
    optionsRectX = 275;
    optionsRectY = 262;

    // back button
    backRectX = 50;
    backRectY = 25;

    // music on
    musicRectOnX = 320;
    musicRectOnY = 200;

    // music off
    musicRectOffX = 360;
    musicRectOffY = 200;

    // sure yes/no
    sureRectYesX = 290;
    sureRectYesY = 200;
    sureRectNoX = 340;
    sureRectNoY = 200;

    // main menu rect
    mainMenuRectX = 15;
    mainMenuRectY = 15;


    // ========================================================
	// Main Loop
	// ========================================================
	while(running == true)
	{
	    start = SDL_GetTicks();
		render(state);
		if(Mix_PlayingMusic() == 0 && soundOff == false)
		{
            if(Mix_PlayMusic(bgMusic, 2) < 0)
            {
                fprintf(stderr, "Music playing failed: %s\n", Mix_GetError());
            }
		}

		// poll for events
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_QUIT:
					running = false;

				case SDL_KEYDOWN:
					switch(event.key.keysym.sym)
					{
						case SDLK_ESCAPE:
							running = false;
					}
				case SDL_MOUSEMOTION:
					mouseX = event.motion.x;
					mouseY = event.motion.y;
                /*
				case SDL_MOUSEBUTTONDOWN:
                    input(event, mouseX, mouseY);
                */
			}
			// The switch above has been commented out because
			// I only want to capture one mouse event at a time
			// not multiple like normal.
			if(event.type == SDL_MOUSEBUTTONDOWN)
			{
			    input(event, mouseX, mouseY);
			}
		}

		// check for win conditions
		checkmatch();

        if(state == 2 && soundOff == false)
        {
            if(playedWinSound == 0)
            {
                if(Mix_PlayChannel(-1, winSound, 0) < 0)
                {
                    fprintf(stderr, "Win sound playing: %s", Mix_GetError());
                    exit(1);
                }
                playedWinSound = 1;
            }
        }

		/*
		This delay should make the processor usage go down, as well as
		limit the frame rate to 60 FPS.
		*/
        finish = SDL_GetTicks();
		if((1000/FPS) > (finish - start))
		{
		    SDL_Delay(1000/FPS - (finish - start));
		}
	}
	clean_up();






	return 0;
}

void clean_up()
{

    // --- This function needs to be optimized ----

    // Free the music
    Mix_HaltMusic();
    Mix_FreeChunk(boing);
    Mix_FreeChunk(boing2);
    Mix_FreeChunk(winSound);
    Mix_FreeMusic(bgMusic);

	// Free surfaces
    SDL_FreeSurface(boardImg);
    SDL_FreeSurface(play);
    SDL_FreeSurface(logo);
    SDL_FreeSurface(turn);
    SDL_FreeSurface(red);
    SDL_FreeSurface(yellow);
	SDL_FreeSurface(background);
	SDL_FreeSurface(icon);
	SDL_FreeSurface(winSurface);
	SDL_FreeSurface(againSurface);
	SDL_FreeSurface(againSurfaceYes);
	SDL_FreeSurface(againSurfaceNo);
	SDL_FreeSurface(optionsSurface);
	SDL_FreeSurface(optionsSurfaceBig);
	SDL_FreeSurface(backSurface);
	SDL_FreeSurface(musicSurface);
	SDL_FreeSurface(musicOnSurface);
	SDL_FreeSurface(musicOffSurface);
	SDL_FreeSurface(chargedProductionsSurface);
	SDL_FreeSurface(websiteSurface);
	SDL_FreeSurface(chargedProductionsLogo);
	SDL_FreeSurface(sureSurface);
	SDL_FreeSurface(sureYesSurface);
	SDL_FreeSurface(sureNoSurface);
	SDL_FreeSurface(mainMenuSurface);

    // Free Fonts
    TTF_CloseFont(playFont);
    TTF_CloseFont(logoFont);
    TTF_CloseFont(turnFont);
    TTF_CloseFont(winFont);
    TTF_CloseFont(againFont);
    TTF_CloseFont(againFontYes);
    TTF_CloseFont(againFontNo);
    TTF_CloseFont(optionsFont);
    TTF_CloseFont(optionsFontBig);
    TTF_CloseFont(backFont);
    TTF_CloseFont(musicFont);
    TTF_CloseFont(musicOnFont);
    TTF_CloseFont(musicOffFont);
    TTF_CloseFont(chargedProductionsFont);
    TTF_CloseFont(websiteFont);
    TTF_CloseFont(sureFont);
    TTF_CloseFont(sureNoFont);
    TTF_CloseFont(sureYesFont);
    TTF_CloseFont(mainMenuFont);

	// main screen
	SDL_FreeSurface(screen);

	// Quit SDL
	Mix_CloseAudio();
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();

	int row = 0;
	int col = 0;

/*
    // print the board array
	for(row = 0; row < 6; row++)
	{
	    for(col = 0; col < 7; col++)
	    {
	        printf("%d", board[row][col]);
	    }
	    printf("\n");
	}
*/

}
