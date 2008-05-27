/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: Shape.cpp
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#include "Shape.h"
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
Shape::Shape()
:
Entity2D(),
m_Vertices(NULL)
{
	
}

//---------------------------------------------------------------------------
void Shape::Draw(Graphics &g_graphics) const
{
	Entity2D::Draw(g_graphics);
	g_graphics.unbindTexture();
}

//---------------------------------------------------------------------------
Shape::~Shape()
{

}

//---------------------------------------------------------------------------