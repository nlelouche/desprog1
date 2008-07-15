/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: ForceTRIANGLE.h
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#ifndef FORCETRIANGLE_H
#define FORCETRIANGLE_H
//---------------------------------------------------------------------------
#include "../Entity2D/Shape.h"
#include "../Entity2D/Entity2D.h"
#include "../Graphics/Graphics.h"
//---------------------------------------------------------------------------
class Graphics;
//---------------------------------------------------------------------------
class FORCEENGINE_API ForceTRIANGLE : public Shape
{
public:

	ForceTRIANGLE();
	~ForceTRIANGLE();

	void Draw(Graphics & rkGraphics) const;
};

//---------------------------------------------------------------------------

#endif /*--- FORCETRIANGLE_H ---*/

//---------------------------------------------------------------------------