/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: Sprite.inl
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
inline void Sprite::setTexture(Texture::Ptr pkTexture)
{
	m_pkTexture = pkTexture;
}

//---------------------------------------------------------------------------
inline const Texture::Ptr Sprite::getTexture() const
{
	return m_pkTexture;
}

//---------------------------------------------------------------------------
inline void Sprite::setAnimation(Animation * pkCurrentAnim)
{
	m_pkCurrentAnim = pkCurrentAnim;
}

//---------------------------------------------------------------------------