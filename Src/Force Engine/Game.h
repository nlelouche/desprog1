/****************************************************************************

Force Engine v0.1

Creado: 28/03/08
Clase: Game
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#ifndef GAME_H
#define GAME_H
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
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

	HINSTANCE hInstance;

protected:

	virtual bool onInit() = 0;
	virtual bool onLoop() = 0;
	virtual bool onDeInit() = 0;

	friend class Graphics;
	friend class Window;
};

#endif /*--- GAME_H ---*/

//---------------------------------------------------------------------------