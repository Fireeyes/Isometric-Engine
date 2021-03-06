//==============================================================================
#ifndef _CTILE_H_
	#define _CTILE_H_

#include "Define.h"
#include <vector>
//==============================================================================
enum {
    TILE_TYPE_NONE = 0,

    TILE_TYPE_NORMAL,
    TILE_TYPE_BLOCK,
    TILE_TYPE_WALL
};

//==============================================================================
class CTile {
    public:
        int     TileID;
        int     TypeID;
        int     TileHeight;

        std::vector<CTile> HeightTile;

    public:
        CTile();
};

//==============================================================================
#endif
