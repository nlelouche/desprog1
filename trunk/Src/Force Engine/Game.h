/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: Game.h
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#ifndef GAME_H
#define GAME_H
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#include "Timer.h"
#include "Shape.h"
#include "Window.h"
#include "Defines.h"
#include "Graphics.h"
#include "GraphicsStructs.h"
//---------------------------------------------------------------------------
class Timer;
class Window;
class Graphics;
//---------------------------------------------------------------------------
class FORCEENGINE_API Game
{
public:

	Game(HINSTANCE hInstance);
	virtual ~Game();

	bool Init();
	bool Loop();
	bool deInit();

	void addEntity(Entity2D* pkEntity);

protected:

	virtual bool onInit() = 0;
	virtual bool onLoop() = 0;
	virtual bool onDeInit() = 0;

	Timer * m_pkTimer;

	Graphics * g_graficos;

	std::vector <Entity2D*> m_apkEntities;

private:

	Window * g_window;

	HINSTANCE m_hInstance;
};

//---------------------------------------------------------------------------
#include "Game.inl"
//---------------------------------------------------------------------------

#endif /*--- GAME_H ---*/

//---------------------------------------------------------------------------