/****************************************************************************

Force Engine v0.1

Creado: 28/03/08
Clase: ForceCIRCLE.cpp
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#include "ForceCIRCLE.h"
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
ForceCIRCLE::ForceCIRCLE()
:
Shape()
{

}

//---------------------------------------------------------------------------
void ForceCIRCLE::Draw(Graphics & g_graphics) const
{
	Shape::Draw(g_graphics);
	g_graphics.Draw(m_Vertices, D3DPT_TRIANGLELIST, m_iCantVertices);
}

//---------------------------------------------------------------------------
void ForceCIRCLE::setCantidadVertices(int iNumCaras)
{
	if(iNumCaras >140)
	{
		m_iNumCaras = 140;
	}
	else
	{
		m_iNumCaras = iNumCaras;
	}

	

	/*
	ColorVertex * pkv;

	m_iCantVertices = 3;

	m_Vertices = new ColorVertex[m_iCantVertices];

	pkv = &(m_Vertices[0]);
	pkv->x = -0.5f;
	pkv->y = 0.5f;
	pkv->z = 1.0f;
	pkv->Color = D3DCOLOR_XRGB(255,0,0);

	pkv = &(m_Vertices[1]);
	pkv->x = 0.5f;
	pkv->y = -0.5f;
	pkv->z = 1.0f;
	pkv->Color = D3DCOLOR_XRGB(255,0,0);

	pkv = &(m_Vertices[2]);
	pkv->x = 0.5f;
	pkv->y = 0.5f;
	pkv->z = 1.0f;
	pkv->Color = D3DCOLOR_XRGB(255,0,0);*/
}

//---------------------------------------------------------------------------
ForceCIRCLE::~ForceCIRCLE()
{

}

//---------------------------------------------------------------------------
