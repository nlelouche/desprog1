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
#include "ForceEngine.h"
#include "Importer.h"
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

	friend class Graphics;

private:

	ForceBOX * m_pBox;
	ForceCIRCLE * m_pCircle;
	ForceTRIANGLE * m_pTriangle;

	Sprite * m_pSprite;
	Texture * m_pTexture;
};

#endif /*--- FORCE_GAME_H ---*/

//---------------------------------------------------------------------------