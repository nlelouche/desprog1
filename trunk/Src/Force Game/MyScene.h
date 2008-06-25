/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: MyScene.h
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#ifndef MY_SCENE_H
#define MY_SCENE_H
//---------------------------------------------------------------------------
#include "../Force Engine/Defines.h"
#include "../Force Engine/ForceEngine.h"
//---------------------------------------------------------------------------

class MyScene : public Scene
{

public:

	MyScene(Graphics & rkGraphics);
	virtual ~MyScene();

	bool onInit();
	bool onUpdate(float fTimeBetweenFrames);
	void onDraw(Graphics & rkGraphics) const;
	bool onDeInit();

protected:

	void updateGhostInput();
	void updatePacmanCollision();

private:

	Sprite * m_pkGhost;

	Texture::Ptr m_pkPacman;

	friend class Graphics;
};

//---------------------------------------------------------------------------

#endif /*--- MY_SCENE_H ---*/

//---------------------------------------------------------------------------