//==============================================================================

#ifndef _CAPP_H_
    #define _CAPP_H_

#include <SDL/SDL.h>
#include <math.h>
#include "SDL/SDL_ttf.h"

#include "Define.h"
#include "Debug.h"


#include "CArea.h"
#include "CCamera.h"
#include "CEntity.h"
#include "CEvent.h"
#include "CSurface.h"
#include "CPlayer.h"


//==============================================================================
class CApp : public CEvent {
    private:
        bool            Running;

        SDL_Surface*    Surf_Display;

    public:
        CApp();
        TTF_Font *times;

    public:
        int Execute();
        bool Init();
        void OnEvent(SDL_Event* Event);

        	void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);

        	void OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);

            void OnExit();

            void OnLButtonDown(int mX, int mY);

        void Loop();
        void Render();
        void Cleanup();
};

//==============================================================================

#endif
