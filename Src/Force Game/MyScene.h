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

private:

	Sprite		*	m_pkChar;
	Sprite		*	m_pkBack;

	Texture::Ptr	m_pkCharText;
	Texture::Ptr	m_pkBackText;

	Animation	*		m_pkCharAnim;

	AnimationInfo::Ptr	m_pkCharAnimInfo;

};

//---------------------------------------------------------------------------

#endif /*--- MY_SCENE_H ---*/

//---------------------------------------------------------------------------