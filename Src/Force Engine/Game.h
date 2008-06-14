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
#include "Scene.h"
#include "Window.h"
#include "Texture.h"
#include "Defines.h"
#include "Graphics.h"
#include "GraphicsStructs.h"
//---------------------------------------------------------------------------
class Timer;
class Window;
class Graphics;
class Texture;
class Scene;
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

	const Scene * getCurrentScene() const;
	void setCurrentScene(Scene * pkCurrentScene);

protected:

	virtual bool onInit() = 0;
	virtual bool onLoop() = 0;
	virtual bool onDeInit() = 0;

	Timer * m_pkTimer;

	Graphics * m_pGraficos;

	std::vector <Entity2D*> m_apkEntities;

	Scene * m_pkCurrentScene;

private:

	Window * m_pWindow;

	HINSTANCE m_hInstance;
};

//---------------------------------------------------------------------------
#include "Game.inl"
//---------------------------------------------------------------------------

#endif /*--- GAME_H ---*/

//---------------------------------------------------------------------------