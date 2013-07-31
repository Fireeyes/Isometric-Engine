//==============================================================================
#include "CEntity.h"

//==============================================================================
std::vector<CEntity*> CEntity::EntityList;

//==============================================================================
CEntity::CEntity() {
    Surf_Entity = NULL;

    X = Y = 0.0f;

    Width = Height = 0;

}

//------------------------------------------------------------------------------
CEntity::~CEntity() {
}

//==============================================================================
bool CEntity::Load(char* File, int Width, int Height) {
	if((Surf_Entity = CSurface::Load(File)) == NULL) {
		return false;
	}

	CSurface::Transparent(Surf_Entity, 255, 0, 255);

	this->Width = Width;
	this->Height = Height;

    return true;
}

//------------------------------------------------------------------------------
void CEntity::Loop() {
    Anim_Control.Animate();
}

//------------------------------------------------------------------------------
void CEntity::Render(SDL_Surface* Surf_Display) {
    if(Surf_Entity == NULL || Surf_Display == NULL) return;

    CSurface::Draw(Surf_Display,
                     Surf_Entity,
                     X - Width  / 2,
                     Y - Height / 2,
                     Anim_Control.GetCurrentFrame() * Width + Anim_Control.X,
                     Anim_Control.Y,
                     Width,
                     Height);
}

//------------------------------------------------------------------------------
void CEntity::Cleanup() {
    if(Surf_Entity) {
        SDL_FreeSurface(Surf_Entity);
    }

    Surf_Entity = NULL;
}
//------------------------------------------------------------------------------
void CEntity::AddAnimation(std::string Name, int X, int Y, int Frames)
{
    CAnimation TempAnimation;
    TempAnimation.X = X;
    TempAnimation.Y = Y;
    TempAnimation.MaxFrames = Frames;
    Animations[Name] = TempAnimation;
}
//------------------------------------------------------------------------------
void CEntity::AddAnimation(std::string Name, int X, int Y, int Frames, bool Oscillate)
{
    CAnimation TempAnimation;
    TempAnimation.X = X;
    TempAnimation.Y = Y;
    TempAnimation.MaxFrames = Frames;
    TempAnimation.Oscillate = Oscillate;
    Animations[Name] = TempAnimation;
}
//------------------------------------------------------------------------------
void CEntity::SetAnimation(std::string Name)
{
    CurrentAnimation = Name;
    Anim_Control.X = Animations[Name].X;
    Anim_Control.Y = Animations[Name].Y;
    Anim_Control.MaxFrames = Animations[Name].MaxFrames;
}
//------------------------------------------------------------------------------
void CEntity::MoveBy(float X, float Y)
{
    this->X += X;
    this->Y += Y;
}
//------------------------------------------------------------------------------
void CEntity::SetDirection (int Direction)
{
    this->Direction = Direction;

}
//==============================================================================
