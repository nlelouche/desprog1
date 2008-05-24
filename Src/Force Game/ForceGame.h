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

	ForceBOX * m_pBox;
	ForceCIRCLE * m_pCircle;
	ForceTRIANGLE * m_pTriangle;

	Sprite * m_pSprite;
	Sprite * m_pAnimation;

	Texture::Ptr m_pTexture;

	friend class Graphics;
};

#endif /*--- FORCE_GAME_H ---*/

//---------------------------------------------------------------------------