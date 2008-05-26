/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: Sprite.cpp
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#include "Sprite.h"
//---------------------------------------------------------------------------

Sprite::Sprite()
:
m_pkCurrentAnim(NULL),
Entity2D()
{
	TextureVertex * pkv;

	pkv = &(m_Vertex[0]);
	pkv->x = -0.5f;	
	pkv->y = -0.5f;	
	pkv->z = 1.0f;
	pkv->tu = 0.0f;	
	pkv->tv = 1.0f;
	
	pkv = &(m_Vertex[1]);
	pkv->x = -0.5f;
	pkv->y = 0.5f;	
	pkv->z = 1.0f;
	pkv->tu = 0.0f;	
	pkv->tv = 0.0f;

	pkv = &(m_Vertex[2]);
	pkv->x = 0.5f;	
	pkv->y = -0.5f;
	pkv->z = 1.0f;
	pkv->tu = 1.0f;	
	pkv->tv = 1.0f;

	pkv = &(m_Vertex[3]);
	pkv->x = 0.5f;	
	pkv->y = 0.5f;	
	pkv->z = 1.0f;
	pkv->tu = 1.0f;	
	pkv->tv = 0.0f;
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
		return * this;
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

	if(m_pkCurrentAnim)
	{
		m_pkCurrentAnim->Update(fTimeBetweenFrames);

		unsigned int uiCurrentFrame = m_pkCurrentAnim->getCurrentFrame();
		const FrameInfo& kInfo = m_pkCurrentAnim->getInfo()->getFrameInfo(uiCurrentFrame);

		setTextureArea(kInfo.uiOffsetX, kInfo.uiOffsetY, kInfo.uiWidth, kInfo.uiHeight);
	}
}

//---------------------------------------------------------------------------
void Sprite::setTextureArea(unsigned int uiOffsetX, unsigned int uiOffsetY, unsigned int uiWidth, unsigned int uiHeight)
{
	assert(m_pkTexture);

	float fTexWidth = static_cast<float>(m_pkTexture->getWidth());
	float fTexHeight = static_cast<float>(m_pkTexture->getHeight());
	
	float fU1 = uiOffsetX / fTexWidth;
	float fU2 = (uiOffsetX + uiWidth) / fTexWidth;

	float fV1 = uiOffsetY / fTexHeight;
	float fV2 = (uiOffsetY + uiHeight) / fTexHeight;
	
	TextureVertex * pkv;

	pkv = &(m_Vertex[0]);
	pkv->tu = fU1;	
	pkv->tv = fV2;
	
	pkv = &(m_Vertex[1]);
	pkv->tu = fU1;
	pkv->tv = fV1;

	pkv = &(m_Vertex[2]);
	pkv->tu = fU2;	
	pkv->tv = fV2;

	pkv = &(m_Vertex[3]);
	pkv->tu = fU2;	
	pkv->tv = fV1;
}

//---------------------------------------------------------------------------
void Sprite::Clone(Sprite& rkSprite)
{
	if(&rkSprite == this)
	{
		return;
	}

	rkSprite.m_pkTexture = m_pkTexture;
	rkSprite.m_kAnimationMap = m_kAnimationMap;

	for(unsigned int i = 0; i < 4; i++)
	{
		rkSprite.m_Vertex[i] = m_Vertex[i];
	}
}

//---------------------------------------------------------------------------
bool Sprite::addAnimationInfo(std::string kName, AnimationInfo::Ptr pkInfo)
{
	AnimationInfo::Ptr pkAnimInfo = m_kAnimationMap[kName];

	if(pkAnimInfo.get())
	{
		return false;
	}

	m_kAnimationMap[kName] = pkInfo;

	return true;
}

//---------------------------------------------------------------------------
bool Sprite::removeAnimationInfo(std::string kName)
{
	AnimationInfo::Ptr pkAnimInfo = m_kAnimationMap[kName];

	if(!pkAnimInfo.get())
	{
		return false;
	}

	m_kAnimationMap.erase(kName);

	return false;
}

//---------------------------------------------------------------------------
Sprite::~Sprite()
{

}

//---------------------------------------------------------------------------