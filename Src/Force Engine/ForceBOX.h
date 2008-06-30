/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: ForceBOX.h
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#ifndef FORCEBOX_H
#define FORCEBOX_H
//---------------------------------------------------------------------------
#include "Shape.h"
#include "Entity2D.h"
#include "Graphics.h"
//---------------------------------------------------------------------------
class Graphics;
//---------------------------------------------------------------------------
class FORCEENGINE_API ForceBOX : public Shape
{
public:

	ForceBOX();
	~ForceBOX();

	void Draw(Graphics & rkGraphics) const;
};

//---------------------------------------------------------------------------

#endif /*--- FORCEBOX_H ---*/

//---------------------------------------------------------------------------