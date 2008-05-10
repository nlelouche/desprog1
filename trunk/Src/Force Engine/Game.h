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
#include "Timer.h"
#include "Shape.h"
#include "Window.h"
#include "Defines.h"
#include "Graphics.h"
//---------------------------------------------------------------------------
class Window;
class Entity2D;
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

	std::vector <Entity2D*> m_apkEntities;

	Graphics * g_graficos;

private:

	HINSTANCE m_hInstance;

	Window * g_window;
};

//---------------------------------------------------------------------------
#include "Game.inl"
//---------------------------------------------------------------------------

#endif /*--- GAME_H ---*/

//---------------------------------------------------------------------------