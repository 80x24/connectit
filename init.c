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

bool init()
{
	// Initialize SDL
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		fprintf(stderr, "SDL initialization failed\n");
		return false;
	}

    // initialize SDL_image
    if(IMG_Init(NULL) < 0)
    {
        fprintf(stderr, "SDL Image initialization fauled\n");
        return false;
    }

	// initialize SDL_TTF
	if(TTF_Init() < 0)
	{
		fprintf(stderr, "SDL TTF initialization failed\n");
		return false;
	}

	// initialize SDL_Mixer
	/*
	if(Mix_Init() < 0)
	{
	    fprintf("SDL Mixer initialization for mp3 files failed\n");
	    return false;
	}*/
    // the 22050 is the sound frequency
	// the 1 is mono 2 is sterio
	if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 1, 4096) < 0)
	{
	    fprintf(stderr, "SDL Mixer initialization failed\n");
	    return false;
	}

	// screen
	screen = SDL_SetVideoMode(640,480,32,SDL_HWSURFACE);

	// window caption
	SDL_WM_SetCaption("Connect It!", NULL);

    // Window icon is located in main.c


	// error for screen
	if(screen == NULL)
	{
		fprintf(stderr, "Error: screen initialization failed\n");
		return false;
	}


	// return true if no errors
	return true;
}

