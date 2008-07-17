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
#include "../Force Engine/ForceEngine.h"
#include "../Defines/Defines.h"
#include "../Entity2D/Entity2D.h"
//---------------------------------------------------------------------------
class Scene;
class Input;
class Timer;
class Graphics;
class ConfigFile;
//---------------------------------------------------------------------------
class FORCEENGINE_API Game
{
public:

	Game(HINSTANCE hInstance);
	virtual ~Game();

	bool Init();
	bool Loop();
	bool deInit();

	void addEntity(Entity2D * pkEntity);

	const Scene * getCurrentScene() const;
	void setCurrentScene(Scene * pkCurrentScene);

protected:

	virtual bool onInit() = 0;
	virtual bool onLoop() = 0;
	virtual bool onDeInit() = 0;

	Timer * m_pkTimer;

	Input * m_pkInput;

	Graphics * m_pkGraphics;

	Scene * m_pkCurrentScene;

	std::vector <Entity2D*> m_apkEntities;

private:

	Window * m_pkWindow;

	HINSTANCE m_hInstance;
};

//---------------------------------------------------------------------------
#include "Game.inl"
//---------------------------------------------------------------------------

#endif /*--- GAME_H ---*/

//---------------------------------------------------------------------------