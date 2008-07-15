/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: AnimEngine.h
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#ifndef ANIM_ENGINE_H
#define ANIM_ENGINE_H
//---------------------------------------------------------------------------
#include "../Src/Force Engine/Defines/Defines.h"
#include "../Src/Force Engine/Force Engine/ForceEngine.h"
//---------------------------------------------------------------------------
class AnimEngine : public Scene
{

public:

	AnimEngine(Graphics & rkGraphics);
	virtual ~AnimEngine();

	bool onInit();
	bool onUpdate(float fTimeBetweenFrames);
	void onDraw(Graphics & rkGraphics) const;
	bool onDeInit();

	void rotateLogo(float fTimeBetweenFrames);

private:

	Sprite * m_pkSpriteLogoFist;
	Sprite * m_pkSpriteLogoGear;

	Texture::Ptr m_pkTextureLogoFist;
	Texture::Ptr m_pkTextureLogoGear;

	friend class Graphics;
};

//---------------------------------------------------------------------------

#endif /*--- ANIM_ENGINE_H ---*/

//---------------------------------------------------------------------------