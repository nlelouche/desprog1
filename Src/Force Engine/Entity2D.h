/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: Entity2D.h
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#ifndef ENTITY2D_H
#define ENTITY2D_H
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#include <d3dx9.h>
#include "Defines.h"
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

	void setName(std::string kName);
	const std::string& getName() const;

	// Seters y Geters de X Y Z

	void setPosX(float fX);
	float getPosX() const;

	void setPosY(float fY);
	float getPosY() const;

	void setRotationZ(float rotationZ);
	float getRotationZ() const;

	void setPosXY(float fX, float fY);
	void setDim(float fW, float fH);

	float getDimHeight();
	float getDimWidth();

	virtual void Draw(Graphics& g_graficos) const;
	virtual void Update(float fTimeBetweenFrames);

private:

	float m_fW; 
	float m_fH;
	
	float m_fX;
	float m_fY;
	float m_fRotationZ;

	std::string m_kName;
};

//---------------------------------------------------------------------------
#include "Entity2D.inl"
//---------------------------------------------------------------------------

#endif /*--- SPRITE_H ---*/

//---------------------------------------------------------------------------