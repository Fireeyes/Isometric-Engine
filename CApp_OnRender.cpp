//==============================================================================
#include "CApp.h"
extern CPlayer Player;
//==============================================================================
void CApp::Render() {
	SDL_Rect Rect;
	Rect.x = 0;
	Rect.y = 0;
	Rect.w = WWIDTH;
	Rect.h = WHEIGHT;

	SDL_FillRect(Surf_Display, &Rect, 0);

	CArea::AreaControl.Render(Surf_Display, -CCamera::CameraControl.GetX(), -CCamera::CameraControl.GetY());

    //--------------------------------------------------------------------------
    // Entities
    //--------------------------------------------------------------------------

    for(int i = 0;i < CEntity::EntityList.size();i++) {
        if(!CEntity::EntityList[i]) continue;

        CEntity::EntityList[i]->Render(Surf_Display);
    }


    Debug::RenderText("Hello World!", 0, 0);
    Debug::PlayerPos();
    Debug::MousePos();
	SDL_Flip(Surf_Display);
}

//==============================================================================
