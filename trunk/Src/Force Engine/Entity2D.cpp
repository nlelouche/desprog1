/****************************************************************************

Force Engine v0.1

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
void Entity2D::Draw(Graphics &g_graficos) const
{
	g_graficos.setMatrixMode(WORLD);
	
	g_graficos.loadIdentity();

	g_graficos.Translate(m_fX, m_fY);
	g_graficos.rotateZ(m_fRotationZ * 3.14159f / 180.0f);
	g_graficos.Scale(m_fW, m_fH);
}

//---------------------------------------------------------------------------
void Entity2D::Update(float fTimeBetweenFrames)
{
	/***/
}

//---------------------------------------------------------------------------
Entity2D::~Entity2D()
{

}

//---------------------------------------------------------------------------