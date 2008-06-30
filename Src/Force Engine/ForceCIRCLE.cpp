/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: ForceCIRCLE.cpp
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#include "ForceCIRCLE.h"
//---------------------------------------------------------------------------
ForceCIRCLE::ForceCIRCLE(int iNumCaras)
:
Shape()
{
	setCantidadCaras(iNumCaras);
}
//---------------------------------------------------------------------------
void ForceCIRCLE::Draw(Graphics & rkGraphics) const
{
	Shape::Draw(rkGraphics);
	rkGraphics.Draw(m_pkVertices, D3DPT_TRIANGLEFAN, m_iCantVertices);
}
//---------------------------------------------------------------------------
void ForceCIRCLE::setCantidadCaras(int iNumCaras)
{
	if(iNumCaras > 140)
	{
		m_iNumCaras = 140;
	}
	else
	{
		m_iNumCaras = iNumCaras;
	}

	ColorVertex * pkv;

	m_pkVertices = new ColorVertex[m_iNumCaras + 2];
	m_iCantVertices = m_iNumCaras + 2;

	pkv = &(m_pkVertices[0]);
	pkv->x = 0.0f;
	pkv->y = 0.0f;	
	pkv->z = 1.0f;
	pkv->Color = D3DCOLOR_XRGB(255, 0, 0);

	for(int i = 1; i <= m_iNumCaras + 1; i++)
	{
		double dAngle = (360.0 / m_iNumCaras) * i;
		double dPIsobre180 = 3.141592654f / 180.0;
		double dSin = sin(dAngle * dPIsobre180);
		double dCos = cos(dAngle * dPIsobre180);

		pkv = &(m_pkVertices[i]);
		pkv->x = (float)(dSin);
		pkv->y = (float)(dCos);
		pkv->z = 1.0f;
		pkv->Color = D3DCOLOR_XRGB(255, 0, 0);
	}
}
//---------------------------------------------------------------------------
int ForceCIRCLE::getNumeroCaras()
{
	return m_iNumCaras;
}
//---------------------------------------------------------------------------
ForceCIRCLE::~ForceCIRCLE()
{
	delete m_pkVertices;
	m_pkVertices = NULL;
}
//---------------------------------------------------------------------------
