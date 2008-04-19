/****************************************************************************

Force Engine v0.1

Creado: 28/03/08
Clase: Entity2D.h
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#ifndef ENTITY2D_H
#define ENTITY2D_H
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#include <d3d9.h>
#include <d3dx9.h>
#include "Graphics.h"
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
class Graphics;
//---------------------------------------------------------------------------

class FORCEENGINE_API Entity2D
{
public:

	Entity2D();
	virtual ~Entity2D();

	// Seters y Geters de X Y Z

	void setPosX(float fX);
	float getPosX()const;

	void setPosY(float fY);
	float getPosY()const;

	void setRotationZ(float rotationZ);
	float getRotationZ()const;

	void setPosXY(float fX, float fY);
	void setDim(float fW, float fH);

	virtual void Draw (Graphics& g_graficos) const;

private:
	
	float m_fX;
	float m_fY;
	float m_fRotationZ;

	float m_fW; 
	float m_fH;

};

//---------------------------------------------------------------------------
#include "Entity2D.inl"
//---------------------------------------------------------------------------

#endif /*--- SPRITE_H ---*/

//---------------------------------------------------------------------------