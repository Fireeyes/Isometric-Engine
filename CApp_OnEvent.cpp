//==============================================================================
#include "CApp.h"
//==============================================================================

void CApp::OnEvent(SDL_Event* Event) {
    CEvent::OnEvent(Event);
}

//==============================================================================
void CApp::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
	switch(sym) {
        case SDLK_UP:
            CPlayer::Player.MoveBy( 0, -2);
            CPlayer::Player.SetAnimation("WalkNorth");
            CPlayer::Player.SetDirection(DIRECTION_NORTH);
            break;
		case SDLK_DOWN:
		    CPlayer::Player.MoveBy( 0,  2);
		    CPlayer::Player.SetAnimation("WalkSouth");
		    CPlayer::Player.SetDirection(DIRECTION_SOUTH);
		    break;
		case SDLK_LEFT:
		    CPlayer::Player.MoveBy(-2,  0);
		    CPlayer::Player.SetAnimation("WalkWest");
		    CPlayer::Player.SetDirection(DIRECTION_WEST);
		    break;
		case SDLK_RIGHT:
		    CPlayer::Player.MoveBy( 2,  0);
		    CPlayer::Player.SetAnimation("WalkEast");
		    CPlayer::Player.SetDirection(DIRECTION_EAST);
		    break;
		default:
		    {

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
void CApp::OnLButtonDown(int mX, int mY)
{

//  CPlayer::Player.MoveBy( 0, -2);
}
//------------------------------------------------------------------------------
void CApp::OnExit() {
	Running = false;
}

//==============================================================================
