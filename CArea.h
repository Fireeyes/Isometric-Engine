//=============================================================================
#ifndef _CAREA_H_
    #define _CAREA_H_

#include "CMap.h"

//=============================================================================
class CArea {
    public:
        static CArea            AreaControl;

    public:
        std::vector<CMap>       MapList;

    private:
        int                     AreaSize;

        SDL_Surface*			Surf_Tileset;

    public:
        CArea();

        bool    Load(char* File);

        void    Render(SDL_Surface* MouseMap, SDL_Surface* Surf_Display, int CameraX, int CameraY);

        void    Cleanup();
};

//=============================================================================

#endif

