//==============================================================================
#include "CApp.h"
//==============================================================================

void CApp::OnEvent(SDL_Event* Event) {
    CEvent::OnEvent(Event);
}

//==============================================================================
void CApp::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
	switch(sym) {
	    /*
		case SDLK_UP: 	 CCamera::CameraControl.Move( 0,  5); CPlayer::Player.SetAnimation("WalkNorth"); break;
		case SDLK_DOWN:  CCamera::CameraControl.Move( 0, -5); CPlayer::Player.SetAnimation("WalkSouth"); break;
		case SDLK_LEFT:  CCamera::CameraControl.Move( 5,  0); CPlayer::Player.SetAnimation("WalkWest");  break;
		case SDLK_RIGHT: CCamera::CameraControl.Move(-5,  0); CPlayer::Player.SetAnimation("WalkEast");  break;
        */
        case SDLK_UP: 	 CPlayer::Player.MoveBy( 0,  2); CPlayer::Player.SetAnimation("WalkNorth"); break;
		case SDLK_DOWN:  CPlayer::Player.MoveBy( 0, -2); CPlayer::Player.SetAnimation("WalkSouth"); break;
		case SDLK_LEFT:  CPlayer::Player.MoveBy( 2,  0); CPlayer::Player.SetAnimation("WalkWest");  break;
		case SDLK_RIGHT: CPlayer::Player.MoveBy(-2,  0); CPlayer::Player.SetAnimation("WalkEast");  break;
		default: {
		    //CPlayer::Player.SetAnimation("IdleEast");
		}
	}
}

//------------------------------------------------------------------------------
void CApp::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode) {
	switch(sym) {
        case SDLK_UP: 	 CPlayer::Player.SetAnimation("IdleNorth"); break;
		case SDLK_DOWN:  CPlayer::Player.SetAnimation("IdleSouth"); break;
		case SDLK_LEFT:  CPlayer::Player.SetAnimation("IdleWest");  break;
		case SDLK_RIGHT: CPlayer::Player.SetAnimation("IdleEast");  break;
		default: {
		    //CPlayer::Player.SetAnimation("IdleEast");
		}
	}
}
//------------------------------------------------------------------------------
void CApp::OnExit() {
	Running = false;
}

//==============================================================================
