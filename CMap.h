//==============================================================================
#ifndef _CMAP_H_
    #define _CMAP_H_

#include <SDL/SDL.h>
#include <vector>

#include "CTile.h"
#include "CSurface.h"

//==============================================================================
class CMap {
	public:
		SDL_Surface*			Surf_Tileset;

	private:
		std::vector<CTile>      TileList;

	public:
		CMap();

	public:
		bool Load(char* File);

		void Render(SDL_Surface* Surf_Display, int MapX, int MapY);
};

//==============================================================================

#endif
