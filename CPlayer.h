#ifndef _CPLAYER_H_
    #define _CPLAYER_H_

#include <math.h>

#include "CEntity.h"
#include "Define.h"

class CPlayer : public CEntity
{
public:
    static CPlayer Player;

    static char* state;

    void Render(SDL_Surface* Surf_Display);

    void Loop();
};

#endif // _CPLAYER_H_
