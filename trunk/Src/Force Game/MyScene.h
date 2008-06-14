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
#include <fmod/fmod.h>
#include "../Force Engine/Defines.h"
#include "../Force Engine/ForceEngine.h"
//---------------------------------------------------------------------------

class MyScene : public Scene
{

public:

	MyScene();
	virtual ~MyScene();

	bool onInit();
	bool onUpdate(float fTimeBetweenFrames);
	void onDraw(Graphics& rkGraphics) const;
	bool onDeInit();

private:

	Sprite * m_pPacman;
	Sprite * m_pPhantom;

	Texture::Ptr m_pkPacman;

	ForceBOX * m_pShapeBox1;
	ForceBOX * m_pShapeBox2;
	ForceBOX * m_pShapeRoof;
	ForceBOX * m_pShapeFloor;

	Animation * m_pAnimationPac;
	Animation * m_pAnimationPacMuerte;

	AnimationInfo::Ptr m_pAnimationInfoPac;
	AnimationInfo::Ptr m_pAnimationInfoPacMuerte;

	friend class Graphics;
};

//---------------------------------------------------------------------------

#endif /*--- MY_SCENE_H ---*/

//---------------------------------------------------------------------------