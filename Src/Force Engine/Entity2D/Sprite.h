/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: Sprite.h
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#ifndef SPRITE_H
#define SPRITE_H
//---------------------------------------------------------------------------
#include "../Graphics/Texture.h"
#include "../Entity2D/Entity2D.h"
#include "../Graphics/Graphics.h"
#include "../Animation/Animation.h"
#include "../Graphics/GraphicsStructs.h"
//---------------------------------------------------------------------------
class FORCEENGINE_API Sprite: public Entity2D
{

public:

	Sprite();
	Sprite(const Sprite & rkSprite);
	~Sprite();

	void Draw(Graphics & rkGraphics) const;
	void Update(float fTimeBetweenFrames);

	void setTexture(Texture::Ptr pkTexture);
	const Texture::Ptr getTexture() const;

	void setTextureArea(
						unsigned int uiOffsetX,
						unsigned int uiOffsetY,
						unsigned int uiWidth,
						unsigned int uiHeight
						); 

	void setAnimation(Animation * pkCurrentAnim);

	virtual void onCollision(Entity2D * pkEntity) { /*****/ }

private:

	Texture::Ptr m_pkTexture;
	TextureVertex m_pkVertex[4];

	Animation * m_pkCurrentAnim;
};

//---------------------------------------------------------------------------
#include "Sprite.inl"
//---------------------------------------------------------------------------

#endif /*--- SPRITE_H ---*/

//---------------------------------------------------------------------------