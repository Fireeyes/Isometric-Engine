#include "Debug.h"

TTF_Font*     Debug::font;
SDL_Surface*  Debug::Surf_Dest;
    const double PI = 3.141592;
std::string Debug::Int2String(float i) {
    std::stringstream sstream;

    sstream << i;

    return sstream.str();
}
void Debug::RenderText(char* text, int X, int Y)
{
    SDL_Color white = {255, 255, 255};
    SDL_Surface* text_solid = NULL;
    text_solid = TTF_RenderText_Solid(font, text, white);
    SDL_Rect DestR;
    DestR.x = X;
    DestR.y = Y;
    SDL_BlitSurface(text_solid, NULL, Surf_Dest, &DestR);
}

void Debug::PlayerPos()
{
    SDL_Color white = {255, 255, 255};
    SDL_Surface* text_solid = NULL;
    std::string debugText = "Player Position:";
    debugText.append(Int2String((int) CPlayer::Player.X));
    debugText.append(" ");
    debugText.append(Int2String((int) CPlayer::Player.Y));

    text_solid = TTF_RenderText_Solid(font, debugText.c_str(), white);
    SDL_Rect DestR;
    DestR.x = 0;
    DestR.y = 20;

    SDL_BlitSurface(text_solid, NULL, Surf_Dest, &DestR);
}
void Debug::MousePos()
{
    int x, y;
    SDL_GetMouseState(&x, &y);

    SDL_Color white = {255, 255, 255};
    SDL_Surface* text_solid = NULL;
    std::string debugText = "Mouse Position:";
    debugText.append(Int2String(tan(PI / 6)));
    debugText.append(" ");
    debugText.append(Int2String(y));

    text_solid = TTF_RenderText_Solid(font, debugText.c_str(), white);
    SDL_Rect DestR;
    DestR.x = 0;
    DestR.y = 40;

    SDL_BlitSurface(text_solid, NULL, Surf_Dest, &DestR);
    debugText = "Slope:";

    x = x - WWIDTH / 2;
    y = WHEIGHT / 2 - y;

    float slope =  (float) y / x;
    double angle = atan(slope);

    float vx = sin(angle);

    debugText.append(Int2String(slope));
    text_solid = TTF_RenderText_Solid(font, debugText.c_str(), white);

    DestR.x = 0;
    DestR.y = 60;

    SDL_BlitSurface(text_solid, NULL, Surf_Dest, &DestR);
}
