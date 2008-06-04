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
m_fW(0),
m_fH(0),
m_fRotationZ(0)
{

}

//---------------------------------------------------------------------------
void Entity2D::Draw(Graphics & m_pGraficos) const
{
	m_pGraficos.setMatrixMode(WORLD);
	
	m_pGraficos.loadIdentity();

	m_pGraficos.Translate(m_fX, m_fY);
	m_pGraficos.rotateZ(m_fRotationZ * PI / 180.0f);
	m_pGraficos.Scale(m_fW, m_fH);
}

//---------------------------------------------------------------------------
void Entity2D::Update(float fTimeBetweenFrames)
{
	/*if(m_bMoving)
	{
		m_fX = (fTimeBetweenFrames / 1000.0f) * m_fMovingSpeed * cos(m_fMovingAngleRad);
		m_fY = (fTimeBetweenFrames / 1000.0f) * m_fMovingSpeed * sin(m_fMovingAngleRad);
	}*/
}

//---------------------------------------------------------------------------
bool Entity2D::checkCollision(Entity2D * pkEntity)
{
	float fAuxPosX = pkEntity->getPosX() - m_fX;
	float fAuxPosY = pkEntity->getPosY() - m_fY;

	float fAuxW = m_fW / 2.0f + pkEntity->getDimWidth() / 2.0f;
	float fAuxH = m_fH / 2.0f + pkEntity->getDimHeight() / 2.0f;

	if(fAuxPosX + fAuxW < fAuxPosY + fAuxH)
	{
		//Colision Horizontal
	}
	else
	{
		//Colision Vertical
	}
	
	return ((fabs(fAuxPosX) <= fAuxW) && (fabs(fAuxPosY) <= fAuxH));
}

//---------------------------------------------------------------------------
Entity2D::~Entity2D()
{

}

//---------------------------------------------------------------------------