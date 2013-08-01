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
    CCamera::CameraControl.SetPos(CPlayer::Player.X - 320, CPlayer::Player.Y - 240);

}

//==============================================================================
