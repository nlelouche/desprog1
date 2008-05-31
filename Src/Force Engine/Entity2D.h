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

	float getDimHeight();
	float getDimWidth();

	float getPosX() const;
	void setPosX(float fX);

	float getPosY() const;
	void setPosY(float fY);

	float getRotationZ() const;
	void setRotationZ(float rotationZ);

	void setDim(float fW, float fH);
	void setPosXY(float fX, float fY);

	float getMovingSpeed() const;
	void setMovingSpeed(float fMovingSpeed);

	float getMovingAngle() const;
	void setMovingAngle(float fMovingAngle);

	float getMovingAngleRad() const;
	void setMovingAngleRad(float fMovingAngleRad);

	void setName(std::string kName);
	const std::string& getName() const;

	virtual void Draw(Graphics& g_graficos) const;
	virtual void Update(float fTimeBetweenFrames);

public:

	bool m_bMoving;

	float m_fMovingSpeed;
	float m_fMovingAngle;
	float m_fMovingAngleRad;

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