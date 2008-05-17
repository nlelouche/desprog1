/****************************************************************************

Force Engine v0.1

Creado: 28/03/08
Clase: ForceGame.h
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#ifndef FORCE_GAME_H
#define FORCE_GAME_H
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#include "Importer.h"
#include "ForceEngine.h"
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
	Texture * m_pTexture;

	friend class Graphics;
};

#endif /*--- FORCE_GAME_H ---*/

//---------------------------------------------------------------------------