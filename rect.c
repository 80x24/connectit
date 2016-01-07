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

void play_rect(int rectLocX, int rectLocY)
{
	playRect.x = play->clip_rect.x;
	playRect.y = play->clip_rect.y;
	playRect.w = play->clip_rect.w;
	playRect.h = play->clip_rect.h;

	playRect.x = rectLocX;
	playRect.y = rectLocY;
}


void again_rect_yes(int rectLocX, int rectLocY)
{
    againRectYes.x = againSurfaceYes->clip_rect.x;
    againRectYes.y = againSurfaceYes->clip_rect.y;
    againRectYes.w = againSurfaceYes->clip_rect.w;
    againRectYes.h = againSurfaceYes->clip_rect.h;

    againRectYes.x = rectLocX;
    againRectYes.y = rectLocY;

}

void again_rect_no(int rectLocX, int rectLocY)
{
    againRectNo.x = againSurfaceNo->clip_rect.x;
    againRectNo.y = againSurfaceNo->clip_rect.y;
    againRectNo.w = againSurfaceNo->clip_rect.w;
    againRectNo.h = againSurfaceNo->clip_rect.h;

    againRectNo.x = rectLocX;
    againRectNo.y = rectLocY;

}

void options_rect(int rectLocX, int rectLocY)
{
    optionsRect.x = optionsSurface->clip_rect.x;
    optionsRect.y = optionsSurface->clip_rect.y;
    optionsRect.w = optionsSurface->clip_rect.w;
    optionsRect.h = optionsSurface->clip_rect.h;

    optionsRect.x = rectLocX;
    optionsRect.y = rectLocY;
}

// back button
void back_rect(int rectLocX, int rectLocY)
{
    backRect.x = backSurface->clip_rect.x;
    backRect.y = backSurface->clip_rect.y;
    backRect.w = backSurface->clip_rect.w;
    backRect.h = backSurface->clip_rect.h;

    backRect.x = rectLocX;
    backRect.y = rectLocY;
}

// music button on
void music_rect_on(int rectLocX, int rectLocY)
{
    musicRectOn.x = musicOnSurface->clip_rect.x;
    musicRectOn.y = musicOnSurface->clip_rect.y;
    musicRectOn.w = musicOnSurface->clip_rect.w;
    musicRectOn.h = musicOnSurface->clip_rect.h;

    musicRectOn.x = rectLocX;
    musicRectOn.y = rectLocY;
}

// music button off
void music_rect_off(int rectLocX, int rectLocY)
{
    musicRectOff.x = musicOffSurface->clip_rect.x;
    musicRectOff.y = musicOffSurface->clip_rect.y;
    musicRectOff.w = musicOffSurface->clip_rect.w;
    musicRectOff.h = musicOffSurface->clip_rect.h;

    musicRectOff.x = rectLocX;
    musicRectOff.y = rectLocY;
}


// Sure yes
void sure_rect_yes(int rectLocX, int rectLocY)
{
    sureRectYes.x = sureYesSurface->clip_rect.x;
    sureRectYes.y = sureYesSurface->clip_rect.y;
    sureRectYes.w = sureYesSurface->clip_rect.w;
    sureRectYes.h = sureYesSurface->clip_rect.h;

    sureRectYes.x = rectLocX;
    sureRectYes.y = rectLocY;
}
// sure no
void sure_rect_no(int rectLocX, int rectLocY)
{
    sureRectNo.x = sureNoSurface->clip_rect.x;
    sureRectNo.y = sureNoSurface->clip_rect.y;
    sureRectNo.w = sureNoSurface->clip_rect.w;
    sureRectNo.h = sureNoSurface->clip_rect.h;

    sureRectNo.x = rectLocX;
    sureRectNo.y = rectLocY;
}

// rect to go back to the main menu
void main_menu_rect(int rectLocX, int rectLocY)
{
    mainMenuRect.x = mainMenuSurface->clip_rect.x;
    mainMenuRect.y = mainMenuSurface->clip_rect.y;
    mainMenuRect.w = mainMenuSurface->clip_rect.w;
    mainMenuRect.h = mainMenuSurface->clip_rect.h;

    mainMenuRect.x = rectLocX;
    mainMenuRect.y = rectLocY;
}

// ------------- BOARD RECTS -----------------------------
void board_rect1(int rectLocX, int rectLocY, int rectLocW, int rectLocH)
{
    boardRect1.x = rectLocX;
    boardRect1.y = rectLocY;
    boardRect1.w = rectLocW;
    boardRect1.h = rectLocH;

}

void board_rect2(int rectLocX, int rectLocY, int rectLocW, int rectLocH)
{
    boardRect2.x = rectLocX;
    boardRect2.y = rectLocY;
    boardRect2.w = rectLocW;
    boardRect2.h = rectLocH;
}

void board_rect3(int rectLocX, int rectLocY, int rectLocW, int rectLocH)
{
    boardRect3.x = rectLocX;
    boardRect3.y = rectLocY;
    boardRect3.w = rectLocW;
    boardRect3.h = rectLocH;
}

void board_rect4(int rectLocX, int rectLocY, int rectLocW, int rectLocH)
{
    boardRect4.x = rectLocX;
    boardRect4.y = rectLocY;
    boardRect4.w = rectLocW;
    boardRect4.h = rectLocH;
}

void board_rect5(int rectLocX, int rectLocY, int rectLocW, int rectLocH)
{
    boardRect5.x = rectLocX;
    boardRect5.y = rectLocY;
    boardRect5.w = rectLocW;
    boardRect5.h = rectLocH;
}

void board_rect6(int rectLocX, int rectLocY, int rectLocW, int rectLocH)
{
    boardRect6.x = rectLocX;
    boardRect6.y = rectLocY;
    boardRect6.w = rectLocW;
    boardRect6.h = rectLocH;
}

void board_rect7(int rectLocX, int rectLocY, int rectLocW, int rectLocH)
{
    boardRect7.x = rectLocX;
    boardRect7.y = rectLocY;
    boardRect7.w = rectLocW;
    boardRect7.h = rectLocH;
}



