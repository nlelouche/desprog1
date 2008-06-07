/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: Shape.h
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#ifndef SHAPE_H
#define SHAPE_H
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#include "Shape.h"
#include "Defines.h"
#include "Graphics.h"
#include "Entity2D.h"
#include "GraphicsStructs.h"
//---------------------------------------------------------------------------
class Graphics;
//---------------------------------------------------------------------------
class FORCEENGINE_API Shape : public Entity2D
{
public:

	~Shape();

	virtual void Draw(Graphics &g_graphics) const;
	virtual void onCollision (Entity2D* pkEntity) { /*****/ }

	int m_iCantVertices;
	ColorVertex * m_Vertices;

protected:

	Shape();

};

#endif /*--- SHAPE_H ---*/

//---------------------------------------------------------------------------