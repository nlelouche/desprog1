/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: Entity2D.inl
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
inline void Entity2D::setPosX(float fX)
{
	m_fX = fX;
}

//---------------------------------------------------------------------------
inline void Entity2D::setPosY(float fY)
{
	m_fY = fY;
}

//---------------------------------------------------------------------------
inline void Entity2D::setRotationZ(float rotationZ)
{
	m_fRotationZ = rotationZ;
}

//---------------------------------------------------------------------------
inline void Entity2D::setPosXY(float fX, float fY)
{
	m_fX = fX;
	m_fY = fY;
}

//---------------------------------------------------------------------------
inline void Entity2D::setDim(float fW, float fH)
{
	m_fW = fW;
	m_fH = fH;
}

//---------------------------------------------------------------------------
inline void Entity2D::setMovingSpeed(float fMovingSpeed)
{
	m_fMovingSpeed = fMovingSpeed;
}

//---------------------------------------------------------------------------
inline void Entity2D::setMovingAngle(float fMovingAngle)
{
	m_fMovingAngle = fMovingAngle;
}

//---------------------------------------------------------------------------
inline void Entity2D::setMovingAngleRad(float fMovingAngleRad)
{
	m_fMovingAngleRad = fMovingAngleRad;
}

//---------------------------------------------------------------------------
inline float Entity2D::getPosX() const
{
	return m_fX;
}

//---------------------------------------------------------------------------
inline float Entity2D::getPosY() const
{
	return m_fY;
}

//---------------------------------------------------------------------------
inline float Entity2D::getRotationZ() const
{
	return m_fRotationZ;
}

//---------------------------------------------------------------------------
inline float Entity2D::getMovingSpeed() const
{
	return m_fMovingSpeed;
}

//---------------------------------------------------------------------------
inline float Entity2D::getMovingAngle() const
{
	return m_fMovingAngle;
}

//---------------------------------------------------------------------------
inline float Entity2D::getMovingAngleRad() const
{
	return m_fMovingAngleRad;
}

//---------------------------------------------------------------------------
inline void Entity2D::setName(std::string kName)
{
	m_kName = kName;
}

//---------------------------------------------------------------------------
inline float Entity2D::getDimHeight()
{
	return m_fH;
}

//---------------------------------------------------------------------------
inline float Entity2D::getDimWidth()
{
	return m_fW;
}

//---------------------------------------------------------------------------
inline const std::string& Entity2D::getName() const
{
	return m_kName;
}

//---------------------------------------------------------------------------