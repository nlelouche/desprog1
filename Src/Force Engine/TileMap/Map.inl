/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: Map.inl
Hecho by: Nahuel Lelouche
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
inline float Map::getPosX()
{
	return m_fPosX;
}
//---------------------------------------------------------------------------
inline float Map::getPosY()
{
	return m_fPosY;
}
//---------------------------------------------------------------------------
inline float Map::getPosZ()
{
	return m_fPosZ;
}
//---------------------------------------------------------------------------
inline int Map::getTileHeight()
{
	return m_iTileHeight;
}
//---------------------------------------------------------------------------
inline int Map::getTileWidth()
{
	return m_iTileWidth;
}
//---------------------------------------------------------------------------
inline void Map::setPos(float fX, float fY, float fZ)
{
	m_fPosX = fX;
	m_fPosY = fY;
	m_fPosZ = fZ;

	moveMap();
}
//---------------------------------------------------------------------------
