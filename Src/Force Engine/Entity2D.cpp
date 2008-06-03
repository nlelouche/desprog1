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
void Entity2D::Draw(Graphics & m_gGraficos) const
{
	m_gGraficos.setMatrixMode(WORLD);
	
	m_gGraficos.loadIdentity();

	m_gGraficos.Translate(m_fX, m_fY);
	m_gGraficos.rotateZ(m_fRotationZ * PI / 180.0f);
	m_gGraficos.Scale(m_fW, m_fH);
}

//---------------------------------------------------------------------------
void Entity2D::Update(float fTimeBetweenFrames)
{
	if(m_bMoving)
	{
		m_fX = (fTimeBetweenFrames / 1000.0f) * m_fMovingSpeed * cos(m_fMovingAngleRad);
		m_fY = (fTimeBetweenFrames / 1000.0f) * m_fMovingSpeed * sin(m_fMovingAngleRad);
	}
}

//---------------------------------------------------------------------------
Entity2D::~Entity2D()
{

}

//---------------------------------------------------------------------------