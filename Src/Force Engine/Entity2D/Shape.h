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
#include "../Defines/Defines.h"
#include "../Graphics/Graphics.h"
#include "../Entity2D/Entity2D.h"
#include "../Graphics/GraphicsStructs.h"
//---------------------------------------------------------------------------
class Graphics;
//---------------------------------------------------------------------------
class FORCEENGINE_API Shape : public Entity2D
{
public:

	~Shape();

	virtual void Draw(Graphics & rkGraphics) const;
	virtual void onCollision(Entity2D* pkEntity) { /*****/ }

	int m_iCantVertices;
	ColorVertex * m_pkVertices;

protected:

	Shape();

};

//---------------------------------------------------------------------------

#endif /*--- SHAPE_H ---*/

//---------------------------------------------------------------------------