//==============================================================================
#ifndef _CENTITY_H_
    #define _CENTITY_H_

#include <string.h>

#include <iostream>
#include <utility>
#include <vector>
#include <map>

#include "CAnimation.h"
#include "CSurface.h"

using namespace std;

//==============================================================================
class CEntity {
    public:
        static std::vector<CEntity*>    EntityList;

    protected:
        CAnimation      Anim_Control;

        SDL_Surface*    Surf_Entity;

    public:
        float           X;
        float           Y;

        int             Width;
        int             Height;

        string          CurrentAnimation;
        map<string,
            CAnimation> Animations;

	public:
		CEntity();

		virtual ~CEntity();

	public:
        virtual bool Load(char* File, int Width, int Height);

        virtual void Loop();

		virtual void Render(SDL_Surface* Surf_Display);

		virtual void Cleanup();

		virtual void AddAnimation(string Name, int X, int Y, int Frames);

		virtual void AddAnimation(string Name, int X, int Y, int Frames, bool Oscillate);

		virtual void SetAnimation(string Name);

		virtual void MoveBy (int X, int Y);
};

//==============================================================================

#endif
