//==============================================================================
#include "CApp.h"

//==============================================================================
void CApp::Loop() {
    //--------------------------------------------------------------------------
    // Entities
    //--------------------------------------------------------------------------
    for(int i = 0;i < CEntity::EntityList.size();i++) {
        if(!CEntity::EntityList[i]) continue;

        CEntity::EntityList[i]->Loop();
    }
    CCamera::CameraControl.SetPos(CPlayer::Player.X, CPlayer::Player.Y);
    if(SDL_GetMouseState(NULL, NULL)&SDL_BUTTON(1))
    {
        const double PI = 3.141592;

        float vx, vy;
        int x, y;

        SDL_GetMouseState(&x, &y);
        x = x - WWIDTH / 2;
        y = y - WHEIGHT / 2;

        float slope = (float) y / x / 1.0;
        double angle = atan(slope);
        vx = cos(angle) * 0.5;
        vy = sin(angle) * 0.5;
        if(x > 0 )
        {
            vx = vx * (-1);
            vy = vy * (-1);
        }
        vx = vx * (-1);
        if(vx > 0)
            if(vy > 0)
                if(vx > vy)
                    CPlayer::Player.SetAnimation("WalkEast");
                else
                    CPlayer::Player.SetAnimation("WalkNorth");
            else
                if(vx > vy * (-1))
                    CPlayer::Player.SetAnimation("WalkEast");
                else
                    CPlayer::Player.SetAnimation("WalkSouth");
        else
            if(vy > 0)
                if((-1) * vx > vy)
                    CPlayer::Player.SetAnimation("WalkWest");
                else
                    CPlayer::Player.SetAnimation("WalkNorth");
            else
                if((-1) * vx > vy * (-1))
                    CPlayer::Player.SetAnimation("WalkWest");
                else
                    CPlayer::Player.SetAnimation("WalkSouth");
        CPlayer::Player.MoveBy(- vx, vy);
    }
}

//==============================================================================
