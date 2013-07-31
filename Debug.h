#ifndef _DEBUG_H_
    #define _DEBUG_H_

#include "SDL/SDL_ttf.h"
#include <string>
#include <sstream>
#include "CPlayer.h"
#include <math.h>

class Debug
{
public:
    static TTF_Font *font;
    static SDL_Surface* Surf_Dest;

    static void RenderText(char* Text, int X, int Y);
    static void PlayerPos();
    static void MousePos();
    static std::string Int2String(float i);
    Debug();
};


#endif // _DEBUG_H_

