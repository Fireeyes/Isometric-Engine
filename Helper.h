
#ifndef _HELPER_H_
#define _HELPER_H_

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

class Helper
{
    static void put_pixel32( SDL_Surface *surface, int x, int y, Uint32 pixel);

    static Uint32 get_pixel32( SDL_Surface *surface, int x, int y );

};

#endif // _HELPER_CPP_

