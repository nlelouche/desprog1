/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: ForceBOX.cpp
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#include "ForceBOX.h"
//---------------------------------------------------------------------------
ForceBOX::ForceBOX()
:
Shape()
{
	ColorVertex * pkv;

	m_iCantVertices = 4;

	m_pkVertices = new ColorVertex[m_iCantVertices];

	pkv = &(m_pkVertices[0]);
	pkv->x = -0.5f;
	pkv->y = -0.5f;
	pkv->z = 1.0f;
	pkv->Color = D3DCOLOR_XRGB(0,0,0);

	pkv = &(m_pkVertices[1]);
	pkv->x = -0.5f;
	pkv->y = 0.5f;
	pkv->z = 1.0f;
	pkv->Color = D3DCOLOR_XRGB(0,0,0);

	pkv = &(m_pkVertices[2]);
	pkv->x = 0.5f;
	pkv->y = -0.5f;
	pkv->z = 1.0f;
	pkv->Color = D3DCOLOR_XRGB(0,0,0);
	
	pkv = &(m_pkVertices[3]);
	pkv->x = 0.5f;
	pkv->y = 0.5f;
	pkv->z = 1.0f;
	pkv->Color = D3DCOLOR_XRGB(0,0,0);
}
//---------------------------------------------------------------------------
void ForceBOX::Draw(Graphics & rkGraphics) const
{
	Shape::Draw(rkGraphics);
	rkGraphics.Draw(m_pkVertices, D3DPT_TRIANGLESTRIP, m_iCantVertices);
}
//---------------------------------------------------------------------------
ForceBOX::~ForceBOX()
{
	delete m_pkVertices;
	m_pkVertices = NULL;
}
//---------------------------------------------------------------------------