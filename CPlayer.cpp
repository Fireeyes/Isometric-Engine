#include "CPlayer.h"


CPlayer CPlayer::Player;

void CPlayer::Render(SDL_Surface* Surf_Display) {
if(Surf_Entity == NULL || Surf_Display == NULL) return;

    CSurface::Draw(Surf_Display,
                     Surf_Entity,
                     WWIDTH  / 2  - Width  / 2,
                     WHEIGHT / 2  - Height / 2,
                     Anim_Control.GetCurrentFrame() * Width + Anim_Control.X,
                     Anim_Control.Y,
                     Width,
                     Height);
}
