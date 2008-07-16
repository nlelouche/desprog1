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
#include "../Src/Force Engine/Defines/Defines.h"
#include "../Src/Force Engine/Force Engine/ForceEngine.h"
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

	void updateCollisionChar();

private:

	ForceBOX * m_pkFloor;

	Sprite * m_pkChar;
	Sprite * m_pkBack;

	Texture::Ptr m_pkCharText;
	Texture::Ptr m_pkBackText;

	Animation * m_pkCharAnimIzq;
	Animation * m_pkCharAnimDer;

	AnimationInfo::Ptr m_pkCharAnimInfoIzq;
	AnimationInfo::Ptr m_pkCharAnimInfoDer;

	float	fVelocityX;
	float	fVelocityY;
	
	float	fPosX;
	float	fPosY;

	float	fGravity;

};

//---------------------------------------------------------------------------

#endif /*--- MY_SCENE_H ---*/

//---------------------------------------------------------------------------