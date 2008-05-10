/****************************************************************************

Force Engine v0.1

Creado: 28/03/08
Clase: Sprite.h
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#ifndef SPRITE_H
#define SPRITE_H
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#include "Texture.h"
#include "Defines.h"
#include "Entity2D.h"
#include "GraphicsStructs.h"
//---------------------------------------------------------------------------

class FORCEENGINE_API Sprite: public Entity2D
{

public:

	Sprite();
	Sprite(const Sprite& rkSprite);
	~Sprite(){ /***/ }

	void Draw(Graphics& g_graphics) const;
	void Update(float fTimeBetweenFrames);

	Sprite& operator=(const Sprite& rkSprite);

	void Clone (Sprite& rkSprite);

	void setTexture(Texture * pkTexture);
	const Texture * getTexture() const;

	void setTextureArea(unsigned int uiOffsetX, unsigned int uiOffsetY, unsigned int uiWidth, unsigned int uiHeight); 

private:

	Texture * m_pkTexture;
	TextureVertex m_Vertex[4];
};

//---------------------------------------------------------------------------
#include "Sprite.inl"
//---------------------------------------------------------------------------

#endif /*--- SPRITE_H ---*/

//---------------------------------------------------------------------------