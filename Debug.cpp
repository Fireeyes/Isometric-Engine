#include "Debug.h"

TTF_Font * Debug::font;

void Debug::RenderText(char* text, SDL_Surface* Surf_Dest, int X, int Y)
{
    SDL_Color white = {255, 255, 255};
    SDL_Surface* text_solid = NULL;
    text_solid = TTF_RenderText_Solid(font, text, white);
    SDL_Rect DestR;
    DestR.x = X;
    DestR.y = Y;
    SDL_BlitSurface(text_solid, NULL, Surf_Dest, &DestR);
}

