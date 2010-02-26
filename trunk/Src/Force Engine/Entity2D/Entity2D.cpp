/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: Entity2D.cpp
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#include "Entity2D.h"
//---------------------------------------------------------------------------
Entity2D::Entity2D()
:
m_fX(0), 
m_fY(0),
m_fZ(0),
m_fW(0),
m_fH(0),
m_fRotationZ(0),
m_bMoving(false),
m_fMovingSpeed(0),
m_fMovingAngle(0),
m_fMovingAngleRad(0),
m_fPrevX(0),
m_fPrevY(0),
m_fGravity(0),
m_kName("")
{
	ColorVertex * pkV;
	
	pkV = &(m_akAABBVertices[0]);
	pkV->x = -0.5f;
	pkV->y = -0.5f;
	pkV->z = 0.0f;
	pkV->Color = D3DCOLOR_XRGB(255,255,255);
	
	pkV = &(m_akAABBVertices[1]);
	pkV->x = -0.5f;
	pkV->y = 0.5f;	
	pkV->z = 0.0f;
	pkV->Color = D3DCOLOR_XRGB(255,255,255);

	pkV = &(m_akAABBVertices[2]);
	pkV->x = 0.5f;
	pkV->y = 0.5f;
	pkV->z = 0.0f;
	pkV->Color = D3DCOLOR_XRGB(255,255,255);	
	
	pkV = &(m_akAABBVertices[3]);
	pkV->x = 0.5f;	
	pkV->y = -0.5f;	
	pkV->z = 0.0f;
	pkV->Color = D3DCOLOR_XRGB(255,255,255);

	pkV = &(m_akAABBVertices[4]);
	pkV->x = -0.5f;	
	pkV->y = -0.5f;	
	pkV->z = 0.0f;
	pkV->Color = D3DCOLOR_XRGB(255,255,255);
}
//---------------------------------------------------------------------------
void Entity2D::Draw(Graphics & rkGraphics) const
{
	rkGraphics.setMatrixMode(WORLD);
	
	rkGraphics.loadIdentity();

	//Dibuja los Bordes de Entities
/*
	rkGraphics.Translate(m_fX, m_fY, m_fZ);
	rkGraphics.Scale(m_fW, m_fH);
	rkGraphics.unbindTexture();
	rkGraphics.Draw(m_akAABBVertices, D3DPT_LINESTRIP, 5);
*/
	rkGraphics.loadIdentity();
	rkGraphics.Translate(m_fX, m_fY, m_fZ);
	rkGraphics.rotateZ(m_fRotationZ * PI / 180.0f);
	rkGraphics.Scale(m_fW, m_fH);
}
//---------------------------------------------------------------------------
void Entity2D::Update(float fTimeBetweenFrames)
{
	if(m_bMoving)
	{
		m_fPrevX = m_fX;
		m_fPrevY = m_fY;

		m_fX += (fTimeBetweenFrames / 1000.0f) * m_fMovingSpeed * cos(m_fMovingAngleRad);
		m_fY += (fTimeBetweenFrames / 1000.0f) * m_fMovingSpeed * sin(m_fMovingAngleRad);
	}
}
//---------------------------------------------------------------------------
Entity2D::CollisionResult Entity2D::checkCollision(Entity2D * pkEntity) const
{
	float fAuxPosX = fabs(pkEntity->getPosX() - m_fX);
	float fAuxPosY = fabs(pkEntity->getPosY() - m_fY);

	float fAuxW = (m_fW / 2.0f + pkEntity->getDimWidth() / 2.0f);
	float fAuxH = (m_fH / 2.0f + pkEntity->getDimHeight() / 2.0f);

	if(fAuxPosX < fAuxW && fAuxPosY < fAuxH)
	{
		if(fAuxPosX + fAuxW > fAuxPosY + fAuxH)
		{
			return Vertical;
		}
		else
		{
			return Horizontal;
		}
	}
	else
	{
		return None;
	}
}
//---------------------------------------------------------------------------
Entity2D::~Entity2D()
{
	/*****/
}
//---------------------------------------------------------------------------