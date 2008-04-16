/****************************************************************************

Force Engine v0.1

Creado: 28/03/08
Clase: Game.h
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#ifndef GAME_H
#define GAME_H
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#include "Shape.h"
#include "Window.h"
#include "Graphics.h"
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
class FORCEENGINE_API Game
{
public:

	Game();
	virtual ~Game();

	bool Init();
	bool Loop();
	bool deInit();

protected:

	virtual bool onInit() = 0;
	virtual bool onLoop() = 0;
	virtual bool onDeInit() = 0;

	Graphics * g_graficos;

private:

	Shape m_Shape;

	HINSTANCE hInstance;

	Window * g_window;
};

#endif /*--- GAME_H ---*/

//---------------------------------------------------------------------------