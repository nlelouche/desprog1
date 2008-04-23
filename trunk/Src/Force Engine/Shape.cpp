/****************************************************************************

Force Engine v0.1

Creado: 28/03/08
Clase: Shape.cpp
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#include "Shape.h"
#include "Graphics.h"
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
Shape::Shape()
{
	ColorVertex * pkv;

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
	pkv->Color = D3DCOLOR_XRGB(255,0,0);
}

//---------------------------------------------------------------------------
void Shape::Draw(Graphics &g_graphics) const
{
	Entity2D::Draw(g_graphics);
	g_graphics.Draw(m_Vertices, D3DPT_TRIANGLELIST, 3);
}

//---------------------------------------------------------------------------
Shape::~Shape()
{

}

//---------------------------------------------------------------------------