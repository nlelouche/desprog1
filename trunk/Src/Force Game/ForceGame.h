/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: ForceGame.h
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#ifndef FORCE_GAME_H
#define FORCE_GAME_H
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#include "../Force Engine/ForceEngine.h"
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
class ForceGame: public Game
{
public:

	ForceGame(HINSTANCE hInstance);
	~ForceGame();

protected:

	bool onInit();
	bool onLoop();
	bool onDeInit();

private:

	Sprite * m_pSprite;
	Sprite * m_pSpriteAnim;

	Texture::Ptr m_pTexture;
	
	Animation * m_pAnimation;
	AnimationInfo::Ptr m_pAnimationInfo;

	friend class Graphics;
};

//---------------------------------------------------------------------------

#endif /*--- FORCE_GAME_H ---*/

//---------------------------------------------------------------------------