bool load_assets()
{
	// ======================= LOAD IMAGES ============================

	// graph paper background
	background = load_image("assets/images/graph-paper-640-480.png");
	if(background == NULL)
	{
		fprintf(stderr, "Error: background image not loaded\n");
		return false;
	}

    // board image
	boardImg = load_image("assets/images/board.png");
	if(board == NULL)
	{
		fprintf(stderr, "Error: board could not be loaded\n");
		return false;
	}

	// red ball
	red = load_image("assets/images/red.png");
	if(red == NULL)
	{
	    fprintf(stderr,"Error: Red ball loading failed\n");
	    return false;
	}

	// yellow ball
	yellow = load_image("assets/images/yellow.png");
	if(yellow == NULL)
	{
	    fprintf(stderr, "Error: Yellow ball loading failed\n");
	    return false;
	}

	// icon
	icon = load_image("assets/images/red.png");
	if(icon == NULL)
	{
	    fprintf(stderr, "Error: Window icon could not be loaded\n");
	    return false;
	}

	// Charged Productions Logo
	chargedProductionsLogo = load_image("assets/images/cp-logo.png");
	if(chargedProductionsLogo == NULL)
	{
	    fprintf(stderr, "Error: Charged Productions Logo failed to load");
	    return false;
	}

	// ======================== LOAD FONTS =============================

	// play button
	playFont = TTF_OpenFont("assets/fonts/GreasySpoonNF.ttf", 30);
	if(playFont == NULL)
	{
		fprintf(stderr, "Error: Play button font loading failed\n");
		return false;
	}

    // small option
	optionsFont = TTF_OpenFont("assets/fonts/GreasySpoonNF.ttf", 30);
	if(optionsFont == NULL)
	{
	    fprintf(stderr, "Error: options font could not be loaded\n");
	    return false;
	}

	// big option font
	optionsFontBig = TTF_OpenFont("assets/fonts/GreasySpoonNF.ttf", 50);
	if(optionsFontBig == NULL)
	{
	    fprintf(stderr, "Error: options font could not be loaded\n");
	    return false;
	}

	// back button
	backFont = TTF_OpenFont("assets/fonts/GreasySpoonNF.ttf", 30);
	if(backFont == NULL)
	{
	    fprintf(stderr, "Error: Back font could not be loaded\n");
	    return false;
	}

	// music option font
	musicFont = TTF_OpenFont("assets/fonts/GreasySpoonNF.ttf", 30);
	if(musicFont == NULL)
	{
	    fprintf(stderr, "Error: music font could not be loaded\n");
	    return false;
	}

	// music on
	musicOnFont = TTF_OpenFont("assets/fonts/GreasySpoonNF.ttf", 30);
	if(musicOnFont == NULL)
	{
	    fprintf(stderr, "Error: music on font could not be loaded\n");
	    return false;
	}

	// music off
	musicOffFont = TTF_OpenFont("assets/fonts/GreasySpoonNF.ttf", 30);
	if(musicOffFont == NULL)
	{
	    fprintf(stderr, "Error: music off font could not be loaded\n");
	    return false;
	}

	// logo
	logoFont = TTF_OpenFont("assets/fonts/orbitron-black.otf", 40);
	if(logoFont == NULL)
	{
	    fprintf(stderr, "Error: Logo font loading failed\n");
	    return false;
	}

	// developed by font
	chargedProductionsFont = TTF_OpenFont("assets/fonts/LindenHill.otf", 30);
	if(chargedProductionsFont == NULL)
	{
	    fprintf(stderr, "Error: Developed by font loading failed\n");
	    return false;
	}

	// website font
	websiteFont = TTF_OpenFont("assets/fonts/LindenHill.otf", 28);
	if(websiteFont == NULL)
	{
	    fprintf(stderr, "Error: website font could not be loaded\n");
	    return false;
	}

	// Are you sure you want to quit font
	sureFont = TTF_OpenFont("assets/fonts/LindenHill.otf", 24);
	if(sureFont == NULL)
	{
	    fprintf(stderr, "Error: sure font could not be loaded\n");
	    return false;
	}

    // yes
	sureYesFont = TTF_OpenFont("assets/fonts/LindenHill.otf", 28);
	if(sureYesFont == NULL)
	{
	    fprintf(stderr, "Error: sure yes font could not be loaded\n");
	    return false;
	}
    //no
	sureNoFont = TTF_OpenFont("assets/fonts/LindenHill.otf", 28);
	if(sureNoFont == NULL)
	{
	    fprintf(stderr, "Error: sure no font could not be loaded\n");
	    return false;
	}

	// turn
	turnFont = TTF_OpenFont("assets/fonts/LindenHill.otf", 28);
	if(turnFont == NULL)
	{
	    fprintf(stderr, "Error: Turn font loading failed\n");
	    return false;
	}

	// win
	winFont = TTF_OpenFont("assets/fonts/LindenHill.otf", 40);
	if(winFont == NULL)
	{
	    fprintf(stderr, "Error: Win font could  not be loaded\n");
	    return false;
	}

	// again font
	againFont = TTF_OpenFont("assets/fonts/LindenHill.otf", 28);
	if(againFont == NULL)
	{
	    fprintf(stderr, "Error: Play Again font could not be loaded\n");
	    return false;
	}

	// again yes font
	againFontYes = TTF_OpenFont("assets/fonts/LindenHill.otf", 28);
	if(againFontYes == NULL)
	{
	    fprintf(stderr, "Error: againFontYes could not be loaded\n");
	    return false;
	}

	// again no font
	againFontNo = TTF_OpenFont("assets/fonts/LindenHill.otf", 28);
	if(againFontNo == NULL)
	{
	    fprintf(stderr, "Error: againFontNo could not be loaded\n");
	    return false;
	}

	// main menu font
	mainMenuFont = TTF_OpenFont("assets/fonts/GreasySpoonNF.ttf", 28);
	if(mainMenuFont == NULL)
	{
	    fprintf(stderr, "Error: main menu font loading failed\n");
	    return false;
	}

	// ====== Load Sounds
	if(load_sounds() != true)
	{
	    fprintf(stderr, "Sound loading failed\n");
	    return false;
	}


}



