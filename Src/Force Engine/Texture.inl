/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: Texture.inl
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
inline unsigned int Texture::getWidth() const
{
	return m_uiWidth;
}
//---------------------------------------------------------------------------
inline unsigned int Texture::getHeight() const
{
	return m_uiHeight;
}
//---------------------------------------------------------------------------
inline void Texture::setWidth(unsigned int uiWidth)
{
	m_uiWidth = uiWidth;
}
//---------------------------------------------------------------------------
inline void Texture::setHeight(unsigned int uiHeight)
{
	m_uiHeight = uiHeight;
}
//---------------------------------------------------------------------------
inline std::string Texture::getFileName() const
{
	return m_kFilename;
}
//---------------------------------------------------------------------------
inline unsigned long Texture::getColorKey() const
{
	return m_ulColor;
}
//---------------------------------------------------------------------------