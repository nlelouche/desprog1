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
class MyScene;
//---------------------------------------------------------------------------
#include "../Src/Force Game/MyGame/MyScene.h"
#include "../Src/Force Game/Animation Engine/AnimEngine.h"
#include "../Src/Force Engine/Defines/Defines.h"
#include "../Src/Force Engine/Force Engine/ForceEngine.h"
//---------------------------------------------------------------------------
class ForceGame : public Game
{
public:

	ForceGame(HINSTANCE hInstance);
	~ForceGame();

protected:

	bool onInit();
	bool onLoop();
	bool onDeInit();

private:

	MyScene	* m_pkMyScene;

	friend class Graphics;
};

//---------------------------------------------------------------------------

#endif /*--- FORCE_GAME_H ---*/

//---------------------------------------------------------------------------