bool render_fonts()
{
	// -------- Render Fonts -------------
	// These fonts are static and aren't going to change

	// play button
	SDL_Color playColor = {0,0,0};
	play = TTF_RenderText_Blended(playFont, "Play", playColor);
	if(play == NULL)
	{
		fprintf(stderr,"Error: Logo Font rendering failed\n");
		return false;
	}

	// options button
	SDL_Color optionsColor = {0,0,0};
	optionsSurface = TTF_RenderText_Blended(optionsFont, "Options", optionsColor);
	if(optionsSurface == NULL)
	{
	    fprintf(stderr, "Error: Options font rendering fialed\n");
	    return false;
	}

	// music font
	SDL_Color musicColor = {0,0,0};
	musicSurface = TTF_RenderText_Blended(musicFont, "Music:", musicColor);
	if(musicSurface == NULL)
	{
	    fprintf(stderr, "Error: music font rendering failed\n");
	    return false;
	}

	// music on
	musicOnSurface = TTF_RenderText_Blended(musicOnFont, "On", musicColor);
	if(musicOnSurface == NULL)
	{
	    fprintf(stderr, "Error: music font on rendering failed\n");
	    return false;
	}

	// music off
	musicOffSurface = TTF_RenderText_Blended(musicOffFont, "Off", musicColor);
	if(musicOffSurface == NULL)
	{
	    fprintf(stderr, "Error: music font off rendering failed\n");
	    return false;
	}

	// Charged Productions Font
	SDL_Color cpColor = {0,0,0};
	chargedProductionsSurface = TTF_RenderText_Blended(chargedProductionsFont, "Developed By", cpColor);
	if(chargedProductionsSurface == NULL)
	{
	    fprintf(stderr, "Error: Charged Productions font rendering failed\n");
	    return false;
	}

	// website font
	SDL_Color webColor = {0,0,0};
	websiteSurface = TTF_RenderText_Blended(websiteFont, "Need Help? chargedproductions.com/help", webColor);
	if(websiteSurface == NULL)
	{
	    fprintf(stderr, "Error: website font rendering fialed");
	    return false;
	}


	// back button
	SDL_Color backColor = {255,0,0};
	backSurface = TTF_RenderText_Blended(backFont, "Back", backColor);
	if(backSurface == NULL)
	{
	    fprintf(stderr, "Error: back surface rendering failed\n");
	    return false;
	}

	// logo
	SDL_Color logoColor =  {255,0,0};
	logo = TTF_RenderText_Solid(logoFont, "Connect It!", logoColor);
	if(logo == NULL)
	{
	    fprintf(stderr, "Error: Logo Rendering failed\n");
	    return false;
	}

	// turn
	SDL_Color turnColor = {0,191,255}; //nice aqua color
	turn = TTF_RenderText_Blended(turnFont, "Player 1's Turn", turnColor);
	if(turn == NULL)
	{
	    fprintf(stderr, "Error: Turn font rendering failed\n");
	    return false;
	}

	// Are you sure you want to quit
	SDL_Color sureColor = {0,0,0};
	sureSurface = TTF_RenderText_Blended(sureFont, "Are you sure you want to quit", sureColor);
	if(sureSurface == NULL)
	{
	    fprintf(stderr, "Error: Sure surface rendering failed\n");
	    return false;
	}

	sureYesSurface = TTF_RenderText_Blended(sureYesFont, "Yes", sureColor);
	if(sureYesSurface == NULL)
	{
	    fprintf(stderr, "Error: sure yes font rendering failed\n");
	    return false;
	}

	sureNoSurface = TTF_RenderText_Blended(sureNoFont, "No", sureColor);
	if(sureNoSurface == NULL)
	{
	    fprintf(stderr, "Error: sure no font rendering failed\n");
	    return false;
	}

	// main menu
	SDL_Color menuColor = {255,0,0};
	mainMenuSurface = TTF_RenderText_Blended(mainMenuFont, "Main Menu", menuColor);
    if(mainMenuSurface == NULL)
    {
        fprintf(stderr, "Error: main menu font rendering failed\n");
        return false;
    }
    // everything went ok
	return true;
}

