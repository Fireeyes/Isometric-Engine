//=============================================================================
#include "CMap.h"

//=============================================================================
CMap::CMap() {
	Surf_Tileset = NULL;
    MouseMapTexture = NULL;
}

//=============================================================================
bool CMap::Load(char* File) {
    TileList.clear();
    MouseMapTexture = CSurface::Load("./textures/mousemap.png");


    FILE* FileHandle = fopen(File, "r");

    if(FileHandle == NULL) {
        return false;
    }

    for(int Y = 0;Y < MAP_HEIGHT;Y++) {
        for(int X = 0;X < MAP_WIDTH;X++) {
            CTile tempTile;
            CTile tempHeight;
            int nHeightTiles;
            fscanf(FileHandle, "%d:%d:%d:%d ", &tempTile.TileID, &tempTile.TypeID, &nHeightTiles,&tempTile.TileHeight);
            if(nHeightTiles != 0)
            {
                for(int i = 0; i < nHeightTiles; i++)
                {
                    int HeightTileID;
                    fscanf(FileHandle, "%d", &HeightTileID);
                    tempHeight.TileID = HeightTileID;
                    tempHeight.TypeID = tempTile.TypeID;
                    tempTile.HeightTile.push_back(tempHeight);
                }
            }

            TileList.push_back(tempTile);
        }
        fscanf(FileHandle, "\n");
    }

    fclose(FileHandle);

    return true;
}

//-----------------------------------------------------------------------------
void CMap::Render(SDL_Surface* MouseMap, SDL_Surface* Surf_Display, int MapX, int MapY) {
	bool oddRow = false;

	if(Surf_Tileset == NULL) return;

	int TilesetWidth  = Surf_Tileset->w / TILE_WIDTH;
	int TilesetHeight = Surf_Tileset->h / TILE_HEIGHT;

	int ID = 0;

	for(int Y = 0;Y < MAP_HEIGHT;Y++) {
		for(int X = 0;X < MAP_WIDTH;X++) {
            oddRow = false;
			if(TileList[ID].TypeID == TILE_TYPE_NONE) {
				ID++;
				continue;
			}
			int tX, tY;

			tX = MapX + X * TILE_WIDTH;
			tY = MapY + Y * TILE_HEIGHT / 2;
			if(Y % 2 == 1)
            {
                tX = MapX + X * TILE_WIDTH + TILE_WIDTH / 2;
                oddRow = true;

            }



			int TilesetX = (TileList[ID].TileID % TilesetWidth) * TILE_WIDTH;
			int TilesetY = (TileList[ID].TileID / TilesetWidth) * TILE_HEIGHT;

			CSurface::Draw(Surf_Display,
                           Surf_Tileset,
                           tX,
                           tY - TILE_HEIGHT * TileList[ID].TileHeight,
                           TilesetX,
                           TilesetY,
                           TILE_WIDTH,
                           TILE_HEIGHT);
            if(oddRow == false)
                CSurface::Draw(Surf_Display,
                               MouseMapTexture,
                               tX,
                               tY,
                               0,
                               0,
                               TILE_WIDTH,
                               TILE_HEIGHT);


            for(int i=0; i < TileList[ID].HeightTile.size(); i++)
            {
                int TilesetX = (TileList[ID].HeightTile[i].TileID % TilesetWidth) * TILE_WIDTH;
                int TilesetY = (TileList[ID].HeightTile[i].TileID / TilesetWidth) * TILE_HEIGHT;

                CSurface::Draw(Surf_Display,
                               Surf_Tileset,
                               tX,
                               tY,
                               TilesetX,
                               TilesetY,
                               TILE_WIDTH,
                               TILE_HEIGHT);

                tY -= TILE_HEIGHT;
            }

			ID++;
		}
	}
}

//=============================================================================
