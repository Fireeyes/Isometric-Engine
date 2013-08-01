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

void CPlayer::Loop()
{
    Anim_Control.Animate();
    if(SDL_GetMouseState(NULL, NULL)&SDL_BUTTON(1)) //Character Movement
    {
        const double PI = 3.141592;
        float vx, vy;
        int x, y;

        SDL_GetMouseState(&x, &y);

        x = x - WWIDTH  / 2;
        y = y - WHEIGHT / 2;

        double slope = (double) y / x / 1.0;
        double angle = atan(slope);
        vx = cos(angle) * 0.1;
        vy = sin(angle) * 0.1;
        if(x > 0 )
        {
            vx = vx * (-1);
            vy = vy * (-1);
        }

        if(angle <= 0)
            angle = angle * (-1);
        if(vx < 0)
        {

            if(angle >=0 && angle <= PI / 6)
                CPlayer::Player.SetAnimation("WalkEast");
            else if(angle >= PI / 6 && angle <= PI / 3)
                    if(vy > 0)
                        CPlayer::Player.SetAnimation("WalkNorthEast");
                    else
                        CPlayer::Player.SetAnimation("WalkSouthEast");
            else if(angle > PI / 3)
                    if(vy > 0)
                        CPlayer::Player.SetAnimation("WalkNorth");
                    else
                        CPlayer::Player.SetAnimation("WalkSouth");

        }
        else
        {
            if(angle >=0 && angle <= PI / 6)
                CPlayer::Player.SetAnimation("WalkWest");
            else if(angle >= PI / 6 && angle <= PI / 3)
                    if(vy > 0)
                        CPlayer::Player.SetAnimation("WalkNorthWest");
                    else
                        CPlayer::Player.SetAnimation("WalkSouthWest");
            else if(angle > PI / 3)
                    if(vy > 0)
                        CPlayer::Player.SetAnimation("WalkNorth");
                    else
                        CPlayer::Player.SetAnimation("WalkSouth");
        }

        CPlayer::Player.MoveBy(vx, vy);
    }
    else
    {
       std::string newAnim = "Idle";
       newAnim.append(CPlayer::Player.CurrentAnimation.substr(4));
       CPlayer::Player.SetAnimation(newAnim);
    }
}
