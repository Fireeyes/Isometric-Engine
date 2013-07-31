//==============================================================================
// Animation Class
//==============================================================================
#ifndef _CANIMATION_H_
    #define _CANIMATION_H_

#include <SDL/SDL.h>

//public void AddAnimation(string Name, int X, int Y, int Width, int Height, int Frames)
//==============================================================================
class CAnimation {
	private:
		int	    CurrentFrame;

		int     FrameInc;

    private:
        int     FrameRate; //Milliseconds

		long    OldTime;

	public:
	    int     X;
	    int     Y;
        int	    MaxFrames;

		bool	Oscillate;

	public:
		CAnimation();

		void Animate();

	public:
        void SetFrameRate(int Rate);

		void SetCurrentFrame(int Frame);

		int GetCurrentFrame();
};

//==============================================================================

#endif
