/****************************************************************************

Force Engine v0.1

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
inline void Entity2D::setName(std::string kName)
{
	m_kName = kName;
}

//---------------------------------------------------------------------------
inline const std::string& Entity2D::getName() const
{
	return m_kName;
}

//---------------------------------------------------------------------------