/****************************************************************************

Force Engine v0.1

Creado: 28/03/08
Clase: Sprite.cpp
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#include "Sprite.h"
//---------------------------------------------------------------------------

Sprite::Sprite ()
:
Entity2D()
{
	TextureVertex * pkV;

	pkV = &(m_Vertex[0]);
	pkV->x = -0.5f;	
	pkV->y = -0.5f;	
	pkV->z = 1.0f;
	pkV->tu = 0.0f;	
	pkV->tv = 1.0f;
	
	pkV = &(m_Vertex[1]);
	pkV->x = -0.5f;
	pkV->y = 0.5f;	
	pkV->z = 1.0f;
	pkV->tu = 0.0f;	
	pkV->tv = 0.0f;

	pkV = &(m_Vertex[2]);
	pkV->x = 0.5f;	
	pkV->y = -0.5f;
	pkV->z = 1.0f;
	pkV->tu = 1.0f;	
	pkV->tv = 1.0f;

	pkV = &(m_Vertex[3]);
	pkV->x = 0.5f;	
	pkV->y = 0.5f;	
	pkV->z = 1.0f;
	pkV->tu = 1.0f;	
	pkV->tv = 0.0f;
}

//---------------------------------------------------------------------------
Sprite::Sprite(const Sprite& rkSprite)
{
	*this = rkSprite;
}

//---------------------------------------------------------------------------
Sprite& Sprite::operator=(const Sprite& rkSprite)
{
	if(&rkSprite == this)
	{
		return *this;
	}

	m_pkTexture = rkSprite.m_pkTexture;
	
	for(unsigned int i = 0; i < 4; i++)
	{
		m_Vertex[i] = rkSprite.m_Vertex[i];
	}

	return * this;
}

//---------------------------------------------------------------------------
void Sprite::Draw(Graphics& rkGraphics) const
{
	assert(m_pkTexture);

	Entity2D::Draw(rkGraphics);
	
	if(rkGraphics.bindTexture(* m_pkTexture))
	{
		rkGraphics.Draw(m_Vertex, D3DPT_TRIANGLESTRIP, 4);
	}
	else
	{
		assert(0);
	}
}

//---------------------------------------------------------------------------
void Sprite::Update(float fTimeBetweenFrames)
{
	Entity2D::Update(fTimeBetweenFrames);
}

//---------------------------------------------------------------------------
void Sprite::setTextureArea (unsigned int uiOffsetX, unsigned int uiOffsetY, unsigned int uiWidth, unsigned int uiHeight)
{
	assert(m_pkTexture);

	float fTexWidth = static_cast<float>(m_pkTexture->getWidth());
	float fTexHeight = static_cast<float>(m_pkTexture->getHeight());
	
	float fU1 = uiOffsetX / fTexWidth;
	float fU2 = (uiOffsetX + uiWidth) / fTexWidth;

	float fV1 = uiOffsetY / fTexHeight;
	float fV2 = (uiOffsetY + uiHeight) / fTexHeight;
	
	TextureVertex* pkV = &(m_Vertex[0]);
	pkV->tu = fU1;	
	pkV->tv = fV2;
	
	pkV = &(m_Vertex[1]);
	pkV->tu = fU1;
	pkV->tv = fV1;

	pkV = &(m_Vertex[2]);
	pkV->tu = fU2;	
	pkV->tv = fV2;

	pkV = &(m_Vertex[3]);
	pkV->tu = fU2;	
	pkV->tv = fV1;
}

//---------------------------------------------------------------------------
void Sprite::Clone(Sprite& rkSprite)
{
	if(&rkSprite == this)
	{
		return;
	}

	rkSprite.m_pkTexture = m_pkTexture;

	for(unsigned int i = 0; i < 4; i++)
	{
		rkSprite.m_Vertex[i] = m_Vertex[i];
	}
}

//---------------------------------------------------------------------------
Sprite::~Sprite()
{
	
}

//---------------------------------------------------------------------------