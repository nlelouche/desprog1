/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: ForceCIRCLE.h
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#ifndef FORCECIRCLE_H
#define FORCECIRCLE_H
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#include "../Entity2D/Shape.h"
#include "../Entity2D/Entity2D.h"
#include "../Graphics/Graphics.h"
//---------------------------------------------------------------------------
class Graphics;
//---------------------------------------------------------------------------

class FORCEENGINE_API ForceCIRCLE : public Shape
{
public:

	ForceCIRCLE(int iNumCaras);
	~ForceCIRCLE();

	void Draw(Graphics & rkGraphics) const;
	
	int getNumeroCaras();
	void setCantidadCaras(int iNumCaras);

private:

	int m_iNumCaras;
};

//---------------------------------------------------------------------------

#endif /*--- FORCECIRCLE_H ---*/

//---------------------------------------------------------------------------