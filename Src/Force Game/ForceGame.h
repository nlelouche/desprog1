/****************************************************************************

Force Engine v0.1

Creado: 28/03/08
Clase: Force Game.h
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#ifndef FORCE_GAME_H
#define FORCE_GAME_H
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#include "Game.h"
#include "Shape.h"
#include "Window.h"
#include "Graphics.h"
#include "ForceBOX.h"
#include "ForceCIRCLE.h"
#include "ForceTRIANGLE.h"
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
};

#endif /*--- FORCE_GAME_H ---*/

//---------------------------------------------------------------------------