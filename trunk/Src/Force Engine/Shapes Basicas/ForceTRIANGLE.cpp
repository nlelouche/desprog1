/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: ForceTRIANGLE.cpp
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#include "ForceTRIANGLE.h"
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
ForceTRIANGLE::ForceTRIANGLE()
{
	ColorVertex * pkv;

	m_iCantVertices = 3;

	m_pkVertices = new ColorVertex[m_iCantVertices];

	pkv = &(m_pkVertices[0]);
	pkv->x = -0.5f;
	pkv->y = 0.5f;
	pkv->z = 1.0f;
	pkv->Color = D3DCOLOR_XRGB(0,0,0);

	pkv = &(m_pkVertices[1]);
	pkv->x = 0.5f;
	pkv->y = -0.5f;
	pkv->z = 1.0f;
	pkv->Color = D3DCOLOR_XRGB(0,0,0);

	pkv = &(m_pkVertices[2]);
	pkv->x = 0.5f;
	pkv->y = 0.5f;
	pkv->z = 1.0f;
	pkv->Color = D3DCOLOR_XRGB(0,0,0);
}

//---------------------------------------------------------------------------
void ForceTRIANGLE::Draw(Graphics & rkGraphics) const
{
	Shape::Draw(rkGraphics);
	rkGraphics.Draw(m_pkVertices, D3DPT_TRIANGLELIST, m_iCantVertices);
}

//---------------------------------------------------------------------------
ForceTRIANGLE::~ForceTRIANGLE()
{
	delete m_pkVertices;
	m_pkVertices = NULL;
}

//---------------------------------------------------------------------------