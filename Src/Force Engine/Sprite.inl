/****************************************************************************

Force Engine v0.1

Creado: 28/03/08
Clase: Sprite.inl
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
inline void Sprite::setTexture(Texture * pkTexture)
{
	m_pkTexture = pkTexture;
}

//---------------------------------------------------------------------------
inline const Texture * Sprite::getTexture() const
{
	return m_pkTexture;
}

//---------------------------------------------------------------------------