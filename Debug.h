#ifndef _DEBUG_H_
    #define _DEBUG_H_

#include "SDL/SDL_ttf.h"

class Debug
{
public:
    static TTF_Font *font;

    static void RenderText(char* Text, SDL_Surface* Surf_Dest, int X, int Y);

    Debug();
};


#endif // _DEBUG_H_

