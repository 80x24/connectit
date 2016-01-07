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

bool load_sounds()
{
    // load the .ogg background music
    bgMusic = Mix_LoadMUS("assets/sounds/tech-a-cool.ogg");
    if(bgMusic == NULL)
    {
        fprintf(stderr, "Background music loading failed\n");
        return false;
    }
    // load the .ogg sound effect
    boing = Mix_LoadWAV("assets/sounds/boing_1.ogg");
    if(boing == NULL)
    {
        fprintf(stderr, "Sound effect 1 loading failed\n");
        return false;
    }

    boing2 = Mix_LoadWAV("assets/sounds/boing_2.ogg");
    if(boing2 == NULL)
    {
        fprintf(stderr, "Sound effect 2 loading failed\n");
        return false;
    }

    winSound = Mix_LoadWAV("assets/sounds/winner2.ogg");
    if(winSound == NULL)
    {
        fprintf(stderr, "Win sound effect loading failed\n");
        return false;
    }
    return true;
}
