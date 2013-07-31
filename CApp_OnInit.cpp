//==============================================================================
#include "CApp.h"
extern CPlayer Player;
//using namespace CPlayer;
//==============================================================================
bool CApp::Init() {

    //==============================================================================
    // SDL Initialization
    //==============================================================================
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    if((Surf_Display = SDL_SetVideoMode(WWIDTH, WHEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        return false;
    }

    if (TTF_Init() < 0) {
        std::cerr << "Error: Unable to initialize SDL_ttf" << std::endl;
        return false;
    }

    SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL / 3);

    if(CArea::AreaControl.Load("./maps/1.area") == false) {
    	return false;
    }

    if(CPlayer::Player.Load("player.png", 128, 128) == false)
        return false;

    CPlayer::Player.AddAnimation("IdleWest",      0, 128 * 0, 4, true);
    CPlayer::Player.AddAnimation("IdleNorthWest", 0, 128 * 1, 4, true);
    CPlayer::Player.AddAnimation("IdleNorth",     0, 128 * 2, 4, true);
    CPlayer::Player.AddAnimation("IdleNorthEast", 0, 128 * 3, 4, true);
    CPlayer::Player.AddAnimation("IdleEast",      0, 128 * 4, 4, true);
    CPlayer::Player.AddAnimation("IdleSouthEast", 0, 128 * 5, 4, true);
    CPlayer::Player.AddAnimation("IdleSouth",     0, 128 * 6, 4, true);
    CPlayer::Player.AddAnimation("IdleSouthWest", 0, 128 * 7, 4, true);

    CPlayer::Player.AddAnimation("WalkWest",      128 * 4, 128 * 0, 8);
    CPlayer::Player.AddAnimation("WalkNorthWest", 128 * 4, 128 * 1, 8);
    CPlayer::Player.AddAnimation("WalkNorth",     128 * 4, 128 * 2, 8);
    CPlayer::Player.AddAnimation("WalkNorthEast", 128 * 4, 128 * 3, 8);
    CPlayer::Player.AddAnimation("WalkEast",      128 * 4, 128 * 4, 8);
    CPlayer::Player.AddAnimation("WalkSouthEast", 128 * 4, 128 * 5, 8);
    CPlayer::Player.AddAnimation("WalkSouth",     128 * 4, 128 * 6, 8);
    CPlayer::Player.AddAnimation("WalkSouthWest", 128 * 4, 128 * 7, 8);

    CPlayer::Player.SetAnimation("IdleSouth");
    CPlayer::Player.X = WWIDTH  / 2;
    CPlayer::Player.Y = WHEIGHT / 2;
    CEntity::EntityList.push_back(&CPlayer::Player);
    CPlayer::Player.SetAnimation("IdleWest");

    if(!(Debug::font = TTF_OpenFont("Times.ttf", 12)))
        return false;

    Debug::Surf_Dest = Surf_Display;

    return true;
}

//==============================================================================
