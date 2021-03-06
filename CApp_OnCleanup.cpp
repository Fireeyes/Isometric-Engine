//==============================================================================
#include "CApp.h"

//==============================================================================
void CApp::Cleanup() {
	CArea::AreaControl.Cleanup();

    //--------------------------------------------------------------------------
    // Entities
    //--------------------------------------------------------------------------
    for(int i = 0;i < CEntity::EntityList.size();i++) {
        if(!CEntity::EntityList[i]) continue;

        CEntity::EntityList[i]->Cleanup();
    }

    CEntity::EntityList.clear();

    SDL_FreeSurface(Surf_Display);
    SDL_Quit();
}

//==============================================================================
