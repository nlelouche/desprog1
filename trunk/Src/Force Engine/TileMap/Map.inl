//----------------------------------------------------------------
inline float Map::getPosX()
{
	return m_fPosX;
}
//----------------------------------------------------------------
inline float Map::getPosY()
{
	return m_fPosY;
}
//----------------------------------------------------------------
inline float Map::getPosZ()
{
	return m_fPosZ;
}
//----------------------------------------------------------------
inline void Map::setPos(float fX, float fY, float fZ)
{
	m_fPosX = fX;
	m_fPosY = fY;
	m_fPosZ = fZ;

	moveMap();
}
//----------------------------------------------------------------
