//==============================================================================
#include "CApp.h"
extern CPlayer Player;
//==============================================================================
CApp::CApp() {
    Surf_Display = NULL;

    Running = true;
}

//------------------------------------------------------------------------------
int CApp::Execute() {

    if(Init() == false) {
        return -1;
    }

    SDL_Event Event;

    while(Running) {
        while(SDL_PollEvent(&Event)) {
            OnEvent(&Event);
        }

        Loop();
        Render();
    }

    Cleanup();

    return 0;
}

//==============================================================================
int main(int argc, char* argv[]) {

    int x;
    CApp theApp;

    return theApp.Execute();
}

//==============================================================================
